#ifndef _Function_Init_H_
#define _Function_Init_H_
#include "lcd.h"
#include "sc32f10xx_gpio.h"
#include "sc32f10xx_rcc.h"
#include "w1222a.h"
#include "main.h"
#include "qspi.h"
#include "sc32r803_tim.h"
#include "sc32r803_uart.h"
#include "stdio.h"
#include "timer.h"
#include "uart.h"
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long ulong;
typedef unsigned char uint8_t;

typedef struct {
    uint16_t DMA_Priority; /*!<  Specifies the software priority for the DMAy
                              Streamx. This parameter can be a value of @ref
                              DMA_Priority_level */

    uint16_t
        DMA_CircularMode; /*!< Specifies the DMA mode.
                                                                                                                                   This parameter can be a value of @ref DMA_CircularMode_TypeDef */

    uint16_t
        DMA_DataSize; /*!< Specifies the DMA data width.
                                                                                                                                           This parameter can be a value of @ref DMA_DataSize_TypeDef */

    uint16_t
        DMA_TargetMode; /*!< Specifies the DMA target address change mode.
                                                                                                                                   This parameter can be a value of @ref DMA_TargetMode_TypeDef */

    uint16_t
        DMA_SourceMode; /*!< Specifies the DMA source address change mode.
                                                                                                                                   This parameter can be a value of @ref DMA_Burst_TypeDef */

    uint16_t
        DMA_Burst; /*!< Specifies the counter dierction.
                                                                                                           This parameter can be a value of @ref DMA_Burst_TypeDef */

    uint32_t DMA_BufferSize; /*!< Specifies the buffer size, in data unit, of
                                the specified Stream.*/

    uint32_t
        DMA_Request; /*!< DMA request source.
                                                                                                                                    This parameter can be a value of @ref DMA_Request_TypeDef */

    uint32_t DMA_SrcAddress; /*!< The source memory Buffer address. */

    uint32_t DMA_DstAddress; /*!< The destination memory Buffer address. */

} DMA_InitTypeDef;

typedef enum {
    DMA_Priority_LOW =
        ((uint32_t)0x00U << DMA_CFG_PL_Pos), /*!< Priority level: Low       */
    DMA_Priority_MEDIUM =
        ((uint32_t)0x01U << DMA_CFG_PL_Pos), /*!< Priority level: Medium    */
    DMA_Priority_HIGH =
        ((uint32_t)0x02U << DMA_CFG_PL_Pos), /*!< Priority level: High      */
    DMA_Priority_VERY_HIGH =
        ((uint32_t)0x03U << DMA_CFG_PL_Pos), /*!< Priority level: Very High */
} DMA_Priority_TypeDef;

#define IS_DMA_PROIORITY(PROIORITY)                                            \
    (((PROIORITY) == DMA_Priority_LOW) ||                                      \
     ((PROIORITY) == DMA_Priority_MEDIUM) ||                                   \
     ((PROIORITY) == DMA_Priority_HIGH) ||                                     \
     ((PROIORITY) == DMA_Priority_VERY_HIGH))
/**
 * @}
 */

/** @brief DMA_CircularMode DMA CircularMode
 * @{
 */
typedef enum {
    DMA_CircularMode_Disable =
        ((uint32_t)0x00U << DMA_CFG_CIRC_Pos), /*!< DMA Mode: Disable */
    DMA_CircularMode_Enable =
        ((uint32_t)0x01U << DMA_CFG_CIRC_Pos), /*!< DMA Mode: Enable */
} DMA_CircularMode_TypeDef;

#define IS_DMA_CIRCULARMODE(MODE)                                              \
    (((MODE) == DMA_CircularMode_Disable) ||                                   \
     ((MODE) == DMA_CircularMode_Enable))
/**
 * @}
 */

/** @brief DMA_DataSize DMA Data DataSize
 * @{
 */
typedef enum {
    DMA_DataSize_Byte =
        ((uint32_t)0x00U
         << DMA_CFG_TXWIDTH_Pos), /*!< Peripheral data alignment: Byte     */
    DMA_DataSize_HakfWord =
        ((uint32_t)0x01U
         << DMA_CFG_TXWIDTH_Pos), /*!< Peripheral data alignment: HalfWord */
    DMA_DataSize_Word =
        ((uint32_t)0x03U
         << DMA_CFG_TXWIDTH_Pos), /*!< Peripheral data alignment: Word     */
} DMA_DataSize_TypeDef;

