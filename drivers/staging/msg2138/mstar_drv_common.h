/*==============================================================================
 *
 * Copyright (c) 2006-2012 MStar Semiconductor, Inc.
 * All rights reserved.
 *
 * Unless otherwise stipulated in writing, any and all information contained
 * herein regardless in any format shall remain the sole proprietary of
 * MStar Semiconductor Inc. and be kept in strict confidence
 * (??MStar Confidential Information??) by the recipient.
 * Any unauthorized act including without limitation unauthorized disclosure,
 * copying, use, reproduction, sale, distribution, modification, disassembling,
 * reverse engineering and compiling of the contents of MStar Confidential
 * Information is unlawful and strictly prohibited. MStar hereby reserves the
 * rights to any and all damages, losses, costs and expenses resulting
 therefrom.
 *
==============================================================================*/

/**
 *
 * @file    mstar_drv_common.h
 *
 * @brief   This file defines the interface of touch screen
 *
 * @version v2.2.0.0
 *
 */

#ifndef __MSTAR_DRV_COMMON_H__
#define __MSTAR_DRV_COMMON_H__

/*--------------------------------------------------------------------------*/
/* INCLUDE FILE                                                             */
/*--------------------------------------------------------------------------*/

#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/types.h>
#include <linux/input.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/gpio.h>
#ifdef CONFIG_HAS_EARLYSUSPEND
#include <linux/earlysuspend.h>
#endif
#include <linux/i2c.h>
#include <linux/proc_fs.h>
#include <asm/irq.h>
/* #include <asm/io.h> */
#include <linux/io.h>
/*--------------------------------------------------------------------------*/
/* TOUCH DEVICE DRIVER RELEASE VERSION                                      */
/*--------------------------------------------------------------------------*/

#define DEVICE_DRIVER_RELEASE_VERSION   ("2.2.0.0")

/*--------------------------------------------------------------------------*/
/* COMPILE OPTION DEFINITION                                                */
/*--------------------------------------------------------------------------*/

/*
 * Note.
 * The below compile option is used to enable the specific device driver code
 handling for distinct smart phone developer platform.
 * For running on Spreadtrum platform, please define the compile option
 CONFIG_TOUCH_DRIVER_RUN_ON_SPRD_PLATFORM.
 * For running on Qualcomm platform, please define the compile option
 CONFIG_TOUCH_DRIVER_RUN_ON_QCOM_PLATFORM.
 * For running on MediaTek platform, please define the compile option
 CONFIG_TOUCH_DRIVER_RUN_ON_MTK_PLATFORM.
 */
#define CONFIG_TOUCH_DRIVER_RUN_ON_SPRD_PLATFORM
/* #define CONFIG_TOUCH_DRIVER_RUN_ON_QCOM_PLATFORM */
/* #define CONFIG_TOUCH_DRIVER_RUN_ON_MTK_PLATFORM */

/*
 * Note.
 * The below compile option is used to enable the specific device driver code
 handling for distinct touch ic.
 * Please enable the compile option depends on the touch ic that customer
 project are using and disable the others.
 */
#define CONFIG_ENABLE_CHIP_MSG21XXA
/* #define CONFIG_ENABLE_CHIP_MSG22XX */
/* #define CONFIG_ENABLE_CHIP_MSG26XXM */

/*
 * Note.
 * The below compile option is used to enable the specific device driver code
 handling to make sure main board can supply power to touch ic for some
 specific BB chip of MTK(EX. MT6582)/SPRD(EX. SC7715)/QCOM(EX. MSM8610).
 * By default, this compile option is disabled.
 */
#define CONFIG_ENABLE_REGULATOR_POWER_ON

/*
 * Note.
 * The below compile option is used to distinguish different workqueue
 scheduling mechanism when firmware report finger touch to device driver by IRQ
 interrupt.
 * For MTK platform, there are two type of workqueue scheduling mechanism
 available.
 * Please refer to the related code which is enclosed by compile option
 CONFIG_USE_IRQ_INTERRUPT_FOR_MTK_PLATFORM in
 mstar_drv_platform_porting_layer.c for more detail.
 * This compile option is used for MTK platform only.
 * By default, this compile option is disabled.
 */

/* #define CONFIG_USE_IRQ_INTERRUPT_FOR_MTK_PLATFORM */

