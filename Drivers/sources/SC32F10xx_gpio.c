/**
 ******************************************************************************
 * @file    SC32F10xx_gpio.c
 * @author  soc
 * @version V1.0.1
 * @date    07-9-2021
 * @brief   This file provides firmware functions to manage the following
 *          functionalities of the GPIO peripheral:
 *           + Initialization and Configuration functions
 *           + GPIO Read and Write functions
 *
 *  @verbatim
 **/

/* Includes ------------------------------------------------------------------*/
#include "sc32f10xx_gpio.h"

/** @addtogroup SC32F10xx_StdPeriph_Driver
 * @{
 */

/** @defgroup GPIO
 * @brief GPIO driver modules
 * @{
 */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup GPIO_Private_Functions
 * @{
 */

/** @defgroup GPIO_Group1 Initialization and Configuration
 *  @brief   Initialization and Configuration
 *
@verbatim
 ===============================================================================
                    ##### Initialization and Configuration #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
 * @brief  Deinitializes the GPIOx peripheral registers to their default reset
 *         values.
 * @param  GPIOx: where x can be (1, 2, 3, 4, 5 or 6) to select the GPIO
 * peripheral.
 * @note
 * @note   初始默认IO为高阻输入态
 * @retval None
 */

void GPIO_DeInit(GPIO_TypeDef *GPIOx) {
    /* Check the parameters */
    // assert_param(IS_GPIO_ALL_PERIPH(GPIOX));
    GPIOx->PXCON = 0x00;
    GPIOx->PXPH = 0x00;
    GPIOx->PIN = 0xFF;
}

/**
 * @brief  Deinitializes the GPIOx peripheral registers
 * @param  GPIOx: where x can be 0 to select the GPIO peripheral.
 * @note   GPIOx只能设置为GPIO0
 * @note   配置IO的模式，上拉输入状态
 * @retval None
 */
void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct) {
    //	assert_param(IS_GPIO_0_PERIPH(GPIOx));
    //  assert_param(IS_GPIO_PIN(GPIO_InitStruct->GPIO_Pin));
    //	assert_param(IS_GPIO_MODE(GPIO_InitStruct->GPIO_Mode));
    //  assert_param(IS_GPIO_PUPD(GPIO_InitStruct->GPIO_PuPd));
    uint32_t pinpos = 0x00, pos = 0x00;
    for (pinpos = 0x00; pinpos < 0x10; pinpos++) {
        pos = ((uint32_t)0x01) << pinpos;
        if ((GPIO_InitStruct->GPIO_Pin) & pos) {
            GPIOx->PXCON &= ~pos;
            GPIOx->PXCON |= (uint32_t)GPIO_InitStruct->GPIO_Mode
                            << pinpos; // SET PXCON
            GPIOx->PXPH &= ~pos;
            GPIOx->PXPH |= (uint32_t)GPIO_InitStruct->GPIO_PuPd
                           << pinpos; // SET PXPH
        }
    }
}
/**
 * @brief  Sets the selected data port bits.
 * @param  GPIOx: where x can be (0, 1, 2, 3, 4 or 5) to select the GPIO
 * peripheral.
 * @note
 * @note
 * @param  GPIO_Pin: specifies the port bits to be written.
 * @note
 * @retval None
 */
void GPIO_SetBits(GPIO_BIT_TypeDef *GPIOx_BIT, uint16_t GPIO_Pin) {
    /* Check the parameters */
    ////	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    uint32_t pinpos = 0x00, pos = 0x00;
    uint8_t *GPIOBitx = (uint8_t *)&GPIOx_BIT->PIN_BIT[0];
    for (pinpos = 0x00; pinpos < 0x10; pinpos++) {
        pos = ((uint32_t)0x01) << pinpos;
        if (GPIO_Pin & pos) {
            *(GPIOBitx + pinpos) = Bit_SET;
        }
    }
}
/**
 * @brief  Sets the selected data port bits.
 * @param  GPIOx: where x can be (0, 1, 2, 3, 4 or 5) to select the GPIO
 * peripheral.
 * @note
 * @note
 * @param  GPIO_Pin: specifies the port bits to be written.
 * @note
 * @retval None
 */
