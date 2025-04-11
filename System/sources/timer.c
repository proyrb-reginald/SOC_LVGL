#include "timer.h"
#include "Function_Init.h"
#include "SC32r803_tim.h"
#include "lvgl.h"

void SC_TIM0_Init(void) {

    // Forbid editing areas between the labels !!!
    RCC_APB0PeriphClockCmd(RCC_APB0Periph_TIM0, ENABLE);
    /*Init Struct*/ TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    TIM_TimeBaseInitStruct.TIM_WorkMode = TIM_WorkMode_Timer;
    TIM_TimeBaseInitStruct.TIM_Prescaler = TIM_PRESCALER_2;
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStruct.TIM_Preload = 33536;
    TIM_TimeBaseInitStruct.TIM_EXENX = TIM_EXENX_Disable;
    TIM_TIMBaseInit(TIM0, &TIM_TimeBaseInitStruct);
    /*Init Struct*/ TIM_IC_InitTypeDef TIM_IC_InitStruct;
    TIM_IC_InitStruct.TIM_RICPIN = TIM_RICPin_Disable;
    TIM_IC_InitStruct.TIM_FICPIN = TIM_FICPin_Disable;
    TIM_ICInit(TIM0, &TIM_IC_InitStruct);
    TIM_ICCmd(TIM0, DISABLE);
    /*INTEN*/ TIM_ITConfig(TIM0, TIM_IT_INTEN, ENABLE);
    /*TI*/ TIM_ITConfig(TIM0, TIM_IT_TI, ENABLE);
    /*Init Struct*/ NVIC_SetPriority(TIMER0_IRQn, 3); /*TIMER0*/
    NVIC_EnableIRQ(TIMER0_IRQn);
    TIM_Cmd(TIM0, ENABLE);
}

void TIM_TimeBase_TIM0Handler(void) {
    if (TIM_GetFlagStatus(TIM0, TIM_Flag_TI) == SET) {
        TIM_ClearFlag(TIM0, TIM_Flag_TI);
        lv_tick_inc(1);
    }
}

void TIMER0_IRQHandler(void) { TIM_TimeBase_TIM0Handler(); }
