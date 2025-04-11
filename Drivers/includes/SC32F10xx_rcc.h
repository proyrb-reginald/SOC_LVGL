/**
 ******************************************************************************
 * @file   sc32f10xx_rcc.h
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
#ifndef __SC32F10XX_RCC_H
#define __SC32F10XX_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

/*!< Includes ----------------------------------------------------------------*/
#include "w1222a.h"

/** @addtogroup sc32f10xx_StdPeriph_Driver
 * @{
 */

/** @addtogroup rcc
 * @{
 */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/**
 * @}
 */
typedef enum {
    RCC_CFG0_WAIT0 = 0x00, /*!< 0 wait              */
    RCC_CFG0_WAIT1 = 0x01, /*!< 1 wait              */
    RCC_CFG0_WAIT2 = 0x02, /*!< 2 wait              */
    RCC_CFG0_WAIT3 = 0x03, /*!< 3 wait              */
} RCC_CFG0_WAIT_TypeDef;
/**
 * @}
 */
typedef enum {
    RCC_CFG0_SYSCLKSW_HIRC = 0x00,    /*!< HRC              */
    RCC_CFG0_SYSCLKSEL_CLKSEL = 0x01, /*!< RCC_CFG0_SYSCLKSEL   */
} RCC_CFG0_SYSCLKSW_TypeDef;

/**
 * @}
 */
typedef enum {
    RCC_SYSTICKCLKSOURCE_HLCK_DIV8 =
        0x00,                             /*!<HCLK/8>						*/
    RCC_SYSTICKCLKSOURCE_HRC_DIV2 = 0x01, /*!< HRC/2 >             */
    RCC_SYSTICKCLKSOURCE_HXT_DIV2 = 0x02, /*!< HXT/2 >             */
} RCC_SYSTICKCLKSOURCE_TypeDef;

/**
 * @}
 */
typedef enum {
    RCC_PWM0CLKSOURCE_PCLK = 0x00, /*!<PCLK	> */
    RCC_PWM0CLKSOURCE_PLLQ = 0x01, /*!< PLLQ >          */
} RCC_PWM0CLKSOURCE_TypeDef;

/**
 * @}
 */
typedef enum {
    RCC_LCDCLKSOURCE_LIRC =
        0x00,                    /*!<LIRC>						*/
    RCC_LCDCLKSOURCE_LXT = 0x01, /*!< LXT>              */
} RCC_LCDCLKSOURCE_TypeDef;

/**
 * @}
 */
typedef enum {
    RCC_BTMCLKSOURCE_LIRC =
        0x00,                    /*!<LIRC>						*/
    RCC_BTMCLKSOURCE_LXT = 0x01, /*!< LXT>              */
} RCC_BTMCLKSOURCE_TypeDef;

/**
 * @}
 */
typedef enum {
    RCC_PLLCLKSOURCE_HXT = 0x01,  /*!<HXT>  */
    RCC_PLLCLKSOURCE_HIRC = 0x00, /*!<HIRC>              */
} RCC_PLLCLKSOURCE_TypeDef;

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
#define RCC_AHBPeriph_IFB ((uint32_t)0x00000004)

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
#define RCC_APB0Periph_UART5 ((uint32_t)0x00000200)
#define RCC_APB0Periph_PWM0 ((uint32_t)0x00000100)
#define RCC_APB0Periph_ALL ((uint32_t)0x000001FF)
#define IS_RCC_APB0PERIPH(PERIPH)                                              \
    ((((PERIPH) & (uint8_t)0xFC00) == 0x00) && ((PERIPH) != (uint16_t)0x00))
/** @defgroup APB1_peripheral
 * @{
 */

#define RCC_APB1Periph_TIM4 ((uint32_t)0x00000001)
#define RCC_APB1Periph_TIM5 ((uint32_t)0x00000002)
#define RCC_APB1Periph_TIM6 ((uint32_t)0x00000004)
#define RCC_APB1Periph_TIM7 ((uint32_t)0x00000008)
#define RCC_APB1Periph_TWI1 ((uint32_t)0x00000010)
#define RCC_APB1Periph_UART4 ((uint32_t)0x00000040)
#define RCC_APB1Periph_UART2 ((uint32_t)0x00000080)
#define RCC_APB1Periph_ALL ((uint32_t)0x0000009F)
#define IS_RCC_APB1PERIPH(PERIPH)                                              \
    ((((PERIPH) & (uint8_t)0xFE00) == 0x00) && ((PERIPH) != (uint16_t)0x00))
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
void RCC_LIRCCmd(FunctionalState NewState);
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
void RCC_PLLCLKConfig(RCC_PLLCLKSOURCE_TypeDef RCC_PLLCLKSource);
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

void RCC_APB0PeriphResetCmd(uint32_t RCC_APB0Periph, FunctionalState NewState);
void RCC_APB1PeriphResetCmd(uint32_t RCC_APB0Periph, FunctionalState NewState);
void RCC_APB2PeriphResetCmd(uint32_t RCC_APB0Periph, FunctionalState NewState);
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