void GPIO_ResetBits(GPIO_BIT_TypeDef *GPIOx_BIT, uint16_t GPIO_Pin) {
    /* Check the parameters */
    //	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    //	assert_param(IS_GPIO_PIN(GPIO_Pin));
    uint32_t pinpos = 0x00, pos = 0x00;
    uint8_t *GPIOBitx = (uint8_t *)&GPIOx_BIT->PIN_BIT[0];
    for (pinpos = 0x00; pinpos < 0x10; pinpos++) {
        pos = ((uint32_t)0x01) << pinpos;
        if (GPIO_Pin & pos) {
            *(GPIOBitx + pinpos) = Bit_SET;
        }
    }
}

/** @defgroup GPIO_Group2 GPIO Read and Write
 *  @brief   GPIO Read and Write
 *
@verbatim
 ===============================================================================
                      ##### GPIO Read and Write #####
 ===============================================================================

@endverbatim
  * @{
  */

/**
 * @brief  Reads the specified input port pin.
 * @param  GPIOx: where x can be (0, 1, 2, 3, 4 or 5) to select the GPIO
 * peripheral.
 * @note
 * @note
 * @param  GPIO_Pin: specifies the port bit to read.
 * @note
 * @retval The input port pin value.
 */
uint8_t GPIO_ReadInputDataBit(GPIO_BIT_TypeDef *GPIOx_BIT, uint16_t GPIO_Pin) {
    uint8_t bitstatus = 0x00;

    /* Check the parameters */
    //  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    //  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
    uint8_t *GPIOBitx = (uint8_t *)&GPIOx_BIT;
    uint32_t pinpos = 0x00, pos = 0x00;
    for (pinpos = 0x00; pinpos < 0x10; pinpos++) {
        pos = ((uint32_t)0x01) << pinpos;
        if (GPIO_Pin & pos) {
            if (*(GPIOBitx + pinpos) != (uint8_t)Bit_RESET) {
                bitstatus = (uint8_t)Bit_SET;
            } else {
                bitstatus = (uint8_t)Bit_RESET;
            }
            break;
        }
    }
    return bitstatus;
}

/**
 * @brief  Reads the specified input port pin.
 * @param  GPIOx: where x can be (1, 2, 3, 4, 5) to select the GPIO peripheral.
 * @note
 * @note
 * @retval The input port pin value.
 */
uint16_t GPIOx_ReadInputData(GPIO_TypeDef *GPIOx) {
    /* Check the parameters */
    // assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

    return ((uint16_t)GPIOx->PIN);
}

/**
 * @brief  Reversal port pin out.
 * @param  GPIOx: where x can be (0) to select the GPIO peripheral.
 * @note
 * @note
 * @retval The input port pin value.
 */
void GPIO_ReversalBits(GPIO_BIT_TypeDef *GPIOx_BIT, uint16_t GPIO_Pin) {
    /* Check the parameters */
    //	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    // assert_param(IS_GPIO_PIN(GPIO_Pin));
    uint8_t *OverTrunx = (uint8_t *)&GPIOx_BIT->PIN_XR[0];
    uint32_t pinpos = 0x00, pos = 0x00;
    for (pinpos = 0x00; pinpos < 0x08; pinpos++) {
        pos = ((uint32_t)0x01) << pinpos;
        if (GPIO_Pin & pos) {
            *(OverTrunx + pinpos) = Bit_SET;
        }
    }
}
/**
 * @brief  Sets or clears the selected data port bit.
 * @param  GPIOx: where x can be (0, 1, 2, 3, 4 or 5) to select the GPIO
 * peripheral.
 * @note
 * @note
 * @param  GPIO_Pin: specifies the port bit to be written.
 * @param  BitVal: specifies the value to be written to the selected bit.
 *          This parameter can be one of the BitAction enumeration values:
 *            @arg Bit_RESET: to clear the port pin
 *            @arg Bit_SET: to set the port pin
 * @note
 * @retval None
 */
