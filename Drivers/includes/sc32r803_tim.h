/**
 ******************************************************************************
 * @file    sc32r803_tim.h
 * @author  SOC AE Team
 * @version V0.1
 * @date    29-09-2024
 * @brief   Header file of TIM module.
 ******************************************************************************
 * @attention
 *
 *1.This software is supplied by SinOne Microelectronics Co.,Ltd. and is only
 *intended for use with SinOne products. No other uses are authorized. This
 *software is owned by SinOne Microelectronics Co.,Ltd. and is protected under
 *all applicable laws, including copyright laws.
 *2.The software which is for guidance only aims at providing customers with
 *coding information regarding their products in order for them to save time.
 *As a result, SinOne shall not be held liable for any direct, indirect or
 *consequential damages with respect to any claims arising from the content of
 *such software and/or the use made by customers of the coding information
 *contained herein in connection with their products.
 *
 *  COPYRIGHT 2024 SinOne Microelectronics
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __sc32r803_TIM_H
#define __sc32r803_TIM_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "SC32F10xx_rcc.h"
#include "W1222A.h"
#include "sc32.h"

/** @addtogroup sc32r803_StdPeriph_Driver
 * @{
 */

/** @addtogroup TIM
 * @{
 */

/** @defgroup TIM_Enumerations TIM Enumerations
 * @{
 */

/** @brief TIM_Prescaler_TypeDef TIM Prescaler
 * @{
 */
typedef enum {
    TIM_PRESCALER_1 =
        (uint16_t)(0x00U
                   << TIM_CON_TIMCLK_Pos), /*!< Clock division: Fsource/1 */
    TIM_PRESCALER_2 =
        (uint16_t)(0x01U
                   << TIM_CON_TIMCLK_Pos), /*!< Clock division: Fsource/2 */
    TIM_PRESCALER_4 =
        (uint16_t)(0x02U
                   << TIM_CON_TIMCLK_Pos), /*!< Clock division: Fsource/4 */
    TIM_PRESCALER_8 =
        (uint16_t)(0x03U
                   << TIM_CON_TIMCLK_Pos), /*!< Clock division: Fsource/8 */
    TIM_PRESCALER_16 =
        (uint16_t)(0x04U
                   << TIM_CON_TIMCLK_Pos), /*!< Clock division: Fsource/16    */
    TIM_PRESCALER_32 =
        (uint16_t)(0x05U
                   << TIM_CON_TIMCLK_Pos), /*!< Clock division: Fsource/32    */
    TIM_PRESCALER_64 =
        (uint16_t)(0x06U
                   << TIM_CON_TIMCLK_Pos), /*!< Clock division: Fsource/64    */
    TIM_PRESCALER_128 =
        (uint16_t)(0x07U
                   << TIM_CON_TIMCLK_Pos), /*!< Clock division: Fsource/128 */
} TIM_Prescaler_TypeDef;

#define IS_TIM_PRESCALER(PRESCALER)                                            \
    (((PRESCALER) == TIM_PRESCALER_1) || ((PRESCALER) == TIM_PRESCALER_2) ||   \
     ((PRESCALER) == TIM_PRESCALER_4) || ((PRESCALER) == TIM_PRESCALER_8) ||   \
     ((PRESCALER) == TIM_PRESCALER_16) || ((PRESCALER) == TIM_PRESCALER_32) || \
     ((PRESCALER) == TIM_PRESCALER_64) || ((PRESCALER) == TIM_PRESCALER_128))
/**
 * @}
 */

/** @brief TIM_WorkMode TIM WorkMode
 * @{
 */
typedef enum {
    TIM_WorkMode_Timer =
        (uint16_t)(0x00U << TIM_CON_CTSEL_Pos), /*!< Work Mode: Timer Mode */
    TIM_WorkMode_Counter =
        (uint16_t)(0x01U << TIM_CON_CTSEL_Pos), /*!< Work Mode: Counter Mode */
} TIM_WorkMode_Typedef;

#define IS_TIM_WORKMODE(MODE)                                                  \
    (((MODE) == TIM_WorkMode_Timer) || ((MODE) == TIM_WorkMode_Counter))
/**
 * @}
 */

/** @brief TIM_CounterMode TIM Counter Mode
 * @{
 */
typedef enum {
    TIM_CounterMode_Up =
        (uint16_t)(0x00U << TIM_CON_DEC_Pos), /*!< Counter mode: up-counter */
    TIM_CounterMode_Down_UP =
        (uint16_t)(0x01U
                   << TIM_CON_DEC_Pos), /*!< Counter mode: down or up counter */
} TIM_CounterMode_Typedef;

