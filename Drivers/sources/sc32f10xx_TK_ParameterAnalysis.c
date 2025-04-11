//*************************************************************************************************
//  Copyright (c) 	深圳市赛元微电子股份有限公司
//	文件名称	:  sc32f10xx_TK_FileAnalysis.c
//	作者		:
//	模块功能	:  触控键配置文件
// 	版本		:
// 	更改记录	:
//	注意事项	:  用户需要配置的文件在S_TouchKeyCFG.h中
//  库版本标记	:
//************************************************************************************************
#include "sc32f10xx_TK_ParameterAnalysis.h"
#include "S_TOUCHKEYCFG.h"
#include "W1222A.h"

//===============================================================================
// 全局变量声明：该区域不可修改
uint8_t TK_TouchKeyStatus;
uint8_t CurrentChannel[SOCAPI_SET_TOUCHKEY_TOTAL];

uint8_t RestAreaCnt[SOCAPI_SET_TOUCHKEY_TOTAL];
uint8_t TouchCnt[SOCAPI_SET_TOUCHKEY_TOTAL];
uint8_t NoTouchCnt[SOCAPI_SET_TOUCHKEY_TOTAL];
uint8_t LowFingerDataCnt[SOCAPI_SET_TOUCHKEY_TOTAL];
uint8_t FloatAreaCnt[SOCAPI_SET_TOUCHKEY_TOTAL];
int16_t DifferAccum[SOCAPI_SET_TOUCHKEY_TOTAL];

TK_ParameterBuffer_StructDef
    SingleParameterBufferSet[SOCAPI_SET_TOUCHKEY_TOTAL];
TK_ParameterBuffer_StructDef
    CombineParameterBufferSet[SOCAPI_SET_TOUCHKEY_TOTAL];

TK_BaseLineUpdatePar_StructDef
    SingleChannelsBaseLineUpdatePar[SOCAPI_SET_TOUCHKEY_TOTAL];

uint8_t ConfirmTouchCnt;
int8_t SetNoiseThreshold;
uint8_t MultipleDealTpye = 0;

//===============================================================================
// 自定义变量
uint16_t UpdateBaseLNum; // 单键长按计数
uint16_t MultipleLNum;   // 多按键干扰计数

//===============================================================================
// 外部变量接口
extern uint8_t SingleCurrentChannelMax; // 当前单通道的keysensor的个数
extern uint8_t bMultiple;               // 多按键标志
extern uint8_t TK_GetIsNeedUpdateBaseline(void);

extern uint32_t TK_SensorKeyFlag(void);
extern void TK_SetNeedUpdateBaseline(void);
extern void TK_MultipleDeal(uint8_t CycleCnt);
extern void TK_TouchKey_Service(void);

/*******************************库函数基础设置，一般不需要更改***************************************/
#define SOCAPI_CFG_CYCLE_CNT                                                   \
    32 // 取值范围10-255，触控初始化数据滤出次数，以及修正值初始化修正次数，默认32，取值越大触控初始化时间越长，触控数据越稳定
#define SOCAPI_CFG_OVERLOW_MAX_COUNT                                           \
    10 // 低基线更新速度设置，代表发生低基线后，多少轮更新一次基线，更新步进noise/2，值越小基线更新速度越快
#define SOCAPI_CFG_RESET_BASELINE_CNT                                          \
    10 // 低基线更新多少次后，如果还处于低基线状态，直接强制更新基线，值越小基线更新速度越快
       // SOCAPI_CFG_OVERLOW_MAX_COUNT和SOCAPI_CFG_RESET_BASELINE_CNT的取值乘积不能大于255
/**************************************************************************************************/

/******************************************弹簧库独有***********************************************/
#define SOCAPI_SET_CS_FUNCTION 1 // 0:表示不进行CS测试,1: 表示进行CS测试,默认0
#define SOCAPI_INHIBITION_ZONE                                                 \
    8 // 抑制区间%，设置范围5-10，默认7,即（7*10）%=70%
      // ，连水时加大该参数,对讲机设置小
#define SOCAPI_MAX_KEY_MUTIPLE 300   // 多少次干扰更新基线，默认300*5=1500
#define SOCAPI_MAX_KEY_NUM_INVALID 3 // 强制更新基线按键限制个数，默认3
/**************************************************************************************************/