void GPIO_WriteBit(GPIO_BIT_TypeDef *GPIOx_BIT, uint16_t GPIO_Pin,
                   BitAction BitVal) {
    /* Check the parameters */
    //  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    //  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
    //  assert_param(IS_GPIO_BIT_ACTION(BitVal));

    if (BitVal != Bit_RESET) {
        GPIO_ResetBits(GPIOx_BIT, GPIO_Pin);
    } else {
        GPIO_SetBits(GPIOx_BIT, GPIO_Pin);
    }
}

/**
 * @brief  Writes data to the specified GPIO data port.
 * @param  GPIOx: where x can be (0, 1, 2, 3, 4 or 5) to select the GPIO
 * peripheral.
 * @note
 * @note
 * @param  PortVal: specifies the value to be written to the port output data
 * register.
 * @retval None
 */
void GPIOx_Write(GPIO_TypeDef *GPIOx, uint16_t PortVal) {
    /* Check the parameters */
    // assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    GPIOx->PIN = PortVal;
}

#if 0
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
  uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00;

  /* Check the parameters */
 // assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  //assert_param(IS_GPIO_PIN(GPIO_InitStruct->GPIO_Pin));
 // assert_param(IS_GPIO_MODE(GPIO_InitStruct->GPIO_Mode));
 // assert_param(IS_GPIO_PUPD(GPIO_InitStruct->GPIO_PuPd));

  /*-------------------------- Configure the port pins -----------------------*/
  /*-- GPIO Mode Configuration --*/
  for (pinpos = 0x00; pinpos < 0x10; pinpos++)
  {
    pos = ((uint32_t)0x01) << pinpos;

    /* Get the port pins position */
    currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;

    if (currentpin == pos)
    {
      if ((GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT) || (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_AF))
      {
        /* Check Speed mode parameters */
       // assert_param(IS_GPIO_SPEED(GPIO_InitStruct->GPIO_Speed));

        /* Speed mode configuration */
        GPIOx->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED0 << (pinpos * 2));//修改
        GPIOx->OSPEEDR |= ((uint32_t)(GPIO_InitStruct->GPIO_Speed) << (pinpos * 2));

        /* Check Output mode parameters */
      // assert_param(IS_GPIO_OTYPE(GPIO_InitStruct->GPIO_OType));

        /* Output mode configuration */
        GPIOx->OTYPER &= ~((GPIO_OTYPER_OT0) << ((uint16_t)pinpos));//修改
        GPIOx->OTYPER |= (uint16_t)(((uint16_t)GPIO_InitStruct->GPIO_OType) << ((uint16_t)pinpos));
      }

      GPIOx->MODER  &= ~(GPIO_MODER_MODE0 << (pinpos * 2));  //修改

      GPIOx->MODER |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << (pinpos * 2));

      /* Pull-up Pull down resistor configuration */
      GPIOx->PUPDR &= ~(GPIO_PUPDR_PUPD0 << ((uint16_t)pinpos * 2));  //修改
      GPIOx->PUPDR |= (((uint32_t)GPIO_InitStruct->GPIO_PuPd) << (pinpos * 2));
    }
  }
}


/**
  * @brief  Sets the selected data port bits.
  * @param  GPIOx: where x can be (A, B, C, D, E or F) to select the GPIO peripheral.
  * @note   GPIOE is available only for STM32F072.
  * @note   GPIOD is not available for STM32F031.    
  * @param  GPIO_Pin: specifies the port bits to be written.
  * @note   This parameter can be GPIO_Pin_x where x can be:
  *         For STM32F051 and STM32F030: (0..15) for GPIOA, GPIOB, GPIOC, (2) for GPIOD and (0..1, 4..7) for GIIOF.
  *         For STM32F072: (0..15) for GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, (0..10) for GPIOF.
  *         For STM32F031: (0..15) for GPIOA, GPIOB, (13..15) for GPIOC and (0..1, 6..7) for GPIOF. 
  * @retval None
  */
void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));

  GPIOx->BSRR = GPIO_Pin;
}

