/*
 ******************************************************************************
 * @file    sc32r803_uart.c
 * @author  SOC AE Team
 * @version V0.1
 * @date     29-09-2024
 * @brief UART function module
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
#include "sc32r803_uart.h"

/** @defgroup UART_Exported_Group1 Configuration of the UART computation unit
functions
 *  @brief   Configuration of the UART computation unit functions
 *
@verbatim
 ===============================================================================
                     ##### UART configuration functions #####
 ===============================================================================
@endverbatim
  * @{
  */
UART_TypeDef *Printf_Uart;
/**
 * @brief  DeInitializes the UART peripheral
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART0:UART peripheral select UART0
 *                  - UART1:UART peripheral select UART1
 *                  - UART2:UART peripheral select UART2
 *                  - UART3:UART peripheral select UART3
 *                  - UART4:UART peripheral select UART4
 *                  - UART5:UART peripheral select UART5
 * @retval None
 */
void UART_DeInit(UART_TypeDef *UARTx) {
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    if (UARTx == UART0) {
        /* Enable UART0 reset state */
        RCC_APB0PeriphResetCmd(RCC_APB0Periph_UART0, ENABLE);
        /* Release UART0 from reset state */
        RCC_APB0PeriphResetCmd(RCC_APB0Periph_UART0, DISABLE);
    } else if (UARTx == UART1) {
        /* Enable UART1 reset state */
        RCC_APB0PeriphResetCmd(RCC_APB0Periph_UART1, ENABLE);
        /* Release UART1 from reset state */
        RCC_APB0PeriphResetCmd(RCC_APB0Periph_UART1, DISABLE);
    } else if (UARTx == UART2) {
        /* Enable UART2 reset state */
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART2, ENABLE);
        /* Release UART2 from reset state */
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART2, DISABLE);
    } else if (UARTx == UART3) {
        /* Enable UART3 reset state */
        RCC_APB2PeriphResetCmd(RCC_APB2Periph_UART3, ENABLE);
        /* Release UART3 from reset state */
        RCC_APB2PeriphResetCmd(RCC_APB2Periph_UART3, DISABLE);
    } else if (UARTx == UART4) {
        /* Enable UART4 reset state */
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART4, ENABLE);
        /* Release UART4 from reset state */
        RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART4, DISABLE);
    } else if (UARTx == UART5) {
        /* Enable UART5 reset state */
        RCC_APB0PeriphResetCmd(RCC_APB0Periph_UART5, ENABLE);
        /* Release UART5 from reset state */
        RCC_APB0PeriphResetCmd(RCC_APB0Periph_UART5, DISABLE);
    }
}

/**
 * @brief  Initializes the UARTx peripheral according to
 *         the specified parameters in the UART_InitStruct.
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART0:UART peripheral select UART0
 *                  - UART1:UART peripheral select UART1
 *                  - UART2:UART peripheral select UART2
 *                  - UART3:UART peripheral select UART3
 *                  - UART4:UART peripheral select UART4
 *                  - UART5:UART peripheral select UART5
 * @param  UART_InitStruct[out]:Pointer to structure UART_InitTypeDef, to be
 * initialized.
 * @retval None
 * @note The default SYSCLK clock source is HRC
 */
void UART_Init(UART_TypeDef *UARTx, UART_InitTypeDef *UART_InitStruct) {
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_Mode(UART_InitStruct->UART_Mode));

    tmpreg = UARTx->UART_CON;
    tmpreg &= (uint32_t)~(UART_CON_SM01 | UART_CON_SM2);
    tmpreg |= (uint32_t)(UART_InitStruct->UART_Mode);
    UARTx->UART_CON = tmpreg;

    if (UART_InitStruct->UART_Mode == UART_Mode_8B) {
        assert_param(IS_UART_PRESCALER(UART_InitStruct->UART_BaudRate));

        UARTx->UART_CON &= ~(uint32_t)UART_CON_PERSCALER;
        UARTx->UART_CON |= (uint32_t)UART_InitStruct->UART_BaudRate;
    } else {
        tmpreg = (UART_InitStruct->UART_ClockFrequency /
                  UART_InitStruct->UART_BaudRate);
        if (tmpreg > 65535) {
            UARTx->UART_CON |= (uint32_t)UART_CON_PERSCALER;
            tmpreg = tmpreg / 16;
        }
        UARTx->UART_BAUD = tmpreg;
    }
}