#define IS_TIM_COUNTERMODE(MODE)                                               \
    (((MODE) == TIM_CounterMode_Up) || ((MODE) == TIM_CounterMode_Down_UP))
/**
 * @}
 */

/** @brief TIM_EXENX TIM EXENX
 * @{
 */
typedef enum {
    TIM_EXENX_Disable =
        (uint16_t)(0x00U
                   << TIM_CON_EXENX_Pos), /*!< External load pin disable */
    TIM_EXENX_Enable =
        (uint16_t)(0x01U << TIM_CON_EXENX_Pos), /*!< External load pin enable */
} TIM_EXENX_Typedef;

#define IS_TIM_EXENX(STATE)                                                    \
    (((STATE) == TIM_EXENX_Disable) || ((STATE) == TIM_EXENX_Enable))
/**
 * @}
 */

/** @brief TIM_RICPIN TIM Rising Input Capture Pin
 * @{
 */
typedef enum {
    TIM_RICPin_Disable =
        (uint16_t)(0x00U << TIM_CON_EXENR_Pos), /*!< No rising input is required
                                                   for capture   */
    TIM_RICPin_Tn =
        (uint16_t)(0x01U << TIM_CON_EXENR_Pos), /*!< TIM rising input capture
                                                   pin is Tn   */
} TIM_RICPIN_Typedef;

#define IS_TIM_RICPin(RICPin)                                                  \
    (((RICPin) == TIM_RICPin_Disable) || ((RICPin) == TIM_RICPin_Tn))
/**
 * @}
 */

/** @brief TIM_FICPIN TIM Falling Input Capture Pin
 * @{
 */
typedef enum {
    TIM_FICPin_Disable =
        (uint16_t)(0x00U), /*!< No rising input is required for capture   */
    TIM_FICPin_Tn =
        (uint16_t)(TIM_CON_EXENF), /*!< TIM failing input capture pin is Tn   */
    TIM_FICPin_TnEx =
        (uint16_t)(TIM_CON_EXENX |
                   TIM_CON_FSEL), /*!< TIM failing input capture pin is TnEx */
} TIM_FICPIN_Typedef;

#define IS_TIM_FICPin(FICPin)                                                  \
    (((FICPin) == TIM_FICPin_Disable) || ((FICPin) == TIM_FICPin_Tn) ||        \
     ((FICPin) == TIM_FICPin_TnEx))
/**
 * @}
 */

/** @brief TIM_PWMChannel TIM PWM Channel
 * @{
 */
typedef enum {
    TIM_PWMChannel_Less = (uint16_t)0x00, /*!< No channels are selected */
    TIM_PWMChannel_PWMB = (uint16_t)0x01, /*!< PMWB output channel */
    TIM_PWMChannel_PWMA = (uint16_t)0x02, /*!< PMWA output channel */
    TIM_PWMChannel_ALL = (uint16_t)0x03,  /*!< PMW All output channel */
} TIM_PWMChannel_Typedef;

#define IS_TIM_PWMCHANNEL(CHANNEL) (((CHANNEL) & (uint32_t)0xFFFC) == 0x00)
/**
 * @}
 */

/** @brief TIM_PinRemap TIM Pin Remap
 * @{
 */

typedef enum {
    TIM_PinRemap_Default =
        (uint32_t)(0x00 << TIM_CON_SPOS_Pos), /*!< TIM Pin Remap: Disable */
    TIM_PinRemap_A =
        (uint32_t)(0x01
                   << TIM_CON_SPOS_Pos), /*!< TIM  Pin Remap: Remap mode A*/
} TIM_PinRemap_TypeDef;

#define IS_TIM_PINREMAP(REMAP)                                                 \
    (((REMAP) == TIM_PinRemap_Default) || ((REMAP) == TIM_PinRemap_A))

/**
 * @}
 */

/** @brief TIM_IT TIM Interrupt
 * @{
 */
typedef enum {
    TIM_IT_INTEN =
        (uint8_t)TIM_IDE_INTEN, /*!< TIM Interrupt: TIM Interrupt Enable */
    TIM_IT_TI = (uint8_t)TIM_IDE_TIE, /*!< TIM Interrupt: TIM overflow  */
    TIM_IT_EXR =
        (uint8_t)TIM_IDE_EXIRE, /*!< TIM Interrupt: Rising edge capture */
    TIM_IT_EXF =
        (uint8_t)TIM_IDE_EXIFE, /*!< TIM Interrupt: Falling edge capture */
} TIM_IT_TypeDef;

#define IS_TIM_IT(IT)                                                          \
    ((((IT) & (uint8_t)0xF0) == 0x00) && ((IT) != (uint8_t)0x00))
/**
 * @}
 */

