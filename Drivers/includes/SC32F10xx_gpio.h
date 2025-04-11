/**
 ******************************************************************************
 * @file    SC32f10xx_gpio.h
 * @author  SOC
 * @version V1.0.1
 * @date    07-9-2021
 * @brief   This file contains all the functions prototypes for the GPIO
 ******************************************************************************
 * @attention
 *
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SC32F10XX_GPIO_H
#define __SC32F10XX_GPIO_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "w1222a.h"

/** @addtogroup SC32F10xx_StdPeriph_Driver
 * @{
 */

/** @addtogroup GPIO
 * @{
 */
/* Exported types ------------------------------------------------------------*/

#define IS_GPIO_ALL_PERIPH(PERIPH)                                             \
    (((PERIPH) == GPIOA) || ((PERIPH) == GPIOB) || ((PERIPH) == GPIOC))
/** @defgroup GPIOMode_TypeDef
 * @{
 */
typedef enum {
    GPIO_Mode_IN = 0x00,  /*!< GPIO Input Mode              */
    GPIO_Mode_OUT = 0x01, /*!< GPIO Output Mode             */
} GPIOMode_TypeDef;

#define IS_GPIO_MODE(MODE)                                                     \
    (((MODE) == GPIO_Mode_IN) || ((MODE) == GPIO_Mode_OUT))

/**
 * @}
 */

/** @defgroup GPIOOType_TypeDef
 * @{
 */
typedef enum { GPIO_OType_PP = 0x00, GPIO_OType_OD = 0x01 } GPIOOType_TypeDef;

#define IS_GPIO_OTYPE(OTYPE)                                                   \
    (((OTYPE) == GPIO_OType_PP) || ((OTYPE) == GPIO_OType_OD))

/**
 * @}
 */

/** @defgroup GPIOSpeed_TypeDef
 * @{
 */
typedef enum {
    GPIO_Speed_Level_1 = 0x00, /*!< I/O output speed: Low 2 MHz */
    GPIO_Speed_Level_2 = 0x01, /*!< I/O output speed: Medium 10 MHz */
    GPIO_Speed_Level_3 = 0x03  /*!< I/O output speed: High 50 MHz */
} GPIOSpeed_TypeDef;

#define IS_GPIO_SPEED(SPEED)                                                   \
    (((SPEED) == GPIO_Speed_Level_1) || ((SPEED) == GPIO_Speed_Level_2) ||     \
     ((SPEED) == GPIO_Speed_Level_3))
/**
 * @}
 */

/** @defgroup GPIOPuPd_TypeDef
 * @{
 */
typedef enum {
    GPIO_PuPd_NOPULL = 0x00,
    GPIO_PuPd_UP = 0x01,
} GPIOPuPd_TypeDef;

#define IS_GPIO_PUPD(PUPD)                                                     \
    (((PUPD) == GPIO_PuPd_NOPULL) || ((PUPD) == GPIO_PuPd_UP))

/**
 * @}
 */

/** @defgroup Bit_SET_and_Bit_RESET_enumeration
 * @{
 */
typedef enum { Bit_RESET = 0, Bit_SET } BitAction;

#define IS_GPIO_BIT_ACTION(ACTION)                                             \
    (((ACTION) == Bit_RESET) || ((ACTION) == Bit_SET))
/**
 * @}
 */

/**
 * @brief  GPIO Init structure definition
 */
typedef struct {
    uint32_t GPIO_Pin;          /*!< Specifies the GPIO pins to be configured.
                                     This parameter can be any value of @ref
                                   GPIO_pins_define */
    GPIOMode_TypeDef GPIO_Mode; /*!< Specifies the operating mode for the
                                   selected pins. This parameter can be a value
                                   of @ref GPIOMode_TypeDef */
    GPIOPuPd_TypeDef GPIO_PuPd; /*!< Specifies the operating Pull-up/Pull down
                                   for the selected pins. This parameter can be
                                   a value of @ref GPIOPuPd_TypeDef   */
} GPIO_InitTypeDef;

/* Exported constants --------------------------------------------------------*/

/** @defgroup GPIO_Exported_Constants
 * @{
 */

/** @defgroup GPIO_pins_define
 * @{
 */
#define GPIO_Pin_0 ((uint16_t)0x0001)  /*!< Pin 0 selected    */
#define GPIO_Pin_1 ((uint16_t)0x0002)  /*!< Pin 1 selected    */
#define GPIO_Pin_2 ((uint16_t)0x0004)  /*!< Pin 2 selected    */
#define GPIO_Pin_3 ((uint16_t)0x0008)  /*!< Pin 3 selected    */
#define GPIO_Pin_4 ((uint16_t)0x0010)  /*!< Pin 4 selected    */
#define GPIO_Pin_5 ((uint16_t)0x0020)  /*!< Pin 5 selected    */
#define GPIO_Pin_6 ((uint16_t)0x0040)  /*!< Pin 6 selected    */
#define GPIO_Pin_7 ((uint16_t)0x0080)  /*!< Pin 7 selected    */
#define GPIO_Pin_8 ((uint16_t)0x0100)  /*!< Pin 8 selected    */
#define GPIO_Pin_9 ((uint16_t)0x0280)  /*!< Pin 9 selected    */
#define GPIO_Pin_10 ((uint16_t)0x0480) /*!< Pin 10 selected    */
#define GPIO_Pin_11 ((uint16_t)0x0880) /*!< Pin 11 selected    */
#define GPIO_Pin_12 ((uint16_t)0x1000) /*!< Pin 12 selected    */
#define GPIO_Pin_13 ((uint16_t)0x2000) /*!< Pin 13 selected    */
#define GPIO_Pin_14 ((uint16_t)0x4000) /*!< Pin 14 selected    */
#define GPIO_Pin_15 ((uint16_t)0x8000) /*!< Pin 15 selected    */
/* Exported types ------------------------------------------------------------*/

