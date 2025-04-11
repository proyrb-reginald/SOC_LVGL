#include "function_init.h"
void IO_Init(void) {
    GPIOA->PXCON = 0XFFFF;
    GPIOB->PXCON = 0XFFFF;
    GPIOC->PXCON = 0XFFFF;
    GPIOD->PXCON = 0XFFFF;
    GPIOA->PIN = 0XFFFF;
    GPIOB->PIN = 0XFFFF;
    GPIOC->PIN = 0XFFFF;
    GPIOD->PIN = 0XFFFF;
    GPIOB->PXPH = 0xFFFF;
    // 初始化UART1 PC1,PC2口为输入带上拉
    GPIO_InitTypeDef UART1_TX_RX;
    UART1_TX_RX.GPIO_Pin = GPIO_Pin_5;
    UART1_TX_RX.GPIO_Mode = GPIO_Mode_IN;
    UART1_TX_RX.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOD, &UART1_TX_RX);

    PD_BIT(0) = 1;
}
