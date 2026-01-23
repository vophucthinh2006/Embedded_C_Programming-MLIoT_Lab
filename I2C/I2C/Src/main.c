#include "RCC.h"
#include "GPIO.h"
#include "UART.h"
#include "I2C.h"
#include "ADXL345.h"

int main (void){
	RCC_Enable(RCC_PORTA);
	RCC_Enable(RCC_PORTB);
	RCC_Enable(UART1);
	RCC_Enable(RCC_I2C1);

	UART_Init(UART1, 9600, UART_WORD_LENGTH_8);
	I2C_Init(I2C1, 8, I2C_SPEED_STANDARD);

	int16_t X, Y, Z;
	char x[20], y[20], z[20];

	while(1){
		ADXL345_I2C_Read(I2C1, &X, &Y, &Z);
		value_to_str(X, x);
		value_to_str(Y, y);
		value_to_str(Z, z);

		UART_Transmit_String(UART1, "X: ");
		UART_Transmit_String(UART1, x);
		UART_Transmit_String(UART1, "\r\n");

		UART_Transmit_String(UART1, "Y: ");
		UART_Transmit_String(UART1, y);
		UART_Transmit_String(UART1, "\r\n");

		UART_Transmit_String(UART1, "Z: ");
		UART_Transmit_String(UART1, z);
		UART_Transmit_String(UART1, "\r\n");

		for (int i = 0; i < 500000; i++);
	}
}