/**
  * @brief  Clears the selected data port bits.
  * @param  GPIOx: where x can be (A, B, C, D, E or F) to select the GPIO peripheral.
  * @note   GPIOE is available only for STM32F072.
  * @note   GPIOD is not available for STM32F031.
  * @param  GPIO_Pin: specifies the port bits to be written.
  * @note   This parameter can be GPIO_Pin_x where x can be:
  *         For STM32F051 and STM32F030: (0..15) for GPIOA, GPIOB, GPIOC, (2) for GPIOD and (0..1, 4..7) for GIIOF.
  *         For STM32F072: (0..15) for GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, (0..10) for GPIOF.
  *         For STM32F031: (0..15) for GPIOA, GPIOB, (13..15) for GPIOC and (0..1, 6..7) for GPIOF. 
  * @retval None
  */
void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));

  GPIOx->BRR = GPIO_Pin;
}

#if 0	
/**
  * @brief  Initializes the GPIOx peripheral according to the specified 
  *         parameters in the GPIO_InitStruct.
  * @param  GPIOx: where x can be (A, B, C, D, E or F) to select the GPIO peripheral.
  * @note   GPIOE is available only for STM32F072.
  * @note   GPIOD is not available for STM32F031.   
  * @param  GPIO_InitStruct: pointer to a GPIO_InitTypeDef structure that contains
  *         the configuration information for the specified GPIO peripheral.
  * @retval None
  */
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct)
{
  uint32_t pinpos = 0x00, pos = 0x00 , currentpin = 0x00;

  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_InitStruct->GPIO_Pin));
  assert_param(IS_GPIO_MODE(GPIO_InitStruct->GPIO_Mode));
  assert_param(IS_GPIO_PUPD(GPIO_InitStruct->GPIO_PuPd));

  /*-------------------------- Configure the port pins -----------------------*/
  /*-- GPIO Mode Configuration --*/
  for (pinpos = 0x00; pinpos < 0x10; pinpos++)
  {
    pos = ((uint32_t)0x01) << pinpos;

    /* Get the port pins position */
    currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;

    if (currentpin == pos)
    {
      if ((GPIO_InitStruct->GPIO_Mode == GPIO_Mode_OUT) || (GPIO_InitStruct->GPIO_Mode == GPIO_Mode_AF))
      {
        /* Check Speed mode parameters */
        assert_param(IS_GPIO_SPEED(GPIO_InitStruct->GPIO_Speed));

        /* Speed mode configuration */
        GPIOx->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0 << (pinpos * 2));
        GPIOx->OSPEEDR |= ((uint32_t)(GPIO_InitStruct->GPIO_Speed) << (pinpos * 2));

        /* Check Output mode parameters */
        assert_param(IS_GPIO_OTYPE(GPIO_InitStruct->GPIO_OType));

        /* Output mode configuration */
        GPIOx->OTYPER &= ~((GPIO_OTYPER_OT_0) << ((uint16_t)pinpos));
        GPIOx->OTYPER |= (uint16_t)(((uint16_t)GPIO_InitStruct->GPIO_OType) << ((uint16_t)pinpos));
      }

      GPIOx->MODER  &= ~(GPIO_MODER_MODER0 << (pinpos * 2));

      GPIOx->MODER |= (((uint32_t)GPIO_InitStruct->GPIO_Mode) << (pinpos * 2));

      /* Pull-up Pull down resistor configuration */
      GPIOx->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << ((uint16_t)pinpos * 2));
      GPIOx->PUPDR |= (((uint32_t)GPIO_InitStruct->GPIO_PuPd) << (pinpos * 2));
    }
  }
}
#endif
/**
  * @brief  Fills each GPIO_InitStruct member with its default value.
  * @param  GPIO_InitStruct: pointer to a GPIO_InitTypeDef structure which will 
  *         be initialized.
  * @retval None
  */
void GPIO_StructInit(GPIO_InitTypeDef* GPIO_InitStruct)
{
  /* Reset GPIO init structure parameters values */
  GPIO_InitStruct->GPIO_Pin  = GPIO_Pin_All;
  GPIO_InitStruct->GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStruct->GPIO_Speed = GPIO_Speed_Level_2;
  GPIO_InitStruct->GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct->GPIO_PuPd = GPIO_PuPd_NOPULL;
}