/**
 * @brief  Enables or disables the specified UART peripheral.
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART0:UART peripheral select UART0
 *                  - UART1:UART peripheral select UART1
 *                  - UART2:UART peripheral select UART2
 *                  - UART3:UART peripheral select UART3
 *                  - UART4:UART peripheral select UART4
 *                  - UART5:UART peripheral select UART5
 * @param  NewState[in]:new state of the UARTx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void UART_TXCmd(UART_TypeDef *UARTx, FunctionalState NewState) {
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        /* Enable the UART TX Function */
        UARTx->UART_CON |= UART_CON_TXEN;
    } else {
        /* Disable the UART TX Function */
        UARTx->UART_CON &= (uint16_t)~UART_CON_TXEN;
    }
}

/**
 * @brief  Enables or disables the specified UART peripheral.
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART0:UART peripheral select UART0
 *                  - UART1:UART peripheral select UART1
 *                  - UART2:UART peripheral select UART2
 *                  - UART3:UART peripheral select UART3
 *                  - UART4:UART peripheral select UART4
 *                  - UART5:UART peripheral select UART5
 * @param  NewState[in]:new state of the UARTx peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void UART_RXCmd(UART_TypeDef *UARTx, FunctionalState NewState) {
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        /* Enable the UART RX Function */
        UARTx->UART_CON |= UART_CON_RXEN;
    } else {
        /* Disable the UART RX Function */
        UARTx->UART_CON &= (uint16_t)~UART_CON_RXEN;
    }
}

/**
 * @}
 */

/** @defgroup UART_Group2 Data transfers functions
 *  @brief   Data transfers functions
 *
@verbatim
 ===============================================================================
                      ##### Data transfers functions #####
 ===============================================================================
@endverbatim
  * @{
  */

/**
 * @brief  Transmits single data through the UARTx peripheral.
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART0:UART peripheral select UART0
 *                  - UART1:UART peripheral select UART1
 *                  - UART2:UART peripheral select UART2
 *                  - UART3:UART peripheral select UART3
 *                  - UART4:UART peripheral select UART4
 *                  - UART5:UART peripheral select UART5
 * @param  Data[in]: the data to transmit.
 * @retval None
 */
void UART_SendData(UART_TypeDef *UARTx, uint16_t Data) {
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    /* Transmit Data */
    UARTx->UART_DATA = (Data & (uint16_t)0x01FF);
}

/**
 * @brief  Returns the most recent received data by the UARTx peripheral.
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART0:UART peripheral select UART0
 *                  - UART1:UART peripheral select UART1
 *                  - UART2:UART peripheral select UART2
 *                  - UART3:UART peripheral select UART3
 *                  - UART4:UART peripheral select UART4
 *                  - UART5:UART peripheral select UART5
 * @retval The received data.
 */
uint16_t UART_ReceiveData(UART_TypeDef *UARTx) {
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    /* Receive Data */
    return (uint16_t)(UARTx->UART_DATA & (uint16_t)0x01FF);
}

/**
 * @}
 */

/** @defgroup UART_Group3 Pin remap management functions
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
 * @brief  Configures the TIMx Pin Remap
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART0:UART peripheral select UART0
 *                  - UART1:UART peripheral select UART1
 *                  - UART2:UART peripheral select UART2
 *                  - UART3:UART peripheral select UART3
 *                  - UART4:UART peripheral select UART4
 *                  - UART5:UART peripheral select UART5
 * @param  UART_Remap[in]: specifies the UARTx input remapping source.
 *                  - UART_PinRemap_Default:TIM Pin Remap  Disable
 *                  - UART_PinRemap_A :TIM Pin Remap: Remap mode A
 * @retval None
 */
