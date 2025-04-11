#ifndef __MAIN_H
#define __MAIN_H

#include "function_init.h"
/* Reset Operations */
#define RESET_ENABLE_CMD 0x66
#define RESET_MEMORY_CMD 0x99

/* Identification Operations */
#define READ_ID_CMD 0x9E
#define READ_ID_CMD2 0x9F
#define MULTIPLE_IO_READ_ID_CMD 0xAF
#define READ_SERIAL_FLASH_DISCO_PARAM_CMD 0x5A

/* Read Operations */
#define READ_CMD 0x03
#define READ_4_BYTE_ADDR_CMD 0x13

#define FAST_READ_CMD 0x0B
#define FAST_READ_DTR_CMD 0x0D
#define FAST_READ_4_BYTE_ADDR_CMD 0x0C

#define DUAL_OUT_FAST_READ_CMD 0x3B
#define DUAL_OUT_FAST_READ_DTR_CMD 0x3D
#define DUAL_OUT_FAST_READ_4_BYTE_ADDR_CMD 0x3C

#define DUAL_INOUT_FAST_READ_CMD 0xBB
#define DUAL_INOUT_FAST_READ_DTR_CMD 0xBD
#define DUAL_INOUT_FAST_READ_4_BYTE_ADDR_CMD 0xBC

#define QUAD_OUT_FAST_READ_CMD 0x6B
#define QUAD_OUT_FAST_READ_DTR_CMD 0x6D
#define QUAD_OUT_FAST_READ_4_BYTE_ADDR_CMD 0x6C

#define QUAD_INOUT_FAST_READ_CMD 0xEB
#define QUAD_INOUT_FAST_READ_DTR_CMD 0xED
#define QUAD_INOUT_FAST_READ_4_BYTE_ADDR_CMD 0xEC

/* Write Operations */
#define WRITE_ENABLE_CMD 0x06
#define WRITE_DISABLE_CMD 0x04

/* Register Operations */
#define READ_STATUS_REG_CMD 0x05
#define WRITE_STATUS_REG_CMD 0x01

#define READ_LOCK_REG_CMD 0xE8
#define WRITE_LOCK_REG_CMD 0xE5

#define READ_FLAG_STATUS_REG_CMD 0x70
#define CLEAR_FLAG_STATUS_REG_CMD 0x50

#define READ_NONVOL_CFG_REG_CMD 0xB5
#define WRITE_NONVOL_CFG_REG_CMD 0xB1

#define READ_VOL_CFG_REG_CMD 0x85
#define WRITE_VOL_CFG_REG_CMD 0x81

#define READ_ENHANCED_VOL_CFG_REG_CMD 0x65
#define WRITE_ENHANCED_VOL_CFG_REG_CMD 0x61

#define READ_EXT_ADDR_REG_CMD 0xC8
#define WRITE_EXT_ADDR_REG_CMD 0xC5

/* Program Operations */
#define PAGE_PROG_CMD 0x02
#define PAGE_PROG_4_BYTE_ADDR_CMD 0x12

#define DUAL_IN_FAST_PROG_CMD 0xA2
#define EXT_DUAL_IN_FAST_PROG_CMD 0xD2

#define QUAD_IN_FAST_PROG_CMD 0x32
#define EXT_QUAD_IN_FAST_PROG_CMD 0x12 /*0x38*/
#define QUAD_IN_FAST_PROG_4_BYTE_ADDR_CMD 0x34

/* Erase Operations */
#define SUBSECTOR_ERASE_CMD 0x20
#define SUBSECTOR_ERASE_4_BYTE_ADDR_CMD 0x21

#define SECTOR_ERASE_CMD 0xD8
#define SECTOR_ERASE_4_BYTE_ADDR_CMD 0xDC

#define BULK_ERASE_CMD 0xC7

#define PROG_ERASE_RESUME_CMD 0x7A
#define PROG_ERASE_SUSPEND_CMD 0x75