/** @brief TIM_Flag TIM Flag
 * @{
 */
typedef enum {
    TIM_Flag_TI = (uint8_t)0x01,  /*!< TIM Flag: TIM overflow */
    TIM_Flag_EXR = (uint8_t)0x02, /*!< TIM Flag: Immediate mode */
    TIM_Flag_EXF = (uint8_t)0x04, /*!< TIM Flag: Immediate mode */
} TIM_Flag_TypeDef;

#define IS_TIM_FLAG(FLAG)                                                      \
    ((((FLAG) & (uint8_t)0xF8) == 0x00) && ((FLAG) != (uint8_t)0x00))

#define IS_GET_TIM_FLAG(FLAG)                                                  \
    (((FLAG) == TIM_Flag_TI) || ((FLAG) == TIM_Flag_EXR) ||                    \
     ((FLAG) == TIM_Flag_EXF))
/**
 * @}
 */

/** @brief TIM_DMAReq TIM DMAReq
 * @{
 */
typedef enum {
    TIM_DMAReq_TI = (uint8_t)TIM_IDE_TIDE, /*!< TIM DMA: TIM overflow */
    TIM_DMAReq_CAPR =
        (uint8_t)TIM_IDE_CAPRDE, /*!< TIM DMA: Rising edge capture */
    TIM_DMAReq_CAPF =
        (uint8_t)TIM_IDE_CAPFDE, /*!< TIM DMA: Falling edge capture */
} TIM_DMAReq_TypeDef;

#define IS_TIM_DMAREQ(DMAREQ)                                                  \
    ((((DMAREQ) & (uint8_t)0x8F) == 0x00) && ((DMAREQ) != 0x00))
/**
 * @}
 */

/**
 * @}
 */
/* End of enumerations -----------------------------------------------------*/

/** @brief TIM_Constants TIM Constants
 * @{
 */

#define IS_TIM_ALL_PERIPH(PERIPH)                                              \
    (((PERIPH) == TIM0) || ((PERIPH) == TIM1) || ((PERIPH) == TIM2) ||         \
     ((PERIPH) == TIM3) || ((PERIPH) == TIM4) || ((PERIPH) == TIM5) ||         \
     ((PERIPH) == TIM6) || ((PERIPH) == TIM7))

#define IS_TIM_TN_PERIPH(PERIPH)                                               \
    (((PERIPH) == TIM0) || ((PERIPH) == TIM1) || ((PERIPH) == TIM2) ||         \
     ((PERIPH) == TIM3) || ((PERIPH) == TIM4) || ((PERIPH) == TIM5) ||         \
     ((PERIPH) == TIM6) || ((PERIPH) == TIM7))

#define IS_TIM_TNEX_PERIPH(PERIPH)                                             \
    (((PERIPH) == TIM0) || ((PERIPH) == TIM1) || ((PERIPH) == TIM2) ||         \
     ((PERIPH) == TIM3) || ((PERIPH) == TIM4) || ((PERIPH) == TIM5) ||         \
     ((PERIPH) == TIM6) || ((PERIPH) == TIM7))

#define IS_TIM_DMA_PERIPH(PERIPH)                                              \
    (((PERIPH) == TIM1) || ((PERIPH) == TIM2) || ((PERIPH) == TIM6))

#define IS_TIM_REMAP_PERIPH(PERIPH)                                            \
    (((PERIPH) == TIM2) || ((PERIPH) == TIM3) || ((PERIPH) == TIM4) ||         \
     ((PERIPH) == TIM5) || ((PERIPH) == TIM6) || ((PERIPH) == TIM7))

/**
 * @}
 */
/* End of constants -----------------------------------------------------*/

/** @defgroup TIM_Struct TIM Struct
 * @{
 */

/** @brief TIM_TimeBaseInitTypeDef TIM Time base Configuration Structure
 * definition
 * @{
 */
typedef struct {
    uint16_t TIM_Prescaler; /*!<  Specifies the clock division.
                                      This parameter can be a value of @ref
                               TIM_Prescaler_TypeDef */

    uint16_t TIM_WorkMode; /*!< Specifies the Word mode.
                                          This parameter can be a value of @ref
                              TIM_WordMode_Typedef */

    uint16_t TIM_CounterMode; /*!< Specifies the Counter mode.
                                      This parameter can be a value of @ref
                                 TIM_CounterMode_Typedef */

    uint16_t TIM_EXENX; /*!< Specifies whether falling edge reloading on the
                           TnEX pin is enabled. This parameter can be a value of
                           @ref TnEX_Reload	*/

    uint16_t TIM_Preload; /*!< Specifies the preload value to be loaded into the
                             active Auto-Reload Register at the next update
                             event. This parameter can be a number between
                             Min_Data = 0x0000 and Max_Data = 0xFFFF.  */

} TIM_TimeBaseInitTypeDef;
/**
 * @}
 */

