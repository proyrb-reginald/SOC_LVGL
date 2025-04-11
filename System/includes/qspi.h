#ifndef _QSPI_H_
#define _QSPI_H_

#include "Function_Init.h"

// typedef struct
//{
//   uint32_t ClockPrescaler;     /* Specifies the prescaler factor for
//   generating clock based on the AHB clock.
//                                   This parameter can be a number between 0
//                                   and 255 */
//   uint32_t SampleShifting;     /* Specifies the Sample Shift. The data is
//   sampled 1/2 clock cycle delay later to
//                                   take in account external signal delays. (It
//                                   should be QSPI_SAMPLE_SHIFTING_NONE in DDR
//                                   mode) This parameter can be a value of @ref
//                                   QSPI_SampleShifting */
//   uint32_t ClockMode;            /* QSPI mode only mode0 and mode3 available
//   */ uint32_t Direction;            /* QSPI mode only MSB available*/
//   uint32_t MasterSlaveSel;       /* QSPI mode only Master mode available */
//   uint32_t CommunicateMode;
// }QSPI_InitTypeDef;

// typedef struct
//{
//   TWI_QSPIx_TypeDef          *Instance;        /* QSPI registers base address
//   */ QSPI_InitTypeDef           Init;             /* QSPI communication
//   parameters      */ uint8_t                    *pTxBuffPtr;      /* Pointer
//   to QSPI Tx transfer Buffer */
//   __IO uint32_t              TxXferSize;       /* QSPI Tx Transfer size */
//   __IO uint32_t              TxXferCount;      /* QSPI Tx Transfer Counter */
//   uint8_t                    *pRxBuffPtr;      /* Pointer to QSPI Rx transfer
//   Buffer */
//   __IO uint32_t              RxXferSize;       /* QSPI Rx Transfer size */
//   __IO uint32_t              RxXferCount;      /* QSPI Rx Transfer Counter */
// }QSPI_HandleTypeDef;

typedef struct {
    uint32_t LineMode;    /* Specifies the Instruction to be sent
                                This parameter can be a value (8-bit) between 0x00
                             and 0xFF */
    uint32_t DataWidth;   /* Specifies the Address to be sent (Size from 1 to 4
                           bytes according AddressSize)   This parameter can be a
                           value (32-bits) between 0x0 and 0xFFFFFFFF */
    uint32_t ReadOrWrite; /* 0:Write 1:Read */
    uint32_t ClockOnly;   /* Use for read mode @WR=1 */
    uint32_t DataLength;  /* Use for read mode @WR=1 */
} QSPI_CommandTypeDef;

typedef struct {
    uint32_t StrDir; /* Specifies the Instruction to be sent
                             This parameter can be a value (8-bit) between 0x00
                        and 0xFF */
    uint32_t StrTen; /* Specifies the Address to be sent (Size from 1 to 4 bytes
                        according AddressSize) This parameter can be a value
                        (32-bits) between 0x0 and 0xFFFFFFFF */
    uint32_t StrRen; /* 0:Write 1:Read */
} QSPI_StrmodeTypeDef;

/**
 * @}
 */
/** @defgroup QSPI_DWidth_TypeDef QSPI DWidth
 * @{
 */
typedef enum {
    QSPI_DWidth_8bit =
        (uint32_t)(0x00U << TWI_QSPIx_CON_DWIDTH_Pos), /*!Transmitted data
                                                          width:8 bit<*/
    QSPI_DWidth_16bit =
        (uint32_t)(0x01U << TWI_QSPIx_CON_DWIDTH_Pos), /*!Transmitted data
                                                          width:16 bit<*/
    QSPI_DWidth_24bit =
        (uint32_t)(0x02U << TWI_QSPIx_CON_DWIDTH_Pos), /*!Transmitted data
                                                          width:24 bit<*/
    QSPI_DWidth_32bit =
        (uint32_t)(0x03U << TWI_QSPIx_CON_DWIDTH_Pos), /*!Transmitted data
                                                          width:32 bit<*/
} QSPI_DWidth_TypeDef;
#define IS_QSPI_DWidth(DWidth)                                                 \
    (((DWidth) == QSPI_DWidth_8bit) || ((DWidth) == QSPI_DWidth_16bit) ||      \
     ((DWidth) == QSPI_DWidth_24bit) || ((DWidth) == QSPI_DWidth_32bit))

