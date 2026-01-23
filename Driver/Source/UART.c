#include "UART.h"

void UART_Init(
		UART_t UART_,
		uint32_t baudrate,
		UART_WORD_LENGTH_t length
		){

	volatile uint32_t *BRR;
	volatile uint32_t *CR1;

	switch (UART_){
	case UART1:
		GPIO_Config(GPIO_PORTA, 9, GPIO_CNF_AF_PP, GPIO_MODE_OUT_50M);
		GPIO_Config(GPIO_PORTA, 10, GPIO_CNF_IN_FLT, GPIO_MODE_IN);
		BRR = &UART1_BRR;
		CR1 = &UART1_CR1;
		break;
	case UART2:
		GPIO_Config(GPIO_PORTA, 12, GPIO_CNF_AF_PP, GPIO_MODE_OUT_50M);
		GPIO_Config(GPIO_PORTA, 13, GPIO_CNF_IN_FLT, GPIO_MODE_IN);
		BRR = &UART2_BRR;
		CR1 = &UART2_CR1;
		break;
	case UART3:
		GPIO_Config(GPIO_PORTB, 10, GPIO_CNF_AF_PP, GPIO_MODE_OUT_50M);
		GPIO_Config(GPIO_PORTB, 11, GPIO_CNF_IN_FLT, GPIO_MODE_IN);
		BRR = &UART3_BRR;
		CR1 = &UART3_CR1;
		break;
	default: return;
	}
	//FCK = 8 000 000 Hz
	uint32_t FCK = 8000000;
	//USARTDIV = FCK / (BAUDRATE * 16)
	float USARTDIV = (float)(FCK / (baudrate * 16));
	uint32_t mantissa = (uint32_t)USARTDIV;
	uint32_t fraction = (uint32_t)((USARTDIV - mantissa) * 16 + 0.5f);

	*BRR = (mantissa << 4 | fraction << 0);

	*CR1 &= ~(1 << 12);
	*CR1 |= (length << 12);

	*CR1 |= (1 << 13);
	*CR1 |= (1 << 3);
	*CR1 |= (1 << 2);
}

void UART_Transmit_Char(
		UART_t UART_,
		char c
		){

	volatile uint32_t *SR;
	volatile uint32_t *DR;

	switch (UART_){
	case UART1:
		SR = &UART1_SR;
		DR = &UART1_DR;
		break;
	case UART2:
		SR = &UART2_SR;
		DR = &UART2_DR;
		break;
	case UART3:
		SR = &UART3_SR;
		DR = &UART3_DR;
		break;
	default: return;
	}

	while (!(*SR & (1 << 7)));
	*DR = c;
}

void UART_Transmit_String(
		UART_t UART_,
		const char *str
		){
	while (*str){
		UART_Transmit_Char(UART_, *str);
		str++;
	}
}

uint8_t UART_Recieve(
		UART_t UART_
		){
	volatile uint32_t *SR;
	volatile uint32_t *DR;

	switch (UART_){
	case UART1:
		SR = &UART1_SR;
		DR = &UART1_DR;
		break;
	case UART2:
		SR = &UART2_SR;
		DR = &UART2_DR;
		break;
	case UART3:
		SR = &UART3_SR;
		DR = &UART3_DR;
		break;
	default: return 0x00;
	}
	while (!(*SR & (1 << 5)));
	return (uint8_t)*DR;
}

void UART1_IRQHandler(void){

}

void value_to_str(
		int32_t value,
		char *str
		){
	int i = 0;
	int start = 0;

	if (value < 0){
		str[i++] = '-';
		value = -value;
		start = 1;
	}

	if (value == 0){
		str[i++] = '0';
		str[i] = '\0';
	return;
	}
	while (value > 0){
		str[i++] = (value % 10) + '0';
		value = ((value - (value % 10)) / 10);
	}
	str[i] = '\0';

	for (int j = start, k = i - 1; j < k; j++, k --){
		char swap = str[j];
		str[j] = str[k];
		str[k] = swap;
	}
}


