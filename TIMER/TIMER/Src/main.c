#include "RCC.h"
#include "GPIO.h"
#include "TIM.h"

int main(void){
	RCC_Enable(RCC_PORTA);
	RCC_Enable(RCC_TIM2);
	RCC_Enable(RCC_TIM3);

	GPIO_Config(GPIO_PORTA, 0, GPIO_CNF_AF_PP, GPIO_MODE_OUT_10M);
	TIM_PWM(TIM2, TIM_CHANNEL_1);

	while(1){
		for (int i = 0; i <= 100; i = i + 10){
		TIM_PWM_Bright_Percent(TIM2, TIM_CHANNEL_1, i);
		TIM_Delay_ms(TIM3, 100);
		}
	}
}
