#include "TIM.h"
//F system = 8 000 000 Hz

/*
void TIM_Init_IT_s(
		TIM_t TIM_,
		uint16_t s
		){

	volatile uint32_t *PSC;
	volatile uint32_t *ARR;
	volatile uint32_t *CNT;
	volatile uint32_t *DIER;
	volatile uint32_t *CR1;

	switch(TIM_){
	case TIM2:
		PSC = &TIM2_PSC;
		ARR = &TIM2_ARR;
		CNT = &TIM2_CNT;
		DIER = &TIM2_DIER;
		CR1 = &TIM2_CR1;
		NVIC_ISER0 |= (1 << 28);
		break;
	case TIM3:
		PSC = &TIM3_PSC;
		ARR = &TIM3_ARR;
		CNT = &TIM3_CNT;
		DIER = &TIM3_DIER;
		CR1 = &TIM3_CR1;
		NVIC_ISER0 |= (1 << 29);
		break;
	case TIM4:
		PSC = &TIM4_PSC;
		ARR = &TIM4_ARR;
		CNT = &TIM4_CNT;
		DIER = &TIM4_DIER;
		CR1 = &TIM4_CR1;
		//NVIC_ISER0 |= (1 << 38);
		break;
	default: return;
	}
}
*/

void TIM1_IRQHandler(void){

}

void TIM_Delay_ms(
		TIM_t TIM_,
		uint16_t ms
		){
	volatile uint32_t *SR;
	volatile uint32_t *PSC;
	volatile uint32_t *ARR;
	volatile uint32_t *CNT;
	volatile uint32_t *DIER;
	volatile uint32_t *CR1;

	switch(TIM_){
	case TIM2:
		SR = &TIM2_SR;
		PSC = &TIM2_PSC;
		ARR = &TIM2_ARR;
		CNT = &TIM2_CNT;
		DIER = &TIM2_DIER;
		CR1 = &TIM2_CR1;
		break;
	case TIM3:
		SR = &TIM3_SR;
		PSC = &TIM3_PSC;
		ARR = &TIM3_ARR;
		CNT = &TIM3_CNT;
		DIER = &TIM3_DIER;
		CR1 = &TIM3_CR1;
		break;
	case TIM4:
		SR = &TIM4_SR;
		PSC = &TIM4_PSC;
		ARR = &TIM4_ARR;
		CNT = &TIM4_CNT;
		DIER = &TIM4_DIER;
		CR1 = &TIM4_CR1;
		break;
	default: return;
	}
	*CR1 &= ~(1 << 0);
	*CR1 &= ~(1 << 4);

	*PSC = 7999;
	*ARR = ms - 1;
	*CNT = 0;
	*SR &= ~(1 << 0);

	*DIER |= (1 << 0);
	*CR1 |= (1 << 0);
	while(!(*SR & (1 << 0)));

	*CR1 &= ~(1 << 0);
}

