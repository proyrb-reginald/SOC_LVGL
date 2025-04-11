#include "Function_Init.h"

void SC_DMA_Init(void) {
#if Test_Mode == Striaight_Mode
    RCCAHB->AHB_CFG |= 0X01; // 开启DMA模块时钟

    /* 使能DMA的时钟 */
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA, ENABLE);
    /* DMA外设配置 */
    CLEAR_REG(DMA0->DMA_CFG);
    CLEAR_REG(DMA0->DMA_CNT);
    DMA_InitTypeDef DMA_InitStruct; // 定义DMA初始化结构体变量
    DMA_StructInit(&DMA_InitStruct);
    DMA_InitStruct.DMA_Burst = DMA_Burst_Disable;               // Brust模式关闭
    DMA_InitStruct.DMA_CircularMode = DMA_CircularMode_Disable; // 开启循环模式
    DMA_InitStruct.DMA_DataSize = DMA_DataSize_HakfWord;  // 传输宽度为字节
    DMA_InitStruct.DMA_SourceMode = DMA_SourceMode_INC;   // 源地址固定
    DMA_InitStruct.DMA_TargetMode = DMA_TargetMode_FIXED; // 目标地址固定

    //  DMA_InitStruct.DMA_SrcAddress = (uint32_t)&QSPI0->TWI_QSPIx_DATA;
    //  //设置第一次传输的首地址
    DMA_InitStruct.DMA_DstAddress =
        (uint32_t)&QSPI1->TWI_QSPIx_DATA;                  // 设置目标地址
    DMA_InitStruct.DMA_Request = DMA_Request_TWI_QSPI1_TX; //
    DMA_Init(DMA0, &DMA_InitStruct);

    //	WRITE_REG(DMA0->DMA_CNT,4);
    //	REG_SET(DMA0->DMA_CFG,DMA_CFG_INTEN);//打开DMA中断
    //	REG_SET(DMA0->DMA_CFG,DMA_CFG_TCIE);//打开DMA传输完成中断
    //	REG_SET(DMA0->DMA_CFG,DMA_CFG_CHEN);//DMA0通道使能

#elif Test_Mode == LCD_Communication
    RCCAHB->AHB_CFG |= 0X01; // 开启DMA模块时钟

    CLEAR_REG(DMA0->DMA_CFG);
    CLEAR_REG(DMA0->DMA_CNT);
    // 以下为SPI发送DMA配置
    REG_SETn(DMA0->DMA_CFG, DMA_CFG_TXWIDTH,
             0x0L << DMA_CFG_TXWIDTH_Pos);    // 传输宽度8bit
    CLEAR_BIT(DMA0->DMA_CFG, DMA_CFG_TPTYPE); // 单次传输
    CLEAR_BIT(DMA0->DMA_CFG, DMA_CFG_CIRC);   // 关闭循环
    //	REG_SETn(DMA0->DMA_CFG,DMA_CFG_SAINC,0x0L <<
    // DMA_CFG_SAINC_Pos);//源地址固定
    REG_SETn(DMA0->DMA_CFG, DMA_CFG_DAINC,
             0x0L << DMA_CFG_DAINC_Pos); // 目标地址固定
    REG_SETn(DMA0->DMA_CFG, DMA_CFG_REQSRC,
             14 << DMA_CFG_REQSRC_Pos);     // QSPI0_TX
    WRITE_REG(DMA0->DMA_SADR, (uint32_t)0); // 源地址待后续填写
    WRITE_REG(DMA0->DMA_DADR, (uint32_t)&QSPI1->TWI_QSPIx_DATA);
    //	WRITE_REG(DMA0->DMA_CNT,20);
