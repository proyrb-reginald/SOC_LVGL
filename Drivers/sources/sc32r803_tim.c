/*
 ******************************************************************************
 * @file    sc32r803_tim.c
 * @author  SOC AE Team
 * @version V0.1
 * @date    29-09-2024
 * @brief TIM function module
 *
 *******************************************************************************
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

/* Includes ------------------------------------------------------------------*/
#include "sc32r803_tim.h"

/** @defgroup TIM_Group1 Configuration of the TIM computation unit functions
 *  @brief   Configuration of the TIM computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### TIM configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  DeInitializes the TIM peripheral
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @retval None
 */
void TIM_DeInit(TIM_TypeDef *TIMx) {
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    if (TIMx == TIM0) {
        RCC_APB0PeriphResetCmd(RCC_APB0Periph_TIM0, ENABLE);
        RCC_APB0PeriphResetCmd(RCC_APB0Periph_TIM0, DISABLE);
    } else if (TIMx == TIM1) {
        RCC_APB0PeriphResetCmd(RCC_APB0Periph_TIM1, ENABLE);
        RCC_APB0PeriphResetCmd(RCC_APB0Periph_TIM1, DISABLE);
    } else if (TIMx == TIM2) {
        RCC_APB0PeriphResetCmd(RCC_APB0Periph_TIM2, ENABLE);
        RCC_APB0PeriphResetCmd(RCC_APB0Periph_TIM2, DISABLE);
    }

    else if (TIMx == TIM3) {
        RCC_APB0PeriphResetCmd(RCC_APB0Periph_TIM3, ENABLE);
        RCC_APB0PeriphResetCmd(RCC_APB0Periph_TIM3, DISABLE);
    }

    else if (TIMx == TIM4) {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM4, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM4, DISABLE);
    } else if (TIMx == TIM5) {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM5, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM5, DISABLE);
    } else if (TIMx == TIM6) {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM6, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM6, DISABLE);
    } else if (TIMx == TIM7) {
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM7, ENABLE);
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_TIM7, DISABLE);
    }
}

/**
 * @brief  Initializes the time base unit of TIMx according to the parameter
 * specified in TIM_TimeBaseInitStruct
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  TIM_TimeBaseInitStruct[out]:Pointer to structure
 * TIM_TimeBaseInitTypeDef, to be initialized.
 * @retval None
 * @note The default SYSCLK clock source is HRC
 */
void TIM_TIMBaseInit(TIM_TypeDef *TIMx,
                     TIM_TimeBaseInitTypeDef *TIM_TimeBaseInitStruct) {
    /* Check the parameters */
    uint32_t tmpreg;
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_TIM_PRESCALER(TIM_TimeBaseInitStruct->TIM_EXENX));
    assert_param(IS_TIM_WORKMODE(TIM_TimeBaseInitStruct->TIM_WorkMode));
    assert_param(IS_TIM_COUNTERMODE(TIM_TimeBaseInitStruct->TIM_CounterMode));
    assert_param(IS_TIM_RICPin(TIM_TimeBaseInitStruct->TIM_Prescaler));

    /*---------------------------- TIMx TIM_CON Configuration
     * ------------------------*/
    /* Get the TIMx TIM_CON value */
    tmpreg = TIMx->TIM_CON;
    /* Clear TIMCK, DEC, CTSEL and EXENX SPR bits */
    tmpreg &= (uint32_t)~(TIM_CON_TIMCLK | TIM_CON_CTSEL | TIM_CON_DEC |
                          TIM_CON_EXENX);
    /* Configure TIMx: Prescaler, AlignedMode and WorkMode */
    /* Set TIMCK bits according to Prescaler value */
    /* Set DEC bit according to CounterMode value */
    /* Set CTSEL bit according to WorkMode value */
    /* Set EXENX bit according to EXENX value */
    tmpreg |=
        (uint32_t)(TIM_TimeBaseInitStruct->TIM_Prescaler |
                   TIM_TimeBaseInitStruct->TIM_CounterMode |
                   TIM_TimeBaseInitStruct->TIM_WorkMode |
                   (TIM_TimeBaseInitStruct->TIM_EXENX << TIM_CON_EXENX_Pos));
    /* Write to TIMx TIM_CON */
    TIMx->TIM_CON = tmpreg;
    /* Write to TIMx TIM_CYCLE */
    TIMx->TIM_CNT = TIMx->TIM_RLD = TIM_TimeBaseInitStruct->TIM_Preload;
}

