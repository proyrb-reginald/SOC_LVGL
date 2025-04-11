#include "qspi.h"
#include "main.h"

/*==========================================
                  QSPI初始化函数
===========================================*/
void SC_QSPI_Init(TWI_QSPIx_TypeDef *qspi) {
    QSPI_InitTypeDef QSPI_InitStruct;
    QSPI_StructInit(&QSPI_InitStruct);
    QSPI_InitStruct.QSPI_CLKONLY = QSPI_CLKONLY_OFF; // 只发时钟关闭
    QSPI_InitStruct.QSPI_CPMode = QSPI_CPMode_Low;   // 空闲时低电平和第一沿采样
    QSPI_InitStruct.QSPI_Prescaler = QSPI_Prescaler_1;   // 时钟分频16
    QSPI_InitStruct.QSPI_Mode = QSPI_Mode_QSPI;          // QSPI半双工模式
    QSPI_InitStruct.QSPI_SShift = QSPI_SShift_HalfClock; // 时钟偏移
    QSPI_Init(qspi, &QSPI_InitStruct);
    QSPI_Cmd(qspi, ENABLE);
}

/**
 * @brief  Enables or disables the specified OP peripheral.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  QSPI_InitStruct[out]:Pointer to structure QSPI_InitTypeDef, to be
 * initialized.
 * @retval None
 */
void QSPI_Init(TWI_QSPIx_TypeDef *QSPIx, QSPI_InitTypeDef *QSPI_InitStruct) {
    uint32_t tmpreg;
    assert_param(IS_QSPI_SShift(SShift));
    assert_param(IS_QSPI_PRESCALER(PRESCALER));
    assert_param(IS_QSPI_DWidth(DWidth));
    assert_param(IS_QSPI_LMode(LMode));
    assert_param(IS_QSPI_Mode(Mode));
    assert_param(IS_QSPI_CPMode(CPMode));
    /*---------------------------- TWI_QSPIx_CON Configuration
     * ------------------------*/
    /* Get the TWI_QSPIx_CON value */
    tmpreg = QSPIx->TWI_QSPIx_CON;
    /* Clear SSHIFT, QTWCK ,DWIDTH , LMODE , MDOE , STRDIR , STRTEN  , QTWEN And
     * so on SPR bits */
    tmpreg &=
        ~(TWI_QSPIx_CON_SSHIFT | TWI_QSPIx_CON_QTWCK | TWI_QSPIx_CON_DWIDTH |
          TWI_QSPIx_CON_LMODE | TWI_QSPIx_CON_MDOE | TWI_QSPIx_CON_STRDIR |
          TWI_QSPIx_CON_STRTEN | TWI_QSPIx_CON_STRREN | TWI_QSPIx_CON_RW |
          TWI_QSPIx_CON_CPOL | TWI_QSPIx_CON_CPHA | TWI_QSPIx_CON_DORD |
          TWI_QSPIx_CON_CLKONLY | TWI_QSPIx_CON_SMSTR | TWI_QSPIx_CON_SPOS |
          TWI_QSPIx_CON_QTWEN);
    /* Configure QSPI: SSHIFT, QTWCK ,DWIDTH , LMODE , MDOE , STRDIR , STRTEN  ,
     * QTWEN And so on SPR bits */
    tmpreg |= (QSPI_InitStruct->QSPI_CLKONLY | QSPI_InitStruct->QSPI_CPMode |
               QSPI_InitStruct->QSPI_DWidth | QSPI_InitStruct->QSPI_Mode |
               QSPI_InitStruct->QSPI_Prescaler | QSPI_InitStruct->QSPI_RW |
               QSPI_InitStruct->QSPI_SShift | QSPI_InitStruct->QSP_LMode);
    tmpreg |= TWI_QSPIx_CON_SMSTR;
    /* Write to TWI_QSPIx_CON */
    QSPIx->TWI_QSPIx_CON = tmpreg;
}

