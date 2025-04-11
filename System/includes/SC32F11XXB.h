/**
  ******************************************************************************
  * @file    SC32F11XXB.h
  * @author  SOC SA Team
  * @brief   CMSIS Cortex-M0+ Device Peripheral Access Layer Header File.
  *          This file contains all the peripheral register's definitions, bits
  *          definitions and memory mapping for SC32F10XX devices.
  *
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral's registers hardware
  *
  ******************************************************************************
  * @attention

  ******************************************************************************
  */

/** @addtogroup CMSIS_Device
 * @{
 */

/** @addtogroup sc32f11xx
 * @{
 */

#ifndef SC32F11XXB_H
#define SC32F11XXB_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/** @addtogroup Configuration_section_for_CMSIS
 * @{
 */

/**
 * @brief Configuration of the Cortex-M0+ Processor and Core Peripherals
 */
#define __CM0PLUS_REV 0U  /*!< Core Revision r0p0                            */
#define __MPU_PRESENT 1U  /*!< Coretex Mo+  provides an MPU                  */
#define __VTOR_PRESENT 1U /*!< Vector  Table  Register supported */
#define __NVIC_PRIO_BITS                                                       \
    2U /*!< SC32F10XX uses 2 Bits for the Priority Levels                      \
        */
#define __Vendor_SysTickConfig                                                 \
    0U /*!< Set to 1 if different SysTick Config is used  */

/**
 * @}
 */

/** @addtogroup Peripheral_interrupt_number_definition
 * @{
 */

/**
 * @brief SC32F10XX Interrupt Number Definition, according to the selected
 * device in @ref Library_configuration_section
 */

/*!< Interrupt Number Definition */
typedef enum {
    /******  Cortex-M0+ Processor Exceptions Numbers
     ***************************************************************/
    NonMaskableInt_IRQn = -14, /*!< 2 Non Maskable Interrupt */
    HardFault_IRQn = -13,      /*!< 3 Cortex-M Hard Fault Interrupt      */
    SVC_IRQn = -5,             /*!< 11 Cortex-M SV Call Interrupt             */
    PendSV_IRQn = -2,          /*!< 14 Cortex-M Pend SV Interrupt          */
    SysTick_IRQn = -1,         /*!< 15 Cortex-M System Tick Interrupt         */
    /******  STM32G0xxxx specific Interrupt Numbers
     ****************************************************************/
    EXTI0_IRQn = 0,           /*!< EXTI  0 Interrupt           */
    EXTI1_7_IRQn = 1,         /*!< EXTI Line from 1 to 7  Interrupt         */
    EXTI8_11_IRQn = 2,        /*!< EXTI Line from 8 to 11  Interrupt        */
    EXTI12_15_IRQn = 3,       /*!< EXTI Line from 12 to 15  Interrupt       */
    RCC_IRQn = 4,             /*!< RCC shut down Interrupts             */
    BTM_IRQn = 6,             /*!< BTM  Interrupts             */
    UART0_2_4_IRQn = 7,       /*!< UART0 and UART2 Interrupts       */
    UART1_3_5_IRQn = 8,       /*!< UART1 and UART3 Interrupts       */
    TWIx_QSPIx_0_2_IRQn = 9,  /*!< TWIx_QSPIx_0_1_IRQn Interrupts  */
    TWIx_QSPIx_1_3_IRQn = 10, /*!< TWIx_SPIx_2_3 Interrupts */
    DMA0_IRQn = 11,           /*!< DMA0 Interrupts           */
    DMA1_IRQn = 12,           /*!< DMA1 Interrupts           */
    DMA2_IRQn = 13,           /*!< DMA2 Interrupts           */
    DMA3_IRQn = 14,           /*!< DMA3 Interrupts           */
    TIMER0_IRQn = 15,         /*!< TIMER0 global Interrupts         */
    TIMER1_IRQn = 16,         /*!< TIMER1 global Interrupt         */
    TIMER2_IRQn = 17,         /*!< TIMER2 global Interrupt         */
    TIMER3_IRQn = 18,         /*!< TIMER3 global Interrupt         */
    TIMER4_5_IRQn = 19,       /*!< TIMER4 and TIMER5 global Interrupt       */
    TIMER6_7_IRQn = 20,       /*!< TIMER6 global TIMER7 Interrupt       */
    PWM0_IRQn = 21,           /*!< PWM0 Interrupt           */
    LEDPWM_IRQn = 22,         /*!< LEDPWM Interrupt         */
    CAN_IRQn = 28,            /*!< CAN  Interrupt            */
    ADC_IRQn = 29,            /*!< ADC  Interrupt            */
    CMP_IRQn = 30,            /*!< CMP  Interrupt            */
    TK_IRQn = 31,             /*!< TouchKey  Interrupt             */
} IRQn_Type;

/**
 * @}
 */

#include "core_cm0plus.h" /* Cortex-M0+ processor and core peripherals */
#include <stdint.h>

/** @addtogroup Exported_types
 * @{
 */
typedef enum { RESET = 0, SET = !RESET } FlagStatus, ITStatus;

typedef enum { DISABLE = 0, ENABLE = !DISABLE } FunctionalState;

#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum { SUCCESS = 0, ERROR = !SUCCESS } ErrorStatus;

typedef enum { FLASE = 0, TURE = !FLASE } boolType;

/** @addtogroup Exported_macros
 * @{
 */
#define SET_BIT(REG, BIT) ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT) ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT) ((REG) & (BIT))

#define CLEAR_REG(REG) ((REG) = (0x0))

#define WRITE_REG(REG, VAL) ((REG) = (VAL))

#define READ_REG(REG) ((REG))

#define REG_SET(REG, BIT)                                                      \
    ((REG) &= ~(BIT));                                                         \
    ((REG) |= (BIT))

#define REG_SETn(REG, BITs, BIT)                                               \
    ((REG) &= ~(BITs));                                                        \
    ((REG) |= (BIT))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)                                    \
    WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/* Peripheral for APB0=0x40020000
         Peripheral for APB1=0x40021000
   Peripheral for APB2=0x40022000
*/
/**
 * @brief RCCAPB0 for APB0,Peripheral offset =0x00
 */
typedef struct {
    __IO uint32_t
        APB0_CFG; /*!< APB0 Config register,      Address offset: 0x00 */
    __IO uint32_t
        APB0_RST; /*!< APB0 Reset register,       Address offset: 0x04 */
} RCCAPB0_TypeDef;

/**
 * @brief RCCAPB1 for APB1,Peripheral offset =0x00
 */
typedef struct {
    __IO uint32_t
        APB1_CFG; /*!< APB1 Config register,      Address offset: 0x00 */
    __IO uint32_t
        APB1_RST; /*!< APB1 Reset register,       Address offset: 0x04 */
} RCCAPB1_TypeDef;

/**
 * @brief RCCAPB2 for APB2,Peripheral offset =0x00
 */
typedef struct {
    __IO uint32_t
        APB2_CFG; /*!< APB2 Config register,      Address offset: 0x00 */
    __IO uint32_t
        APB2_RST; /*!< APB2 Reset register,       Address offset: 0x04 */
} RCCAPB2_TypeDef;

/** @addtogroup Peripheral_registers_structures
 * @{
 */
/**
 * @brief UART0-1 for APB0,UART2 for APB1,UART3 for APB2,UART0/2/3 Peripheral
 * offset =0x20,UART1 Peripheral offset=0x80
 */
typedef struct {
    __IO uint32_t
        UART_CON; /*!< UART Config register,      	Address offset: 0x00 */
    __IO uint32_t
        UART_STS; /*!< UART Status register,       Address offset: 0x04 */
    __IO uint32_t UART_BAUD; /*!< UART BaudRate register, 		Address
                                offset: 0x08 */
    __IO uint32_t UART_DATA; /*!< UART Data register,
                                Address offset: 0x0C */
    __IO uint32_t UART_IDE;  /*!< UART Interrupt /Dma Enable register,   Address
                                offset: 0x10 */
} UART_TypeDef;

/**
 * @brief TWI_QSPI0 for APB0 ,Peripheral offset =0x40
 */
typedef struct {
    __IO uint32_t TWI_QSPIx_CON;  /*!< TWI_QSPI0 Control register,      Address
                                     offset: 0x00 */
    __IO uint32_t TWI_QSPIx_STS;  /*!< TWI_QSPI0 Status register,       Address
                                     offset: 0x04 */
    __IO uint32_t TWI_QSPIx_ADD;  /*!< TWI_QSPI0 Address register,
                                     Address offset: 0x08 */
    __IO uint32_t TWI_QSPIx_DATA; /*!< TWI_QSPI0 Data register,
                                     Address offset: 0x0C */
    __IO uint32_t TWI_QSPIx_IDE;  /*!< TWI_QSPI0 Interrupt /Dma Enable register,
                                     Address offset: 0x10 */
    __IO uint32_t TWI_QSPIx_DL;   /*!< TWI_QSPI0 Data Length register,   Address
                                     offset: 0x14 */
    __IO uint32_t
        RESERVED0; /*!< TWI_QSPI0 Resever0 register,   Address offset: 0x18 */
    __IO uint32_t TWI_QSPIx_REV; /*!< TWI_QSPI0 Resever register,
                                    Address offset: 0x1C */
} TWI_QSPIx_TypeDef;
/**
 * @brief SPI_TWI for APB0,SPI1 for APB1 ,Peripheral offset =0x40
 */
typedef struct {
    __IO uint32_t
        TWI_SPIx_CON; /*!< SPI Control register,      Address offset: 0x00 */
    __IO uint32_t
        TWI_SPIx_STS; /*!< SPI Status register,       Address offset: 0x04 */
    __IO uint32_t TWI_SPIx_ADD;  /*!< Reserved,
                                    Address offset: 0x08 */
    __IO uint32_t TWI_SPIx_DATA; /*!< SPI Data register,
                                    Address offset: 0x0C */
    __IO uint32_t TWI_SPIx_IDE; /*!< SPI Interrupt /Dma Enable register, Address
                                   offset: 0x10 */
} TWI_SPIx_TypeDef;

/**
 * @brief TIEMR0123 for APB0,TIEMR4567 for APB1, Peripheral
 * offset=0x100+0x40*n(n=0,1,2,3)
 */
typedef struct {
    __IO uint32_t TIM_CON; /*!< TCON register,      Address offset: 0x00 */
    __IO uint32_t TIM_CNT; /*!< TCNT register,       Address offset: 0x04 */
    __IO uint32_t TIM_RLD; /*!< TIMER ReLoad register, Address offset: 0x08 */
    __IO uint32_t TIM_STS; /*!< TIMER Status register,   Address offset: 0x0C */
    __IO uint32_t TIM_PDTA_RCAP; /*!< TIMER Rise Caputre Key register,   Address
                                    offset: 0x10 */
    __IO uint32_t TIM_PDTB_FCAP; /*!< TIMER fall Caputre register,   Address
                                    offset: 0x14 */
    __IO uint32_t TIM_IDE; /*!< TIMER Interrupt /Dma Enable register,  Address
                              offset: 0x18 */
} TIM_TypeDef;

/**
 * @brief PWM0 for APB0, PWM0 Peripheral offset=0x200,PWM1 Peripheral
 * offset=0x300,
 */
typedef struct {
    __IO uint32_t
        PWM0_CON; /*!< Pwm Control register,      	Address offset: 0x00 */
    __IO uint32_t
        PWM0_CHN; /*!< PWM Channel register,       	Address offset: 0x04 */
    __IO uint32_t PWM0_STS; /*!< PWM Status register,
                               Address offset: 0x08 */
    __IO uint32_t PWM0_INV; /*!< PWM Inverse register,
                               Address offset: 0x0C */
    __IO uint32_t
        PWM0_DFR; /*!< PWM Dead space register,   	Address offset: 0x10 */
    __IO uint32_t
        PWM0_FLT; /*!< PWM FaiLure detection register,   Address offset: 0x14 */
    __IO uint32_t PWM0_CYCLE;  /*!< PWM Cycles register,
                                  Address  offset: 0x18 */
    __IO uint32_t RESERVED[5]; /*!< Reserved,
                                  Address offset: 0x1C */
    __IO uint32_t PWM0_DT[8];  /*!< PWM Duty register,@PWM0 PWM_DT[8] is Valied,
                                  Address offset: 0x30 */
} PWM0_TypeDef;
/**
 * @brief PWM1 for APB2, PWM0 Peripheral offset=0x200,PWM1 Peripheral
 * offset=0x300,
 */
typedef struct {
    __IO uint32_t LEDPWM_CON;    /*!< Pwm Control register,             Address
                                    offset: 0x00 */
    __IO uint32_t LEDPWM_CHN0;   /*!< PWM Channel0 register,            Address
                                    offset: 0x04 */
    __IO uint32_t LEDPWM_STS;    /*!< PWM Status register,              Address
                                    offset: 0x08 */
    __IO uint32_t LEDPWM_INV0;   /*!< PWM Inverse0 register,            Address
                                    offset: 0x0C */
    __IO uint32_t LEDPWM_DFR;    /*!< PWM Dead space register,          Address
                                    offset: 0x10 */
    __IO uint32_t LEDPWM_FLT;    /*!< PWM FaiLure detection register,   Address
                                    offset: 0x14 */
    __IO uint32_t LEDPWM_CYCLE;  /*!< PWM Cycles register,              Address
                                    offset: 0x18 */
    __IO uint32_t LEDPWM_CHN1;   /*!< PWM Channel1 register,            Address
                                    offset: 0x1C */
    __IO uint32_t LEDPWM_INV1;   /*!< PWM Inverse1 register,            Address
                                    offset: 0x20 */
    __IO uint32_t RESERVED[3];   /*!< Reserved,                         Address
                                    offset: 0x24~0x2C */
    __IO uint32_t LEDPWM_DT[39]; /*!< PWM Duty register,@PWM0 PWM_DT[38] is
                                    Valied, 	Address offset: 0x30 */
} LEDPWM_TypeDef;
/**
 * @brief BTM for APB2,Peripheral offset=0x100
 */
typedef struct {
    __IO uint32_t
        BTM_CON; /*!< ADC Control register,      Address offset: 0x00 */
    __IO uint32_t
        BTM_STS; /*!< ADC Status register,       Address offset: 0x04 */
} BTM_TypeDef;

/**
 * @brief ADC for APB2,Peripheral offset=0x110
 */
typedef struct {
    __IO uint32_t
        ADC_CON; /*!< ADC Control register,      Address offset: 0x00 */
    __IO uint32_t
        ADC_STS; /*!< ADC Status register,       Address offset: 0x04 */
    __IO uint32_t ADC_VALUE; /*!< ADC Value register,
                                Address offset: 0x08 */
    __IO uint32_t
        ADC_CFG; /*!< ADC Config register,   		Address offset: 0x0C */
} ADC_TypeDef;

/**
 * @brief CMP for APB2,Peripheral offset=0x130
 */
typedef struct {
    __IO uint32_t
        CMP_STS; /*!< CMP Status register,       Address offset: 0x00 */
    __IO uint32_t CMP_CFG; /*!< CMP Config register,
                              Address offset: 0x04 */
} CMP_TypeDef;

/**
 * @brief PGA for APB2,Peripheral offset=0x140
 */
typedef struct {
    __IO uint32_t
        PGA_CON; /*!< CMP Control register,       Address offset: 0x00 */
} PGA_TypeDef;

/**
 * @brief TK for APB2,Peripheral offset=0x200
 */
typedef struct {
    __IO uint32_t
        TK_CHN; /*!< TK Channel register,          	Address offset: 0x00 */
    __IO uint32_t RESERVED[2]; /*!< Reserved,
                                  Address offset: 0x04 */
    __IO uint32_t TK_CON;      /*!< TK Control register,
                                  Address offset: 0x0C */
    __IO uint32_t TK_CFG;      /*!< TK Config register,
                                  Address offset: 0x10 */
    __IO uint32_t RESERVED0;   /*!< Reserved,
                                  Address offset: 0x14 */
    __IO uint32_t TK_CNT;      /*!< TK RawData register,
                                  Address offset: 0x18 */
    __IO uint32_t TK_TM;       /*!< TK TM register,
                                  Address offset: 0x1C */
} TK_TypeDef;

/**
 * @brief LCD/LED for APB2,Peripheral offset=0x280
 */
typedef struct {
    __IO uint32_t DDR_CON; /*!< Display Drive Control register,      Address
                              offset: 0x00 */
    __IO uint32_t DDR_CFG; /*!< Display Drive Config register, 	  Address
                              offset: 0x04 */
    __IO uint32_t SEG_EN0; /*!< Segment IO Enable register,
                              Address offset: 0x08 */
    __IO uint32_t SEG_EN1; /*!< Segment IO Enable register,
                              Address offset: 0x0C */
    __IO uint32_t
        COM_EN; /*!< COM IO Enable register register, 	  Address
                   offset: 0x10 */
} LCD_LED_TypeDef;

/*
         Peripheral for IOPORT=0x40011000
*/
/**
 * @brief GPIO for IOPORT,Peripheral offset=0x100*n(n=0,1,2)
 */
typedef struct {
    __IO uint32_t
        PIN; /*!< GPIOA,B,C register,               Address offset: 0x00      */
    __IO uint32_t RESERVED0[7]; /*!< Reserved,
                                   Address offset: 0x04 */
    __IO uint32_t
        PXCON; /*!< GPIO port Control register,       Address offset: 0x20 */
    __IO uint32_t RESERVED1[7]; /*!< Reserved,
                                   Address offset: 0x24 */
    __IO uint32_t
        PXPH; /*!< GPIO port pull-up/pull-down register, Address offset: 0x40 */
    __IO uint32_t RESERVED2[7]; /*!< Reserved,
                                   Address offset: 0x44 */
    __IO uint32_t PXLEV;        /*!< GPIO port Level register,
                                   Address offset: 0x60    	*/
} GPIO_TypeDef;

/**
 * @brief GPIO for IOPORT BIT,Peripheral offset=0x100*n(n=0,1,2)
 */
typedef struct {
    __IO uint8_t PIN_BIT[16]; /*!< GPIOA,B,C Bit register,               Address
                                 offset: 0x00      */
    __IO uint8_t PIN_XR[16];  /*!< GPIOA,B,C Bit register,               Address
                                 offset: 0x20      */
} GPIO_BIT_TypeDef;

/**
 * @brief EXTI for IOPORT,Peripheral offset=0x300
 */
typedef struct {
    __IO uint32_t
        INTF_IE; /*!< EXTI Fall edge Enable register,   Address offset: 0x00 */
    __IO uint32_t RESERVED0[7]; /*!< Reserved,
                                   Address offset: 0x04 */
    __IO uint32_t INTR_IE; /*!< EXTI Rise edge Enable register register, Address
                              offset: 0x20     	*/
    __IO uint32_t RESERVED1[7]; /*!< Reserved,
                                   Address offset: 0x24 */
    __IO uint32_t
        INT_SEL0; /*!< EXTI0-7 Port Select register, Address offset: 0x40    */
    __IO uint32_t RESERVED2[7]; /*!< Reserved,
                                   Address offset: 0x44 */
    __IO uint32_t
        INT_SEL1; /*!< EXTI8-15 Port Select register, Address offset: 0x60    */
    __IO uint32_t RESERVED3[7]; /*!< Reserved,
                                   Address offset: 0x64 */
    __IO uint32_t
        INTF_CON; /*!< EXTI Fall Control  register, Address offset: 0x80    */
    __IO uint32_t RESERVED4[7]; /*!< Reserved,
                                   Address offset: 0x84 */
    __IO uint32_t
        INTR_CON; /*!< EXTI Rise Control register, Address offset: 0xA0    */
    __IO uint32_t RESERVED5[7]; /*!< Reserved,
                                   Address offset: 0xA4 */
    __IO uint32_t
        INTF_STS; /*!< EXTI Fall Status  register, Address offset: 0xC0    */
    __IO uint32_t RESERVED6[7]; /*!< Reserved,
                                   Address offset: 0xC4 */
    __IO uint32_t
        INTR_STS; /*!< EXTI Rise status register, Address offset: 0xE0    */
    __IO uint32_t RESERVED7[7]; /*!< Reserved,
                                   Address offset: 0xE4 */
} EXTI_TypeDef;

/*
         Peripheral for AHB=0x40000000
*/
/**
 * @brief WDT for AHB,Peripheral offset=0x330
 */
typedef struct {
    __IO uint32_t RESERVED0[3]; /*!< Reserved,      Address offset: 0x00 */
    __IO uint32_t WDT_CON;      /*!< WDT Control register, 			Address
                                   offset: 0x0C */
    __IO uint32_t WDT_CFG;      /*!< WDT Config register, 			Address
                                   offset: 0x10 */
} WDT_TypeDef;

/**
 * @brief IAP for AHB,Peripheral offset=0x3C0
 */
typedef struct {
    __IO uint32_t
        IAPKEY;            /*!< IAP KEY register,      		Address offset: 0x00 */
    __IO uint32_t IAP_SNB; /*!< IAP Sector Number register,
                              Address offset: 0x04 */
    __IO uint32_t RESERVED0; /*!< Reserved,      Address offset: 0x08 */
    __IO uint32_t IAP_CON;   /*!< IAP Control register, 			Address
                                offset: 0x0C */
} IAP_TypeDef;

/**
 * @brief OPT for AHB,Peripheral offset=0x3F8
 */
typedef struct {
    __IO uint32_t OPINX; /*!< IAP KEY register,      		   Address
                            offset: 0x00 */
    __IO uint32_t
        OPREG; /*!< IAP Sector Number register, 	 Address offset: 0x04 */
} OPT_TypeDef;

/**
 * @brief CRC for AHB,Peripheral offset=0x2000
 */
typedef struct {
    __IO uint32_t CRC_DR; /*!< CRC Data register,       Address offset: 0x00 */
    __IO uint32_t
        CRC_CON;           /*!< CRC Config register, 	  Address offset: 0x04 */
    __IO uint32_t CRC_INT; /*!< CRC Inital register,     Address offset: 0x08 */
    __IO uint32_t CRC_POL; /*!< CRC Poly  register, 			Address
                              offset: 0x0C */
} CRC_TypeDef;

/**
 * @brief RCCAHB for AHB,Peripheral offset =0x3000
 */
typedef struct {
    __IO uint32_t
        AHB_CFG; /*!< APB2 Config register,      Address offset: 0x00 */
    __IO uint32_t
        AHB_RST; /*!< APB2 Reset register,       Address offset: 0x04 */
} RCCAHB_TypeDef;

/**
 * @brief RCC for AHB,Peripheral offset=0x3014
 */
typedef struct {
    __IO uint32_t RCC_KEY; /*!< RCC Config0 register,    Address offset: 0x00 */
    __IO uint32_t
        RESERVED0; /*!< Reserved,                Address offset: 0x04 */
    __IO uint32_t
        RCC_CFG0; /*!< RCC Config0 register,    Address offset: 0x08 */
    __IO uint32_t
        RCC_CFG1; /*!< RCC Config1 register,    Address offset: 0x0C */
    __IO uint32_t
        RESERVED1;         /*!< PLL Config register,     Address offset: 0x10 */
    __IO uint32_t RCC_STS; /*!< RCC Status  register,    Address offset: 0x14 */
    __IO uint32_t
        RESERVED2; /*!< Reserved,                Address offset: 0x18 */
    __IO uint32_t
        SYST_CALIB; /*!< RCC Calib  register,     Address offset: 0x1C */
    __IO uint32_t NMI_CFG;
} RCC_TypeDef; // V0.12

/*
         Peripheral for DMA=AHB+0x10800
*/
/**
 * @brief DMA0..DMA3 Peripheral offset=0x40*n(n=0,1,2,3)
 */
typedef struct {
    __IO uint32_t
        DMA_SADR; /*!< DMA Source Adress register,    Address offset: 0x00 */
    __IO uint32_t DMA_DADR; /*!< DMA Destination Adress register,
                               Address offset: 0x04 */
    __IO uint32_t DMA_CFG; /*!< DMA Config register,     Address offset: 0x08 */
    __IO uint32_t
        DMA_CNT; /*!< DMA Count  register, 		Address offset: 0x0C */
    __IO uint32_t
        DMA_STS; /*!< DMA Status register, 		Address offset: 0x10 */
} DMA_TypeDef;
/**
 * @brief CAN for AHB,Peripheral offset=0x10C00
 */
typedef struct {
    __IO uint32_t CAN_RX_ID;   /*!< CAN Receive Buffer ID register,    Address
                                  offset: 0x00 */
    __IO uint32_t CAN_RX_CTRL; /*!< CAN Receive Control register,    Address
                                  offset: 0x04 */
    __IO uint32_t
        CAN_RBUF0; /*!< CAN Receive Buffer0 register,    Address offset: 0x08 */
    __IO uint32_t
        CAN_RBUF1; /*!< CAN Receive Buffer1 register,    Address offset: 0x0C */
    __IO uint32_t
        CAN_RBUF2; /*!< CAN Receive Buffer2 register,    Address offset: 0x10 */
    __IO uint32_t
        CAN_RBUF3; /*!< CAN Receive Buffer3 register,    Address offset: 0x14 */
    __IO uint32_t
        CAN_RBUF4; /*!< CAN Receive Buffer4 register,    Address offset: 0x18 */
    __IO uint32_t
        CAN_RBUF5; /*!< CAN Receive Buffer5 register,    Address offset: 0x1C */
    __IO uint32_t
        CAN_RBUF6; /*!< CAN Receive Buffer6 register,    Address offset: 0x20 */
    __IO uint32_t
        CAN_RBUF7; /*!< CAN Receive Buffer7 register,    Address offset: 0x24 */
    __IO uint32_t
        CAN_RBUF8; /*!< CAN Receive Buffer8 register,    Address offset: 0x28 */
    __IO uint32_t CAN_RBUF9;  /*!< CAN Receive Buffer9 register,      Address
                                 offset: 0x2C */
    __IO uint32_t CAN_RBUF10; /*!< CAN Receive Buffer10 register,     Address
                                 offset: 0x30 */
    __IO uint32_t CAN_RBUF11; /*!< CAN Receive Buffer11 register,     Address
                                 offset: 0x34 */
    __IO uint32_t CAN_RBUF12; /*!< CAN Receive Buffer12 register,     Address
                                 offset: 0x38 */
    __IO uint32_t CAN_RBUF13; /*!< CAN Receive Buffer13 register,     Address
                                 offset: 0x3C */
    __IO uint32_t CAN_RBUF14; /*!< CAN Receive Buffer14 register,     Address
                                 offset: 0x40 */
    __IO uint32_t CAN_RBUF15; /*!< CAN Receive Buffer15 register,     Address
                                 offset: 0x44 */
    __IO uint32_t CAN_RTSL;   /*!< CAN Receive TimeStampLow register,    Address
                                 offset: 0x48 */
    __IO uint32_t CAN_RTSH; /*!< CAN Receive TimeStampHigh register,    Address
                               offset: 0x4C */
} CAN_RX_BUFFER_TypeDef;