void UART_PinRemapConfig(UART_TypeDef *UARTx,
                         UART_PinRemap_TypeDef UART_Remap) {
    uint32_t tmpreg;

    /* Check the parameters */
    if (UARTx == UART1 || UARTx == UART2 || UARTx == UART5) {
        tmpreg = UARTx->UART_CON;

        tmpreg &= (uint32_t)(~UART_CON_SPOS);

        tmpreg |= UART_Remap;

        UARTx->UART_CON = tmpreg;
    }
}

/**
 * @}
 */
/* End of UART_Group3.	*/

/** @defgroup UART_Group4 Interrupts, DMA and flags management functions
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
 * @brief  Enables or disables the specified UART interrupts.
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART0:UART peripheral select UART0
 *                  - UART1:UART peripheral select UART1
 *                  - UART2:UART peripheral select UART2
 *                  - UART3:UART peripheral select UART3
 *                  - UART4:UART peripheral select UART4
 *                  - UART5:UART peripheral select UART5
 * @param  UART_IT[in]:specifies the UART interrupts sources to be enabled or
 * disabled.
 *                  - UART_IT_EN:UART Interrupt
 *                  - UART_IT_TX:Transmit Interrupt
 *                  - UART_IT_RX:Receive Interrupt
 *                  - UART_IT_BK:UART Interrupt: Break Interrupt
 *                  - UART_IT_SL:SLVHEIE Interrupt
 *                  - UART_IT_SY:SYNCIE Interrupt
 * @param  NewState[in]: new state of the UART interrupts.
 *          This parameter can be: ENABLE or DISABLE.
 * @retval None
 */
void UART_ITConfig(UART_TypeDef *UARTx, uint16_t UART_IT,
                   FunctionalState NewState) {
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_IT(UART_IT));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        /* Enable the Interrupt sources */
        UARTx->UART_IDE |= UART_IT;
    } else {
        /* Disable the Interrupt sources */
        UARTx->UART_IDE &= (uint16_t)~UART_IT;
    }
}

/**
 * @brief  Checks whether the specified UART flag is set or not.
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART0:UART peripheral select UART0
 *                  - UART1:UART peripheral select UART1
 *                  - UART2:UART peripheral select UART2
 *                  - UART3:UART peripheral select UART3
 *                  - UART4:UART peripheral select UART4
 *                  - UART5:UART peripheral select UART5
 * @param  UART_FLAG[in]: specifies the flag to check.
 *                  - UART_Flag_RX:Receive flag
 *                  - UART_Flag_TX:Transmit flag
 *                  - UART_Flag_BK:Break flag
 *                  - UART_Flag_SY:SYNCIE flag
 * @retval The new state of UART_FLAG (SET or RESET).
 */
FlagStatus UART_GetFlagStatus(UART_TypeDef *UARTx,
                              UART_FLAG_TypeDef UART_FLAG) {
    ITStatus bitstatus = RESET;
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_GET_UART_FLAG(UART_FLAG));

    if ((UARTx->UART_STS & UART_FLAG) != (uint16_t)RESET) {
        bitstatus = SET;
    } else {
        bitstatus = RESET;
    }
    return bitstatus;
}

/**
 * @brief  Clears the UARTx's pending flags.
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART0:UART peripheral select UART0
 *                  - UART1:UART peripheral select UART1
 *                  - UART2:UART peripheral select UART2
 *                  - UART3:UART peripheral select UART3
 *                  - UART4:UART peripheral select UART4
 *                  - UART5:UART peripheral select UART5
 * @param  UART_FLAG[in]: specifies the flag bit to clear.
 *                  - UART_Flag_RX:Receive flag
 *                  - UART_Flag_TX:Transmit flag
 *                  - UART_Flag_BK:Break flag
 *                  - UART_Flag_SY:SYNCIE flag
 *                  - UART_Flag_SLVYN:SLVYN flag
 *                  - UART_Flag_SLVHE:SLVHE flag
 * @retval None
 */
