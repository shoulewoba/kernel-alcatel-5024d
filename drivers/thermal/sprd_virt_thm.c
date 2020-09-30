/*
 * Copyright (C) 2015 Spreadtrum Communications Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/cpu_cooling.h>
#include <linux/cpufreq.h>
#include <linux/cpumask.h>
#include <linux/debugfs.h>
#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/thermal.h>
#include <linux/of.h>
#include <linux/kernel.h>
#include "sprd_thm.h"

struct sprd_ipa_info {
	/*
	 * Proportional parameter of the PID controller when
	 * overshooting (i.e., when temperature is below the target)
	 */
	s32 k_po;

	/*
	 * Proportional parameter of the PID controller when
	 * undershooting
	 */
	s32 k_pu;

	/* Integral parameter of the PID controller */
	s32 k_i;

	/* Derivative parameter of the PID controller */
	s32 k_d;

	/* threshold below which the error is no longer accumulated */
	s32 integral_cutoff;
};

struct virt_sensor {
	u16 sensor_id;
	int nsensor;
	struct sprd_ipa_info ipa_info;
	struct sprd_thermal_zone *pzone;
	const char *sensor_names[THM_SENSOR_NUMBER];
	struct thermal_zone_device *thm_zones[THM_SENSOR_NUMBER];
};

struct virt_sensor virt_temp_sensor;

static int __sprd_get_max_temp(int *temp)
{
	int i, ret = 0;
	int virt_temp = 0;
	int sensor_temp[THM_SENSOR_NUMBER];
	struct thermal_zone_device *tz = NULL;
	struct virt_sensor *psensor = &virt_temp_sensor;

	for (i = 0; i < psensor->nsensor; i++) {
		tz = psensor->thm_zones[i];
		if (!tz || IS_ERR(tz) || !tz->ops->get_temp) {
			pr_err("get thermal zone failed\n");
			return -ENODEV;
		}

		ret = tz->ops->get_temp(tz, &sensor_temp[i]);
		if (ret) {
			pr_err("get thermal %s temp failed\n", tz->type);
			return ret;
		}
	}

	/*get max temperature of all thermal sensors*/
	for (i = 0; i < psensor->nsensor; i++) {
		virt_temp = max(virt_temp, sensor_temp[i]);
	}

	*temp = virt_temp;
	return ret;
}

static int sprd_temp_sensor_read(struct sprd_thermal_zone *pzone, int *temp)
{
	int ret = -EINVAL;

	if (!pzone || !temp)
		return ret;

	ret = __sprd_get_max_temp(temp);
	pr_debug("virt_sensor_id:%d, temp:%d\n", pzone->id, *temp);

	return ret;
}

struct thm_handle_ops sprd_virt_thm_ops = {
	.read_temp = sprd_temp_sensor_read,
};

static void sprd_ipa_info_copy(struct sprd_thermal_zone *pzone,
				struct virt_sensor *pvirt_sensor)
{
	struct sprd_ipa_info *ipa_info = &pvirt_sensor->ipa_info;
	struct thermal_zone_params *tzp = pzone->therm_dev->tzp;

	if (ipa_info->k_po)
		tzp->k_po = ipa_info->k_po;
	if (ipa_info->k_pu)
		tzp->k_pu = ipa_info->k_pu;
	if (ipa_info->k_i)
		tzp->k_i = ipa_info->k_i;
	if (ipa_info->k_d)
		tzp->k_d = ipa_info->k_d;
	if (ipa_info->integral_cutoff)
		tzp->integral_cutoff = ipa_info->integral_cutoff;
}

static void  sprd_ipa_info_parse_dt(const struct device_node *np,
			struct sprd_ipa_info *ipa_info)
{
	int ret = 0;

	ret = of_property_read_u32(np, "k-po", &ipa_info->k_po);
	if (ret) {
		ipa_info->k_po = 0;
		pr_warn("no k_po property for virt thm\n");
	}
	ret = of_property_read_u32(np, "k-pu", &ipa_info->k_pu);
	if (ret) {
		ipa_info->k_pu = 0;
		pr_warn("no k_pu property for virt thm\n");
	}
	ret = of_property_read_u32(np, "k-i", &ipa_info->k_i);
	if (ret) {
		ipa_info->k_i = 0;
		pr_warn("no k_i property for virt thm\n");
	}
	ret = of_property_read_u32(np, "k-d", &ipa_info->k_d);
	if (ret) {
		ipa_info->k_d = 0;
		pr_warn("no k_d property for virt thm\n");
	}
	ret = of_property_read_u32(np, "cutoff", &ipa_info->integral_cutoff);
	if (ret) {
		ipa_info->integral_cutoff = 0;
		pr_warn("no cutoff property for virt thm\n");
	}
}

