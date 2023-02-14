

#ifndef TIMER_HW_H_
#define TIMER_HW_H_
#include "DIO.h"
#include "BitMath.h"
#define TCCR0_REG (*(volatile Uint8*)0x53)
#define TCNT0_REG (*(volatile Uint8*)0x52)
#define OCR0_REG (*(volatile Uint8*)0x5c)
#define TIMSK_REG (*(volatile Uint8*)0x59)
#define TIFR_REG (*(volatile Uint8*)0x58)
#define CS00_BIT 0
#define CS01_BIT 1
#define CS02_BIT 2
#define WGM00_BIT 6
#define WGM01_BIT 3
#define FOC_BIT 7
#define TOIE0_BIT 0
#define OCIE0_BIT 1
#define TOV0_BIT 0
#define OCF0_BIT 1




#endif /* TIMER_HW_H_ */