void TIM_PWM(
		TIM_t TIM_,
		TIM_CHANNEL_t channel
		){
	volatile uint32_t *CCMR;
	volatile uint32_t *CCER;
	volatile uint32_t *PSC;
	volatile uint32_t *ARR;
	volatile uint32_t *CNT;
	//volatile uint32_t *DIER;
	volatile uint32_t *CR1;
	volatile uint32_t *EGR;

	switch(TIM_){
	case TIM2:
		if ((channel == TIM_CHANNEL_1) | (channel == TIM_CHANNEL_2)){
			CCMR = &TIM2_CCMR1;
		}
		else {
			CCMR = &TIM2_CCMR2;
		}
		CCER = &TIM2_CCER;
		PSC = &TIM2_PSC;
		ARR = &TIM2_ARR;
		CNT = &TIM2_CNT;
		//DIER = &TIM2_DIER;
		CR1 = &TIM2_CR1;
		EGR = &TIM2_EGR;
		break;
	case TIM3:
		if ((channel == TIM_CHANNEL_1) | (channel == TIM_CHANNEL_2)){
			CCMR = &TIM3_CCMR1;
		}
		else {
			CCMR = &TIM3_CCMR2;
		}
		CCER = &TIM3_CCER;
		PSC = &TIM3_PSC;
		ARR = &TIM3_ARR;
		CNT = &TIM3_CNT;
		//DIER = &TIM3_DIER;
		CR1 = &TIM3_CR1;
		EGR = &TIM3_EGR;
		break;
	case TIM4:
		if ((channel == TIM_CHANNEL_1) | (channel == TIM_CHANNEL_2)){
			CCMR = &TIM4_CCMR1;
		}
		else {
			CCMR = &TIM4_CCMR2;
		}
		CCER = &TIM4_CCER;
		PSC = &TIM4_PSC;
		ARR = &TIM4_ARR;
		CNT = &TIM4_CNT;
		//DIER = &TIM4_DIER;
		CR1 = &TIM4_CR1;
		EGR = &TIM4_EGR;
		break;
	default: return;
	}

	switch(channel){
	case TIM_CHANNEL_1:
		*CCMR |= (0b00 << 0);

		*CCMR &= ~(0b111 << 4);
		*CCMR |= (0b110 << 4);

		*CCMR |= (1 << 3);

		*CCER &= ~(1 << 1);
		*CCER |= (1 << 0);

		//*DIER |= (1 << 9);
		break;
	case TIM_CHANNEL_2:
		*CCMR |= (0b00 << 8);

		*CCMR &= ~(0b111 << 12);
		*CCMR |= (0b110 << 12);

		*CCMR |= (1 << 11);

		*CCER &= ~(1 << 5);
		*CCER |= (1 << 4);

		//*DIER |= (1 << 10);
		break;
	case TIM_CHANNEL_3:
		*CCMR |= (0b00 << 0);

		*CCMR &= ~(0b111 << 4);
		*CCMR |= (0b110 << 4);

		*CCMR |= (1 << 3);

		*CCER &= ~(1 << 9);
		*CCER |= (1 << 8);

		//*DIER |= (1 << 11);
		break;
	case TIM_CHANNEL_4:
		*CCMR |= (0b00 << 9);

		*CCMR &= ~(0b111 << 12);
		*CCMR |= (0b110 << 12);

		*CCMR |= (1 << 11);

		*CCER &= ~(1 << 13);
		*CCER |= (1 << 12);

		//*DIER |= (1 << 12);
		break;
	default: return;
	}
	*CCMR |= (1 << 3);

	*CR1 &= ~(1 << 0);
	*PSC = 7;
	*ARR = 999;
	*CNT = 0;

	*CR1 |= (1 << 7);
	*EGR |= 1;

	*CR1 |= (1 << 0);
}

void TIM_PWM_Bright_Percent(
		TIM_t TIM_,
		TIM_CHANNEL_t channel,
		uint8_t percent
		){
	volatile uint32_t *CCR;
	volatile uint32_t *ARR;
	switch(TIM_){
	case TIM2:
		if (channel == TIM_CHANNEL_1){
			CCR = &TIM2_CCR1;
		}
		else if (channel == TIM_CHANNEL_2){
			CCR = &TIM2_CCR2;
		}
		else if (channel == TIM_CHANNEL_3){
			CCR = &TIM2_CCR3;
		}
		else {
			CCR = &TIM2_CCR4;
		}
		ARR = &TIM2_ARR;
		break;
	case TIM3:
		if (channel == TIM_CHANNEL_1){
			CCR = &TIM3_CCR1;
		}
		else if (channel == TIM_CHANNEL_2){
			CCR = &TIM3_CCR2;
		}
		else if (channel == TIM_CHANNEL_3){
			CCR = &TIM3_CCR3;
		}
		else {
			CCR = &TIM3_CCR4;
		}
		ARR = &TIM3_ARR;
		break;
	case TIM4:
		if (channel == TIM_CHANNEL_1){
			CCR = &TIM4_CCR1;
		}
		else if (channel == TIM_CHANNEL_2){
			CCR = &TIM4_CCR2;
		}
		else if (channel == TIM_CHANNEL_3){
			CCR = &TIM4_CCR3;
		}
		else {
			CCR = &TIM4_CCR4;
		}
		ARR = &TIM4_ARR;
		break;
	default: return;
	}

	*CCR = (percent * (*ARR + 1)) / 100;
}