typedef struct {
    __IO uint32_t CAN_TX_ID;   /*!< CAN Transmit Buffer ID register,  Address
                                  offset: 0x50 */
    __IO uint32_t CAN_TX_CTRL; /*!< CAN Transmit Control register,    Address
                                  offset: 0x54 */
    __IO uint32_t CAN_TBUF0;   /*!< CAN Transmit Buffer0 register,    Address
                                  offset: 0x58 */
    __IO uint32_t CAN_TBUF1;   /*!< CAN Transmit Buffer1 register,    Address
                                  offset: 0x5C */
    __IO uint32_t CAN_TBUF2;   /*!< CAN Transmit Buffer2 register,    Address
                                  offset: 0x60 */
    __IO uint32_t CAN_TBUF3;   /*!< CAN Transmit Buffer3 register,    Address
                                  offset: 0x64 */
    __IO uint32_t CAN_TBUF4;   /*!< CAN Transmit Buffer4 register,    Address
                                  offset: 0x68 */
    __IO uint32_t CAN_TBUF5;   /*!< CAN Transmit Buffer5 register,    Address
                                  offset: 0x6C */
    __IO uint32_t CAN_TBUF6;   /*!< CAN Transmit Buffer6 register,    Address
                                  offset: 0x70 */
    __IO uint32_t CAN_TBUF7;   /*!< CAN Transmit Buffer7 register,    Address
                                  offset: 0x74 */
    __IO uint32_t CAN_TBUF8;   /*!< CAN Transmit Buffer8 register,    Address
                                  offset: 0x78 */
    __IO uint32_t CAN_TBUF9;   /*!< CAN Transmit Buffer9 register,    Address
                                  offset: 0x7C */
    __IO uint32_t CAN_TBUF10;  /*!< CAN Transmit Buffer10 register,    Address
                                  offset: 0x80 */
    __IO uint32_t CAN_TBUF11;  /*!< CAN Transmit Buffer11 register,    Address
                                  offset: 0x84 */
    __IO uint32_t CAN_TBUF12;  /*!< CAN Transmit Buffer12 register,    Address
                                  offset: 0x88 */
    __IO uint32_t CAN_TBUF13;  /*!< CAN Transmit Buffer13 register,    Address
                                  offset: 0x8C */
    __IO uint32_t CAN_TBUF14;
    /*!< CAN Transmit Buffer14 register,    Address offset: 0x90 */ /*!< CAN
                                                                       Transmit
                                                                       Buffer0
                                                                       register,
                                                                       Address
                                                                       offset:
                                                                       0x08 */
    __IO uint32_t CAN_TBUF15; /*!< CAN Transmit Buffer15 register,    Address
                                 offset: 0x94 */
} CAN_TX_BUFFER_TypeDef;
typedef struct {
    __IO uint32_t CAN_TTSL; /*!< CAN Transmit TimeStampLow register, Address
                               offset: 0x98 */
    __IO uint32_t CAN_TTSH; /*!< CAN Transmit TimeStampHigh register, Address
                               offset: 0x9C */
    __IO uint32_t CAN_CFG_STAT; /*!< CAN Configure Status register, Address
                                   offset: 0xA0 */
    __IO uint32_t CAN_RTIE;     /*!< CAN Receive and Transmit Interrup register,
                                   Address offset: 0xA4 */
    __IO uint32_t CAN_S_SEG;    /*!< CAN Timing register (slow speed), Address
                                   offset: 0xA8 */
    __IO uint32_t CAN_F_SEG;    /*!< CAN Timing register (fast speed), Address
                                   offset: 0xAC */
    __IO uint32_t CAN_EALCAP;   /*!< CAN Error and Arbitration Lost Capture
                                   register,    Address offset: 0xB0 */
    __IO uint32_t CAN_ACFCTRL;  /*!< CAN Acceptance Filter Control register,
                                   Address offset: 0xB4 */
    __IO uint32_t CAN_ACF; /*!< CAN Acceptance Filter register, Address offset:
                              0xB8 */
    __IO uint32_t
        TTCAN_CFG; /*!< TTCAN Configure register, Address offset: 0xBC */
    __IO uint32_t TTCAN_RFMSG; /*!< TTCAN Reference Message register,    Address
                                  offset: 0xC0 */
    __IO uint32_t TTCAN_TRIG_CFG; /*!< TTCAN Trigge Configure register, Address
                                     offset: 0xC4 */
    __IO uint32_t TTCAN_WTRIG; /*!< TTCAN Watch Trigger Time register, Address
                                  offset: 0xC8 */
    __IO uint32_t CAN_IDE; /*!< CAN IDE register,        Address offset: 0xCC */
    __IO uint32_t CAN_TIML; /*!< CAN TimestampLow Timer register, Address
                               offset: 0xD0 */
    __IO uint32_t CAN_TIMH; /*!< CAN TimestampHigh Timer register, Address
                               offset: 0xD4 */
} CAN_TypeDef;

///*
//	 IFB[200H]~IFB[3FFH] for CustomerOption
//*/
///**
//* @brief must to OPINX and OPREG operate，and  AHB_CFG.2(FIBEN)=1,Protect
// Adress=Adress[8:0]*512
//  */
// typedef struct
//{
//	__IO uint8_t Option0;
///*!< OPINX=0xC1>*/
//	__IO uint8_t Option1;
///*!< OPINX=0xC2>*/
//	__IO uint8_t IapPortectA_SAH;     		  	/*!<
// OPINX=0xC3>*/
//	__IO uint8_t IapPortectA_SAL;     		  	/*!<
// OPINX=0xC4>*/
//	__IO uint8_t IapPortectA_EAH;          		/*!< OPINX=0xC5>*/
//	__IO uint8_t IapPortectA_EAL;     		  	/*!<
// OPINX=0xC6>*/
//	__IO uint8_t IapPortectB_SAH;          		/*!< OPINX=0xC7>*/
//	__IO uint8_t IapPortectB_SAL;          		/*!< OPINX=0xC8>*/
//	__IO uint8_t IapPortectB_EAH;          		/*!< OPINX=0xC9>*/
//	__IO uint8_t IapPortectB_EAL;          		/*!< OPINX=0xCA>*/
//} CustomerOption_TypeDef;

/*
         IFB[400H]~IFB[5FFH] for DesignOption
*/
/**
 * @brief must to OPINX and OPREG operate，and
 * AHB_CFG.2(FIBEN)=1&&PASSWORD=Decode
 */
typedef struct {
    __IO uint8_t Bg;      /*!< OPINX=0x81>*/
    __IO uint8_t Vref;    /*!< OPINX=0x82>*/
    __IO uint8_t Hrcr;    /*!< OPINX=0x83>*/
    __IO uint8_t Lrc;     /*!< OPINX=0x84>*/
    __IO uint8_t Hrcc;    /*!< OPINX=0x85>*/
    __IO uint8_t RomSize; /*!< OPINX=0x86>*/
    __IO uint8_t Tk;      /*!< OPINX=0x87>*/
    __IO uint8_t Ldo;     /*!< OPINX=0x88>*/
    __IO uint8_t Adcmp;   /*!< OPINX=0x89>*/
    __IO uint8_t Rcc;     /*!< OPINX=0x8A>*/
} DesignOption_TypeDef;

/** @addtogroup Peripheral_memory_map
 * @{
 */
#define FLASH_BASE (0x08000000UL)  /*!< FLASH base address */
#define EEPROM_BASE (0X08E00000UL) /*!< EEPROM base address*/
#define SRAM_BASE (0x20000000UL)   /*!< SRAM base address */
#define PERIPH_BASE (0x40000000UL) /*!< Peripheral base address */
#define IOPORT_BASE (0x40011000UL) /*!< IOPORT base address */
#define ERAM_BASE (0x50000000UL)   /*!< Extern Ram base address */
#define SRAM_SIZE_MAX                                                          \
    (0x00006000UL)                    /*!< maximum SRAM size (up to 32 KBytes) \
                                       */
#define PWMDUTY_OFFSET (0x00000040UL) /*!< PwmDuty offset */
#define LXDRAM_OFFSET (0x00000040UL)
// Prviate Peripheral_memory_map
#define IFB_BASE (0x08C00000UL) /*!<Ifb>*/
#define PASSWORD_BASE (IFB_BASE + 0x00000)
#define CODEOPTION_BASE (IFB_BASE + 0x00200)
#define DESIGNOPTION_BASE (IFB_BASE + 0x00400)
#define LDROM_BASE (IFB_BASE + 0x00600)
//===============================================
#define SECTOR_SIZE 512
#define FLASH_SIZE (SECTOR_SIZE * 1024)
#define LDROM_SIZE (SECTOR_SIZE * 4)

/*!< Peripheral memory map */
#define AHBPERIPH_BASE (PERIPH_BASE)
#define APB0PERIPH_BASE (PERIPH_BASE + 0x20000)
#define APB1PERIPH_BASE (PERIPH_BASE + 0x21000)
#define APB2PERIPH_BASE (PERIPH_BASE + 0x22000)
#define DMAPERIPH_BASE (PERIPH_BASE + 0x10800)
#define IOPORTPERIPH_BASE (PERIPH_BASE + 0x11000)

// #define PWMDUTY_BASE (ERAM_BASE+PWMDUTY_OFFSET) #define LXDRAM_BASE
// (ERAM_BASE+LXDRAM_OFFSET)
/*!< AHB peripherals */
#define WDT_BASE (AHBPERIPH_BASE + (0x00000330UL))
#define IAP_BASE (AHBPERIPH_BASE + (0x000003C0UL))
#define OPT_BASE (AHBPERIPH_BASE + (0x000003F8UL))
#define CRC_BASE (AHBPERIPH_BASE + (0x00002000UL))
#define RCCAHB_BASE (AHBPERIPH_BASE + (0x00003000UL))
#define RCC_BASE (AHBPERIPH_BASE + (0x0000300CUL))
#define CAN_BASE (AHBPERIPH_BASE + (0x00010C00UL))
/*!< APB0 peripherals */
#define RCCAPB0_BASE (APB0PERIPH_BASE + (0x00000000UL))
#define UART0_BASE (APB0PERIPH_BASE + (0x00000020UL))
#define UART1_BASE (APB0PERIPH_BASE + (0x00000080UL))
#define TWI0_QSPI0_BASE (APB0PERIPH_BASE + (0x00000040UL))
#define TWI2_SPI2_BASE (APB0PERIPH_BASE + (0x00000060UL))
#define UART5_BASE (APB0PERIPH_BASE + (0x000000A0UL))
#define TIM0_BASE (APB0PERIPH_BASE + (0x00000100UL))
#define TIM1_BASE (APB0PERIPH_BASE + (0x00000140UL))
#define TIM2_BASE (APB0PERIPH_BASE + (0x00000180UL))
#define TIM3_BASE (APB0PERIPH_BASE + (0x000001C0UL))
#define PWM0_BASE (APB0PERIPH_BASE + (0x00000200UL))
/*!< APB1 peripherals */
#define RCCAPB1_BASE (APB1PERIPH_BASE + (0x00000000UL))
#define UART2_BASE (APB1PERIPH_BASE + (0x00000020UL))
#define TWI1_QSPI1_BASE (APB1PERIPH_BASE + (0x00000040UL))
#define TWI3_SPI3_BASE (APB1PERIPH_BASE + (0x00000060UL))
#define UART4_BASE (APB1PERIPH_BASE + (0x00000080UL))
#define TIM4_BASE (APB1PERIPH_BASE + (0x00000100UL))
#define TIM5_BASE (APB1PERIPH_BASE + (0x00000140UL))
#define TIM6_BASE (APB1PERIPH_BASE + (0x00000180UL))
#define TIM7_BASE (APB1PERIPH_BASE + (0x000001C0UL))
/*!< APB2 peripherals */
#define RCCAPB2_BASE (APB2PERIPH_BASE + (0x00000000UL))
#define UART3_BASE (APB2PERIPH_BASE + (0x00000020UL))
#define LEDPWM_BASE (APB2PERIPH_BASE + (0x00000300UL))
#define BTM_BASE (APB2PERIPH_BASE + (0x00000100UL))
#define ADC_BASE (APB2PERIPH_BASE + (0x00000110UL))
#define CMP_BASE (APB2PERIPH_BASE + (0x00000130UL))
#define PGA_BASE (APB2PERIPH_BASE + (0x00000140UL))
#define TK_BASE (APB2PERIPH_BASE + (0x00000200UL))
#define LCD_LED_BASE (APB2PERIPH_BASE + (0x00000280UL))
/*!< DMA */
#define DMA0_BASE (DMAPERIPH_BASE + (0x00000000UL))
#define DMA1_BASE (DMAPERIPH_BASE + (0x00000040UL))
#define DMA2_BASE (DMAPERIPH_BASE + (0x00000080UL))
#define DMA3_BASE (DMAPERIPH_BASE + (0x000000C0UL))
/*!< IOPORT */
#define GPIOA_BASE (IOPORTPERIPH_BASE + (0x00000000UL))
#define GPIOB_BASE (IOPORTPERIPH_BASE + (0x00000100UL))
#define GPIOC_BASE (IOPORTPERIPH_BASE + (0x00000200UL))
#define GPIOD_BASE (IOPORTPERIPH_BASE + (0x00000300UL))
#define EXTI_BASE (IOPORTPERIPH_BASE + (0x00000800UL))
/*!< IOPORT-Bit */
#define GPIOA_BIT_BASE (GPIOA_BASE + (0x00000000UL))
#define GPIOB_BIT_BASE (GPIOB_BASE + (0x00000000UL))
#define GPIOC_BIT_BASE (GPIOC_BASE + (0x00000000UL))
#define GPIOD_BIT_BASE (GPIOD_BASE + (0x00000000UL))
/*!< IOPORT-OverTurn */
#define GPIOA_OT_BASE (GPIOA_BASE + (0x00000010UL))
#define GPIOB_OT_BASE (GPIOB_BASE + (0x00000010UL))
#define GPIOC_OT_BASE (GPIOC_BASE + (0x00000010UL))
#define GPIOD_OT_BASE (GPIOD_BASE + (0x00000010UL))
/*<PA.SetBit:n=0...15>*/
#define PA_BIT(n) (*((uint8_t *)((GPIOA_BIT_BASE + (n)))))
#define PB_BIT(n) (*((uint8_t *)((GPIOB_BIT_BASE + (n)))))
#define PC_BIT(n) (*((uint8_t *)((GPIOC_BIT_BASE + (n)))))
#define PD_BIT(n) (*((uint8_t *)((GPIOD_BIT_BASE + (n)))))
/*<PA.OverTurn:n=0...15>*/
#define PA_OT(n) (*((uint8_t *)((GPIOA_OT_BASE + (n))))) = 1
#define PB_OT(n) (*((uint8_t *)((GPIOB_OT_BASE + (n))))) = 1
#define PC_OT(n) (*((uint8_t *)((GPIOC_OT_BASE + (n))))) = 1
#define PD_OT(n) (*((uint8_t *)((GPIOD_OT_BASE + (n))))) = 1

/*!< CAN */
#define CAN_RX_BUFFER_BASE (CAN_BASE + 0x00000000UL)
#define CAN_TX_BUFFER_BASE (CAN_BASE + 0x00000050UL)
#define CAN_FD_T_BASE (CAN_BASE + 0X00000098UL)

/*!< Device Electronic Signature */
// #define PACKAGE_BASE          (0xXXXXXXXUL)        /*!< Package data register
// base address     */ #define UID_BASE              (0xXXXXXXXUL)        /*!<
// Unique device ID register base address */ #define FLASHSIZE_BASE
// (0xXXXXXXXUL)        /*!< Flash size data register base address  */

/** @addtogroup Peripheral_declaration
 * @{
 */
#define RCC ((RCC_TypeDef *)RCC_BASE)
#define RCCAHB ((RCCAHB_TypeDef *)RCCAHB_BASE)
#define RCCAPB0 ((RCCAPB0_TypeDef *)RCCAPB0_BASE)
#define RCCAPB1 ((RCCAPB1_TypeDef *)RCCAPB1_BASE)
#define RCCAPB2 ((RCCAPB2_TypeDef *)RCCAPB2_BASE)
#define UART0 ((UART_TypeDef *)UART0_BASE)
#define UART1 ((UART_TypeDef *)UART1_BASE)
#define UART2 ((UART_TypeDef *)UART2_BASE)
#define UART3 ((UART_TypeDef *)UART3_BASE)
#define UART4 ((UART_TypeDef *)UART4_BASE)
#define UART5 ((UART_TypeDef *)UART5_BASE)
#define TWI0_QSPI0 ((TWI_QSPIx_TypeDef *)TWI0_QSPI0_BASE)
#define TWI1_QSPI1 ((TWI_QSPIx_TypeDef *)TWI1_QSPI1_BASE)
#define TWI2_SPI2 ((TWI_SPIx_TypeDef *)TWI2_SPI2_BASE)
#define TWI3_SPI3 ((TWI_SPIx_TypeDef *)TWI3_SPI3_BASE)
#define TIM0 ((TIM_TypeDef *)TIM0_BASE)
#define TIM1 ((TIM_TypeDef *)TIM1_BASE)
#define TIM2 ((TIM_TypeDef *)TIM2_BASE)
#define TIM3 ((TIM_TypeDef *)TIM3_BASE)
#define TIM4 ((TIM_TypeDef *)TIM4_BASE)
#define TIM5 ((TIM_TypeDef *)TIM5_BASE)
#define TIM6 ((TIM_TypeDef *)TIM6_BASE)
#define TIM7 ((TIM_TypeDef *)TIM7_BASE)
#define PWM0 ((PWM0_TypeDef *)PWM0_BASE)
#define LEDPWM ((LEDPWM_TypeDef *)LEDPWM_BASE)
#define BTM ((BTM_TypeDef *)BTM_BASE)
#define ADC ((ADC_TypeDef *)ADC_BASE)
#define CMP ((CMP_TypeDef *)CMP_BASE)
#define PGA ((PGA_TypeDef *)PGA_BASE)
#define TK ((TK_TypeDef *)TK_BASE)
#define LCD_LED ((LCD_LED_TypeDef *)LCD_LED_BASE)
#define EXTI ((EXTI_TypeDef *)EXTI_BASE)
#define WDT ((WDT_TypeDef *)WDT_BASE)
#define IAP ((IAP_TypeDef *)IAP_BASE)
#define CRC ((CRC_TypeDef *)CRC_BASE)
#define CAN ((CAN_TypeDef *)CAN_FD_T_BASE)
#define CAN_RUF ((CAN_RX_BUFFER_TypeDef *)CAN_RX_BUFFER_BASE)
#define CAN_TUF ((CAN_TX_BUFFER_TypeDef *)CAN_TX_BUFFER_BASE)
#define DMA0 ((DMA_TypeDef *)DMA0_BASE)
#define DMA1 ((DMA_TypeDef *)DMA1_BASE)
#define DMA2 ((DMA_TypeDef *)DMA2_BASE)
#define DMA3 ((DMA_TypeDef *)DMA3_BASE)
#define GPIOA ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOA_BIT ((GPIO_BIT_TypeDef *)GPIOA_BIT_BASE)
#define GPIOB_BIT ((GPIO_BIT_TypeDef *)GPIOB_BIT_BASE)
#define GPIOC_BIT ((GPIO_BIT_TypeDef *)GPIOC_BIT_BASE)
#define GPIOD_BIT ((GPIO_BIT_TypeDef *)GPIOD_BIT_BASE)
//----------------------------------------------------------
#define OPT ((OPT_TypeDef *)OPT_BASE)
//----------------------------------------------------------
/** @addtogroup Peripheral_Registers_Bits_Definition
 * @{
 */

/******************************************************************************/
/*                         Peripheral Registers Bits Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                      RCC                    */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RCC_CFG0 register
 * ********************/
#define RCC_CFG0_LXTEN_Pos (0U)
#define RCC_CFG0_LXTEN_Msk (0x1UL << RCC_CFG0_LXTEN_Pos)
#define RCC_CFG0_LXTEN RCC_CFG0_LXTEN_Msk

#define RCC_CFG0_LIRCEN_Pos (1U)
#define RCC_CFG0_LIRCEN_Msk (0x1UL << RCC_CFG0_LIRCEN_Pos)
#define RCC_CFG0_LIRCEN RCC_CFG0_LIRCEN_Msk

#define RCC_CFG0_CRYHF_Pos (4U)
#define RCC_CFG0_CRYHF_Msk (0x1UL << RCC_CFG0_CRYHF_Pos)
#define RCC_CFG0_CRYHF RCC_CFG0_CRYHF_Msk

#define RCC_CFG0_HXTEN_Pos (5U)
#define RCC_CFG0_HXTEN_Msk (0x1UL << RCC_CFG0_HXTEN_Pos)
#define RCC_CFG0_HXTEN RCC_CFG0_HXTEN_Msk

#define RCC_CFG0_HIRCEN_Pos (6U)
#define RCC_CFG0_HIRCEN_Msk (0x1UL << RCC_CFG0_HIRCEN_Pos)
#define RCC_CFG0_HIRCEN RCC_CFG0_HIRCEN_Msk

#define RCC_CFG0_SYSCLKSW_Pos (7U)
#define RCC_CFG0_SYSCLKSW_Msk (0x1UL << RCC_CFG0_SYSCLKSW_Pos)
#define RCC_CFG0_SYSCLKSW RCC_CFG0_SYSCLKSW_Msk

#define RCC_CFG0_SYSCLKSEL_Pos (8U)
#define RCC_CFG0_SYSCLKSEL_Msk (0x3UL << RCC_CFG0_SYSCLKSEL_Pos)
#define RCC_CFG0_SYSCLKSEL RCC_CFG0_SYSCLKSEL_Msk

#define RCC_CFG0_HPLDODP_Pos (11U)
#define RCC_CFG0_HPLDOD_Msk (0x1UL << RCC_CFG0_HPLDODP_Pos)
#define RCC_CFG0_HPLDOD RCC_CFG0_HPLDOD_Msk

#define RCC_CFG0_WAIT_Pos (12U)
#define RCC_CFG0_WAIT_Msk (0x3UL << RCC_CFG0_WAIT_Pos)
#define RCC_CFG0_WAIT RCC_CFG0_WAIT_Msk

#define RCC_CFG0_HIRC72EN_Pos (14U)
#define RCC_CFG0_HIRC72EN_Msk (0x1UL << RCC_CFG0_HIRC72EN_Pos)
#define RCC_CFG0_HIRC72EN RCC_CFG0_HIRC72EN_Msk

#define RCC_CFG0_INTEN_Pos (15U)
#define RCC_CFG0_INTEN_Msk (0x1UL << RCC_CFG0_INTEN_Pos)
#define RCC_CFG0_INTEN RCC_CFG0_INTEN_Msk

/********************  Bit definition for RCC_CFG1 register
 * ********************/
#define RCC_CFG1_BTMCLKSEL_Pos (0U)
#define RCC_CFG1_BTMCLKSEL_Msk (0x1UL << RCC_CFG1_BTMCLKSEL_Pos)
#define RCC_CFG1_BTMCLKSEL RCC_CFG1_BTMCLKSEL_Msk

#define RCC_CFG1_LCDCLKSEL_Pos (1U)
#define RCC_CFG1_LCDCLKSEL_Msk (0x1UL << RCC_CFG1_LCDCLKSEL_Pos)
#define RCC_CFG1_LCDCLKSEL RCC_CFG1_LCDCLKSEL_Msk

#define RCC_CFG1_PWM0CLKSEL_Pos (2U)
#define RCC_CFG1_PWM0CLKSEL_Msk (0x1UL << RCC_CFG1_PWM0CLKSEL_Pos)
#define RCC_CFG1_PWM0CLKSEL RCC_CFG1_PWM0CLKSEL_Msk

#define RCC_CFG1_STCLKSEL_Pos (5U)
#define RCC_CFG1_STCLKSEL_Msk (0x3UL << RCC_CFG1_STCLKSEL_Pos)
#define RCC_CFG1_STCLKSEL RCC_CFG1_STCLKSEL_Msk

/********************  Bit definition for RCC_STS register ********************/
#define RCC_STS_CLKFIF_Pos (0U)
#define RCC_STS_CLKFIF_Msk (0x1UL << RCC_STS_CLKFIF_Pos)
#define RCC_STS_CLKFIF RCC_STS_CLKFIF_Msk

#define RCC_STS_SRAMPEIF_Pos (3U)
#define RCC_STS_SRAMPEIF_Msk (0x1UL << RCC_STS_SRAMPEIF_Pos)
#define RCC_STS_SRAMPEIF RCC_STS_SRAMPEIF_Msk

/********************  Bit definition for NMI_CFG register ********************/
#define NMI_CFG_CSSEN_Pos (0U)
#define NMI_CFG_CSSEN_Msk (0x1UL << NMI_CFG_CSSEN_Pos)
#define NMI_CFG_CSSEN NMI_CFG_CSSEN_Msk

