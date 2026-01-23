#include "RCC.h"
#include "GPIO.h"
#include "SPI.h"
#include "UART.h"

int main(void){
	RCC_Enable(RCC_SPI1);
	RCC_Enable(RCC_PORTA);
	RCC_Enable(RCC_UART1);
	SPI_Init_Master(SPI1, SPI_BAUDRATE_FPCLK_2);
	UART_Init(UART1, 9600, UART_WORD_LENGTH_8);

	while(1){
		SPI_Transmit_SS1(SPI1, 'A');
		if (SPI_Receive_SS1(SPI1) == 'B'){
			UART_Transmit_String(UART1, "RECEIVED_B\r\n");
		}
		for (int i = 0; i < 500000; i++);
	}
}