/**
 * @}
 */
/** @defgroup QSPI_LMode_TypeDef QSPI LMode
 * @{
 */
typedef enum {
    QSPI_LMode_0Line =
        (uint32_t)(0x00U
                   << TWI_QSPIx_CON_LMODE_Pos), /*!Transmitted line :0 line<*/
    QSPI_LMode_1Line =
        (uint32_t)(0x01U
                   << TWI_QSPIx_CON_LMODE_Pos), /*!Transmitted line :1 line<*/
    QSPI_LMode_2Line =
        (int32_t)(0x02UL
                  << TWI_QSPIx_CON_LMODE_Pos), /*!Transmitted line :2 line<*/
    QSPI_LMode_4Line =
        (int32_t)(0x03UL
                  << TWI_QSPIx_CON_LMODE_Pos), /*!Transmitted line :4 line<*/
} QSPI_LMode_TypeDef;
#define IS_QSPI_LMode(LMode)                                                   \
    (((LMode) == QSPI_LMode_0Line) || ((LMode) == QSPI_LMode_1Line) ||         \
     ((LMode) == QSPI_LMode_2Line) || ((LMode) == QSPI_LMode_4Line))

/** @defgroup QSPI_SShift_TypeDef QSPI SShift
 * @{
 */
typedef enum {
    QSPI_SShift_OFF =
        (uint32_t)(0x00U << TWI_QSPIx_CON_SSHIFT_Pos), /*!Sampling shift off<*/
    QSPI_SShift_HalfClock =
        (uint32_t)(0x01U << TWI_QSPIx_CON_SSHIFT_Pos), /*!HalfClock Sampling
                                                          shift open<*/
} QSPI_SShift_TypeDef;
#define IS_QSPI_SShift(SShift)                                                 \
    (((SShift) == QSPI_SShift_OFF) || ((SShift) == QSPI_SShift_HalfClock))

/**
 * @}
 */
/** @defgroup QSPI_DMAReq_TypeDef QSPI DMAReq
 * @{
 */
typedef enum {
    QSPI_DMAReq_RX =
        (uint32_t)TWI_SPIx_IDE_RXDMAEN, /*!< QSPI DMA Request: Receive */
    QSPI_DMAReq_TX =
        (uint32_t)TWI_SPIx_IDE_TXDMAEN, /*!< QSPI DMA Request: Transmit */
} QSPI_DMAReq_TypeDef;

#define IS_QSPI_DMAREQ(DMAREQ)                                                 \
    (((DMAREQ) == QSPI_DMAReq_RX) || ((DMAREQ) == QSPI_DMAReq_TX))
/**
 * @}
 */
#define IS_QSPI_ALL_PERIPH(PERIPH) (((PERIPH) == QSPI0) || ((PERIPH) == QSPI1))

/** @defgroup QSPI_Struct QSPI Struct
 * @{
 */
typedef struct {

    uint32_t QSPI_SShift;    /*!< This member configures QSPI.
                                  This parameter can be a value of @ref
                                QSPI_SShift_TypeDef. */
    uint32_t QSPI_Prescaler; /*!< This member configures QSPI.
                                  This parameter can be a value of @ref
                                QSPI_Prescaler_TypeDef. */
    uint32_t QSPI_DWidth;    /*!< This member configures QSPI.
                                 This parameter can be a value of @ref
                                QSPI_DWidth_TypeDef. */
    int32_t QSP_LMode;       /*!< This member configures QSPI.
                                 This parameter can be a value of @ref
                                QSPI_LMode_TypeDef. */
    uint32_t QSPI_Mode;      /*!< This member configures QSPI.
                                       This parameter can be a value of @ref
                                QSPI_Mode_TypeDef. */

    uint32_t QSPI_CPMode;  /*!< This member configures QSPI.
                                This parameter can be a value of @ref
                              QSPI_CPMode_TypeDef. */
    uint32_t QSPI_RW;      /*!< This member configures QSPI.
                                      This parameter can be a value of @ref
                              QSPI_RW_TypeDef. */
    uint32_t QSPI_CLKONLY; /*!< This member configures QSPI.
                                 This parameter can be a value of @ref
                              QSPI_CLKONLY_TypeDef. */

} QSPI_InitTypeDef;

