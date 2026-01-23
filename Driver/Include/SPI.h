#ifndef __SPI_H
#define __SPI_H
#include <stdint.h>
#include "GPIO.h"

#define SPI1_ADD_BASE    0x40013000UL
#define SPI2_ADD_BASE    0x40003800UL

#define SPI_ADD_CR1      0x00
#define SPI_ADD_CR2      0x04
#define SPI_ADD_SR       0x08
#define SPI_ADD_DR       0x0C
#define SPI_ADD_CRCPR    0x10
#define SPI_ADD_RXCRCR   0x14
#define SPI_ADD_TXCRCR   0x18
#define SPI_ADD_I2SCFGR  0x1C
#define SPI_ADD_I2SPR    0x20

#define SPI1_CR1         (*(volatile uint32_t*)(SPI1_ADD_BASE + SPI_ADD_CR1))
#define SPI1_CR2         (*(volatile uint32_t*)(SPI1_ADD_BASE + SPI_ADD_CR2))
#define SPI1_SR          (*(volatile uint32_t*)(SPI1_ADD_BASE + SPI_ADD_SR))
#define SPI1_DR          (*(volatile uint32_t*)(SPI1_ADD_BASE + SPI_ADD_DR))
#define SPI1_CRCPR       (*(volatile uint32_t*)(SPI1_ADD_BASE + SPI_ADD_CRCPR))
#define SPI1_RXCRCR      (*(volatile uint32_t*)(SPI1_ADD_BASE + SPI_ADD_RXCRCR))
#define SPI1_TXCRCR      (*(volatile uint32_t*)(SPI1_ADD_BASE + SPI_ADD_TXCRCR))
#define SPI1_I2SCFGR     (*(volatile uint32_t*)(SPI1_ADD_BASE + SPI_ADD_I2SCFGR))
#define SPI1_I2SPR       (*(volatile uint32_t*)(SPI1_ADD_BASE + SPI_ADD_I2SPR))

#define SPI2_CR1         (*(volatile uint32_t*)(SPI2_ADD_BASE + SPI_ADD_CR1))
#define SPI2_CR2         (*(volatile uint32_t*)(SPI2_ADD_BASE + SPI_ADD_CR2))
#define SPI2_SR          (*(volatile uint32_t*)(SPI2_ADD_BASE + SPI_ADD_SR))
#define SPI2_DR          (*(volatile uint32_t*)(SPI2_ADD_BASE + SPI_ADD_DR))
#define SPI2_CRCPR       (*(volatile uint32_t*)(SPI2_ADD_BASE + SPI_ADD_CRCPR))
#define SPI2_RXCRCR      (*(volatile uint32_t*)(SPI2_ADD_BASE + SPI_ADD_RXCRCR))
#define SPI2_TXCRCR      (*(volatile uint32_t*)(SPI2_ADD_BASE + SPI_ADD_TXCRCR))
#define SPI2_I2SCFGR     (*(volatile uint32_t*)(SPI2_ADD_BASE + SPI_ADD_I2SCFGR))
#define SPI2_I2SPR       (*(volatile uint32_t*)(SPI2_ADD_BASE + SPI_ADD_I2SPR))

//SPI1
#define SPI1_PORT_SCK    GPIO_PORTA
#define SPI1_PORT_MISO   GPIO_PORTA
#define SPI1_PORT_MOSI   GPIO_PORTA
#define SPI1_PORT_SS1    GPIO_PORTA //CHANGABLE

#define SPI1_PIN_SCK     5
#define SPI1_PIN_MISO    6
#define SPI1_PIN_MOSI    7
#define SPI1_PIN_SS1     4          //CHANGABLE

//SPI2
#define SPI2_PORT_SCK    GPIO_PORTA
#define SPI2_PORT_MISO   GPIO_PORTA
#define SPI2_PORT_MOSI   GPIO_PORTA
#define SPI2_PORT_SS1    GPIO_PORTA //CHANGABLE

#define SPI2_PIN_SCK     13
#define SPI2_PIN_MISO    14
#define SPI2_PIN_MOSI    15
#define SPI2_PIN_SS1     12         //CHANGABLE

//SPI_
typedef enum{
	SPI1,
	SPI2
}SPI_t;

//BAUDRATE
typedef enum{
	SPI_BAUDRATE_FPCLK_2 = 0b000,
	SPI_BAUDRATE_FPCLK_4 = 0b001,
	SPI_BAUDRATE_FPCLK_8 = 0b010,
	SPI_BAUDRATE_FPCLK_16 = 0b011,
	SPI_BAUDRATE_FPCLK_32 = 0b100,
	SPI_BAUDRATE_FPCLK_64 = 0b101,
	SPI_BAUDRATE_FPCLK_128 = 0b110,
	SPI_BAUDRATE_FPCLK_256 = 0b111,
}SPI_BAUDRATE_t;

void SPI_Init_Master(
		SPI_t SPI_,
		SPI_BAUDRATE_t baudrate
		);

void SPI_Init_Slave1(
		SPI_t SPI_,
		SPI_BAUDRATE_t baudrate
		);

void SPI_Transmit_SS1(
		SPI_t SPI_,
		uint8_t data
		);

void SPI_SS1_Transmit(
		SPI_t SPI_,
		uint16_t data
		);

uint32_t SPI_Receive_SS1(
		SPI_t SPI_
		);

uint32_t SPI_SS1_Receive(
		SPI_t SPI_
		);

#endif
