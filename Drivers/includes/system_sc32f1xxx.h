/**
 ******************************************************************************
 * @file    SYSTEM_sc32f1xxx.h
 * @author  SOC SA Team
 * @brief   CMSIS Cortex-M0+ Device System Source File for sc32f1xxx devices.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 Sin One Chip.
 * All rights reserved.</center></h2>
 *
 ******************************************************************************
 */

/** @addtogroup CMSIS
 * @{
 */

/** @addtogroup sc32f1xxx_system
 * @{
 */

/**
 * @brief Define to prevent recursive inclusion
 */
#ifndef SYSTEM_SOC0003_H
#define SYSTEM_SOC0003_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup sc32f1xxx_System_Includes
 * @{
 */

/**
 * @}
 */

/** @addtogroup sc32f1xxx_System_Exported_types
 * @{
 */
extern uint32_t SystemCoreClock; /*!< System Clock Frequency (Core Clock) */

extern const uint32_t AHBPrescTable[16]; /*!<  AHB prescalers table values */
extern const uint32_t APBPrescTable[8];  /*!< APB prescalers table values */

/**
 * @}
 */

/** @addtogroup STM32G0xx_System_Exported_Constants
 * @{
 */

/**
 * @}
 */

/** @addtogroup STM32G0xx_System_Exported_Macros
 * @{
 */

/**
 * @}
 */

/** @addtogroup STM32G0xx_System_Exported_Functions
 * @{
 */

extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);
/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /*SYSTEM_STM32G0XX_H */

/**
 * @}
 */

/**
 * @}
 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
