#include "GPIO.h"
#include <stdint.h>

void GPIO_Config(
		GPIO_PORT_t port,
		uint8_t pin,
		GPIO_CNF_t cnf,
		GPIO_MODE_t mode
		){
	if (pin > 15){
		return;
	}

	volatile uint32_t *CR_;
	volatile uint32_t *ODR;

	if (pin < 8){
		switch(port){
		case 'A': CR_ = &GPIOA_CRL; ODR = &GPIOA_ODR; break;
		case 'B': CR_ = &GPIOB_CRL; ODR = &GPIOB_ODR; break;
		case 'C': CR_ = &GPIOC_CRL; ODR = &GPIOC_ODR; break;
		default: return;
		}
	}

	else{
		pin -=8;
		switch(port){
		case 'A': CR_ = &GPIOA_CRH; ODR = &GPIOA_ODR; break;
		case 'B': CR_ = &GPIOB_CRH; ODR = &GPIOB_ODR; break;
		case 'C': CR_ = &GPIOC_CRH; ODR = &GPIOC_ODR; break;
		default: return;
		}
	}

	*CR_ &= ~(0b1111 << (pin * 4));
	*CR_ |= (((cnf << 2) | mode) << (pin * 4));

	if (cnf == GPIO_CNF_IN_PU){
		*ODR |= (1 << pin);
	}
}

void GPIO_Write_Pin(
		GPIO_PORT_t port,
		uint8_t pin,
		GPIO_PINSTATE_t state
		){

	if (pin > 15){
		return;
	}

	switch(port){
	case 'A':
		if (state == GPIO_PIN_SET){
			GPIOA_BSRR |= (1 << pin);
		}
		else{
			GPIOA_BRR |= (1 << pin);
		}
		break;
	case 'B':
		if (state == GPIO_PIN_SET){
			GPIOB_BSRR |= (1 << pin);
		}
		else{
			GPIOB_BRR |= (1 << pin);
		}
		break;
	case 'C':
		if (state == GPIO_PIN_SET){
			GPIOC_BSRR |= (1 << pin);
		}
		else{
			GPIOC_BRR |= (1 << pin);
		}
		break;
	default: return;
	}
}

uint8_t GPIO_Read_Pin(
		GPIO_PORT_t port,
		uint8_t pin
		){
	if (pin > 15){
		return GPIO_PIN_RESET;
	}
	switch(port){
	case 'A': return ((GPIOA_IDR & (1 << pin)) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	case 'B': return ((GPIOB_IDR & (1 << pin)) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	case 'C': return ((GPIOC_IDR & (1 << pin)) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	default: return GPIO_PIN_RESET;
	}
}


