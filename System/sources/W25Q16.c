#include "main.h"
/*===============================================
                      �ȴ�����
=================================================*/
void W25QXX_WaitIdle(TWI_QSPIx_TypeDef *qspi) {
    uint8_t sta_reg1 = 0x00;
    do {
        // /CS ����
        QSPI_SET_CS_Low(qspi);
        // ���÷�������  0X05 Read Status Register 1
        QSPIx_Write_ComSet(qspi, QSPI_DATA_1_LINE, QSPI_BYTES_8_BITS,
                           QSPI_CLKONLY_OFF);
        QSPIx_Send_singleData(qspi, 0x05);
        while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
            ; // �ȴ�BUSY����
        // ���ûض�����
        QSPIx_Read_ComSet(qspi, QSPI_DATA_1_LINE, QSPI_BYTES_8_BITS,
                          QSPI_CLKONLY_ON);
        while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
            ; // �ȴ�BUSY����
        QSPIx_Receive(qspi, &sta_reg1, 1);
        // /CS ����
        QSPI_SET_CS_High(qspi);
    } while ((sta_reg1 & 0x01) == 0x01);
}
/***************************************************************************************
 * @brief   ����QSPIĳ������
 * @input
 * @return
 ***************************************************************************************/
void W25QXX_EraseSector(TWI_QSPIx_TypeDef *qspi, uint32_t sector_id) {
    uint32_t addr = sector_id * 4096;
    //	uint16_t i,j;
    // /CS ����
    QSPI_SET_CS_Low(qspi);
    QSPIx_Write_ComSet(qspi, QSPI_DATA_1_LINE, QSPI_BYTES_8_BITS,
                       QSPI_CLKONLY_OFF);
    QSPIx_Send_singleData(qspi, WRITE_ENABLE_CMD); // 0x06
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    QSPI_SET_CS_High(qspi);
    // /CS ����
    QSPI_SET_CS_Low(qspi);
    QSPIx_Write_ComSet(qspi, QSPI_DATA_1_LINE, QSPI_BYTES_32_BITS,
                       QSPI_CLKONLY_OFF);
    QSPIx_Send_singleData(qspi, 0x20000000 + addr); // 0x20
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    // /CS ����
    QSPI_SET_CS_High(qspi);
    Delay(10);
    W25QXX_WaitIdle(qspi);
}
/***************************************************************************************
  * @brief   SPI��һҳ(0~65535)��д������256���ֽڵ�����
  * @input   pBuffer:���ݴ洢��
             WriteAddr:��ʼд��ĵ�ַ(���32bit)
             NumByteToWrite:Ҫд����ֽ���(���256),������Ӧ�ó�����ҳ��ʣ���ֽ���!!!
  * @return
***************************************************************************************/
void W25QXX_Write_Page(TWI_QSPIx_TypeDef *qspi, uint8_t *pBuffer,
                       uint32_t WriteAddr, uint16_t NumByteToWrite) {
    // /CS ����
    QSPI_SET_CS_Low(qspi);

    QSPIx_Write_ComSet(qspi, QSPI_DATA_1_LINE, QSPI_BYTES_8_BITS,
                       QSPI_CLKONLY_OFF);
    QSPIx_Send_singleData(qspi, WRITE_ENABLE_CMD);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    // /CS ����
    QSPI_SET_CS_High(qspi);

    // /CS ����
    QSPI_SET_CS_Low(qspi);
    QSPIx_Write_ComSet(qspi, (int32_t)QSPI_DATA_1_LINE,
                       (uint32_t)QSPI_BYTES_8_BITS, (uint32_t)QSPI_CLKONLY_OFF);
    QSPIx_Send_singleData(qspi, 0x32);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    QSPIx_Write_ComSet(qspi, (int32_t)QSPI_DATA_1_LINE,
                       (uint32_t)QSPI_BYTES_24_BITS,
                       (uint32_t)QSPI_CLKONLY_OFF);
    QSPIx_Send_singleData(qspi, WriteAddr);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    QSPIx_Write_ComSet(qspi, (int32_t)QSPI_DATA_4_LINES,
                       (uint32_t)QSPI_BYTES_8_BITS, (uint32_t)QSPI_CLKONLY_OFF);
    QSPIx_Send_multipleData(qspi, pBuffer, NumByteToWrite);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    // /CS ����
    QSPI_SET_CS_High(qspi);
    W25QXX_WaitIdle(qspi); // �ȴ�д�����
}
/*==================================================================================
                      ��ȡ FLASH ָ����ַ����
  * @input   pBuffer:���ݴ洢��
             ReadAddr:��ʼ��ȡ�ĵ�ַ(���32bit)
             NumByteToRead:Ҫ��ȡ���ֽ���(���65535)
=====================================================================================*/
void W25QXX_Read(TWI_QSPIx_TypeDef *qspi, uint8_t *pBuffer, uint8_t Readcmd,
                 uint32_t ReadAddr, uint32_t NumByteToRead) {
    QSPI_SET_CS_Low(qspi);

    QSPIx_Write_ComSet(qspi, QSPI_DATA_1_LINE, QSPI_BYTES_8_BITS,
                       QSPI_CLKONLY_OFF);
    QSPIx_Send_singleData(qspi, WRITE_ENABLE_CMD);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    // /CS ����
    QSPI_SET_CS_High(qspi);
    // /CS ����
    QSPI_SET_CS_Low(qspi);
    // ���÷�������
    QSPIx_Write_ComSet(qspi, (int32_t)QSPI_DATA_1_LINE,
                       (uint32_t)QSPI_BYTES_8_BITS, (uint32_t)QSPI_CLKONLY_OFF);
    QSPIx_Send_singleData(qspi, Readcmd);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    // ���÷��͵�ַ
    QSPIx_Write_ComSet(qspi, (int32_t)QSPI_DATA_1_LINE,
                       (uint32_t)QSPI_BYTES_24_BITS,
                       (uint32_t)QSPI_CLKONLY_OFF);
    QSPIx_Send_singleData(qspi, ReadAddr);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    // ���ÿ�����
    qspi->TWI_QSPIx_REV = 0xA05F0700;
    QSPIx_Write_ComSet(qspi, (int32_t)QSPI_DATA_NONE,
                       (uint32_t)QSPI_BYTES_32_BITS,
                       (uint32_t)QSPI_CLKONLY_OFF);
    QSPIx_Send_singleData(qspi, 0XFF000000);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    qspi->TWI_QSPIx_REV = 0xA05F0000;
    // ��������
    QSPIx_Read_ComSet(qspi, (int32_t)QSPI_DATA_4_LINES,
                      (uint32_t)QSPI_BYTES_8_BITS, (uint32_t)QSPI_CLKONLY_ON);
    QSPIx_Receive(qspi, pBuffer, NumByteToRead);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    //	Delay(1000);
    // /CS ����
    QSPI_SET_CS_High(qspi);
}
/*==================================================================================
                      ��ȡ FLASH ָ����ַ����
  * @input   pBuffer:���ݴ洢��
             ReadAddr:��ʼ��ȡ�ĵ�ַ(���32bit)
             NumByteToRead:Ҫ��ȡ���ֽ���(���65535)
=====================================================================================*/
// void W25QXX_FastRead( TWI_QSPIx_TypeDef
// *qspi,//W25QXX_FastRead(qspi_flash,QSPI_Receive_Buffer,0xEB,0x002000,STR_MODE_DL/4);
//				//uint8_t* pBuffer,
//                   uint8_t	 Readcmd,
//	                uint32_t ReadAddr,
//                   uint32_t NumByteToRead
//                   )
//{
//	QSPIx_Write_ComSet(qspi,QSPI_DATA_1_LINE,QSPI_BYTES_8_BITS,QSPI_CLKONLY_OFF);
//	// /CS ����
//	QSPI_SET_CS_Low(qspi);