#define NMI_CFG_CMPEN_Pos (1U)
#define NMI_CFG_CMPEN_Msk (0x1UL << NMI_CFG_CMPEN_Pos)
#define NMI_CFG_CMPEN NMI_CFG_CMPEN_Msk

#define NMI_CFG_INT0EN_Pos (2U)
#define NMI_CFG_INT0EN_Msk (0x1UL << NMI_CFG_INT0EN_Pos)
#define NMI_CFG_INT0EN NMI_CFG_INT0EN_Msk

#define NMI_CFG_SRAMPEEN_Pos (3U)
#define NMI_CFG_SRAMPEEN_Msk (0x1UL << NMI_CFG_SRAMPEEN_Pos)
#define NMI_CFG_SRAMPEEN NMI_CFG_SRAMPEEN_Msk

/********************  Bit definition for AHB_CFG register ********************/
#define AHB_CFG_DMAEN_Pos (0U)
#define AHB_CFG_DMAEN_Msk (0x1UL << AHB_CFG_DMAEN_Pos)
#define AHB_CFG_DMAEN AHB_CFG_DMAEN_Msk

#define AHB_CFG_CRCEN_Pos (1U)
#define AHB_CFG_CRCEN_Msk (0x1UL << AHB_CFG_CRCEN_Pos)
#define AHB_CFG_CRCEN AHB_CFG_CRCEN_Msk

#define AHB_CFG_IFBEN_Pos (2U)
#define AHB_CFG_IFBEN_Msk (0x1UL << AHB_CFG_IFBEN_Pos)
#define AHB_CFG_IFBEN AHB_CFG_IFBEN_Msk

#define AHB_CFG_CANEN_Pos (4U)
#define AHB_CFG_CANEN_Msk (0x1UL << AHB_CFG_CANEN_Pos)
#define AHB_CFG_CANEN AHB_CFG_CANEN_Msk

#define AHB_CFG_CLKDIV_Pos (20U)
#define AHB_CFG_CLKDIV_Msk (0x7UL << AHB_CFG_CLKDIV_Pos)
#define AHB_CFG_CLKDIV AHB_CFG_CLKDIV_Msk

/********************  Bit definition for AHB_RST register ********************/
#define AHB_RST_DMARST_Pos (0U)
#define AHB_RST_DMARST_Msk (0x1UL << AHB_RST_DMARST_Pos)
#define AHB_RST_DMARST AHB_RST_DMARST_Msk

#define AHB_RST_CRCRST_Pos (1U)
#define AHB_RST_CRCRST_Msk (0x1UL << AHB_RST_CRCRST_Pos)
#define AHB_RST_CRCRST AHB_RST_CRCRST_Msk

/********************  Bit definition for APB0_CFG register
 * ********************/
#define APB0_CFG_TIM0EN_Pos (0U)
#define APB0_CFG_TIM0EN_Msk (0x1UL << APB0_CFG_TIM0EN_Pos)
#define APB0_CFG_TIM0EN APB0_CFG_TIM0EN_Msk

#define APB0_CFG_TIM1EN_Pos (1U)
#define APB0_CFG_TIM1EN_Msk (0x1UL << APB0_CFG_TIM1EN_Pos)
#define APB0_CFG_TIM1EN APB0_CFG_TIM1EN_Msk

#define APB0_CFG_TIM2EN_Pos (2U)
#define APB0_CFG_TIM2EN_Msk (0x1UL << APB0_CFG_TIM2EN_Pos)
#define APB0_CFG_TIM2EN APB0_CFG_TIM2EN_Msk

#define APB0_CFG_TIM3EN_Pos (3U)
#define APB0_CFG_TIM3EN_Msk (0x1UL << APB0_CFG_TIM3EN_Pos)
#define APB0_CFG_TIM3EN APB0_CFG_TIM3EN_Msk

#define APB0_CFG_TWI0EN_Pos (4U)
#define APB0_CFG_TWI0EN_Msk (0x1UL << APB0_CFG_TWI0EN_Pos)
#define APB0_CFG_TWI0EN APB0_CFG_TWI0EN_Msk

#define APB0_CFG_SPI0EN_Pos (5U)
#define APB0_CFG_SPI0EN_Msk (0x1UL << APB0_CFG_SPI0EN_Pos)
#define APB0_CFG_SPI0EN APB0_CFG_SPI0EN_Msk

#define APB0_CFG_UART0EN_Pos (6U)
#define APB0_CFG_UART0EN_Msk (0x1UL << APB0_CFG_UART0EN_Pos)
#define APB0_CFG_UART0EN APB0_CFG_UART0EN_Msk

#define APB0_CFG_UART1EN_Pos (7U)
#define APB0_CFG_UART1EN_Msk (0x1UL << APB0_CFG_UART1EN_Pos)
#define APB0_CFG_UART1EN APB0_CFG_UART1EN_Msk

#define APB0_CFG_PWM0EN_Pos (8U)
#define APB0_CFG_PWM0EN_Msk (0x1UL << APB0_CFG_PWM0EN_Pos)
#define APB0_CFG_PWM0EN APB0_CFG_PWM0EN_Msk

#define APB0_CFG_UART5EN_Pos (9U)
#define APB0_CFG_UART5EN_Msk (0x1UL << APB0_CFG_UART5EN_Pos)
#define APB0_CFG_UART5EN APB0_CFG_UART5EN_Msk

#define APB0_CFG_CLKDIV_Pos (20U)
#define APB0_CFG_CLKDIV_Msk (0x7UL << APB0_CFG_CLKDIV_Pos)
#define APB0_CFG_CLKDIV APB0_CFG_CLKDIV_Msk

#define APB0_CFG_ENAPB_Pos (23U)
#define APB0_CFG_ENAPB_Msk (0x1UL << APB0_CFG_ENAPB_Pos)
#define APB0_CFG_ENAPB APB0_CFG_ENAPB_Msk

/********************  Bit definition for APB0_RST register
 * ********************/
#define APB0_RST_TIM0RST_Pos (0U)
#define APB0_RST_TIM0RST_Msk (0x1UL << APB0_RST_TIM0RST_Pos)
#define APB0_RST_TIM0RST APB0_RST_TIM0RST_Msk

#define APB0_RST_TIM1RST_Pos (1U)
#define APB0_RST_TIM1RST_Msk (0x1UL << APB0_RST_TIM1RST_Pos)
#define APB0_RST_TIM1RST APB0_RST_TIM1RST_Msk

#define APB0_RST_TIM2RST_Pos (2U)
#define APB0_RST_TIM2RST_Msk (0x1UL << APB0_RST_TIM2RST_Pos)
#define APB0_RST_TIM2RST APB0_RST_TIM2RST_Msk

#define APB0_RST_TIM3RST_Pos (3U)
#define APB0_RST_TIM3RST_Msk (0x1UL << APB0_RST_TIM3RST_Pos)
#define APB0_RST_TIM3RST APB0_RST_TIM3RST_Msk

#define APB0_RST_TWI0RST_Pos (4U)
#define APB0_RST_TWI0RST_Msk (0x1UL << APB0_RST_TWI0RST_Pos)
#define APB0_RST_TWI0RST APB0_RST_TWI0RST_Msk

#define APB0_RST_SPI0RST_Pos (5U)
#define APB0_RST_SPI0RST_Msk (0x1UL << APB0_RST_SPI0RST_Pos)
#define APB0_RST_SPI0RST APB0_RST_SPI0RST_Msk

#define APB0_RST_UART0RST_Pos (6U)
#define APB0_RST_UART0RST_Msk (0x1UL << APB0_RST_UART0RST_Pos)
#define APB0_RST_UART0RST APB0_RST_UART0RST_Msk

#define APB0_RST_UART1RST_Pos (7U)
#define APB0_RST_UART1RST_Msk (0x1UL << APB0_RST_UART1RST_Pos)
#define APB0_RST_UART1RST APB0_RST_UART1RST_Msk

#define APB0_RST_PWM0RST_Pos (8U)
#define APB0_RST_PWM0RST_Msk (0x1UL << APB0_RST_PWM0RST_Pos)
#define APB0_RST_PWM0RST APB0_RST_PWM0RST_Msk

#define APB0_RST_UART5RST_Pos (9U)
#define APB0_RST_UART5RST_Msk (0x1UL << APB0_RST_UART5RST_Pos)
#define APB0_RST_UART5RST APB0_RST_UART5RST_Msk

/********************  Bit definition for APB1_CFG register
 * ********************/
#define APB1_CFG_TIM4EN_Pos (0U)
#define APB1_CFG_TIM4EN_Msk (0x1UL << APB1_CFG_TIM4EN_Pos)
#define APB1_CFG_TIM4EN APB1_CFG_TIM4EN_Msk

#define APB1_CFG_TIM5EN_Pos (1U)
#define APB1_CFG_TIM5EN_Msk (0x1UL << APB1_CFG_TIM5EN_Pos)
#define APB1_CFG_TIM5EN APB1_CFG_TIM5EN_Msk

#define APB1_CFG_TIM6EN_Pos (2)
#define APB1_CFG_TIM6EN_Msk (0x1UL << APB1_CFG_TIM6EN_Pos)
#define APB1_CFG_TIM6EN APB1_CFG_TIM6EN_Msk

#define APB1_CFG_TIM7EN_Pos (3U)
#define APB1_CFG_TIM7EN_Msk (0x1UL << APB1_CFG_TIM7EN_Pos)
#define APB1_CFG_TIM7EN APB1_CFG_TIM7EN_Msk

#define APB1_CFG_TWI1EN_Pos (4U)
#define APB1_CFG_TWI1EN_Msk (0x1UL << APB1_CFG_TWI1EN_Pos)
#define APB1_CFG_TWI1EN APB1_CFG_TWI1EN_Msk

#define APB1_CFG_UART4EN_Pos (6U)
#define APB1_CFG_UART4EN_Msk (0x1UL << APB1_CFG_UART4EN_Pos)
#define APB1_CFG_UART4EN APB1_CFG_UART4EN_Msk

#define APB1_CFG_UART2EN_Pos (7U)
#define APB1_CFG_UART2EN_Msk (0x1UL << APB1_CFG_TUART2EN_Pos)
#define APB1_CFG_UART2EN APB1_CFG_UART2EN_Msk

#define APB1_CFG_CLKDIV_Pos (20U)
#define APB1_CFG_CLKDIV_Msk (0x7UL << APB1_CFG_CLKDIV_Pos)
#define APB1_CFG_CLKDIV APB1_CFG_CLKDIV_Msk

#define APB1_CFG_ENAPB_Pos (23U)
#define APB1_CFG_ENAPB_Msk (0x1UL << APB1_CFG_ENAPB_Pos)
#define APB1_CFG_ENAPB APB1_CFG_ENAPB_Msk

/********************  Bit definition for APB1_RST register
 * ********************/
#define APB1_RST_TIM4RST_Pos (0U)
#define APB1_RST_TIM4RST_Msk (0x1UL << APB1_RST_TIM4RST_Pos)
#define APB1_RST_TIM4RST APB1_RST_TIM4RST_Msk

#define APB1_RST_TIM5RST_Pos (1U)
#define APB1_RST_TIM5RST_Msk (0x1UL << APB1_RST_TIM5RST_Pos)
#define APB1_RST_TIM5RST APB1_RST_TIM5RST_Msk

#define APB1_RST_TIM6RST_Pos (2)
#define APB1_RST_TIM6RST_Msk (0x1UL << APB1_RST_TIM6RST_Pos)
#define APB1_RST_TIM6RST APB1_RST_TIM6RST_Msk

#define APB1_RST_TIM7RST_Pos (3U)
#define APB1_RST_TIM7RST_Msk (0x1UL << APB1_RST_TIM7RST_Pos)
#define APB1_RST_TIM7RST APB1_RST_TIM7RST_Msk

#define APB1_RST_TWI1RST_Pos (4U)
#define APB1_RST_TWI1RST_Msk (0x1UL << APB1_RST_TWI1RST_Pos)
#define APB1_RST_TWI1RST APB1_RST_TWI1RST_Msk

#define APB1_RST_UART4RST_Pos (6U)
#define APB1_RST_UART4RST_Msk (0x1UL << APB1_RST_UART4RST_Pos)
#define APB1_RST_UART4RST APB1_RST_UART4RST_Msk

#define APB1_RST_UART2RST_Pos (7U)
#define APB1_RST_UART2RST_Msk (0x1UL << APB1_RST_UART2RST_Pos)
#define APB1_RST_UART2EN APB1_RST_UART2RST_Msk

/********************  Bit definition for APB2_CFG register
 * ********************/
#define APB2_CFG_LEDPWMEN_Pos (0U)
#define APB2_CFG_LEDPWMEN_Msk (0x1UL << APB2_CFG_LEDPWMEN_Pos)
#define APB2_CFG_LEDPWMEN APB2_CFG_LEDPWMEN_Msk

#define APB2_CFG_LCDEN_Pos (1U)
#define APB2_CFG_LCDEN_Msk (0x1UL << APB2_CFG_LCDEN_Pos)
#define APB2_CFG_LCDEN APB2_CFG_LCDEN_Msk

#define APB2_CFG_UART3EN_Pos (2U)
#define APB2_CFG_UART3EN_Msk (0x1UL << APB2_CFG_UART3EN_Pos)
#define APB2_CFG_UART3EN APB2_CFG_UART3EN_Msk

#define APB2_CFG_CLKDIV_Pos (20U)
#define APB2_CFG_CLKDIV_Msk (0x7UL << APB2_CFG_CLKDIV_Pos)
#define APB2_CFG_CLKDIV APB2_CFG_CLKDIV_Msk

#define APB2_CFG_ENAPB_Pos (23U)
#define APB2_CFG_ENAPB_Msk (0x1UL << APB2_CFG_ENAPB_Pos)
#define APB2_CFG_ENAPB APB2_CFG_ENAPB_Msk

/********************  Bit definition for APB2_RST register
 * ********************/
#define APB2_RST_LEDPWMRST_Pos (0U)
#define APB2_RST_LEDPWMRST_Msk (0x1UL << APB2_RST_LEDPWMRST_Pos)
#define APB2_RST_LEDPWMRST APB2_RST_LEDPWMRST_Msk

#define APB2_RST_LCDRST_Pos (1U)
#define APB2_RST_LCDRST_Msk (0x1UL << APB2_RST_LCDRST_Pos)
#define APB2_RST_LCDRST APB2_RST_LCDRST_Msk

#define APB2_RST_UART3RST_Pos (2U)
#define APB2_RST_UART3RST_Msk (0x1UL << APB2_RST_UART3RST_Pos)
#define APB2_RST_UART3RST APB2_RST_UART3RST_Msk

/************private bit *************************************/
#define APB0_CFG_RDMODE_Pos (31U)
#define APB0_CFG_RDMODE_Msk (0x1UL << APB0_CFG_RDMODE_Pos)
#define APB0_CFG_RDMODE APB0_CFG_RDMODE_Msk

#define APB1_CFG_RDMODE_Pos (31U)
#define APB1_CFG_RDMODE_Msk (0x1UL << APB1_CFG_RDMODE_Pos)
#define APB1_CFG_RDMODE APB1_CFG_RDMODE_Msk

#define APB2_CFG_RDMODE_Pos (31U)
#define APB2_CFG_RDMODE_Msk (0x1UL << APB2_CFG_RDMODE_Pos)
#define APB2_CFG_RDMODE APB2_CFG_RDMODE_Msk

/******************************************************************************/
/*                                                                            */
/*                      ADC                    */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for ADC_CON register ********************/
#define ADC_CON_ADCIS_Pos (0U)
#define ADC_CON_ADCIS_Msk (0x0FUL << ADC_CON_ADCIS_Pos)
#define ADC_CON_ADCIS ADC_CON_ADCIS_Msk

#define ADC_CON_ADCS_Pos (7U)
#define ADC_CON_ADCS_Msk (0x1UL << ADC_CON_ADCS_Pos)
#define ADC_CON_ADCS ADC_CON_ADCS_Msk

#define ADC_CON_INTEN_Pos (8U)
#define ADC_CON_INTEN_Msk (0x1UL << ADC_CON_INTEN_Pos)
#define ADC_CON_INTEN ADC_CON_INTEN_Msk

#define ADC_CON_CONT_Pos (11U)
#define ADC_CON_CONT_Msk (0x1UL << ADC_CON_CONT_Pos)
#define ADC_CON_CONT ADC_CON_CONT_Msk

#define ADC_CON_DMAEN_Pos (12U)
#define ADC_CON_DMAEN_Msk (0x1UL << ADC_CON_DMAEN_Pos)
#define ADC_CON_DMAEN ADC_CON_DMAEN_Msk

#define ADC_CON_ADCEN_Pos (15U)
#define ADC_CON_ADCEN_Msk (0x1UL << ADC_CON_ADCEN_Pos)
#define ADC_CON_ADCEN ADC_CON_ADCEN_Msk

#define ADC_CON_LOWSP_Pos (16U)
#define ADC_CON_LOWSP_Msk (0x7UL << ADC_CON_LOWSP_Pos)
#define ADC_CON_LOWSP ADC_CON_LOWSP_Msk

#define ADC_CON_VREFS_Pos (20U)
#define ADC_CON_VREFS_Msk (0x3UL << ADC_CON_VREFS_Pos)
#define ADC_CON_VREFS ADC_CON_VREFS_Msk
/********************  Bit definition for ADC_STS register ********************/
#define ADC_STS_EOC_Pos (0U)
#define ADC_STS_EOC_Msk (0x01UL << ADC_STS_EOC_Pos)
#define ADC_STS_EOC ADC_STS_EOC_Msk

/********************  Bit definition for ADC_CFG register ********************/
#define ADC_CFG_AIN0_Pos (0U)
#define ADC_CFG_AIN0_Msk (0x1L << ADC_CFG_AIN0_Pos)
#define ADC_CFG_AIN0 ADC_CFG_AIN0_Msk

#define ADC_CFG_AIN1_Pos (1U)
#define ADC_CFG_AIN1_Msk (0x1L << ADC_CFG_AIN1_Pos)
#define ADC_CFG_AIN1 ADC_CFG_AIN1_Msk

#define ADC_CFG_AIN2_Pos (2U)
#define ADC_CFG_AIN2_Msk (0x1L << ADC_CFG_AIN2_Pos)
#define ADC_CFG_AIN2 ADC_CFG_AIN2_Msk

#define ADC_CFG_AIN3_Pos (3U)
#define ADC_CFG_AIN3_Msk (0x1L << ADC_CFG_AIN3_Pos)
#define ADC_CFG_AIN3 ADC_CFG_AIN3_Msk

#define ADC_CFG_AIN4_Pos (4U)
#define ADC_CFG_AIN4_Msk (0x1L << ADC_CFG_AIN4_Pos)
#define ADC_CFG_AIN4 ADC_CFG_AIN4_Msk

#define ADC_CFG_AIN5_Pos (5U)
#define ADC_CFG_AIN5_Msk (0x1L << ADC_CFG_AIN5_Pos)
#define ADC_CFG_AIN5 ADC_CFG_AIN5_Msk

#define ADC_CFG_AIN6_Pos (6U)
#define ADC_CFG_AIN6_Msk (0x1L << ADC_CFG_AIN6_Pos)
#define ADC_CFG_AIN6 ADC_CFG_AIN6_Msk

#define ADC_CFG_AIN7_Pos (7U)
#define ADC_CFG_AIN7_Msk (0x1L << ADC_CFG_AIN7_Pos)
#define ADC_CFG_AIN7 ADC_CFG_AIN7_Msk

#define ADC_CFG_AIN8_Pos (8U)
#define ADC_CFG_AIN8_Msk (0x1L << ADC_CFG_AIN8_Pos)
#define ADC_CFG_AIN8 ADC_CFG_AIN8_Msk

#define ADC_CFG_AIN9_Pos (9U)
#define ADC_CFG_AIN9_Msk (0x1L << ADC_CFG_AIN9_Pos)
#define ADC_CFG_AIN9 ADC_CFG_AIN9_Msk

#define ADC_CFG_AIN10_Pos (10U)
#define ADC_CFG_AIN10_Msk (0x1L << ADC_CFG_AIN10_Pos)
#define ADC_CFG_AIN10 ADC_CFG_AIN10_Msk

#define ADC_CFG_AIN11_Pos (11U)
#define ADC_CFG_AIN11_Msk (0x1L << ADC_CFG_AIN11_Pos)
#define ADC_CFG_AIN11 ADC_CFG_AIN11_Msk

#define ADC_CFG_AIN12_Pos (12U)
#define ADC_CFG_AIN12_Msk (0x1L << ADC_CFG_AIN12_Pos)
#define ADC_CFG_AIN12 ADC_CFG_AIN12_Msk

#define ADC_CFG_AIN13_Pos (13U)
#define ADC_CFG_AIN13_Msk (0x1L << ADC_CFG_AIN13_Pos)
#define ADC_CFG_AIN13 ADC_CFG_AIN13_Msk

#define ADC_CFG_AIN14_Pos (14U)
#define ADC_CFG_AIN14_Msk (0x1L << ADC_CFG_AIN14_Pos)
#define ADC_CFG_AIN14 ADC_CFG_AIN14_Msk

#define ADC_CFG_AIN15_Pos (15U)
#define ADC_CFG_AIN15_Msk (0x1L << ADC_CFG_AIN15_Pos)
#define ADC_CFG_AIN15 ADC_CFG_AIN15_Msk

#define ADC_CFG_AIN16_Pos (16U)
#define ADC_CFG_AIN16_Msk (0x1L << ADC_CFG_AIN16_Pos)
#define ADC_CFG_AIN16 ADC_CFG_AIN16_Msk

#define ADC_CFG_AIN17_Pos (17U)
#define ADC_CFG_AIN17_Msk (0x1L << ADC_CFG_AIN17_Pos)
#define ADC_CFG_AIN17 ADC_CFG_AIN17_Msk
/********************  Bit definition for ADC_ADCV register
 * ********************/
#define ADC_ADCV_OVERRUN_Pos (31U)
#define ADC_ADCV_OVERRUN_Msk (0x1L << ADC_ADCV_OVERRUN_Pos)
#define ADC_ADCV_OVERRUN ADC_ADCV_OVERRUN_Msk

#define ADC_ADCV_ADCV_Pos (0U)
#define ADC_ADCV_ADCV_Msk (0x3FFFL << ADC_ADCV_ADCV_Pos)
#define ADC_ADCV_ADCV ADC_ADCV_ADCV_Msk

/******************************************************************************/
/*                                                                            */
/*                      BTM                    */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for BTM_CON register ********************/
#define BTM_CON_BTMFS_Pos (0U)
#define BTM_CON_BTMFS_Msk (0x0FL << BTM_CON_BTMFS_Pos)
#define BTM_CON_BTMFS BTM_CON_BTMFS_Msk

#define BTM_CON_INTEN_Pos (6U)
#define BTM_CON_INTEN_Msk (0x1L << BTM_CON_INTEN_Pos)
#define BTM_CON_INTEN BTM_CON_INTEN_Msk

#define BTM_CON_BTMEN_Pos (7U)
#define BTM_CON_BTMEN_Msk (0x1L << BTM_CON_BTMEN_Pos)
#define BTM_CON_BTMEN BTM_CON_BTMEN_Msk

/********************  Bit definition for BTM_STS register ********************/
#define BTM_STS_BTMIF_Pos (0U)
#define BTM_STS_BTMIF_Msk (0x1L << BTM_STS_BTMIF_Pos)
#define BTM_STS_BTMIF BTM_STS_BTMIF_Msk

/******************************************************************************/
/*                                                                            */
/*                      CMP                    */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for CMP_CFG register ********************/
#define CMP_CFG_CMPIS_Pos (0U)
#define CMP_CFG_CMPIS_Msk (0x7L << CMP_CFG_CMPIS_Pos)
#define CMP_CFG_CMPIS CMP_CFG_CMPIS_Msk

#define CMP_CFG_CMPP_Pos (4U)
#define CMP_CFG_CMPP_Msk (0x1L << CMP_CFG_CMPP_Pos)
#define CMP_CFG_CMPP CMP_CFG_CMPP_Msk

#define CMP_CFG_CMPIM_Pos (5U)
#define CMP_CFG_CMPIM_Msk (0x3L << CMP_CFG_CMPIM_Pos)
#define CMP_CFG_CMPIM CMP_CFG_CMPIM_Msk

#define CMP_CFG_CMPEN_Pos (7U)
#define CMP_CFG_CMPEN_Msk (0x1L << CMP_CFG_CMPEN_Pos)
#define CMP_CFG_CMPEN CMP_CFG_CMPEN_Msk

#define CMP_CFG_CMPRF_Pos (8U)
#define CMP_CFG_CMPRF_Msk (0x0FL << CMP_CFG_CMPRF_Pos)
#define CMP_CFG_CMPRF CMP_CFG_CMPRF_Msk
/********************  Bit definition for CMP_STS register ********************/
#define CMP_STS_CMPIF_Pos (0U)
#define CMP_STS_CMPIF_Msk (0x1L << CMP_STS_CMPIF_Pos)
#define CMP_STS_CMPIF CMP_STS_CMPIF_Msk

#define CMP_STS_CMPSTA_Pos (1U)
#define CMP_STS_CMPSTA_Msk (0x1L << CMP_STS_CMPSTA_Pos)
#define CMP_STS_CMPSTA CMP_STS_CMPSTA_Msk
/******************************************************************************/
/*                                                                            */
/*                      CRC                   */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for CRC_CON register ********************/
#define CRC_CON_CRCRST_Pos (0U)
#define CRC_CON_CRCRST_Msk (0x1L << CRC_CON_CRCRST_Pos)
#define CRC_CON_CRCRST CRC_CON_CRCRST_Msk

#define CRC_CON_POLYSIZE_Pos (6U)
#define CRC_CON_POLYSIZE_Msk (0x3L << CRC_CON_POLYSIZE_Pos)
#define CRC_CON_POLYSIZE CRC_CON_POLYSIZE_Msk
/********************  Bit definition for CRC_INT register ********************/
#define CRC_INT_INIT_Pos (0U)
#define CRC_INT_INIT_Msk (0xFFFFFFFFL << CRC_INT_INIT_Pos)
#define CRC_INT_INIT CRC_INT_INIT_Msk

