#ifndef __GESTURE_LED_H
#define __GESTURE_LED_H

#include "stm32f0xx_hal.h"

#define LED0_PIN           (GPIO_PIN_0)
#define LED0_PORT          (GPIOA)
#define LED0_CLK_ENABLE()  __GPIOA_CLK_ENABLE()
#define LED0_CLK_DISABLE() __GPIOA_CLK_DISABLE()

typedef enum {
  LED0 = 0,
	LEDn,
} LED_TypeDef;

void BSP_LED_Init(LED_TypeDef led);
void BSP_LED_On(LED_TypeDef led);
void BSP_LED_Off(LED_TypeDef led);
void BSP_LED_Toggle(LED_TypeDef led);

#endif