/**
 * @}
 */
/** @defgroup QSPI_CPMode_TypeDef QSPI CPMode
 * @{
 */
typedef enum {
    QSPI_CPMode_Low =
        (uint32_t)((0x00U << TWI_QSPIx_CON_CPOL_Pos) |
                   (0x00U
                    << TWI_QSPIx_CON_CPHA_Pos)), /*!Idle clock low, sampling
                                                    along the first edge
                                                    sampling <*/
    QSPI_CPMode_High =
        (uint32_t)((0x01U << TWI_QSPIx_CON_CPOL_Pos) |
                   (0x01U
                    << TWI_QSPIx_CON_CPHA_Pos)), /*!Idle clock high, sampling
                                                    along the second edge<*/

} QSPI_CPMode_TypeDef;
#define IS_QSPI_CPMode(CPMode)                                                 \
    (((CPMode) == QSPI_CPMode_Low) || ((CPMode) == QSPI_CPMode_High))

/**
 * @}
 */
/** @defgroup QSPI_RW_TypeDef QSPI RW
 * @{
 */
typedef enum {
    QSPI_RW_Write = (uint32_t)((
        0x00U << TWI_QSPIx_CON_RW_Pos)), /*!QSPI write requirements<*/
    QSPI_RW_Read = (uint32_t)((
        0x01U << TWI_QSPIx_CON_RW_Pos)), /*!QSPI read requirements<*/

} QSPI_RW_TypeDef;
#define IS_QSPI_RW(RW) (((RW) == QSPI_RW_Write) || ((RW) == QSPI_RW_Read))

/**
 * @}
 */
/** @defgroup QSPI_Prescaler_TypeDef QSPI Prescaler
 * @{
 */
typedef enum {
    QSPI_Prescaler_1 =
        0x00U << TWI_QSPIx_CON_QTWCK_Pos, /*!< Clock division: Fsource/1    */
    QSPI_Prescaler_2 =
        0x01U << TWI_QSPIx_CON_QTWCK_Pos, /*!< Clock division: Fsource/2    */
    QSPI_Prescaler_4 =
        0x02U << TWI_QSPIx_CON_QTWCK_Pos, /*!< Clock division: Fsource/4    */
    QSPI_Prescaler_8 =
        0x03U << TWI_QSPIx_CON_QTWCK_Pos, /*!< Clock division: Fsource/8    */
    QSPI_Prescaler_16 =
        0x04U << TWI_QSPIx_CON_QTWCK_Pos, /*!< Clock division: Fsource/16    */
    QSPI_Prescaler_32 =
        0x05U << TWI_QSPIx_CON_QTWCK_Pos, /*!< Clock division: Fsource/32    */
    QSPI_Prescaler_64 =
        0x06U << TWI_QSPIx_CON_QTWCK_Pos, /*!< Clock division: Fsource/64    */
    QSPI_Prescaler_128 =
        0x07U << TWI_QSPIx_CON_QTWCK_Pos, /*!< Clock division: Fsource/128    */
    QSPI_Prescaler_256 =
        0x08U << TWI_QSPIx_CON_QTWCK_Pos, /*!< Clock division: Fsource/256    */
    QSPI_Prescaler_512 =
        0x09U << TWI_QSPIx_CON_QTWCK_Pos, /*!< Clock division: Fsource/512    */
    QSPI_Prescaler_1024 =
        0x0AU << TWI_QSPIx_CON_QTWCK_Pos, /*!< Clock division: Fsource/1024 */
    QSPI_Prescaler_2048 =
        (uint16_t)(0x0BU << TWI_QSPIx_CON_QTWCK_Pos), /*!< Clock division:
                                                         Fsource/2048   */
    QSPI_Prescaler_4096 =
        (uint16_t)(0x0CU << TWI_QSPIx_CON_QTWCK_Pos), /*!< Clock division:
                                                         Fsource/2048   */
} QSPI_Prescaler_TypeDef;
#define IS_QSPI_PRESCALER(PRESCALER)                                           \
    (((PRESCALER) == QSPI_Prescaler_1) || ((PRESCALER) == QSPI_Prescaler_2) || \
     ((PRESCALER) == QSPI_Prescaler_4) || ((PRESCALER) == QSPI_Prescaler_8) || \
     ((PRESCALER) == QSPI_Prescaler_16) ||                                     \
     ((PRESCALER) == QSPI_Prescaler_32) ||                                     \
     ((PRESCALER) == QSPI_Prescaler_64) ||                                     \
     ((PRESCALER) == QSPI_Prescaler_128) ||                                    \
     ((PRESCALER) == QSPI_Prescaler_256) ||                                    \
     ((PRESCALER) == QSPI_Prescaler_512) ||                                    \
     ((PRESCALER) == QSPI_Prescaler_1024) ||                                   \
     ((PRESCALER) == QSPI_Prescaler_2048) ||                                   \
     ((PRESCALER) == QSPI_Prescaler_4096))