#define AppType 0
#define IsDoubleKey 1
#define AirSeparationDistance 2
#define CONFIRMTOUCHCNT 3
#define INIT_AUTO_UPDATE_TIME 4
#define SET_KEY_CONTI_TIME 5
#define SET_SYNC_UPDATE 6
#define SET_UPDATE_SPEED 7
#define AUTO_UPDATE_TIME 8
#define FilteredKValue 9
#define SET_ANTIJAM 10
#define BAUD 11
#define DwellTime 12
#define SaveTime 13
#define NOISE 16

#define SET_TOUCH_FREQ 0
#define SET_RESOLUTION_FACTOR 1
#define SET_RESOLUTION 2
#define SET_GAIN_CFG 3
#define SCANTIME 4
#define SET_ICHA_FACTOR 5
#define SET_ICHA 6
#define FINGER_THRESHOLD_H 8
#define FINGER_THRESHOLD_L 9

// #define   	SET_TOUCH_FREQ		 			0
// #define	  	SET_RESOLUTION		 			1
// #define   	SET_GAIN_CFG			 		2
// #define   	SCANTIME				 		3
// #define   	SET_ICHA				 		4
// #define   	FINGER_THRESHOLD_H	 		    6
// #define   	FINGER_THRESHOLD_L	 		    7

//**********************************************************************************
// 								宏定义接口调用部分
// //
//**********************************************************************************
uint8_t CFG_OVERLOW_MAX_COUNT = SOCAPI_CFG_OVERLOW_MAX_COUNT;
uint8_t CFG_RESET_BASELINE_CNT = SOCAPI_CFG_RESET_BASELINE_CNT;
uint8_t CFG_CYCLE_CNT = SOCAPI_CFG_CYCLE_CNT;

//**********************************************************************************
// 								触控参数解析函数
// //
//**********************************************************************************

/****************************************************************************
*函数名称：uint16_t TK_SetOneKeyPushResetTime(void)
*函数功能：按键最长的输出时间
*入口参数：void
*出口参数：uint16_t SOCAPI_SET_KEY_CONTI_TIME
*备注	 ：这个返回值的设置， 是根据有多长时间启动TouchKeyRestart（）一次
例如10ms 启动一次， 那SOCAPI_SET_KEY_CONTI_TIME*10ms，超过时间后此按键无效。
*****************************************************************************/
uint16_t TK_SetOneKeyPushResetTime(void) { return TKCFG[SET_KEY_CONTI_TIME]; }

/****************************************************************************
 *函数名称：uint16_t  TK_GetBaselineUpdateThreshold(void)
 *函数功能：更新速度
 *入口参数：void
 *出口参数：uint16_t
 *备注	 ：
 *****************************************************************************/
uint16_t TK_GetBaselineUpdateThreshold(void) { return TKCFG[SET_UPDATE_SPEED]; }

/****************************************************************************
 *函数名称：uint8_t TK_GetInitAutoUpdateTime(void)
 *函数功能：初始化自动校准次数
 *入口参数：void
 *出口参数：uint8_t
 *备注	 ：
 *****************************************************************************/
uint8_t TK_GetInitAutoUpdateTime(void) { return TKCFG[INIT_AUTO_UPDATE_TIME]; }

/****************************************************************************
 *函数名称：uint8_t TK_IsDoubleKeyOrSlideKey(void)
 *函数功能：检测是否是弹簧滑条或者双键
 *入口参数：void
 *出口参数：uint8_t
 *备注	 ：
 *****************************************************************************/
uint8_t TK_IsDoubleKeyOrSlideKey(void) { return TKCFG[IsDoubleKey]; }

/****************************************************************************
 *函数名称：uint8_t TK_GetCsFunction(void)
 *函数功能：进行CS 测试
 *入口参数：void
 *出口参数：uint8_t SOCAPI_SET_CS_FUNCTION
 *备注	 ：
 *****************************************************************************/
uint8_t TK_GetCsFunction(void) { return SOCAPI_SET_CS_FUNCTION; }

/****************************************************************************
 *函数名称：uint8_t TK_GetUpConfirmCnt(void)
 *函数功能：检测按键弹起次数
 *入口参数：void
 *出口参数：返回按键弹起确认次数
 *备注	 ：
 *****************************************************************************/
