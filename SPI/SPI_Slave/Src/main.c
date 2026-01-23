#include "RCC.h"
#include "GPIO.h"
#include "SPI.h"


int main (void){
	RCC_Enable(RCC_SPI1);
	RCC_Enable(RCC_PORTA);
	SPI_Init_Slave1(SPI1, SPI_BAUDRATE_FPCLK_2);

	while(1){
		if (SPI_SS1_Receive(SPI1) == 'A'){
			SPI_SS1_Transmit(SPI1, 'B');
		}
	}
}