/**
  * @brief  Locks GPIO Pins configuration registers.
  * @note   The locked registers are GPIOx_MODER, GPIOx_OTYPER, GPIOx_OSPEEDR,
  *         GPIOx_PUPDR, GPIOx_AFRL and GPIOx_AFRH.
  * @note   The configuration of the locked GPIO pins can no longer be modified
  *         until the next device reset.
  * @param  GPIOx: where x can be (A or B) to select the GPIO peripheral.
  * @param  GPIO_Pin: specifies the port bit to be written.
  *          This parameter can be any combination of GPIO_Pin_x where x can be (0..15).
  * @retval None
  */
void GPIO_PinLockConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  __IO uint32_t tmp = 0x00010000;

  /* Check the parameters */
  assert_param(IS_GPIO_LIST_PERIPH(GPIOx));
  assert_param(IS_GPIO_PIN(GPIO_Pin));

  tmp |= GPIO_Pin;
  /* Set LCKK bit */
  GPIOx->LCKR = tmp;
  /* Reset LCKK bit */
  GPIOx->LCKR =  GPIO_Pin;
  /* Set LCKK bit */
  GPIOx->LCKR = tmp;
  /* Read LCKK bit */
  tmp = GPIOx->LCKR;
  /* Read LCKK bit */
  tmp = GPIOx->LCKR;
}

/**
  * @}
  */

/** @defgroup GPIO_Group2 GPIO Read and Write
 *  @brief   GPIO Read and Write
 *
@verbatim   
 ===============================================================================
                      ##### GPIO Read and Write #####
 ===============================================================================  

@endverbatim
  * @{
  */

/**
  * @brief  Reads the specified input port pin.
  * @param  GPIOx: where x can be (A, B, C, D, E or F) to select the GPIO peripheral.
  * @note   GPIOE is available only for STM32F072.
  * @note   GPIOD is not available for STM32F031.   
  * @param  GPIO_Pin: specifies the port bit to read.
  * @note   This parameter can be GPIO_Pin_x where x can be:
  *         For STM32F051 and STM32F030: (0..15) for GPIOA, GPIOB, GPIOC, (2) for GPIOD and (0..1, 4..7) for GIIOF.
  *         For STM32F072: (0..15) for GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, (0..10) for GPIOF.
  *         For STM32F031: (0..15) for GPIOA, GPIOB, (13..15) for GPIOC and (0..1, 6..7) for GPIOF.  
  * @retval The input port pin value.
  */
uint8_t GPIO_ReadInputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  uint8_t bitstatus = 0x00;

  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

  if ((GPIOx->IDR & GPIO_Pin) != (uint32_t)Bit_RESET)
  {
    bitstatus = (uint8_t)Bit_SET;
  }
  else
  {
    bitstatus = (uint8_t)Bit_RESET;
  }
  return bitstatus;
}

/**
  * @brief  Reads the specified input port pin.
  * @param  GPIOx: where x can be (A, B, C, D, E or F) to select the GPIO peripheral.
  * @note   GPIOE is available only for STM32F072.
  * @note   GPIOD is not available for STM32F031.   
  * @retval The input port pin value.
  */
uint16_t GPIO_ReadInputData(GPIO_TypeDef* GPIOx)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

  return ((uint16_t)GPIOx->IDR);
}

/**
  * @brief  Reads the specified output data port bit.
  * @param  GPIOx: where x can be (A, B, C, D, E or F) to select the GPIO peripheral.
  * @note   GPIOE is available only for STM32F072.
  * @note   GPIOD is not available for STM32F031.   
  * @param  GPIO_Pin: Specifies the port bit to read.
  * @note   This parameter can be GPIO_Pin_x where x can be:
  *         For STM32F051 and STM32F030: (0..15) for GPIOA, GPIOB, GPIOC, (2) for GPIOD and (0..1, 4..7) for GIIOF.
  *         For STM32F072: (0..15) for GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, (0..10) for GPIOF.
  *         For STM32F031: (0..15) for GPIOA, GPIOB, (13..15) for GPIOC and (0..1, 6..7) for GPIOF. 
  * @retval The output port pin value.
  */
