#ifndef __EXTI_H
#define __EXTI_H
#include <stdint.h>
#include "AFIO.h"
#include "UART.h"

#define EXTI_ADD_BASE    0x40010400UL
#define NVIC_ADD_BASE    0xE000E100UL

#define EXTI_IMR         (*(volatile uint32_t*)(EXTI_ADD_BASE + 0x00))
#define EXTI_EMR         (*(volatile uint32_t*)(EXTI_ADD_BASE + 0x04))
#define EXTI_RTSR        (*(volatile uint32_t*)(EXTI_ADD_BASE + 0x08))
#define EXTI_FTSR        (*(volatile uint32_t*)(EXTI_ADD_BASE + 0x0C))
#define EXTI_SWIER       (*(volatile uint32_t*)(EXTI_ADD_BASE + 0x10))
#define EXTI_PR          (*(volatile uint32_t*)(EXTI_ADD_BASE + 0x14))

#define NVIC_ISER0       (*(volatile uint32_t*)(NVIC_ADD_BASE + 0x00))
#define NVIC_ISER1       (*(volatile uint32_t*)(NVIC_ADD_BASE + 0X04))

//PORT
typedef enum{
	EXTI_PORTA = 0b0000,
	EXTI_PORTB = 0b0001,
	EXTI_PORTC = 0b0010
}EXTI_PORT_t;

typedef enum{
	EXTI_MODE_RISING,
	EXTI_MODE_FALLING,
	EXTI_MODE_BOTH
}EXTI_MODE_t;

//UART
typedef enum{
	EXTI_UART1,
	EXTI_UART2,
	EXTI_UART3
}EXTI_UART_t;

void EXTI_Init(
		EXTI_PORT_t port,
		uint8_t pin,
		EXTI_MODE_t mode
		);
void EXTI_IRQHandler(
		uint8_t pin
		);

void NVIC_UART_Enable(
		EXTI_UART_t UART_
		);

#endif
