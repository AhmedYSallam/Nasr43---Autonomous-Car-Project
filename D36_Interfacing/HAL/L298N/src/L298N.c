/*
 * L298N.c
 *
 * Created: 2/11/2023 1:01:41 PM
 *  Author: Ahmed Yasser
 */ 
#include "L298N.h"

void Motor_Init(void){
	SetBit(DDRC_Reg, H4);
	SetBit(DDRC_Reg, H3);
	SetBit(DDRC_Reg, H2);
	SetBit(DDRC_Reg, H1);
	ClearBit(PORTC_Reg, H4);
	ClearBit(PORTC_Reg, H3);
	ClearBit(PORTC_Reg, H2);
	ClearBit(PORTC_Reg, H1);
}

void Motor_Left(void){
	SetBit(PORTC_Reg, H1);
	ClearBit(PORTC_Reg, H3);
	ClearBit(PORTC_Reg, H2);
	ClearBit(PORTC_Reg, H4);
}
void Motor_Right(void){
	ClearBit(PORTC_Reg, H2);
	SetBit(PORTC_Reg, H4);
	ClearBit(PORTC_Reg, H3);
	ClearBit(PORTC_Reg, H1);
}
void Motor_Forward(void){
	SetBit(PORTC_Reg, H4);
	SetBit(PORTC_Reg, H1);
	ClearBit(PORTC_Reg, H3);
	ClearBit(PORTC_Reg, H2);
}
void Motor_Stop(void){
	
	ClearBit(PORTC_Reg, H3);
	ClearBit(PORTC_Reg, H1);
	ClearBit(PORTC_Reg, H4);
	ClearBit(PORTC_Reg, H2);
}
void Motor_BackWard(void){
	SetBit(PORTC_Reg, H3);
	SetBit(PORTC_Reg, H2);
	ClearBit(PORTC_Reg, H4);
	ClearBit(PORTC_Reg, H1);
}