/**
 * @brief  Fills each TIM_TimeBaseInitStruct member with its default value.
 * @param  TIM_TimeBaseInitStruct[out]:  Pointer to structure
 * TIM_TimeBaseInitTypeDef, to be initialized.
 * @retval None
 */
void TIM_TimeBaseStructInit(TIM_TimeBaseInitTypeDef *TIM_TimeBaseInitStruct) {
    /* Set the default configuration */
    TIM_TimeBaseInitStruct->TIM_Prescaler = TIM_PRESCALER_1;
    TIM_TimeBaseInitStruct->TIM_WorkMode = TIM_WorkMode_Timer;
    TIM_TimeBaseInitStruct->TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct->TIM_Preload = 0x0000;
    TIM_TimeBaseInitStruct->TIM_EXENX = TIM_EXENX_Disable;
}

/**
 * @brief  Enables or disables the specified TIM peripheral.
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  NewState[in]: new state of the TIMx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void TIM_Cmd(TIM_TypeDef *TIMx, FunctionalState NewState) {
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        /* Enable the TIM Counter */
        TIMx->TIM_CON |= TIM_CON_TR;
    } else {
        /* Disable the TIM Counter */
        TIMx->TIM_CON &= (uint16_t)~TIM_CON_TR;
    }
}

/**
 * @brief  Set the Register value of TIMx Counter
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  Counter[in]: specifies the Counter register new value.
 * @retval None
 */
void TIM_SetCounter(TIM_TypeDef *TIMx, uint32_t Counter) {
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    /* Set the Counter Register value */
    TIMx->TIM_CNT = (uint32_t)Counter;
}

/**
 * @brief  Gets the TIMx Counter value.
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @retval Counter Register value
 */
uint32_t TIM_GetCounter(TIM_TypeDef *TIMx) {
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    /* Get the Counter Register value */
    return TIMx->TIM_CNT;
}

/**
 * @brief  Sets the TIMx Autoreload Register value
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  Autoreload[in]: specifies the ReloadData register new value.
 * @retval None
 */
void TIM_SetAutoreload(TIM_TypeDef *TIMx, uint16_t Autoreload) {
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    /* Set the ReloadData Register value */
    TIMx->TIM_RLD = Autoreload;
}

/**
 * @brief  Get the value of TIMx automatic reload.
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @retval the value of TIMx automatic reload
 */
uint16_t TIM_GetAutoreload(TIM_TypeDef *TIMx) {
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    /* Get the ReloadData Register value */
    return TIMx->TIM_RLD;
}

/**
 * @brief  Sets the TIMx Clock per-division value.
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  TIM_Perscaler[in]:Select the frequency of TIMx
 *                  - TIM_PRESCALER_1:Clock division: Fsource/1
 *                  - TIM_PRESCALER_2:Clock division: Fsource/2
 *                  - TIM_PRESCALER_4:Clock division: Fsource/4
 *                  - TIM_PRESCALER_8:Clock division: Fsource/8
 *                  - TIM_PRESCALER_16:Clock division: Fsource/16
 *                  - TIM_PRESCALER_32:Clock division: Fsource/32
 *                  - TIM_PRESCALER_64:Clock division: Fsource/64
 *                  - TIM_PRESCALER_128:Clock division: Fsource/128
 * @retval None
 */
void TIM_SetPerscaler(TIM_TypeDef *TIMx, TIM_Prescaler_TypeDef TIM_Perscaler) {

    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_TIM_PRESCALER(TIM_Perscaler));

    /* Reset the CKD Bits */
    TIMx->TIM_CON &= (uint32_t)(~TIM_CON_TIMCLK);

    /* Set the CKD value */
    TIMx->TIM_CON |= TIM_Perscaler;
}

/**
 * @brief  Gets the TIMx Clock per-division value.
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @retval The clock division value.
 *                  - TIM_PRESCALER_1:Clock division: Fsource/1
 *                  - TIM_PRESCALER_2:Clock division: Fsource/2
 *                  - TIM_PRESCALER_4:Clock division: Fsource/4
 *                  - TIM_PRESCALER_8:Clock division: Fsource/8
 *                  - TIM_PRESCALER_16:Clock division: Fsource/16
 *                  - TIM_PRESCALER_32:Clock division: Fsource/32
 *                  - TIM_PRESCALER_64:Clock division: Fsource/64
 *                  - TIM_PRESCALER_128:Clock division: Fsource/128
 */
TIM_Prescaler_TypeDef TIM_GetPrescaler(TIM_TypeDef *TIMx) {
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    /* Get the CKD value */
    return (TIM_Prescaler_TypeDef)(TIMx->TIM_CON & TIM_CON_TIMCLK);
}

