/**
 ******************************************************************************
 * @file   SC32F10xx_rcc.h
 * @author  soc
 * @version V1.5.0
 * @date    07-9-2021
 * @brief   This file provides firmware functions to manage the following
 *
 *  @verbatim
 ******************************************************************************
 * @attention
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SC32F10XX_SPI_H
#define __SC32F10XX_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

/*!< Includes ----------------------------------------------------------------*/
#include "SC32F10xx.h"

/** @addtogroup sc32f10xx_StdPeriph_Driver
 * @{
 */

/** @addtogroup spi
 * @{
 */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/**
 * @}
 */
typedef enum {
    SPI0_CON_SPEN_OFF = 0x00, /*!< 关闭SPI              */
    SPI0_CON_SPEN_ON = 0x01,  /*!< 打开SPI              */
} SPI0_CON_SPEN_TypeDef;
/**
 * @}
 */
typedef enum {
    SPI0_CON_CPOL_LOW = 0x00,  /*!< 时钟空闲为低              */
    SPI0_CON_CPOL_HIGH = 0x01, /*!< 时钟空闲为高   */
} SPI0_CON_CPOL_TypeDef;

/**
 * @}
 */
typedef enum {
    SPI0_CON_CPHA_1 = 0x00, /*!<时钟第一沿采集数据>               */
    SPI0_CON_CPHA_2 = 0x01, /*!< 时钟第二沿采集数据 >             */
} SPI0_CON_CPHA_TypeDef;

/**
 * @}
 */
typedef enum {
    SPI0_CON_DORD_MSB = 0x00, /*!<MSB	>				*/
    SPI0_CON_DORD_LSB = 0x01, /*!<LSB >          */
} SPI0_CON_DORD_TypeDef;

/**
 * @}
 */
typedef enum {
    SPI0_CON_SPMD_8 = 0x00,  /*!<8位模式>  */
    SPI0_CON_SPMD_16 = 0x01, /*!<16位模式>              */
} SPI0_CON_SPMD_TypeDef;

/**
 * @}
 */
typedef enum {
    SPI0_CON_MSTR_Slave =
        0x00,                    /*!<从设备>						*/
    SPI0_CON_MSTR_Master = 0x01, /*!<主设备>              */
} SPI0_CON_MSTR_TypeDef;

/**
 * @}
 */
typedef enum {
    SPI0_CON_SPR_1 = 0x00,   /*!<Fpclk>   */
    SPI0_CON_SPR_2 = 0x01,   /*!<Fpclk/2> */
    SPI0_CON_SPR_4 = 0x02,   /*!<Fpclk/4>   */
    SPI0_CON_SPR_8 = 0x03,   /*!<Fpclk/8> 	*/
    SPI0_CON_SPR_16 = 0x04,  /*!<Fpclk/16>  */
    SPI0_CON_SPR_32 = 0x05,  /*!<Fpclk/32> */
    SPI0_CON_SPR_64 = 0x06,  /*!<Fpclk/64>  */
    SPI0_CON_SPR_128 = 0x07, /*!<Fpclk/128> 	*/
    SPI0_CON_SPR_256 =
        0x08,                /*!<Fpclk/256>						*/
    SPI0_CON_SPR_512 = 0x09, /*!<Fpclk/512> */
    SPI0_CON_SPR_1024 =
        0x0A, /*!<Fpclk/1024>						*/
} SPI0_CON_SPR_TypeDef;

/** @defgroup RCC TI/FLGA Check
 * @{
 */
#define RCC_IT_CLKIF ((uint32_t)0x00000001)
#define RCC_FLAG_PLLRDY ((uint32_t)0x00000002)
#define RCC_FLAG_LOCKERR ((uint32_t)0x00000004)

/** @defgroup System_clock_source
 * @{
 */
#define RCC_SYSCLKSource_LRC ((uint32_t)0x00000000)
#define RCC_SYSCLKSource_HXT ((uint32_t)0x00000100)
#define RCC_SYSCLKSource_PLLCLK ((uint32_t)0x00000200)
#define RCC_SYSCLKSource_LXT ((uint32_t)0x00000300)
/** @defgroup AHB_clock_source
 * @{
 */
#define RCC_SYSCLK_Div1 ((uint32_t)0x00000000)
#define RCC_SYSCLK_Div2 ((uint32_t)0x00100000)
#define RCC_SYSCLK_Div4 ((uint32_t)0x00200000)
#define RCC_SYSCLK_Div8 ((uint32_t)0x00300000)
#define RCC_SYSCLK_Div16 ((uint32_t)0x00400000)

/** @defgroup APB0_APB1_APB2clock_source
 * @{
 */
