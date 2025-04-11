#include "main.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"
#include "lvgl.h"
#include "sc32f10xx_TK_DynamicDebug.h"
#include "sc32f10xx_TK_FunctionResource.h"
#include "sc32f10xx_TK_ParameterAnalysis.h"
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

uint32_t TK_exKeyValueFlag = 0; // ��ǰ�ְ�����־
uint8_t exKeyValue = 0;
uint8_t gTkIsValid = 0;
uint8_t KeyValue = 0;
void SystemClock_Config(void);

void SystemInit(void);
/******************************************************************************/
void SystemClock_Config(void);

uint8_t SPIF_flag = 0;

uint8_t DL_OK = 0;
extern uint16_t TIM_BaseCnt; // �Զ���TIM0��������

QSPI_CommandTypeDef sCommand;
QSPI_StrmodeTypeDef strmode;
void SystemInit(void) {
    /* Configure the Vector Table location add offset address
     * ------------------*/
#ifdef VECT_TAB_SRAM
    SCB->VTOR = SRAM_BASE |
                VECT_TAB_OFFSET; /* Vector Table Relocation in Internal SRAM */
#else
    SCB->VTOR = FLASH_BASE |
                VECT_TAB_OFFSET; /* Vector Table Relocation in Internal FLASH */
#endif
}

int i = 0;
uint8_t PicNum = 0;
uint8_t menu = 1;
int value = 10; // ��ʼֵ
int picLeft1[] = {
    4, 13, 26, 36}; // ��Ҫ�ų�����ֵ�б���...��ʾ�����кܶ���ֵ//Сѭ��������
int picRight1[] = {13, 26, 36, 48}; // Сѭ��������
int n1 = sizeof(picLeft1) / sizeof(picLeft1[0]);
int n2 = sizeof(picRight1) / sizeof(picRight1[0]);
int picLeft2[] = {
    50, 66, 83}; // ��Ҫ�ų�����ֵ�б���...��ʾ�����кܶ���ֵ//Сѭ��������
int picRight2[] = {66, 83, 98}; // Сѭ��������
int n3 = sizeof(picLeft2) / sizeof(picLeft2[0]);
int n4 = sizeof(picRight2) / sizeof(picRight2[0]);
int picLeft3[] = {
    101, 112, 123,
    134}; // ��Ҫ�ų�����ֵ�б���...��ʾ�����кܶ���ֵ//Сѭ��������
int picRight3[] = {112, 123, 134, 144}; // Сѭ��������
int n5 = sizeof(picLeft3) / sizeof(picLeft3[0]);
int n6 = sizeof(picRight3) / sizeof(picRight3[0]);
int picLeft4[] = {
    146, 155, 166}; // ��Ҫ�ų�����ֵ�б���...��ʾ�����кܶ���ֵ//Сѭ��������
int picRight4[] = {155, 166, 175}; // Сѭ��������
int n7 = sizeof(picLeft4) / sizeof(picLeft4[0]);
int n8 = sizeof(picRight4) / sizeof(picRight4[0]);
int a;

int PicLeft(void) {
    if (menu == 2) {
        for (a = 0; a < n1; a++) {  // �����ų���ֵ�б�
            if (i == picLeft1[a]) { // ����ҵ���ƥ�����ֵ
                return picLeft1[a];
                //			break; //
                // ����Ҫ������һ�����������������ѭ���������Ҫ�Ļ���
            }
        }
    }

    if (menu == 3) {
        for (a = 0; a < n3; a++) {  // �����ų���ֵ�б�
            if (i == picLeft2[a]) { // ����ҵ���ƥ�����ֵ
                return picLeft2[a];
                //			break; //
                // ����Ҫ������һ�����������������ѭ���������Ҫ�Ļ���
            }
        }
    }

    if (menu == 4) {
        for (a = 0; a < n5; a++) {  // �����ų���ֵ�б�
            if (i == picLeft3[a]) { // ����ҵ���ƥ�����ֵ
                return picLeft3[a];
                //			break; //
                // ����Ҫ������һ�����������������ѭ���������Ҫ�Ļ���
            }
        }
    }

    if (menu == 5) {
        for (a = 0; a < n7; a++) {  // �����ų���ֵ�б�
            if (i == picLeft4[a]) { // ����ҵ���ƥ�����ֵ
                return picLeft4[a];
                //			break; //
                // ����Ҫ������һ�����������������ѭ���������Ҫ�Ļ���
            }
        }
    }

    return 0xff;
}