/**
 * @}
 */
/** @defgroup QSPI_Mode_TypeDef QSPI Mode
 * @{
 */
typedef enum {
    QSPI_Mode_SPI =
        (uint32_t)(0x01U << TWI_QSPIx_CON_MODE_Pos), /*!Work mode:SPI <*/
    QSPI_Mode_QSPI =
        (uint32_t)(0x02U << TWI_QSPIx_CON_MODE_Pos), /*!Work mode:QSPI <*/
    QSPI_Mode_QSPISTRT =
        (uint32_t)((0x03U << TWI_QSPIx_CON_MODE_Pos) |
                   TWI_QSPIx_CON_STRTEN), /*!Work mode:QSPISTRT <*/
    QSPI_Mode_QSPISTRR =
        (uint32_t)((0x03U << TWI_QSPIx_CON_MODE_Pos) | TWI_QSPIx_CON_STRREN |
                   TWI_QSPIx_CON_STRDIR), /*!Work mode:QSPISTRR <*/
} QSPI_Mode_TypeDef;
#define IS_QSPI_Mode(Mode)                                                     \
    (((LMode) == QSPI_Mode_SPI) || ((LMode) == QSPI_Mode_QSPI) ||              \
     ((LMode) == QSPI_Mode_QSPISTRT) || ((LMode) == QSPI_Mode_QSPISTRR))

/*---------------------模式选择-------------------*/
/*---------------------传输功能模式选择-------------------*/
#define TWI_Mode 0x00000000U
#define Full_Duplex_SPI ((uint32_t)(0x1L << TWI_QSPIx_CON_MODE_Pos))
#define Half_Duplex_QSPI ((uint32_t)(0x2L << TWI_QSPIx_CON_MODE_Pos))
#define Str_mode_QSPI ((uint32_t)(0x3L << TWI_QSPIx_CON_MODE_Pos))
/*---------------------传输模式选择-------------------*/
#define QSPI_CLOCK_MODE_0 0x00000000U
#define QSPI_CLOCK_MODE_1 ((uint32_t)TWI_QSPIx_CON_CPHA)
#define QSPI_CLOCK_MODE_2 ((uint32_t)TWI_QSPIx_CON_CPOL)
#define QSPI_CLOCK_MODE_3 ((uint32_t)(TWI_QSPIx_CON_CPHA | TWI_QSPIx_CON_CPOL))
/*------------传输方向选择,可选MSB或LSB传输-----------*/
#define QSPI_MSB 0x00000000U
#define QSPI_LSB ((uint32_t)TWI_QSPIx_CON_DORD)
/*------------传输线模式,可选无数据，单线，双线，四线传输------------*/
#define QSPI_DATA_NONE 0x00000000U
#define QSPI_DATA_1_LINE ((uint32_t)(0x1L << TWI_QSPIx_CON_LMODE_Pos))
#define QSPI_DATA_2_LINES ((uint32_t)(0x2L << TWI_QSPIx_CON_LMODE_Pos))
#define QSPI_DATA_4_LINES                                                      \
    ((uint32_t)((uint32_t)0x3L << TWI_QSPIx_CON_LMODE_Pos))