/**
 * @brief  Enables or disables the specified QSPI peripheral.
 * @param  QSPIx[out]:  can be select the QSPIx peripheral.
 *               - QSPI0: QSPI0 can be select the QSPI0 peripheral.
 *               - QSPI1: QSPI0 can be select the QSPI1 peripheral.
 * @param  NewState[in]: new state of the QSPI peripheral.
 *                  - DISABLE:Function disable
 *                  - ENABLE:Function enable
 * @retval None
 */
void QSPI_Cmd(TWI_QSPIx_TypeDef *QSPIx, FunctionalState NewState) {
    /* Check the parameters */
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (NewState != DISABLE) {
        /* Enable the selected QSPI interrupt */
        QSPIx->TWI_QSPIx_CON |= TWI_QSPIx_CON_QTWEN;
    } else {
        /* Disable the selected QSPI interrupt */
        QSPIx->TWI_QSPIx_CON &= ~TWI_QSPIx_CON_QTWEN;
    }
}

/**
 * @brief  Fills each QSPI_InitTypeDef member with its default value.
 * @param  QSPI_InitStruct[out]:Pointer to structure QSPI_InitTypeDef, to be
 * initialized.
 * @retval None
 */
void QSPI_StructInit(QSPI_InitTypeDef *QSPI_InitStruct) {
    /* Set the default configuration */
    QSPI_InitStruct->QSPI_CLKONLY = QSPI_CLKONLY_OFF;
    QSPI_InitStruct->QSPI_CPMode = QSPI_CPMode_Low;
    QSPI_InitStruct->QSPI_DWidth = QSPI_DWidth_8bit;
    QSPI_InitStruct->QSPI_Mode = QSPI_Mode_SPI;
    QSPI_InitStruct->QSPI_Prescaler = QSPI_Prescaler_1;
    QSPI_InitStruct->QSPI_RW = QSPI_RW_Write;
    QSPI_InitStruct->QSPI_SShift = QSPI_SShift_OFF;
    QSPI_InitStruct->QSP_LMode = QSPI_LMode_0Line;
}

// void QSPIx_Strmode_ComSet(TWI_QSPIx_TypeDef *qspi, uint32_t STRDIR, uint32_t
// STRTEN, uint32_t STRREN)
//{
//     qspi0.Instance = qspi;
//     strmode.StrDir = STRDIR;//指令
//     strmode.StrTen = STRTEN;//地址
//     strmode.StrRen = STRREN;///* 0:Write 1:Read */
//     qspi0.Init.CommunicateMode = Str_mode_QSPI;
//     MODIFY_REG(qspi->TWI_QSPIx_CON, TWI_QSPIx_CON_MDOE | TWI_QSPIx_CON_STRDIR
//     | TWI_QSPIx_CON_STRTEN | TWI_QSPIx_CON_STRREN,
//                strmode.StrDir | strmode.StrTen | strmode.StrRen |
//                qspi0.Init.CommunicateMode);
// }

/*=======================================================
                      QSPI 写设置函数
=======================================================*/
void QSPIx_Write_ComSet(TWI_QSPIx_TypeDef *QSPIx, int32_t LMODE,
                        uint32_t DWIDTH, uint32_t CLKONLY) {
    uint32_t tmpreg;
    assert_param(IS_QSPI_SShift(SShift));
    assert_param(IS_QSPI_PRESCALER(PRESCALER));
    assert_param(IS_QSPI_DWidth(DWidth));
    assert_param(IS_QSPI_LMode(LMode));
    assert_param(IS_QSPI_Mode(Mode));
    assert_param(IS_QSPI_CPMode(CPMode));
    /* Get the TWI_QSPIx_CON value */
    tmpreg = QSPIx->TWI_QSPIx_CON;
    /* Clear SSHIFT, QTWCK ,DWIDTH , LMODE , MDOE , RW SPR bits */
    tmpreg &= ~(TWI_QSPIx_CON_DWIDTH | TWI_QSPIx_CON_LMODE | TWI_QSPIx_CON_RW);
    /* Configure QSPI: LMODE, DWIDTH */
    tmpreg |= LMODE | DWIDTH;
    /* Write to TWI_QSPIx_CON */
    QSPIx->TWI_QSPIx_CON = tmpreg;
    /* Configure QSPI: QSPI_CLKONLY */
    if (CLKONLY == QSPI_CLKONLY_ON) // 判断只发时钟是否禁止
    {
        QSPIx->TWI_QSPIx_CON |= QSPI_CLKONLY_ON;
    } else {
        QSPIx->TWI_QSPIx_CON &= ~QSPI_CLKONLY_ON;
    }
}

