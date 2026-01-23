#include "RCC.h"
#include "GPIO.h"
#include "ADC.h"
#include "UART.h"

int main(void){
	RCC_Enable(RCC_PORTA);
	RCC_Enable(RCC_ADC1);
	RCC_Enable(RCC_UART1);
	GPIO_Config(GPIO_PORTA, 0, GPIO_CNF_IN_ANA, GPIO_MODE_IN);
	GPIO_Config(GPIO_PORTA, 1, GPIO_CNF_IN_ANA, GPIO_MODE_IN);

	ADC_Number_Conversation(ADC1, 2);
	ADC_Init(ADC1, 0, ADC_SAMPLE_TIME_239_5, 1, ADC_MODE_CONTINUOUS);
	ADC_Init(ADC1, 1, ADC_SAMPLE_TIME_239_5, 2, ADC_MODE_CONTINUOUS);

	UART_Init(UART1, 9600, UART_WORD_LENGTH_8);
	char adc1_str[20];

	while(1){
	uint16_t adc1_value = ADC_Read_Pin(ADC1);
	value_to_str((uint32_t)(adc1_value * 3300 / 4095), adc1_str);

	for (int i = 0; i < 500000; i++);

	UART_Transmit_String(UART1, adc1_str);
	UART_Transmit_String(UART1, "\r\n");
	}
}
