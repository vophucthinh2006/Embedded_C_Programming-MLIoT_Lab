#include "SPI.h"

void SPI_Init_Master(
		SPI_t SPI_,
		SPI_BAUDRATE_t baudrate
		){

	volatile uint32_t *CR1;

	switch (SPI_){
	case SPI1:
		GPIO_Config(SPI1_PORT_SCK, SPI1_PIN_SCK, GPIO_CNF_AF_PP, GPIO_MODE_OUT_50M);   //SCK
		GPIO_Config(SPI1_PORT_MISO, SPI1_PIN_MISO, GPIO_CNF_IN_FLT, GPIO_MODE_IN);       //MISO
		GPIO_Config(SPI1_PORT_MOSI, SPI1_PIN_MOSI, GPIO_CNF_AF_PP, GPIO_MODE_OUT_50M);   //MOSI
		GPIO_Config(SPI1_PORT_SS1, SPI1_PIN_SS1, GPIO_CNF_OUT_PP, GPIO_MODE_OUT_50M);  //SS: changeable

		CR1 = &SPI1_CR1;
		break;
	case SPI2:
		GPIO_Config(SPI2_PORT_SCK, SPI2_PIN_SCK, GPIO_CNF_AF_PP, GPIO_MODE_OUT_50M);
		GPIO_Config(SPI2_PORT_MISO, SPI2_PIN_MISO, GPIO_CNF_IN_FLT, GPIO_MODE_IN);
		GPIO_Config(SPI2_PORT_MOSI, SPI2_PIN_MOSI, GPIO_CNF_AF_PP, GPIO_MODE_OUT_50M);
		GPIO_Config(SPI2_PORT_SS1, SPI2_PIN_SS1, GPIO_CNF_OUT_PP, GPIO_MODE_OUT_50M);

		CR1 = &SPI1_CR1;
		break;
	default: return;
	}
	*CR1 |= (1 << 2);

	*CR1 &= ~(0b111 << 3);
	*CR1 |=(baudrate << 3);

	*CR1 |= (1 << 9);
	*CR1 |= (1 << 8);

	*CR1 |= (1 << 6);

	GPIO_Write_Pin(SPI1_PORT_SS1, SPI1_PIN_SS1, GPIO_PIN_SET);
}

void SPI_Init_Slave1(
		SPI_t SPI_,
		SPI_BAUDRATE_t baudrate
		){
	volatile uint32_t *CR1;

	switch (SPI_){
	case SPI1:
		GPIO_Config(SPI1_PORT_SCK, SPI1_PIN_SCK, GPIO_CNF_IN_FLT, GPIO_MODE_IN);   //SCK
		GPIO_Config(SPI1_PORT_MISO, SPI1_PIN_MISO, GPIO_CNF_AF_PP, GPIO_MODE_OUT_50M);       //MISO
		GPIO_Config(SPI1_PORT_MOSI, SPI1_PIN_MOSI, GPIO_CNF_IN_FLT, GPIO_MODE_IN);   //MOSI
		GPIO_Config(SPI1_PORT_SS1, SPI1_PIN_SS1, GPIO_CNF_IN_PU, GPIO_MODE_IN);  //SS: changeable

		CR1 = &SPI1_CR1;
		break;
	case SPI2:
		GPIO_Config(SPI2_PORT_SCK, SPI2_PIN_SCK, GPIO_CNF_IN_FLT, GPIO_MODE_IN);
		GPIO_Config(SPI2_PORT_MISO, SPI2_PIN_MISO, GPIO_CNF_AF_PP, GPIO_MODE_OUT_50M);
		GPIO_Config(SPI2_PORT_MOSI, SPI2_PIN_MOSI, GPIO_CNF_IN_FLT, GPIO_MODE_IN);
		GPIO_Config(SPI2_PORT_SS1, SPI2_PIN_SS1, GPIO_CNF_IN_PU, GPIO_MODE_IN);

		CR1 = &SPI1_CR1;
		break;
	default: return;
	}
	*CR1 &= ~(1 << 2);

	*CR1 &= ~(0b111 << 3);
	*CR1 |=(baudrate << 3);

	*CR1 |= (1 << 9);
	*CR1 &= ~(1 << 8);

	*CR1 |= (1 << 6);
}

