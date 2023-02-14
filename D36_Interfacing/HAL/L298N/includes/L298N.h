/*
 * L298N.h
 *
 * Created: 2/11/2023 1:01:24 PM
 *  Author: Ahmed Yasser
 */ 
#ifndef L298N_H_
#define L298N_H_

#include "DIO.h"

#define H4 6
#define H3 5
#define H2 4
#define H1 3

void Motor_Init(void);
void Motor_Left(void);
void Motor_Right(void);
void Motor_Forward(void);
void Motor_Stop(void);
void Motor_BackWard(void);

#endif