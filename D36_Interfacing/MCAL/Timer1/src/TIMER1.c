/*
 * TIMER1.c
 *
 * Created: 11/18/2022 10:15:06 AM
 *  Author: Ahmed Yasser
 */ 
#include "TIMER1.h"
 
void Timer1_Init(void){
	/* Set COM1  and COM0 for both TCCR1A and TCCR1B*/
	SetBit(TCCR1A_REG, 7);
	ClearBit(TCCR1A_REG, 6);
	SetBit(TCCR1B_REG, 7);
	ClearBit(TCCR1B_REG, 6);
	/* Set Bits WGM13->10*/
	ClearBit(TCCR1A_REG, 0);
	SetBit(TCCR1A_REG, 1);
	SetBit(TCCR1B_REG, 3);
	SetBit(TCCR1B_REG, 4);
	/* Set  ICR : 40,000*/
	ICR1L_REG = 40000;
	/* Choose Prescaler : 8*/
	SetBit(TCCR1B_REG, 1);
	/* Set  OCR1 : 40,000*/
	OCR1AL_REG  = 2000;
	
	
}