#endif
}
// void DMA_Init(void)
//{
//	CLEAR_REG(DMA0->DMA_CFG);
//	CLEAR_REG(DMA0->DMA_CNT);
//
////	//以下为SPI发送DMA配置
//////	REG_SETn(DMA0->DMA_CFG,DMA_CFG_TXWIDTH,0x0L <<
/// DMA_CFG_TXWIDTH_Pos);//传输宽度8bit /
/// CLEAR_BIT(DMA0->DMA_CFG,DMA_CFG_TPTYPE); //单次传输 /
/// REG_SET(DMA0->DMA_CFG,DMA_CFG_CIRC);//循环 /
/// REG_SETn(DMA0->DMA_CFG,DMA_CFG_BURSIZE,0x7L <<
/// DMA_CFG_BURSIZE_Pos);//触发一次传输1个数据 /
/// REG_SETn(DMA0->DMA_CFG,DMA_CFG_SAINC,0x3L <<
/// DMA_CFG_SAINC_Pos);//源地址增量模式 /
/// REG_SETn(DMA0->DMA_CFG,DMA_CFG_DAINC,0x0L <<
/// DMA_CFG_DAINC_Pos);//目标地址无增量模式 /
/// REG_SETn(DMA0->DMA_CFG,DMA_CFG_REQSRC,12 << DMA_CFG_REQSRC_Pos);//SPI_TX /
/// WRITE_REG(DMA0->DMA_SADR,(uint32_t)SPI_Send_Buffer); /
/// WRITE_REG(DMA0->DMA_DADR,(uint32_t)&SPI0->SPI_DATA); /
/// WRITE_REG(DMA0->DMA_CNT,20); /
/// REG_SET(DMA0->DMA_CFG,DMA_CFG_INTEN);//打开DMA中断 /
/// REG_SET(DMA0->DMA_CFG,DMA_CFG_TCIE);//打开DMA传输完成中断 /
/// REG_SET(DMA0->DMA_CFG,DMA_CFG_CHEN);//DMA0通道使能
//
//	//以下为SPI接收DMA配置
//	REG_SETn(DMA0->DMA_CFG,DMA_CFG_TXWIDTH,0x0L <<
// DMA_CFG_TXWIDTH_Pos);//传输宽度8bit 	CLEAR_BIT(DMA0->DMA_CFG,DMA_CFG_TPTYPE);
////单次传输 	REG_SET(DMA0->DMA_CFG,DMA_CFG_CIRC);//循环
//	REG_SETn(DMA0->DMA_CFG,DMA_CFG_BURSIZE,0x7L <<
// DMA_CFG_BURSIZE_Pos);//触发一次传输1个数据
//	REG_SETn(DMA0->DMA_CFG,DMA_CFG_SAINC,0x0L <<
// DMA_CFG_SAINC_Pos);//源地址无增量模式
//	REG_SETn(DMA0->DMA_CFG,DMA_CFG_DAINC,0x3L <<
// DMA_CFG_DAINC_Pos);//目标地址增量模式
// REG_SETn(DMA0->DMA_CFG,DMA_CFG_REQSRC,15
//<< DMA_CFG_REQSRC_Pos);//SPI1_RX
//	WRITE_REG(DMA0->DMA_SADR,(uint32_t)&SPI1->SPI_DATA);
//	WRITE_REG(DMA0->DMA_DADR,(uint32_t)SPI_Receive_Buffer);
//	WRITE_REG(DMA0->DMA_CNT,4);
//	REG_SET(DMA0->DMA_CFG,DMA_CFG_INTEN);//打开DMA中断
//	REG_SET(DMA0->DMA_CFG,DMA_CFG_TCIE);//打开DMA传输完成中断
//	REG_SET(DMA0->DMA_CFG,DMA_CFG_CHEN);//DMA0通道使能
//}

// void SPI0_DMA_Init(void)
//{
//	SPI0_Open(SPI0_SPOS_Select, Master_Slave_Select, SPI_Mode_Select,
// SPI_MSBLSB_Select, SPI_Send_Select, SPI_Clk_Select); 	SPI0_Close();

////	REG_SET(SPI0->SPI_IDE,SPI0_IDE_TXDMAEN);
//	REG_SET(SPI0->SPI_IDE,SPI0_IDE_RXDMAEN);
////	SPI0->SPI_REV = 0xA05F0021;
//	REG_SET(SPI0->SPI_CON,SPI0_CON_SPEN);
////	CS_IO = CS_LOW;
////	Delay(100);
////	WRITE_REG(SPI0->SPI_DATA, DATA_Master_LOW);
////	REG_SET(RCCAPB0->APB0_RST,APB0_RST_SPI0RST);   // SPI0复位
//}

// void SPI1_DMA_Init(void)
//{
//	SPI1_Open(SPI1_SPOS_Select, Master_Slave_Select, SPI_Mode_Select,
// SPI_MSBLSB_Select, SPI_Send_Select, SPI_Clk_Select); 	SPI1_Close();
////	REG_SET(SPI1->SPI_IDE,SPI1_IDE_TXDMAEN);
//	REG_SET(SPI1->SPI_IDE,SPI1_IDE_RXDMAEN);
//	REG_SET(SPI1->SPI_CON,SPI1_CON_SPEN);
////	CS_IO = CS_LOW;
////	Delay(100);
////	WRITE_REG(SPI1->SPI_DATA, DATA_Master_LOW);
////	REG_SET(RCCAPB0->APB0_RST,APB0_RST_SPI0RST);   // SPI0复位
//
//}

///*DMA0中断处理函数*/
// void DMA0_IRQHandler(void)
//{
//	PC_OT(1);
////	Test_IO;
////	PC_OT(15);
//	if(SPI_Receive_Buffer[19]==0x01)
//	{
//		Data_IO;
//	}
//	if(DMA0->DMA_STS & DMA_STS_GIF)
//	{
//	if((DMA0->DMA_STS & DMA_STS_HTIF)&&(DMA0->DMA_CFG & DMA_CFG_HTIE))
//	  {
//		  DMA0->DMA_STS |= DMA_STS_HTIF;
//	  }
//	  if((DMA0->DMA_STS & DMA_STS_TCIF)&&(DMA0->DMA_CFG & DMA_CFG_TCIE))
//	  {
//		  DMA0->DMA_CFG |= DMA_CFG_CHEN ;
//		  DMA0->DMA_STS |= DMA_STS_TCIF;
//	  }
//  }

//}