/*
 * Note.
 * The below compile option is used to apply DMA mode for read/write data
 between device driver and firmware by I2C.
 * The DMA mode is used to reslove I2C read/write 8 bytes limitation for
 specific MTK BB chip(EX. MT6589/MT6572/...)
 * This compile option is used for MTK platform only.
 * By default, this compile option is disabled.
 */
/* #define CONFIG_ENABLE_DMA_IIC */

/*
 * Note.
 * The below compile option is used to enable the output log mechanism while
 touch device driver is running.
 * If this compile option is not defined, the function for output log will be
 disabled.
 * By default, this compile option is enabled.
 */
/* #define CONFIG_ENABLE_TOUCH_DRIVER_DEBUG */

/*
 * Note.
 * The below compile option is used to enable the specific device driver code
 handling when touch panel support virtual key(EX. Menu, Home, Back, Search).
 * If this compile option is not defined, the function for virtual key handling
 will be disabled.
 * By default, this compile option is enabled.
 */
#define TOUCH_VIRTUAL_KEYS

/*
 * Note.
 * Since specific MTK BB chip report virtual key touch by using coordinate
 instead of key code, the below compile option is used to enable the code
 handling for reporting key with coordinate.
 * This compile option is used for MTK platform only.
 * By default, this compile option is disabled.
 */
/* #define CONFIG_ENABLE_REPORT_KEY_WITH_COORDINATE */

/*
 * Note.
 * The below compile option is used to enable debug mode data log for firmware.
 * By default, this compile option is enabled.
 */
/* #define CONFIG_ENABLE_FIRMWARE_DATA_LOG */

/*
 * Note.
 * The below compile option is used to enable gesture wakeup.
 * By default, this compile option is disabled.
 */
/* #define CONFIG_ENABLE_GESTURE_WAKEUP */

/*
 * Note.
 * The below compile option is used to enable phone level MP test handling.
 * By the way, phone level MP test is ready for MSG21XXA(support Open
 Test&Short Test)/MSG26XXM(support Open Test) only, but phone level MP test for
 MSG22XX is not ready yet.
 * By default, this compile option is disabled.
 */
/* #define CONFIG_ENABLE_ITO_MP_TEST */

/*
 * Note.
 * The below compile option is used to change the permission of the sysfs
 virtual file system for CTS test.
 * If this compile option is enabled, the permission 0644 will be used.
 * If this compile option is disabled, the permission 0777 will be used.
 * By default, this compile option is disabled.
 */
#define SYSFS_AUTHORITY_CHANGE_FOR_CTS_TEST

/*
 * Note.
 * If this compile option is not defined, the SW ID mechanism for updating
 firmware will be disabled.
 * By default, this compile option is disabled.
 */
/* #define CONFIG_UPDATE_FIRMWARE_BY_SW_ID */

/*
 * Note.
 * If this compile option is defined, the update firmware bin file shall be
 stored in a two dimensional array format.
 * Else, the update firmware bin file shall be stored in an one dimensional
 array format.
 * Be careful, MSG22XX only support storing update firmware bin file in an one
 dimensional array format, it does not support two dimensional array format.
 * By default, this compile option is disabled.
 */
/* #define CONFIG_UPDATE_FIRMWARE_BY_TWO_DIMENSIONAL_ARRAY */

/*--------------------------------------------------------------------------*/
/* PREPROCESSOR CONSTANT DEFINITION                                         */
/*--------------------------------------------------------------------------*/

#define u8   unsigned char
#define u16  unsigned short
#define u32  unsigned int
#define s8   signed char
#define s16  signed short
#define s32  signed int

/* #define SLAVE_I2C_ID_DBBUS         (0xB2>>1) //0x59 // for MSG22XX */
/* 0x62 // for MSG21XX/MSG21XXA/MSG26XXM */
#define SLAVE_I2C_ID_DBBUS         (0xC4>>1)
#define SLAVE_I2C_ID_DWI2C         (0x4C>>1)/* 0x26 */

#define CHIP_TYPE_MSG21XX   (0x01)/* EX. MSG2133 */
#define CHIP_TYPE_MSG21XXA  (0x02)
#define CHIP_TYPE_MSG26XXM  (0x03)/* EX. MSG2633M */
#define CHIP_TYPE_MSG22XX   (0x7A)/* EX. MSG2238/MSG2256 */

