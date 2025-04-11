/**
  ******************************************************************************
  * @file   SC32F10xx_RCC.c
  * @author  soc
  * @version V1.5.0
  * @date    07-9-2021
  * @brief   This file provides firmware functions to manage the following
  *
  *  @verbatim
 ===============================================================================
                     ##### How to use this driver #####
 ===============================================================================

     @endverbatim
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "SC32F10xx_rcc.h"

/** @addtogroup STM32F0xx_StdPeriph_Driver
 * @{
 */

/** @defgroup CRC
 * @brief CRC driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup RCC_Private_Functions
 * @{
 */
/*
1,LRC的开关参考规格(写保护,LRCEN不是总开关,只要WDT使用LRC一定启动


*/

/** @defgroup RCC_Group1 Configuration of the RCC computation unit functions
 *  @brief   Configuration of the RCC computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### RCC configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  RCC 缺省值.
 * @param  None
 * @retval None
 */
void RCC_DeInit(void) {
    /*		INTEN = 0,LXTEN=0,LIRCEN=0,HXTEN=0,SYSCLKSW=0,Wait[1:0]=b11*/
    /*默认SysClk=HRC*/
    RCC->RCC_CFG0 = (RCC_CFG0_SYSCLKSW_HIRC << RCC_CFG0_SYSCLKSW_Pos) |
                    (RCC_CFG0_WAIT3 << RCC_CFG0_WAIT_Pos);
}
/**
 * @brief SysCLKSW选择
 * @arg RCC_CFG0_SYSCLKSW_TypeDef=RCC_CFG0_SYSCLKSW_HIRC：HIRC
 * @arg
 * =RCC_CFG0_SYSCLKSEL_CLKSEL：SystemCLk
 * @retval None
 */
void RCC_SYSCLKSWConfig(RCC_CFG0_SYSCLKSW_TypeDef RCC_SYSCLKSW) {
    RCC->RCC_KEY = 0XFF;
    /*清SYSCLKSW选择位*/
    RCC->RCC_CFG0 &= ~((uint32_t)RCC_CFG0_SYSCLKSW);
    RCC->RCC_KEY = 0XFF;
    RCC->RCC_CFG0 |= (uint32_t)(RCC_SYSCLKSW << RCC_CFG0_SYSCLKSW_Pos);
}
/**
 * @brief SystemCLk选择:SysCLKSW=1
 * @arg RCC_SYSCLKSource_LRC:LRC
 * @arg RCC_SYSCLKSource_HXT:HXT
 * @arg RCC_SYSCLKSource_PLLCLK:PLL
 * @arg RCC_SYSCLKSource_LXT:LXT
 * @retval None
 */
void RCC_SYSCLKConfig(uint32_t RCC_SYSCLKSource) {
    RCC->RCC_KEY = 0XFF;
    /*SYSCLKSW选择位=SYSCLKSEL设置项*/
    RCC->RCC_CFG0 |= (uint32_t)RCC_CFG0_SYSCLKSW; // SW选择SYSCLKSEL设置
    /*清SYSCLKSEL*/
    RCC->RCC_KEY = 0XFF;
    RCC->RCC_CFG0 &= ~((uint32_t)RCC_CFG0_SYSCLKSEL);
    RCC->RCC_KEY = 0XFF;
    RCC->RCC_CFG0 |= RCC_SYSCLKSource;
}
/**
 * @brief SystickCLk选择
 * @param  None
 * @retval None
 */
void RCC_SystickCLKConfig(RCC_SYSTICKCLKSOURCE_TypeDef RCC_SYSTICKCLKSource) {
    RCC->RCC_CFG1 &= ~((uint32_t)RCC_CFG1_STCLKSEL);
    RCC->RCC_CFG1 |= (uint32_t)(RCC_SYSTICKCLKSource << RCC_CFG1_STCLKSEL_Pos);
}
/**
 * @brief HCLk选择
 * @arg RCC_SYSCLK_Div1
 * @arg RCC_SYSCLK_Div2
 * @arg RCC_SYSCLK_Div4
 * @arg RCC_SYSCLK_Div8
 * @arg RCC_SYSCLK_Div16
 * @retval None
 */