/******************************************************************************/
/*                                                                            */
/*                      DMA
 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DMA_CFG register ********************/
#define DMA_CFG_PL_Pos (0U)
#define DMA_CFG_PL_Msk (0x3L << DMA_CFG_PL_Pos)
#define DMA_CFG_PL DMA_CFG_PL_Msk

#define DMA_CFG_TXWIDTH_Pos (2U)
#define DMA_CFG_TXWIDTH_Msk (0x3L << DMA_CFG_TXWIDTH_Pos)
#define DMA_CFG_TXWIDTH DMA_CFG_TXWIDTH_Msk

#define DMA_CFG_CIRC_Pos (4U)
#define DMA_CFG_CIRC_Msk (0x1L << DMA_CFG_CIRC_Pos)
#define DMA_CFG_CIRC DMA_CFG_CIRC_Msk

#define DMA_CFG_PAUSE_Pos (5U)
#define DMA_CFG_PAUSE_Msk (0x1L << DMA_CFG_PAUSE_Pos)
#define DMA_CFG_PAUSE DMA_CFG_PAUSE_Msk

#define DMA_CFG_CHRST_Pos (6U)
#define DMA_CFG_CHRST_Msk (0x1L << DMA_CFG_CHRST_Pos)
#define DMA_CFG_CHRST DMA_CFG_CHRST_Msk

#define DMA_CFG_CHEN_Pos (7U)
#define DMA_CFG_CHEN_Msk (0x1L << DMA_CFG_CHEN_Pos)
#define DMA_CFG_CHEN DMA_CFG_CHEN_Msk

#define DMA_CFG_DAINC_Pos (8U)
#define DMA_CFG_DAINC_Msk (0x3L << DMA_CFG_DAINC_Pos)
#define DMA_CFG_DAINC DMA_CFG_DAINC_Msk

#define DMA_CFG_SAINC_Pos (10U)
#define DMA_CFG_SAINC_Msk (0x3L << DMA_CFG_SAINC_Pos)
#define DMA_CFG_SAINC DMA_CFG_SAINC_Msk

#define DMA_CFG_BURSIZE_Pos (12U)
#define DMA_CFG_BURSIZE_Msk (0x7L << DMA_CFG_BURSIZE_Pos)
#define DMA_CFG_BURSIZE DMA_CFG_BURSIZE_Msk

#define DMA_CFG_TPTYPE_Pos (15U)
#define DMA_CFG_TPTYPE_Msk (0x1L << DMA_CFG_TPTYPE_Pos)
#define DMA_CFG_TPTYPE DMA_CFG_TPTYPE_Msk

#define DMA_CFG_INTEN_Pos (16U)
#define DMA_CFG_INTEN_Msk (0x1L << DMA_CFG_INTEN_Pos)
#define DMA_CFG_INTEN DMA_CFG_INTEN_Msk

#define DMA_CFG_TCIE_Pos (17U)
#define DMA_CFG_TCIE_Msk (0x1L << DMA_CFG_TCIE_Pos)
#define DMA_CFG_TCIE DMA_CFG_TCIE_Msk

#define DMA_CFG_HTIE_Pos (18U)
#define DMA_CFG_HTIE_Msk (0x1L << DMA_CFG_HTIE_Pos)
#define DMA_CFG_HTIE DMA_CFG_HTIE_Msk

#define DMA_CFG_TEIE_Pos (19U)
#define DMA_CFG_TEIE_Msk (0x1L << DMA_CFG_TEIE_Pos)
#define DMA_CFG_TEIE DMA_CFG_TEIE_Msk

#define DMA_CFG_CHRQ_Pos (23U)
#define DMA_CFG_CHRQ_Msk (0x1L << DMA_CFG_CHRQ_Pos)
#define DMA_CFG_CHRQ DMA_CFG_CHRQ_Msk

#define DMA_CFG_REQSRC_Pos (24U)
#define DMA_CFG_REQSRC_Msk (0x3FL << DMA_CFG_REQSRC_Pos)
#define DMA_CFG_REQSRC DMA_CFG_REQSRC_Msk

/********************  Bit definition for DMA_STS register ********************/
#define DMA_STS_GIF_Pos (0U)
#define DMA_STS_GIF_Msk (0x1L << DMA_STS_GIF_Pos)
#define DMA_STS_GIF DMA_STS_GIF_Msk

#define DMA_STS_TCIF_Pos (1U)
#define DMA_STS_TCIF_Msk (0x1L << DMA_STS_TCIF_Pos)
#define DMA_STS_TCIF DMA_STS_TCIF_Msk

#define DMA_STS_HTIF_Pos (2U)
#define DMA_STS_HTIF_Msk (0x1L << DMA_STS_HTIF_Pos)
#define DMA_STS_HTIF DMA_STS_HTIF_Msk

#define DMA_STS_TEIF_Pos (3U)
#define DMA_STS_TEIF_Msk (0x1L << DMA_STS_TEIF_Pos)
#define DMA_STS_TEIF DMA_STS_TEIF_Msk

#define DMA_STS_STATUS_Pos (4U)
#define DMA_STS_STATUS_Msk (0x0FL << DMA_STS_STATUS_Pos)
#define DMA_STS_STATUS DMA_STS_STATUS_Msk

#define DMA_STS_SWREQ_Pos (8U)
#define DMA_STS_SWREQ_Msk (0x1L << DMA_STS_SWREQ_Pos)
#define DMA_STS_SWREQ DMA_STS_SWREQ_Msk

/******************************************************************************/
/*                                                                            */
/*                      IAP
 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for IAP_CON register ********************/
#define IAP_CON_CMD_Pos (0U)
#define IAP_CON_CMD_Msk (0x3L << IAP_CON_CMD_Pos)
#define IAP_CON_CMD IAP_CON_CMD_Msk

#define IAP_CON_PRG_Pos (4U)
#define IAP_CON_PRG_Msk (0x1L << IAP_CON_PRG_Pos)
#define IAP_CON_PRG IAP_CON_PRG_Msk

#define IAP_CON_SERASE_Pos (5U)
#define IAP_CON_SERASE_Msk (0x1L << IAP_CON_SERASE_Pos)
#define IAP_CON_SERASE IAP_CON_SERASE_Msk

#define IAP_CON_ERASE_Pos (7U)
#define IAP_CON_ERASE_Msk (0x1L << IAP_CON_ERASE_Pos)
#define IAP_CON_ERASE IAP_CON_ERASE_Msk

#define IAP_CON_RST_Pos (8U)
#define IAP_CON_RST_Msk (0x1L << IAP_CON_RST_Pos)
#define IAP_CON_RST IAP_CON_RST_Msk

#define IAP_CON_BTLD_Pos (9U)
#define IAP_CON_BTLD_Msk (0x3L << IAP_CON_BTLD_Pos)
#define IAP_CON_BTLD IAP_CON_BTLD_Msk

#define IAP_CON_LOCK_Pos (31U)
#define IAP_CON_LOCK_Msk (0x1L << IAP_CON_LOCK_Pos) // V0.12
#define IAP_CON_LOCK IAP_CON_LOCK_Msk

/******************************************************************************/
/*                                                                            */
/*                      EXTI
 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for EXTI_FIE register
 * ********************/
#define EXTI_FIE_ENF0_Pos (0U)
#define EXTI_FIE_ENF0_Msk (0x1L << EXTI_FIE_ENF0_Pos)
#define EXTI_FIE_ENF0 EXTI_FIE_ENF0_Msk

#define EXTI_FIE_ENF1_Pos (1U)
#define EXTI_FIE_ENF1_Msk (0x1L << EXTI_FIE_ENF1_Pos)
#define EXTI_FIE_ENF1 EXTI_FIE_ENF1_Msk

#define EXTI_FIE_ENF2_Pos (2U)
#define EXTI_FIE_ENF2_Msk (0x1L << EXTI_FIE_ENF2_Pos)
#define EXTI_FIE_ENF2 EXTI_FIE_ENF2_Msk

#define EXTI_FIE_ENF3_Pos (3U)
#define EXTI_FIE_ENF3_Msk (0x1L << EXTI_FIE_ENF3_Pos)
#define EXTI_FIE_ENF3 EXTI_FIE_ENF3_Msk

#define EXTI_FIE_ENF4_Pos (4U)
#define EXTI_FIE_ENF4_Msk (0x1L << EXTI_FIE_ENF4_Pos)
#define EXTI_FIE_ENF4 EXTI_FIE_ENF4_Msk

#define EXTI_FIE_ENF5_Pos (5U)
#define EXTI_FIE_ENF5_Msk (0x1L << EXTI_FIE_ENF5_Pos)
#define EXTI_FIE_ENF5 EXTI_FIE_ENF5_Msk

#define EXTI_FIE_ENF6_Pos (6U)
#define EXTI_FIE_ENF6_Msk (0x1L << EXTI_FIE_ENF6_Pos)
#define EXTI_FIE_ENF6 EXTI_FIE_ENF6_Msk

#define EXTI_FIE_ENF7_Pos (7U)
#define EXTI_FIE_ENF7_Msk (0x1L << EXTI_FIE_ENF7_Pos)
#define EXTI_FIE_ENF7 EXTI_FIE_ENF7_Msk

#define EXTI_FIE_ENF8_Pos (8U)
#define EXTI_FIE_ENF8_Msk (0x1L << EXTI_FIE_ENF8_Pos)
#define EXTI_FIE_ENF8 EXTI_FIE_ENF8_Msk

#define EXTI_FIE_ENF9_Pos (9U)
#define EXTI_FIE_ENF9_Msk (0x1L << EXTI_FIE_ENF9_Pos)
#define EXTI_FIE_ENF9 EXTI_FIE_ENF9_Msk

#define EXTI_FIE_ENF10_Pos (10U)
#define EXTI_FIE_ENF10_Msk (0x1L << EXTI_FIE_ENF10_Pos)
#define EXTI_FIE_ENF10 EXTI_FIE_ENF10_Msk

#define EXTI_FIE_ENF11_Pos (11U)
#define EXTI_FIE_ENF11_Msk (0x1L << EXTI_FIE_ENF11_Pos)
#define EXTI_FIE_ENF11 EXTI_FIE_ENF11_Msk

#define EXTI_FIE_ENF12_Pos (12U)
#define EXTI_FIE_ENF12_Msk (0x1L << EXTI_FIE_ENF12_Pos)
#define EXTI_FIE_ENF12 EXTI_FIE_ENF12_Msk

#define EXTI_FIE_ENF13_Pos (13U)
#define EXTI_FIE_ENF13_Msk (0x1L << EXTI_FIE_ENF13_Pos)
#define EXTI_FIE_ENF13 EXTI_FIE_ENF13_Msk

#define EXTI_FIE_ENF14_Pos (14U)
#define EXTI_FIE_ENF14_Msk (0x1L << EXTI_FIE_ENF14_Pos)
#define EXTI_FIE_ENF14 EXTI_FIE_ENF14_Msk

#define EXTI_FIE_ENF15_Pos (15U)
#define EXTI_FIE_ENF15_Msk (0x1L << EXTI_FIE_ENF15_Pos)
#define EXTI_FIE_ENF15 EXTI_FIE_ENF15_Msk
/********************  Bit definition for EXTI_RIE register
 * ********************/
#define EXTI_RIE_ENR0_Pos (0U)
#define EXTI_RIE_ENR0_Msk (0x1L << EXTI_RIE_ENR0_Pos)
#define EXTI_RIE_ENR0 EXTI_RIE_ENR0_Msk

#define EXTI_RIE_ENR1_Pos (1U)
#define EXTI_RIE_ENR1_Msk (0x1L << EXTI_RIE_ENR1_Pos)
#define EXTI_RIE_ENR1 EXTI_RIE_ENR1_Msk

#define EXTI_RIE_ENR2_Pos (2U)
#define EXTI_RIE_ENR2_Msk (0x1L << EXTI_RIE_ENR2_Pos)
#define EXTI_RIE_ENR2 EXTI_RIE_ENR2_Msk

#define EXTI_RIE_ENR3_Pos (3U)
#define EXTI_RIE_ENR3_Msk (0x1L << EXTI_RIE_ENR3_Pos)
#define EXTI_RIE_ENR3 EXTI_RIE_ENR3_Msk

#define EXTI_RIE_ENR4_Pos (4U)
#define EXTI_RIE_ENR4_Msk (0x1L << EXTI_RIE_ENR4_Pos)
#define EXTI_RIE_ENR4 EXTI_RIE_ENR4_Msk

#define EXTI_RIE_ENR5_Pos (5U)
#define EXTI_RIE_ENR5_Msk (0x1L << EXTI_RIE_ENR5_Pos)
#define EXTI_RIE_ENR5 EXTI_RIE_ENR5_Msk

#define EXTI_RIE_ENR6_Pos (6U)
#define EXTI_RIE_ENR6_Msk (0x1L << EXTI_RIE_ENR6_Pos)
#define EXTI_RIE_ENR6 EXTI_RIE_ENR6_Msk

#define EXTI_RIE_ENR7_Pos (7U)
#define EXTI_RIE_ENR7_Msk (0x1L << EXTI_RIE_ENR7_Pos)
#define EXTI_RIE_ENR7 EXTI_RIE_ENR7_Msk

#define EXTI_RIE_ENR8_Pos (8U)
#define EXTI_RIE_ENR8_Msk (0x1L << EXTI_RIE_ENR8_Pos)
#define EXTI_RIE_ENR8 EXTI_RIE_ENR8_Msk

#define EXTI_RIE_ENR9_Pos (9U)
#define EXTI_RIE_ENR9_Msk (0x1L << EXTI_RIE_ENR9_Pos)
#define EXTI_RIE_ENR9 EXTI_RIE_ENR9_Msk

#define EXTI_RIE_ENR10_Pos (10U)
#define EXTI_RIE_ENR10_Msk (0x1L << EXTI_RIE_ENR10_Pos)
#define EXTI_RIE_ENR10 EXTI_RIE_ENR10_Msk

#define EXTI_RIE_ENR11_Pos (11U)
#define EXTI_RIE_ENR11_Msk (0x1L << EXTI_RIE_ENR11_Pos)
#define EXTI_RIE_ENR11 EXTI_RIE_ENR11_Msk

#define EXTI_RIE_ENR12_Pos (12U)
#define EXTI_RIE_ENR12_Msk (0x1L << EXTI_RIE_ENR12_Pos)
#define EXTI_RIE_ENR12 EXTI_RIE_ENR12_Msk

#define EXTI_RIE_ENR13_Pos (13U)
#define EXTI_RIE_ENR13_Msk (0x1L << EXTI_RIE_ENR13_Pos)
#define EXTI_RIE_ENR13 EXTI_RIE_ENR13_Msk

#define EXTI_RIE_ENR14_Pos (14U)
#define EXTI_RIE_ENR14_Msk (0x1L << EXTI_RIE_ENR14_Pos)
#define EXTI_RIE_ENR14 EXTI_RIE_ENR14_Msk

#define EXTI_RIE_ENR15_Pos (15U)
#define EXTI_RIE_ENR15_Msk (0x1L << EXTI_RIE_ENR15_Pos)
#define EXTI_RIE_ENR15 EXTI_RIE_ENR15_Msk

/********************  Bit definition for EXTI_SEL0 register
 * ********************/
#define EXTI_SEL0_INT0SEL_Pos (0U)
#define EXTI_SEL0_INT0SEL_Msk (0x0FL << EXTI_SEL0_INT0SEL_Pos)
#define EXTI_SEL0_INT0SEL EXTI_SEL0_INT0SEL_Msk

#define EXTI_SEL0_INT1SEL_Pos (4U)
#define EXTI_SEL0_INT1SEL_Msk (0x0FL << EXTI_SEL0_INT1SEL_Pos)
#define EXTI_SEL0_INT1SEL EXTI_SEL0_INT1SEL_Msk

#define EXTI_SEL0_INT2SEL_Pos (8U)
#define EXTI_SEL0_INT2SEL_Msk (0x0FL << EXTI_SEL0_INT2SEL_Pos)
#define EXTI_SEL0_INT2SEL EXTI_SEL0_INT2SEL_Msk

#define EXTI_SEL0_INT3SEL_Pos (12U)
#define EXTI_SEL0_INT3SEL_Msk (0x0FL << EXTI_SEL0_INT3SEL_Pos)
#define EXTI_SEL0_INT3SEL EXTI_SEL0_INT3SEL_Msk

#define EXTI_SEL0_INT4SEL_Pos (16U)
#define EXTI_SEL0_INT4SEL_Msk (0x0FL << EXTI_SEL0_INT4SEL_Pos)
#define EXTI_SEL0_INT4SEL EXTI_SEL0_INT4SEL_Msk

#define EXTI_SEL0_INT5SEL_Pos (20U)
#define EXTI_SEL0_INT5SEL_Msk (0x0FL << EXTI_SEL0_INT5SEL_Pos)
#define EXTI_SEL0_INT5SEL EXTI_SEL0_INT5SEL_Msk

#define EXTI_SEL0_INT6SEL_Pos (24U)
#define EXTI_SEL0_INT6SEL_Msk (0x0FL << EXTI_SEL0_INT6SEL_Pos)
#define EXTI_SEL0_INT6SEL EXTI_SEL0_INT6SEL_Msk

#define EXTI_SEL0_INT7SEL_Pos (28U)
#define EXTI_SEL0_INT7SEL_Msk (0x0FL << EXTI_SEL0_INT7SEL_Pos)
#define EXTI_SEL0_INT7SEL EXTI_SEL0_INT7SEL_Msk

/********************  Bit definition for EXTI_SEL1 register
 * ********************/
#define EXTI_SEL1_INT8SEL_Pos (0U)
#define EXTI_SEL1_INT8SEL_Msk (0x0FL << EXTI_SEL1_INT8SEL_Pos)
#define EXTI_SEL1_INT8SEL EXTI_SEL1_INT8SEL_Msk

#define EXTI_SEL1_INT9SEL_Pos (4U)
#define EXTI_SEL1_INT9SEL_Msk (0x0FL << EXTI_SEL1_INT9SEL_Pos)
#define EXTI_SEL1_INT9SEL EXTI_SEL1_INT9SEL_Msk

#define EXTI_SEL1_INT10SEL_Pos (8U)
#define EXTI_SEL1_INT10SEL_Msk (0x0FL << EXTI_SEL1_INT10SEL_Pos)
#define EXTI_SEL1_INT10SEL EXTI_SEL1_INT10SEL_Msk

#define EXTI_SEL1_INT11SEL_Pos (12U)
#define EXTI_SEL1_INT11SEL_Msk (0x0FL << EXTI_SEL1_INT11SEL_Pos)
#define EXTI_SEL1_INT11SEL EXTI_SEL1_INT11SEL_Msk

#define EXTI_SEL1_INT12SEL_Pos (16U)
#define EXTI_SEL1_INT12SEL_Msk (0x0FL << EXTI_SEL1_INT12SEL_Pos)
#define EXTI_SEL1_INT12SEL EXTI_SEL1_INT12SEL_Msk

#define EXTI_SEL1_INT13SEL_Pos (20U)
#define EXTI_SEL1_INT13SEL_Msk (0x0FL << EXTI_SEL1_INT13SEL_Pos)
#define EXTI_SEL1_INT13SEL EXTI_SEL1_INT13SEL_Msk

#define EXTI_SEL1_INT14SEL_Pos (24U)
#define EXTI_SEL1_INT14SEL_Msk (0x0FL << EXTI_SEL1_INT14SEL_Pos)
#define EXTI_SEL1_INT14SEL EXTI_SEL1_INT14SEL_Msk

#define EXTI_SEL1_INT15SEL_Pos (28U)
#define EXTI_SEL1_INT15SEL_Msk (0x0FL << EXTI_SEL1_INT15SEL_Pos)
#define EXTI_SEL1_INT15SEL EXTI_SEL1_INT15SEL_Msk

/********************  Bit definition for EXTI_FCON register
 * ********************/
#define EXTI_FCON_FT0_Pos (0U)
#define EXTI_FCON_FT0_Msk (0x1L << EXTI_FCON_FT0_Pos)
#define EXTI_FCON_FT0 EXTI_FCON_FT0_Msk

#define EXTI_FCON_FT1_Pos (1U)
#define EXTI_FCON_FT1_Msk (0x1L << EXTI_FCON_FT1_Pos)
#define EXTI_FCON_FT1 EXTI_FCON_FT1_Msk

#define EXTI_FCON_FT2_Pos (2U)
#define EXTI_FCON_FT2_Msk (0x1L << EXTI_FCON_FT2_Pos)
#define EXTI_FCON_FT2 EXTI_FCON_FT2_Msk

#define EXTI_FCON_FT3_Pos (3U)
#define EXTI_FCON_FT3_Msk (0x1L << EXTI_FCON_FT3_Pos)
#define EXTI_FCON_FT3 EXTI_FCON_FT3_Msk

#define EXTI_FCON_FT4_Pos (4U)
#define EXTI_FCON_FT4_Msk (0x1L << EXTI_FCON_FT4_Pos)
#define EXTI_FCON_FT4 EXTI_FCON_FT4_Msk

#define EXTI_FCON_FT5_Pos (5U)
#define EXTI_FCON_FT5_Msk (0x1L << EXTI_FCON_FT5_Pos)
#define EXTI_FCON_FT5 EXTI_FCON_FT5_Msk

#define EXTI_FCON_FT6_Pos (6U)
#define EXTI_FCON_FT6_Msk (0x1L << EXTI_FCON_FT6_Pos)
#define EXTI_FCON_FT6 EXTI_FCON_FT6_Msk

#define EXTI_FCON_FT7_Pos (7U)
#define EXTI_FCON_FT7_Msk (0x1L << EXTI_FCON_FT7_Pos)
#define EXTI_FCON_FT EXTI_FCON_FT7_Msk

#define EXTI_FCON_FT8_Pos (8U)
#define EXTI_FCON_FT8_Msk (0x1L << EXTI_FCON_FT8_Pos)
#define EXTI_FCON_FT8 EXTI_FCON_FT8_Msk

#define EXTI_FCON_FT9_Pos (9U)
#define EXTI_FCON_FT9_Msk (0x1L << EXTI_FCON_FT9_Pos)
#define EXTI_FCON_FT9 EXTI_FCON_FT9_Msk

#define EXTI_FCON_FT10_Pos (10U)
#define EXTI_FCON_FT10_Msk (0x1L << EXTI_FCON_FT10_Pos)
#define EXTI_FCON_FT10 EXTI_FCON_FT10_Msk

#define EXTI_FCON_FT11_Pos (11U)
#define EXTI_FCON_FT11_Msk (0x1L << EXTI_FCON_FT11_Pos)
#define EXTI_FCON_FT11 EXTI_FCON_FT11_Msk

#define EXTI_FCON_FT12_Pos (12U)
#define EXTI_FCON_FT12_Msk (0x1L << EXTI_FCON_FT12_Pos)
#define EXTI_FCON_FT12 EXTI_FCON_FT12_Msk

#define EXTI_FCON_FT13_Pos (13U)
#define EXTI_FCON_FT13_Msk (0x1L << EXTI_FCON_FT13_Pos)
#define EXTI_FCON_FT13 EXTI_FCON_FT13_Msk

#define EXTI_FCON_FT14_Pos (14U)
#define EXTI_FCON_FT14_Msk (0x1L << EXTI_FCON_FT14_Pos)
#define EXTI_FCON_FT14 EXTI_FCON_FT14_Msk

#define EXTI_FCON_FT15_Pos (15U)
#define EXTI_FCON_FT15_Msk (0x1L << EXTI_FCON_FT15_Pos)
#define EXTI_FCON_FT15 EXTI_FCON_FT15_Msk

/********************  Bit definition for EXTI_RCON register
 * ********************/
#define EXTI_RCON_RT0_Pos (0U)
#define EXTI_RCON_RT0_Msk (0x1L << EXTI_RCON_RT0_Pos)
#define EXTI_RCON_RT0 EXTI_RCON_RT0_Msk

#define EXTI_RCON_RT1_Pos (1U)
#define EXTI_RCON_RT_Msk (0x1L << EXTI_RCON_RT1_Pos)
#define EXTI_RCON_RT1 EXTI_RCON_RT_Msk

#define EXTI_RCON_RT2_Pos (2U)
#define EXTI_RCON_RT2_Msk (0x1L << EXTI_RCON_RT2_Pos)
#define EXTI_RCON_RT2 EXTI_RCON_RT2_Msk

#define EXTI_RCON_RT3_Pos (3U)
#define EXTI_RCON_RT3_Msk (0x1L << EXTI_RCON_RT3_Pos)
#define EXTI_RCON_RT3 EXTI_RCON_RT3_Msk

#define EXTI_RCON_RT4_Pos (4U)
#define EXTI_RCON_RT4_Msk (0x1L << EXTI_RCON_RT4_Pos)
#define EXTI_RCON_RT4 EXTI_RCON_RT4_Msk

#define EXTI_RCON_RT5_Pos (5U)
#define EXTI_RCON_RT5_Msk (0x1L << EXTI_RCON_RT5_Pos)
#define EXTI_RCON_RT5 EXTI_RCON_RT5_Msk

#define EXTI_RCON_RT6_Pos (6U)
#define EXTI_RCON_RT6_Msk (0x1L << EXTI_RCON_RT6_Pos)
#define EXTI_RCON_RT6 EXTI_RCON_RT6_Msk

#define EXTI_RCON_RT7_Pos (7U)
#define EXTI_RCON_RT7_Msk (0x1L << EXTI_RCON_RT7_Pos)
#define EXTI_RCON_RT EXTI_RCON_RT7_Msk

#define EXTI_RCON_RT8_Pos (8U)
#define EXTI_RCON_RT8_Msk (0x1L << EXTI_RCON_RT8_Pos)
#define EXTI_RCON_RT8 EXTI_RCON_RT8_Msk

