/*
 * Ultrasonic.c
 *
 * Created: 2/4/2023 5:37:55 PM
 *  Author: Ahmed Yasser
 */ 
#include "Ultrasonic.h"

void Ultrasonic_Init(void){
	TimerOvf = 0;
	SetBit(DDRB_Reg, 6);
	ClearBit(DDRD_Reg, 6);
	sei();
	SetBit(TMSK_REG, 2);
	TCCR1A_REG = 0;
	TCCR1B_REG = 0;
}
void Ultrasonic_Ping(void){
	SetBit(PORTB_Reg, Trigger);
	_delay_us(10);
	ClearBit(PORTB_Reg, Trigger);
	TCNT1L_REG = 0;
	SetBit(TCCR1B_REG, 6);
	SetBit(TCCR1B_REG, 0);
	SetBit(TIFR_REG, 5);
	SetBit(TIFR_REG, 2);
	while ((TIFR_REG & (1 << 5)) == 0);
	TCNT1L_REG = 0;
	ClearBit(TCCR1B_REG, 6);
	SetBit(TCCR1B_REG, 0);
	SetBit(TIFR_REG, 5);
	SetBit(TIFR_REG, 2);
	TimerOvf = 0;
	while ((TIFR_REG & (1 << 5)) == 0);
	count = ICR1L_REG + (65535 * TimerOvf);
	distance = (double)count / 932.95;
}

ISR(TIMER1_OVF_vect)
{
	TimerOvf++;
}