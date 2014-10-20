#ifndef _GESTURE_GPIO_H
#define _GESTURE_GPIO_H

#include "stm32f0xx_hal.h"
#include "gesture.h"

#define LEFT_GPIO_PIN    GPIO_PIN_2
#define LEFT_GPIO_PORT   GPIOA
#define RIGHT_GPIO_PIN   GPIO_PIN_3
#define RIGHT_GPIO_PORT  GPIOA
#define UP_GPIO_PIN      GPIO_PIN_4
#define UP_GPIO_PORT     GPIOA

void gesture_init(void);


#endif