uint8_t GPIO_ReadOutputDataBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  uint8_t bitstatus = 0x00;

  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

  if ((GPIOx->ODR & GPIO_Pin) != (uint32_t)Bit_RESET)
  {
    bitstatus = (uint8_t)Bit_SET;
  }
  else
  {
    bitstatus = (uint8_t)Bit_RESET;
  }
  return bitstatus;
}

/**
  * @brief  Reads the specified GPIO output data port.
  * @param  GPIOx: where x can be (A, B, C, D, E or F) to select the GPIO peripheral.
  * @note   GPIOE is available only for STM32F072.
  * @note   GPIOD is not available for STM32F031.    
  * @retval GPIO output data port value.
  */
uint16_t GPIO_ReadOutputData(GPIO_TypeDef* GPIOx)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

  return ((uint16_t)GPIOx->ODR);
}

///**
//  * @brief  Sets the selected data port bits.
//  * @param  GPIOx: where x can be (A, B, C, D, E or F) to select the GPIO peripheral.
//  * @note   GPIOE is available only for STM32F072.
//  * @note   GPIOD is not available for STM32F031.    
//  * @param  GPIO_Pin: specifies the port bits to be written.
//  * @note   This parameter can be GPIO_Pin_x where x can be:
//  *         For STM32F051 and STM32F030: (0..15) for GPIOA, GPIOB, GPIOC, (2) for GPIOD and (0..1, 4..7) for GIIOF.
//  *         For STM32F072: (0..15) for GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, (0..10) for GPIOF.
//  *         For STM32F031: (0..15) for GPIOA, GPIOB, (13..15) for GPIOC and (0..1, 6..7) for GPIOF. 
//  * @retval None
//  */
//void GPIO_SetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//{
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  assert_param(IS_GPIO_PIN(GPIO_Pin));

//  GPIOx->BSRR = GPIO_Pin;
//}

/**
  * @brief  Clears the selected data port bits.
  * @param  GPIOx: where x can be (A, B, C, D, E or F) to select the GPIO peripheral.
  * @note   GPIOE is available only for STM32F072.
  * @note   GPIOD is not available for STM32F031.
  * @param  GPIO_Pin: specifies the port bits to be written.
  * @note   This parameter can be GPIO_Pin_x where x can be:
  *         For STM32F051 and STM32F030: (0..15) for GPIOA, GPIOB, GPIOC, (2) for GPIOD and (0..1, 4..7) for GIIOF.
  *         For STM32F072: (0..15) for GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, (0..10) for GPIOF.
  *         For STM32F031: (0..15) for GPIOA, GPIOB, (13..15) for GPIOC and (0..1, 6..7) for GPIOF. 
  * @retval None
  */
//void GPIO_ResetBits(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
//{
//  /* Check the parameters */
//  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
//  assert_param(IS_GPIO_PIN(GPIO_Pin));

//  GPIOx->BRR = GPIO_Pin;
//}

/**
  * @brief  Sets or clears the selected data port bit.
  * @param  GPIOx: where x can be (A, B, C, D, E or F) to select the GPIO peripheral.
  * @note   GPIOE is available only for STM32F072.
  * @note   GPIOD is not available for STM32F031.  
  * @param  GPIO_Pin: specifies the port bit to be written.
  * @param  BitVal: specifies the value to be written to the selected bit.
  *          This parameter can be one of the BitAction enumeration values:
  *            @arg Bit_RESET: to clear the port pin
  *            @arg Bit_SET: to set the port pin
  * @note   This parameter can be GPIO_Pin_x where x can be:
  *         For STM32F051 and STM32F030: (0..15) for GPIOA, GPIOB, GPIOC, (2) for GPIOD and (0..1, 4..7) for GIIOF.
  *         For STM32F072: (0..15) for GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, (0..10) for GPIOF.
  *         For STM32F031: (0..15) for GPIOA, GPIOB, (13..15) for GPIOC and (0..1, 6..7) for GPIOF.
  * @retval None
  */
void GPIO_WriteBit(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, BitAction BitVal)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
  assert_param(IS_GPIO_BIT_ACTION(BitVal));

  if (BitVal != Bit_RESET)
  {
    GPIOx->BSRR = GPIO_Pin;
  }
  else
  {
    GPIOx->BRR = GPIO_Pin ;
  }
}

