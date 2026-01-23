#ifndef __AFIO_H
#define __AFIO_H
#include <stdint.h>

#define AFIO_ADD_BASE    0x40010000UL

#define AFIO_EVCR        (*(volatile uint32_t*)(AFIO_ADD_BASE + 0x00))
#define AFIO_MAPR        (*(volatile uint32_t*)(AFIO_ADD_BASE + 0x04))
#define AFIO_EXTICR1     (*(volatile uint32_t*)(AFIO_ADD_BASE + 0x08))
#define AFIO_EXTICR2     (*(volatile uint32_t*)(AFIO_ADD_BASE + 0x0C))
#define AFIO_EXTICR3     (*(volatile uint32_t*)(AFIO_ADD_BASE + 0x10))
#define AFIO_EXTICR4     (*(volatile uint32_t*)(AFIO_ADD_BASE + 0x14))
#define AFIO_MAPR2       (*(volatile uint32_t*)(AFIO_ADD_BASE + 0x1C))

#endif
