#include "I2C.h"

void I2C_Init(
		I2C_t I2C_,
		uint8_t clock_frequency_MHz,
		I2C_SPEED_t speed_kHz
		){

	volatile uint32_t *CR1;
	volatile uint32_t *CR2;
	volatile uint32_t *CCR;
	volatile uint32_t *TRISE;

	switch (I2C_){
	case I2C1:
		GPIO_Config(I2C1_PORT_SCL, I2C1_PIN_SCL, GPIO_CNF_AF_OD, GPIO_MODE_OUT_10M);
		GPIO_Config(I2C1_PORT_SDA, I2C1_PIN_SDA, GPIO_CNF_AF_OD, GPIO_MODE_OUT_10M);

		CR1 = &I2C1_CR1;
		CR2 = &I2C1_CR2;
		CCR = &I2C1_CCR;
		TRISE = &I2C1_TRISE;
		break;
	case I2C2:
		GPIO_Config(I2C2_PORT_SCL, I2C2_PIN_SCL, GPIO_CNF_AF_OD, GPIO_MODE_OUT_10M);
		GPIO_Config(I2C2_PORT_SDA, I2C2_PIN_SDA, GPIO_CNF_AF_OD, GPIO_MODE_OUT_10M);

		CR1 = &I2C2_CR1;
		CR2 = &I2C2_CR2;
		CCR = &I2C2_CCR;
		TRISE = &I2C2_TRISE;
		break;
	default: return;
	}
	*CR1 &= ~(1 << 0);

	*CR2 = (uint8_t)clock_frequency_MHz;

	uint32_t clock_frequency_Hz = (clock_frequency_MHz * 1000000);
	uint32_t speed_Hz = (speed_kHz * 1000);

	uint32_t TPCLK1_ns = (1 * 1000000000 / clock_frequency_Hz);
	uint32_t TSCL_ns = (1 * 1000000000 / speed_Hz);

	uint32_t tHIGH_ns;
	uint32_t tRISE_ns;
	switch(speed_kHz){
	case I2C_SPEED_STANDARD:
		tHIGH_ns = (uint32_t)(TSCL_ns / 2);  // = tLOW_ns
		tRISE_ns = (uint32_t)(1000);
		break;
	case I2C_SPEED_FAST:
		//something
		tRISE_ns = (uint32_t)(300);
		break;
	default: return;
	}
	*CCR = (uint32_t)(tHIGH_ns / TPCLK1_ns);
	*TRISE = ((uint32_t)(tRISE_ns / TPCLK1_ns) + 1);

	*CR1 |= (1 << 10);

	*CR1 |= (1 << 0);
}

void I2C_Start(
		I2C_t I2C_
		){
	volatile uint32_t *SR2;
	volatile uint32_t *CR1;
	volatile uint32_t *SR1;

	switch (I2C_){
	case I2C1:
		SR2 = &I2C1_SR2;
		CR1 = &I2C1_CR1;
		SR1 = &I2C1_SR1;
		break;
	case I2C2:
		SR2 = &I2C2_SR2;
		CR1 = &I2C2_CR1;
		SR1 = &I2C2_SR1;
		break;
	default: return;
	}
	while (*SR2 & (1 << 1));
	*CR1 |= (1 << 8);

	while(!(*SR1 & (1 << 0)));
	//DO SOMETHING
}

void I2C_Stop(
		I2C_t I2C_
		){
	volatile uint32_t *CR1;

	switch (I2C_){
	case I2C1:
		CR1 = &I2C1_CR1;
		break;
	case I2C2:
		CR1 = &I2C2_CR1;
		break;
	default: return;
	}
	*CR1 |= (1 << 9);
}

void I2C_Transmit_Address(
		I2C_t I2C_,
		uint8_t address,
		I2C_LSB_t transmit_receive
		){
	volatile uint32_t *DR;
	volatile uint32_t *SR1;
	volatile uint32_t *SR2;

	switch (I2C_){
	case I2C1:
		DR = &I2C1_DR;
		SR1 = &I2C1_SR1;
		SR2 = &I2C1_SR2;
		break;
	case I2C2:
		DR = &I2C2_DR;
		SR1 = &I2C2_SR1;
		SR2 = &I2C2_SR2;
		break;
	default: return;
	}
	*DR = (uint32_t)((address << 1) | (transmit_receive << 0));
	while(!(*SR1 & (1 << 1)));
	volatile uint8_t dummy = 0x00;
	dummy = *SR2;
}

