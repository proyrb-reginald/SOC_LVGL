/**
******************************************************************************
* @file    SC32.h
* @author  SOC AE Team
* @version V0.1
* @date    29-09-2024
* @brief
*
******************************************************************************
* @attention
*
*1.This software is supplied by SinOne Microelectronics Co.,Ltd. and is only
*intended for use with SinOne products. No other uses are authorized. This
*software is owned by SinOne Microelectronics Co.,Ltd. and is protected under
*all applicable laws, including copyright laws.
*2.The software which is for guidance only aims at providing customers with
*coding information regarding their products in order for them to save time.
*As a result, SinOne shall not be held liable for any direct, indirect or
*consequential damages with respect to any claims arising from the content of
*such software and/or the use made by customers of the coding information
*contained herein in connection with their products.
*
*  COPYRIGHT 2024 SinOne Microelectronics
*/
/** @addtogroup CMSIS_Device
 * @{
 */

/** @addtogroup sc32
 * @{
 */

#ifndef SC32_H
#define SC32_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* Exported macro ------------------------------------------------------------*/
#ifdef USE_FULL_ASSERT
/**
 * @brief  The assert_param macro is used for function's parameters check.
 * @param  expr: If expr is false, it calls assert_failed function
 *         which reports the name of the source file and the source
 *         line number of the call that failed.
 *         If expr is true, it returns no value.
 * @retval None
 */
#define assert_param(expr)                                                     \
    ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
void assert_failed(uint8_t *file, uint32_t line);
#else
#define assert_param(expr) ((void)0U)
#endif /* USE_FULL_ASSERT */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* SC32_H */

/**
 * @}
 */

/**
 * @}
 */

/************************ (C) COPYRIGHT SIN ONE CHIP *****END OF FILE****/
