#ifndef __ADC_H
#define __ADC_H
#include <stdint.h>

#define ADC1_ADD_BASE    0x40012400UL
#define ADC2_ADD_BASE    0x40012800UL

#define ADC_ADD_SR       0x00
#define ADC_ADD_CR1      0x04
#define ADC_ADD_CR2      0x08
#define ADC_ADD_SMPR1    0x0C
#define ADC_ADD_SMPR2    0x10
#define ADC_ADD_JOFR1    0x14
#define ADC_ADD_JOFR2    0x18
#define ADC_ADD_JOFR3    0x1C
#define ADC_ADD_JOFR4    0x20
#define ADC_ADD_HTR      0x24
#define ADC_ADD_LTR      0x28
#define ADC_ADD_SQR1     0x2C
#define ADC_ADD_SQR2     0x30
#define ADC_ADD_SQR3     0x34
#define ADC_ADD_ISQR     0x38
#define ADC_ADD_JDR1     0x3C
#define ADC_ADD_JDR2     0x40
#define ADC_ADD_JDR3     0x44
#define ADC_ADD_JDR4     0x48
#define ADC_ADD_DR       0x4C

#define ADC1_SR          (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_SR))
#define ADC1_CR1         (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_CR1))
#define ADC1_CR2         (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_CR2))
#define ADC1_SMPR1       (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_SMPR1))
#define ADC1_SMPR2       (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_JOFR2))
#define ADC1_JOFR1       (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_JOFR1))
#define ADC1_JOFR2       (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_JOFR2))
#define ADC1_JOFR3       (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_JOFR3))
#define ADC1_JOFR4       (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_JOFR4))
#define ADC1_HTR         (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_HTR))
#define ADC1_LTR         (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_LTR))
#define ADC1_SQR1        (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_SQR1))
#define ADC1_SQR2        (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_SQR2))
#define ADC1_SQR3        (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_SQR3))
#define ADC1_ISQR        (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_ISQR))
#define ADC1_JDR1        (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_JDR1))
#define ADC1_JDR2        (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_JDR2))
#define ADC1_JDR3        (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_JDR3))
#define ADC1_JDR4        (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_JDR4))
#define ADC1_DR          (*(volatile uint32_t*)(ADC1_ADD_BASE + ADC_ADD_DR))

#define ADC2_SR          (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_SR))
#define ADC2_CR1         (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_CR1))
#define ADC2_CR2         (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_CR2))
#define ADC2_SMPR1       (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_SMPR1))
#define ADC2_SMPR2       (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_JOFR2))
#define ADC2_JOFR1       (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_JOFR1))
#define ADC2_JOFR2       (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_JOFR2))
#define ADC2_JOFR3       (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_JOFR3))
#define ADC2_JOFR4       (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_JOFR4))
#define ADC2_HTR         (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_HTR))
#define ADC2_LTR         (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_LTR))
#define ADC2_SQR1        (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_SQR1))
#define ADC2_SQR2        (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_SQR2))
#define ADC2_SQR3        (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_SQR3))
#define ADC2_ISQR        (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_ISQR))
#define ADC2_JDR1        (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_JDR1))
#define ADC2_JDR2        (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_JDR2))
#define ADC2_JDR3        (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_JDR3))
#define ADC2_JDR4        (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_JDR4))
#define ADC2_DR          (*(volatile uint32_t*)(ADC2_ADD_BASE + ADC_ADD_DR))

//ADC_
typedef enum{
	ADC1,
	ADC2
}ADC_t;

//SAMPLE TIME
typedef enum{
	ADC_SAMPLE_TIME_1_5   = 0b000,
	ADC_SAMPLE_TIME_7_5   = 0b001,
	ADC_SAMPLE_TIME_13_5  = 0b010,
	ADC_SAMPLE_TIME_28_5  = 0b011,
	ADC_SAMPLE_TIME_41_5  = 0b100,
	ADC_SAMPLE_TIME_55_5  = 0b101,
	ADC_SAMPLE_TIME_71_5  = 0b110,
	ADC_SAMPLE_TIME_239_5 = 0b111,
}ADC_SAMPLE_TIME_t;

//MODE
typedef enum{
	ADC_MODE_SINGLE = 0,
	ADC_MODE_CONTINUOUS = 1
}ADC_MODE_t;

void ADC_Number_Conversation(
		ADC_t ADC_,
		uint8_t number
		);

void ADC_Init(
		ADC_t ADC_,
		uint8_t channel,
		ADC_SAMPLE_TIME_t sample,
		uint8_t sequence,
		ADC_MODE_t mode
		);

uint16_t ADC_Read_Pin(
		ADC_t ADC_
		);

#endif
