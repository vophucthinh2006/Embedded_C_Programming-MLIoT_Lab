#ifndef __UART_H
#define __UART_H
#include <stdint.h>
#include "GPIO.h"

#define UART1_ADD_BASE    0x40013800UL
#define UART2_ADD_BASE    0x40004400UL
#define UART3_ADD_BASE    0x40004800UL

#define UART_ADD_SR       0x00
#define UART_ADD_DR       0x04
#define UART_ADD_BRR      0x08
#define UART_ADD_CR1      0x0C
#define UART_ADD_CR2      0x10
#define UART_ADD_CR3      0x14
#define UART_ADD_GTPR     0x18

#define UART1_SR          (*(volatile uint32_t*)(UART1_ADD_BASE + UART_ADD_SR))
#define UART1_DR          (*(volatile uint32_t*)(UART1_ADD_BASE + UART_ADD_DR))
#define UART1_BRR         (*(volatile uint32_t*)(UART1_ADD_BASE + UART_ADD_BRR))
#define UART1_CR1         (*(volatile uint32_t*)(UART1_ADD_BASE + UART_ADD_CR1))
#define UART1_CR2         (*(volatile uint32_t*)(UART1_ADD_BASE + UART_ADD_CR2))
#define UART1_CR3         (*(volatile uint32_t*)(UART1_ADD_BASE + UART_ADD_CR3))
#define UART1_GTPR        (*(volatile uint32_t*)(UART1_ADD_BASE + UART_ADD_GTPR))

#define UART2_SR          (*(volatile uint32_t*)(UART2_ADD_BASE + UART_ADD_SR))
#define UART2_DR          (*(volatile uint32_t*)(UART2_ADD_BASE + UART_ADD_DR))
#define UART2_BRR         (*(volatile uint32_t*)(UART2_ADD_BASE + UART_ADD_BRR))
#define UART2_CR1         (*(volatile uint32_t*)(UART2_ADD_BASE + UART_ADD_CR1))
#define UART2_CR2         (*(volatile uint32_t*)(UART2_ADD_BASE + UART_ADD_CR2))
#define UART2_CR3         (*(volatile uint32_t*)(UART2_ADD_BASE + UART_ADD_CR3))
#define UART2_GTPR        (*(volatile uint32_t*)(UART2_ADD_BASE + UART_ADD_GTPR))

#define UART3_SR          (*(volatile uint32_t*)(UART3_ADD_BASE + UART_ADD_SR))
#define UART3_DR          (*(volatile uint32_t*)(UART3_ADD_BASE + UART_ADD_DR))
#define UART3_BRR         (*(volatile uint32_t*)(UART3_ADD_BASE + UART_ADD_BRR))
#define UART3_CR1         (*(volatile uint32_t*)(UART3_ADD_BASE + UART_ADD_CR1))
#define UART3_CR2         (*(volatile uint32_t*)(UART3_ADD_BASE + UART_ADD_CR2))
#define UART3_CR3         (*(volatile uint32_t*)(UART3_ADD_BASE + UART_ADD_CR3))
#define UART3_GTPR        (*(volatile uint32_t*)(UART3_ADD_BASE + UART_ADD_GTPR))

//UART_
typedef enum{
	UART1,
	UART2,
	UART3
}UART_t;

//WORD_LENGTH
typedef enum{
	UART_WORD_LENGTH_8 = 0,
	UART_WORD_LENGTH_9 = 1
}UART_WORD_LENGTH_t;

void UART_Init(
		UART_t UART_,
		uint32_t baudrate,
		UART_WORD_LENGTH_t length
		);

void UART_Transmit_Char(
		UART_t UART_,
		char c
		);

void UART_Transmit_String(
		UART_t UART_,
		const char *str
		);

uint8_t UART_Recieve(
		UART_t UART_
		);

void UART1_IRQHandler(void);


void value_to_str(
		int32_t value,
		char *str
		);
#endif
