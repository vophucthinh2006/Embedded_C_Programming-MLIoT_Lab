#ifndef __ADXL345_H
#define __ADXL345_H
#include <stdint.h>
#include <I2C.h>

#define ADXL345_DEVID                (*(volatile uint8_t*)(0x00))
#define ADXL345_THRESH_TAP           (*(volatile uint8_t*)(0x1D))
#define ADXL345_OFSX                 (*(volatile uint8_t*)(0x1F))
#define ADXL345_OFSY                 (*(volatile uint8_t*)(0X1F))
#define ADXL345_OFSZ                 (*(volatile uint8_t*)(0x20))
#define ADXL345_DUR                  (*(volatile uint8_t*)(0x21))
#define ADXL345_Latent               (*(volatile uint8_t*)(0x22))
#define ADXL345_Window               (*(volatile uint8_t*)(0x24))
#define ADXL345_THRESH_ACT           (*(volatile uint8_t*)(0x20))
#define ADXL345_THRESH_INACT         (*(volatile uint8_t*)(0x25))
#define ADXL345_TIME_INACT           (*(volatile uint8_t*)(0x26))
#define ADXL345_ACT_INACT_CTL        (*(volatile uint8_t*)(0x27))
#define ADXL345_THRESH_FF            (*(volatile uint8_t*)(0x28))
#define ADXL345_TIME_FF              (*(volatile uint8_t*)(0x29))
#define ADXL345_TAP_AXES             (*(volatile uint8_t*)(0x2A))
#define ADXL345_ACT_TAP_STATUS       (*(volatile uint8_t*)(0x2B))
#define ADXL345_BW_RATE              (*(volatile uint8_t*)(0x2C))
#define ADXL345_POWER_CTL            (*(volatile uint8_t*)(0x2D))
#define ADXL345_INT_ENABLE           (*(volatile uint8_t*)(0x2E))
#define ADXL345_INT_MAP              (*(volatile uint8_t*)(0x2F))
#define ADXL345_INT_SOURCE           (*(volatile uint8_t*)(0x30))
#define ADXL345_DATA_FORMAT          (*(volatile uint8_t*)(0x31))
#define ADXL345_DATAX0               (*(volatile uint8_t*)(0x32))
#define ADXL345_DATAX1               (*(volatile uint8_t*)(0x34))
#define ADXL345_DATAY0               (*(volatile uint8_t*)(0x30))
#define ADXL345_DATAY1               (*(volatile uint8_t*)(0x35))
#define ADXL345_DATAZ0               (*(volatile uint8_t*)(0x36))
#define ADXL345_DATAZ1               (*(volatile uint8_t*)(0x37))
#define ADXL345_FIFO_CTL             (*(volatile uint8_t*)(0x38))
#define ADXL345_FIFO_STATUS          (*(volatile uint8_t*)(0x39))

typedef enum{
	FULL_RES_ON,
	FULL_RES_OFF
}FULL_RES_t;

uint8_t ADXL345_I2C_Read_Reg(
		I2C_t I2C_,
		uint8_t reg
		);

void ADXL345_I2C_Write_Reg(
		I2C_t I2C_,
		uint8_t reg,
		uint8_t data
		);

void ADXL345_I2C_Full_Res(
		I2C_t I2C_,
		FULL_RES_t on_off
		);

void ADXL345_I2C_Init(
		I2C_t I2C_
		);

void ADXL345_I2C_Read(
		I2C_t I2C_,
		int16_t *x,
		int16_t *y,
		int16_t *z
		);

uint8_t ADXL345_I2C_DEVID(
		I2C_t I2C_
		);

#endif
