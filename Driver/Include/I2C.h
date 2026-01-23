#ifndef __I2C_H
#define __I2C_H
#include <stdint.h>
#include "GPIO.h"

#define I2C1_ADD_BASE    0x40005400UL
#define I2C2_ADD_BASE    0x40005800UL

#define I2C_ADD_CR1      0x00
#define I2C_ADD_CR2      0x04
#define I2C_ADD_OAR1     0x08
#define I2C_ADD_OAR2     0x0C
#define I2C_ADD_DR       0x10
#define I2C_ADD_SR1      0x14
#define I2C_ADD_SR2      0x18
#define I2C_ADD_CCR      0x1C
#define I2C_ADD_TRISE    0x20

#define I2C1_CR1         (*(volatile uint32_t*)( I2C1_ADD_BASE + I2C_ADD_CR1))
#define I2C1_CR2         (*(volatile uint32_t*)( I2C1_ADD_BASE + I2C_ADD_CR2))
#define I2C1_OAR1        (*(volatile uint32_t*)( I2C1_ADD_BASE + I2C_ADD_OAR1))
#define I2C1_OAR2        (*(volatile uint32_t*)( I2C1_ADD_BASE + I2C_ADD_OAR2))
#define I2C1_DR          (*(volatile uint32_t*)( I2C1_ADD_BASE + I2C_ADD_DR))
#define I2C1_SR1         (*(volatile uint32_t*)( I2C1_ADD_BASE + I2C_ADD_SR1))
#define I2C1_SR2         (*(volatile uint32_t*)( I2C1_ADD_BASE + I2C_ADD_SR2))
#define I2C1_CCR         (*(volatile uint32_t*)( I2C1_ADD_BASE + I2C_ADD_CCR))
#define I2C1_TRISE       (*(volatile uint32_t*)( I2C1_ADD_BASE + I2C_ADD_TRISE))

#define I2C2_CR1         (*(volatile uint32_t*)( I2C2_ADD_BASE + I2C_ADD_CR1))
#define I2C2_CR2         (*(volatile uint32_t*)( I2C2_ADD_BASE + I2C_ADD_CR2))
#define I2C2_OAR1        (*(volatile uint32_t*)( I2C2_ADD_BASE + I2C_ADD_OAR1))
#define I2C2_OAR2        (*(volatile uint32_t*)( I2C2_ADD_BASE + I2C_ADD_OAR2))
#define I2C2_DR          (*(volatile uint32_t*)( I2C2_ADD_BASE + I2C_ADD_DR))
#define I2C2_SR1         (*(volatile uint32_t*)( I2C2_ADD_BASE + I2C_ADD_SR1))
#define I2C2_SR2         (*(volatile uint32_t*)( I2C2_ADD_BASE + I2C_ADD_SR2))
#define I2C2_CCR         (*(volatile uint32_t*)( I2C2_ADD_BASE + I2C_ADD_CCR))
#define I2C2_TRISE       (*(volatile uint32_t*)( I2C2_ADD_BASE + I2C_ADD_TRISE))


//I2C1
#define I2C1_PORT_SCL    GPIO_PORTB
#define I2C1_PORT_SDA    GPIO_PORTB

#define I2C1_PIN_SCL     6
#define I2C1_PIN_SDA     7

//I2C2
#define I2C2_PORT_SCL    GPIO_PORTB
#define I2C2_PORT_SDA    GPIO_PORTB

#define I2C2_PIN_SCL     10
#define I2C2_PIN_SDA     11

//I2C_
typedef enum{
	I2C1,
	I2C2
}I2C_t;

//SPEED
typedef enum{
	I2C_SPEED_STANDARD = 100000,
	I2C_SPEED_FAST     = 400000
}I2C_SPEED_t;

//WRITE_READ
typedef enum{
	I2C_LSB_TRANSMIT = 0,
	I2C_LSB_RECEIVE  = 1
}I2C_LSB_t;

//ACK-RECIEVE
typedef enum{
	I2C_ACK_CONTINUE,
	I2C_ACK_STOP
}I2C_ACK_t;

void I2C_Init(
		I2C_t I2C_,
		uint8_t clock_frequency_MHz,
		I2C_SPEED_t speed_kHz
		);

void I2C_Start(
		I2C_t I2C_
		);

void I2C_Stop(
		I2C_t I2C_
		);

void I2C_Transmit_Address(
		I2C_t I2C_,
		uint8_t address,
		I2C_LSB_t write_read
		);

void I2C_Master_Transmit_Data(
		I2C_t I2C_,
		uint8_t data
		);

void I2C_Slave_Transmit_Data(
		I2C_t I2C_,
		uint8_t data
		);

uint8_t I2C_Master_Receive_Continue(
		I2C_t I2C_
		);

uint8_t I2C_Master_Receive_Stop(
		I2C_t I2C_
		);

uint16_t I2C_Master_Receive_Data(
		I2C_t I2C_,
		I2C_ACK_t ack
		);

uint16_t I2C_Slave_Receive_Data(
		I2C_t I2C_,
		I2C_ACK_t ack
		);

void I2C_Slave_Stop_Detection(
		I2C_t I2C_
		);

#endif