/**
 * @}
 */
/* End of TIM_Group1.	*/

/** @defgroup TIM_Group2 Input Capture management functions
 *  @brief    Input Capture management functions
 *
@verbatim
 ===============================================================================
                     ##### Input Capture management functions #####
 ===============================================================================
@endverbatim
  * @{
  */
/**
 * @brief  Initializes the input capture mode for TIMx according to the
 * parameters specified in TIM_IC_InitStruct.
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  TIM_IC_InitStruct[out]: Pointer to structure TIM_IC_InitTypeDef, to
 * be initialized.
 * @retval None
 */
void TIM_ICInit(TIM_TypeDef *TIMx, TIM_IC_InitTypeDef *TIM_IC_InitStruct) {
    uint16_t tmpreg;
    /* Check the parameters */

    if (TIM_IC_InitStruct->TIM_FICPIN == TIM_FICPin_TnEx)
        assert_param(IS_TIM_TNEX_PERIPH(TIMx));
    if ((TIM_IC_InitStruct->TIM_FICPIN == TIM_FICPin_Tn) ||
        (TIM_IC_InitStruct->TIM_RICPIN == TIM_RICPin_Tn))
        assert_param(IS_TIM_TN_PERIPH(TIMx));

    /* Get the TIMx TIM_CON register value */
    tmpreg = (uint16_t)TIMx->TIM_CON;

    /* Clear EXENR, EXENF and EXENX SPR bits */
    tmpreg &= ~(TIM_CON_EXENR | TIM_CON_EXENF | TIM_CON_FSEL | TIM_CON_EXENX);

    tmpreg |= (TIM_IC_InitStruct->TIM_FICPIN | TIM_IC_InitStruct->TIM_RICPIN);

    TIMx->TIM_CON = (uint32_t)tmpreg;
}

/**
 * @brief  Fill each parameter in TIM_IC_InitStruct with its default value.
 * @param  TIM_IC_InitStruct[out]:Pointer to structure TIM_IC_InitTypeDef, to be
 * initialized.
 * @retval None
 */
void TIM_ICStructInit(TIM_IC_InitTypeDef *TIM_IC_InitStruct) {
    /* Set the default configuration */
    TIM_IC_InitStruct->TIM_FICPIN = TIM_FICPin_Disable;
    TIM_IC_InitStruct->TIM_RICPIN = TIM_RICPin_Disable;
}

/**
 * @brief  Enables or disables the capture function of TIMx
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  NewState[in]:new state of the TIMx clock output.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void TIM_ICCmd(TIM_TypeDef *TIMx, FunctionalState NewState) {
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        /* Enable the capture function of TIMx */
        TIMx->TIM_CON |= TIM_CON_CPRL;
    } else {
        /* Disable the capture function of TIMx */
        TIMx->TIM_CON &= (uint16_t)~TIM_CON_CPRL;
    }
}

/**
 * @brief  Gets the TIMx Input Rising Capture value.
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @retval Capture Rising Capture Register value.
 */
uint32_t TIM_GetRisingCapture(TIM_TypeDef *TIMx) {
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    /* Get the Rising Capture Register value */
    return TIMx->TIM_PDTA_RCAP;
}

/**
 * @brief  Gets the TIMx Input Failing Capture value.
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @retval Capture Rising Capture Register value.
 */
uint32_t TIM_GetFailingCapture(TIM_TypeDef *TIMx) {
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    /* Get the Failing Capture Register value */
    return TIMx->TIM_PDTB_FCAP;
}

/**
 * @}
 */
/* End of TIM_Group2.	*/

/** @defgroup TIM_Group3 PWM management functions
 *  @brief   PWM management functions
 *
@verbatim
 ===============================================================================
                     ##### TIME PWM management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Initializes the PWM mode of TIMx according to the parameters
 * specified in TIM_PWM_InitStruct
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  TIM_PWM_InitStruct[out]:Pointer to structure TIM_PWM_InitTypeDef, to
 * be initialized.
 * @retval None
 */
void TIM_PWMInit(TIM_TypeDef *TIMx, TIM_PWM_InitTypeDef *TIM_PWM_InitStruct) {
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    /* Get the TIMx TIM_CON value */
    tmpreg = TIMx->TIM_CON;

    /* Clear EPWMNA,EPWMNB,INVNA and INVNB bit */
    tmpreg &= (uint32_t)~(TIM_CON_EPWMNA | TIM_CON_EPWMNB | TIM_CON_INVNA |
                          TIM_CON_INVNB);

    /* TIM0 has no TnPWMA and TIM1,2,3,4,5,6,7 has no TnPWMB */

    {
        /* Set EPWMNA and EPWMNB bit to PWM Output Channl value */
        /* Set INVNA and INVNB bit to PWM Low Polarity Channl value */
        tmpreg |=
            (uint32_t)((TIM_PWM_InitStruct->TIM_PWMOutputChannl << (13U)) |
                       (TIM_PWM_InitStruct->TIM_PWMLowPolarityChannl) << (11U));
    }

    /* Write to TIMx TIM_CON */
    TIMx->TIM_CON = tmpreg;
}