void RCC_HCLKConfig(uint32_t RCC_HCLKCLKSource) {
    RCCAHB->AHB_CFG &= ~((uint32_t)AHB_CFG_CLKDIV);
    RCCAHB->AHB_CFG |= RCC_HCLKCLKSource;
}
/**
 * @brief APB0选择
 * @arg RCC_HCLK_Div1
 * @arg RCC_HCLK_Div2
 * @arg RCC_HCLK_Div4
 * @arg RCC_HCLK_Div8
 * @arg RCC_HCLK_Div16
 * @retval None
 */
void RCC_APB0KConfig(uint32_t RCC_APB0CLKSource) {
    RCCAPB0->APB0_CFG &= ~((uint32_t)APB0_CFG_CLKDIV);
    RCCAPB0->APB0_CFG |= RCC_APB0CLKSource;
}
/**
 * @brief APB1选择
 * @arg RCC_HCLK_Div1
 * @arg RCC_HCLK_Div2
 * @arg RCC_HCLK_Div4
 * @arg RCC_HCLK_Div8
 * @arg RCC_HCLK_Div16
 * @retval None
 */
void RCC_APB1KConfig(uint32_t RCC_APB1CLKSource) {
    RCCAPB1->APB1_CFG &= ~((uint32_t)APB1_CFG_CLKDIV);
    RCCAPB1->APB1_CFG |= RCC_APB1CLKSource;
}
/**
 * @brief APB2选择
 * @arg RCC_HCLK_Div1
 * @arg RCC_HCLK_Div2
 * @arg RCC_HCLK_Div4
 * @arg RCC_HCLK_Div8
 * @arg RCC_HCLK_Div16
 * @retval None
 */
void RCC_APB2KConfig(uint32_t RCC_APB2CLKSource) {
    RCCAPB2->APB2_CFG &= ~((uint32_t)APB2_CFG_CLKDIV);
    RCCAPB2->APB2_CFG |= RCC_APB2CLKSource;
}
/**
 * @brief PWM0Lk选择
 * @param  None
 * @retval None
 */
void RCC_PWM0CLKConfig(RCC_PWM0CLKSOURCE_TypeDef RCC_PWM0CLKSource) {
    RCC->RCC_CFG1 &= ~((uint32_t)RCC_CFG1_PWM0CLKSEL);
    RCC->RCC_CFG1 |= (uint32_t)(RCC_PWM0CLKSource << RCC_CFG1_PWM0CLKSEL_Pos);
}
/**
 * @brief LCDCLk选择
 * @param  None
 * @retval None
 */
void RCC_LCDCLKConfig(RCC_LCDCLKSOURCE_TypeDef RCC_LCDCLKSource) {
    RCC->RCC_CFG1 &= ~((uint32_t)RCC_CFG1_STCLKSEL);
    RCC->RCC_CFG1 |= (uint32_t)(RCC_LCDCLKSource << RCC_CFG1_LCDCLKSEL_Pos);
}
/**
 * @brief BTMCLk选择
 * @param  None
 * @retval None
 */
void RCC_BTMCLKConfig(RCC_BTMCLKSOURCE_TypeDef RCC_BTMCLKSource) {
    RCC->RCC_CFG1 &= ~((uint32_t)RCC_CFG1_STCLKSEL);
    RCC->RCC_CFG1 |= (uint32_t)(RCC_BTMCLKSource << RCC_CFG1_BTMCLKSEL_Pos);
}
/**
 * @brief 使能HXT
 * @param  None
 * @retval None
 */
void RCC_HXTCmd(FunctionalState NewState) {
    if (NewState != DISABLE) {
        /* Enable the selected HXT peripheral */
        RCC->RCC_CFG0 |= RCC_CFG0_HXTEN;
    } else {
        /* Disable the selected HXT peripheral */
        RCC->RCC_CFG0 &= (uint32_t)~((uint32_t)RCC_CFG0_HXTEN);
    }
}
/**
 * @brief 使能HIRC
 * @param  None
 * @retval None
 */
