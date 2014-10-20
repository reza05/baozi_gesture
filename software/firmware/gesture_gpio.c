#include "gesture_gpio.h"
#include "gesture.h"


void gesture_init(void)
{
  GPIO_InitTypeDef   GPIO_InitStructure;
  
  __GPIOA_CLK_ENABLE();
  
  /* Configure LEFT_GPIO pin as input floating */
  GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  GPIO_InitStructure.Pin = LEFT_GPIO_PIN;
  HAL_GPIO_Init(LEFT_GPIO_PORT, &GPIO_InitStructure);

  /* Configure RIGHT_GPIO pin as input floating */
  GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  GPIO_InitStructure.Pin = RIGHT_GPIO_PIN;
  HAL_GPIO_Init(RIGHT_GPIO_PORT, &GPIO_InitStructure);
  
  /* Configure UP_GPIO pin as input floating */
  GPIO_InitStructure.Mode = GPIO_MODE_IT_RISING_FALLING;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  GPIO_InitStructure.Pin = UP_GPIO_PIN;
  HAL_GPIO_Init(UP_GPIO_PORT, &GPIO_InitStructure);
  
  /* Enable and set EXTI line Interrupt to the lowest priority */
  HAL_NVIC_SetPriority(EXTI4_15_IRQn, 2, 0);
  HAL_NVIC_SetPriority(EXTI2_3_IRQn, 2, 0);
  HAL_NVIC_EnableIRQ(EXTI2_3_IRQn);
  HAL_NVIC_EnableIRQ(EXTI4_15_IRQn);

  return;
}

/**
  * @brief  EXTI line detection callbacks.
  * @param  GPIO_Pin: Specifies the port pin connected to corresponding EXTI line.
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  gesture_tuple tuple;

#if 0
  if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(LEFT_GPIO_PORT, LEFT_GPIO_PIN)) {
    tuple.state |= 1<<2;
  }
  if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(RIGHT_GPIO_PORT, RIGHT_GPIO_PIN)) {
    tuple.state |= 1;
  }
  if (GPIO_PIN_RESET == HAL_GPIO_ReadPin(UP_GPIO_PORT, UP_GPIO_PIN)) {
    tuple.state |= 1<<1;
  }
#else 
  uint32_t state = GPIOA->IDR;
  tuple.state = 0;
  if ((state&(0x1<<2)) == 0) {
    tuple.state |= 1<<2;
  }
  if ((state&(0x1<<4)) == 0) {
    tuple.state |= 1<<1;
  }
  if ((state&(0x1<<3)) == 0) {
    tuple.state |= 1;
  }
#endif
  tuple.time = HAL_GetTick();
  write_tuple(&tuple);
  gesture_uart_sendbyte(0xF0);
  //gesture_uart_sendbyte(state);
  gesture_uart_sendbyte(tuple.state);
  //gesture_uart_senddata(4,(uint8_t*)&tuple.time);
  gesture_uart_sendbyte(0xF1);
  
  if (tuple.state == 0) {
    trigger();
  }
}
