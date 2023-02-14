/*
 * TIMER1.h
 *
 * Created: 11/18/2022 10:14:53 AM
 *  Author: Ahmed Yasser
 */ 
#ifndef TIMER1_H_
#define TIMER1_H_

#include "BitMath.h"     

#define TCCR1A_REG (*(volatile unsigned char*) 0x4F)
#define TCCR1B_REG (*(volatile unsigned char*) 0x4E)
#define ICR1L_REG (*(volatile unsigned short int*) 0x46) 
// short int 16 bit also takes from ICR1H
#define OCR1AL_REG (*(volatile unsigned short int*) 0x4A)
// short int 16 bit also takes from OCR1AH
#define TCNT1L_REG (*(volatile unsigned short int*)0x4C)
#define TMSK_REG (*(volatile unsigned char*)0x59)
#define TIFR_REG (*(volatile unsigned char*)0x58)

void Timer1_Init(void);

#endif /* TIMER1_H_*/