void SPI_Transmit_SS1(
		SPI_t SPI_,
		uint8_t data
		){
	volatile uint32_t SPI_PORT_SS1;
	volatile uint8_t SPI_PIN_SS1;
	volatile uint32_t *SR;
	volatile uint32_t *DR;

	switch(SPI_){
	case SPI1:
		SPI_PORT_SS1 = SPI1_PORT_SS1;
		SPI_PIN_SS1 = SPI1_PIN_SS1;

		SR = &SPI1_SR;
		DR = &SPI1_DR;
		break;
	case SPI2:
		SPI_PORT_SS1 = SPI2_PORT_SS1;
		SPI_PIN_SS1 = SPI2_PIN_SS1;

		SR = &SPI2_SR;
		DR = &SPI1_DR;
		break;
	default: return;
	}
	GPIO_Write_Pin(SPI_PORT_SS1, SPI_PIN_SS1, GPIO_PIN_RESET);

	while(!(*SR & (1 << 1)));
	*DR = data;

	while(*SR & (1 << 7));
	volatile uint8_t dummy = 0x00;
	dummy = *DR;

	while(*SR & (1 << 7));

	GPIO_Write_Pin(SPI_PORT_SS1, SPI_PIN_SS1, GPIO_PIN_SET);
}

void SPI_SS1_Transmit(
		SPI_t SPI_,
		uint16_t data
		){
	volatile uint32_t SPI_PORT_SS1;
	volatile uint8_t SPI_PIN_SS1;
	volatile uint32_t *SR;
	volatile uint32_t *DR;

	switch(SPI_){
	case SPI1:
		SPI_PORT_SS1 = SPI1_PORT_SS1;
		SPI_PIN_SS1 = SPI1_PIN_SS1;

		SR = &SPI1_SR;
		DR = &SPI1_DR;
		break;
	case SPI2:
		SPI_PORT_SS1 = SPI2_PORT_SS1;
		SPI_PIN_SS1 = SPI2_PIN_SS1;

		SR = &SPI2_SR;
		DR = &SPI1_DR;
		break;
	default: return;
	}
	while (GPIO_Read_Pin(SPI_PORT_SS1, SPI_PIN_SS1	) == 1);

	while (!(*SR & (1 << 1)));
	*DR = data;

	while (!(*SR & (1 << 0)));
	volatile uint8_t dummy;
	dummy = *DR;
}

uint32_t SPI_Receive_SS1(
		SPI_t SPI_
		){
	volatile uint32_t SPI_PORT_SS1;
	volatile uint8_t SPI_PIN_SS1;
	volatile uint32_t *SR;
	volatile uint32_t *DR;

	switch(SPI_){
	case SPI1:
		SPI_PORT_SS1 = SPI1_PORT_SS1;
		SPI_PIN_SS1 = SPI1_PIN_SS1;

		SR = &SPI1_SR;
		DR = &SPI1_DR;
		break;
	case SPI2:
		SPI_PORT_SS1 = SPI2_PORT_SS1;
		SPI_PIN_SS1 = SPI2_PIN_SS1;

		SR = &SPI2_SR;
		DR = &SPI1_DR;
		break;
	default: return (uint32_t)0x00;
	}
	GPIO_Write_Pin(SPI_PORT_SS1, SPI_PIN_SS1, GPIO_PIN_RESET);

	while(!(*SR & (1 << 1)));
	volatile uint8_t dummy = 0x00;
	*DR = dummy;
	while(!(*SR & (1 << 0)));

	uint32_t data = *DR;

	while(*SR & (1 << 7));

	GPIO_Write_Pin(SPI_PORT_SS1, SPI_PIN_SS1, GPIO_PIN_SET);
	return (uint32_t)data;
}

uint32_t SPI_SS1_Receive(
		SPI_t SPI_
		){
	volatile uint32_t SPI_PORT_SS1;
	volatile uint8_t SPI_PIN_SS1;
	volatile uint32_t *SR;
	volatile uint32_t *DR;

	switch(SPI_){
	case SPI1:
		SPI_PORT_SS1 = SPI1_PORT_SS1;
		SPI_PIN_SS1 = SPI1_PIN_SS1;

		SR = &SPI1_SR;
		DR = &SPI1_DR;
		break;
	case SPI2:
		SPI_PORT_SS1 = SPI2_PORT_SS1;
		SPI_PIN_SS1 = SPI2_PIN_SS1;

		SR = &SPI2_SR;
		DR = &SPI1_DR;
		break;
	default: return (uint32_t)0x00;
	}
	while (GPIO_Read_Pin(SPI_PORT_SS1, SPI_PIN_SS1) == 1);

	while (!(*SR & (1 << 0)));

	return (uint32_t)*DR;
}

