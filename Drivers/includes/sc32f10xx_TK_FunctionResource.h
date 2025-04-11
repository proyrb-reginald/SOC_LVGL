//*************************************************************************************************
//  Copyright (c) 	深圳市赛元微电子股份有限公司
//	文件名称	:  SensorMethod.h
//	作者		:
//	模块功能	:  触控算法头文件
// 	版本	    :
// 	更改记录	:
//	注意事项	:
//************************************************************************************************
#ifndef _SENSORMETHOD_C_H
#define _SENSORMETHOD_C_H

#include "W1222A.h"
#include "sc32F10xx_rcc.h"

extern uint8_t TK_TouchKeyStatus; // 按键扫描完成标志位
extern uint8_t ConfirmTouchCnt;

extern uint8_t RestAreaCnt[];
extern uint8_t TouchCnt[];
extern uint8_t NoTouchCnt[];
extern uint8_t CurrentChannel[];
extern uint8_t LowFingerDataCnt[];
extern int16_t DifferAccum[];
extern uint8_t FloatAreaCnt[];
extern uint8_t MultipleDealTpye;
extern int8_t SetNoiseThreshold;

extern void TK_Init(void);
extern void TK_Restart(void);
extern uint32_t TK_TouchKeyScan(void);
#endif