void RCC_HIRCCmd(FunctionalState NewState) {
    if (NewState != DISABLE) {
        /* Enable the selected HIRC peripheral */
        RCC->RCC_KEY = 0XFF;
        RCC->RCC_CFG0 |= RCC_CFG0_HIRCEN;
    } else {
        /* Disable the selected HIRC peripheral */
        RCC->RCC_KEY = 0XFF;
        RCC->RCC_CFG0 &= (uint32_t)~((uint32_t)RCC_CFG0_HIRCEN);
    }
}
/**
 * @brief 使能LXT
 * @param  None
 * @retval None
 */
void RCC_LXTCmd(FunctionalState NewState) {
    if (NewState != DISABLE) {
        /* Enable the selected LXT peripheral */
        RCC->RCC_CFG0 |= RCC_CFG0_LXTEN;
    } else {
        /* Disable the selected LXT peripheral */
        RCC->RCC_CFG0 &= (uint32_t)~((uint32_t)RCC_CFG0_LXTEN);
    }
}
/**
 * @brief 使能LIRC
 * @param  None
 * @retval None
 */
void RCC_LIRCCmd(FunctionalState NewState) {
    if (NewState != DISABLE) {
        /* Enable the selected LXT peripheral */
        RCC->RCC_CFG0 |= RCC_CFG0_LIRCEN;
    } else {
        /* Disable the selected LXT peripheral */
        RCC->RCC_CFG0 &= (uint32_t)~((uint32_t)RCC_CFG0_LIRCEN);
    }
}
/**
 * @brief 使能RCC中断
 * @param  None
 * @retval None
 */
void RCC_ITConfig(FunctionalState NewState) {
    if (NewState != DISABLE) {
        RCC->RCC_CFG0 |= RCC_CFG0_INTEN;
    } else {
        RCC->RCC_CFG0 &= (uint32_t)~((uint32_t)RCC_CFG0_INTEN);
    }
}
/** @defgroup PLL Peripheral access functions
 *  @brief  Perihal PLL Disable/Enable functions
 *
@verbatim
 ===============================================================================
           ##### PLL Peripheralaccess functions #####
 ===============================================================================

@endverbatim
  * @{
  */
/**
 * @brief PLL时钟源选择
 * @param  None
 * @retval None
 */
void RCC_PLLCLKConfig(RCC_PLLCLKSOURCE_TypeDef RCC_PLLCLKSource) {
    //		RCC->RCC_KEY = 0XFF;
    //		RCC->PLL_CFG &= ~((uint32_t)PLL_CFG_PLLCLKSEL);
    //		RCC->PLL_CFG |=
    //(uint32_t)(RCC_PLLCLKSource<<PLL_CFG_PLLCLKSEL_Pos);
}

/**
 * @brief PLL使能
 * @arg None
 * @arg None
 * @retval None
 */
void RCC_PLLCmd(FunctionalState NewState) {
    if (NewState != DISABLE) {
        //			RCC->RCC_KEY = 0XFF;
        //			RCC->PLL_CFG|= 1<<7;
    } else {
        //			RCC->RCC_KEY = 0XFF;
        //			RCC->PLL_CFG &=
        //(uint32_t)~((uint32_t)PLL_CFG_PLLON);
    }
}
/**
 * @brief PLLR使能
 * @arg None
 * @arg None
 * @retval None
 */
void RCC_PLLRCmd(FunctionalState NewState) {
    if (NewState != DISABLE) {
        //			RCC->RCC_KEY = 0XFF;
        //			RCC->PLL_CFG|= 1<<6;
        //			PLL_CFG_PLLREN;
    } else {
        //			RCC->RCC_KEY = 0XFF;
        //			RCC->PLL_CFG &=
        //(uint32_t)~((uint32_t)PLL_CFG_PLLREN);
    }
}

/**
 * @brief PLLQ使能
 * @arg None
 * @arg None
 * @retval None
 */
void RCC_PLLQCmd(FunctionalState NewState) {
    if (NewState != DISABLE) {
        //			RCC->RCC_KEY = 0XFF;
        //			RCC->PLL_CFG|= PLL_CFG_PLLQEN;
    } else {
        //			RCC->RCC_KEY = 0XFF;
        //			RCC->PLL_CFG &=
        //(uint32_t)~((uint32_t)PLL_CFG_PLLQEN);
    }
}
/**
 * @brief RCC中断标志
 * @arg RCC_IT_CLKIF
 * @arg None
 * @retval None
 */