uint8_t TK_GetUpConfirmCnt(void) { return ConfirmTouchCnt >> 1; }

/****************************************************************************
 *函数名称：uint8_t TK_GetTKYzCnt(void)
 *函数功能：获取按键抑制确认次数
 *入口参数：void
 *出口参数：返回抑制次数
 *备注	 ：
 *****************************************************************************/
uint8_t TK_GetTKYzCnt(void) { return (ConfirmTouchCnt / 3); }

/****************************************************************************
 *函数名称：uint16_t  TK_GetCurrFingerValue(uint8_t i)
 *函数功能：获取当前的finger 值
 *入口参数：uint8_t
 *出口参数：uint16_t
 *备注	 ：
 *****************************************************************************/
uint16_t TK_GetCurrFingerValue(uint8_t i) {
    return TKChannelCfg[i][FINGER_THRESHOLD_H] * 256 +
           TKChannelCfg[i][FINGER_THRESHOLD_L];
}

/****************************************************************************
 *函数名称：uint8_t TK_GetScanTimeValue(uint8_t i)
 *函数功能：获取当前通道的扫描时间
 *入口参数：uint8_t
 *出口参数：uint8_t
 *备注	 ：
 *****************************************************************************/
uint8_t TK_GetScanTimeValue(uint8_t i) { return TKChannelCfg[i][SCANTIME]; }

/****************************************************************************
*函数名称：uint8_t TK_GetBaseLineAdjustValue(uint8_t i)
*函数功能：获取当前通道的基线调整
j
*入口参数：uint8_t
*出口参数：uint8_t
*备注	 ：
*****************************************************************************/
uint8_t TK_GetBaseLineAdjustValue(uint8_t i) {
    return SingleParameterBufferSet[i].BaseLineAdjusttmp;
}

/****************************************************************************
 *函数名称：uint16_t TK_GetTKYzThreshold(uint8_t i)
 *函数功能：获取按键抑制区间
 *入口参数：uint8_t i
 *出口参数：返回抑制区间
 *备注	 ：
 *****************************************************************************/
uint16_t TK_GetTKYzThreshold(uint8_t i) {
    uint16_t SetFingerThresholdtmp;

    SetFingerThresholdtmp = TK_GetCurrFingerValue(i);
    SetFingerThresholdtmp = SetFingerThresholdtmp * SOCAPI_INHIBITION_ZONE / 10;

    return SetFingerThresholdtmp;
}

/****************************************************************************
 *函数名称：void TK_SingleCurrentSensorChoose(void)
 *函数功能：当前单通道选择
 *入口参数：void
 *出口参数：void
 *备注	 ：
 *****************************************************************************/
void TK_SingleCurrentSensorChoose(void) {
    uint8_t i = 0;
    uint8_t Ctk_Channel_mark = 0;
    uint32_t CurrentSensorKey;

    CurrentSensorKey = SOCAPI_SET_TOUCHKEY_CHANNEL;

    for (i = 0; i < 32; i++) {
        if ((0x01L << i) & CurrentSensorKey) {
            CurrentChannel[Ctk_Channel_mark] = i; // 选择触摸当前的通道
            Ctk_Channel_mark++;
            if (Ctk_Channel_mark >= SOCAPI_SET_TOUCHKEY_TOTAL)
                break;
        }
    }
    SingleCurrentChannelMax = Ctk_Channel_mark; // 当前选择的按键数
}

/****************************************************************************
 *函数名称：uint8_t  TK_GetCfgMsg(uint8_t i,uint8_t j)
 *函数功能：获取Touch KEY 配置信息
 *入口参数：void
 *出口参数：
 *备注	 ：
 *****************************************************************************/
uint8_t TK_GetCfgMsg(uint8_t i, uint8_t j) {
    switch (j) {
    case 0:
        return TKChannelCfg[i][SET_TOUCH_FREQ];
    case 1:
        return TKChannelCfg[i][SET_RESOLUTION];
    case 2:
        return TKChannelCfg[i][SET_GAIN_CFG];
    case 3:
        return TK_GetBaseLineAdjustValue(i);
    case 4:
        return TKCFG[SET_ANTIJAM];
    case 5:
        return TKChannelCfg[i][SET_RESOLUTION_FACTOR];
    case 6:
        return TKChannelCfg[i][SET_ICHA_FACTOR];

    default:
        return 0;
    }
}