static int sprd_temp_sen_parse_dt(struct device *dev,
				struct virt_sensor *pvirt_sensor)
{
	int count, i, ret = 0;
	struct device_node *np = dev->of_node;

	if (!np) {
		dev_err(dev, "device node not found\n");
		return -EINVAL;
	}

	count = of_property_count_strings(np, "sensor-names");
	if (count < 0) {
		dev_err(dev, "sensor names not found\n");
		return count;
	}

	pvirt_sensor->nsensor = count;
	for (i = 0; i < count; i++) {
		ret = of_property_read_string_index(np, "sensor-names",
			i, &pvirt_sensor->sensor_names[i]);
		if (ret) {
			dev_err(dev, "fail to get  sensor-names\n");
			return ret;
		}
	}

	sprd_ipa_info_parse_dt(np, &pvirt_sensor->ipa_info);

	return ret;
}

static int sprd_virt_thm_probe(struct platform_device *pdev)
{
	int i = 0;
	int ret = 0, sensor_id = 0;
	struct sprd_thermal_zone *pzone = NULL;
	struct virt_sensor *pvirt_sensor = &virt_temp_sensor;
	struct device_node *np = pdev->dev.of_node;

	pr_info("sprd virt sensor probe start\n");
	if (!np) {
		dev_err(&pdev->dev, "device node not found\n");
		return -EINVAL;
	}

	ret = sprd_temp_sen_parse_dt(&pdev->dev, pvirt_sensor);
	if (ret) {
		dev_err(&pdev->dev, "not found ptrips\n");
		return -EINVAL;
	}

	for (i = 0; i < pvirt_sensor->nsensor; i++) {
		pvirt_sensor->thm_zones[i] =
		thermal_zone_get_zone_by_name(pvirt_sensor->sensor_names[i]);
		if (IS_ERR(pvirt_sensor->thm_zones[i])) {
			pr_err("get thermal zone %s failed\n",
					pvirt_sensor->sensor_names[i]);
			return -ENOMEM;
		}
	}

	pzone = devm_kzalloc(&pdev->dev, sizeof(*pzone), GFP_KERNEL);
	if (!pzone) {
		ret = -ENOMEM;
		goto err;
	}

	mutex_init(&pzone->th_lock);

	sensor_id = of_alias_get_id(np, "thm-sensor");
	if (sensor_id == -ENODEV) {
		dev_err(&pdev->dev, "fail to get id\n");
		goto err;
	}
	pr_info("sprd virt sensor id %d\n", sensor_id);

	pzone->dev = &pdev->dev;
	pzone->id = sensor_id;
	pzone->ops = &sprd_virt_thm_ops;
	strlcpy(pzone->name, np->name, sizeof(pzone->name));

	ret = sprd_thermal_init(pzone);
	if (ret) {
		dev_err(&pdev->dev,
			"virt sensor sw init error id =%d\n", pzone->id);
		goto err;
	}

	sprd_ipa_info_copy(pzone, pvirt_sensor);
	pvirt_sensor->pzone = pzone;
	platform_set_drvdata(pdev, pzone);

	pr_info("sprd virt sensor probe start end\n");

	return 0;
err:
	kfree(pzone);
	return ret;
}

static int sprd_virt_thm_remove(struct platform_device *pdev)
{
	struct sprd_thermal_zone *pzone = platform_get_drvdata(pdev);

	sprd_thermal_remove(pzone);
	return 0;
}

static struct of_device_id virt_thermal_of_match[] = {
	{ .compatible = "sprd,virt-thermal" },
	{},
};
MODULE_DEVICE_TABLE(of, virt_thermal_of_match);

static struct platform_driver sprd_virt_thermal_driver = {
	.probe = sprd_virt_thm_probe,
	.remove = sprd_virt_thm_remove,
	.driver = {
		   .owner = THIS_MODULE,
		   .name = "virt-thermal",
		   .of_match_table = of_match_ptr(virt_thermal_of_match),
		   },
};

static int __init sprd_virt_thermal_init(void)
{
	return platform_driver_register(&sprd_virt_thermal_driver);
}

static void __exit sprd_virt_thermal_exit(void)
{
	platform_driver_unregister(&sprd_virt_thermal_driver);
}

device_initcall_sync(sprd_virt_thermal_init);
module_exit(sprd_virt_thermal_exit);

MODULE_DESCRIPTION("sprd thermal driver");
MODULE_LICENSE("GPL");
