//*************************************************************************************************
//  Copyright (c) 	深圳市赛元微电子股份有限公司
//	文件名称	:  SensorMethod.h
//	作者		:
//	模块功能	:  触控算法头文件
// 	版本	    :
// 	更改记录	:
//	注意事项	:
//************************************************************************************************
#ifndef _sc32f10xx_TK_FileAnalysis_H
#define _sc32f10xx_TK_FileAnalysis_H

typedef struct {
    unsigned short int Rawdata;    // 原始数据
    unsigned short int Baseline;   // 基线
    unsigned short int FilterData; // 原始数据滤波缓存区

} TK_BaseLineUpdatePar_StructDef;

typedef struct {
    unsigned char BaseLineAdjusttmp; // IA缓存数组

} TK_ParameterBuffer_StructDef;

extern TK_BaseLineUpdatePar_StructDef SingleChannelsBaseLineUpdatePar[];
extern TK_BaseLineUpdatePar_StructDef CombineChannelsBaseLineUpdatePar[];

extern TK_ParameterBuffer_StructDef SingleParameterBufferSet[];
extern TK_ParameterBuffer_StructDef CombineParameterBufferSet[];

#endif
