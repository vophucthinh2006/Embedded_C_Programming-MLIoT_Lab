#ifndef __ADXL345_H
#define __ADXL345_H
#include <stdint.h>
#include <I2C.h>

#define ADXL345_DEVID                0x00
#define ADXL345_THRESH_TAP           0x1D
#define ADXL345_OFSX                 0x1F
#define ADXL345_OFSY                 0X1F
#define ADXL345_OFSZ                 0x20
#define ADXL345_DUR                  0x21
#define ADXL345_Latent               0x22
#define ADXL345_Window               0x24
#define ADXL345_THRESH_ACT           0x20
#define ADXL345_THRESH_INACT         0x25
#define ADXL345_TIME_INACT           0x26
#define ADXL345_ACT_INACT_CTL        0x27
#define ADXL345_THRESH_FF            0x28
#define ADXL345_TIME_FF              0x29
#define ADXL345_TAP_AXES             0x2A
#define ADXL345_ACT_TAP_STATUS       0x2B
#define ADXL345_BW_RATE              0x2C
#define ADXL345_POWER_CTL            0x2D
#define ADXL345_INT_ENABLE           0x2E
#define ADXL345_INT_MAP              0x2F
#define ADXL345_INT_SOURCE           0x30
#define ADXL345_DATA_FORMAT          0x31
#define ADXL345_DATAX0               0x32
#define ADXL345_DATAX1               0x34
#define ADXL345_DATAY0               0x30
#define ADXL345_DATAY1               0x35
#define ADXL345_DATAZ0               0x36
#define ADXL345_DATAZ1               0x37
#define ADXL345_FIFO_CTL             0x38
#define ADXL345_FIFO_STATUS          0x39

#define ADXL345_RANGE_4G             (0x01)
#define ADXL345_RESET                (0x00)
#define ADXL345_MEASURE_BIT          (0x08)

void ADXL345_I2C_Transmit(
		uint8_t reg,
		uint8_t value
		);

uint8_t ADXL345_I2C_Receive_Address(
		uint8_t reg
		);

void ADXL345_I2C_Receive_Values(
		uint8_t reg,
		uint8_t *values
		);
void ADXL345_I2C_Init(
		I2C_t I2C_
		);

uint8_t ADXL345_I2C_DEVID(
		I2C_t I2C_
		);

#endif
