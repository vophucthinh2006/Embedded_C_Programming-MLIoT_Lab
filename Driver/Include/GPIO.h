#ifndef __GPIO_H
#define __GPIO_H
#include <stdint.h>

#define GPIOA_ADD_BASE    0x40010800UL
#define GPIOB_ADD_BASE    0x40010C00UL
#define GPIOC_ADD_BASE    0x40011000UL

#define GPIOA_CRL         (*(volatile uint32_t*)(GPIOA_ADD_BASE + 0x00))
#define GPIOA_CRH         (*(volatile uint32_t*)(GPIOA_ADD_BASE + 0x04))
#define GPIOA_IDR         (*(volatile uint32_t*)(GPIOA_ADD_BASE + 0x08))
#define GPIOA_ODR         (*(volatile uint32_t*)(GPIOA_ADD_BASE + 0x0C))
#define GPIOA_BSRR        (*(volatile uint32_t*)(GPIOA_ADD_BASE + 0x10))
#define GPIOA_BRR         (*(volatile uint32_t*)(GPIOA_ADD_BASE + 0x14))
#define GPIOA_LCKR        (*(volatile uint32_t*)(GPIOA_ADD_BASE + 0x18))

#define GPIOB_CRL         (*(volatile uint32_t*)(GPIOB_ADD_BASE + 0x00))
#define GPIOB_CRH         (*(volatile uint32_t*)(GPIOB_ADD_BASE + 0x04))
#define GPIOB_IDR         (*(volatile uint32_t*)(GPIOB_ADD_BASE + 0x08))
#define GPIOB_ODR         (*(volatile uint32_t*)(GPIOB_ADD_BASE + 0x0C))
#define GPIOB_BSRR        (*(volatile uint32_t*)(GPIOB_ADD_BASE + 0x10))
#define GPIOB_BRR         (*(volatile uint32_t*)(GPIOB_ADD_BASE + 0x14))
#define GPIOB_LCKR        (*(volatile uint32_t*)(GPIOB_ADD_BASE + 0x18))

#define GPIOC_CRL         (*(volatile uint32_t*)(GPIOC_ADD_BASE + 0x00))
#define GPIOC_CRH         (*(volatile uint32_t*)(GPIOC_ADD_BASE + 0x04))
#define GPIOC_IDR         (*(volatile uint32_t*)(GPIOC_ADD_BASE + 0x08))
#define GPIOC_ODR         (*(volatile uint32_t*)(GPIOC_ADD_BASE + 0x0C))
#define GPIOC_BSRR        (*(volatile uint32_t*)(GPIOC_ADD_BASE + 0x10))
#define GPIOC_BRR         (*(volatile uint32_t*)(GPIOC_ADD_BASE + 0x14))
#define GPIOC_LCKR        (*(volatile uint32_t*)(GPIOC_ADD_BASE + 0x18))

//PORT
typedef enum{
	GPIO_PORTA = 'A',
	GPIO_PORTB = 'B',
	GPIO_PORTC = 'C'
}GPIO_PORT_t;

//CNF
typedef enum{
	//INPUT
	GPIO_CNF_IN_ANA    = 0b00,
	GPIO_CNF_IN_FLT    = 0b01,
	GPIO_CNF_IN_PU     = 0b110,
	GPIO_CNF_IN_PD     = 0b010,
	GPIO_CNF_IN_RES    = 0b11,
	//OUTPUT
	GPIO_CNF_OUT_PP    = 0b00,
	GPIO_CNF_OUT_OD    = 0b01,
	GPIO_CNF_AF_PP     = 0b10,
	GPIO_CNF_AF_OD     = 0b11
}GPIO_CNF_t;

//MODE
typedef enum{
	GPIO_MODE_IN      = 0b00,
	GPIO_MODE_OUT_10M = 0b01,
	GPIO_MODE_OUT_2M  = 0b10,
	GPIO_MODE_OUT_50M = 0b11
}GPIO_MODE_t;

//PINSTATE
typedef enum{
	GPIO_PIN_RESET = 0b0,
	GPIO_PIN_SET   = 0b1
}GPIO_PINSTATE_t;

void GPIO_Config(
		GPIO_PORT_t port,
		uint8_t pin,
		GPIO_CNF_t cnf,
		GPIO_MODE_t mode
		);

void GPIO_Write_Pin(
		GPIO_PORT_t port,
		uint8_t pin,
		GPIO_PINSTATE_t state
		);

uint8_t GPIO_Read_Pin(
		GPIO_PORT_t port,
		uint8_t pin
		);

#endif
