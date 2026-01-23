#include "ADXL345.h"

uint8_t ADXL345_I2C_Read_Reg(
		I2C_t I2C_,
		uint8_t reg
		){
	I2C_Start(I2C_);
	I2C_Transmit_Address(I2C_, 0x53, I2C_LSB_TRANSMIT);
	I2C_Master_Transmit_Data(I2C_, reg);

	I2C_Start(I2C_);
	I2C_Transmit_Address(I2C_, 0x53, I2C_LSB_RECEIVE);
	uint8_t data = I2C_Master_Receive_Data(I2C_, I2C_ACK_STOP);

	return data;
}

void ADXL345_I2C_Write_Reg(
		I2C_t I2C_,
		uint8_t reg,
		uint8_t data
		){
	I2C_Start(I2C_);
	I2C_Transmit_Address(I2C_, 0x53, I2C_LSB_TRANSMIT);
	I2C_Master_Transmit_Data(I2C_, reg);
	I2C_Master_Transmit_Data(I2C_, data);
	I2C_Stop(I2C_);
}

void ADXL345_I2C_Full_Res(
		I2C_t I2C_,
		FULL_RES_t on_off
		){

	uint8_t data_format = ADXL345_I2C_Read_Reg(I2C_, ADXL345_DATA_FORMAT);

	if (on_off == FULL_RES_ON){
		data_format |= (1 << 3);
	}
	else{
		data_format &= ~(1 << 3);
	}
	ADXL345_I2C_Write_Reg(I2C_, ADXL345_DATA_FORMAT, data_format);
}

void ADXL345_I2C_Init(
		I2C_t I2C_
		){
	uint8_t power = ADXL345_I2C_Read_Reg(I2C_, ADXL345_POWER_CTL);

	power |= (1 << 3);

	ADXL345_I2C_Write_Reg(I2C_, ADXL345_POWER_CTL, power);
}

void ADXL345_I2C_Read(
		I2C_t I2C_,
		int16_t *x,
		int16_t *y,
		int16_t *z
		){
	uint8_t raw[6];

	I2C_Start(I2C_);
	I2C_Transmit_Address(I2C_, 0x53, I2C_LSB_TRANSMIT);
	I2C_Master_Transmit_Data(I2C_, ADXL345_DATAX0 | 0b10000000);

	I2C_Start(I2C_);
	I2C_Transmit_Address(I2C_, 0x53, I2C_LSB_RECEIVE);

	raw[0] = I2C_Master_Receive_Data(I2C_, I2C_ACK_CONTINUE);
	raw[1] = I2C_Master_Receive_Data(I2C_, I2C_ACK_CONTINUE);
	raw[2] = I2C_Master_Receive_Data(I2C_, I2C_ACK_CONTINUE);
	raw[3] = I2C_Master_Receive_Data(I2C_, I2C_ACK_CONTINUE);
	raw[4] = I2C_Master_Receive_Data(I2C_, I2C_ACK_CONTINUE);
	raw[5] = I2C_Master_Receive_Data(I2C_, I2C_ACK_STOP);

	I2C_Stop(I2C_);

	*x = (int16_t)((raw[1] << 8) | raw[0]);
	*y = (int16_t)((raw[3] << 8) | raw[2]);
	*z = (int16_t)((raw[5] << 8) | raw[4]);
}

uint8_t ADXL345_I2C_DEVID(
		I2C_t I2C_
		){
	uint8_t DEVID = ADXL345_I2C_Read_Reg(I2C_, ADXL345_DEVID);

	if (DEVID == 0xE5){
		return 1;
	}
	else {
		return 0;
	}
}