/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  GPIOx: where x can be (A, B, C, D, E or F) to select the GPIO peripheral.
  * @note   GPIOE is available only for STM32F072.
  * @note   GPIOD is not available for STM32F031.  
  * @param  PortVal: specifies the value to be written to the port output data register.
  * @retval None
  */
void GPIO_Write(GPIO_TypeDef* GPIOx, uint16_t PortVal)
{
  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

  GPIOx->ODR = PortVal;
}

/**
  * @}
  */

/** @defgroup GPIO_Group3 GPIO Alternate functions configuration functions
 *  @brief   GPIO Alternate functions configuration functions
 *
@verbatim   
 ===============================================================================
          ##### GPIO Alternate functions configuration functions #####
 ===============================================================================  

@endverbatim
  * @{
  */

/**
  * @brief  Writes data to the specified GPIO data port.
  * @param  GPIOx: where x can be (A, B, C, D, E or F) to select the GPIO peripheral.
  * @note   GPIOC, GPIOD, GPIOE and GPIOF  are available only for STM32F072 and STM32F091. 
  * @param  GPIO_PinSource: specifies the pin for the Alternate function.
  *          This parameter can be GPIO_PinSourcex where x can be (0..15) for GPIOA, GPIOB, GPIOD, GPIOE
  *          and (0..12) for GPIOC and (0, 2..5, 9..10) for GPIOF.    
  * @param  GPIO_AF: selects the pin to used as Alternate function.
  *          This parameter can be one of the following value:
  *            @arg GPIO_AF_0:  WKUP, EVENTOUT, TIM15, SPI1, TIM17, MCO, SWDAT, SWCLK,
  *                             TIM14, BOOT, USART1, CEC, IR_OUT, SPI2, TIM3, USART4,
  *                             CAN, USART2, CRS, TIM16, TIM1, TS, USART8 
  *            @arg GPIO_AF_1: USART2, CEC, TIM3, USART1, USART2, EVENTOUT, I2C1,
  *                            I2C2, TIM15, SPI2, USART3, TS, SPI1, USART7, USART8
  *                            USART5, USART4, USART6, I2C1   
  *            @arg GPIO_AF_2: TIM2, TIM1, EVENTOUT, TIM16, TIM17, USB, USART6, USART5,
  *                            USART8, USART7, USART6  
  *            @arg GPIO_AF_3: TS, I2C1, TIM15, EVENTOUT 
  *            @arg GPIO_AF_4: TIM14, USART4, USART3, CRS, CAN, I2C1, USART5
  *            @arg GPIO_AF_5: TIM16, TIM17, TIM15, SPI2, I2C2, USART6, MCO
  *            @arg GPIO_AF_6: EVENTOUT
  *            @arg GPIO_AF_7: COMP1 OUT, COMP2 OUT 
  * @note   The pin should already been configured in Alternate Function mode(AF)
  *         using GPIO_InitStruct->GPIO_Mode = GPIO_Mode_AF
  * @note   Refer to the Alternate function mapping table in the device datasheet 
  *         for the detailed mapping of the system and peripherals'alternate 
  *         function I/O pins.
  * @retval None
  */
void GPIO_PinAFConfig(GPIO_TypeDef* GPIOx, uint16_t GPIO_PinSource, uint8_t GPIO_AF)
{
  uint32_t temp = 0x00;
  uint32_t temp_2 = 0x00;

  /* Check the parameters */
  assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
  assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSource));
  assert_param(IS_GPIO_AF(GPIO_AF));

  temp = ((uint32_t)(GPIO_AF) << ((uint32_t)((uint32_t)GPIO_PinSource & (uint32_t)0x07) * 4));
  GPIOx->AFR[GPIO_PinSource >> 0x03] &= ~((uint32_t)0xF << ((uint32_t)((uint32_t)GPIO_PinSource & (uint32_t)0x07) * 4));
  temp_2 = GPIOx->AFR[GPIO_PinSource >> 0x03] | temp;
  GPIOx->AFR[GPIO_PinSource >> 0x03] = temp_2;
}

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
#endif
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
