#ifndef __LCD_H
#define __LCD_H
#include "W1222A.h"
#include "stdint.h"
/* Includes ------------------------------------------------------------------*/
#define POINT_SIZE 10
#define START_X 50
#define START_Y 30
#define DIRRECTION Horizontal

void Init_LCD(TWI_QSPIx_TypeDef *qspi);
void LCDBlockWrite(TWI_QSPIx_TypeDef *qspi, unsigned int Xstart,
                   unsigned int Xend, unsigned int Ystart, unsigned int Yend);
void Delayms(uint16_t num);
void delay10s(void);
void write_sendcmd(TWI_QSPIx_TypeDef *qspi, uint8_t cmddata);
void write_senddata(TWI_QSPIx_TypeDef *qspi, uint8_t cmddata, uint8_t *data,
                    uint32_t len);
void write_send_onlyQdata(TWI_QSPIx_TypeDef *qspi, uint32_t cmddata,
                          uint16_t data, uint32_t len, uint32_t start,
                          uint32_t end);
void DispColor(TWI_QSPIx_TypeDef *qspi, uint16_t sx, uint16_t ex, uint16_t sy,
               uint16_t ey, uint16_t *color_p);
void Lcd_Refrsh_DMA(TWI_QSPIx_TypeDef *qspi, uint16_t sx, uint16_t ex,
                    uint16_t sy, uint16_t ey, uint16_t *color_p);
void QSPI_SendCmd(TWI_QSPIx_TypeDef *qspi, uint32_t cmd, uint32_t cmdMode,
                  uint32_t addr, uint32_t addrMode, uint32_t addrSize,
                  uint32_t dataMode, uint32_t altermode, uint32_t alter,
                  uint32_t alterSize, uint32_t Dummy);

#define RED 0xF800 // 定义颜色常量 0xF800
#define GREEN 0x07E0
#define BLUE 0x001F
#define WHITE 0xFFFF
#define BLACK 0x0000
#define GRAY 0xEF5D // 0x2410
#define GRAY75 0x39E7
#define GRAY50 0x7BEF
#define GRAY25 0xADB5

#define Horizontal 0 // 横向
#define Vertical 1   // 纵向
/* -------------------------LCD_Command-----------------------------*/
#define Read_Dispaly_idinformaiton2 0x04 //
#define Read_Display_status 0x09         // 读屏状态
#define Enter_sleep_m144ode 0x10         // 进入睡眠模式
#define Sleep_out 0x11                   // 推出睡眠模式
#define Partial_Mode_ON 0x12
#define Normal_Display_mode_ON 0x13
#define Display_OFF 0X28
#define Display_ON 0X29
#define Column_Address_Set 0x2A
#define Page_Address_Set 0x2B
#define Memory_Write 0X2C
#define Partial_Area 0X30
#define Vertical_Scrolling_Definition 0X33
#define Tearing_Effect_Line_OFF 0x34
#define Tearing_Effect_Line_ON 0x35
#define Memory_Access_Control 0x36
#define Vertical_Scrolling_Start_Address 0x37
#define Idle_Mode_OFF 0X38
#define Idle_Mode_ON 0X39
#define Pixel_Format_Set 0X3A
#define Write_Memory_Continue 0X3C
#define Set_Tear_Scanline 0X44
#define Get_Scanline 0X45
#define Write_Display_Brightness 0X51
#define Write_CTRL_Display 0X53
#define Read_ID1 0XDA
#define Read_ID2 0XDB
#define Read_ID3 0XDC
#define SPI_2DATA_control 0xB1
#define TE_Control 0XB4
#define Display_Function_Control 0XB6
#define Power_Criterion_Control 0XC1
#define Vreg1a_voltage_Control 0XC3
#define Vreg1b_voltage_Control 0XC4
#define Vreg2a_voltage_Control 0XC9
#define Inversion 0XEC
#define Inter_Register_Enable1 0XFE
#define Inter_Register_Enable2 0XEF
#define SET_GAMM_A1 0XF0
#define SET_GAMM_A2 0XF1
#define SET_GAMM_A3 0XF2
#define SET_GAMM_A4 0XF3

#endif
