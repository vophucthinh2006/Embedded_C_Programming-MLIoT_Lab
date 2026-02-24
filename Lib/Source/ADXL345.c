#include "ADXL345.h"

void ADXL345_I2C_Transmit(
		uint8_t reg,
		uint8_t value
		){
    I2C_Start(I2C1);

    I2C_Transmit_Address(I2C1, 0x53, reg, I2C_LSB_TRANSMIT);
    I2C_Master_Transmit_Data(I2C1, &value, 1);

    I2C_Stop(I2C1);
}

uint8_t ADXL345_I2C_Receive_Address(
		uint8_t reg
		){
    uint8_t data;
    I2C_Start(I2C1);
    I2C_Transmit_Address(I2C1, 0x53, reg, I2C_LSB_TRANSMIT);

    I2C_Start(I2C1);
    data = I2C_Master_Receive_Stop(I2C1);

    return data;
}

void ADXL345_I2C_Receive_Values(
		uint8_t reg,
		uint8_t *values
		){

    I2C_Start(I2C1);
    I2C_Transmit_Address(I2C1, 0x53, reg, I2C_LSB_TRANSMIT);

    I2C_Start(I2C1);
    I2C_Transmit_Address(I2C1, 0x53, 0, I2C_LSB_RECEIVE);

    for(int i=0;i<6;i++)
    {
        if(i==5)
            values[i] = I2C_Master_Receive_Stop(I2C1);

        else
            values[i] = I2C_Master_Receive_Continue(I2C1);
    }
}
void ADXL345_I2C_Init(
		I2C_t I2C_
		){
    I2C_Init(I2C_, 8, I2C_SPEED_STANDARD);

    ADXL345_I2C_Transmit(ADXL345_DATA_FORMAT, ADXL345_RANGE_4G);
    for (int i = 0; i < 10; i++);
    ADXL345_I2C_Transmit(ADXL345_POWER_CTL, ADXL345_RESET);
    for (int i = 0; i < 10; i++);
    ADXL345_I2C_Transmit(ADXL345_POWER_CTL, ADXL345_MEASURE_BIT);
    for (int i = 0; i < 10; i++);
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