int PicRight(void) {
    if (menu == 2) {
        for (a = 0; a < n2; a++) {   // �����ų���ֵ�б�
            if (i == picRight1[a]) { // ����ҵ���ƥ�����ֵ
                return picRight1[a];
                //			break; //
                // ����Ҫ������һ�����������������ѭ���������Ҫ�Ļ���
            }
        }
    }

    if (menu == 3) {
        for (a = 0; a < n4; a++) {   // �����ų���ֵ�б�
            if (i == picRight2[a]) { // ����ҵ���ƥ�����ֵ
                return picRight2[a];
                //			break; //
                // ����Ҫ������һ�����������������ѭ���������Ҫ�Ļ���
            }
        }
    }

    if (menu == 4) {
        for (a = 0; a < n6; a++) {   // �����ų���ֵ�б�
            if (i == picRight3[a]) { // ����ҵ���ƥ�����ֵ
                return picRight3[a];
                //			break; //
                // ����Ҫ������һ�����������������ѭ���������Ҫ�Ļ���
            }
        }
    }

    if (menu == 5) {
        for (a = 0; a < n8; a++) {   // �����ų���ֵ�б�
            if (i == picRight4[a]) { // ����ҵ���ƥ�����ֵ
                return picRight4[a];
                //			break; //
                // ����Ҫ������һ�����������������ѭ���������Ҫ�Ļ���
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

void SwitchPic(void) // ѡ���Ӧ�Ĳ˵������Ӷ�Ӧ��iֵ
{
    switch (PicNum) {
    // 0-3Ϊһ���˵�
    case 0:
        i = 4 + 0;
        break; // ��һ�Ų˵�

    case 1:
        i = 4 + 45;
        break; // �ڶ��Ų˵�

    case 2:
        i = 4 + 96;
        break; // �����Ų˵�

    case 3:
        i = 4 + 151;
        break; //

    default:
        break;
    }
}

// void SwitchLast(void)
//{
//	switch(i)
//     {        						//0-3Ϊһ���˵�
//         case 4:i = 12;break;    //4-9   		4  5  6  --- 7  8  9
//         case 13:i = 25;break; 	//10-15		10 11 12 --- 13 14 15
//         case 26:i = 35;break;	//16-24		16 17 18 19  ---  20 21
//         22 23
//		case 36:i = 48;break;   //25-31 		24 25 26 27
//---  28 29 30 31
//         default:break;
//     }
// }

// void UpdateDisplay(void)
//{
//     if (exKeyValue != 0xff) {
//         if (gTkIsValid == 0) { //����ǰֻ��һ�μ�
//             gTkIsValid = 1;
//             KeyValue = exKeyValue;

//            if (menu == 1) {
//                if (KeyValue == 4) {
//                    if (PicNum == 0) {
//                        PicNum = 4;
//                    }

//                    PicNum--;
//                    Striaight_Mode_Test(QSPI0, QSPI1, PicNum);
//                }

//                if (KeyValue == 3) {
//                    PicNum++;

//                    if (PicNum == 4) {
//                        PicNum = 0;
//                    }

//                    Striaight_Mode_Test(QSPI0, QSPI1, PicNum);
//                }

//                if (KeyValue == 2) {
//                    SwitchPic();
//                    Striaight_Mode_Test(QSPI0, QSPI1, i);
//                    menu = 2 + PicNum;
//                }
//            }
//            /*				ѡ���һ��ͼƬ��Ĳ˵����ܸı�
//            */ else if (menu == 2) {
//                if (KeyValue == 4) {
//                    if (i == PicLeft()) {
//                        i--;    //����ִ�к�����forѭ��
//                    }

//                    if (i == 4 || i == 3) {
//                        i = 48;
//                    }

//                    for (; i != PicLeft(); i--) { //�����������ֹͣ
//                        Striaight_Mode_Test(QSPI0, QSPI1, i);
//                    }
//                }

//                if (KeyValue == 3) {
//                    if (i == PicRight()) {
//                        i++;    //����ִ�к�����forѭ��
//                    }

//                    if (i == 49 || i == 48) {
//                        i = 4;
//                    }

//                    for (; i != PicRight(); i++) { //�ӵ��������ֹͣ
//                        Striaight_Mode_Test(QSPI0, QSPI1, i);
//                    }
//                }

//                if (KeyValue == 2) {
//                }

//                if (KeyValue == 1) {
//                    Striaight_Mode_Test(QSPI0, QSPI1, PicNum);
//                    menu = 1;
//                }
//            }
//            /*				ѡ��ڶ���ͼƬ��Ĳ˵����ܸı�
//            */ else if (menu == 3) {
//                if (KeyValue == 4) {
//                    if (i == PicLeft()) {
//                        i--;    //����ִ�к�����forѭ��
//                    }

//                    if (i == 50 || i == 49) {
//                        i = 98;
//                    }

//                    for (; i != PicLeft(); i--) { //�����������ֹͣ
//                        Striaight_Mode_Test(QSPI0, QSPI1, i);
//                    }
//                }

//                if (KeyValue == 3) {
//                    if (i == PicRight()) {
//                        i++;    //����ִ�к�����forѭ��
//                    }

//                    for (; i != PicRight(); i++) { //�ӵ��������ֹͣ
//                        Striaight_Mode_Test(QSPI0, QSPI1, i);
//                    }

//                    if (i == 99 || i == 98) {
//                        i = 49;
//                        Striaight_Mode_Test(QSPI0, QSPI1, i);
//                    }//���⴦�����99��һ֡��Ϊ��49֡
//                }

//                if (KeyValue == 2) {
//                }

//                if (KeyValue == 1) {
//                    Striaight_Mode_Test(QSPI0, QSPI1, PicNum);
//                    menu = 1;
//                }
//            }
//            /*				ѡ�������ͼƬ��Ĳ˵����ܸı�
//            */ else if (menu == 4) {
//                if (KeyValue == 4) {
//                    if (i == PicLeft()) {
//                        i--;    //����ִ�к�����forѭ��
//                    }

//                    if (i == 100 || i == 101) {
//                        i = 144;
//                    }

//                    for (; i != PicLeft(); i--) { //�����������ֹͣ
//                        Striaight_Mode_Test(QSPI0, QSPI1, i);
//                    }
//                }

//                if (KeyValue == 3) {
//                    if (i == PicRight()) {
//                        i++;    //����ִ�к�����forѭ��
//                    }

//                    for (; i != PicRight(); i++) { //�ӵ��������ֹͣ
//                        Striaight_Mode_Test(QSPI0, QSPI1, i);
//                    }

//                    if (i == 144 || i == 145) {
//                        i = 100;
//                        Striaight_Mode_Test(QSPI0, QSPI1, i);
//                    }//���⴦��
//                }

//                if (KeyValue == 2) {
//                }

//                if (KeyValue == 1) {
//                    Striaight_Mode_Test(QSPI0, QSPI1, PicNum);
//                    menu = 1;
//                }
//            }
//            /*				ѡ�������ͼƬ��Ĳ˵����ܸı�
//            */ else if (menu == 5) {
//                if (KeyValue == 4) {
//                    if (i == PicLeft()) {
//                        i--;    //����ִ�к�����forѭ��
//                    }

//                    if (i == 145 || i == 144) {
//                        i = 175;
//                    }

//                    for (; i != PicLeft(); i--) { //�����������ֹͣ
//                        Striaight_Mode_Test(QSPI0, QSPI1, i);
//                    }

//                    if (i == 145 || i == 146) {
//                        i = 175;
//                        Striaight_Mode_Test(QSPI0, QSPI1, i);
//                    }
//                }

//                if (KeyValue == 3) {
//                    if (i == PicRight()) {
//                        i++;    //����ִ�к�����forѭ��
//                    }

//                    if (i == 175 || i == 176) {
//                        i = 146;
//                        Striaight_Mode_Test(QSPI0, QSPI1, i);
//                    }

//                    for (; i != PicRight(); i++) { //�ӵ��������ֹͣ
//                        Striaight_Mode_Test(QSPI0, QSPI1, i);
//                    }

//                    if (i == 175) {
//                        Striaight_Mode_Test(QSPI0, QSPI1, i);
//                    }
//                }

//                if (KeyValue == 2) {
//                }

//                if (KeyValue == 1) {
//                    Striaight_Mode_Test(QSPI0, QSPI1, PicNum);
//                    menu = 1;
//                }
//            }
//        }
//    } else {
//        gTkIsValid = 0;
//    }
//}

void Sys_Scan(void) {
    if (TK_TouchKeyStatus &
        0x80) { // ��Ҫ����2:
                // ������ɨ��һ�ֱ�־���Ƿ����TouchKeyScan()һ��Ҫ���ݴ˱�־λ�����
        TK_TouchKeyStatus &= 0x7f; // ��Ҫ����3: �����־λ�� ��Ҫ�ⲿ�����
        TK_exKeyValueFlag = TK_TouchKeyScan(); // �������ݴ�����
        //				printf("���� value��%u\r\n",
        // TK_exKeyValueFlag);
        ChangeTouchKeyvalue();
        //        UpdateDisplay();
        TK_Restart(); // ������һ��ת��
    }
}

int main(void) {
    // uint16_t k=0;
    SystemClock_Config(); // ϵͳʱ��ѡ��
    TK_Init();
    IO_Init(); // IO��ʼ�����������
    SC_DMA_Init();
    //    Uart1_Config(32000000, 9600); //PC11_TX,���ﲻ��printf�Ļ����ò�����
    //		SC_UART0_Init();
    //		printf("\r\n UART0 OK! \r\n");
    //	while(1);
    PA_BIT(0) = 0;
    PA_BIT(1) = 1;
    PA_BIT(2) = 1;
    //	PC_BIT(0) = 0;
    SC_TIM0_Init();
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

    //		lv_obj_t* switch_obj = lv_switch_create(lv_scr_act());
    //		lv_obj_set_size(switch_obj, 120, 60);
    //		lv_obj_align(switch_obj, LV_ALIGN_CENTER, 0, 0);

    ui_init();

    //		PB_BIT(12)=0;
    //		PB_BIT(11)=0;
    //		PB_BIT(10)=0;
    //		PB_BIT(9)=0;
    while (1) {
        //        WDT->WDT_CON |= WDT_CON_CLRWDT;	//ι�� WDT_CON_CLRWDT
        Sys_Scan(); // ����TK��������
        //			Delay(100);
        lv_timer_handler();
    }
}

/*==========================================
                   ʱ��Դѡ����
==========================================*/
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
    RCCAHB->AHB_CFG |= ((uint32_t)0x00000000);    //HLCK 1��Ƶ
#endif
#if 1                                            // HRC = 64M
    RCC->RCC_CFG0 |= (0X1 << RCC_CFG0_WAIT_Pos); // WAIT = 01~11
    RCC->RCC_CFG0 |= 0x00004000;
    RCC->RCC_CFG0 |= 0x00000200;
    RCCAHB->AHB_CFG &= ~((uint32_t)AHB_CFG_CLKDIV);
    RCCAHB->AHB_CFG |= ((uint32_t)0x00000000); // HLCK 1��Ƶ
    RCC->RCC_KEY = 0XFF;
    RCC->RCC_CFG0 |= 0x00000080;
#endif
    RCC_APB0Cmd(ENABLE);
    RCC_APB1Cmd(ENABLE);
    RCC_APB0PeriphClockCmd(RCC_APB0Periph_UART1, ENABLE); // ����UART1ʱ��
    RCC_APB0PeriphClockCmd(RCC_APB0Periph_TWI0, ENABLE);  // ����UART1ʱ��
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TWI1, ENABLE);  // ����UART1ʱ��
    __NVIC_EnableIRQ(TWIx_QSPIx_0_2_IRQn);
    __NVIC_EnableIRQ(TWIx_QSPIx_1_3_IRQn);
}
