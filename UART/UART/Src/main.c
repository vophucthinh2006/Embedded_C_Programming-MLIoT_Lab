#include "RCC.h"
#include "UART.h"

int main(void){
	RCC_Enable(RCC_PORTA);
	RCC_Enable(RCC_UART1);

	UART_Init(UART1,  9600,  UART_WORD_LENGTH_8);
	while(1){
		uint8_t c = UART_Recieve(UART1);
		if (c == 'A'){
			UART_Transmit_String(UART1, "RECIEVED_A\r\n");
		}
	}
}
