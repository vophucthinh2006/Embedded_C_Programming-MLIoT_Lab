#ifndef __TIM_H
#define __TIM_H
#include "EXTI.h"
#include <stdint.h>

#define TIM2_ADD_BASE    (0x40000000UL)
#define TIM3_ADD_BASE    (0x40000400UL)
#define TIM4_ADD_BASE    (0x40000800UL)

#define TIM2_CR1         (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x00))
#define TIM2_CR2         (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x04))
#define TIM2_SMCR        (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x08))
#define TIM2_DIER        (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x0C))
#define TIM2_SR          (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x10))
#define TIM2_EGR         (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x14))
#define TIM2_CCMR1       (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x18))
#define TIM2_CCMR2       (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x1C))
#define TIM2_CCER        (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x20))
#define TIM2_CNT         (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x24))
#define TIM2_PSC         (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x28))
#define TIM2_ARR         (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x2C))
#define TIM2_CCR1        (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x34))
#define TIM2_CCR2        (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x38))
#define TIM2_CCR3        (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x3C))
#define TIM2_CCR4        (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x40))
#define TIM2_DCR         (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x48))
#define TIM2_DMAR        (*(volatile uint32_t*)(TIM2_ADD_BASE + 0x4C))

#define TIM3_CR1         (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x00))
#define TIM3_CR2         (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x04))
#define TIM3_SMCR        (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x08))
#define TIM3_DIER        (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x0C))
#define TIM3_SR          (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x10))
#define TIM3_EGR         (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x14))
#define TIM3_CCMR1       (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x18))
#define TIM3_CCMR2       (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x1C))
#define TIM3_CCER        (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x20))
#define TIM3_CNT         (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x24))
#define TIM3_PSC         (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x28))
#define TIM3_ARR         (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x2C))
#define TIM3_CCR1        (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x34))
#define TIM3_CCR2        (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x38))
#define TIM3_CCR3        (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x3C))
#define TIM3_CCR4        (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x40))
#define TIM3_DCR         (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x48))
#define TIM3_DMAR        (*(volatile uint32_t*)(TIM3_ADD_BASE + 0x4C))

#define TIM4_CR1         (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x00))
#define TIM4_CR2         (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x04))
#define TIM4_SMCR        (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x08))
#define TIM4_DIER        (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x0C))
#define TIM4_SR          (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x10))
#define TIM4_EGR         (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x14))
#define TIM4_CCMR1       (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x18))
#define TIM4_CCMR2       (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x1C))
#define TIM4_CCER        (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x20))
#define TIM4_CNT         (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x24))
#define TIM4_PSC         (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x28))
#define TIM4_ARR         (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x2C))
#define TIM4_CCR1        (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x34))
#define TIM4_CCR2        (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x38))
#define TIM4_CCR3        (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x3C))
#define TIM4_CCR4        (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x40))
#define TIM4_DCR         (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x48))
#define TIM4_DMAR        (*(volatile uint32_t*)(TIM4_ADD_BASE + 0x4C))

typedef enum{
	TIM2,
	TIM3,
	TIM4
}TIM_t;

typedef enum{
	TIM_CHANNEL_1,
	TIM_CHANNEL_2,
	TIM_CHANNEL_3,
	TIM_CHANNEL_4
}TIM_CHANNEL_t;

void TIM_Init_IT_s(
		TIM_t TIM_,
		uint16_t s
		);

void TIM1_IRQHandler(void);

void TIM_Delay_ms(
		TIM_t TIM_,
		uint16_t ms
		);

void TIM_PWM(
		TIM_t TIM_,
		TIM_CHANNEL_t channel
		);

void TIM_PWM_Bright_Percent(
		TIM_t TIM_,
		TIM_CHANNEL_t channel,
		uint8_t percent
		);

#endif