/** @brief TIM_IC_InitTypeDef Configuration Structure definition
 * @{
 */
typedef struct {
    uint16_t TIM_RICPIN; /*!<  Specifies the rising input capture pin.
                                      This parameter can be a value of @ref
                            TIM_RICPIN_Typedef */

    uint16_t TIM_FICPIN; /*!<  Specifies the failing input capture pin.
                                      This parameter can be a value of @ref
                            TIM_FICPIN_Typedef */

} TIM_IC_InitTypeDef;
/**
 * @}
 */

/** @brief TIM_PWM TIM PWM
 * @{
 */
typedef struct {
    uint16_t
        TIM_PWMOutputChannl; /*!<	TIM PWM Channel to be enabled.
                                                                                                                                                    This parameter can be a value of @ref TIM_PWMChannel_Typedef */

    uint16_t TIM_PWMLowPolarityChannl; /*!< TIM PWM Channl Polarity is set to
                                          Low. This parameter can be a value of
                                          @ref TIM_PWMChannel_Typedef */

} TIM_PWM_InitTypeDef;
/**
 * @}
 */

/**
 * @}
 */
/* End of struct -----------------------------------------------------*/

/** @addtogroup TIM_Functions TIM Functions
 * @{
 */

/* Time Base functions ********************************************************/
void TIM_DeInit(TIM_TypeDef *TIMx);
void TIM_TIMBaseInit(TIM_TypeDef *TIMx,
                     TIM_TimeBaseInitTypeDef *TIM_TimeBaseInitStruct);
void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef *TIM_TimeBaseInitStruct);
void TIM_SetCounter(TIM_TypeDef *TIMx, uint32_t Counter);
uint32_t TIM_GetCounter(TIM_TypeDef *TIMx);
void TIM_SetAutoreload(TIM_TypeDef *TIMx, uint16_t Autoreload);
uint16_t TIM_GetAutoreload(TIM_TypeDef *TIMx);
void TIM_SetPerscaler(TIM_TypeDef *TIMx, TIM_Prescaler_TypeDef TIM_Perscaler);
TIM_Prescaler_TypeDef TIM_GetPrescaler(TIM_TypeDef *TIMx);
void TIM_Cmd(TIM_TypeDef *TIMx, FunctionalState NewState);

/* Timer Input Capture functions **********************************************/
void TIM_ICInit(TIM_TypeDef *TIMx, TIM_IC_InitTypeDef *TIM_IC_InitStruct);
void TIM_ICStructInit(TIM_IC_InitTypeDef *TIM_IC_InitStruct);
void TIM_ICCmd(TIM_TypeDef *TIMx, FunctionalState NewState);
uint32_t TIM_GetRisingCapture(TIM_TypeDef *TIMx);
uint32_t TIM_GetFailingCapture(TIM_TypeDef *TIMx);

/* Timer PWM functions **********************************************/
void TIM_PWMInit(TIM_TypeDef *TIMx, TIM_PWM_InitTypeDef *TIM_PWM_InitStruct);
void TIM_PWMStructInit(TIM_PWM_InitTypeDef *TIM_PWM_InitStruct);
void TIM_PWMSetDuty(TIM_TypeDef *TIMx, TIM_PWMChannel_Typedef TIM_PWMChannel,
                    uint16_t PWM_DutyValue);
uint16_t TIM_PWMGetDuty(TIM_TypeDef *TIMx,
                        TIM_PWMChannel_Typedef TIM_PWMChannel);

/* Clocks Output management
 * functions**********************************************/
void TIM_ClockOutputCmd(TIM_TypeDef *TIMx, FunctionalState NewState);

/* Pin Remap functions**********************************************/

void TIM_PinRemapConfig(TIM_TypeDef *TIMx, TIM_PinRemap_TypeDef TIM_Remap);

/* Interrupts, DMA and flags management functions
 * ***********************************************/
void TIM_ITConfig(TIM_TypeDef *TIMx, uint16_t TIM_IT, FunctionalState NewState);
FlagStatus TIM_GetFlagStatus(TIM_TypeDef *TIMx, TIM_Flag_TypeDef TIM_FLAG);
void TIM_ClearFlag(TIM_TypeDef *TIMx, uint16_t TIM_FLAG);
void TIM_DMACmd(TIM_TypeDef *TIMx, uint16_t TIM_DMAReq,
                FunctionalState NewState);

/**
 * @}
 */

/* End of exported functions
 * --------------------------------------------------*/

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