ITStatus RCC_GetITStatus(uint32_t RCC_IT) {
    if ((RCC->RCC_STS & RCC_IT) != (uint32_t)RESET) {
        return (SET);
    }
    return (RESET);
}

/**
 * @brief RCC状态查询
 * @arg RCC_FLAG_PLLRDY =0:未锁定 		RCC_FLAG_PLLRDY =1:已锁定
 * @arg RCC_FLAG_LOCKERR =0:未失锁 		RCC_FLAG_PLLRDY =1:失锁异常
 * @arg None
 * @retval None
 */
FlagStatus RCC_GetFlagStatus(uint32_t RCC_FLAG) {
    if ((RCC->RCC_STS & RCC_FLAG) != (uint32_t)RESET) {
        return (SET);
    }
    return (RESET);
}
/**
 * @brief 清RCC中断
 * @arg RCC_IT_CLKIF
 * @arg None
 * @retval None
 */
void RCC_ClearITPendingBit(uint32_t RCC_IT) { RCC->RCC_STS |= RCC_IT_CLKIF; }

/** @defgroup AHB,APB0,APB1,APB2 Peripheral access functions
 *  @brief  Perihal Clk Disable/Enable functions
 *
@verbatim
 ===============================================================================
           ##### AHB,APB0,APB1,APB2 Peripheral access functions #####
 ===============================================================================

@endverbatim
  * @{
  */
/**
 * @brief APB0时钟使能
 * @arg None
 * @arg None
 * @retval None
 */
void RCC_APB0Cmd(FunctionalState NewState) {
    if (NewState != DISABLE) {
        RCCAPB0->APB0_CFG |= APB0_CFG_ENAPB;
    } else {
        RCCAPB0->APB0_CFG &= ~APB0_CFG_ENAPB;
    }
}
/**
 * @brief APB1时钟使能
 * @arg None
 * @arg None
 * @retval None
 */
void RCC_APB1Cmd(FunctionalState NewState) {
    if (NewState != DISABLE) {
        RCCAPB1->APB1_CFG |= APB1_CFG_ENAPB;
    } else {
        RCCAPB1->APB1_CFG &= ~APB1_CFG_ENAPB;
    }
}
/**
 * @brief APB2时钟使能
 * @arg None
 * @arg None
 * @retval None
 */
void RCC_APB2Cmd(FunctionalState NewState) {
    if (NewState != DISABLE) {
        RCCAPB2->APB2_CFG |= APB2_CFG_ENAPB;
    } else {
        RCCAPB2->APB2_CFG &= ~APB2_CFG_ENAPB;
    }
}
/**
 * @brief AHB的外设时钟使能
 * @arg RCC_AHBPeriph_DMA
 * @arg RCC_AHBPeriph_CRC
 * @retval None
 */
void RCC_AHBPeriphClockCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState) {
    if (NewState != DISABLE) {
        RCCAHB->AHB_CFG |= RCC_AHBPeriph;
    } else {
        RCCAHB->AHB_CFG &= ~RCC_AHBPeriph;
    }
}
/**
 * @brief APB0的外设时钟使能
 * @arg RCC_APB0Periph_TIM0
 * @arg RCC_APB0Periph_TIM1
 * @arg RCC_APB0Periph_TIM2
 * @arg RCC_APB0Periph_TIM3
 * @arg RCC_APB0Periph_TWI0
 * @arg RCC_APB0Periph_SPI0
 * @arg RCC_APB0Periph_UART0
 * @arg RCC_APB0Periph_UART1
 * @arg RCC_APB1Periph_ALL
 * @retval None
 */
void RCC_APB0PeriphClockCmd(uint32_t RCC_APB0Periph, FunctionalState NewState) {
    if (NewState != DISABLE) {
        RCCAPB0->APB0_CFG |= RCC_APB0Periph;
    } else {
        RCCAPB0->APB0_CFG &= ~RCC_APB0Periph;
    }
}
/**
 * @brief APB1的外设时钟使能
 * @arg RCC_APB1Periph_TIM4
 * @arg RCC_APB1Periph_TIM5
 * @arg RCC_APB1Periph_TIM6
 * @arg RCC_APB1Periph_TIM7
 * @arg RCC_APB1Periph_TWI1
 * @arg RCC_APB1Periph_UART2
 * @arg RCC_APB1Periph_ALL
 * @retval None
 */
