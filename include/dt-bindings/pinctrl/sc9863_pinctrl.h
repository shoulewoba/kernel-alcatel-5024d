#include "pinctrl-common.h"

/* pin_number  ctrl_pin bit_offset bit_width */

/* UART_MATRIX_MTX_CFG */
#define	UART_INF6_SYS_SEL		SPRD_PIN_INFO(0, 1, 28, 4, 1)
#define	UART_INF5_SYS_SEL		SPRD_PIN_INFO(1, 1, 24, 4, 1)
#define	UART_INF4_SYS_SEL		SPRD_PIN_INFO(2, 1, 20, 4, 1)
#define	UART_INF3_SYS_SEL		SPRD_PIN_INFO(3, 1, 16, 4, 1)
#define	UART_INF2_INF3_LOOP		SPRD_PIN_INFO(4, 1, 15, 1, 1)
#define	UART_INF2_INF4_LOOP		SPRD_PIN_INFO(5, 1, 14, 1, 1)
#define	UART_INF2_SYS_SEL		SPRD_PIN_INFO(6, 1, 10, 4, 1)
#define	UART_INF1_INF4_LOOP		SPRD_PIN_INFO(7, 1, 9, 1, 1)
#define	UART_INF1_INF3_LOOP		SPRD_PIN_INFO(8, 1, 8, 1, 1)
#define	UART_INF1_SYS_SEL		SPRD_PIN_INFO(9, 1, 4, 4, 1)
#define	UART_INF0_SYS_SEL		SPRD_PIN_INFO(10, 1, 0, 4, 1)

/* UART_MATRIX_MTX_CFG1 */
#define	UART_INF10_SYS_SEL		SPRD_PIN_INFO(11, 1, 9, 4, 2)
#define	UART_INF9_SYS_SEL		SPRD_PIN_INFO(12, 1, 5, 4, 2)
#define	UART_INF8_INF9_LOOP		SPRD_PIN_INFO(13, 1, 4, 1, 2)
#define	UART_INF8_SYS_SEL		SPRD_PIN_INFO(14, 1, 0, 4, 2)

/* IIS_MATRIX_MTX_CFG */
#define	IIS_INF4_INF3_LOOP		SPRD_PIN_INFO(15, 1, 23, 1, 3)
#define	IIS_INF4_SYS_SEL		SPRD_PIN_INFO(16, 1, 19, 4, 3)
#define	IIS_INF3_SYS_SEL		SPRD_PIN_INFO(17, 1, 15, 4, 3)
#define	IIS_INF2_SYS_SEL		SPRD_PIN_INFO(18, 1, 11, 4, 3)
#define	IIS_INF1_INF2_LOOP		SPRD_PIN_INFO(19, 1, 10, 1, 3)
#define	IIS_INF1_SYS_SEL		SPRD_PIN_INFO(20, 1, 6, 4, 3)
#define	IIS_INF0_INF2_LOOP		SPRD_PIN_INFO(21, 1, 5, 1, 3)
#define	IIS_INF0_INF1_LOOP		SPRD_PIN_INFO(22, 1, 4, 1, 3)
#define	IIS_INF0_SYS_SEL		SPRD_PIN_INFO(23, 1, 0, 4, 3)

/* SIM_MATRIX_MTX_CFG */
#define	SIM_INF2_SYS_SEL		SPRD_PIN_INFO(24, 1, 2, 1, 4)
#define SIM_INF1_SYS_SEL		SPRD_PIN_INFO(25, 1, 1, 1, 4)
#define	SIM_INFO_SYS_SEL		SPRD_PIN_INFO(26, 1, 0, 1, 4)

/* SPI_MATRIX_MTX_CFG */
#define	SPI_INF3_SYS_SEL		SPRD_PIN_INFO(27, 1, 3, 1, 5)
#define	SPI_INF2_SYS_SEL		SPRD_PIN_INFO(28, 1, 2, 1, 5)
#define	SPI_INF1_SYS_SEL		SPRD_PIN_INFO(29, 1, 1, 1, 5)
#define	SPI_INF0_SYS_SEL		SPRD_PIN_INFO(30, 1, 0, 1, 5)

/* IIC_MATRIX_MTX_CFG */
#define	IIC_INF6_SYS_SEL		SPRD_PIN_INFO(31, 1, 12, 2, 6)
#define	IIC_INF5_SYS_SEL		SPRD_PIN_INFO(32, 1, 10, 2, 6)
#define	IIC_INF4_SYS_SEL		SPRD_PIN_INFO(33, 1, 8, 2, 6)
#define	IIC_INF3_SYS_SEL		SPRD_PIN_INFO(34, 1, 6, 2, 6)
#define	IIC_INF2_SYS_SEL		SPRD_PIN_INFO(35, 1, 4, 2, 6)
#define	IIC_INF1_SYS_SEL		SPRD_PIN_INFO(36, 1, 2, 2, 6)
#define	IIC_INF0_SYS_SEL		SPRD_PIN_INFO(37, 1, 0, 2, 6)

