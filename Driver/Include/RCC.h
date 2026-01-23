#ifndef __RCC_H
#define __RCC_H
#include <stdint.h>

#define RCC_ADD_BASE    (0x40021000UL)

#define RCC_CR          (*(volatile uint32_t*)(RCC_ADD_BASE + 0x000))
#define RCC_CFGR        (*(volatile uint32_t*)(RCC_ADD_BASE + 0x004))
#define RCC_CIR         (*(volatile uint32_t*)(RCC_ADD_BASE + 0x008))
#define RCC_APB2RSTR    (*(volatile uint32_t*)(RCC_ADD_BASE + 0x00C))
#define RCC_APB1RSTR    (*(volatile uint32_t*)(RCC_ADD_BASE + 0x010))
#define RCC_AHBENR      (*(volatile uint32_t*)(RCC_ADD_BASE + 0x014))
#define RCC_APB2ENR     (*(volatile uint32_t*)(RCC_ADD_BASE + 0x018))
#define RCC_APB1ENR     (*(volatile uint32_t*)(RCC_ADD_BASE + 0x01C))
#define RCC_BDCR        (*(volatile uint32_t*)(RCC_ADD_BASE + 0x020))
#define RCC_CSR         (*(volatile uint32_t*)(RCC_ADD_BASE + 0x024))
#define RCC_AHBSTR      (*(volatile uint32_t*)(RCC_ADD_BASE + 0x028))
#define RCC_CFGR2       (*(volatile uint32_t*)(RCC_ADD_BASE + 0x02C))

typedef enum{
	//RCC_APB2ENR
	RCC_UART1,
	RCC_SPI1,
	RCC_ADC2,
	RCC_ADC1,
	RCC_PORTC,
	RCC_PORTB,
	RCC_PORTA,
	RCC_AFIO,
	//RCC_APB1ENR
	RCC_I2C2,
	RCC_I2C1,
	RCC_UART2,
	RCC_SPI2,
	RCC_TIM4,
	RCC_TIM3,
	RCC_TIM2
}RCC_PERIPHERAL_t;

void RCC_Enable(
		RCC_PERIPHERAL_t peripheral
		);

#endif
