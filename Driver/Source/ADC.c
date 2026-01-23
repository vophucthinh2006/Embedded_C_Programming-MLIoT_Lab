#include "ADC.h"

void ADC_Number_Conversation(
		ADC_t ADC_,
		uint8_t number
		){

	if (number > 16){
		return;
	}

	volatile uint32_t *ADC_SQR1;
	volatile uint32_t *ADC_CR1;

	switch(ADC_){
	case ADC1: ADC_SQR1 = &ADC1_SQR1; ADC_CR1 = &ADC1_CR1; break;
	case ADC2: ADC_SQR1 = &ADC2_SQR1; ADC_CR1 = &ADC2_CR1; break;
	default: return;
	}

	*ADC_SQR1 &= ~(0b1111 << 20);
	*ADC_SQR1 |= ((number - 1) << 20);

	*ADC_CR1 &= ~(1 << 8);
	if (number > 0){
		*ADC_CR1 |= (1 << 8);
	}
}

void ADC_Init(
		ADC_t ADC_,
		uint8_t channel,
		ADC_SAMPLE_TIME_t sample,
		uint8_t sequence,
		ADC_MODE_t mode
		){
	if (channel > 17){
		return;
	}

	volatile uint32_t *ADC_SMPR;
	volatile uint32_t *ADC_SQR;
	volatile uint32_t *ADC_CR2;

	switch(ADC_){
	case ADC1:
		if (channel <= 9) ADC_SMPR = &ADC1_SMPR2;
		else              ADC_SMPR = &ADC1_SMPR1;

		if (sequence <= 6)       ADC_SQR = &ADC1_SQR3;
		else if (sequence <= 12) ADC_SQR = &ADC1_SQR2;
		else                     ADC_SQR = &ADC1_SQR1;

		ADC_CR2 = &ADC1_CR2;
		break;

	case ADC2:
		if (channel <= 9) ADC_SMPR = &ADC2_SMPR2;
		else              ADC_SMPR = &ADC2_SMPR1;

		if (sequence <= 6)       ADC_SQR = &ADC2_SQR3;
		else if (sequence <= 12) ADC_SQR = &ADC2_SQR2;
		else                     ADC_SQR = &ADC2_SQR1;

		ADC_CR2 = &ADC2_CR2;
		if (mode == ADC_MODE_CONTINUOUS){
			*ADC_CR2 |= (1 << 22);
		}
		break;

	default: return;
	}

	if (channel <= 9){
		*ADC_SMPR &= ~(0x111 << (channel * 3));
		*ADC_SMPR |= (sample << (channel * 3));
	}
	else{
		*ADC_SMPR &= ~(0x111 << ((channel - 10) * 3));
		*ADC_SMPR |= (sample << ((channel - 10) * 3));
	}

	if (sequence <= 6){
		*ADC_SQR &= ~(0x11111 << ((sequence - 1) * 5));
		*ADC_SQR |= (channel << ((sequence - 1) * 5));
	}
	else if (sequence <= 12){
		*ADC_SQR &= ~(0x11111 << ((sequence - 7) * 5));
		*ADC_SQR |= (channel << ((sequence - 7) * 5));
	}
	else {
		*ADC_SQR &= ~(0x11111 << ((sequence - 13) * 5));
		*ADC_SQR |= (channel << ((sequence - 13) * 5));
	}

	*ADC_CR2 &= ~(1 << 1);
	*ADC_CR2 |= (mode << 1);

	*ADC_CR2 |= (1 << 0);

	*ADC_CR2 |= (1 << 3);
	while(*ADC_CR2 & (1 << 3));
	*ADC_CR2 |= (1 << 2);
	while(*ADC_CR2 & (1 << 2));

	*ADC_CR2 |= (1 << 0);
	for (volatile uint8_t i = 0; i < 10; i++);
}

uint16_t ADC_Read_Pin(
		ADC_t ADC_
		){

	volatile uint32_t *ADC_SR;
	volatile uint32_t *ADC_DR;
	volatile uint32_t *ADC_CR2;

	switch(ADC_){
	case ADC1:
		ADC_SR = &ADC1_SR;
		ADC_DR = &ADC1_DR;
		ADC_CR2 = &ADC1_CR2;
		break;
	case ADC2:
		ADC_SR = &ADC2_SR;
		ADC_DR = &ADC2_DR;
		ADC_CR2 = &ADC2_CR2;
		break;
	default: return 0x00;
	}
	if (!(*ADC_CR2 & (1 << 1))){
	*ADC_CR2 |= (1 << 22);
	}
	while (!(*ADC_SR & (1 << 1)));
	return (uint16_t)*ADC_DR;
}