/* One-Time Programmable Operations */
#define READ_OTP_ARRAY_CMD 0x4B
#define PROG_OTP_ARRAY_CMD 0x42

/* 4-byte Address Mode Operations */
#define ENTER_4_BYTE_ADDR_MODE_CMD 0xB7
#define EXIT_4_BYTE_ADDR_MODE_CMD 0xE9

/* Quad Operations */
#define ENTER_QUAD_CMD 0x35
#define EXIT_QUAD_CMD 0xF5

void SC_QSPI_Init(TWI_QSPIx_TypeDef *qspi);
void QSPI_Cmd(TWI_QSPIx_TypeDef *QSPIx, FunctionalState NewState);
void QSPIx_EnableInt(TWI_QSPIx_TypeDef *qspi);
void QSPIx_0_1_Open(TWI_QSPIx_TypeDef *qspi, uint32_t Functioning,
                    uint32_t MODE, uint32_t ClockPrescaler, uint32_t SPOS,
                    uint32_t SSHIFT, uint32_t Enable);
void IO_Init(void);
void QSPI_SET_CS_High(TWI_QSPIx_TypeDef *qspi);
void QSPI_SET_CS_Low(TWI_QSPIx_TypeDef *qspi);
void QSPIx_Send_singleData(TWI_QSPIx_TypeDef *qspi, uint32_t buf);
void QSPIx_Send_multipleData(TWI_QSPIx_TypeDef *qspi, uint8_t *buf,
                             uint32_t len);
// void QSPIx_Strmode_ComSet( TWI_QSPIx_TypeDef *qspi, uint32_t STRDIR, uint32_t
// STRTEN,uint32_t STRREN);
void QSPIx_Receive(TWI_QSPIx_TypeDef *qspi, uint8_t *buf, uint32_t len);
void QSPIx_Write_ComSet(TWI_QSPIx_TypeDef *QSPIx, int32_t LMODE,
                        uint32_t DWIDTH, uint32_t CLKONLY);
void QSPIx_Read_ComSet(TWI_QSPIx_TypeDef *QSPIx, int32_t LMODE, uint32_t DWIDTH,
                       uint32_t CLKONLY);
void DispPic_str(TWI_QSPIx_TypeDef *qspi);
void QSPIx_Enable(TWI_QSPIx_TypeDef *qspi);
void QSPI_DMACmd(TWI_QSPIx_TypeDef *QSPIx, uint16_t QSPI_DMAReq,
                 FunctionalState NewState);
uint16_t W25Q16_QSPIReadID(TWI_QSPIx_TypeDef *qspi);
void W25QXX_WaitIdle(TWI_QSPIx_TypeDef *qspi);
void W25QXX_Read(TWI_QSPIx_TypeDef *qspi, uint8_t *pBuffer, uint8_t Readcmd,
                 uint32_t ReadAddr, uint32_t NumByteToRead);
void W25QXX_EraseSector(TWI_QSPIx_TypeDef *qspi, uint32_t sector_id);
void W25QXX_Write_Page(TWI_QSPIx_TypeDef *qspi, uint8_t *pBuffer,
                       uint32_t WriteAddr, uint16_t NumByteToWrite);
void Delay(uint32_t count);
void W25QXX_DualRead(TWI_QSPIx_TypeDef *qspi, uint8_t *pBuffer, uint8_t Readcmd,
                     uint32_t ReadAddr, uint32_t NumByteToRead);
// 直通函数
void W25QXX_FastRead(TWI_QSPIx_TypeDef *qspi,
                     // uint8_t* pBuffer,
                     uint8_t Readcmd, uint32_t ReadAddr,
                     uint32_t NumByteToRead);

extern uint8_t QSPI_Receive_Buffer[30];
extern uint8_t FLASH_OK;
extern uint32_t TK_exKeyValueFlag;

#endif /* __MAIN_H */
