#include "main.h"
#include "lv_port_disp.h"
// #include "lv_port_indev.h"
#include "lvgl.h"
#include "sc32f10xx_touch_key_dynamic_debug.h"
#include "sc32f10xx_touch_key_function_resource.h"
#include "sc32f10xx_touch_key_parameter_analysis.h"
#include "stdio.h"
#include "timer.h"
#include "uart.h"
#include "ui.h"

/************************* Miscellaneous Configuration ************************/
/*!< Uncomment the following line if you need to relocate your vector Table in
     Internal SRAM. */
// #define VECT_TAB_SRAM
#define VECT_TAB_OFFSET 0x0U
/*!< Vector Table base offset field.
                                   This value must be a multiple of 0x100. */
#define SetIO_PA(x) PA_BIT(x) = 1
#define SetIO_PB(x) PB_BIT(x) = 1
#define SetIO_PC(x) PC_BIT(x) = 1
#define ResetIO_PA(x) PA_BIT(x) = 0
#define ResetIO_PB(x) PB_BIT(x) = 0
#define ResetIO_PC(x) PC_BIT(x) = 0

extern uint16_t TIM_BaseCnt; // 自定义TIM0计数变量

uint32_t TK_exKeyValueFlag = 0; // 当前轮按键标志
uint8_t exKeyValue = 0;
uint8_t gTkIsValid = 0;
uint8_t KeyValue = 0;
uint8_t SPIF_flag = 0;
uint8_t DL_OK = 0;
QSPI_CommandTypeDef sCommand;
QSPI_StrmodeTypeDef strmode;

int i = 0;
uint8_t PicNum = 0;
uint8_t menu = 1;
int value = 10;                     // 初始值
int picLeft1[] = {4, 13, 26, 36};   // 需要排除的数值列表，用...表示可能有很多数值//小循环左区间
int picRight1[] = {13, 26, 36, 48}; // 小循环右区间
int n1 = sizeof(picLeft1) / sizeof(picLeft1[0]);
int n2 = sizeof(picRight1) / sizeof(picRight1[0]);
int picLeft2[] = {50, 66, 83};  // 需要排除的数值列表，用...表示可能有很多数值//小循环左区间
int picRight2[] = {66, 83, 98}; // 小循环右区间
int n3 = sizeof(picLeft2) / sizeof(picLeft2[0]);
int n4 = sizeof(picRight2) / sizeof(picRight2[0]);
int picLeft3[] = {101, 112, 123, 134};  // 需要排除的数值列表，用...表示可能有很多数值//小循环左区间
int picRight3[] = {112, 123, 134, 144}; // 小循环右区间
int n5 = sizeof(picLeft3) / sizeof(picLeft3[0]);
int n6 = sizeof(picRight3) / sizeof(picRight3[0]);
int picLeft4[] = {146, 155, 166};  // 需要排除的数值列表，用...表示可能有很多数值//小循环左区间
int picRight4[] = {155, 166, 175}; // 小循环右区间
int n7 = sizeof(picLeft4) / sizeof(picLeft4[0]);
int n8 = sizeof(picRight4) / sizeof(picRight4[0]);
int a;

void SystemInit(void) {
    /* Configure the Vector Table location add offset address
     * ------------------*/
#ifdef VECT_TAB_SRAM
    SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM */
#else
    SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH */
#endif
}

void SystemClock_Config(void) {
    RCC->RCC_KEY = 0XFF;
#if 0 // HRC = 32M
    //		RCCAHB->AHB_CFG |= AHB_CFG_IFBEN;
    //		OPT->OPINX = 0X86;
    //		OPT->OPREG &= ~0X20;
    //		OPT->OPINX = 0X85;
    //		OPT->OPREG &= ~0X0F;
    //		OPT->OPREG |= 0X09;
    //		OPT->OPINX = 0X83;
    //		OPT->OPREG = 0X99;
    RCC->RCC_KEY = 0XFF;
    RCC->RCC_CFG0 = (0x1 << RCC_CFG0_WAIT_Pos); //WAIT = 01
    RCCAHB->AHB_CFG &= ~((uint32_t)AHB_CFG_CLKDIV);
    RCCAHB->AHB_CFG |= ((uint32_t)0x00000000);    //HLCK 1分频
#endif
#if 1                                            // HRC = 64M
    RCC->RCC_CFG0 |= (0X1 << RCC_CFG0_WAIT_Pos); // WAIT = 01~11
    RCC->RCC_CFG0 |= 0x00004000;
    RCC->RCC_CFG0 |= 0x00000200;
    RCCAHB->AHB_CFG &= ~((uint32_t)AHB_CFG_CLKDIV);
    RCCAHB->AHB_CFG |= ((uint32_t)0x00000000); // HLCK 1分频
    RCC->RCC_KEY = 0XFF;
    RCC->RCC_CFG0 |= 0x00000080;
#endif
    RCC_APB0Cmd(ENABLE);
    RCC_APB1Cmd(ENABLE);
    RCC_APB0PeriphClockCmd(RCC_APB0Periph_UART1, ENABLE); // 开启UART1时钟
    RCC_APB0PeriphClockCmd(RCC_APB0Periph_TWI0, ENABLE);  // 开启UART1时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TWI1, ENABLE);  // 开启UART1时钟
    __NVIC_EnableIRQ(TWIx_QSPIx_0_2_IRQn);
    __NVIC_EnableIRQ(TWIx_QSPIx_1_3_IRQn);
}