/* registers definitions for controller CTL_PIN */
#define	SC9863_IIS1CLK       SPRD_PIN_INFO(38, 0, 0, 0, 0)
#define	SC9863_IIS1DI        SPRD_PIN_INFO(39, 0, 0, 0, 0)
#define	SC9863_IIS1DO        SPRD_PIN_INFO(40, 0, 0, 0, 0)
#define	SC9863_IIS1LRCK      SPRD_PIN_INFO(41, 0, 0, 0, 0)
#define	SC9863_SCL2          SPRD_PIN_INFO(42, 0, 0, 0, 0)
#define	SC9863_SDA2          SPRD_PIN_INFO(43, 0, 0, 0, 0)
#define	SC9863_CLK_AUX0      SPRD_PIN_INFO(44, 0, 0, 0, 0)
#define	SC9863_T_DIG         SPRD_PIN_INFO(45, 0, 0, 0, 0)
#define	SC9863_GNSS_LNA_EN   SPRD_PIN_INFO(46, 0, 0, 0, 0)
#define	SC9863_EXTINT0       SPRD_PIN_INFO(47, 0, 0, 0, 0)
#define	SC9863_EXTINT1       SPRD_PIN_INFO(48, 0, 0, 0, 0)
#define	SC9863_SCL3          SPRD_PIN_INFO(49, 0, 0, 0, 0)
#define	SC9863_SDA3          SPRD_PIN_INFO(50, 0, 0, 0, 0)
#define	SC9863_SCL0          SPRD_PIN_INFO(51, 0, 0, 0, 0)
#define	SC9863_SDA0          SPRD_PIN_INFO(52, 0, 0, 0, 0)
#define	SC9863_SCL1          SPRD_PIN_INFO(53, 0, 0, 0, 0)
#define	SC9863_SDA1          SPRD_PIN_INFO(54, 0, 0, 0, 0)
#define	SC9863_CMPD2         SPRD_PIN_INFO(55, 0, 0, 0, 0)
#define	SC9863_CMRST2        SPRD_PIN_INFO(56, 0, 0, 0, 0)
#define	SC9863_CMMCLK0       SPRD_PIN_INFO(57, 0, 0, 0, 0)
#define	SC9863_CMRST0        SPRD_PIN_INFO(58, 0, 0, 0, 0)
#define	SC9863_CMPD0         SPRD_PIN_INFO(59, 0, 0, 0, 0)
#define	SC9863_CMMCLK1       SPRD_PIN_INFO(60, 0, 0, 0, 0)
#define	SC9863_CMRST1        SPRD_PIN_INFO(61, 0, 0, 0, 0)
#define	SC9863_CMPD1         SPRD_PIN_INFO(62, 0, 0, 0, 0)
#define	SC9863_U0TXD         SPRD_PIN_INFO(63, 0, 0, 0, 0)
#define	SC9863_U0RXD         SPRD_PIN_INFO(64, 0, 0, 0, 0)
#define	SC9863_U0CTS         SPRD_PIN_INFO(65, 0, 0, 0, 0)
#define	SC9863_U0RTS         SPRD_PIN_INFO(66, 0, 0, 0, 0)
#define	SC9863_U1TXDG0       SPRD_PIN_INFO(67, 0, 0, 0, 0)
#define	SC9863_U1RXDG0       SPRD_PIN_INFO(68, 0, 0, 0, 0)
#define	SC9863_U2TXDG0       SPRD_PIN_INFO(69, 0, 0, 0, 0)
#define	SC9863_U2RXDG0       SPRD_PIN_INFO(70, 0, 0, 0, 0)
#define	SC9863_EXTINT9       SPRD_PIN_INFO(71, 0, 0, 0, 0)
#define	SC9863_EXTINT10      SPRD_PIN_INFO(72, 0, 0, 0, 0)
#define	SC9863_SD1_CLK       SPRD_PIN_INFO(73, 0, 0, 0, 0)
#define	SC9863_SD1_CMD       SPRD_PIN_INFO(74, 0, 0, 0, 0)
#define	SC9863_SD1_D0        SPRD_PIN_INFO(75, 0, 0, 0, 0)
#define	SC9863_SD1_D1        SPRD_PIN_INFO(76, 0, 0, 0, 0)
#define	SC9863_SD1_D2        SPRD_PIN_INFO(77, 0, 0, 0, 0)
#define	SC9863_SD1_D3        SPRD_PIN_INFO(78, 0, 0, 0, 0)
#define	SC9863_DMIC_CLKG0    SPRD_PIN_INFO(79, 0, 0, 0, 0)
#define	SC9863_DMIC_DATG0    SPRD_PIN_INFO(80, 0, 0, 0, 0)
#define	SC9863_DMIC_CLKG1    SPRD_PIN_INFO(81, 0, 0, 0, 0)
#define	SC9863_DMIC_DATG1    SPRD_PIN_INFO(82, 0, 0, 0, 0)
#define	SC9863_IIS0DI        SPRD_PIN_INFO(83, 0, 0, 0, 0)
#define	SC9863_IIS0DO        SPRD_PIN_INFO(84, 0, 0, 0, 0)
#define	SC9863_IIS0CLK       SPRD_PIN_INFO(85, 0, 0, 0, 0)
#define	SC9863_IIS0LRCK      SPRD_PIN_INFO(86, 0, 0, 0, 0)
#define	SC9863_U4TXD         SPRD_PIN_INFO(87, 0, 0, 0, 0)
#define	SC9863_U4RXD         SPRD_PIN_INFO(88, 0, 0, 0, 0)
#define	SC9863_U4CTS         SPRD_PIN_INFO(89, 0, 0, 0, 0)
#define	SC9863_U4RTS         SPRD_PIN_INFO(90, 0, 0, 0, 0)
#define	SC9863_U5TXD         SPRD_PIN_INFO(91, 0, 0, 0, 0)
#define	SC9863_U5RXD         SPRD_PIN_INFO(92, 0, 0, 0, 0)
#define	SC9863_SCL6          SPRD_PIN_INFO(93, 0, 0, 0, 0)
#define	SC9863_SDA6          SPRD_PIN_INFO(94, 0, 0, 0, 0)
#define	SC9863_EMMC_D3       SPRD_PIN_INFO(95, 0, 0, 0, 0)
#define	SC9863_EMMC_D7       SPRD_PIN_INFO(96, 0, 0, 0, 0)
#define	SC9863_EMMC_D4       SPRD_PIN_INFO(97, 0, 0, 0, 0)
#define	SC9863_EMMC_D2       SPRD_PIN_INFO(98, 0, 0, 0, 0)
#define	SC9863_EMMC_DS       SPRD_PIN_INFO(99, 0, 0, 0, 0)
#define	SC9863_EMMC_CLK      SPRD_PIN_INFO(100, 0, 0, 0, 0)
#define	SC9863_EMMC_D5       SPRD_PIN_INFO(101, 0, 0, 0, 0)
#define	SC9863_EMMC_D1       SPRD_PIN_INFO(102, 0, 0, 0, 0)
#define	SC9863_EMMC_CMD      SPRD_PIN_INFO(103, 0, 0, 0, 0)
#define	SC9863_EMMC_D0       SPRD_PIN_INFO(104, 0, 0, 0, 0)
#define SC9863_EMMC_RST      SPRD_PIN_INFO(105, 0, 0, 0, 0)
#define	SC9863_EMMC_D6       SPRD_PIN_INFO(106, 0, 0, 0, 0)
#define	SC9863_NF_DATA_1     SPRD_PIN_INFO(107, 0, 0, 0, 0)
#define	SC9863_NF_CEN0       SPRD_PIN_INFO(108, 0, 0, 0, 0)
#define	SC9863_NF_DATA_2     SPRD_PIN_INFO(109, 0, 0, 0, 0)
#define	SC9863_NF_DATA_0     SPRD_PIN_INFO(110, 0, 0, 0, 0)
#define	SC9863_NF_WEN        SPRD_PIN_INFO(111, 0, 0, 0, 0)
#define SC9863_LCM_FMARK     SPRD_PIN_INFO(112, 0, 0, 0, 0)
#define	SC9863_XTL_BUF_EN2   SPRD_PIN_INFO(113, 0, 0, 0, 0)
#define	SC9863_XTL_BUF_EN1   SPRD_PIN_INFO(114, 0, 0, 0, 0)
#define	SC9863_AUD_SCLK      SPRD_PIN_INFO(115, 0, 0, 0, 0)
#define	SC9863_LCM_RSTN      SPRD_PIN_INFO(116, 0, 0, 0, 0)
#define	SC9863_AUD_ADD0      SPRD_PIN_INFO(117, 0, 0, 0, 0)
#define	SC9863_CHIP_SLEEP    SPRD_PIN_INFO(118, 0, 0, 0, 0)
#define	SC9863_PTEST         SPRD_PIN_INFO(119, 0, 0, 0, 0)
#define	SC9863_EXT_RST_B     SPRD_PIN_INFO(120, 0, 0, 0, 0)
#define	SC9863_AUD_ADSYNC    SPRD_PIN_INFO(121, 0, 0, 0, 0)
#define	SC9863_AUD_DASYNC    SPRD_PIN_INFO(122, 0, 0, 0, 0)
#define	SC9863_DCDCARM_EN    SPRD_PIN_INFO(123, 0, 0, 0, 0)
#define	SC9863_AUD_DAD0      SPRD_PIN_INFO(124, 0, 0, 0, 0)
#define	SC9863_AUD_DAD1      SPRD_PIN_INFO(125, 0, 0, 0, 0)
#define	SC9863_CLK_32K       SPRD_PIN_INFO(126, 0, 0, 0, 0)
#define SC9863_ADI_D         SPRD_PIN_INFO(127, 0, 0, 0, 0)
#define	SC9863_ADI_SCLK      SPRD_PIN_INFO(128, 0, 0, 0, 0)
#define	SC9863_ANA_INT       SPRD_PIN_INFO(129, 0, 0, 0, 0)
#define	SC9863_ADI_SYNC      SPRD_PIN_INFO(130, 0, 0, 0, 0)
#define	SC9863_SD0_CMD       SPRD_PIN_INFO(131, 0, 0, 0, 0)
#define	SC9863_SD0_D1        SPRD_PIN_INFO(132, 0, 0, 0, 0)
#define	SC9863_SD0_D0        SPRD_PIN_INFO(133, 0, 0, 0, 0)
#define	SC9863_SD0_CLK       SPRD_PIN_INFO(134, 0, 0, 0, 0)
#define	SC9863_SD0_D2        SPRD_PIN_INFO(135, 0, 0, 0, 0)
#define	SC9863_SD0_D3        SPRD_PIN_INFO(136, 0, 0, 0, 0)
#define	SC9863_SD2_CLK       SPRD_PIN_INFO(137, 0, 0, 0, 0)
#define	SC9863_SD2_D1        SPRD_PIN_INFO(138, 0, 0, 0, 0)
#define	SC9863_SD2_D0        SPRD_PIN_INFO(139, 0, 0, 0, 0)
#define	SC9863_SD2_CMD       SPRD_PIN_INFO(140, 0, 0, 0, 0)
#define	SC9863_SD2_D3        SPRD_PIN_INFO(141, 0, 0, 0, 0)
#define	SC9863_SD2_D2        SPRD_PIN_INFO(142, 0, 0, 0, 0)
#define SC9863_SIMCLK0       SPRD_PIN_INFO(143, 0, 0, 0, 0)
#define SC9863_SIMDAT0       SPRD_PIN_INFO(144, 0, 0, 0, 0)
#define	SC9863_SIMRST0       SPRD_PIN_INFO(145, 0, 0, 0, 0)
#define	SC9863_SIMCLK1       SPRD_PIN_INFO(146, 0, 0, 0, 0)
#define SC9863_SIMDAT1       SPRD_PIN_INFO(147, 0, 0, 0, 0)
#define	SC9863_SIMRST1       SPRD_PIN_INFO(148, 0, 0, 0, 0)
#define	SC9863_SIMCLK2       SPRD_PIN_INFO(149, 0, 0, 0, 0)
#define	SC9863_SIMDAT2       SPRD_PIN_INFO(150, 0, 0, 0, 0)
#define	SC9863_SIMRST2       SPRD_PIN_INFO(151, 0, 0, 0, 0)
#define SC9863_KEYOUT0       SPRD_PIN_INFO(152, 0, 0, 0, 0)
#define	SC9863_KEYOUT1       SPRD_PIN_INFO(153, 0, 0, 0, 0)
#define	SC9863_KEYOUT2       SPRD_PIN_INFO(154, 0, 0, 0, 0)
#define	SC9863_KEYIN0        SPRD_PIN_INFO(155, 0, 0, 0, 0)
#define	SC9863_KEYIN1        SPRD_PIN_INFO(156, 0, 0, 0, 0)
#define	SC9863_KEYIN2        SPRD_PIN_INFO(157, 0, 0, 0, 0)
#define	SC9863_RFFE0_SCK     SPRD_PIN_INFO(158, 0, 0, 0, 0)
#define	SC9863_RFFE0_SDA     SPRD_PIN_INFO(159, 0, 0, 0, 0)
#define	SC9863_RFCTL0        SPRD_PIN_INFO(160, 0, 0, 0, 0)
#define	SC9863_RFCTL1        SPRD_PIN_INFO(161, 0, 0, 0, 0)
#define	SC9863_RFCTL2        SPRD_PIN_INFO(162, 0, 0, 0, 0)
#define	SC9863_RFCTL3        SPRD_PIN_INFO(163, 0, 0, 0, 0)
#define	SC9863_RFCTL4        SPRD_PIN_INFO(164, 0, 0, 0, 0)
#define	SC9863_RFCTL5        SPRD_PIN_INFO(165, 0, 0, 0, 0)
#define	SC9863_RFCTL6        SPRD_PIN_INFO(166, 0, 0, 0, 0)
#define	SC9863_RFCTL7        SPRD_PIN_INFO(167, 0, 0, 0, 0)
#define SC9863_RFCTL8        SPRD_PIN_INFO(168, 0, 0, 0, 0)
#define	SC9863_RFCTL9        SPRD_PIN_INFO(169, 0, 0, 0, 0)
#define	SC9863_RFCTL10       SPRD_PIN_INFO(170, 0, 0, 0, 0)
#define	SC9863_RFCTL11       SPRD_PIN_INFO(171, 0, 0, 0, 0)
#define	SC9863_GPIO31        SPRD_PIN_INFO(172, 0, 0, 0, 0)
#define	SC9863_GPIO32        SPRD_PIN_INFO(173, 0, 0, 0, 0)
#define	SC9863_RFFE1_SCK     SPRD_PIN_INFO(174, 0, 0, 0, 0)
#define	SC9863_RFFE1_SDA     SPRD_PIN_INFO(175, 0, 0, 0, 0)
#define	SC9863_GPIO33        SPRD_PIN_INFO(176, 0, 0, 0, 0)
#define	SC9863_RFCTL16       SPRD_PIN_INFO(177, 0, 0, 0, 0)
#define	SC9863_RFCTL17       SPRD_PIN_INFO(178, 0, 0, 0, 0)
#define	SC9863_GPIO9         SPRD_PIN_INFO(179, 0, 0, 0, 0)
#define	SC9863_RFCTL19       SPRD_PIN_INFO(180, 0, 0, 0, 0)
#define	SC9863_RFCTL20       SPRD_PIN_INFO(181, 0, 0, 0, 0)
#define	SC9863_RFSDA1        SPRD_PIN_INFO(182, 0, 0, 0, 0)
#define	SC9863_RFSCK1        SPRD_PIN_INFO(183, 0, 0, 0, 0)
#define	SC9863_RFSEN1        SPRD_PIN_INFO(184, 0, 0, 0, 0)
#define	SC9863_RFSDA0        SPRD_PIN_INFO(185, 0, 0, 0, 0)
#define	SC9863_RFSCK0        SPRD_PIN_INFO(186, 0, 0, 0, 0)
#define	SC9863_RFSEN0        SPRD_PIN_INFO(187, 0, 0, 0, 0)
#define	SC9863_LVDSRF0_ADCON SPRD_PIN_INFO(188, 0, 0, 0, 0)
#define	SC9863_LVDSRF0_DACON SPRD_PIN_INFO(189, 0, 0, 0, 0)
#define	SC9863_SPI2_CSN      SPRD_PIN_INFO(190, 0, 0, 0, 0)
#define	SC9863_SPI2_DO       SPRD_PIN_INFO(191, 0, 0, 0, 0)
#define	SC9863_SPI2_DI       SPRD_PIN_INFO(192, 0, 0, 0, 0)
#define	SC9863_SPI2_CLK      SPRD_PIN_INFO(193, 0, 0, 0, 0)
#define	SC9863_SPI0_CSN      SPRD_PIN_INFO(194, 0, 0, 0, 0)
#define	SC9863_SPI0_DO       SPRD_PIN_INFO(195, 0, 0, 0, 0)
#define	SC9863_SPI0_DI       SPRD_PIN_INFO(196, 0, 0, 0, 0)
#define SC9863_SPI0_CLK      SPRD_PIN_INFO(197, 0, 0, 0, 0)
#define SC9863_TDO_LTE       SPRD_PIN_INFO(198, 0, 0, 0, 0)
#define SC9863_TDI_LTE       SPRD_PIN_INFO(199, 0, 0, 0, 0)
#define SC9863_TCK_LTE       SPRD_PIN_INFO(200, 0, 0, 0, 0)
#define SC9863_TMS_LTE       SPRD_PIN_INFO(201, 0, 0, 0, 0)
#define SC9863_RTCK_LTE      SPRD_PIN_INFO(202, 0, 0, 0, 0)
#define SC9863_TCK_ARM       SPRD_PIN_INFO(203, 0, 0, 0, 0)
#define SC9863_TMS_ARM       SPRD_PIN_INFO(204, 0, 0, 0, 0)