#define RCC_HCLK_Div1 ((uint32_t)0x00000000)
#define RCC_HCLK_Div2 ((uint32_t)0x00100000)
#define RCC_HCLK_Div4 ((uint32_t)0x00200000)
#define RCC_HCLK_Div8 ((uint32_t)0x00300000)
#define RCC_HCLK_Div16 ((uint32_t)0x00400000)

/** @defgroup AHB_peripheral
 * @{
 */

#define RCC_AHBPeriph_DMA ((uint32_t)0x00000001)
#define RCC_AHBPeriph_CRC ((uint32_t)0x00000002)

/** @defgroup APB0_peripheral
 * @{
 */

#define RCC_APB0Periph_TIM0 ((uint32_t)0x00000001)
#define RCC_APB0Periph_TIM1 ((uint32_t)0x00000002)
#define RCC_APB0Periph_TIM2 ((uint32_t)0x00000004)
#define RCC_APB0Periph_TIM3 ((uint32_t)0x00000008)
#define RCC_APB0Periph_TWI0 ((uint32_t)0x00000010)
#define RCC_APB0Periph_SPI0 ((uint32_t)0x00000020)
#define RCC_APB0Periph_UART0 ((uint32_t)0x00000040)
#define RCC_APB0Periph_UART1 ((uint32_t)0x00000080)
#define RCC_APB0Periph_PWM0 ((uint32_t)0x00000100)
#define RCC_APB0Periph_ALL ((uint32_t)0x000001FF)

/** @defgroup APB1_peripheral
 * @{
 */

#define RCC_APB1Periph_TIM4 ((uint32_t)0x00000001)
#define RCC_APB1Periph_TIM5 ((uint32_t)0x00000002)
#define RCC_APB1Periph_TIM6 ((uint32_t)0x00000004)
#define RCC_APB1Periph_TIM7 ((uint32_t)0x00000008)
#define RCC_APB1Periph_TWI1 ((uint32_t)0x00000010)
#define RCC_APB1Periph_UART2 ((uint32_t)0x00000080)
#define RCC_APB1Periph_ALL ((uint32_t)0x0000009F)

/** @defgroup APB2_peripheral
 * @{
 */

#define RCC_APB2Periph_PWM1 ((uint32_t)0x00000001)
#define RCC_APB2Periph_LCD ((uint32_t)0x00000002)
#define RCC_APB2Periph_UART3 ((uint32_t)0x00000004)
#define RCC_APB2Periph_ALL ((uint32_t)0x00000007)

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/* Configuration of the RCC computation unit **********************************/
void RCC_DeInit(void);
void RCC_HXTCmd(FunctionalState NewState);
void RCC_LXTCmd(FunctionalState NewState);
void RCC_HIRCCmd(FunctionalState NewState);
void RCC_ITConfig(FunctionalState NewState);
void RCC_SYSCLKSWConfig(RCC_CFG0_SYSCLKSW_TypeDef RCC_SYSCLKSW);
void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource);
void RCC_SystickCLKConfig(RCC_SYSTICKCLKSOURCE_TypeDef RCC_SYSTICKSource);
void RCC_HCLKConfig(uint32_t RCC_HCLKCLKSource);
void RCC_APB0KConfig(uint32_t RCC_APB0CLKSource);
void RCC_APB1KConfig(uint32_t RCC_APB1CLKSource);
void RCC_APB2KConfig(uint32_t RCC_APB2CLKSource);
void RCC_PWM0CLKConfig(RCC_PWM0CLKSOURCE_TypeDef RCC_PWM0CLKSource);
void RCC_LCDCLKConfig(RCC_LCDCLKSOURCE_TypeDef RCC_LCDCLKSource);
void RCC_BTMCLKConfig(RCC_BTMCLKSOURCE_TypeDef RCC_BTMCLKSource);

void RCC_PLLRCLKConfig(RCC_PLLCLKSOURCE_TypeDef RCC_PLLCLKSource);
void RCC_PLLCmd(FunctionalState NewState);
void RCC_PLLRCmd(FunctionalState NewState);
void RCC_PLLQCmd(FunctionalState NewState);
ITStatus RCC_GetITStatus(uint32_t RCC_IT);
FlagStatus RCC_GetFlagStatus(uint32_t RCC_FLAG);
void RCC_ClearITPendingBit(uint32_t RCC_IT);

void RCC_APB0Cmd(FunctionalState NewState);
void RCC_APB1Cmd(FunctionalState NewState);
void RCC_APB2Cmd(FunctionalState NewState);
void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState);
void RCC_APB0PeriphClockCmd(uint32_t RCC_APB0Periph, FunctionalState NewState);
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState);
void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState);

#ifdef __cplusplus
}
#endif

#endif /* __SC32F10XX_RCC_H */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