/****************************************************************************
 *函数名称：void TK_TouchKeyCFGInit(void)
 *函数功能：初始化TK寄存器
 *入口参数：void
 *出口参数：void
 *备注	 ：
 *****************************************************************************/
void TK_TouchKeyCFGInit(void) {
    uint8_t i;
    ConfirmTouchCnt = TKCFG[CONFIRMTOUCHCNT];
    SetNoiseThreshold = TKCFG[NOISE];
    TK_SingleCurrentSensorChoose();
    for (i = 0; i < SingleCurrentChannelMax; i++) {
        SingleParameterBufferSet[i].BaseLineAdjusttmp =
            TKChannelCfg[i][SET_ICHA];
        ;
    }
    UpdateBaseLNum = 0;
}

/****************************************************************************
*函数名称：uint32_t TK_TouchKeyScan(void)
*函数功能：检测按键接口
*入口参数：void
*出口参数：按键通道， 返回的是一个uint32_t , 通道数4个字节0x00000000
*备注	 ：1,  调用触控库检测函数SensorKeyFlag()
                   2,  分析得出31个通道，哪个通道有按下，按下bit
位设置为1，否则为0 3,  检测是否需要立即更新baseline:  大于MAX_KEY_RESET_BASELINE
个按键按下时立即更新baseline 4,  双键或者单键按下时，
时间大于SetOneKeyPushResetTime()结果时更新baseline
*****************************************************************************/
uint32_t TK_TouchKeyScan(void) {
    uint8_t t;
    uint8_t MultipleCnt = 0; // 按键计数
    uint32_t Keyvalue;
    uint32_t KeyData = 0;

    if (TK_GetIsNeedUpdateBaseline() == 0) // 检测是否需要更新baseline
    {
        Keyvalue = TK_SensorKeyFlag(); // Sensor判断, 这里如果bMultiple = 1
                                       // 表示中间有干扰
                                       // //分析按键，得出标准的通道bit 位

        for (t = 0; t < SingleCurrentChannelMax; t++) {
            if ((0x01L << t) & Keyvalue) {
                KeyData |= ((uint32_t)0x01 << (CurrentChannel[t]));
                MultipleCnt++;
            }
        }

        if (MultipleCnt >= 2) // 进入多按键处理
        {
            bMultiple = 1;
            if (MultipleCnt >= SOCAPI_MAX_KEY_NUM_INVALID) {
                TK_SetNeedUpdateBaseline(); // 立即更新baseline
                                            // ,例如亚克力板盖上去
            } else {
                if (TK_IsDoubleKeyOrSlideKey()) {
                    bMultiple = 0;
                }
            }
        }

        if (bMultiple == 0) // 进入按键判断
        {
            if (KeyData !=
                0x0) // 单个按键达到多长时间就update baseline ,松手检测
            {
                UpdateBaseLNum++;
            } else {
                UpdateBaseLNum = 0;
            }
        } else {
            // 考虑基线更新
            MultipleLNum++;
            KeyData = 0x00;
        }

        if (UpdateBaseLNum >=
            TK_SetOneKeyPushResetTime()) // 按键超出最长输出时间更新基线
        {
            TK_SetNeedUpdateBaseline();
            UpdateBaseLNum = 0;
        }

        if (MultipleLNum >
            SOCAPI_MAX_KEY_MUTIPLE) // 干扰计数大于最大计数更新基线
        {
            TK_SetNeedUpdateBaseline();
            MultipleDealTpye = 1;
            MultipleLNum = 0;
        }
    } else {
        TK_MultipleDeal(TKCFG[AUTO_UPDATE_TIME]); // 基线复位处理
    }

    return KeyData;
}

/****************************************************************************
 *函数名称：void TK_IRQHandler(void)
 *函数功能：触摸中断服务函数
 *入口参数：void
 *出口参数：void
 *备注	 ：
 *****************************************************************************/
void TK_IRQHandler(void) { TK_TouchKey_Service(); }