#define IS_DMA_DATASIZE(SIZE)                                                  \
    (((SIZE) == DMA_DataSize_Byte) || ((SIZE) == DMA_DataSize_HakfWord) ||     \
     ((SIZE) == DMA_DataSize_Word))
/**
 * @}
 */

/** @brief DMA_TargetMode DMA Target Address Change Mode
 * @{
 */
typedef enum {
    DMA_TargetMode_FIXED =
        ((uint32_t)0x00U
         << DMA_CFG_DAINC_Pos), /*!< DMA Target Mode: Fixed address */
    DMA_TargetMode_INC =
        ((uint32_t)0x01U
         << DMA_CFG_DAINC_Pos), /*!< DMA Target Mode: Address increase */
    DMA_TargetMode_DEC =
        ((uint32_t)0x02U
         << DMA_CFG_DAINC_Pos), /*!< DMA Target Mode: Address decrease */
    DMA_TargetMode_INC_CIRC =
        ((uint32_t)0x03U
         << DMA_CFG_DAINC_Pos), /*!< DMA Target Mode: Address increase loop */
} DMA_TargetMode_TypeDef;

#define IS_DMA_TARGERT_MODE(MODE)                                              \
    (((MODE) == DMA_TargetMode_FIXED) || ((MODE) == DMA_TargetMode_INC) ||     \
     ((MODE) == DMA_TargetMode_DEC) || ((MODE) == DMA_TargetMode_INC_CIRC))
/**
 * @}
 */

/** @brief DMA_SourceMode DMA Source
 * @{
 */
typedef enum {
    DMA_SourceMode_FIXED =
        ((uint32_t)0x00U
         << DMA_CFG_SAINC_Pos), /*!< DMA Source Mode: Fixed address */
    DMA_SourceMode_INC =
        ((uint32_t)0x01U
         << DMA_CFG_SAINC_Pos), /*!< DMA Source Mode: Address increase */
    DMA_SourceMode_DEC =
        ((uint32_t)0x02U
         << DMA_CFG_SAINC_Pos), /*!< DMA Source Mode: Address decrease */
    DMA_SourceMode_INC_CIRC =
        ((uint32_t)0x03U
         << DMA_CFG_SAINC_Pos), /*!< DMA Source Mode: Address increase loop */
} DMA_SourceMode_TypeDef;

#define IS_DMA_SOURCE_MODE(MODE)                                               \
    (((MODE) == DMA_SourceMode_FIXED) || ((MODE) == DMA_SourceMode_INC) ||     \
     ((MODE) == DMA_SourceMode_DEC) || ((MODE) == DMA_SourceMode_INC_CIRC))
/**
 * @}
 */

/** @brief DMA_Burst  DMA Brust
 * @{
 */
typedef enum {
    DMA_Burst_Disable = ((uint16_t)0x00000000), /*!< Brust Mode Disable */
    DMA_Burst_1B = (((uint16_t)0x07U << DMA_CFG_BURSIZE_Pos) |
                    DMA_CFG_TPTYPE), /*!< Burst Mode: rease 1 */
    DMA_Burst_2B = (((uint16_t)0x06U << DMA_CFG_BURSIZE_Pos) |
                    DMA_CFG_TPTYPE), /*!< Burst Mode: rease 2 */
    DMA_Burst_4B = (((uint16_t)0x05U << DMA_CFG_BURSIZE_Pos) |
                    DMA_CFG_TPTYPE), /*!< Burst Mode: rease 4 */
    DMA_Burst_8B = (((uint16_t)0x04U << DMA_CFG_BURSIZE_Pos) |
                    DMA_CFG_TPTYPE), /*!< Burst Mode: rease 8 */
    DMA_Burst_16B = (((uint16_t)0x03U << DMA_CFG_BURSIZE_Pos) |
                     DMA_CFG_TPTYPE), /*!< Burst Mode: rease 16 */
    DMA_Burst_32B = (((uint16_t)0x02U << DMA_CFG_BURSIZE_Pos) |
                     DMA_CFG_TPTYPE), /*!< Burst Mode: rease 32 */
    DMA_Burst_64B = (((uint16_t)0x01U << DMA_CFG_BURSIZE_Pos) |
                     DMA_CFG_TPTYPE), /*!< Burst Mode: rease 64 */
    DMA_Burst_128B = (((uint16_t)0x00U << DMA_CFG_BURSIZE_Pos) |
                      DMA_CFG_TPTYPE), /*!< Burst Mode: rease 128 */
} DMA_Burst_TypeDef;