/*=======================================================
                      QSPI 读设置函数
=======================================================*/
void QSPIx_Read_ComSet(TWI_QSPIx_TypeDef *QSPIx, int32_t LMODE, uint32_t DWIDTH,
                       uint32_t CLKONLY) {
    uint32_t tmpreg;
    assert_param(IS_QSPI_SShift(SShift));
    assert_param(IS_QSPI_PRESCALER(PRESCALER));
    assert_param(IS_QSPI_DWidth(DWidth));
    assert_param(IS_QSPI_LMode(LMode));
    assert_param(IS_QSPI_Mode(Mode));
    assert_param(IS_QSPI_CPMode(CPMode));
    /* Get the TWI_QSPIx_CON value */
    tmpreg = QSPIx->TWI_QSPIx_CON;
    /* Clear SSHIFT, QTWCK ,DWIDTH , LMODE , MDOE , RW SPR bits */
    tmpreg &= ~(TWI_QSPIx_CON_DWIDTH | TWI_QSPIx_CON_LMODE | TWI_QSPIx_CON_RW);
    /* Configure QSPI: LMODE, DWIDTH */
    tmpreg |= LMODE | DWIDTH;
    /* Write to TWI_QSPIx_CON */

    QSPIx->TWI_QSPIx_CON = tmpreg;
    /* Configure QSPI: QSPI_CLKONLY */
    if (CLKONLY == QSPI_CLKONLY_ON) {
        QSPIx->TWI_QSPIx_CON |= QSPI_CLKONLY_ON;
    } else {
        QSPIx->TWI_QSPIx_CON &= ~QSPI_CLKONLY_ON;
    }
    QSPIx->TWI_QSPIx_CON |= TWI_QSPIx_CON_RW;
    /* Clear WI_QSPIx_DL */
    QSPIx->TWI_QSPIx_DL = 0x00;
}

/*=======================================================
                       QSPI 发送单个数据函数
=========================================================*/
void QSPIx_Send_singleData(TWI_QSPIx_TypeDef *qspi, uint32_t buf) {
    qspi->TWI_QSPIx_DATA = buf;
}

void QSPIx_Enable(TWI_QSPIx_TypeDef *qspi) {
    qspi->TWI_QSPIx_CON |= TWI_QSPIx_CON_QTWEN;
}

/*=======================================================
                       QSPI 发送多个数据函数
=========================================================*/
void QSPIx_Send_multipleData(TWI_QSPIx_TypeDef *qspi, uint8_t *buf,
                             uint32_t len) {
    uint32_t i;

    for (i = 0; i < len; i++) {
        qspi->TWI_QSPIx_DATA = *buf;

        while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
            ;

        buf++;
    }
}

/*=======================================================
                       QSPI 接收数据函数
=========================================================*/
void QSPIx_Receive(TWI_QSPIx_TypeDef *qspi, uint8_t *buf, uint32_t len) {
    uint32_t i, temp = 0;

    for (i = 0; i < len + 1; i += 4) {
        temp = qspi->TWI_QSPIx_DATA;
        //			printf("%X\n",temp);
        *buf = temp >> (0 * 8);
        buf++;
        *buf = temp >> (1 * 8);
        buf++;
        *buf = temp >> (2 * 8);
        buf++;
        *buf = temp >> (3 * 8);
        buf++;
    }
}