/* registers definitions for controller MISC_CTL_PIN */
#define	SC9863_MISC_IIS1CLK       SPRD_PIN_INFO(205, 2, 0, 0, 0)
#define	SC9863_MISC_IIS1DI        SPRD_PIN_INFO(206, 2, 0, 0, 0)
#define	SC9863_MISC_IIS1DO        SPRD_PIN_INFO(207, 2, 0, 0, 0)
#define	SC9863_MISC_IIS1LRCK      SPRD_PIN_INFO(208, 2, 0, 0, 0)
#define	SC9863_MISC_SCL2          SPRD_PIN_INFO(209, 2, 0, 0, 0)
#define	SC9863_MISC_SDA2          SPRD_PIN_INFO(210, 2, 0, 0, 0)
#define	SC9863_MISC_CLK_AUX0      SPRD_PIN_INFO(211, 2, 0, 0, 0)
#define	SC9863_MISC_T_DIG         SPRD_PIN_INFO(212, 2, 0, 0, 0)
#define	SC9863_MISC_GNSS_LNA_EN   SPRD_PIN_INFO(213, 2, 0, 0, 0)
#define	SC9863_MISC_EXTINT0       SPRD_PIN_INFO(214, 2, 0, 0, 0)
#define	SC9863_MISC_EXTINT1       SPRD_PIN_INFO(215, 2, 0, 0, 0)
#define	SC9863_MISC_SCL3          SPRD_PIN_INFO(216, 2, 0, 0, 0)
#define	SC9863_MISC_SDA3          SPRD_PIN_INFO(217, 2, 0, 0, 0)
#define	SC9863_MISC_SCL0          SPRD_PIN_INFO(218, 2, 0, 0, 0)
#define	SC9863_MISC_SDA0          SPRD_PIN_INFO(219, 2, 0, 0, 0)
#define	SC9863_MISC_SCL1          SPRD_PIN_INFO(220, 2, 0, 0, 0)
#define	SC9863_MISC_SDA1          SPRD_PIN_INFO(221, 2, 0, 0, 0)
#define	SC9863_MISC_CMPD2         SPRD_PIN_INFO(222, 2, 0, 0, 0)
#define	SC9863_MISC_CMRST2        SPRD_PIN_INFO(223, 2, 0, 0, 0)
#define	SC9863_MISC_CMMCLK0       SPRD_PIN_INFO(224, 2, 0, 0, 0)
#define	SC9863_MISC_CMRST0        SPRD_PIN_INFO(225, 2, 0, 0, 0)
#define	SC9863_MISC_CMPD0         SPRD_PIN_INFO(226, 2, 0, 0, 0)
#define	SC9863_MISC_CMMCLK1       SPRD_PIN_INFO(227, 2, 0, 0, 0)
#define	SC9863_MISC_CMRST1        SPRD_PIN_INFO(228, 2, 0, 0, 0)
#define	SC9863_MISC_CMPD1         SPRD_PIN_INFO(229, 2, 0, 0, 0)
#define	SC9863_MISC_U0TXD         SPRD_PIN_INFO(230, 2, 0, 0, 0)
#define	SC9863_MISC_U0RXD         SPRD_PIN_INFO(231, 2, 0, 0, 0)
#define	SC9863_MISC_U0CTS         SPRD_PIN_INFO(232, 2, 0, 0, 0)
#define	SC9863_MISC_U0RTS         SPRD_PIN_INFO(233, 2, 0, 0, 0)
#define	SC9863_MISC_U1TXDG0       SPRD_PIN_INFO(234, 2, 0, 0, 0)
#define	SC9863_MISC_U1RXDG0       SPRD_PIN_INFO(235, 2, 0, 0, 0)
#define	SC9863_MISC_U2TXDG0       SPRD_PIN_INFO(236, 2, 0, 0, 0)
#define	SC9863_MISC_U2RXDG0       SPRD_PIN_INFO(237, 2, 0, 0, 0)
#define	SC9863_MISC_EXTINT9       SPRD_PIN_INFO(238, 2, 0, 0, 0)
#define	SC9863_MISC_EXTINT10      SPRD_PIN_INFO(239, 2, 0, 0, 0)
#define	SC9863_MISC_SD1_CLK       SPRD_PIN_INFO(240, 2, 0, 0, 0)
#define	SC9863_MISC_SD1_CMD       SPRD_PIN_INFO(241, 2, 0, 0, 0)
#define	SC9863_MISC_SD1_D0        SPRD_PIN_INFO(242, 2, 0, 0, 0)
#define	SC9863_MISC_SD1_D1        SPRD_PIN_INFO(243, 2, 0, 0, 0)
#define	SC9863_MISC_SD1_D2        SPRD_PIN_INFO(244, 2, 0, 0, 0)
#define	SC9863_MISC_SD1_D3        SPRD_PIN_INFO(245, 2, 0, 0, 0)
#define	SC9863_MISC_DMIC_CLKG0    SPRD_PIN_INFO(246, 2, 0, 0, 0)
#define	SC9863_MISC_DMIC_DATG0    SPRD_PIN_INFO(247, 2, 0, 0, 0)
#define	SC9863_MISC_DMIC_CLKG1    SPRD_PIN_INFO(248, 2, 0, 0, 0)
#define	SC9863_MISC_DMIC_DATG1    SPRD_PIN_INFO(249, 2, 0, 0, 0)
#define	SC9863_MISC_IIS0DI        SPRD_PIN_INFO(250, 2, 0, 0, 0)
#define	SC9863_MISC_IIS0DO        SPRD_PIN_INFO(251, 2, 0, 0, 0)
#define	SC9863_MISC_IIS0CLK       SPRD_PIN_INFO(252, 2, 0, 0, 0)
#define	SC9863_MISC_IIS0LRCK      SPRD_PIN_INFO(253, 2, 0, 0, 0)
#define	SC9863_MISC_U4TXD         SPRD_PIN_INFO(254, 2, 0, 0, 0)
#define	SC9863_MISC_U4RXD         SPRD_PIN_INFO(255, 2, 0, 0, 0)
#define	SC9863_MISC_U4CTS         SPRD_PIN_INFO(256, 2, 0, 0, 0)
#define	SC9863_MISC_U4RTS         SPRD_PIN_INFO(257, 2, 0, 0, 0)
#define	SC9863_MISC_U5TXD         SPRD_PIN_INFO(258, 2, 0, 0, 0)
#define	SC9863_MISC_U5RXD         SPRD_PIN_INFO(259, 2, 0, 0, 0)
#define	SC9863_MISC_SCL6          SPRD_PIN_INFO(260, 2, 0, 0, 0)
#define	SC9863_MISC_SDA6          SPRD_PIN_INFO(261, 2, 0, 0, 0)
#define	SC9863_MISC_EMMC_D3       SPRD_PIN_INFO(262, 2, 0, 0, 0)
#define	SC9863_MISC_EMMC_D7       SPRD_PIN_INFO(263, 2, 0, 0, 0)
#define	SC9863_MISC_EMMC_D4       SPRD_PIN_INFO(264, 2, 0, 0, 0)
#define	SC9863_MISC_EMMC_D2       SPRD_PIN_INFO(265, 2, 0, 0, 0)
#define	SC9863_MISC_EMMC_DS       SPRD_PIN_INFO(266, 2, 0, 0, 0)
#define	SC9863_MISC_EMMC_CLK      SPRD_PIN_INFO(267, 2, 0, 0, 0)
#define	SC9863_MISC_EMMC_D5       SPRD_PIN_INFO(268, 2, 0, 0, 0)
#define	SC9863_MISC_EMMC_D1       SPRD_PIN_INFO(269, 2, 0, 0, 0)
#define	SC9863_MISC_EMMC_CMD      SPRD_PIN_INFO(270, 2, 0, 0, 0)
#define	SC9863_MISC_EMMC_D0       SPRD_PIN_INFO(271, 2, 0, 0, 0)
#define SC9863_MISC_EMMC_RST      SPRD_PIN_INFO(272, 2, 0, 0, 0)
#define	SC9863_MISC_EMMC_D6       SPRD_PIN_INFO(273, 2, 0, 0, 0)
#define	SC9863_MISC_NF_DATA_1     SPRD_PIN_INFO(274, 2, 0, 0, 0)
#define	SC9863_MISC_NF_CEN0       SPRD_PIN_INFO(275, 2, 0, 0, 0)
#define	SC9863_MISC_NF_DATA_2     SPRD_PIN_INFO(276, 2, 0, 0, 0)
#define	SC9863_MISC_NF_DATA_0     SPRD_PIN_INFO(277, 2, 0, 0, 0)
#define	SC9863_MISC_NF_WEN        SPRD_PIN_INFO(278, 2, 0, 0, 0)
#define SC9863_MISC_LCM_FMARK     SPRD_PIN_INFO(279, 2, 0, 0, 0)
#define	SC9863_MISC_XTL_BUF_EN2   SPRD_PIN_INFO(280, 2, 0, 0, 0)
#define	SC9863_MISC_XTL_BUF_EN1   SPRD_PIN_INFO(281, 2, 0, 0, 0)
#define	SC9863_MISC_AUD_SCLK      SPRD_PIN_INFO(282, 2, 0, 0, 0)
#define	SC9863_MISC_LCM_RSTN      SPRD_PIN_INFO(283, 2, 0, 0, 0)
#define	SC9863_MISC_AUD_ADD0      SPRD_PIN_INFO(284, 2, 0, 0, 0)
#define	SC9863_MISC_CHIP_SLEEP    SPRD_PIN_INFO(285, 2, 0, 0, 0)
#define	SC9863_MISC_PTEST         SPRD_PIN_INFO(286, 2, 0, 0, 0)
#define	SC9863_MISC_EXT_RST_B     SPRD_PIN_INFO(287, 2, 0, 0, 0)
#define	SC9863_MISC_AUD_ADSYNC    SPRD_PIN_INFO(288, 2, 0, 0, 0)
#define	SC9863_MISC_AUD_DASYNC    SPRD_PIN_INFO(289, 2, 0, 0, 0)
#define	SC9863_MISC_DCDCARM_EN    SPRD_PIN_INFO(290, 2, 0, 0, 0)
#define	SC9863_MISC_AUD_DAD0      SPRD_PIN_INFO(291, 2, 0, 0, 0)
#define	SC9863_MISC_AUD_DAD1      SPRD_PIN_INFO(292, 2, 0, 0, 0)
#define	SC9863_MISC_CLK_32K       SPRD_PIN_INFO(293, 2, 0, 0, 0)
#define SC9863_MISC_ADI_D         SPRD_PIN_INFO(294, 2, 0, 0, 0)
#define	SC9863_MISC_ADI_SCLK      SPRD_PIN_INFO(295, 2, 0, 0, 0)
#define	SC9863_MISC_ANA_INT       SPRD_PIN_INFO(296, 2, 0, 0, 0)
#define	SC9863_MISC_ADI_SYNC      SPRD_PIN_INFO(297, 2, 0, 0, 0)
#define	SC9863_MISC_SD0_CMD       SPRD_PIN_INFO(298, 2, 0, 0, 0)
#define	SC9863_MISC_SD0_D1        SPRD_PIN_INFO(299, 2, 0, 0, 0)
#define	SC9863_MISC_SD0_D0        SPRD_PIN_INFO(300, 2, 0, 0, 0)
#define	SC9863_MISC_SD0_CLK       SPRD_PIN_INFO(301, 2, 0, 0, 0)
#define	SC9863_MISC_SD0_D2        SPRD_PIN_INFO(302, 2, 0, 0, 0)
#define	SC9863_MISC_SD0_D3        SPRD_PIN_INFO(303, 2, 0, 0, 0)
#define	SC9863_MISC_SD2_CLK       SPRD_PIN_INFO(304, 2, 0, 0, 0)
#define	SC9863_MISC_SD2_D1        SPRD_PIN_INFO(305, 2, 0, 0, 0)
#define	SC9863_MISC_SD2_D0        SPRD_PIN_INFO(306, 2, 0, 0, 0)
#define	SC9863_MISC_SD2_CMD       SPRD_PIN_INFO(307, 2, 0, 0, 0)
#define	SC9863_MISC_SD2_D3        SPRD_PIN_INFO(308, 2, 0, 0, 0)
#define	SC9863_MISC_SD2_D2        SPRD_PIN_INFO(309, 2, 0, 0, 0)
#define SC9863_MISC_SIMCLK0       SPRD_PIN_INFO(310, 2, 0, 0, 0)
#define SC9863_MISC_SIMDAT0       SPRD_PIN_INFO(311, 2, 0, 0, 0)
#define	SC9863_MISC_SIMRST0       SPRD_PIN_INFO(312, 2, 0, 0, 0)
#define	SC9863_MISC_SIMCLK1       SPRD_PIN_INFO(313, 2, 0, 0, 0)
#define SC9863_MISC_SIMDAT1       SPRD_PIN_INFO(314, 2, 0, 0, 0)
#define	SC9863_MISC_SIMRST1       SPRD_PIN_INFO(315, 2, 0, 0, 0)
#define	SC9863_MISC_SIMCLK2       SPRD_PIN_INFO(316, 2, 0, 0, 0)
#define	SC9863_MISC_SIMDAT2       SPRD_PIN_INFO(317, 2, 0, 0, 0)
#define	SC9863_MISC_SIMRST2       SPRD_PIN_INFO(318, 2, 0, 0, 0)
#define SC9863_MISC_KEYOUT0       SPRD_PIN_INFO(319, 2, 0, 0, 0)
#define	SC9863_MISC_KEYOUT1       SPRD_PIN_INFO(320, 2, 0, 0, 0)
#define	SC9863_MISC_KEYOUT2       SPRD_PIN_INFO(321, 2, 0, 0, 0)
#define	SC9863_MISC_KEYIN0        SPRD_PIN_INFO(322, 2, 0, 0, 0)
#define	SC9863_MISC_KEYIN1        SPRD_PIN_INFO(323, 2, 0, 0, 0)
#define	SC9863_MISC_KEYIN2        SPRD_PIN_INFO(324, 2, 0, 0, 0)
#define	SC9863_MISC_RFFE0_SCK     SPRD_PIN_INFO(325, 2, 0, 0, 0)
#define	SC9863_MISC_RFFE0_SDA     SPRD_PIN_INFO(326, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL0        SPRD_PIN_INFO(327, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL1        SPRD_PIN_INFO(328, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL2        SPRD_PIN_INFO(329, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL3        SPRD_PIN_INFO(330, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL4        SPRD_PIN_INFO(331, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL5        SPRD_PIN_INFO(332, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL6        SPRD_PIN_INFO(333, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL7        SPRD_PIN_INFO(334, 2, 0, 0, 0)
#define SC9863_MISC_RFCTL8        SPRD_PIN_INFO(335, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL9        SPRD_PIN_INFO(336, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL10       SPRD_PIN_INFO(337, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL11       SPRD_PIN_INFO(338, 2, 0, 0, 0)
#define	SC9863_MISC_GPIO31        SPRD_PIN_INFO(339, 2, 0, 0, 0)
#define	SC9863_MISC_GPIO32        SPRD_PIN_INFO(340, 2, 0, 0, 0)
#define	SC9863_MISC_RFFE1_SCK     SPRD_PIN_INFO(341, 2, 0, 0, 0)
#define	SC9863_MISC_RFFE1_SDA     SPRD_PIN_INFO(342, 2, 0, 0, 0)
#define	SC9863_MISC_GPIO33        SPRD_PIN_INFO(343, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL16       SPRD_PIN_INFO(344, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL17       SPRD_PIN_INFO(345, 2, 0, 0, 0)
#define	SC9863_MISC_GPIO9         SPRD_PIN_INFO(346, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL19       SPRD_PIN_INFO(347, 2, 0, 0, 0)
#define	SC9863_MISC_RFCTL20       SPRD_PIN_INFO(348, 2, 0, 0, 0)
#define	SC9863_MISC_RFSDA1        SPRD_PIN_INFO(349, 2, 0, 0, 0)
#define	SC9863_MISC_RFSCK1        SPRD_PIN_INFO(350, 2, 0, 0, 0)
#define	SC9863_MISC_RFSEN1        SPRD_PIN_INFO(351, 2, 0, 0, 0)
#define	SC9863_MISC_RFSDA0        SPRD_PIN_INFO(352, 2, 0, 0, 0)
#define	SC9863_MISC_RFSCK0        SPRD_PIN_INFO(353, 2, 0, 0, 0)
#define	SC9863_MISC_RFSEN0        SPRD_PIN_INFO(354, 2, 0, 0, 0)
#define	SC9863_MISC_LVDSRF0_ADCON SPRD_PIN_INFO(355, 2, 0, 0, 0)
#define	SC9863_MISC_LVDSRF0_DACON SPRD_PIN_INFO(356, 2, 0, 0, 0)
#define	SC9863_MISC_SPI2_CSN      SPRD_PIN_INFO(357, 2, 0, 0, 0)
#define	SC9863_MISC_SPI2_DO       SPRD_PIN_INFO(358, 2, 0, 0, 0)
#define	SC9863_MISC_SPI2_DI       SPRD_PIN_INFO(359, 2, 0, 0, 0)
#define	SC9863_MISC_SPI2_CLK      SPRD_PIN_INFO(360, 2, 0, 0, 0)
#define	SC9863_MISC_SPI0_CSN      SPRD_PIN_INFO(361, 2, 0, 0, 0)
#define	SC9863_MISC_SPI0_DO       SPRD_PIN_INFO(362, 2, 0, 0, 0)
#define	SC9863_MISC_SPI0_DI       SPRD_PIN_INFO(363, 2, 0, 0, 0)
#define SC9863_MISC_SPI0_CLK      SPRD_PIN_INFO(364, 2, 0, 0, 0)
#define SC9863_MISC_TDO_LTE       SPRD_PIN_INFO(365, 2, 0, 0, 0)
#define SC9863_MISC_TDI_LTE       SPRD_PIN_INFO(366, 2, 0, 0, 0)
#define SC9863_MISC_TCK_LTE       SPRD_PIN_INFO(367, 2, 0, 0, 0)
#define SC9863_MISC_TMS_LTE       SPRD_PIN_INFO(368, 2, 0, 0, 0)
#define SC9863_MISC_RTCK_LTE      SPRD_PIN_INFO(369, 2, 0, 0, 0)
#define SC9863_MISC_TCK_ARM       SPRD_PIN_INFO(370, 2, 0, 0, 0)
#define SC9863_MISC_TMS_ARM       SPRD_PIN_INFO(371, 2, 0, 0, 0)