void RCC_APB1PeriphClockCmd(uint32_t RCC_APB1Periph, FunctionalState NewState) {
    if (NewState != DISABLE) {
        RCCAPB1->APB1_CFG |= RCC_APB1Periph;
    } else {
        RCCAPB1->APB1_CFG &= ~RCC_APB1Periph;
    }
}

/**
 * @brief APB2的外设时钟使能
 * @arg RCC_APB2Periph_PWM1
 * @arg RCC_APB2Periph_LCD
 * @arg RCC_APB2Periph_UART3
 * @arg RCC_APB2Periph_ALL
 * @retval None
 */
void RCC_APB2PeriphClockCmd(uint32_t RCC_APB2Periph, FunctionalState NewState) {
    if (NewState != DISABLE) {
        RCCAPB2->APB2_CFG |= RCC_APB2Periph;
    } else {
        RCCAPB2->APB2_CFG &= ~RCC_APB2Periph;
    }
}
/** @defgroup AHB,APB0,APB1,APB2 Peripheral Reset access functions
 *  @brief  Perihal Reset functions
 *
@verbatim
 ===============================================================================
           ##### AHB,APB0,APB1,APB2 Peripheral Reset functions #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
 * @brief AHB外设复位
 * @arg RCC_AHBPeriph_DMA
 * @arg RCC_AHBPeriph_CRC
 * @retval None
 */
void RCC_AHBPeriphResetCmd(uint32_t RCC_AHBPeriph, FunctionalState NewState) {
    if (NewState != DISABLE) {
        RCCAHB->AHB_RST |= RCC_AHBPeriph;
    } else {
        RCCAHB->AHB_RST &= ~RCC_AHBPeriph;
    }
}

/**
 * @brief APB0外设复位
 * @arg RCC_APB0Periph_TIM0
 * @arg RCC_APB0Periph_TIM1
 * @arg RCC_APB0Periph_TIM2
 * @arg RCC_APB0Periph_TIM3
 * @arg RCC_APB0Periph_TWI0
 * @arg RCC_APB0Periph_SPI0
 * @arg RCC_APB0Periph_UART0
 * @arg RCC_APB0Periph_UART1
 * @arg RCC_APB1Periph_ALL
 * @retval None
 */
void RCC_APB0PeriphResetCmd(uint32_t RCC_APB0Periph, FunctionalState NewState) {
    assert_param(IS_RCC_APB0PERIPH(RCC_APB0Periph));
    if (NewState != DISABLE) {
        RCCAPB0->APB0_RST |= RCC_APB0Periph;
    } else {
        RCCAPB0->APB0_RST &= ~RCC_APB0Periph;
    }
}
/**
 * @brief APB1外设复位
 * @arg RCC_APB1Periph_TIM4
 * @arg RCC_APB1Periph_TIM5
 * @arg RCC_APB1Periph_TIM6
 * @arg RCC_APB1Periph_TIM7
 * @arg RCC_APB1Periph_TWI1
 * @arg RCC_APB1Periph_UART2
 * @arg RCC_APB1Periph_ALL
 * @retval None
 */
void RCC_APB1PeriphResetCmd(uint32_t RCC_APB1Periph, FunctionalState NewState) {
    assert_param(IS_RCC_APB1PERIPH(RCC_APB1Periph));
    if (NewState != DISABLE) {
        RCCAPB1->APB1_RST |= RCC_APB1Periph;
    } else {
        RCCAPB1->APB1_RST &= ~RCC_APB1Periph;
    }
}

/**
 * @brief APB2外设复位
 * @arg RCC_APB2Periph_PWM1
 * @arg RCC_APB2Periph_LCD
 * @arg RCC_APB2Periph_UART3
 * @arg RCC_APB2Periph_ALL
 * @retval None
 */
void RCC_APB2PeriphResetCmd(uint32_t RCC_APB2Periph, FunctionalState NewState) {
    if (NewState != DISABLE) {
        RCCAPB2->APB2_RST |= RCC_APB2Periph;
    } else {
        RCCAPB2->APB2_RST &= ~RCC_APB2Periph;
    }
}
/**
 * @}
 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