/**
 * @brief   Fill each parameter in TIM_PWM_InitStruct with its default value.
 * @param  TIM_PWM_InitStruct: A pointer to the structure TIM_PWM_InitTypeDef
 * that initializes the PWM mode of TIMx.
 * @retval None
 */
void TIM_PWMStructInit(TIM_PWM_InitTypeDef *TIM_PWM_InitStruct) {
    /* Set the default configuration */
    TIM_PWM_InitStruct->TIM_PWMLowPolarityChannl = TIM_PWMChannel_Less;
    TIM_PWM_InitStruct->TIM_PWMOutputChannl = TIM_PWMChannel_Less;
}

/**
 * @brief  TIMx PWM duty cycle Settings.
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  TIM_PWMChannel[in]:specifies the TIM_PWM channel to check.
 *                  - TIM_PWMChannel_Less:No channels are selected
 *                  - TIM_PWMChannel_PWMB:PMWB output channel
 *                  - TIM_PWMChannel_PWMA:PMWA output channel
 * @param  PWM_DutyValue[in]: specifies the RCAP register new value.s
 * @retval None
 */
void TIM_PWMSetDuty(TIM_TypeDef *TIMx, TIM_PWMChannel_Typedef TIM_PWMChannel,
                    uint16_t PWM_DutyValue) {

    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    if (TIM_PWMChannel == TIM_PWMChannel_PWMA) {
        TIMx->TIM_PDTA_RCAP = PWM_DutyValue;
    } else if (TIM_PWMChannel == TIM_PWMChannel_PWMB) {
        TIMx->TIM_PDTB_FCAP = PWM_DutyValue;
    }
}

/**
 * @brief  Get the PWM duty cycle of TIMx
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  TIM_PWMChannel[in]:selects a PWM channel.
 *                  - TIM_PWMChannel_Less:No channels are selected
 *                  - TIM_PWMChannel_PWMB:PMWB output channel
 *                  - TIM_PWMChannel_PWMA:PMWA output channel
 * @retval PWM duty cycle of TIMx
 */
uint16_t TIM_PWMGetDuty(TIM_TypeDef *TIMx,
                        TIM_PWMChannel_Typedef TIM_PWMChannel) {
    uint16_t tmpduty = 0;

    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    if (TIM_PWMChannel == TIM_PWMChannel_PWMA) {
        tmpduty = (uint16_t)TIMx->TIM_PDTA_RCAP;
    } else {
        tmpduty = (uint16_t)TIMx->TIM_PDTB_FCAP;
    }

    return tmpduty;
}

/**
 * @}
 */
/* End of TIM_Group3.	*/

/** @defgroup TIM_Group4 Clocks management functions
 *  @brief   Clocks management functions
 *
@verbatim
 ===============================================================================
                     ##### Clocks management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Enables or disables TIMx's programmable clock output
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  NewState[in]: new state of the TIMx clock output.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void TIM_ClockOutputCmd(TIM_TypeDef *TIMx, FunctionalState NewState) {
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        /* Enable the TIM Clock Output */
        TIMx->TIM_CON |= TIM_CON_TXOE;
    } else {
        /* Disable the TIM Clock Output */
        TIMx->TIM_CON &= (uint32_t)~TIM_CON_TXOE;
    }
}

/**
 * @}
 */
/* End of TIM_Group4.	*/

/** @defgroup TIM_Group5 Pin remap management functions
 *  @brief  Pin remap management functions
 *
@verbatim
 ===============================================================================
                     ##### Pin remap management functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Configure the remapping of TIM2/3/7 pins
 * @param  TIMx: where x can be 2,3 and 7 to select the TIM peripheral.
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  TIM_Remap: specifies the TIM input remapping source.
 *          This parameter can be one of TIM_PinRemap_TypeDef.
 * @retval None
 */
void TIM_PinRemapConfig(TIM_TypeDef *TIMx, TIM_PinRemap_TypeDef TIM_Remap) {
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param(IS_TIM_REMAP_PERIPH(TIMx));
    assert_param(IS_TIM_PINREMAP(TIM_Remap));

    tmpreg = TIMx->TIM_CON;

    tmpreg &= (uint32_t)(~TIM_CON_SPOS);

    tmpreg |= TIM_Remap;

    TIMx->TIM_CON = tmpreg;
}

