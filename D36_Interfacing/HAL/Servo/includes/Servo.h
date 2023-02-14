/*
 * Servo.h
 *
 * Created: 2/3/2023 11:29:44 AM
 *  Author: Ahmed Yasser
 */ 
#ifndef SERVO_H_
#define SERVO_H_

#include "DIO.h"
#include "TIMER1.h"
#include "STD_Types.h"
#include <util/delay.h>

void Servo_Init(Uint16 degree);


#endif