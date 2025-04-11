//*************************************************************************************************
//  Copyright (c) 	深圳市赛元微电子有限公司
//	文件名称	:  S_TouchKeyCFG.h
//	作者		:
//	模块功能	:  触控键配置文件
// 	版本		:  V0.1
// 	更改记录	:
//************************************************************************************************
#ifndef __S_TOUCHKEYCFG_H__
#define __S_TOUCHKEYCFG_H__

#define SOCAPI_SET_TOUCHKEY_TOTAL 4
#define SOCAPI_SET_TOUCHKEY_CHANNEL 0x0003C000
const unsigned int TKCFG[17] = {0, 0, 0, 5, 10, 3000,  200,   100, 2,
                                0, 0, 4, 0, 1,  65535, 65535, 0};
const unsigned char TKChannelCfg[4][10] = {
    0x03, 0x02, 0x44, 0x04, 0x08, 0x03, 0x15, 0x05, 0x01, 0xe5,
    0x03, 0x02, 0x44, 0x04, 0x08, 0x03, 0x1a, 0x05, 0x01, 0xe5,
    0x03, 0x02, 0x44, 0x04, 0x08, 0x03, 0x1c, 0x05, 0x01, 0xe5,
    0x03, 0x02, 0x44, 0x04, 0x08, 0x03, 0x20, 0x05, 0x01, 0xe5,
};

#endif