#define PACKET_TYPE_TOOTH_PATTERN   (0x20)
#define PACKET_TYPE_GESTURE_WAKEUP  (0x50)

/* #define TOUCH_SCREEN_X_MIN   (0) */
/* #define TOUCH_SCREEN_Y_MIN   (0) */
/*
 * Note.
 * Please change the below touch screen resolution according to the touch panel
 that you are using.
 */
/* #define TOUCH_SCREEN_X_MAX   (480) //LCD_WIDTH */
/* #define TOUCH_SCREEN_Y_MAX   (800) //LCD_HEIGHT */
/*
 * Note.
 * Please do not change the below setting.
 */
#define TPD_WIDTH   (2048)
#define TPD_HEIGHT  (2048)

#define BIT0  (1<<0)/* 0x0001 */
#define BIT1  (1<<1)/* 0x0002 */
#define BIT2  (1<<2)/* 0x0004 */
#define BIT3  (1<<3)/* 0x0008 */
#define BIT4  (1<<4)/* 0x0010 */
#define BIT5  (1<<5)/* 0x0020 */
#define BIT6  (1<<6)/* 0x0040 */
#define BIT7  (1<<7)/* 0x0080 */
#define BIT8  (1<<8)/* 0x0100 */
#define BIT9  (1<<9)/* 0x0200 */
#define BIT10 (1<<10)/* 0x0400 */
#define BIT11 (1<<11)/* 0x0800 */
#define BIT12 (1<<12)/* 0x1000 */
#define BIT13 (1<<13)/* 0x2000 */
#define BIT14 (1<<14)/* 0x4000 */
#define BIT15 (1<<15)/* 0x8000 */

#define MAX_DEBUG_REGISTER_NUM     (10)

#ifdef SYSFS_AUTHORITY_CHANGE_FOR_CTS_TEST
#define SYSFS_AUTHORITY (0644)
#else
#define SYSFS_AUTHORITY (0777)
#endif

#ifdef CONFIG_ENABLE_GESTURE_WAKEUP
/* 0000 0000 0000 0001 */
#define GESTURE_WAKEUP_MODE_DOUBLE_CLICK_FLAG     0x0001
/* 0000 0000 0000 0010 */
#define GESTURE_WAKEUP_MODE_UP_DIRECT_FLAG        0x0002
/* 0000 0000 0000 0100 */
#define GESTURE_WAKEUP_MODE_DOWN_DIRECT_FLAG      0x0004
/* 0000 0000 0000 1000 */
#define GESTURE_WAKEUP_MODE_LEFT_DIRECT_FLAG      0x0008
/* 0000 0000 0001 0000 */
#define GESTURE_WAKEUP_MODE_RIGHT_DIRECT_FLAG     0x0010
/* 0000 0000 0010 0000 is  m */
#define GESTURE_WAKEUP_MODE_M_CHARACTER_FLAG      0x0020
/* 0000 0000 0100 0000 */
#define GESTURE_WAKEUP_MODE_W_CHARACTER_FLAG      0x0040
/* 0000 0000 1000 0000 */
#define GESTURE_WAKEUP_MODE_C_CHARACTER_FLAG      0x0080
/* 0000 0001 0000 0000 is e */
#define GESTURE_WAKEUP_MODE_E_CHARACTER_FLAG      0x0100
/* 0000 0010 0000 0000 */
#define GESTURE_WAKEUP_MODE_V_CHARACTER_FLAG      0x0200
/* 0000 0100 0000 0000 */
#define GESTURE_WAKEUP_MODE_O_CHARACTER_FLAG      0x0400
/* 0000 1000 0000 0000 */
#define GESTURE_WAKEUP_MODE_S_CHARACTER_FLAG      0x0800
/* 0001 0000 0000 0000 */
#define GESTURE_WAKEUP_MODE_Z_CHARACTER_FLAG      0x1000

#define GESTURE_WAKEUP_PACKET_LENGTH    (6)
#endif/* CONFIG_ENABLE_GESTURE_WAKEUP */

/*--------------------------------------------------------------------------*/
/* PREPROCESSOR MACRO DEFINITION                                            */
/*--------------------------------------------------------------------------*/

