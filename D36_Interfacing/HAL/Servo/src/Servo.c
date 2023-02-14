/*
 * Servo.c
 *
 * Created: 2/3/2023 11:29:33 AM
 *  Author: Ahmed Yasser
 */ 

#include "Servo.h"
#include <avr/io.h>

void Servo_Init(Uint16 degree){
	TCCR1A_REG = 0;
	TCCR1B_REG = 0;
	SetBit(TCCR1A_REG, 1);
	SetBit(TCCR1A_REG, 7);
	//Prescaler 8. freq 16MHz
	SetBit(TCCR1B_REG, 1);
	SetBit(TCCR1B_REG, 3);
	SetBit(TCCR1B_REG, 4);
	ICR1L_REG = 39999;
	TCNT1L_REG = 0;
	SetBit(DDRD_Reg, 5);
	OCR1AL_REG = degree;
	// -90 1ms, 0 1.5ms, +90 2ms
}