/*=========================================================
                      QSPI CS IO口拉高
===========================================================*/
void QSPI_SET_CS_High(TWI_QSPIx_TypeDef *qspi) {
    if (qspi == QSPI0) {
        CS_IO = 1;
    } else {
        CS_IO1 = 1;
    }
}

/*==========================================================
                       QSPI CS IO口拉底
===========================================================*/
void QSPI_SET_CS_Low(TWI_QSPIx_TypeDef *qspi) {
    if (qspi == QSPI0) {
        CS_IO = 0;
    } else {
        CS_IO1 = 0;
    }
}

// 中断使能
void QSPIx_EnableInt(TWI_QSPIx_TypeDef *qspi) {
    //		__NVIC_EnableIRQ(TWIx_QSPIx_0_1_IRQn);//开QSPIx内核中断
    // 中断使能
#if (SPI_Int_Switch == ON)
    REG_SET(qspi->TWI_QSPIx_IDE, TWI_QSPIx_IDE_INTEN); // 允许中断
#endif
#if (SPI_QTWIE_Switch == ON)
    REG_SET(qspi->TWI_QSPIx_IDE, TWI_QSPIx_IDE_QTWIE); // 允许中断
#endif
#if (SPI_RXNEIE_Switch == ON)
    REG_SET(qspi->TWI_QSPIx_IDE,
            TWI_QSPIx_IDE_RXNEIE); // 允许接收缓存区非空中断
#endif
#if (SPI_TBLE_Switch == ON)
    REG_SET(qspi->TWI_QSPIx_IDE, TWI_QSPIx_IDE_TBIE); // 允许发送缓存为空中断
#endif
#if (SPI_RXFIF_Switch == ON)
    REG_SET(qspi->TWI_QSPIx_IDE, TWI_QSPIx_IDE_RXIE); // 允许接收FIFO溢出中断
#endif
#if (SPI_RXHIE_Switch == ON)
    REG_SET(qspi->TWI_QSPIx_IDE, TWI_QSPIx_IDE_RXHIE); // 允许接收FIFO超一半中断
#endif
#if (SPI_TXHIE_Switch == ON)
    REG_SET(qspi->TWI_QSPIx_IDE, TWI_QSPIx_IDE_TXHIE); // 允许发送FIFO超一半中断
#endif
#if (SPI_DLUFIE_Switch == ON)
    REG_SET(qspi->TWI_QSPIx_IDE, TWI_QSPIx_IDE_DLUFIE); // DL下溢中断使能
#endif
}

/*==========================================================
                       QSPI0/1中断服务函数
===========================================================*/
void TWI_QSPIx_0_2_IRQHandler() {
    // uint32_t data;

    if (READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_WCOL)) {
        QSPI0->TWI_QSPIx_STS = 0x00000080;
        WCOL_IO;
    }

    if (READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_QTWIF)) {
        QSPI0->TWI_QSPIx_STS = 0x00000001;
        //		 SPIF_flag = 1;
        SPIF_IO;
    }

    if (READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_TXHIF)) {
        TXHIF_IO;
        CLEAR_BIT(QSPI0->TWI_QSPIx_IDE, TWI_QSPIx_IDE_TXHIE);
    }

    if (READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_TXEIF)) {
        QSPI0->TWI_QSPIx_STS = 0x00000004;
        TXEIF_IO;
    }

    if (READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_RXNEIF)) {
        //		 data = QSPI0->TWI_QSPIx_DATA;
        RXNEIF_IO;
    }

    if (READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_RXHIF)) {
        //		 data = QSPI0->TWI_QSPIx_DATA;
        //		 data = QSPI0->TWI_QSPIx_DATA;
        //		 data = QSPI0->TWI_QSPIx_DATA;
        //		 data = QSPI0->TWI_QSPIx_DATA;
        //		 data = QSPI0->TWI_QSPIx_DATA;
        RXHIF_IO;
    }

    if (READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_RXFIF)) {
        //		 data = QSPI0->TWI_QSPIx_DATA;
        //		 data = QSPI0->TWI_QSPIx_DATA;
        //		 data = QSPI0->TWI_QSPIx_DATA;
        //		 data = QSPI0->TWI_QSPIx_DATA;
        //		 data = QSPI0->TWI_QSPIx_DATA;
        //		 data = QSPI0->TWI_QSPIx_DATA;
        //		 data = QSPI0->TWI_QSPIx_DATA;
        //		 data = QSPI0->TWI_QSPIx_DATA;
        RXFIF_IO;
    }

    if (READ_BIT(QSPI0->TWI_QSPIx_STS, TWI_QSPIx_STS_DLUFIF)) {
        QSPI0->TWI_QSPIx_STS = 0x00000040;
        DLUFIF_IO;
        DL_OK = 1;
    }
}