#define EXTI_RCON_RT9_Pos (9U)
#define EXTI_RCON_RT9_Msk (0x1L << EXTI_RCON_RT9_Pos)
#define EXTI_RCON_RT9 EXTI_RCON_RT9_Msk

#define EXTI_RCON_RT10_Pos (10U)
#define EXTI_RCON_RT10_Msk (0x1L << EXTI_RCON_RT10_Pos)
#define EXTI_RCON_RT10 EXTI_RCON_RT10_Msk

#define EXTI_RCON_RT11_Pos (11U)
#define EXTI_RCON_RT11_Msk (0x1L << EXTI_RCON_RT11_Pos)
#define EXTI_RCON_RT11 EXTI_RCON_RT11_Msk

#define EXTI_RCON_RT12_Pos (12U)
#define EXTI_RCON_RT12_Msk (0x1L << EXTI_RCON_RT12_Pos)
#define EXTI_RCON_RT12 EXTI_RCON_RT12_Msk

#define EXTI_RCON_RT13_Pos (13U)
#define EXTI_RCON_RT13_Msk (0x1L << EXTI_RCON_RT13_Pos)
#define EXTI_RCON_RT13 EXTI_RCON_RT13_Msk

#define EXTI_RCON_RT14_Pos (14U)
#define EXTI_RCON_RT14_Msk (0x1L << EXTI_RCON_RT14_Pos)
#define EXTI_RCON_RT14 EXTI_RCON_RT14_Msk

#define EXTI_RCON_RT15_Pos (15U)
#define EXTI_RCON_RT15_Msk (0x1L << EXTI_RCON_RT15_Pos)
#define EXTI_RCON_RT15 EXTI_RCON_RT15_Msk

/********************  Bit definition for EXTI_FSTS register
 * ********************/
#define EXTI_FSTS_FIF0_Pos (0U)
#define EXTI_FSTS_FIF0_Msk (0x1L << EXTI_FSTS_FIF0_Pos)
#define EXTI_FSTS_FIF0 EXTI_FSTS_FIF0_Msk

#define EXTI_FSTS_FIF1_Pos (1U)
#define EXTI_FSTS_FIF1_Msk (0x1L << EXTI_FSTS_FIF1_Pos)
#define EXTI_FSTS_FIF1 EXTI_FSTS_FIF1_Msk

#define EXTI_FSTS_FIF2_Pos (2U)
#define EXTI_FSTS_FIF2_Msk (0x1L << EXTI_FSTS_FIF2_Pos)
#define EXTI_FSTS_FIF2 EXTI_FSTS_FIF2_Msk

#define EXTI_FSTS_FIF3_Pos (3U)
#define EXTI_FSTS_FIF3_Msk (0x1L << EXTI_FSTS_FIF3_Pos)
#define EXTI_FSTS_FIF3 EXTI_FSTS_FIF3_Msk

#define EXTI_FSTS_FIF4_Pos (4U)
#define EXTI_FSTS_FIF4_Msk (0x1L << EXTI_FSTS_FIF4_Pos)
#define EXTI_FSTS_FIF4 EXTI_FSTS_FIF4_Msk

#define EXTI_FSTS_FIF5_Pos (5U)
#define EXTI_FSTS_FIF5_Msk (0x1L << EXTI_FSTS_FIF5_Pos)
#define EXTI_FSTS_FIF5 EXTI_FSTS_FIF5_Msk

#define EXTI_FSTS_FIF6_Pos (6U)
#define EXTI_FSTS_FIF6_Msk (0x1L << EXTI_FSTS_FIF6_Pos)
#define EXTI_FSTS_FIF6 EXTI_FSTS_FIF6_Msk

#define EXTI_FSTS_FIF7_Pos (7U)
#define EXTI_FSTS_FIF7_Msk (0x1L << EXTI_FSTS_FIF7_Pos)
#define EXTI_FSTS_FIF EXTI_FSTS_FIF7_Msk

#define EXTI_FSTS_FIF8_Pos (8U)
#define EXTI_FSTS_FIF8_Msk (0x1L << EXTI_FSTS_FIF8_Pos)
#define EXTI_FSTS_FIF8 EXTI_FSTS_FIF8_Msk

#define EXTI_FSTS_FIF9_Pos (9U)
#define EXTI_FSTS_FIF9_Msk (0x1L << EXTI_FSTS_FIF9_Pos)
#define EXTI_FSTS_FIF9 EXTI_FSTS_FIF9_Msk

#define EXTI_FSTS_FIF10_Pos (10U)
#define EXTI_FSTS_FIF10_Msk (0x1L << EXTI_FSTS_FIF10_Pos)
#define EXTI_FSTS_FIF10 EXTI_FSTS_FIF10_Msk

#define EXTI_FSTS_FIF11_Pos (11U)
#define EXTI_FSTS_FIF11_Msk (0x1L << EXTI_FSTS_FIF11_Pos)
#define EXTI_FSTS_FIF11 EXTI_FSTS_FIF11_Msk

#define EXTI_FSTS_FIF12_Pos (12U)
#define EXTI_FSTS_FIF12_Msk (0x1L << EXTI_FSTS_FIF12_Pos)
#define EXTI_FSTS_FIF12 EXTI_FSTS_FIF12_Msk

#define EXTI_FSTS_FIF13_Pos (13U)
#define EXTI_FSTS_FIF13_Msk (0x1L << EXTI_FSTS_FIF13_Pos)
#define EXTI_FSTS_FIF13 EXTI_FSTS_FIF13_Msk

#define EXTI_FSTS_FIF14_Pos (14U)
#define EXTI_FSTS_FIF14_Msk (0x1L << EXTI_FSTS_FIF14_Pos)
#define EXTI_FSTS_FIF14 EXTI_FSTS_FIF14_Msk

#define EXTI_FSTS_FIF15_Pos (15U)
#define EXTI_FSTS_FIF15_Msk (0x1L << EXTI_FSTS_FIF15_Pos)
#define EXTI_FSTS_FIF15 EXTI_FSTS_FIF15_Msk

/********************  Bit definition for EXTI_RSTS register
 * ********************/
#define EXTI_RSTS_RIF0_Pos (0U)
#define EXTI_RSTS_RIF0_Msk (0x1L << EXTI_RSTS_RIF0_Pos)
#define EXTI_RSTS_RIF0 EXTI_RSTS_RIF0_Msk

#define EXTI_RSTS_RIF1_Pos (1U)
#define EXTI_RSTS_RIF_Msk (0x1L << EXTI_RSTS_RIF1_Pos)
#define EXTI_RSTS_RIF1 EXTI_RSTS_RIF_Msk

#define EXTI_RSTS_RIF2_Pos (2U)
#define EXTI_RSTS_RIF2_Msk (0x1L << EXTI_RSTS_RIF2_Pos)
#define EXTI_RSTS_RIF2 EXTI_RSTS_RIF2_Msk

#define EXTI_RSTS_RIF3_Pos (3U)
#define EXTI_RSTS_RIF3_Msk (0x1L << EXTI_RSTS_RIF3_Pos)
#define EXTI_RSTS_RIF3 EXTI_RSTS_RIF3_Msk

#define EXTI_RSTS_RIF4_Pos (4U)
#define EXTI_RSTS_RIF4_Msk (0x1L << EXTI_RSTS_RIF4_Pos)
#define EXTI_RSTS_RIF4 EXTI_RSTS_RIF4_Msk

#define EXTI_RSTS_RIF5_Pos (5U)
#define EXTI_RSTS_RIF5_Msk (0x1L << EXTI_RSTS_RIF5_Pos)
#define EXTI_RSTS_RIF5 EXTI_RSTS_RIF5_Msk

#define EXTI_RSTS_RIF6_Pos (6U)
#define EXTI_RSTS_RIF6_Msk (0x1L << EXTI_RSTS_RIF6_Pos)
#define EXTI_RSTS_RIF6 EXTI_RSTS_RIF6_Msk

#define EXTI_RSTS_RIF7_Pos (7U)
#define EXTI_RSTS_RIF7_Msk (0x1L << EXTI_RSTS_RIF7_Pos)
#define EXTI_RSTS_RIF EXTI_RSTS_RIF7_Msk

#define EXTI_RSTS_RIF8_Pos (8U)
#define EXTI_RSTS_RIF8_Msk (0x1L << EXTI_RSTS_RIF8_Pos)
#define EXTI_RSTS_RIF8 EXTI_RSTS_RIF8_Msk

#define EXTI_RSTS_RIF9_Pos (9U)
#define EXTI_RSTS_RIF9_Msk (0x1L << EXTI_RSTS_RIF9_Pos)
#define EXTI_RSTS_RIF9 EXTI_RSTS_RIF9_Msk

#define EXTI_RSTS_RIF10_Pos (10U)
#define EXTI_RSTS_RIF10_Msk (0x1L << EXTI_RSTS_RIF10_Pos)
#define EXTI_RSTS_RIF10 EXTI_RSTS_RIF10_Msk

#define EXTI_RSTS_RIF11_Pos (11U)
#define EXTI_RSTS_RIF11_Msk (0x1L << EXTI_RSTS_RIF11_Pos)
#define EXTI_RSTS_RIF11 EXTI_RSTS_RIF11_Msk

#define EXTI_RSTS_RIF12_Pos (12U)
#define EXTI_RSTS_RIF12_Msk (0x1L << EXTI_RSTS_RIF12_Pos)
#define EXTI_RSTS_RIF12 EXTI_RSTS_RIF12_Msk

#define EXTI_RSTS_RIF13_Pos (13U)
#define EXTI_RSTS_RIF13_Msk (0x1L << EXTI_RSTS_RIF13_Pos)
#define EXTI_RSTS_RIF13 EXTI_RSTS_RIF13_Msk

#define EXTI_RSTS_RIF14_Pos (14U)
#define EXTI_RSTS_RIF14_Msk (0x1L << EXTI_RSTS_RIF14_Pos)
#define EXTI_RSTS_RIF14 EXTI_RSTS_RIF14_Msk

#define EXTI_RSTS_RIF15_Pos (15U)
#define EXTI_RSTS_RIF15_Msk (0x1L << EXTI_RSTS_RIF15_Pos)
#define EXTI_RSTS_RIF15 EXTI_RSTS_RIF15
/******************************************************************************/
/*                                                                            */
/*                      LCD
 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DDR_CON register ********************/
#define DDR_CON_DMOD_Pos (0U)
#define DDR_CON_DMOD_Msk (0x1L << DDR_CON_DMOD_Pos)
#define DDR_CON_DMOD DDR_CON_DMOD_Msk

#define DDR_CON_BIAS_Pos (1U)
#define DDR_CON_BIAS_Msk (0x1L << DDR_CON_BIAS_Pos)
#define DDR_CON_BIAS DDR_CON_BIAS_Msk

#define DDR_CON_VOIRSF_Pos (3U)
#define DDR_CON_VOIRSF_Msk (0x1L << DDR_CON_VOIRSF_Pos)
#define DDR_CON_VOIRSF DDR_CON_VOIRSF_Msk

#define DDR_CON_TYPE_Pos (4U)
#define DDR_CON_TYPE_Msk (0x1L << DDR_CON_TYPE_Pos)
#define DDR_CON_TYPE DDR_CON_TYPE_Msk

#define DDR_CON_DDRON_Pos (7U)
#define DDR_CON_DDRON_Msk (0x1L << DDR_CON_DDRON_Pos)
#define DDR_CON_DDRON DDR_CON_DDRON_Msk

#define DDR_CON_DDRCK_Pos (8U)
#define DDR_CON_DDRCK_Msk (0x3L << DDR_CON_DDRCK_Pos)
#define DDR_CON_DDRCK DDR_CON_DDRCK_Msk

#define DDR_CON_TRICOM_Pos (14U)
#define DDR_CON_TRICOM_Msk (0x1L << DDR_CON_TRICOM_Pos)
#define DDR_CON_TRICOM DDR_CON_TRICOM_Msk

#define DDR_CON_TRIMODE_Pos (15U)
#define DDR_CON_TRIMODE_Msk (0x1L << DDR_CON_TRIMODE_Pos)
#define DDR_CON_TRIMODE DDR_CON_TRIMODE_Msk

/********************  Bit definition for DDR_CFG register ********************/
#define DDR_CFG_DMOD_Pos (0U)
#define DDR_CFG_DMOD_Msk (0x3L << DDR_CFG_DMOD_Pos)
#define DDR_CFG_DMOD DDR_CFG_DMOD_Msk

#define DDR_CFG_DUTY_Pos (4U)
#define DDR_CFG_DUTY_Msk (0x3L << DDR_CFG_DUTY_Pos)
#define DDR_CFG_DUTY DDR_CFG_DUTY_Msk

#define DDR_CFG_SCS_Pos (7U)
#define DDR_CFG_SCS_Msk (0x3L << DDR_CFG_SCS_Pos)
#define DDR_CFG_SCS DDR_CFG_SCS_Msk

#define DDR_CFG_VLCD_Pos (8U)
#define DDR_CFG_VLCD_Msk (0x0FL << DDR_CFG_VLCD_Pos)
#define DDR_CFG_VLCD DDR_CFG_VLCD_Msk
/******************************************************************************/
/*                                                                            */
/*                      PGA
 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PGA_CON register ********************/
#define PGA_CON_ENPGA_Pos (0U)
#define PGA_CON_ENPGA_Msk (0x1L << PGA_CON_ENPGA_Pos)
#define PGA_CON_ENPGA PGA_CON_ENPGA_Msk

#define PGA_CON_PGACOM_Pos (1U)
#define PGA_CON_PGACOM_Msk (0x1L << PGA_CON_PGACOM_Pos)
#define PGA_CON_PGACOM PGA_CON_PGACOM_Msk

#define PGA_CON_PGAGAN_Pos (2U)
#define PGA_CON_PGAGAN_Msk (0x1L << PGA_CON_PGAGAN_Pos)
#define PGA_CON_PGAGAN PGA_CON_PGAGAN_Msk

#define PGA_CON_PGAIPT_Pos (3U)
#define PGA_CON_PGAIPT_Msk (0x1L << PGA_CON_PGAIPT_Pos)
#define PGA_CON_PGAIPT PGA_CON_PGAIPT_Msk

#define PGA_CON_PGAINSEL_Pos (4U)
#define PGA_CON_PGAINSEL_Msk (0x1L << PGA_CON_PGAINSEL_Pos)
#define PGA_CON_PGAINSEL PGA_CON_PGAINSEL_Msk

#define PGA_CON_PGAOFS_Pos (8U)
#define PGA_CON_PGAOFS_Msk (0x3FL << PGA_CON_PGAOFS_Pos)
#define PGA_CON_PGAOFS PGA_CON_PGAOFS_Msk

#define PGA_CON_PGAOFC_Pos (15U)
#define PGA_CON_PGAOFC_Msk (0x1L << PGA_CON_PGAOFC_Pos)
#define PGA_CON_PGAOFC PGA_CON_PGAOFC_Msk
/******************************************************************************/
/*                                                                            */
/*                      PWM0
 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PWM0_CON register
 * ********************/
#define PWM0_CON_PWMCLK_Pos (0U)
#define PWM0_CON_PWMCLK_Msk (0x7L << PWM0_CON_PWMCLK_Pos)
#define PWM0_CON_PWMCLK PWM0_CON_PWMCLK_Msk

#define PWM0_CON_PWMMD1_Pos (5U)
#define PWM0_CON_PWMMD1_Msk (0x1L << PWM0_CON_PWMMD1_Pos)
#define PWM0_CON_PWMMD1 PWM0_CON_PWMMD1_Msk

#define PWM0_CON_PWMMD0_Pos (6U)
#define PWM0_CON_PWMMD0_Msk (0x1L << PWM0_CON_PWMMD0_Pos)
#define PWM0_CON_PWMMD0 PWM0_CON_PWMMD0_Msk

#define PWM0_CON_ENPWM_Pos (7U)
#define PWM0_CON_ENPWM_Msk (0x1L << PWM0_CON_ENPWM_Pos)
#define PWM0_CON_ENPWM PWM0_CON_ENPWM_Msk

#define PWM0_CON_INTEN_Pos (8U)
#define PWM0_CON_INTEN_Msk (0x1L << PWM0_CON_INTEN_Pos)
#define PWM0_CON_INTEN PWM0_CON_INTEN_Msk
/********************  Bit definition for PWM0_CHN register
 * ********************/
#define PWM0_CHN_ENPWM0_Pos (0U)
#define PWM0_CHN_ENPWM0_Msk (0x1L << PWM0_CHN_ENPWM0_Pos)
#define PWM0_CHN_ENPWM0 PWM0_CHN_ENPWM0_Msk

#define PWM0_CHN_ENPWM1_Pos (1U)
#define PWM0_CHN_ENPWM1_Msk (0x1L << PWM0_CHN_ENPWM1_Pos)
#define PWM0_CHN_ENPWM1 PWM0_CHN_ENPWM1_Msk

#define PWM0_CHN_ENPWM2_Pos (2U)
#define PWM0_CHN_ENPWM2_Msk (0x1L << PWM0_CHN_ENPWM2_Pos)
#define PWM0_CHN_ENPWM2 PWM0_CHN_ENPWM2_Msk

#define PWM0_CHN_ENPWM3_Pos (3U)
#define PWM0_CHN_ENPWM3_Msk (0x1L << PWM0_CHN_ENPWM3_Pos)
#define PWM0_CHN_ENPWM3 PWM0_CHN_ENPWM3_Msk

#define PWM0_CHN_ENPWM4_Pos (4U)
#define PWM0_CHN_ENPWM4_Msk (0x1L << PWM0_CHN_ENPWM4_Pos)
#define PWM0_CHN_ENPWM4 PWM0_CHN_ENPWM4_Msk

#define PWM0_CHN_ENPWM5_Pos (5U)
#define PWM0_CHN_ENPWM5_Msk (0x1L << PWM0_CHN_ENPWM5_Pos)
#define PWM0_CHN_ENPWM5 PWM0_CHN_ENPWM5_Msk

#define PWM0_CHN_ENPWM6_Pos (6U)
#define PWM0_CHN_ENPWM6_Msk (0x1L << PWM0_CHN_ENPWM6_Pos)
#define PWM0_CHN_ENPWM6 PWM0_CHN_ENPWM6_Msk

#define PWM0_CHN_ENPWM7_Pos (7U)
#define PWM0_CHN_ENPWM7_Msk (0x1L << PWM0_CHN_ENPWM7_Pos)
#define PWM0_CHN_ENPWM7 PWM0_CHN_ENPWM7_Msk
/********************  Bit definition for PWM0_STS register
 * ********************/
#define PWM0_STS_PWMIF_Pos (0U)
#define PWM0_STS_PWMIF_Msk (0x1L << PWM0_STS_PWMIF_Pos)
#define PWM0_STS_PWMIF PWM0_STS_PWMIF_Msk

#define PWM0_STS_FLTSTA_Pos (1U)
#define PWM0_STS_FLTSTA_Msk (0x1L << PWM0_STS_FLTSTA_Pos)
#define PWM0_STS_FLTSTA PWM0_STS_FLTSTA_Msk
/********************  Bit definition for PWM0_INV register
 * ********************/
#define PWM0_INV_INV0_Pos (0U)
#define PWM0_INV_INV0_Msk (0x1L << PWM0_INV_INV0_Pos)
#define PWM0_INV_INV0 PWM0_INV_INV0_Msk

#define PWM0_INV_INV1_Pos (1U)
#define PWM0_INV_INV1_Msk (0x1L << PWM0_INV_INV1_Pos)
#define PWM0_INV_INV1 PWM0_INV_INV1_Msk

#define PWM0_INV_INV2_Pos (2U)
#define PWM0_INV_INV2_Msk (0x1L << PWM0_INV_INV2_Pos)
#define PWM0_INV_INV2 PWM0_INV_INV2_Msk

#define PWM0_INV_INV3_Pos (3U)
#define PWM0_INV_INV3_Msk (0x1L << PWM0_INV_INV3_Pos)
#define PWM0_INV_INV3 PWM0_INV_INV3_Msk

#define PWM0_INV_INV4_Pos (4U)
#define PWM0_INV_INV4_Msk (0x1L << PWM0_INV_INV4_Pos)
#define PWM0_INV_INV4 PWM0_INV_INV4_Msk

#define PWM0_INV_INV5_Pos (5U)
#define PWM0_INV_INV5_Msk (0x1L << PWM0_INV_INV5_Pos)
#define PWM0_INV_INV5 PWM0_INV_INV5_Msk

#define PWM0_INV_INV6_Pos (6U)
#define PWM0_INV_INV6_Msk (0x1L << PWM0_INV_INV6_Pos)
#define PWM0_INV_INV6 PWM0_INV_INV6_Msk

#define PWM0_INV_INV7_Pos (7U)
#define PWM0_INV_INV7_Msk (0x1L << PWM0_INV_INV7_Pos)
#define PWM0_INV_INV7 PWM0_INV_INV7_Msk
/********************  Bit definition for PWM0_DFR register
 * ********************/
#define PWM0_DFR_PDR_Pos (0U)
#define PWM0_DFR_PDR_Msk (0x0FL << PWM0_DFR_PDR_Pos)
#define PWM0_DFR_PDR PWM0_DFR_PDR_Msk

#define PWM0_DFR_PDF_Pos (8U)
#define PWM0_DFR_PDF_Msk (0x0FL << PWM0_DFR_PDF_Pos)
#define PWM0_DFR_PDF PWM0_DFR_PDF_Msk
/********************  Bit definition for PWM0_FLT register
 * ********************/
#define PWM0_FLT_FLTDT_Pos (0U)
#define PWM0_FLT_FLTDT_Msk (0x03L << PWM0_FLT_FLTDT_Pos)
#define PWM0_FLT_FLTDT PWM0_FLT_FLTDT_Msk

#define PWM0_FLT_FLTTV_Pos (4U)
#define PWM0_FLT_FLTTV_Msk (0x1L << PWM0_FLT_FLTTV_Pos)
#define PWM0_FLT_FLTTV PWM0_FLT_FLTTV_Msk

#define PWM0_FLT_FLTMD_Pos (5U)
#define PWM0_FLT_FLTMD_Msk (0x1L << PWM0_FLT_FLTMD_Pos)
#define PWM0_FLT_FLTMD PWM0_FLT_FLTMD_Msk

#define PWM0_FLT_FLTEN_Pos (7U)
#define PWM0_FLT_FLTEN_Msk (0x1L << PWM0_FLT_FLTEN_Pos)
#define PWM0_FLT_FLTEN PWM0_FLT_FLTEN_Msk
/******************************************************************************/
/*                                                                            */
/*                      LEDPWM
 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PWM1_CON register
 * ********************/
#define LEDPWM_CON_PWMCLK_Pos (0U)
#define LEDPWM_CON_PWMCLK_Msk (0x7L << LEDPWM_CON_PWMCLK_Pos)
#define LEDPWM_CON_PWMCLK LEDPWM_CON_PWMCLK_Msk

#define LEDPWM_CON_PWMMD0_Pos (6U)
#define LEDPWM_CON_PWMMD0_Msk (0x1L << LEDPWM_CON_PWMMD0_Pos)
#define LEDPWM_CON_PWMMD0 LEDPWM_CON_PWMMD0_Msk

#define LEDPWM_CON_ENPWM_Pos (7U)
#define LEDPWM_CON_ENPWM_Msk (0x1L << LEDPWM_CON_ENPWM_Pos)
#define LEDPWM_CON_ENPWM LEDPWM_CON_ENPWM_Msk

#define LEDPWM_CON_INTEN_Pos (8U)
#define LEDPWM_CON_INTEN_Msk (0x1L << LEDPWM_CON_INTEN_Pos)
#define LEDPWM_CON_INTEN LEDPWM_CON_INTEN_Msk
/********************  Bit definition for LEDPWM_STS register
 * ********************/
#define LEDPWM_STS_PWMIF_Pos (0U)
#define LEDPWM_STS_PWMIF_Msk (0x1L << LEDPWM_CON_PWMCLK_Pos)
#define LEDPWM_STS_PWMIF LEDPWM_CON_PWMCLK_Msk
/******************************************************************************/
/*                                                                            */
/*                      TWI_QSPIx
 */
/*                                                                            */
/******************************************************************************/
/***************  Bit definition for TWI_QSPIx_CON register  ******************/
#define TWI_QSPIx_CON_STRETCH_Pos (0U)
#define TWI_QSPIx_CON_STRETCH_Msk (0x1L << TWI_QSPIx_CON_STRETCH_Pos)
#define TWI_QSPIx_CON_STRETCH TWI_QSPIx_CON_STRETCH_Msk

#define TWI_QSPIx_CON_AA_Pos (1U)
#define TWI_QSPIx_CON_AA_Msk (0x1L << TWI_QSPIx_CON_AA_Pos)
#define TWI_QSPIx_CON_AA TWI_QSPIx_CON_AA_Msk

#define TWI_QSPIx_CON_STOP_Pos (4U)
#define TWI_QSPIx_CON_STOP_Msk (0x1L << TWI_QSPIx_CON_STOP_Pos)
#define TWI_QSPIx_CON_STOP TWI_QSPIx_CON_STOP_Msk

#define TWI_QSPIx_CON_START_Pos (5U)
#define TWI_QSPIx_CON_START_Msk (0x1L << TWI_QSPIx_CON_START_Pos)
#define TWI_QSPIx_CON_START TWI_QSPIx_CON_START_Msk

#define TWI_QSPIx_CON_QTWEN_Pos (7U)
#define TWI_QSPIx_CON_QTWEN_Msk (0x1L << TWI_QSPIx_CON_QTWEN_Pos)
#define TWI_QSPIx_CON_QTWEN TWI_QSPIx_CON_QTWEN_Msk

#define TWI_QSPIx_CON_QTWCK_Pos (8U)
#define TWI_QSPIx_CON_QTWCK_Msk (0x0FL << TWI_QSPIx_CON_QTWCK_Pos)
#define TWI_QSPIx_CON_QTWCK TWI_QSPIx_CON_QTWCK_Msk