//	QSPIx_Send_singleData(qspi,Readcmd);
//	while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //�ȴ�BUSY����
//
//	// ���÷��͵�ַ
//	QSPIx_Write_ComSet(qspi,QSPI_DATA_4_LINES,QSPI_BYTES_32_BITS,QSPI_CLKONLY_OFF);
//	QSPIx_Send_singleData(qspi,ReadAddr);
//	while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //�ȴ�BUSY����
////	// ���ÿ�����
//	qspi->TWI_QSPIx_REV = 0xA05F0700;
//	QSPIx_Write_ComSet(qspi,QSPI_DATA_NONE,QSPI_BYTES_24_BITS,QSPI_CLKONLY_OFF);
//	QSPIx_Send_singleData(qspi,0XFF0000);
//	while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //�ȴ�BUSY����
//	qspi->TWI_QSPIx_REV = 0xA05F0000;
//	// ֱͨģʽ��������
////	qspi->TWI_QSPIx_CON |= QSPI_PCLK_8<<8;
// #if Test_Mode == Striaight_Mode
// //�ҵ�����ǣ�DMA��FLASH��������QSPI_FLASH��д���ᣩ��
// QSPIx_Strmode_ComSet(
// qspi, QSPI_INNER_TX, QSPI_INNER_TEN,QSPI_INNER_DISREN);//TWI_QSPIx_CON_STRDIR
// 0   ֱͨ��TXģʽ��QSPI���ڶ�FLASH
//																				//TWI_QSPIx_CON_STRTEN
// 1
//																				//TWI_QSPIx_CON_STRREN
// 0:Write  /* 0:Write 1:Read */
//	//PC_BIT(0) = 1;
//
//	QSPIx_Read_ComSet(qspi,QSPI_DATA_4_LINES,QSPI_BYTES_32_BITS,QSPI_CLKONLY_ON,NumByteToRead);
//
////	while(!READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_DLUFIF));
////	qspi->TWI_QSPIx_STS = 0x00000040;

