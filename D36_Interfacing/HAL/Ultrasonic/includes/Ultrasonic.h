/*
 * Ultrasonic.h
 *
 * Created: 2/4/2023 5:37:28 PM
 *  Author: Ahmed Yasser
 */
#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include <avr/interrupt.h>
#include <string.h>
#include "Clock.h"
#include "STD_Types.h"
#include "TIMER1.h"
#include "DIO.h"
#include "LCD.h"

#define Trigger 6

volatile int TimerOvf;
long count;
double distance;
 
void Ultrasonic_Init(void);
void Ultrasonic_Ping(void);

#endif