void I2C_Master_Transmit_Data(
		I2C_t I2C_,
		uint8_t data
		){
	volatile uint32_t *DR;
	volatile uint32_t *SR1;

	switch (I2C_){
	case I2C1:
		DR = &I2C1_DR;
		SR1 = &I2C1_SR1;
		break;
	case I2C2:
		DR = &I2C2_DR;
		SR1 = &I2C2_SR1;
		break;
	default: return;
	}
	while (!(*SR1 & (1 << 7)));
	*DR = data;
	while (!(*SR1 & (1 << 2)));
}

void I2C_Slave_Transmit_Data(
		I2C_t I2C_,
		uint8_t data
		){
	volatile uint32_t *DR;
	volatile uint32_t *SR1;

	switch (I2C_){
	case I2C1:
		DR = &I2C1_DR;
		SR1 = &I2C1_SR1;
		break;
	case I2C2:
		DR = &I2C2_DR;
		SR1 = &I2C2_SR1;
		break;
	default: return;
	}
	while (!(*SR1 & (1 << 7)));

	*DR = data;

	while (!(*SR1 & (1 << 10)) && !(*SR1 & (1 << 7)));
	if (*SR1 & (1 << 10)){
		volatile uint8_t dummy;
		dummy = *SR1;
	}
}

uint8_t I2C_Master_Receive_Continue(
		I2C_t I2C_
		){
    volatile uint32_t *CR1;
    volatile uint32_t *SR1;
    volatile uint32_t *DR;

    switch(I2C_){
    case I2C1:
        CR1 = &I2C1_CR1;
        SR1 = &I2C1_SR1;
        DR  = &I2C1_DR;
        break;
    case I2C2:
        CR1 = &I2C2_CR1;
        SR1 = &I2C2_SR1;
        DR  = &I2C2_DR;
        break;
    default: return 0;
    }

    *CR1 |= (1 << 10);

    while (!(*SR1 & (1 << 6)));

    return (uint8_t)(*DR);
}

uint8_t I2C_Master_Receive_Stop(
		I2C_t I2C_
		){
    volatile uint32_t *CR1;
    volatile uint32_t *SR1;
    volatile uint32_t *SR2;
    volatile uint32_t *DR;

    switch(I2C_){
    case I2C1:
        CR1 = &I2C1_CR1;
        SR1 = &I2C1_SR1;
        SR2 = &I2C1_SR2;
        DR  = &I2C1_DR;
        break;
    case I2C2:
        CR1 = &I2C2_CR1;
        SR1 = &I2C2_SR1;
        SR2 = &I2C2_SR2;
        DR  = &I2C2_DR;
        break;
    default: return 0;
    }

    while (!(*SR1 & (1 << 1)));
    volatile uint32_t dummy;
    dummy = *SR2;

    *CR1 &= ~(1 << 10);

    while (!(*SR1 & (1 << 6)));

    uint8_t data = (uint8_t)(*DR);
    I2C_Stop(I2C_);

    return (uint8_t)data;
}

uint16_t I2C_Master_Receive_Data(
		I2C_t I2C_,
		I2C_ACK_t ack
		){
	if (ack == I2C_ACK_CONTINUE){
		return I2C_Master_Receive_Continue(I2C_);
	}
	else {
		return I2C_Master_Receive_Stop(I2C_);
	}
}

uint16_t I2C_Slave_Receive_Data(
		I2C_t I2C_,
		I2C_ACK_t ack
		){
	volatile uint32_t *SR1;
	volatile uint32_t *DR;

	switch (I2C_){
	case I2C1:
		SR1 = &I2C1_SR1;
		DR = &I2C1_DR;
		break;
	case I2C2:
		SR1 = &I2C2_SR1;
		DR = &I2C2_DR;
		break;
	default: return 0x00;
	}

	while (!(*SR1 & (1 << 6)));
	return (uint16_t)*DR;
}

void I2C_Slave_Stop_Detection(
		I2C_t I2C_
		){
	volatile uint32_t *CR1;
	volatile uint32_t *SR1;

	switch (I2C_){
	case I2C1:
		CR1 = &I2C1_CR1;
		SR1 = &I2C1_SR1;
		break;
	case I2C2:
		CR1 = &I2C2_CR1;
		SR1 = &I2C2_SR1;
		break;
	default: return;
	}
	volatile uint8_t dummy = 0x00;
	dummy = *SR1;
	*CR1 |= (1 << 0);
}
