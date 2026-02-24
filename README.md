# Embedded C Programming - MLIoT Laboratory Course

## 1. Introduction

This repository documents a structured laboratory course focused on bare-metal embedded C programming using the STM32 microcontroller platform. The course emphasizes direct interaction with hardware through register-level programming, without relying on vendor abstraction libraries such as Hardware Abstraction Layer (HAL) or Real-Time Operating Systems (RTOS).

The purpose of this course is to develop a fundamental and rigorous understanding of microcontroller peripherals, hardware architecture, and low-level driver implementation.

All workspaces of the homework folders are uploaded (due to Teaching Assistants' requirement).

## 2. Course Objectives

The primary objectives of this course are:

- To develop embedded software using pure bare-metal techniques.

- To understand the internal architecture and operation of STM32 peripherals.

- To implement peripheral drivers through direct register manipulation.

- To analyze peripheral behavior based on reference manual specifications.

- To design reliable embedded interfaces between the microcontroller and external hardware modules.

The following peripherals are studied and implemented:

- General-Purpose Input/Output (GPIO).

- Universal Asynchronous Receiver Transmitter (UART).

- Serial Peripheral Interface (SPI).

- Inter-Integrated Circuit (I2C).

- Timer and Pulse Width Modulation (PWM).

- Analog-to-Digital Converter (ADC).

## 3. Hardware Platform

MCU: STM32F103C8T6.

Clock: 8 MHz internal clock (default).

Peripheral devices and modules:

- User push button.

- Light Emitting Diode (LED).

- CP2102 Mini USB-to-UART converter.

- ADXL345 digital accelerometer.

- LM35 analog temperature sensor.

- 10 kΩ potentiometer.

Programming: ST-Link.

Development style: Bare metal (direct register access).

## 4. Demonstration Experiments

The following demonstrations validate the functionality of each implemented peripheral driver.

### **GPIO:**

Description:

A push button is used as a digital input. When the microcontroller detects the button press, it activates an LED output.

Concepts demonstrated:

- Input configuration.

- Output configuration.

- Digital signal reading and writing.

Video:

  [GPIO_Demo_Video](https://youtube.com/shorts/TdySQsNt4y0?feature=share)

### **UART:**

Description:

The microcontroller receives a character ('A') from a personal computer via UART. Upon successful reception, it transmits a confirmation string ("RECEIVED_A") back to the computer.

Concepts demonstrated:

- UART initialization.

- Data transmission.

- Data reception.

- Serial communication protocol.

Video:

  [UART_Demo_Video](https://youtube.com/shorts/IpbeLPs09uc?feature=share)

### **SPI:**

Description:

Two microcontrollers communicate using the SPI protocol. MCU1 transmits character 'A' to MCU2, MCU2 responds with character 'B'. MCU1 confirms reception by sending "RECEIVED_B" to the PC via UART.

Concepts demonstrated:

- Master-Slave communication.

- Full-duplex synchronous communication.

- Multi-device interfacing.

Video:

  [SPI_Demo_Video](https://youtube.com/shorts/svTzy_lLtls?feature=share)

### **I2C:**

Description:

The microcontroller reads acceleration data from the ADXL345 accelerometer using the I2C protocol and transmits the data to the PC via UART.

Concepts demonstrated:

- I2C master mode configuration.

- Multi-byte data reception.

- Sensor interfacing.

Video:

  [I2C_Demo_Video](https://youtube.com/shorts/wqdRMsodFWk?feature=share)

### **TIMER:**

Description:

PWM is used to control LED brightness. The duty cycle increases in 10% increments with a delay of 100 ms between each step.

Concepts demonstrated:

- Timer configuration.

- PWM generation.

- Duty cycle control.

Video:

  [TIMER_Demo_Video](https://youtube.com/shorts/yp1pG0UOCjQ?feature=share)

### **ADC:**

Description:

The ADC peripheral samples analog signals from multiple channels: voltage measurement from a potentiometer (mV) and temperature measurement from the LM35 sensor (*C x 10). Results are transmitted to the PC for monitoring.

Concepts demonstrated:

- Multi-channel ADC configuration.

- Analog signal conversion.

- Sensor data acquisition.

Video:

  [ADC_Demo_Video](https://youtube.com/shorts/zZj3HEnZZNo?feature=share)

## 5. Author

Learner: Vo Phuc Thinh.