#define IS_GPIO_PIN(PIN) ((PIN) != (uint16_t)0x00)

#define IS_GET_GPIO_PIN(PIN)                                                   \
    (((PIN) == GPIO_Pin_0) || ((PIN) == GPIO_Pin_1) ||                         \
     ((PIN) == GPIO_Pin_2) || ((PIN) == GPIO_Pin_3) ||                         \
     ((PIN) == GPIO_Pin_4) || ((PIN) == GPIO_Pin_5) ||                         \
     ((PIN) == GPIO_Pin_6) || ((PIN) == GPIO_Pin_7))

/**
 * @}
 */

/** @defgroup GPIO_Pin_sources
 * @{
 */
#define GPIO_PinSource0 ((uint8_t)0x00)
#define GPIO_PinSource1 ((uint8_t)0x01)
#define GPIO_PinSource2 ((uint8_t)0x02)
#define GPIO_PinSource3 ((uint8_t)0x03)
#define GPIO_PinSource4 ((uint8_t)0x04)
#define GPIO_PinSource5 ((uint8_t)0x05)
#define GPIO_PinSource6 ((uint8_t)0x06)
#define GPIO_PinSource7 ((uint8_t)0x07)
#define GPIO_PinSource8 ((uint8_t)0x08)
#define GPIO_PinSource9 ((uint8_t)0x09)
#define GPIO_PinSource10 ((uint8_t)0x0A)
#define GPIO_PinSource11 ((uint8_t)0x0B)
#define GPIO_PinSource12 ((uint8_t)0x0C)
#define GPIO_PinSource13 ((uint8_t)0x0D)
#define GPIO_PinSource14 ((uint8_t)0x0E)
#define GPIO_PinSource15 ((uint8_t)0x0F)

#define IS_GPIO_PIN_SOURCE(PINSOURCE)                                          \
    (((PINSOURCE) == GPIO_PinSource0) || ((PINSOURCE) == GPIO_PinSource1) ||   \
     ((PINSOURCE) == GPIO_PinSource2) || ((PINSOURCE) == GPIO_PinSource3) ||   \
     ((PINSOURCE) == GPIO_PinSource4) || ((PINSOURCE) == GPIO_PinSource5) ||   \
     ((PINSOURCE) == GPIO_PinSource6) || ((PINSOURCE) == GPIO_PinSource7) ||   \
     ((PINSOURCE) == GPIO_PinSource8) || ((PINSOURCE) == GPIO_PinSource9) ||   \
     ((PINSOURCE) == GPIO_PinSource10) || ((PINSOURCE) == GPIO_PinSource11) || \
     ((PINSOURCE) == GPIO_PinSource12) || ((PINSOURCE) == GPIO_PinSource13) || \
     ((PINSOURCE) == GPIO_PinSource14) || ((PINSOURCE) == GPIO_PinSource15))

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
/* Function used to set the GPIO configuration to the default reset state *****/
// void GPIO_DeInit(GPIO_TypeDef* GPIOx);

/* Initialization and Configuration functions *********************************/
void GPIO_DeInit(GPIO_TypeDef *GPIOx);
void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct);
void GPIOx_Write(GPIO_TypeDef *GPIOx, uint16_t PortVal);
void GPIO_WriteBit(GPIO_BIT_TypeDef *GPIOx_BIT, uint16_t GPIO_Pin,
                   BitAction BitVal);
void GPIO_ReversalBits(GPIO_BIT_TypeDef *GPIOx_BIT, uint16_t GPIO_Pin);
uint16_t GPIOx_ReadInputData(GPIO_TypeDef *GPIOx);
uint8_t GPIO_ReadInputDataBit(GPIO_BIT_TypeDef *GPIOx_BIT, uint16_t GPIO_Pin);
void GPIO_ResetBits(GPIO_BIT_TypeDef *GPIOx_BIT, uint16_t GPIO_Pin);
void GPIO_SetBits(GPIO_BIT_TypeDef *GPIOx_BIT, uint16_t GPIO_Pin);

// void GPIO_SetBits(GPIOx_Bit_TypeDef* GPIOx, uint16_t GPIO_Pin);
// void GPIO_ResetBits(GPIOx_Bit_TypeDef* GPIOx, uint16_t GPIO_Pin);
// uint8_t GPIO_ReadInputDataBit(GPIOx_Bit_TypeDef* GPIOx, uint16_t GPIO_Pin);
// uint16_t GPIOx_ReadInputData(GPIOx_TypeDef* GPIOx);
// uint16_t GPIO0_ReadInputData(GPIO0_TypeDef* GPIOx);
// void GPIOx_Write(GPIOx_TypeDef* GPIOx, uint16_t PortVal);
// void GPIO0_Write(GPIO0_TypeDef* GPIOx, uint16_t PortVal);
// void GPIO_ReversalBits(GPIOx_Bit_TypeDef* GPIOx, uint16_t GPIO_Pin);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F0XX_GPIO_H */
/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
