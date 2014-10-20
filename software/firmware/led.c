#include "led.h"


GPIO_TypeDef* LED_PORT[LEDn] = {
	LED0_PORT,
};

const uint16_t LED_PIN[LEDn] = {
	LED0_PIN,
};

static void LEDx_GPIO_CLK_ENABLE(LED_TypeDef led)
{
	switch (led) {
	  case LED0:
			LED0_CLK_ENABLE();
			break;
		default:
			break;
	}
	return;
}

static void LEDx_GPIO_CLK_DISABLE(LED_TypeDef led)
{
	switch (led) {
	  case LED0:
			LED0_CLK_DISABLE();
			break;
		default:
			break;
	}
	return;
}

/**
  * @brief  Configures LED GPIO.
  * @param  Led: Specifies the Led to be configured. 
  *   This parameter can be one of following parameters:
  *     @arg LED2
  * @retval None
  */
void BSP_LED_Init(LED_TypeDef led)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  
  /* Enable the GPIO_LED Clock */
  LEDx_GPIO_CLK_ENABLE(led);

  /* Configure the GPIO_LED pin */
  GPIO_InitStruct.Pin = LED_PIN[led];
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  
  HAL_GPIO_Init(LED_PORT[led], &GPIO_InitStruct);
}

/**
  * @brief  Turns selected LED On.
  * @param  Led: Specifies the Led to be set on. 
  *   This parameter can be one of following parameters:
  *     @arg LED2
  * @retval None
  */
void BSP_LED_On(LED_TypeDef led)
{
  HAL_GPIO_WritePin(LED_PORT[led], LED_PIN[led], GPIO_PIN_SET); 
}

/**
  * @brief  Turns selected LED Off.
  * @param  Led: Specifies the Led to be set off. 
  *   This parameter can be one of following parameters:
  *     @arg LED2
  * @retval None
  */
void BSP_LED_Off(LED_TypeDef led)
{
  HAL_GPIO_WritePin(LED_PORT[led], LED_PIN[led], GPIO_PIN_RESET); 
}

/**
  * @brief  Toggles the selected LED.
  * @param  Led: Specifies the Led to be toggled. 
  *   This parameter can be one of following parameters:
  *     @arg LED2
  * @retval None
  */
void BSP_LED_Toggle(LED_TypeDef led)
{
  HAL_GPIO_TogglePin(LED_PORT[led], LED_PIN[led]);
}