int PicLeft(void) {
    if (menu == 2) {
        for (a = 0; a < n1; a++) {  // 遍历排除数值列表
            if (i == picLeft1[a]) { // 如果找到了匹配的数值
                return picLeft1[a];
                //			break; //
                // 不需要继续减一操作，可以跳出外层循环（如果需要的话）
            }
        }
    }

    if (menu == 3) {
        for (a = 0; a < n3; a++) {  // 遍历排除数值列表
            if (i == picLeft2[a]) { // 如果找到了匹配的数值
                return picLeft2[a];
                //			break; //
                // 不需要继续减一操作，可以跳出外层循环（如果需要的话）
            }
        }
    }

    if (menu == 4) {
        for (a = 0; a < n5; a++) {  // 遍历排除数值列表
            if (i == picLeft3[a]) { // 如果找到了匹配的数值
                return picLeft3[a];
                //			break; //
                // 不需要继续减一操作，可以跳出外层循环（如果需要的话）
            }
        }
    }

    if (menu == 5) {
        for (a = 0; a < n7; a++) {  // 遍历排除数值列表
            if (i == picLeft4[a]) { // 如果找到了匹配的数值
                return picLeft4[a];
                //			break; //
                // 不需要继续减一操作，可以跳出外层循环（如果需要的话）
            }
        }
    }

    return 0xff;
}

int PicRight(void) {
    if (menu == 2) {
        for (a = 0; a < n2; a++) {   // 遍历排除数值列表
            if (i == picRight1[a]) { // 如果找到了匹配的数值
                return picRight1[a];
                //			break; //
                // 不需要继续减一操作，可以跳出外层循环（如果需要的话）
            }
        }
    }

    if (menu == 3) {
        for (a = 0; a < n4; a++) {   // 遍历排除数值列表
            if (i == picRight2[a]) { // 如果找到了匹配的数值
                return picRight2[a];
                //			break; //
                // 不需要继续减一操作，可以跳出外层循环（如果需要的话）
            }
        }
    }

    if (menu == 4) {
        for (a = 0; a < n6; a++) {   // 遍历排除数值列表
            if (i == picRight3[a]) { // 如果找到了匹配的数值
                return picRight3[a];
                //			break; //
                // 不需要继续减一操作，可以跳出外层循环（如果需要的话）
            }
        }
    }

    if (menu == 5) {
        for (a = 0; a < n8; a++) {   // 遍历排除数值列表
            if (i == picRight4[a]) { // 如果找到了匹配的数值
                return picRight4[a];
                //			break; //
                // 不需要继续减一操作，可以跳出外层循环（如果需要的话）
            }
        }
    }

    return 0xff;
}

void ChangeTouchKeyvalue(void) {
    switch (TK_exKeyValueFlag) { // 0x0003C000
    case 0x00004000:
        exKeyValue = 1;
        break;

    case 0x00008000:
        exKeyValue = 2;
        break;

    case 0x00010000:
        exKeyValue = 3;
        break;

    case 0x00020000:
        exKeyValue = 4;
        break;

    default:
        exKeyValue = 0xff;
        break;
    }
}

void SwitchPic(void) // 选择对应的菜单，增加对应的i值
{
    switch (PicNum) {
    // 0-3为一级菜单
    case 0:
        i = 4 + 0;
        break; // 第一张菜单

    case 1:
        i = 4 + 45;
        break; // 第二张菜单

    case 2:
        i = 4 + 96;
        break; // 第三张菜单

    case 3:
        i = 4 + 151;
        break; //

    default:
        break;
    }
}

void Sys_Scan(void) {
    if (TK_TouchKeyStatus &
        0x80) { // 重要步骤2:
                // 触摸键扫描一轮标志，是否调用TouchKeyScan()一定要根据此标志位置起后
        TK_TouchKeyStatus &= 0x7f;             // 重要步骤3: 清除标志位， 需要外部清除。
        TK_exKeyValueFlag = TK_TouchKeyScan(); // 按键数据处理函数
        //				printf("按下 value：%u\r\n",
        // TK_exKeyValueFlag);
        ChangeTouchKeyvalue();
        //        UpdateDisplay();
        TK_Restart(); // 启动下一轮转换
    }
}

int main(void) {
    SystemClock_Config();
    TK_Init();
    IO_Init();
    SC_DMA_Init();
    PA_BIT(0) = 0;
    PA_BIT(1) = 1;
    PA_BIT(2) = 1;
    SC_TIM0_Init();

    lv_init();
    lv_port_disp_init();
    ui_init();

    while (1) {
        // Sys_Scan();
        lv_timer_handler();
    }
}