/*--------------------传输宽度选择----------------------*/
#define QSPI_BYTES_8_BITS 0x00000000U
#define QSPI_BYTES_16_BITS ((uint32_t)(0x1L << TWI_QSPIx_CON_DWIDTH_Pos))
#define QSPI_BYTES_24_BITS ((uint32_t)(0x2L << TWI_QSPIx_CON_DWIDTH_Pos))
#define QSPI_BYTES_32_BITS ((uint32_t)(0x3L << TWI_QSPIx_CON_DWIDTH_Pos))
/*----------------------读写模式选择--------------------*/
#define Write 0x00000000U
#define Read ((uint32_t)TWI_QSPIx_CON_RW_Msk)

/*----------------------主从机选择--------------------*/
#define Slave 0x00000000U
#define Master ((uint32_t)TWI_QSPIx_CON_SMSTR)

/*-------------------------采样移位---------------------*/
#define QSPI_Collect_NONE 0x00000000U
#define QSPI_Collect_HALFCYCLE ((uint32_t)TWI_QSPIx_CON_SSHIFT)
/*------------------------只发时钟模式------------------*/
#define QSPI_CLKONLY_OFF 0x00000000U
#define QSPI_CLKONLY_ON ((uint32_t)TWI_QSPIx_CON_CLKONLY)
/*------------------------直通模式------------------*/
#define QSPI_INNER_TX 0x00000000U
#define QSPI_INNER_RX ((uint32_t)TWI_QSPIx_CON_STRDIR)

#define QSPI_INNER_DISTEN 0x00000000U
#define QSPI_INNER_TEN ((uint32_t)TWI_QSPIx_CON_STRTEN)

#define QSPI_INNER_DISREN 0x00000000U
#define QSPI_INNER_REN ((uint32_t)TWI_QSPIx_CON_STRREN)
/*--------------------传输频率选择----------------------*/
#define QSPI_PCLK_1 0x00000000U
#define QSPI_PCLK_2 ((uint32_t)(0x1L << TWI_QSPIx_CON_QTWCK_Pos))
#define QSPI_PCLK_4 ((uint32_t)(0x2L << TWI_QSPIx_CON_QTWCK_Pos))
#define QSPI_PCLK_8 ((uint32_t)(0x3L << TWI_QSPIx_CON_QTWCK_Pos))
#define QSPI_PCLK_16 ((uint32_t)(0x4L << TWI_QSPIx_CON_QTWCK_Pos))
#define QSPI_PCLK_32 ((uint32_t)(0x5L << TWI_QSPIx_CON_QTWCK_Pos))
#define QSPI_PCLK_64 ((uint32_t)(0x6L << TWI_QSPIx_CON_QTWCK_Pos))
#define QSPI_PCLK_128 ((uint32_t)(0x7L << TWI_QSPIx_CON_QTWCK_Pos))
#define QSPI_PCLK_256 ((uint32_t)(0x8L << TWI_QSPIx_CON_QTWCK_Pos))
#define QSPI_PCLK_512 ((uint32_t)(0x9L << TWI_QSPIx_CON_QTWCK_Pos))
#define QSPI_PCLK_1024 ((uint32_t)(0xAL << TWI_QSPIx_CON_QTWCK_Pos))
#define QSPI_PCLK_2048 ((uint32_t)(0xBL << TWI_QSPIx_CON_QTWCK_Pos))
#define QSPI_PCLK_4096 ((uint32_t)(0xCL << TWI_QSPIx_CON_QTWCK_Pos))

extern QSPI_CommandTypeDef sCommand;
extern QSPI_StrmodeTypeDef strmode;

void QSPI_Init(TWI_QSPIx_TypeDef *QSPIx, QSPI_InitTypeDef *QSPI_InitStruct);
void QSPI_StructInit(QSPI_InitTypeDef *QSPI_InitStruct);

#endif