#define TWI_QSPIx_CON_SPOS_Pos (13U)
#define TWI_QSPIx_CON_SPOS_Msk (0x3L << TWI_QSPIx_CON_SPOS_Pos)
#define TWI_QSPIx_CON_SPOS TWI_QSPIx_CON_SPOS_Msk

#define TWI_QSPIx_CON_SMSTR_Pos (16U)
#define TWI_QSPIx_CON_SMSTR_Msk (0x1L << TWI_QSPIx_CON_SMSTR_Pos)
#define TWI_QSPIx_CON_SMSTR TWI_QSPIx_CON_SMSTR_Msk

#define TWI_QSPIx_CON_CLKONLY_Pos (17U)
#define TWI_QSPIx_CON_CLKONLY_Msk (0x1L << TWI_QSPIx_CON_CLKONLY_Pos)
#define TWI_QSPIx_CON_CLKONLY TWI_QSPIx_CON_CLKONLY_Msk

#define TWI_QSPIx_CON_DORD_Pos (18U)
#define TWI_QSPIx_CON_DORD_Msk (0x1L << TWI_QSPIx_CON_DORD_Pos)
#define TWI_QSPIx_CON_DORD TWI_QSPIx_CON_DORD_Msk

#define TWI_QSPIx_CON_CPHA_Pos (19U)
#define TWI_QSPIx_CON_CPHA_Msk (0x1L << TWI_QSPIx_CON_CPHA_Pos)
#define TWI_QSPIx_CON_CPHA TWI_QSPIx_CON_CPHA_Msk

#define TWI_QSPIx_CON_CPOL_Pos (20U)
#define TWI_QSPIx_CON_CPOL_Msk (0x1L << TWI_QSPIx_CON_CPOL_Pos)
#define TWI_QSPIx_CON_CPOL TWI_QSPIx_CON_CPOL_Msk

#define TWI_QSPIx_CON_RW_Pos (21U)
#define TWI_QSPIx_CON_RW_Msk (0x1L << TWI_QSPIx_CON_RW_Pos)
#define TWI_QSPIx_CON_RW TWI_QSPIx_CON_RW_Msk

#define TWI_QSPIx_CON_MODE_Pos (22U)
#define TWI_QSPIx_CON_MODE_Msk (0x3L << TWI_QSPIx_CON_MODE_Pos)
#define TWI_QSPIx_CON_MDOE TWI_QSPIx_CON_MODE_Msk

#define TWI_QSPIx_CON_STRDIR_Pos (24U)
#define TWI_QSPIx_CON_STRDIR_Msk (0x1L << TWI_QSPIx_CON_STRDIR_Pos)
#define TWI_QSPIx_CON_STRDIR TWI_QSPIx_CON_STRDIR_Msk

#define TWI_QSPIx_CON_STRTEN_Pos (25U)
#define TWI_QSPIx_CON_STRTEN_Msk (0x1L << TWI_QSPIx_CON_STRTEN_Pos)
#define TWI_QSPIx_CON_STRTEN TWI_QSPIx_CON_STRTEN_Msk

#define TWI_QSPIx_CON_STRREN_Pos (26U)
#define TWI_QSPIx_CON_STRREN_Msk (0x1L << TWI_QSPIx_CON_STRREN_Pos)
#define TWI_QSPIx_CON_STRREN TWI_QSPIx_CON_STRREN_Msk

#define TWI_QSPIx_CON_SSHIFT_Pos (27U)
#define TWI_QSPIx_CON_SSHIFT_Msk (0x1L << TWI_QSPIx_CON_SSHIFT_Pos)
#define TWI_QSPIx_CON_SSHIFT TWI_QSPIx_CON_SSHIFT_Msk

#define TWI_QSPIx_CON_DWIDTH_Pos (28U)
#define TWI_QSPIx_CON_DWIDTH_Msk (0x3L << TWI_QSPIx_CON_DWIDTH_Pos)
#define TWI_QSPIx_CON_DWIDTH TWI_QSPIx_CON_DWIDTH_Msk

#define TWI_QSPIx_CON_LMODE_Pos (30U)
#define TWI_QSPIx_CON_LMODE_Msk ((unsigned int)0x3L << TWI_QSPIx_CON_LMODE_Pos)
#define TWI_QSPIx_CON_LMODE TWI_QSPIx_CON_LMODE_Msk
/********************  Bit definition for TWI_QSPIx_STS register
 * ********************/
#define TWI_QSPIx_STS_QTWIF_Pos (0U)
#define TWI_QSPIx_STS_QTWIF_Msk (0x1L << TWI_QSPIx_STS_QTWIF_Pos)
#define TWI_QSPIx_STS_QTWIF TWI_QSPIx_STS_QTWIF_Msk

#define TWI_QSPIx_STS_RXNEIF_Pos (1U)
#define TWI_QSPIx_STS_RXNEIF_Msk (0x1L << TWI_QSPIx_STS_RXNEIF_Pos)
#define TWI_QSPIx_STS_RXNEIF TWI_QSPIx_STS_RXNEIF_Msk

#define TWI_QSPIx_STS_TXEIF_Pos (2U)
#define TWI_QSPIx_STS_TXEIF_Msk (0x1L << TWI_QSPIx_STS_TXEIF_Pos)
#define TWI_QSPIx_STS_TXEIF TWI_QSPIx_STS_TXEIF_Msk

#define TWI_QSPIx_STS_RXFIF_Pos (3U)
#define TWI_QSPIx_STS_RXFIF_Msk (0x1L << TWI_QSPIx_STS_RXFIF_Pos)
#define TWI_QSPIx_STS_RXFIF TWI_QSPIx_STS_RXFIF_Msk

#define TWI_QSPIx_STS_RXHIF_Pos (4U)
#define TWI_QSPIx_STS_RXHIF_Msk (0x1L << TWI_QSPIx_STS_RXHIF_Pos)
#define TWI_QSPIx_STS_RXHIF TWI_QSPIx_STS_RXHIF_Msk

#define TWI_QSPIx_STS_TXHIF_Pos (5U)
#define TWI_QSPIx_STS_TXHIF_Msk (0x1L << TWI_QSPIx_STS_TXHIF_Pos)
#define TWI_QSPIx_STS_TXHIF TWI_QSPIx_STS_TXHIF_Msk

#define TWI_QSPIx_STS_DLUFIF_Pos (6U)
#define TWI_QSPIx_STS_DLUFIF_Msk (0x1L << TWI_QSPIx_STS_DLUFIF_Pos)
#define TWI_QSPIx_STS_DLUFIF TWI_QSPIx_STS_DLUFIF_Msk

#define TWI_QSPIx_STS_WCOL_Pos (7U)
#define TWI_QSPIx_STS_WCOL_Msk (0x1L << TWI_QSPIx_STS_WCOL_Pos)
#define TWI_QSPIx_STS_WCOL TWI_QSPIx_STS_WCOL_Msk

#define TWI_QSPIx_STS_STATE_Pos (8U)
#define TWI_QSPIx_STS_STATE_Msk (0x7L << TWI_QSPIx_STS_STATE_Pos)
#define TWI_QSPIx_STS_STATE TWI_QSPIx_STS_STATE_Msk

#define TWI_QSPIx_STS_TXERXE_Pos (12U)
#define TWI_QSPIx_STS_TXERXE_Msk (0x1L << TWI_QSPIx_STS_TXERXE_Pos)
#define TWI_QSPIx_STS_TXERXE TWI_QSPIx_STS_TXERXE_Msk

#define TWI_QSPIx_STS_GCA_Pos (13U)
#define TWI_QSPIx_STS_GCA_Msk (0x1L << TWI_QSPIx_STS_GCA_Pos)
#define TWI_QSPIx_STS_GCA TWI_QSPIx_STS_GCA_Msk

#define TWI_QSPIx_STS_TMSTR_Pos (14U)
#define TWI_QSPIx_STS_TMSTR_Msk (0x1L << TWI_QSPIx_STS_TMSTR_Pos)
#define TWI_QSPIx_STS_TMSTR TWI_QSPIx_STS_TMSTR_Msk

#define TWI_QSPIx_STS_BUSY_Pos (15U)
#define TWI_QSPIx_STS_BUSY_Msk (0x1L << TWI_QSPIx_STS_BUSY_Pos)
#define TWI_QSPIx_STS_BUSY TWI_QSPIx_STS_BUSY_Msk

#define TWI_QSPIx_STS_NBYTES_Pos (16U)
#define TWI_QSPIx_STS_NBYTES_Msk (0xFFL << TWI_QSPIx_STS_NBYTES_Pos)
#define TWI_QSPIx_STS_NBYTES TWI_QSPIx_STS_NBYTES_Msk

/********************  Bit definition for TWI_QSPIx_ADD register
 * ********************/
#define TWI_QSPIx_ADD_GC_Pos (0U)
#define TWI_QSPIx_ADD_GC_Msk (0x1L << TWI_QSPIx_ADD_GC_Pos)
#define TWI_QSPIx_ADD_GC TWI_QSPIx_ADD_GC_Msk

#define TWI_QSPIx_ADD_QTWADD_Pos (1U)
#define TWI_QSPIx_ADD_QTWADD_Msk (0xFEL << TWI_QSPIx_ADD_QTWADD_Pos)
#define TWI_QSPIx_ADD_QTWADD TWI_QSPIx_ADD_QTWADD_Msk

/********************  Bit definition for TWI_QSPIx_IDE register
 * ********************/
#define TWI_QSPIx_IDE_INTEN_Pos (0U)
#define TWI_QSPIx_IDE_INTEN_Msk (0x1L << TWI_QSPIx_IDE_INTEN_Pos)
#define TWI_QSPIx_IDE_INTEN TWI_QSPIx_IDE_INTEN_Msk

#define TWI_QSPIx_IDE_RXNEIE_Pos (1U)
#define TWI_QSPIx_IDE_RXNEIE_Msk (0x1L << TWI_QSPIx_IDE_RXNEIE_Pos)
#define TWI_QSPIx_IDE_RXNEIE TWI_QSPIx_IDE_RXNEIE_Msk

#define TWI_QSPIx_IDE_TBIE_Pos (2U)
#define TWI_QSPIx_IDE_TBIE_Msk (0x1L << TWI_QSPIx_IDE_TBIE_Pos)
#define TWI_QSPIx_IDE_TBIE TWI_QSPIx_IDE_TBIE_Msk

#define TWI_QSPIx_IDE_RXIE_Pos (3U)
#define TWI_QSPIx_IDE_RXIE_Msk (0x1L << TWI_QSPIx_IDE_RXIE_Pos)
#define TWI_QSPIx_IDE_RXIE TWI_QSPIx_IDE_RXIE_Msk

#define TWI_QSPIx_IDE_RXHIE_Pos (4U)
#define TWI_QSPIx_IDE_RXHIE_Msk (0x1L << TWI_QSPIx_IDE_RXHIE_Pos)
#define TWI_QSPIx_IDE_RXHIE TWI_QSPIx_IDE_RXHIE_Msk

#define TWI_QSPIx_IDE_TXHIE_Pos (5U)
#define TWI_QSPIx_IDE_TXHIE_Msk (0x1L << TWI_QSPIx_IDE_TXHIE_Pos)
#define TWI_QSPIx_IDE_TXHIE TWI_QSPIx_IDE_TXHIE_Msk

#define TWI_QSPIx_IDE_RXDMAEN_Pos (6U)
#define TWI_QSPIx_IDE_RXDMAEN_Msk (0x1L << TWI_QSPIx_IDE_RXDMAEN_Pos)
#define TWI_QSPIx_IDE_RXDMAEN TWI_QSPIx_IDE_RXDMAEN_Msk

#define TWI_QSPIx_IDE_TXDMAEN_Pos (7U)
#define TWI_QSPIx_IDE_TXDMAEN_Msk (0x1L << TWI_QSPIx_IDE_TXDMAEN_Pos)
#define TWI_QSPIx_IDE_TXDMAEN TWI_QSPIx_IDE_TXDMAEN_Msk

#define TWI_QSPIx_IDE_QTWIE_Pos (8U)
#define TWI_QSPIx_IDE_QTWIE_Msk (0x1L << TWI_QSPIx_IDE_QTWIE_Pos)
#define TWI_QSPIx_IDE_QTWIE TWI_QSPIx_IDE_QTWIE_Msk

#define TWI_QSPIx_IDE_DLUFIE_Pos (9U)
#define TWI_QSPIx_IDE_DLUFIE_Msk (0x1L << TWI_QSPIx_IDE_DLUFIE_Pos)
#define TWI_QSPIx_IDE_DLUFIE TWI_QSPIx_IDE_DLUFIE_Msk

/******************************************************************************/
/*                                                                            */
/*                      TWI_SPI
 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for TWI_SPIx_CON register
 * ********************/
#define TWI_SPIx_CON_STRETCH_Pos (0U)
#define TWI_SPIx_CON_STRETCH_Msk (0x1L << TWI_SPIx_CON_STRETCH_Pos)
#define TWI_SPIx_CON_STRETCH TWI_SPIx_CON_STRETCH_Msk

#define TWI_SPIx_CON_AA_Pos (1U)
#define TWI_SPIx_CON_AA_Msk (0x1L << TWI_SPIx_CON_AA_Pos)
#define TWI_SPIx_CON_AA TWI_SPIx_CON_AA_Msk

#define TWI_SPIx_CON_STOP_Pos (4U)
#define TWI_SPIx_CON_STOP_Msk (0x1L << TWI_SPIx_CON_STOP_Pos)
#define TWI_SPIx_CON_STOP TWI_SPIx_CON_STOP_Msk

#define TWI_SPIx_CON_START_Pos (5U)
#define TWI_SPIx_CON_START_Msk (0x1L << TWI_SPIx_CON_START_Pos)
#define TWI_SPIx_CON_START TWI_SPIx_CON_START_Msk

#define TWI_SPIx_CON_QTWEN_Pos (7U)
#define TWI_SPIx_CON_QTWEN_Msk (0x1L << TWI_SPIx_CON_QTWEN_Pos)
#define TWI_SPIx_CON_QTWEN TWI_SPIx_CON_QTWEN_Msk

#define TWI_SPIx_CON_QTWCK_Pos (8U)
#define TWI_SPIx_CON_QTWCK_Msk (0xFL << TWI_SPIx_CON_QTWCK_Pos)
#define TWI_SPIx_CON_QTWCK TWI_SPIx_CON_QTWCK_Msk

#define TWI_SPIx_CON_SPOS_Pos (13U)
#define TWI_SPIx_CON_SPOS_Msk (0x3L << TWI_SPIx_CON_SPOS_Pos)
#define TWI_SPIx_CON_SPOS TWI_SPIx_CON_SPOS_Msk

#define TWI_SPIx_CON_SMSTR_Pos (16U)
#define TWI_SPIx_CON_SMSTR_Msk (0x1L << TWI_SPIx_CON_SMSTR_Pos)
#define TWI_SPIx_CON_SMSTR TWI_SPIx_CON_SMSTR_Msk

#define TWI_SPIx_CON_DORD_Pos (18U)
#define TWI_SPIx_CON_DORD_Msk (0x1L << TWI_SPIx_CON_DORD_Pos)
#define TWI_SPIx_CON_DORD TWI_SPIx_CON_DORD_Msk

#define TWI_SPIx_CON_CPHA_Pos (19U)
#define TWI_SPIx_CON_CPHA_Msk (0x1L << TWI_SPIx_CON_CPHA_Pos)
#define TWI_SPIx_CON_CPHA TWI_SPIx_CON_CPHA_Msk

#define TWI_SPIx_CON_CPOL_Pos (20U)
#define TWI_SPIx_CON_CPOL_Msk (0x1L << TWI_SPIx_CON_CPOL_Pos)
#define TWI_SPIx_CON_CPOL TWI_SPIx_CON_CPOL_Msk

#define TWI_SPIx_CON_RW_Pos (21U)
#define TWI_SPIx_CON_RW_Msk (0x1L << TWI_SPIx_CON_RW_Pos)
#define TWI_SPIx_CON_RW TWI_SPIx_CON_RW_Msk

#define TWI_SPIx_CON_MODE_Pos (22U)
#define TWI_SPIx_CON_MODE_Msk (0x3L << TWI_SPIx_CON_MODE_Pos)
#define TWI_SPIx_CON_MODE TWI_SPIx_CON_MODE_Msk

#define TWI_SPIx_CON_DWIDTH_Pos (28U)
#define TWI_SPIx_CON_DWIDTH_Msk (0x3L << TWI_SPIx_CON_DWIDTH_Pos)
#define TWI_SPIx_CON_DWIDTH TWI_SPIx_CON_DWIDTH_Msk
/********************  Bit definition for TWI_SPIx_STS register
 * ********************/
#define TWI_SPIx_STS_QTWIF_Pos (0U)
#define TWI_SPIx_STS_QTWIF_Msk (0x1L << TWI_SPIx_STS_QTWIF_Pos)
#define TWI_SPIx_STS_QTWIF TWI_SPIx_STS_QTWIF_Msk

#define TWI_SPIx_STS_TXEIF_Pos (2U)
#define TWI_SPIx_STS_TXEIF_Msk (0x1L << TWI_SPIx_STS_TXEIF_Pos)
#define TWI_SPIx_STS_TXEIF TWI_SPIx_STS_TXEIF_Msk

#define TWI_SPIx_STS_WCOL_Pos (7U)
#define TWI_SPIx_STS_WCOL_Msk (0x1L << TWI_SPIx_STS_WCOL_Pos)
#define TWI_SPIx_STS_WCOL TWI_SPIx_STS_WCOL_Msk

#define TWI_SPIx_STS_STATE_Pos (8U)
#define TWI_SPIx_STS_STATE_Msk (0x7L << TWI_SPIx_STS_STATE_Pos)
#define TWI_SPIx_STS_STATE TWI_SPIx_STS_STATE_Msk

#define TWI_SPIx_STS_TXnERXnE_Pos (12U)
#define TWI_SPIx_STS_TXnERXnE_Msk (0x1L << TWI_SPIx_STS_TXnERXnE_Pos)
#define TWI_SPIx_STS_TXnERXnE TWI_SPIx_STS_TXnERXnE_Msk

#define TWI_SPIx_STS_GCA_Pos (13U)
#define TWI_SPIx_STS_GCA_Msk (0x1L << TWI_SPIx_STS_GCA_Pos)
#define TWI_SPIx_STS_GCA TWI_SPIx_STS_GCA_Msk

#define TWI_SPIx_STS_TMSTR_Pos (14U)
#define TWI_SPIx_STS_TMSTR_Msk (0x1L << TWI_SPIx_STS_TMSTR_Pos)
#define TWI_SPIx_STS_TMSTR TWI_SPIx_STS_TMSTR_Msk

#define TWI_SPIx_STS_NBYTES_Pos (16U)
#define TWI_SPIx_STS_NBYTES_Msk (0xFFL << TWI_SPIx_STS_NBYTES_Pos)
#define TWI_SPIx_STS_NBYTES TWI_SPIx_STS_NBYTES_Msk
/********************  Bit definition for QTWI_SPIx_ADD register
 * ********************/
#define TWI_SPIx_ADD_QTWADD_Pos (0U)
#define TWI_SPIx_ADD_QTWADD_Msk (0xFFL << TWI_SPIx_ADD_QTWADD_Pos)
#define TWI_SPIx_ADD_QTWADD TWI_SPIx_ADD_QTWADD_Msk
/********************  Bit definition for QTWI_SPIx_DATA register
 * ********************/
#define TWI_SPIx_DATA_QTWDAT_Pos (0U)
#define TWI_SPIx_DATA_QTWDAT_Msk (0xFFFFL << TWI_SPIx_DATA_QTWDAT_Pos)
#define TWI_SPIx_DATA_QTWDAT TWI_SPIx_DATA_QTWDAT_Msk
/********************  Bit definition for QTWI_SPIx_IDE register
 * ********************/
#define TWI_SPIx_IDE_INTEN_Pos (0U)
#define TWI_SPIx_IDE_INTEN_Msk (0x1 << TWI_SPIx_IDE_INTEN_Pos)
#define TWI_SPIx_IDE_INTEN TWI_SPIx_IDE_INTEN_Msk

#define TWI_SPIx_IDE_TBIE_Pos (2U)
#define TWI_SPIx_IDE_TBIE_Msk (0x1 << TWI_SPIx_IDE_TBIE_Pos)
#define TWI_SPIx_IDE_TBIE TWI_SPIx_IDE_TBIE_Msk

#define TWI_SPIx_IDE_RXDMAEN_Pos (6U)
#define TWI_SPIx_IDE_RXDMAEN_Msk (0x1 << TWI_SPIx_IDE_RXDMAEN_Pos)
#define TWI_SPIx_IDE_RXDMAEN TWI_SPIx_IDE_RXDMAEN_Msk

#define TWI_SPIx_IDE_TXDMAEN_Pos (7U)
#define TWI_SPIx_IDE_TXDMAEN_Msk (0x1 << TWI_SPIx_IDE_TXDMAEN_Pos)
#define TWI_SPIx_IDE_TXDMAEN TWI_SPIx_IDE_TXDMAEN_Msk
/******************************************************************************/
/*                                                                            */
/*                      TIM
 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for TIM_CON register ********************/
#define TIM_CON_CPRL_Pos (0U)
#define TIM_CON_CPRL_Msk (0x1L << TIM_CON_CPRL_Pos)
#define TIM_CON_CPRL TIM_CON_CPRL_Msk

#define TIM_CON_CTSEL_Pos (1U)
#define TIM_CON_CTSEL_Msk (0x1L << TIM_CON_CTSEL_Pos)
#define TIM_CON_CTSEL TIM_CON_CTSEL_Msk

#define TIM_CON_EXENR_Pos (2U)
#define TIM_CON_EXENR_Msk (0x1L << TIM_CON_EXENR_Pos)
#define TIM_CON_EXENR TIM_CON_EXENR_Msk

#define TIM_CON_EXENF_Pos (3U)
#define TIM_CON_EXENF_Msk (0x1L << TIM_CON_EXENF_Pos)
#define TIM_CON_EXENF TIM_CON_EXENF_Msk

#define TIM_CON_FSEL_Pos (4U)
#define TIM_CON_FSEL_Msk (0x1L << TIM_CON_FSEL_Pos)
#define TIM_CON_FSEL TIM_CON_FSEL_Msk

#define TIM_CON_EXENX_Pos (5U)
#define TIM_CON_EXENX_Msk (0x1L << TIM_CON_EXENX_Pos)
#define TIM_CON_EXENX TIM_CON_EXENX_Msk

#define TIM_CON_DEC_Pos (6U)
#define TIM_CON_DEC_Msk (0x1L << TIM_CON_DEC_Pos)
#define TIM_CON_DEC TIM_CON_DEC_Msk

#define TIM_CON_TR_Pos (7U)
#define TIM_CON_TR_Msk (0x1L << TIM_CON_TR_Pos)
#define TIM_CON_TR TIM_CON_TR_Msk

#define TIM_CON_TIMCLK_Pos (8U)
#define TIM_CON_TIMCLK_Msk (0x7L << TIM_CON_TIMCLK_Pos)
#define TIM_CON_TIMCLK TIM_CON_TIMCLK_Msk

#define TIM_CON_INVNB_Pos (11U)
#define TIM_CON_INVNB_Msk (0x1L << TIM_CON_INVNB_Pos)
#define TIM_CON_INVNB TIM_CON_INVNB_Msk

#define TIM_CON_INVNA_Pos (12U)
#define TIM_CON_INVNA_Msk (0x1L << TIM_CON_INVNA_Pos)
#define TIM_CON_INVNA TIM_CON_INVNA_Msk

#define TIM_CON_EPWMNB_Pos (13U)
#define TIM_CON_EPWMNB_Msk (0x1L << TIM_CON_EPWMNB_Pos)
#define TIM_CON_EPWMNB TIM_CON_EPWMNB_Msk

#define TIM_CON_EPWMNA_Pos (14U)
#define TIM_CON_EPWMNA_Msk (0x1L << TIM_CON_EPWMNA_Pos)
#define TIM_CON_EPWMNA TIM_CON_EPWMNA_Msk

#define TIM_CON_TXOE_Pos (15U)
#define TIM_CON_TXOE_Msk (0x1L << TIM_CON_TXOE_Pos)
#define TIM_CON_TXOE TIM_CON_TXOE_Msk

#define TIM_CON_SPOS_Pos (19U)
#define TIM_CON_SPOS_Msk (0x1L << TIM_CON_SPOS_Pos)
#define TIM_CON_SPOS TIM_CON_SPOS_Msk
/********************  Bit definition for TIM_STS register ********************/
#define TIM_STS_TIF_Pos (0U)
#define TIM_STS_TIF_Msk (0x1L << TIM_STS_TIF_Pos)
#define TIM_STS_TIF TIM_STS_TIF_Msk

#define TIM_STS_EXIR_Pos (1U)
#define TIM_STS_EXIR_Msk (0x1L << TIM_STS_EXIR_Pos)
#define TIM_STS_EXIR TIM_STS_EXIR_Msk

#define TIM_STS_EXIF_Pos (2U)
#define TIM_STS_EXIF_Msk (0x1L << TIM_STS_EXIF_Pos)
#define TIM_STS_EXIF TIM_STS_EXIF_Msk
/********************  Bit definition for TIM_IDE register ********************/
#define TIM_IDE_INTEN_Pos (0U)
#define TIM_IDE_INTEN_Msk (0x1L << TIM_IDE_INTEN_Pos)
#define TIM_IDE_INTEN TIM_IDE_INTEN_Msk

#define TIM_IDE_TIE_Pos (1U)
#define TIM_IDE_TIE_Msk (0x1L << TIM_IDE_TIE_Pos)
#define TIM_IDE_TIE TIM_IDE_TIE_Msk

#define TIM_IDE_EXIRE_Pos (2U)
#define TIM_IDE_EXIRE_Msk (0x1L << TIM_IDE_EXIRE_Pos)
#define TIM_IDE_EXIRE TIM_IDE_EXIRE_Msk

