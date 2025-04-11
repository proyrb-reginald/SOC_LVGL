//*************************************************************************************************
//  Copyright (c) 	深圳市赛元微电子股份有限公司
//	文件名称	:
//	作者		:
//	模块功能	:
// 	版本	    :
// 	更改记录	:
//	注意事项	:
//************************************************************************************************
#ifndef _sc32f10xx_TK_DynamicDebug_H
#define _sc32f10xx_TK_DynamicDebug_H

extern void TK_DynamicDebug_Init(
    unsigned int
        TK_UART_ClockFrequency); // TK_UART_ClockFrequency入参用于填写当前系统主频，例如当前是32M,函数入参TK_UART_ClockFrequency填写32000000.
                                 // 请知悉。

#endif
