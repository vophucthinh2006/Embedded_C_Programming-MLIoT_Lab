#include "RCC.h"
#include "I2C.h"
#include "ADXL345.h"
#include "UART.h"

int16_t accel_x, accel_y, accel_z;
char accel_str[20];

uint8_t data_buffer[6];

int main(void){
	RCC_Enable(RCC_UART1);
	RCC_Enable(RCC_I2C1);
	RCC_Enable(RCC_PORTA);
	RCC_Enable(RCC_PORTB);

    UART_Init(UART1, 9600, UART_WORD_LENGTH_8);

    ADXL345_I2C_Init(I2C1);
    while (1)
    {
        ADXL345_I2C_Receive_Values(ADXL345_DATAX0, data_buffer);

        accel_x = (int16_t)((data_buffer[1] << 8) | data_buffer[0]);

        accel_y = (int16_t)((data_buffer[3] << 8) | data_buffer[2]);

        accel_z = (int16_t)((data_buffer[5] << 8) | data_buffer[4]);

        UART_Transmit_String(UART1, "Ox: ");
        value_to_str(accel_x, accel_str);
        UART_Transmit_String(UART1, accel_str);
        UART_Transmit_String(UART1, "\r\n");

        UART_Transmit_String(UART1, "Oy: ");
        value_to_str(accel_y, accel_str);
		UART_Transmit_String(UART1, accel_str);
		UART_Transmit_String(UART1, "\r\n");

		UART_Transmit_String(UART1, "Oz: ");
		value_to_str(accel_z, accel_str);
		UART_Transmit_String(UART1, accel_str);
		UART_Transmit_String(UART1, "\r\n");

        for (int i = 0; i < 1000000; i++);
    }
}