///*DMA1中断处理函数*/
// void DMA1_IRQHandler(void)
//{
////	PC_OT(0);
////	Test_IO;
////	PC_OT(15);
//	if(SPI_Receive_Buffer[19]==0x01)
//	{
//		Data_IO;
//	}
//	if(DMA1->DMA_STS & DMA_STS_GIF)
//	{
//	if((DMA1->DMA_STS & DMA_STS_HTIF)&&(DMA1->DMA_CFG & DMA_CFG_HTIE))
//	  {
//		  DMA1->DMA_STS |= DMA_STS_HTIF;
//	  }
//	  if((DMA1->DMA_STS & DMA_STS_TCIF)&&(DMA1->DMA_CFG & DMA_CFG_TCIE))
//	  {
//		  DMA1->DMA_CFG |= DMA_CFG_CHEN ;
//		  DMA1->DMA_STS |= DMA_STS_TCIF;
//	  }
//  }

//}

void DMA_Init(DMA_TypeDef *DMAx, DMA_InitTypeDef *DMA_InitStruct) {
    uint32_t tmpreg;
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMAx));
    assert_param(IS_DMA_PROIORITY(DMA_InitStruct->DMA_Priority));
    assert_param(IS_DMA_CIRCULARMODE(DMA_InitStruct->DMA_CircularMode));
    assert_param(IS_DMA_DATASIZE(DMA_InitStruct->DMA_DataSize));
    assert_param(IS_DMA_TARGERT_MODE(DMA_InitStruct->DMA_TargetMode));
    assert_param(IS_DMA_SOURCE_MODE(DMA_InitStruct->DMA_SourceMode));
    assert_param(IS_DMA_BURST(DMA_InitStruct->DMA_Burst));

    tmpreg = DMAx->DMA_CFG;

    tmpreg &= (uint32_t)~(DMA_CFG_PL | DMA_CFG_TXWIDTH | DMA_CFG_CIRC |
                          DMA_CFG_CHRST | DMA_CFG_CHEN | DMA_CFG_DAINC |
                          DMA_CFG_SAINC | DMA_CFG_BURSIZE | DMA_CFG_TPTYPE |
                          DMA_CFG_REQSRC);
    tmpreg |=
        (uint32_t)(DMA_InitStruct->DMA_Priority |
                   DMA_InitStruct->DMA_CircularMode |
                   DMA_InitStruct->DMA_DataSize |
                   DMA_InitStruct->DMA_TargetMode |
                   DMA_InitStruct->DMA_SourceMode | DMA_InitStruct->DMA_Burst |
                   DMA_InitStruct->DMA_Request);

    DMAx->DMA_CFG = tmpreg;

    DMAx->DMA_SADR = DMA_InitStruct->DMA_SrcAddress;
    DMAx->DMA_DADR = DMA_InitStruct->DMA_DstAddress;
    DMAx->DMA_CNT = DMA_InitStruct->DMA_BufferSize;
}

void DMA_SetCurrDataCounter(DMA_TypeDef *DMAx, uint32_t Counter) {
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMAx));

    /* Write the number of data units to be transferred */
    DMAx->DMA_CNT = (uint32_t)Counter;
}

void DMA_Cmd(DMA_TypeDef *DMAx, FunctionalState NewState) {
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMAx));
    assert_param(IS_FUNCTIONAL_STATE(NewState));

    if (NewState != DISABLE) {
        /* Enable the selected DMAy Streamx by setting EN bit */
        DMAx->DMA_CFG |= (uint32_t)DMA_CFG_CHEN;
    } else {
        /* Disable the selected DMAy Streamx by clearing EN bit */
        DMAx->DMA_CFG &= ~(uint32_t)DMA_CFG_CHEN;
    }
}

void DMA_SetSrcAddress(DMA_TypeDef *DMAx, uint32_t SrcAddress) {
    /* Check the parameters */
    assert_param(IS_DMA_ALL_PERIPH(DMAx));

    /* Write the number of data units to be transferred */
    DMAx->DMA_SADR = (uint32_t)SrcAddress;
}

void DMA_StructInit(DMA_InitTypeDef *DMA_InitStruct) {
    /* Initialize the DMA_Priority member */
    DMA_InitStruct->DMA_Priority = DMA_Priority_LOW;

    /* Initialize the DMA_CircularMode member */
    DMA_InitStruct->DMA_CircularMode = DMA_CircularMode_Disable;

    /* Initialize the DMA_DataSize member */
    DMA_InitStruct->DMA_DataSize = DMA_DataSize_Byte;

    /* Initialize the DMA_TargetMode member */
    DMA_InitStruct->DMA_TargetMode = DMA_TargetMode_FIXED;

    /* Initialize the DMA_SourceMode member */
    DMA_InitStruct->DMA_SourceMode = DMA_SourceMode_FIXED;

    /* Initialize the DMA_Burst member */
    DMA_InitStruct->DMA_Burst = DMA_Burst_Disable;

    /* Initialize the DMA_Request member */
    DMA_InitStruct->DMA_Request = DMA_Request_Null;
}
