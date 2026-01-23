#include "RCC.h"
#include <stdint.h>

void RCC_Enable(
		RCC_PERIPHERAL_t peripheral
		){
	switch(peripheral){
	//RCC_APB2ENR
	case RCC_UART1: RCC_APB2ENR |= (1 << 14); break;
	case RCC_SPI1:	RCC_APB2ENR |= (1 << 12); break;
	case RCC_ADC2:  RCC_APB2ENR |= (1 << 10); break;
	case RCC_ADC1:  RCC_APB2ENR |= (1 << 9); break;
	case RCC_PORTC: RCC_APB2ENR |= (1 << 4); break;
	case RCC_PORTB: RCC_APB2ENR |= (1 << 3); break;
	case RCC_PORTA: RCC_APB2ENR |= (1 << 2); break;
	case RCC_AFIO:  RCC_APB2ENR |= (1 << 0); break;
	//RCC_APB1ENR
	case RCC_I2C2:	RCC_APB1ENR |= (1 << 22); break;
	case RCC_I2C1:	RCC_APB1ENR |= (1 << 21); break;
	case RCC_UART2:	RCC_APB1ENR |= (1 << 17); break;
	case RCC_SPI2:	RCC_APB1ENR |= (1 << 14); break;
	case RCC_TIM4:  RCC_APB1ENR |= (1 << 2); break;
	case RCC_TIM3:  RCC_APB1ENR |= (1 << 1); break;
	case RCC_TIM2:  RCC_APB1ENR |= (1 << 0); break;
	default: return;
	}
}