void TWI_QSPIx_1_3_IRQHandler() {
    //	 if(READ_BIT(QSPI1->TWI_QSPIx_STS, TWI_QSPIx_STS_WCOL))
    //	 {
    //		 QSPI1->TWI_QSPIx_STS = 0x00000080;
    //		 WCOL_IO;
    //	 }
    if (READ_BIT(QSPI1->TWI_QSPIx_STS, TWI_QSPIx_STS_QTWIF)) {
        QSPI1->TWI_QSPIx_STS = 0x00000001;
        //		 SPIF_flag = 1;
        SPIF_IO;
    }

    if (READ_BIT(QSPI1->TWI_QSPIx_STS, TWI_QSPIx_STS_DLUFIF)) {
        QSPI1->TWI_QSPIx_STS = 0x00000040;
        DLUFIF_IO;
        DL_OK = 1;
    }

    //	 if(READ_BIT(QSPI1->TWI_QSPIx_STS, TWI_QSPIx_STS_TXHIF))
    //	 {
    //		 TXHIF_IO;
    //	 }
    //	 if(READ_BIT(QSPI1->TWI_QSPIx_STS, TWI_QSPIx_STS_TXEIF))
    //	 {
    //		 QSPI1->TWI_QSPIx_STS = 0x00000004;
    //		 TXEIF_IO;
    //	 }
    //	 if(READ_BIT(QSPI1->TWI_QSPIx_STS, TWI_QSPIx_STS_RXNEIF))
    //	 {
    //		 QSPI1->TWI_QSPIx_STS = 0x00000002;
    //		 RXNEIF_IO;
    //	 }
    //	 if(READ_BIT(QSPI1->TWI_QSPIx_STS, TWI_QSPIx_STS_RXHIF))
    //	 {
    //		 RXHIF_IO;
    //	 }
    //	 if(READ_BIT(QSPI1->TWI_QSPIx_STS, TWI_QSPIx_STS_RXFIF))
    //	 {
    //		 RXFIF_IO;
    //	 }
}

void QSPI_DMACmd(TWI_QSPIx_TypeDef *QSPIx, uint16_t QSPI_DMAReq,
                 FunctionalState NewState) {
    /* Check the parameters */
    assert_param(IS_QSPI_ALL_PERIPH(SPIx));
    assert_param(IS_QSPI_DMAREQ(QSPI_DMAReq));
    assert_param(IS_FUNCTIONAL_STATE(NewState));
    if (NewState != DISABLE) {
        /* Enable the selected SPI DMA requests */
        QSPIx->TWI_QSPIx_IDE |= QSPI_DMAReq;
    } else {
        /* Disable the selected SPI DMA requests */
        QSPIx->TWI_QSPIx_IDE &= (uint16_t)~QSPI_DMAReq;
    }
}
