#ifndef _GESTURE_UART_H
#define _GESTURE_UART_H

#include "stm32f0xx_hal.h"
#include "gesture.h"

#define USARTx                           USART1
#define USARTx_CLK_ENABLE()              __USART1_CLK_ENABLE()
#define USARTx_RX_GPIO_CLK_ENABLE()      __GPIOA_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()      __GPIOA_CLK_ENABLE()

#define USARTx_FORCE_RESET()             __USART1_FORCE_RESET()
#define USARTx_RELEASE_RESET()           __USART1_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USARTx_TX_PIN                    GPIO_PIN_9
#define USARTx_TX_GPIO_PORT              GPIOA
#define USARTx_TX_AF                     GPIO_AF1_USART1
#define USARTx_RX_PIN                    GPIO_PIN_10
#define USARTx_RX_GPIO_PORT              GPIOA
#define USARTx_RX_AF                     GPIO_AF1_USART1

/* Definition for USARTx's NVIC */
#define USARTx_IRQn                      USART1_IRQn
#define USARTx_IRQHandler                USART1_IRQHandler
/* Size of Trasmission buffer */
#define TXBUFFERSIZE                      (4)
/* Size of Reception buffer */
#define RXBUFFERSIZE                      TXBUFFERSIZE


void gesture_uart_init(void);
void gesture_uart_deinit(void);
int  gesture_uart_sendbyte(uint8_t data);
void  gesture_uart_senddata(uint32_t len, uint8_t *data);
void  gesture_uart_sendstr(char *data);

#endif