void UART_ClearFlag(UART_TypeDef *UARTx, uint16_t UART_FLAG) {
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    /* Clear the flags */
    UARTx->UART_STS = (uint16_t)UART_FLAG;
}

/**
 * @brief  Clears the UARTx's pending flags.
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART0:UART peripheral select UART0
 *                  - UART1:UART peripheral select UART1
 * @param  UART_DMAReq[in]: specifies the flag bit to clear.
 *                  - UART_DMAReq_RX:UART DMA Request Receive
 *                  - UART_DMAReq_TX:UART DMA Request Transmit
 * @retval None
 */
void UART_DMACmd(UART_TypeDef *UARTx, uint16_t UART_DMAReq,
                 FunctionalState NewState) {
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_DMAREQ(UART_DMAReq));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        /* Enable the DMA transfer for selected requests by setting the DMAT
           and/or DMAR bits in the UART IDE register */
        UARTx->UART_IDE |= UART_DMAReq;
    } else {
        /* Disable the DMA transfer for selected requests by clearing the DMAT
           and/or DMAR bits in the UART IDE register */
        UARTx->UART_IDE &= (uint16_t)~UART_DMAReq;
    }
}
/* End of UART_Group3.	*/

/** @defgroup UART_Group5 Interrupts, LIN functions
 *  @brief
 *
@verbatim
 ===============================================================================
            ##### Interrupts, #####
 ===============================================================================
@endverbatim
  * @{
  */
/**
 * @brief  Enables or disables the specified UART interrupts.
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART2:UART peripheral select UART2
 * @param  UART_LINMODE[in]:Select uart lin working mode
 *                  - UART_MASTER:UART_MASTER
 *                  - UART_SLAVER:UART_SLAVER
 * @retval None
 */

void UART_LIN_MODE(UART_TypeDef *UARTx, UART_LINMODE_TypeDef UART_LINMODE) {
    uint32_t temp;
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_LINMODE(UART_LINMODE));

    if (UARTx == UART2) {
        temp = UART2->UART_CON;
        temp &= ~(UART_CON_SLVEN | UART_CON_FUNCSEL);
        temp |= UART_LINMODE;
        UART2->UART_CON = temp;
    }
}
/**
 * @brief  Configure the LIN interval segment generation bit length.
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART2:UART peripheral select UART2
 * @param  BKSIZE[in]: Interval segment generate bit length
 *                  - UART_BKSIZE_10:UART BKSIZE 10
 *                  - UART_BKSIZE_13:UART BKSIZE 13
 * @retval None
 */
void UART_LIN_BKSIZE(UART_TypeDef *UARTx, UART_BKSIZE_TypeDef BKSIZE) {
    uint32_t temp;
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_BKSIZE(BKSIZE));

    if (UARTx == UART2) {
        temp = UART2->UART_CON;
        temp &= ~UART_CON_BKSIZE;
        temp |= BKSIZE;
        UART2->UART_CON = temp;
    }
}

/**
 * @brief  MASTER mode sends a break interval
 * @retval None
 */
void UART_SendBreak() { UART2->UART_CON |= UART_CON_BKTR; }

/**
 * @brief  The LIN slave automatic resynchronization mode was enabled.
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART2:UART peripheral select UART2
 * @param  NewState[in]: new state of the UART interrupts.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 *
 * @retval None
 */
void UART_LIN_SLVARENE(UART_TypeDef *UARTx, FunctionalState NewState) {

    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));

    if (UARTx == UART2) {
        if (NewState != DISABLE) {
            /* Enable the DMA transfer for selected requests by setting the DMAT
               and/or DMAR bits in the UART IDE register */
            UART2->UART_CON |= UART_CON_SLVAREN;
        } else {
            /* Disable the DMA transfer for selected requests by clearing the
               DMAT and/or DMAR bits in the UART IDE register */
            UART2->UART_CON &= (uint16_t)~UART_CON_SLVAREN;
        }
    }
}

