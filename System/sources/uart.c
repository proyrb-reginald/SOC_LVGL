#include "Function_Init.h"
// void Uart1_Config(unsigned int Clk,unsigned int Baud)
//{
//	/* uart初始化 */
//	UART1->UART_CON |= 0x1UL<<UART_CON_SPOS_Pos;
//	UART1->UART_CON |= 0x1UL<<UART_CON_SM01_Pos;
//	UART1->UART_CON |= UART_CON_TXEN;
//	UART1->UART_CON |= UART_CON_RXEN;
//	UART1->UART_BAUD = Clk / Baud;
// }

// int fputc(int ch, FILE *f)
//{
//     UART1->UART_DATA = ch;
//     while(!(UART1->UART_STS & 0x02));
//	UART1->UART_STS |= 0x02;
//     return (ch);
// }
void SC_UART0_Init(void) {

    // Forbid editing areas between the labels !!!
    /*GPIOInit_PC02 Struct*/ GPIO_InitTypeDef GPIOInit_PB11_Struct;
    GPIOInit_PB11_Struct.GPIO_Pin = GPIO_Pin_11;
    GPIOInit_PB11_Struct.GPIO_Mode = GPIO_Mode_IN;
    GPIOInit_PB11_Struct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOB, &GPIOInit_PB11_Struct); /*TX0?????*/
    /*GPIOInit_PC03 Struct*/ GPIO_InitTypeDef GPIOInit_PB12_Struct;
    GPIOInit_PB12_Struct.GPIO_Pin = GPIO_Pin_12;
    GPIOInit_PB12_Struct.GPIO_Mode = GPIO_Mode_IN;
    GPIOInit_PB12_Struct.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOB, &GPIOInit_PB12_Struct); /*RX0?????*/
    RCC_APB0PeriphClockCmd(RCC_APB0Periph_UART0, ENABLE);
    /*Init Struct*/ UART_InitTypeDef UART_InitStruct;
    UART_InitStruct.UART_ClockFrequency = 32000000;
    UART_InitStruct.UART_BaudRate = 115200;
    UART_InitStruct.UART_Mode = UART_Mode_10B;
    UART_Init(UART0, &UART_InitStruct);
    /*INT_EN*/ UART_ITConfig(UART0, UART_IT_EN, DISABLE);
    /*DMA_TX*/ UART_DMACmd(UART0, UART_DMAReq_TX, DISABLE);
    /*DMA_RX*/ UART_DMACmd(UART0, UART_DMAReq_RX, DISABLE);
    /*Init Struct*/ UART_PinRemapConfig(UART0, UART_PinRemap_Default);
    UART_TXCmd(UART0, ENABLE);
    UART_RXCmd(UART0, ENABLE);
}

int fputc(int c, FILE *f) {
    UART_SendData(UART0, (uint8_t)c);

    while (!UART_GetFlagStatus(UART0, UART_Flag_TX))
        ;

    UART_ClearFlag(UART0, UART_Flag_TX);
    return c;
}
