
#ifndef SOC32G0xx_H
#define SOC32G0xx_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#if !defined(SOC32G0)
#define SOC32G0
#endif /* STM32G0 */

/*  Tip: To avoid modifying this file each time you need to switch between these
        devices, you can define the device in your toolchain compiler
   preprocessor.
  */
/**
 * @brief CMSIS Device version number $VERSION$
 */
#define __SOC32G0_CMSIS_VERSION_MAIN (0x01U) /*!< [31:24] main version */
#define __SOC32G0_CMSIS_VERSION_SUB1 (0x03U) /*!< [23:16] sub1 version */
#define __SOC32G0_CMSIS_VERSION_SUB2 (0x00U) /*!< [15:8]  sub2 version */
#define __SOC32G0_CMSIS_VERSION_RC (0x00U)   /*!< [7:0]  release candidate */
#define __SOC32G0_CMSIS_VERSION                                                \
    ((__SOC32G0_CMSIS_VERSION_MAIN << 24) |                                    \
     (__SOC32G0_CMSIS_VERSION_SUB1 << 16) |                                    \
     (__SOC32G0_CMSIS_VERSION_SUB2 << 8) | (__SOC32G0_CMSIS_VERSION_RC))

/**
 * @}
 */

typedef enum { RESET = 0, SET = !RESET } FlagStatus, ITStatus;

typedef enum { DISABLE = 0, ENABLE = !DISABLE } FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum { SUCCESS = 0, ERROR = !SUCCESS } ErrorStatus;

/**
 * @}
 */

/** @addtogroup Exported_macros
 * @{
 */
#define SET_BIT(REG, BIT) ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT) ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT) ((REG) & (BIT))

#define CLEAR_REG(REG) ((REG) = (0x0))

#define WRITE_REG(REG, VAL) ((REG) = (VAL))

#define READ_REG(REG) ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)                                    \
    WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/*#define POSITION_VAL(VAL)     (__CLZ(__RBIT(VAL)))*/
/**
 * @}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