/**
 * @brief  Configure the LIN break detection length.
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART2:UART peripheral select UART2
 * @param  LBDL[in]: Select the open circuit detection length
 *                  - UART_LBDL_10:UART_LBDL_10
 *                  - UART_LBDL_11:UART_LBDL_11
 * @retval None
 */
void UART_LIN_LBDL(UART_TypeDef *UARTx, UART_LBDL_TypeDef LBDL) {
    uint32_t temp;
    /* Check the parameters */
    assert_param(IS_UART_ALL_PERIPH(UARTx));
    assert_param(IS_UART_LBDL(LBDL));

    if (UARTx == UART2) {
        temp = UART2->UART_CON;
        temp &= ~UART_CON_LBDL;
        temp |= LBDL;
        UART2->UART_CON = temp;
    }
}

/**
 * @brief  ID conversion PID calculation formula
 * @param  id[in]: lin Communication ID.
 * @retval PID
 */
uint8_t LIN_CalID(uint8_t id) {
    uint8_t parity, p0, p1;

    parity = id;
    p0 = (BIT(parity, 0) ^ BIT(parity, 1) ^ BIT(parity, 2) ^ BIT(parity, 4))
         << 6;
    p1 = (!(BIT(parity, 1) ^ BIT(parity, 3) ^ BIT(parity, 4) ^ BIT(parity, 5)))
         << 7;

    parity |= (p0 | p1);

    return parity;
}
/**
 * @brief  lin communication checksum
 * @param  id[in]: lin Communication ID.
 * @param  data[out]: Send data array.
 * @param  len[in]: Send data array length.
 * @retval LIN Checksum
 */
uint8_t LINCalChecksum(uint8_t id, uint8_t *data, uint8_t len) {
    uint32_t sum = LIN_CalID(id);
    uint8_t i;

    for (i = 0; i < len; i++) {
        sum += data[i];
        if (sum & 0xFF00) {
            sum = (sum & 0x00FF) + 1;
        }
    }

    sum ^= 0x00FF;
    return (uint8_t)sum;
}

/**
 * @}
 */
/* End of UART_Group4.	*/
#if AvoidSemiHostEable
#include "stdio.h" /*This header file is required when using printf*/
#ifdef __ARMCC_VERSION
#pragma import(__use_no_semihosting)
// 标准库需要的支持函数
struct __FILE {
    int handle;
};

FILE __stdout;
// 定义_sys_exit()以避免使用半主机模式
void _sys_exit(int x) { x = x; }
#endif
#endif

/**
 * @brief  Enabled or Disable The printf function .
 * @param  UARTx[out]:  where x can be to select the UARTx peripheral.
 *                  - UART0:UART peripheral select UART0
 *                  - UART1:UART peripheral select UART1
 *                  - UART2:UART peripheral select UART2
 * @retval None
 */
__attribute__((weak)) void Printf_UartInit(UART_TypeDef *UARTx) {

    Printf_Uart = UARTx;
}
/*printf mapping function*/
#if defined(__ARMCC_VERSION) || defined(__ICCARM__)
__attribute__((weak)) int fputc(int c, FILE *f) {
    UART_SendData(Printf_Uart, (uint8_t)c);
    while (!UART_GetFlagStatus(Printf_Uart, UART_Flag_TX))
        ;
    UART_ClearFlag(Printf_Uart, UART_Flag_TX);
    return c;
}
#elif defined(__GNUC__)
__attribute__((weak)) int _write(int fd, char *pbuffer, int size) {
    for (int i = 0; i < size; i++) {
        UART_SendData(UART3, (uint8_t)(*pbuffer++));
        while (!UART_GetFlagStatus(UART3, UART_Flag_TX))
            ;
        UART_ClearFlag(UART3, UART_Flag_TX);
    }

    return size;
}

#endif
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