#ifdef CONFIG_ENABLE_TOUCH_DRIVER_DEBUG

#define DBG(fmt, arg...) printk(fmt, ##arg)
#define LOGTP_TAG			"[mstar] "
#define LOGTP_ERRO(fmt, args...)	pr_err(LOGTP_TAG fmt, ##args)
#define LOGTP_WARN(fmt, args...)	pr_warn(LOGTP_TAG fmt, ##args)
#define LOGTP_FUNC()			pr_info(LOGTP_TAG"%s(),entry\n", \
						__func__)
#define LOGTP_FUNX()			pr_info(LOGTP_TAG"%s(),exit\n", \
						__func__)
#define LOGTP_INFO(fmt, args...)	pr_info(LOGTP_TAG fmt, ##args)
#define LOGTP_DBUG(fmt, args...)	pr_debug(LOGTP_TAG fmt, ##args)

#else
#define DBG(fmt, arg...)

#define LOGTP_TAG			"[mstar] "
#define LOGTP_ERRO(fmt, args...)	pr_err(LOGTP_TAG fmt, ##args)
#define LOGTP_WARN(fmt, args...)	pr_warn(LOGTP_TAG fmt, ##args)
#define LOGTP_FUNC()			pr_info(LOGTP_TAG"%s(),entry\n", \
							__func__)
#define LOGTP_FUNX()			pr_info(LOGTP_TAG"%s(),exit\n", \
							__func__)
#define LOGTP_INFO(fmt, args...)
#define LOGTP_DBUG(fmt, args...)
#endif



/*--------------------------------------------------------------------------*/
/* SPREADTRUM  DEFINITION */
/*--------------------------------------------------------------------------*/

/* "msg21xxA" or "msg22xx" or "msg26xxM" */
#define MSG_TP_IC_NAME        "msg2138_ts"
#define MSG_TP_I2C_ADDR      0x26
#define MAX_FINGER_NUM        5

struct msg2138_ts_platform_data {
	int irq_gpio_number;
	int reset_gpio_number;
	const char *vdd_name;
	u32 virtualkeys[12];
	int TP_MAX_X;
	int TP_MAX_Y;
};
struct point_node_t {
	unsigned char active;
	unsigned char finger_id;
	int posx;
	int posy;
};
struct touch_screeninfo_t {
	unsigned char n_touch_keymode;
	unsigned char n_touch_keycode;
};
struct touch_info {
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int p1, p2, p3;
	int count;
};

extern struct i2c_client *gi2c_client;
extern int MS_TS_MSG_IC_GPIO_RST;
extern int MS_TS_MSG_IC_GPIO_INT;
extern int TOUCH_SCREEN_X_MAX;
extern int TOUCH_SCREEN_Y_MAX;
extern struct point_node_t point_slot[MAX_FINGER_NUM * 2];
/*--------------------------------------------------------------------------*/
/* DATA TYPE DEFINITION                                                     */
/*--------------------------------------------------------------------------*/

enum emem_type_e { /* typedef*/
	EMEM_ALL = 0,
	EMEM_MAIN,
	EMEM_INFO
};

enum ito_testmode_e {	/* typedef */
	ITO_TEST_MODE_OPEN_TEST = 1,
	ITO_TEST_MODE_SHORT_TEST = 2
};

enum ito_testresult_e {	/* typedef */
	ITO_TEST_OK = 0,
	ITO_TEST_FAIL,
	ITO_GET_TP_TYPE_ERROR,
	ITO_TEST_UNDEFINED_ERROR,
	ITO_TEST_UNDER_TESTING
};

/*--------------------------------------------------------------------------*/
/* GLOBAL VARIABLE DEFINITION                                               */
/*--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------*/
/* GLOBAL FUNCTION DECLARATION                                              */
/*--------------------------------------------------------------------------*/

extern u8 common_cal_checksum(u8 *p_msg, u32 n_len);
extern u32 common_char_tohexdigit(char *p_chr, u32 n_len);
extern u32 common_crc_reflect(u32 n_ref, s8 n_chr);
extern u32 common_crc_getvalue(u32 n_text, u32 n_prevcrc);
extern void common_crc_inittable(void);

#endif/* __MSTAR_DRV_COMMON_H__ */