#define IS_DMA_BURST(BURST)                                                    \
    (((BURST) == DMA_Burst_Disable) || ((BURST) == DMA_Burst_1B) ||            \
     ((BURST) == DMA_Burst_2B) || ((BURST) == DMA_Burst_4B) ||                 \
     ((BURST) == DMA_Burst_8B) || ((BURST) == DMA_Burst_16B) ||                \
     ((BURST) == DMA_Burst_32B) || ((BURST) == DMA_Burst_64B) ||               \
     ((BURST) == DMA_Burst_128B))
/**
 * @}
 */

/** @brief DMA_Request  DMA Request Source
 * @{
 */
typedef enum {
    DMA_Request_Null =
        ((uint32_t)0x0000U << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: Null    */
    DMA_Request_UART0_TX =
        ((uint32_t)0x0002U
         << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: UART0 TX */
    DMA_Request_UART0_RX =
        ((uint32_t)0x0003U
         << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: UART0 RX */
    DMA_Request_UART1_TX =
        ((uint32_t)0x0004U
         << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: UART1 TX */
    DMA_Request_UART1_RX =
        ((uint32_t)0x0005U
         << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: UART1 RX */
    DMA_Request_TWI_QSPI0_TX =
        ((uint32_t)0x000CU << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: SPI0 TX */
    DMA_Request_TWI_QSPI0_RX =
        ((uint32_t)0x000DU << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: SPI0 RX */
    DMA_Request_TWI_QSPI1_TX =
        ((uint32_t)0x000EU << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: SPI1 TX */
    DMA_Request_TWI_QSPI1_RX =
        ((uint32_t)0x000FU << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: SPI1 RX */
    DMA_Request_TWI_SPI2_TX =
        ((uint32_t)0x0014U << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: TWI0 TX */
    DMA_Request_TWI_SPI2_RX =
        ((uint32_t)0x0015U << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: TWI0 RX */
    DMA_Request_TIM1_TI =
        ((uint32_t)0x0021U << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: TIM1 TI */
    DMA_Request_TIM1_CAPF =
        ((uint32_t)0x0022U
         << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: TIM1 Falling edge capture */
    DMA_Request_TIM1_CAPR =
        ((uint32_t)0x0023U
         << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: TIM1 Rising edge capture  */
    DMA_Request_TIM2_TI =
        ((uint32_t)0x0024U << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: TIM2 TI */
    DMA_Request_TIM2_CAPF =
        ((uint32_t)0x0025U
         << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: TIM2 Falling edge capture */
    DMA_Request_TIM2_CAPR =
        ((uint32_t)0x0026U
         << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: TIM2 Rising edge capture  */
    DMA_Request_TIM6_TI =
        ((uint32_t)0x0030U << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: TIM6 TI */
    DMA_Request_TIM6_CAPF =
        ((uint32_t)0x0031U
         << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: TIM6 Falling edge capture */
    DMA_Request_TIM6_CAPR =
        ((uint32_t)0x0032U
         << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: TIM6 Rising edge capture  */
    DMA_Request_ADC =
        ((uint32_t)0x003BU << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: ADC    */
    DMA_Request_DMA0 =
        ((uint32_t)0x003CU << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: DMA0    */
    DMA_Request_DMA1 =
        ((uint32_t)0x003DU << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: DMA1    */
    DMA_Request_DMA2 =
        ((uint32_t)0x003EU << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: DMA2    */
    DMA_Request_DMA3 =
        ((uint32_t)0x003FU << DMA_CFG_REQSRC_Pos), /*!< DMA Requtest: DMA3    */

} DMA_Request_TypeDef;

#define PIC_COL 480
#define PIC_ROW 272

#define Test_Mode Striaight_Mode

#define Flash_Communication 0
#define LCD_Communication 1
#define Striaight_Mode 2

#define DMA_Test 0 // DMA测试时需要改目标地址和请求源
/*--------------------IO----------------------------*/
#define CS_IO PB_BIT(13)   // P34
#define CS_IO1 PB_BIT(2)   // P34
#define Mode_IO PC_BIT(11) // P33
#define Fsys_IO PC_BIT(2)  // P22
#define Test_IO PC_OT(15)  // P23
#define Data_IO PC_OT(3)   // P23
#define SPIF_IO PC_OT(4)   // P24
#define RXNEIF_IO PC_OT(5) // P25
#define TXEIF_IO PC_OT(6)  // P26
#define RXFIF_IO PC_OT(8)  // P27
#define RXHIF_IO PC_OT(7)  // P30
#define TXHIF_IO PC_OT(9)  // P31
#define WCOL_IO PC_OT(10)  // P32
#define DLUFIF_IO PC_OT(0) ////////////////////????????????????
/*---------------------初始化------------------------*/
#define QSPI_Enable ON
// #define QSPI_Function           Str_mode_QSPI
#define QSPI_Function Half_Duplex_QSPI
#define QSPI_Mode_Select QSPI_CLOCK_MODE_0
#define QSPI_Clk_Select QSPI_PCLK_1
#define QSPI_SPOS_Select SPOS0
#define QSPI_SSHIFT_Select QSPI_Collect_HALFCYCLE

// 其他设置项
#define QSPI_MSBLSB_Select QSPI_MSB
#define Master_Slave_Select Master

#define STR_MODE_DL 2 // 65280
/*------------------SPI0/1中断开关----------------------*/
#define SPI_Int_Switch ON    // 中断
#define SPI_TBLE_Switch OFF  // 发送缓存为空中断使能
#define SPI_QTWIE_Switch OFF // QTWIF中断使能
/*------------------SPI0中断开关----------------------*/
#define SPI_RXNEIE_Switch OFF // 接收缓存区非空中断使能
#define SPI_RXFIF_Switch OFF  // 接收FIFO溢出中断使能
#define SPI_RXHIE_Switch OFF  // 接收FIFO超一半中断使能
#define SPI_TXHIE_Switch OFF  // 发送FIFO超一半中断使能
#define SPI_DLUFIE_Switch ON  // DL下溢中断使能

/*---------------------开和关-------------------------*/
#define ON 1  // 开
#define OFF 0 // 关

extern uint8_t SPIF_flag;
extern uint8_t SPI_Receive_Buffer[20];
extern uint8_t DL_OK;
extern const uint8_t pic[STR_MODE_DL];
void Flash_Communication_Test(TWI_QSPIx_TypeDef *qspi);
void LCD_Communication_Test(TWI_QSPIx_TypeDef *qspi);
void Striaight_Mode_Test(TWI_QSPIx_TypeDef *qspi_flash,
                         TWI_QSPIx_TypeDef *qspi_lcd, uint32_t addr);
void W25QXX_Flash_Test(TWI_QSPIx_TypeDef *qspi, uint8_t *WriteData,
                       uint32_t size);
void DispPic(TWI_QSPIx_TypeDef *qspi, const uint8_t *data, uint32_t len);

void Uart1_Config(unsigned int Clk, unsigned int Baud);
void SC_DMA_Init(void);
void DMA_Init(DMA_TypeDef *DMAx, DMA_InitTypeDef *DMA_InitStruct);
void DMA_SetCurrDataCounter(DMA_TypeDef *DMAx, uint32_t Counter);
void DMA_Cmd(DMA_TypeDef *DMAx, FunctionalState NewState);
void DMA_SetSrcAddress(DMA_TypeDef *DMAx, uint32_t SrcAddress);
void DMA_StructInit(DMA_InitTypeDef *DMA_InitStruct);
#endif