/**
 * @}
 */
/* End of TIM_Group5.	*/

/** @defgroup TIM_Group6 Interrupts, DMA and flags management functions
 *  @brief   Interrupts, DMA and flags management functions
 *
@verbatim
 ===============================================================================
                     ##### Interrupts, DMA and flags management functions #####
 ===============================================================================
@endverbatim
  * @{
  */
/**
 * @brief  Enables or disables the specified TIM interrupts.
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  TIM_IT[in]: specifies the TIM interrupts sources to be enabled or
 * disabled.
 *                  - TIM_IT_INTEN :TIM Interrupt Enable
 *                  -  TIM_IT_TI:IM overflow
 *                  -  TIM_IT_EXR:Rising edge capture
 *                  -  TIM_IT_EXF:Falling edge capture
 * @param  NewState[in]:new state of the TIM interrupts.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void TIM_ITConfig(TIM_TypeDef *TIMx, uint16_t TIM_IT,
                  FunctionalState NewState) {
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_TIM_IT(TIM_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        /* Enable the Interrupt sources */
        TIMx->TIM_IDE |= TIM_IT;
    } else {
        /* Disable the Interrupt sources */
        TIMx->TIM_IDE &= (uint16_t)~TIM_IT;
    }
}

/**
 * @brief  Checks whether the specified TIM flag is set or not.
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  TIM_FLAG[in]:specifies the flag to check.
 *                  - TIM_Flag_TI :TIM overflow
 *                  - TIM_Flag_EXR:Immediate mode
 *                  - TIM_Flag_EXF:Immediate mode
 * @retval The new state of ADC_FLAG (SET or RESET).
 *                  -  RESET:Flag reset
 *                  -  SET :Flag up
 */
FlagStatus TIM_GetFlagStatus(TIM_TypeDef *TIMx, TIM_Flag_TypeDef TIM_FLAG) {
    FlagStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));
    assert_param(IS_GET_TIM_FLAG(TIM_FLAG));

    if ((TIMx->TIM_STS & TIM_FLAG) != (uint16_t)RESET) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }
    return bitstatus;
}

/**
 * @brief  Clears the TIMx's pending flags.
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  TIM_FLAG[in]:specifies the flag to check.
 *                  - TIM_Flag_TI :TIM overflow
 *                  - TIM_Flag_EXR:Immediate mode
 *                  - TIM_Flag_EXF:Immediate mode
 * @retval None
 */
void TIM_ClearFlag(TIM_TypeDef *TIMx, uint16_t TIM_FLAG) {
    /* Check the parameters */
    assert_param(IS_TIM_ALL_PERIPH(TIMx));

    /* Clear the flags */
    TIMx->TIM_STS = (uint16_t)TIM_FLAG;
}

/**
 * @brief  Enables or disables DMA requests for the specified TIMx
 * @param  TIMx[out]: where x can be to select the TIMx peripheral.
 *                  - TIM0:Timer peripheral select TIM0
 *                  - TIM1:Timer peripheral select TIM1
 *                  - TIM2:Timer peripheral select TIM2
 *                  - TIM3:Timer peripheral select TIM3
 *                  - TIM4:Timer peripheral select TIM4
 *                  - TIM5:Timer peripheral select TIM5
 *                  - TIM6:Timer peripheral select TIM6
 *                  - TIM7:Timer peripheral select TIM7
 * @param  TIM_DMAReq[in]:specifies the SPI DMA transfer request to be enabled
 * or disabled.
 *                  - TIM_DMAReq_TI:TIM overflow
 *                  - TIM_DMAReq_CAPR:Rising edge capture
 *                  - TIM_DMAReq_CAPF:Falling edge capture
 * @param  NewState[in]:new state of the TIMx clock output.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void TIM_DMACmd(TIM_TypeDef *TIMx, uint16_t TIM_DMAReq,
                FunctionalState NewState) {
    /* Check the parameters */
    assert_param(IS_TIM_DMA_PERIPH(TIMx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        /* Enable the TIM DMA */
        TIMx->TIM_IDE |= TIM_DMAReq;
    } else {
        /* Disable the TIM DMA */
        TIMx->TIM_IDE &= (uint16_t)~TIM_DMAReq;
    }
}

/**
 * @}
 */
/* End of TIM_Group6.	*/

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT SOC Microelectronics *****END OF
 * FILE****/