#define TIM_IDE_EXIFE_Pos (3U)
#define TIM_IDE_EXIFE_Msk (0x1L << TIM_IDE_EXIFE_Pos)
#define TIM_IDE_EXIFE TIM_IDE_EXIFE_Msk

#define TIM_IDE_TIDE_Pos (4U)
#define TIM_IDE_TIDE_Msk (0x1L << TIM_IDE_TIDE_Pos)
#define TIM_IDE_TIDE TIM_IDE_TIDE_Msk

#define TIM_IDE_CAPRDE_Pos (5U)
#define TIM_IDE_CAPRDE_Msk (0x1L << TIM_IDE_CAPRDE_Pos)
#define TIM_IDE_CAPRDE TIM_IDE_CAPRDE_Msk

#define TIM_IDE_CAPFDE_Pos (6U)
#define TIM_IDE_CAPFDE_Msk (0x1L << TIM_IDE_CAPFDE_Pos)
#define TIM_IDE_CAPFDE TIM_IDE_CAPFDE_Msk
/******************************************************************************/
/*                                                                            */
/*                      TK
 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for TK_CON register  ********************/
#define TK_CON_TRIG_Pos (0U)
#define TK_CON_TRIG_Msk (0x1L << TK_CON_TRIG_Pos)
#define TK_CON_TRIG TK_CON_TRIG_Msk

#define TK_CON_TKIF_Pos (1U)
#define TK_CON_TKIF_Msk (0x1L << TK_CON_TKIF_Pos)
#define TK_CON_TKIF TK_CON_TKIF_Msk

#define TK_CON_INTEN_Pos (4U)
#define TK_CON_INTEN_Msk (0x1L << TK_CON_INTEN_Pos)
#define TK_CON_INTEN TK_CON_INTEN_Msk

#define TK_CON_PRSC_Pos (5U)
#define TK_CON_PRSC_Msk (0x1L << TK_CON_PRSC_Pos)
#define TK_CON_PRSC TK_CON_PRSC_Msk

#define TK_CON_PRS_Pos (6U)
#define TK_CON_PRS_Msk (0x1L << TK_CON_PRS_Pos)
#define TK_CON_PRS TK_CON_PRS_Msk

#define TK_CON_ENTKS_Pos (7U)
#define TK_CON_ENTKS_Msk (0x1L << TK_CON_ENTKS_Pos)
#define TK_CON_ENTKS TK_CON_ENTKS_Msk

#define TK_CON_TKCKS_Pos (8U)
#define TK_CON_TKCKS_Msk (0x1L << TK_CON_TKCKS_Pos)
#define TK_CON_TKCKS TK_CON_TKCKS_Msk

#define TK_CON_CTIME_Pos (12U)
#define TK_CON_CTIME_Msk (0x0FL << TK_CON_TKCKS_Pos)
#define TK_CON_CTIME TK_CON_TKCKS_Msk

#define TK_CON_TKMOD_Pos (16U)
#define TK_CON_TKMOD_Msk (0x1L << TK_CON_TKMOD_Pos)
#define TK_CON_TKMOD TK_CON_TKMOD_Msk

#define TK_CON_TKSCN_Pos (17U)
#define TK_CON_TKSCN_Msk (0x7L << TK_CON_TKSCN_Pos)
#define TK_CON_TKSCN TK_CON_TKSCN_Msk

#define TK_CON_RESC_Pos (22U)
#define TK_CON_RESC_Msk (0x3L << TK_CON_TKCKS_Pos)
#define TK_CON_RESC TK_CON_TKCKS_Msk

/******************************************************************************/
/*                                                                            */
/*                      UART
 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for UART_CON register
 * ********************/
#define UART_CON_SM01_Pos (0U)
#define UART_CON_SM01_Msk (0x3L << UART_CON_SM01_Pos)
#define UART_CON_SM01 UART_CON_SM01_Msk

#define UART_CON_SM2_Pos (2U)
#define UART_CON_SM2_Msk (0x1L << UART_CON_SM2_Pos)
#define UART_CON_SM2 UART_CON_SM2_Msk

#define UART_CON_PERSCALER_Pos (4U)
#define UART_CON_PERSCALER_Msk (0x1L << UART_CON_PERSCALER_Pos)
#define UART_CON_PERSCALER UART_CON_PERSCALER_Msk

#define UART_CON_RXEN_Pos (6U)
#define UART_CON_RXEN_Msk (0x1L << UART_CON_RXEN_Pos)
#define UART_CON_RXEN UART_CON_RXEN_Msk

#define UART_CON_TXEN_Pos (7U)
#define UART_CON_TXEN_Msk (0x1L << UART_CON_TXEN_Pos)
#define UART_CON_TXEN UART_CON_TXEN_Msk

#define UART_CON_FUNCSEL_Pos (8U)
#define UART_CON_FUNCSEL_Msk (0x1L << UART_CON_FUNCSEL_Pos)
#define UART_CON_FUNCSEL UART_CON_FUNCSEL_Msk

#define UART_CON_SPOS_Pos (13U)
#define UART_CON_SPOS_Msk (0x3L << UART_CON_SPOS_Pos)
#define UART_CON_SPOS UART_CON_SPOS_Msk

#define UART_CON_SLVEN_Pos (16U)
#define UART_CON_SLVEN_Msk (0x1L << UART_CON_SLVEN_Pos)
#define UART_CON_SLVEN UART_CON_SLVEN_Msk

#define UART_CON_SLVAREN_Pos (17U)
#define UART_CON_SLVAREN_Msk (0x1L << UART_CON_SLVAREN_Pos)
#define UART_CON_SLVAREN UART_CON_SLVAREN_Msk

#define UART_CON_LBDL_Pos (18U)
#define UART_CON_LBDL_Msk (0x1L << UART_CON_LBDL_Pos)
#define UART_CON_LBDL UART_CON_LBDL_Msk

#define UART_CON_BKTR_Pos (24U)
#define UART_CON_BKTR_Msk (0x1L << UART_CON_BKTR_Pos)
#define UART_CON_BKTR UART_CON_BKTR_Msk

#define UART_CON_BKSIZE_Pos (26U)
#define UART_CON_BKSIZE_Msk (0x1L << UART_CON_BKSIZE_Pos)
#define UART_CON_BKSIZE UART_CON_BKSIZE_Msk

/********************  Bit definition for UART_STS register
 * ********************/
#define UART_STS_RXIF_Pos (0U)
#define UART_STS_RXIF_Msk (0x1L << UART_STS_RXIF_Pos)
#define UART_STS_RXIF UART_STS_RXIF_Msk

#define UART_STS_TXIF_Pos (1U)
#define UART_STS_TXIF_Msk (0x1L << UART_STS_TXIF_Pos)
#define UART_STS_TXIF UART_STS_TXIF_Msk

#define UART_STS_WKIF_Pos (4U)
#define UART_STS_WKIF_Msk (0x1L << UART_STS_WKIF_Pos)
#define UART_STS_WKIF UART_STS_WKIF_Msk

#define UART_STS_BKIF_Pos (8U)
#define UART_STS_BKIF_Msk (0x1L << UART_STS_BKIF_Pos)
#define UART_STS_BKIF UART_STS_BKIF_Msk

#define UART_STS_SLVHEIF_Pos (9U)
#define UART_STS_SLVHEIF_Msk (0x1L << UART_STS_SLVHEIF_Pos)
#define UART_STS_SLVHEIF UART_STS_SLVHEIF_Msk

#define UART_STS_SLVSYNIF_Pos (10U)
#define UART_STS_SLVSYNIF_Msk (0x1L << UART_STS_SLVSYNIF_Pos)
#define UART_STS_SLVSYNIF UART_STS_SLVSYNIF_Msk

#define UART_STS_SYNCIF_Pos (11U)
#define UART_STS_SYNCIF_Msk (0x1L << UART_STS_SYNCIF_Pos)
#define UART_STS_SYNCIF UART_STS_SYNCIF_Msk
/********************  Bit definition for UART_IDE register
 * ********************/
#define UART_IDE_INTEN_Pos (0U)
#define UART_IDE_INTEN_Msk (0x1L << UART_IDE_INTEN_Pos)
#define UART_IDE_INTEN UART_IDE_INTEN_Msk

#define UART_IDE_RXIE_Pos (1U)
#define UART_IDE_RXIE_Msk (0x1L << UART_IDE_RXIE_Pos)
#define UART_IDE_RXIE UART_IDE_RXIE_Msk

#define UART_IDE_TXIE_Pos (2U)
#define UART_IDE_TXIE_Msk (0x1L << UART_IDE_TXIE_Pos)
#define UART_IDE_TXIE UART_IDE_TXIE_Msk

#define UART_IDE_WKIE_Pos (4U)
#define UART_IDE_WKIE_Msk (0x1L << UART_IDE_WKIE_Pos)
#define UART_IDE_WKIE UART_IDE_WKIE_Msk

#define UART_IDE_RXDMAEN_Pos (6U)
#define UART_IDE_RXDMAEN_Msk (0x1L << UART_IDE_RXDMAEN_Pos)
#define UART_IDE_RXDMAEN UART_IDE_RXDMAEN_Msk

#define UART_IDE_TXDMAEN_Pos (7U)
#define UART_IDE_TXDMAEN_Msk (0x1L << UART_IDE_TXDMAEN_Pos)
#define UART_IDE_TXDMAEN UART_IDE_TXDMAEN_Msk

#define UART_IDE_BKIE_Pos (8U)
#define UART_IDE_BKIE_Msk (0x1L << UART_IDE_BKIE_Pos)
#define UART_IDE_BKIE UART_IDE_BKIE_Msk

#define UART_IDE_SLVHEIE_Pos (9U)
#define UART_IDE_SLVHEIE_Msk (0x1L << UART_IDE_SLVHEIE_Pos)
#define UART_IDE_SLVHEIE UART_IDE_SLVHEIE_Msk

#define UART_IDE_SVNCIE_Pos (11U)
#define UART_IDE_SVNCIE_Msk (0x1L << UART_IDE_SVNCIE_Pos)
#define UART_IDE_SVNCIE UART_IDE_SVNCIE_Msk

/******************************************************************************/
/*                                                                            */
/*                      WDT
 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for WDT_CON register ********************/
#define WDT_CON_CLRWDT_Pos (0U)
#define WDT_CON_CLRWDT_Msk (0x1L << WDT_CON_CLRWDT_Pos)
#define WDT_CON_CLRWDT WDT_CON_CLRWDT_Msk

/********************  Bit definition for WDT_CFG register ********************/
#define WDT_CFG_WDTCKS_Pos (0U)
#define WDT_CFG_WDTCKS_Msk (0x7L << WDT_CFG_WDTCKS_Pos)
#define WDT_CFG_WDTCKS WDT_CFG_WDTCKS_Msk

/******************************************************************************/
/*                                                                            */
/*                      CAN
 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for CAN_RX_ID register
 * ********************/
#define CAN_RX_ID_SdID_Pos (0U)
#define CAN_RX_ID_SdID_Msk (0x7FFL << CAN_RX_ID_SdID_Pos)
#define CAN_RX_ID_SdID CAN_RX_ID_SdID_Msk

#define CAN_RX_ID_ExID_Pos (0U)
#define CAN_RX_ID_ExID_Msk (0x1FFFFFFFL << CAN_RX_ID_ExID_Pos)
#define CAN_RX_ID_ExID CAN_RX_ID_ExID_Msk

/********************  Bit definition for CAN_RX_CTRL register
 * ********************/
#define CAN_RX_CTRL_DLC_Pos (0U)
#define CAN_RX_CTRL_DLC_Msk (0xFL << CAN_RX_CTRL_DLC_Pos)
#define CAN_RX_CTRL_DLC CAN_RX_CTRL_DLC_Msk

#define CAN_RX_CTRL_BRS_Pos (4U)
#define CAN_RX_CTRL_BRS_Msk (0x1L << CAN_RX_CTRL_BRS_Pos)
#define CAN_RX_CTRL_BRS CAN_RX_CTRL_BRS_Msk

#define CAN_RX_CTRL_FDF_Pos (5U)
#define CAN_RX_CTRL_FDF_Msk (0x1L << CAN_RX_CTRL_FDF_Pos)
#define CAN_RX_CTRL_FDF CAN_RX_CTRL_FDF_Msk

#define CAN_RX_CTRL_RTR_Pos (6U)
#define CAN_RX_CTRL_RTR_Msk (0x1L << CAN_RX_CTRL_RTR_Pos)
#define CAN_RX_CTRL_RTR CAN_RX_CTRL_RTR_Msk

#define CAN_RX_CTRL_IDE_Pos (7U)
#define CAN_RX_CTRL_IDE_Msk (0x1L << CAN_RX_CTRL_IDE_Pos)
#define CAN_RX_CTRL_IDE CAN_RX_CTRL_IDE_Msk

#define CAN_RX_CTRL_TX_Pos (12U)
#define CAN_RX_CTRL_TX_Msk (0x1L << CAN_RX_CTRL_TX_Pos)
#define CAN_RX_CTRL_TX CAN_RX_CTRL_TX_Msk

#define CAN_RX_CTRL_KOER_Pos (13U)
#define CAN_RX_CTRL_KOER_Msk (0x1L << CAN_RX_CTRL_KOER_Pos)
#define CAN_RX_CTRL_KOER CAN_RX_CTRL_KOER_Msk

#define CAN_RX_CTRL_CYCLE_TIME_Pos (16U)
#define CAN_RX_CTRL_CYCLE_TIME_Msk (0xFFFFL << CAN_RX_CTRL_CYCLE_TIME_Pos)
#define CAN_RX_CTRL_CYCLE_TIME CAN_RX_CTRL_CYCLE_TIME_Msk

/********************  Bit definition for CAN_RBUF register
 * ********************/
#define CAN_RBUF_D1_Pos (0U)
#define CAN_RBUF_D1_Msk (0xFFL << CAN_RBUF_D1_Pos)
#define CAN_RBUF_D1 CAN_RBUF_D1_Msk

#define CAN_RBUF_D2_Pos (8U)
#define CAN_RBUF_D2_Msk (0xFFL << CAN_RBUF_D2_Pos)
#define CAN_RBUF_D2 CAN_RBUF_D2_Msk

#define CAN_RBUF_D3_Pos (16U)
#define CAN_RBUF_D3_Msk (0xFFL << CAN_RBUF_D3_Pos)
#define CAN_RBUF_D3 CAN_RBUF_D3_Msk

#define CAN_RBUF_D4_Pos (24U)
#define CAN_RBUF_D4_Msk (0xFFL << CAN_RBUF_D4_Pos)
#define CAN_RBUF_D4 CAN_RBUF_D4_Msk

/********************  Bit definition for CAN_RTSL register
 * ********************/
#define CAN_RTSL_RTS_Pos (0U)
#define CAN_RTSL_RTS_Msk (0xFFFFFFFFL << CAN_RTSL_RTS_Pos)
#define CAN_RTSL_RTS CAN_RTSL_RTS_Msk

/********************  Bit definition for CAN_RTSH register
 * ********************/
#define CAN_RTSH_RTS_Pos (0U)
#define CAN_RTSH_RTS_Msk (0xFFFFFFFFL << CAN_RTSH_RTS_Pos)
#define CAN_RTSH_RTS CAN_RTSH_RTS_Msk

/********************  Bit definition for CAN_TX_ID register
 * ********************/
#define CAN_TX_ID_SdID_Pos (0U)
#define CAN_TX_ID_SdID_Msk (0x7FFL << CAN_TX_ID_SdID_Pos)
#define CAN_TX_ID_SdID CAN_TX_ID_SdID_Msk

#define CAN_TX_ID_ExID_Pos (0U)
#define CAN_TX_ID_ExID_Msk (0x1FFFFFFFL << CAN_TX_ID_ExID_Pos)
#define CAN_TX_ID_ExID CAN_TX_ID_ExID_Msk

#define CAN_TX_ID_TTSEN_Pos (31U)
#define CAN_TX_ID_TTSEN_Msk (0x1L) << CAN_TX_ID_TTSEN_Pos
#define CAN_TX_ID_TTSEN CAN_TX_ID_TTSEN_Msk

/********************  Bit definition for CAN_TX_CTRL register
 * ********************/
#define CAN_TX_CTRL_DLC_Pos (0U)
#define CAN_TX_CTRL_DLC_Msk (0xFL << CAN_TX_CTRL_DLC_Pos)
#define CAN_TX_CTRL_DLC CAN_TX_CTRL_DLC_Msk

#define CAN_TX_CTRL_BRS_Pos (4U)
#define CAN_TX_CTRL_BRS_Msk (0x1L << CAN_TX_CTRL_BRS_Pos)
#define CAN_TX_CTRL_BRS CAN_TX_CTRL_BRS_Msk

#define CAN_TX_CTRL_FDF_Pos (5U)
#define CAN_TX_CTRL_FDF_Msk (0x1L << CAN_TX_CTRL_FDF_Pos)
#define CAN_TX_CTRL_FDF CAN_TX_CTRL_FDF_Msk

#define CAN_TX_CTRL_RTR_Pos (6U)
#define CAN_TX_CTRL_RTR_Msk (0x1L << CAN_TX_CTRL_RTR_Pos)
#define CAN_TX_CTRL_RTR CAN_TX_CTRL_RTR_Msk

#define CAN_TX_CTRL_IDE_Pos (7U)
#define CAN_TX_CTRL_IDE_Msk (0x1L << CAN_TX_CTRL_IDE_Pos)
#define CAN_TX_CTRL_IDE CAN_TX_CTRL_IDE_Msk

/********************  Bit definition for CAN_TBUF register
 * ********************/
#define CAN_TBUF_D1_Pos (0U)
#define CAN_TBUF_D1_Msk (0xFFL << CAN_TBUF_D1_Pos)
#define CAN_TBUF_D1 CAN_TBUF_D1_Msk

#define CAN_TBUF_D2_Pos (8U)
#define CAN_TBUF_D2_Msk (0xFFL << CAN_TBUF_D2_Pos)
#define CAN_TBUF_D2 CAN_TBUF_D2_Msk

#define CAN_TBUF_D3_Pos (16U)
#define CAN_TBUF_D3_Msk (0xFFL << CAN_TBUF_D3_Pos)
#define CAN_TBUF_D3 CAN_TBUF_D3_Msk

#define CAN_TBUF_D4_Pos (24U)
#define CAN_TBUF_D4_Msk (0xFFL << CAN_TBUF_D4_Pos)
#define CAN_TBUF_D4 CAN_TBUF_D4_Msk

/********************  Bit definition for CAN_TTSL register
 * ********************/
#define CAN_TTSL_RTS_Pos (0U)
#define CAN_TTSL_RTS_Msk (0xFFFFFFFFL << CAN_TTSL_RTS_Pos)
#define CAN_TTSL_RTS CAN_TTSL_RTS_Msk

/********************  Bit definition for CAN_TTSH register
 * ********************/
#define CAN_TTSH_RTS_Pos (0U)
#define CAN_TTSH_RTS_Msk (0xFFFFFFFFL << CAN_TTSH_RTS_Pos)
#define CAN_TTSH_RTS CAN_TTSH_RTS_Msk

/********************  Bit definition for CAN_CFG_STAT register
 * ********************/
#define CAN_CFG_STAT_BUSOFF_Pos (0U)
#define CAN_CFG_STAT_BUSOFF_Msk (0x1L << CAN_CFG_STAT_BUSOFF_Pos)
#define CAN_CFG_STAT_BUSOFF CAN_CFG_STAT_BUSOFF_Msk

#define CAN_CFG_STAT_TACTIVE_Pos (1U)
#define CAN_CFG_STAT_TACTIVE_Msk (0x1L << CAN_CFG_STAT_TACTIVE_Pos)
#define CAN_CFG_STAT_TACTIVE CAN_CFG_STAT_TACTIVE_Msk

#define CAN_CFG_STAT_RACTIVE_Pos (2U)
#define CAN_CFG_STAT_RACTIVE_Msk (0x1L << CAN_CFG_STAT_RACTIVE_Pos)
#define CAN_CFG_STAT_RACTIVE CAN_CFG_STAT_RACTIVE_Msk

#define CAN_CFG_STAT_TSSS_Pos (3U)
#define CAN_CFG_STAT_TSSS_Msk (0x1L << CAN_CFG_STAT_TSSS_Pos)
#define CAN_CFG_STAT_TSSS CAN_CFG_STAT_TSSS_Msk

#define CAN_CFG_STAT_TPSS_Pos (4U)
#define CAN_CFG_STAT_TPSS_Msk (0x1L << CAN_CFG_STAT_TPSS_Pos)
#define CAN_CFG_STAT_TPSS CAN_CFG_STAT_TPSS_Msk

#define CAN_CFG_STAT_TPSS_Pos (4U)
#define CAN_CFG_STAT_TPSS_Msk (0x1L << CAN_CFG_STAT_TPSS_Pos)
#define CAN_CFG_STAT_TPSS CAN_CFG_STAT_TPSS_Msk

#define CAN_CFG_STAT_LBMI_Pos (5U)
#define CAN_CFG_STAT_LBMI_Msk (0x1L << CAN_CFG_STAT_LBMI_Pos)
#define CAN_CFG_STAT_LBMI CAN_CFG_STAT_LBMI_Msk

#define CAN_CFG_STAT_LBME_Pos (6U)
#define CAN_CFG_STAT_LBME_Msk (0x1L << CAN_CFG_STAT_LBME_Pos)
#define CAN_CFG_STAT_LBME CAN_CFG_STAT_LBME_Msk

#define CAN_CFG_STAT_RESET_Pos (7U)
#define CAN_CFG_STAT_RESET_Msk (0x1L << CAN_CFG_STAT_RESET_Pos)
#define CAN_CFG_STAT_RESET CAN_CFG_STAT_RESET_Msk

#define CAN_CFG_STAT_TSA_Pos (8U)
#define CAN_CFG_STAT_TSA_Msk (0x1L << CAN_CFG_STAT_TSA_Pos)
#define CAN_CFG_STAT_TSA CAN_CFG_STAT_TSA_Msk

#define CAN_CFG_STAT_TSALL_Pos (9U)
#define CAN_CFG_STAT_TSALL_Msk (0x1L << CAN_CFG_STAT_TSALL_Pos)
#define CAN_CFG_STAT_TSALL CAN_CFG_STAT_TSALL_Msk

#define CAN_CFG_STAT_TSONE_Pos (10U)
#define CAN_CFG_STAT_TSONE_Msk (0x1L << CAN_CFG_STAT_TSONE_Pos)
#define CAN_CFG_STAT_TSONE CAN_CFG_STAT_TSONE_Msk

#define CAN_CFG_STAT_TPA_Pos (11U)
#define CAN_CFG_STAT_TPA_Msk (0x1L << CAN_CFG_STAT_TPA_Pos)
#define CAN_CFG_STAT_TPA CAN_CFG_STAT_TPA_Msk

#define CAN_CFG_STAT_TPE_Pos (12U)
#define CAN_CFG_STAT_TPE_Msk (0x1L << CAN_CFG_STAT_TPE_Pos)
#define CAN_CFG_STAT_TPE CAN_CFG_STAT_TPE_Msk

#define CAN_CFG_STAT_STBY_Pos (13U)
#define CAN_CFG_STAT_STBY_Msk (0x1L << CAN_CFG_STAT_STBY_Pos)
#define CAN_CFG_STAT_STBY CAN_CFG_STAT_STBY_Msk

#define CAN_CFG_STAT_LOM_Pos (14U)
#define CAN_CFG_STAT_LOM_Msk (0x1L << CAN_CFG_STAT_LOM_Pos)
#define CAN_CFG_STAT_LOM CAN_CFG_STAT_LOM_Msk

#define CAN_CFG_STAT_TBSEL_Pos (15U)
#define CAN_CFG_STAT_TBSEL_Msk (0x1L << CAN_CFG_STAT_TBSEL_Pos)
#define CAN_CFG_STAT_TBSEL CAN_CFG_STAT_TBSEL_Msk

#define CAN_CFG_STAT_TSSTAT_Pos (16U)
#define CAN_CFG_STAT_TSSTAT_Msk (0x3L << CAN_CFG_STAT_TSSTAT_Pos)
#define CAN_CFG_STAT_TSSTAT CAN_CFG_STAT_TSSTAT_Msk

#define CAN_CFG_STAT_TTTBM_Pos (20U)
#define CAN_CFG_STAT_TTTBM_Msk (0x1L << CAN_CFG_STAT_TTTBM_Pos)
#define CAN_CFG_STAT_TTTBM CAN_CFG_STAT_TTTBM_Msk

#define CAN_CFG_STAT_TSMODE_Pos (21U)
#define CAN_CFG_STAT_TSMODE_Msk (0x1L << CAN_CFG_STAT_TSMODE_Pos)
#define CAN_CFG_STAT_TSMODE CAN_CFG_STAT_TSMODE_Msk

#define CAN_CFG_STAT_TSNEXT_Pos (22U)
#define CAN_CFG_STAT_TSNEXT_Msk (0x1L << CAN_CFG_STAT_TSNEXT_Pos)
#define CAN_CFG_STAT_TSNEXT CAN_CFG_STAT_TSNEXT_Msk

#define CAN_CFG_STAT_FD_ISO_Pos (23U)
#define CAN_CFG_STAT_FD_ISO_Msk (0x1L << CAN_CFG_STAT_FD_ISO_Pos)
#define CAN_CFG_STAT_FD_ISO CAN_CFG_STAT_FD_ISO_Msk

#define CAN_CFG_STAT_RSTAT_Pos (24U)
#define CAN_CFG_STAT_RSTAT_Msk (0x3L << CAN_CFG_STAT_RSTAT_Pos)
#define CAN_CFG_STAT_RSTAT CAN_CFG_STAT_RSTAT_Msk

#define CAN_CFG_STAT_RBALL_Pos (27U)
#define CAN_CFG_STAT_RBALL_Msk (0x1L << CAN_CFG_STAT_RBALL_Pos)
#define CAN_CFG_STAT_RBALL CAN_CFG_STAT_RBALL_Msk

