//*************************************************************************************************
//  Copyright (c) 	��������Ԫ΢���ӹɷ����޹�˾
//	�ļ�����	:  SensorMethod.h
//	����		:
//	ģ�鹦��	:  �����㷨ͷ�ļ�
// 	�汾	    :
// 	���ļ�¼	:
//	ע������	:
//************************************************************************************************
#ifndef _SENSORMETHOD_C_H
#define _SENSORMETHOD_C_H

#include "W1222A.h"
#include "sc32F10xx_rcc.h"

extern uint8_t TK_TouchKeyStatus; // ����ɨ����ɱ�־λ
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