//	while(!DL_OK);
//	//PC_BIT(0) = 0;
//	DL_OK = 0;
//	// /CS ����
//	QSPI_SET_CS_High(qspi);
//	FLASH_OK = 1;
// #else
//
//	#if DMA_Test
//    WRITE_REG(DMA0->DMA_DADR,(uint32_t)pBuffer); //Ŀ���ַ
//	WRITE_REG(DMA0->DMA_CNT,NumByteToRead);//����DMA������
//	qspi->TWI_QSPIx_IDE |= 0x40;//RXDMAEN
//	REG_SETn(DMA0->DMA_CFG,DMA_CFG_CHEN,1 << DMA_CFG_CHEN_Pos); //DMAʹ��
//	QSPIx_Read_ComSet(qspi,QSPI_DATA_4_LINES,QSPI_BYTES_8_BITS,QSPI_CLKONLY_ON,NumByteToRead);
////	REG_SETn(DMA0->DMA_STS,DMA_STS_SWREQ,1 << DMA_STS_SWREQ_Pos);
/////DMA�������
//	while(!(DMA0->DMA_STS & DMA_STS_TCIF)); //�ȴ�DMA�������
//	DMA0->DMA_STS |= DMA_STS_TCIF;//���־
//	#else
//	QSPIx_Read_ComSet(qspi,QSPI_DATA_4_LINES,QSPI_BYTES_8_BITS,QSPI_CLKONLY_ON,NumByteToRead);
////	QSPIx_Receive(qspi,pBuffer,NumByteToRead);
//	#endif
//	while(READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY)); //�ȴ�BUSY����
//	// /CS ����
//	QSPI_SET_CS_High(qspi);
// #endif
//
//}
void W25QXX_DualRead(TWI_QSPIx_TypeDef *qspi, uint8_t *pBuffer, uint8_t Readcmd,
                     uint32_t ReadAddr, uint32_t NumByteToRead) {
    QSPIx_Write_ComSet(qspi, (int32_t)QSPI_DATA_1_LINE,
                       (uint32_t)QSPI_BYTES_8_BITS, (uint32_t)QSPI_CLKONLY_OFF);
    // /CS ����
    QSPI_SET_CS_Low(qspi);

    QSPIx_Send_singleData(qspi, Readcmd);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����

    // ���÷��͵�ַ
    QSPIx_Write_ComSet(qspi, (int32_t)QSPI_DATA_2_LINES,
                       (uint32_t)QSPI_BYTES_24_BITS,
                       (uint32_t)QSPI_CLKONLY_OFF);
    QSPIx_Send_singleData(qspi, ReadAddr);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    //	// ���ÿ�����
    qspi->TWI_QSPIx_REV = 0xA05F0700;
    QSPIx_Write_ComSet(qspi, (int32_t)QSPI_DATA_NONE,
                       (uint32_t)QSPI_BYTES_16_BITS,
                       (uint32_t)QSPI_CLKONLY_OFF);
    QSPIx_Send_singleData(qspi, 0XFF0000);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    qspi->TWI_QSPIx_REV = 0xA05F0000;

    QSPIx_Read_ComSet(qspi, (int32_t)QSPI_DATA_2_LINES,
                      (uint32_t)QSPI_BYTES_32_BITS, (uint32_t)QSPI_CLKONLY_ON);
    //	PD_BIT(0) = 0;
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_RXNEIF))
        ;
    QSPIx_Receive(qspi, pBuffer,
                  NumByteToRead); // �˴�NumByteToRead��1byteΪ��λ
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    // /CS ����
    QSPI_SET_CS_High(qspi);
}
/*==========================================
       ����SPI��ȡ FLASH ID
============================================*/
uint16_t W25Q16_QSPIReadID(TWI_QSPIx_TypeDef *qspi) {
    uint8_t u8RxData[4] = {0};

    QSPIx_Write_ComSet(qspi, (int32_t)QSPI_DATA_1_LINE,
                       (uint32_t)QSPI_BYTES_8_BITS, (uint32_t)QSPI_CLKONLY_OFF);
    // /CS ����
    QSPI_SET_CS_Low(qspi);

    // ���÷�������  0X94 Read Manufacturer/Device ID
    QSPIx_Send_singleData(qspi, 0x94);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    // ���� 24bit ��ַ��С����
    QSPIx_Write_ComSet(qspi, (int32_t)QSPI_DATA_4_LINES,
                       (uint32_t)QSPI_BYTES_32_BITS,
                       (uint32_t)QSPI_CLKONLY_OFF);
    QSPIx_Send_singleData(qspi, 0x000000);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    // ���� 3��Dummy
    qspi->TWI_QSPIx_REV = 0xA05F0700;
    QSPIx_Write_ComSet(qspi, (int32_t)QSPI_DATA_NONE,
                       (uint32_t)QSPI_BYTES_32_BITS,
                       (uint32_t)QSPI_CLKONLY_OFF);
    QSPIx_Send_singleData(qspi, 0xFF0000);
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    qspi->TWI_QSPIx_REV = 0xA05F0000;

    // �ض� 2�� bytes
    QSPIx_Read_ComSet(qspi, (int32_t)QSPI_DATA_4_LINES,
                      (uint32_t)QSPI_BYTES_16_BITS,
                      (uint32_t)QSPI_CLKONLY_ON); // yly V0.3 test
    PD_BIT(0) = 0;
    while (READ_BIT(qspi->TWI_QSPIx_STS, TWI_QSPIx_STS_BUSY))
        ; // �ȴ�BUSY����
    QSPIx_Receive(qspi, u8RxData, 1);
    DL_OK = 0;
    //	// /CS ����
    QSPI_SET_CS_High(qspi);
    //	printf("%X\n",(u8RxData[0] ) | u8RxData[1]<<8);
    return ((u8RxData[0]) | u8RxData[1] << 8);
}