#define CAN_CFG_STAT_RREL_Pos (28U)
#define CAN_CFG_STAT_RREL_Msk (0x1L << CAN_CFG_STAT_RREL_Pos)
#define CAN_CFG_STAT_RREL CAN_CFG_STAT_RREL_Msk

#define CAN_CFG_STAT_ROV_Pos (29U)
#define CAN_CFG_STAT_ROV_Msk (0x1L << CAN_CFG_STAT_ROV_Pos)
#define CAN_CFG_STAT_ROV CAN_CFG_STAT_ROV_Msk

#define CAN_CFG_STAT_ROM_Pos (30U)
#define CAN_CFG_STAT_ROM_Msk (0x1L << CAN_CFG_STAT_ROM_Pos)
#define CAN_CFG_STAT_ROM CAN_CFG_STAT_ROM_Msk

#define CAN_CFG_STAT_SACK_Pos (31U)
#define CAN_CFG_STAT_SACK_Msk (0x1L << CAN_CFG_STAT_SACK_Pos)
#define CAN_CFG_STAT_SACK CAN_CFG_STAT_SACK_Msk

/********************  Bit definition for CAN_RTIE register
 * ********************/
#define CAN_RTIE_TSFF_Pos (0U)
#define CAN_RTIE_TSFF_Msk (0x1L << CAN_RTIE_TSFF_Pos)
#define CAN_RTIE_TSFF CAN_RTIE_TSFF_Msk

#define CAN_RTIE_EIE_Pos (1U)
#define CAN_RTIE_EIE_Msk (0x1L << CAN_RTIE_EIE_Pos)
#define CAN_RTIE_EIE CAN_RTIE_EIE_Msk

#define CAN_RTIE_TSIE_Pos (2U)
#define CAN_RTIE_TSIE_Msk (0x1L << CAN_RTIE_TSIE_Pos)
#define CAN_RTIE_TSIE CAN_RTIE_TSIE_Msk

#define CAN_RTIE_TPIE_Pos (3U)
#define CAN_RTIE_TPIE_Msk (0x1L << CAN_RTIE_TPIE_Pos)
#define CAN_RTIE_TPIE CAN_RTIE_TPIE_Msk

#define CAN_RTIE_RAFIE_Pos (4U)
#define CAN_RTIE_RAFIE_Msk (0x1L << CAN_RTIE_RAFIE_Pos)
#define CAN_RTIE_RAFIE CAN_RTIE_RAFIE_Msk

#define CAN_RTIE_RFIE_Pos (5U)
#define CAN_RTIE_RFIE_Msk (0x1L << CAN_RTIE_RFIE_Pos)
#define CAN_RTIE_RFIE CAN_RTIE_RFIE_Msk

#define CAN_RTIE_ROIE_Pos (6U)
#define CAN_RTIE_ROIE_Msk (0x1L << CAN_RTIE_ROIE_Pos)
#define CAN_RTIE_ROIE CAN_RTIE_ROIE_Msk

#define CAN_RTIE_RIE_Pos (7U)
#define CAN_RTIE_RIE_Msk (0x1L << CAN_RTIE_RIE_Pos)
#define CAN_RTIE_RIE CAN_RTIE_RIE_Msk

#define CAN_RTIE_AIF_Pos (8U)
#define CAN_RTIE_AIF_Msk (0x1L << CAN_RTIE_AIF_Pos)
#define CAN_RTIE_AIF CAN_RTIE_AIF_Msk

#define CAN_RTIE_EIF_Pos (9U)
#define CAN_RTIE_EIF_Msk (0x1L << CAN_RTIE_EIF_Pos)
#define CAN_RTIE_EIF CAN_RTIE_EIF_Msk

#define CAN_RTIE_TSIF_Pos (10U)
#define CAN_RTIE_TSIF_Msk (0x1L << CAN_RTIE_TSIF_Pos)
#define CAN_RTIE_TSIF CAN_RTIE_TSIF_Msk

#define CAN_RTIE_TPIF_Pos (11U)
#define CAN_RTIE_TPIF_Msk (0x1L << CAN_RTIE_TPIF_Pos)
#define CAN_RTIE_TPIF CAN_RTIE_TPIF_Msk

#define CAN_RTIE_RAFIF_Pos (12U)
#define CAN_RTIE_RAFIF_Msk (0x1L << CAN_RTIE_RAFIF_Pos)
#define CAN_RTIE_RAFIF CAN_RTIE_RAFIF_Msk

#define CAN_RTIE_RFIF_Pos (13U)
#define CAN_RTIE_RFIF_Msk (0x1L << CAN_RTIE_RFIF_Pos)
#define CAN_RTIE_RFIF CAN_RTIE_RFIF_Msk

#define CAN_RTIE_ROIF_Pos (14U)
#define CAN_RTIE_ROIF_Msk (0x1L << CAN_RTIE_ROIF_Pos)
#define CAN_RTIE_ROIF CAN_RTIE_ROIF_Msk

#define CAN_RTIE_RIF_Pos (15U)
#define CAN_RTIE_RIF_Msk (0x1L << CAN_RTIE_RIF_Pos)
#define CAN_RTIE_RIF CAN_RTIE_RIF_Msk

#define CAN_RTIE_BEIF_Pos (16U)
#define CAN_RTIE_BEIF_Msk (0x1L << CAN_RTIE_BEIF_Pos)
#define CAN_RTIE_BEIF CAN_RTIE_BEIF_Msk

#define CAN_RTIE_BEIE_Pos (17U)
#define CAN_RTIE_BEIE_Msk (0x1L << CAN_RTIE_BEIE_Pos)
#define CAN_RTIE_BEIE CAN_RTIE_BEIE_Msk

#define CAN_RTIE_ALIF_Pos (18U)
#define CAN_RTIE_ALIF_Msk (0x1L << CAN_RTIE_ALIF_Pos)
#define CAN_RTIE_ALIF CAN_RTIE_ALIF_Msk

#define CAN_RTIE_ALIE_Pos (19U)
#define CAN_RTIE_ALIE_Msk (0x1L << CAN_RTIE_ALIE_Pos)
#define CAN_RTIE_ALIE CAN_RTIE_ALIE_Msk

#define CAN_RTIE_EPIF_Pos (20U)
#define CAN_RTIE_EPIF_Msk (0x1L << CAN_RTIE_EPIF_Pos)
#define CAN_RTIE_EPIF CAN_RTIE_EPIF_Msk

#define CAN_RTIE_EPIE_Pos (21U)
#define CAN_RTIE_EPIE_Msk (0x1L << CAN_RTIE_EPIE_Pos)
#define CAN_RTIE_EPIE CAN_RTIE_EPIE_Msk

#define CAN_RTIE_EPASS_Pos (22U)
#define CAN_RTIE_EPASS_Msk (0x1L << CAN_RTIE_EPASS_Pos)
#define CAN_RTIE_EPASS CAN_RTIE_EPASS_Msk

#define CAN_RTIE_EWARN_Pos (23U)
#define CAN_RTIE_EWARN_Msk (0x1L << CAN_RTIE_EWARN_Pos)
#define CAN_RTIE_EWARN CAN_RTIE_EWARN_Msk

#define CAN_RTIE_EWL_Pos (24U)
#define CAN_RTIE_EWL_Msk (0xFL << CAN_RTIE_EWL_Pos)
#define CAN_RTIE_EWL CAN_RTIE_EWL_Msk

#define CAN_RTIE_AFWL_Pos (28U)
#define CAN_RTIE_AFWL_Msk (0xFL << CAN_RTIE_AFWL_Pos)
#define CAN_RTIE_AFWL CAN_RTIE_AFWL_Msk

/********************  Bit definition for CAN_S_SEG register
 * ********************/
#define CAN_S_SEG_1_Pos (0U)
#define CAN_S_SEG_1_Msk (0xFFL << CAN_S_SEG_1_Pos)
#define CAN_S_SEG_1 CAN_S_SEG_1_Msk

#define CAN_S_SEG_2_Pos (8U)
#define CAN_S_SEG_2_Msk (0x7FL << CAN_S_SEG_2_Pos)
#define CAN_S_SEG_2 CAN_S_SEG_2_Msk

#define CAN_S_SJW_Pos (16U)
#define CAN_S_SJW_Msk (0x7FL << CAN_S_SJW_Pos)
#define CAN_S_SJW CAN_S_SJW_Msk

#define CAN_S_PRESC_Pos (24U)
#define CAN_S_PRESC_Msk (0xFFL << CAN_S_PRESC_Pos)
#define CAN_S_PRESC CAN_S_PRESC_Msk

/********************  Bit definition for CAN_F_SEG register
 * ********************/
#define CAN_F_SEG_1_Pos (0U)
#define CAN_F_SEG_1_Msk (0x1FL << CAN_F_SEG_1_Pos)
#define CAN_F_SEG_1 CAN_F_SEG_1_Msk

#define CAN_F_SEG_2_Pos (8U)
#define CAN_F_SEG_2_Msk (0xFL << CAN_F_SEG_2_Pos)
#define CAN_F_SEG_2 CAN_F_SEG_2_Msk

#define CAN_F_SJW_Pos (16U)
#define CAN_F_SJW_Msk (0xFL << CAN_F_SJW_Pos)
#define CAN_F_SJW CAN_F_SJW_Msk

#define CAN_F_PRESC_Pos (24U)
#define CAN_F_PRESC_Msk (0xFFL << CAN_F_PRESC_Pos)
#define CAN_F_PRESC CAN_F_PRESC_Msk

/********************  Bit definition for CAN_EALCAP register
 * ********************/
#define CAN_EALCAP_SSPOFF_Pos (8U)
#define CAN_EALCAP_SSPOFF_Msk (0x1FL << CAN_EALCAP_SSPOFF_Pos)
#define CAN_EALCAP_SSPOFF CAN_EALCAP_SSPOFF_Msk

#define CAN_EALCAP_TDCEN_Pos (15U)
#define CAN_EALCAP_TDCEN_Msk (0x1L << CAN_EALCAP_TDCEN_Pos)
#define CAN_EALCAP_TDCEN CAN_EALCAP_TDCEN_Msk

/********************  Bit definition for CAN_ACFCTRL register
 * ********************/
#define CAN_ACFCTRL_ACFADR_Pos (0U)
#define CAN_ACFCTRL_ACFADR_Msk (0xFL << CAN_ACFCTRL_ACFADR_Pos)
#define CAN_ACFCTRL_ACFADR CAN_ACFCTRL_ACFADR_Msk

#define CAN_ACFCTRL_SELMASK_Pos (5U)
#define CAN_ACFCTRL_SELMASK_Msk (0x1L << CAN_ACFCTRL_SELMASK_Pos)
#define CAN_ACFCTRL_SELMASK CAN_ACFCTRL_SELMASK_Msk

#define CAN_ACFCTRL_TIMEEN_Pos (8U)
#define CAN_ACFCTRL_TIMEEN_Msk (0x1L << CAN_ACFCTRL_TIMEEN_Pos)
#define CAN_ACFCTRL_TIMEEN CAN_ACFCTRL_TIMEEN_Msk

#define CAN_ACFCTRL_TIMEPOS_Pos (9U)
#define CAN_ACFCTRL_TIMEPOS_Msk (0x1L << CAN_ACFCTRL_TIMEPOS_Pos)
#define CAN_ACFCTRL_TIMEPOS CAN_ACFCTRL_TIMEPOS_Msk

#define CAN_ACFCTRL_AE_0_Pos (16U)
#define CAN_ACFCTRL_AE_0_Msk (0x1L << CAN_ACFCTRL_AE_0_Pos)
#define CAN_ACFCTRL_AE_0 CAN_ACFCTRL_AE_0_Msk

#define CAN_ACFCTRL_AE_1_Pos (17U)
#define CAN_ACFCTRL_AE_1_Msk (0x1L << CAN_ACFCTRL_AE_1_Pos)
#define CAN_ACFCTRL_AE_1 CAN_ACFCTRL_AE_1_Msk

#define CAN_ACFCTRL_AE_2_Pos (18U)
#define CAN_ACFCTRL_AE_2_Msk (0x1L << CAN_ACFCTRL_AE_2_Pos)
#define CAN_ACFCTRL_AE_2 CAN_ACFCTRL_AE_2_Msk

#define CAN_ACFCTRL_AE_3_Pos (19U)
#define CAN_ACFCTRL_AE_3_Msk (0x1L << CAN_ACFCTRL_AE_3_Pos)
#define CAN_ACFCTRL_AE_3 CAN_ACFCTRL_AE_3_Msk

#define CAN_ACFCTRL_AE_4_Pos (20U)
#define CAN_ACFCTRL_AE_4_Msk (0x1L << CAN_ACFCTRL_AE_4_Pos)
#define CAN_ACFCTRL_AE_4 CAN_ACFCTRL_AE_4_Msk

#define CAN_ACFCTRL_AE_5_Pos (21U)
#define CAN_ACFCTRL_AE_5_Msk (0x1L << CAN_ACFCTRL_AE_5_Pos)
#define CAN_ACFCTRL_AE_5 CAN_ACFCTRL_AE_5_Msk

#define CAN_ACFCTRL_AE_6_Pos (22U)
#define CAN_ACFCTRL_AE_6_Msk (0x1L << CAN_ACFCTRL_AE_6_Pos)
#define CAN_ACFCTRL_AE_6 CAN_ACFCTRL_AE_6_Msk

#define CAN_ACFCTRL_AE_7_Pos (23U)
#define CAN_ACFCTRL_AE_7_Msk (0x1L << CAN_ACFCTRL_AE_7_Pos)
#define CAN_ACFCTRL_AE_7 CAN_ACFCTRL_AE_7_Msk

#define CAN_ACFCTRL_AE_8_Pos (23U)
#define CAN_ACFCTRL_AE_8_Msk (0x1L << CAN_ACFCTRL_AE_8_Pos)
#define CAN_ACFCTRL_AE_8 CAN_ACFCTRL_AE_8_Msk

#define CAN_ACFCTRL_AE_9_Pos (24U)
#define CAN_ACFCTRL_AE_9_Msk (0x1L << CAN_ACFCTRL_AE_9_Pos)
#define CAN_ACFCTRL_AE_9 CAN_ACFCTRL_AE_9_Msk

#define CAN_ACFCTRL_AE_10_Pos (25U)
#define CAN_ACFCTRL_AE_10_Msk (0x1L << CAN_ACFCTRL_AE_10_Pos)
#define CAN_ACFCTRL_AE_10 CAN_ACFCTRL_AE_10_Msk

#define CAN_ACFCTRL_AE_11_Pos (26U)
#define CAN_ACFCTRL_AE_11_Msk (0x1L << CAN_ACFCTRL_AE_11_Pos)
#define CAN_ACFCTRL_AE_11 CAN_ACFCTRL_AE_11_Msk

#define CAN_ACFCTRL_AE_12_Pos (27U)
#define CAN_ACFCTRL_AE_12_Msk (0x1L << CAN_ACFCTRL_AE_12_Pos)
#define CAN_ACFCTRL_AE_12 CAN_ACFCTRL_AE_12_Msk

#define CAN_ACFCTRL_AE_13_Pos (29U)
#define CAN_ACFCTRL_AE_13_Msk (0x1L << CAN_ACFCTRL_AE_13_Pos)
#define CAN_ACFCTRL_AE_13 CAN_ACFCTRL_AE_13_Msk

#define CAN_ACFCTRL_AE_14_Pos (30U)
#define CAN_ACFCTRL_AE_14_Msk (0x1L << CAN_ACFCTRL_AE_14_Pos)
#define CAN_ACFCTRL_AE_14 CAN_ACFCTRL_AE_14_Msk

#define CAN_ACFCTRL_AE_15_Pos (31U)
#define CAN_ACFCTRL_AE_15_Msk (0x1L << CAN_ACFCTRL_AE_15_Pos)
#define CAN_ACFCTRL_AE_15 CAN_ACFCTRL_AE_15_Msk

/********************  Bit definition for CAN_ACF register ********************/
#define CAN_ACF_AMASK_ACODE_Pos (0U)
#define CAN_ACF_AMASK_ACODE_Msk (0xFFFFFFL << CAN_ACF_AMASK_ACODE_Pos)
#define CAN_ACF_AMASK_ACODE CAN_ACF_AMASK_ACODE_Msk

#define CAN_ACF_AIDE_Pos (29U)
#define CAN_ACF_AIDE_Msk (0x1L << CAN_ACF_AIDE_Pos)
#define CAN_ACF_AIDE CAN_ACF_AIDE_Msk

#define CAN_ACF_AIDEE_Pos (30U)
#define CAN_ACF_AIDEE_Msk (0x1L << CAN_ACF_AIDEE_Pos)
#define CAN_ACF_AIDEE CAN_ACF_AIDEE_Msk

/********************  Bit definition for TTCAN_CFG register
 * ********************/
#define TTCAN_CFG_VER_1_Pos (0U)
#define TTCAN_CFG_VER_1_Msk (0xFFL << TTCAN_CFG_VER_1_Pos)
#define TTCAN_CFG_VER_1 TTCAN_CFG_VER_1_Msk

#define TTCAN_CFG_VER_0_Pos (8U)
#define TTCAN_CFG_VER_0_Msk (0xFFL << TTCAN_CFG_VER_0_Pos)
#define TTCAN_CFG_VER_0 TTCAN_CFG_VER_0_Msk

#define TTCAN_CFG_TBPTR_Pos (16U)
#define TTCAN_CFG_TBPTR_Msk (0x1FL << TTCAN_CFG_TBPTR_Pos)
#define TTCAN_CFG_TBPTR TTCAN_CFG_TBPTR_Msk

#define TTCAN_CFG_TBF_Pos (22U)
#define TTCAN_CFG_TBF_Msk (0x1L << TTCAN_CFG_TBF_Pos)
#define TTCAN_CFG_TBF TTCAN_CFG_TBF_Msk

#define TTCAN_CFG_TBE_Pos (23U)
#define TTCAN_CFG_TBE_Msk (0x1L << TTCAN_CFG_TBE_Pos)
#define TTCAN_CFG_TBE TTCAN_CFG_TBE_Msk

#define TTCAN_CFG_TTEN_Pos (24U)
#define TTCAN_CFG_TTEN_Msk (0x1L << TTCAN_CFG_TTEN_Pos)
#define TTCAN_CFG_TTEN TTCAN_CFG_TTEN_Msk

#define TTCAN_CFG_T_PRESC_Pos (25U)
#define TTCAN_CFG_T_PRESC_Msk (0x3L << TTCAN_CFG_T_PRESC_Pos)
#define TTCAN_CFG_T_PRESC TTCAN_CFG_T_PRESC_Msk

#define TTCAN_CFG_TTIF_Pos (27U)
#define TTCAN_CFG_TTIF_Msk (0x1L << TTCAN_CFG_TTIF_Pos)
#define TTCAN_CFG_TTIF TTCAN_CFG_TTIF_Msk

#define TTCAN_CFG_TTIE_Pos (28U)
#define TTCAN_CFG_TTIE_Msk (0x1L << TTCAN_CFG_TTIE_Pos)
#define TTCAN_CFG_TTIE TTCAN_CFG_TTIE_Msk

#define TTCAN_CFG_TEIF_Pos (29U)
#define TTCAN_CFG_TEIF_Msk (0x1L << TTCAN_CFG_TEIF_Pos)
#define TTCAN_CFG_TEIF TTCAN_CFG_TEIF_Msk

#define TTCAN_CFG_WTIF_Pos (30U)
#define TTCAN_CFG_WTIF_Msk (0x1L << TTCAN_CFG_WTIF_Pos)
#define TTCAN_CFG_WTIF TTCAN_CFG_WTIF_Msk

#define TTCAN_CFG_WTIE_Pos (31U)
#define TTCAN_CFG_WTIE_Msk (0x1L << TTCAN_CFG_WTIE_Pos)
#define TTCAN_CFG_WTIE TTCAN_CFG_WTIE_Msk

/********************  Bit definition for TTCAN_RFMSG register
 * ********************/
#define TTCAN_RFMSG_REF_ID_Pos (0U)
#define TTCAN_RFMSG_REF_ID_Msk (0x1FFFFFFL << TTCAN_RFMSG_REF_ID_Pos)
#define TTCAN_RFMSG_REF_ID TTCAN_RFMSG_REF_ID_Msk

#define TTCAN_RFMSG_REF_IDE_Pos (31U)
#define TTCAN_RFMSG_REF_IDE_Msk (0x1L << TTCAN_RFMSG_REF_IDE_Pos)
#define TTCAN_RFMSG_REF_IDE TTCAN_RFMSG_REF_IDE_Msk

/********************  Bit definition for TTCAN_TRIG_CFG register
 * ********************/
#define TTCAN_TRIG_CFG_TTPTR_Pos (0U)
#define TTCAN_TRIG_CFG_TTPTR_Msk (0x3FL << TTCAN_TRIG_CFG_TTPTR_Pos)
#define TTCAN_TRIG_CFG_TTPTR TTCAN_TRIG_CFG_TTPTR_Msk

#define TTCAN_TRIG_CFG_TTYPE_Pos (8U)
#define TTCAN_TRIG_CFG_TTYPE_Msk (0x7FL << TTCAN_TRIG_CFG_TTYPE_Pos)
#define TTCAN_TRIG_CFG_TTYPE TTCAN_TRIG_CFG_TTYPE_Msk

#define TTCAN_TRIG_CFG_TEW_Pos (12U)
#define TTCAN_TRIG_CFG_TEW_Msk (0xFL << TTCAN_TRIG_CFG_TEW_Pos)
#define TTCAN_TRIG_CFG_TEW TTCAN_TRIG_CFG_TEW_Msk

#define TTCAN_TRIG_CFG_TT_TRIG_Pos (16U)
#define TTCAN_TRIG_CFG_TT_TRIG_Msk (0x3FL << TTCAN_TRIG_CFG_TT_TRIG_Pos)
#define TTCAN_TRIG_CFG_TT_TRIG TTCAN_TRIG_CFG_TT_TRIG_Msk

/********************  Bit definition for TTCAN_WTRIG register
 * ********************/
#define TTCAN_WTRIG_TT_WTRIG_Pos (0U)
#define TTCAN_WTRIG_TT_WTRIG_Msk (0xFFFFL << TTCAN_WTRIG_TT_WTRIG_Pos)
#define TTCAN_WTRIG_TT_WTRIG TTCAN_WTRIG_TT_WTRIG_Msk

/********************  Bit definition for CAN_IDE register ********************/
#define CAN_IDE_INTEN_Pos (0U)
#define CAN_IDE_INTEN_Msk (0x1L << CAN_IDE_INTEN_Pos)
#define CAN_IDE_INTEN CAN_IDE_INTEN_Msk

#define CAN_IDE_TIMEN_Pos (11U)
#define CAN_IDE_TIMEN_Msk (0x1L << CAN_IDE_TIMEN_Pos)
#define CAN_IDE_TIMEN CAN_IDE_TIMEN_Msk

#define CAN_IDE_RXEN_Pos (14U)
#define CAN_IDE_RXEN_Msk (0x1L << CAN_IDE_RXEN_Pos)
#define CAN_IDE_RXEN CAN_IDE_RXEN_Msk

#define CAN_IDE_TXEN_Pos (15U)
#define CAN_IDE_TXEN_Msk (0x1L << CAN_IDE_TXEN_Pos)
#define CAN_IDE_TXEN CAN_IDE_TXEN_Msk

#define CAN_IDE_FD_ENABLE_Pos (31U)
#define CAN_IDE_FD_ENABLE_Msk (0x1L << CAN_IDE_FD_ENABLE_Pos)
#define CAN_IDE_FD_ENABLE CAN_IDE_FD_ENABLE_Msk

/******************************************************************************/
/*                         CustomerOption Registers Bits Definition           */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                      Option0                                               */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for COPT0_CFG register
 * ********************/
#define COPT0_CFG_LVRS_Pos (0U)
#define COPT0_CFG_LVRS_Msk (0x3L << COPT0_CFG_LVRS_Pos)
#define COPT0_CFG_LVRS COPT0_CFG_LVRS_Msk

#define COPT0_CFG_DISLVR_Pos (2U)
#define COPT0_CFG_DISLVR_Msk (0x1L << COPT0_CFG_DISLVR_Pos)
#define COPT0_CFG_DISLVR COPT0_CFG_DISLVR_Msk
/******************************************************************************/
/*                                                                            */
/*                      Option0
 */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for COPT1_CFG register
 * ********************/
#define COPT1_CFG_OPBL_Pos (0U)
#define COPT1_CFG_OPBL_Msk (0x3L << COPT1_CFG_OPBL_Pos)
#define COPT1_CFG_OPBL COPT1_CFG_OPBL_Msk

#define COPT1_CFG_DISRST_Pos (5U)
#define COPT1_CFG_DISRST_Msk (0x1L << COPT1_CFG_DISRST_Pos)
#define COPT1_CFG_DISRST COPT1_CFG_DISRST_Msk

#define COPT1_CFG_DISJTAG_Pos (6U)
#define COPT1_CFG_DISJTAG_Msk (0x1L << COPT1_CFG_DISJTAG_Pos)
#define COPT1_CFG_DISJTAG COPT1_CFG_DISJTAG_Msk

#define COPT1_CFG_ENWDT_Pos (7U)
#define COPT1_CFG_ENWDT_Msk (0x1L << COPT1_CFG_ENWDT_Pos)
#define COPT1_CFG_ENWDT COPT1_CFG_ENWDT_Msk

/********************  Bit definition for COPT1_CFG register
 * ********************/
#define COPT1_CFG_OPBL_Pos (0U)
#define COPT1_CFG_OPBL_Msk (0x3L << COPT1_CFG_OPBL_Pos)
#define COPT1_CFG_OPBL COPT1_CFG_OPBL_Msk

/** @addtogroup Exported_macros
 * @{
 */

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SC32F11xxB_H */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT SIN ONE CHIP *****END OF FILE****/
