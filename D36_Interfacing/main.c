

#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "Clock.h"
#include "DIO.h"
#include "LCD.h"
#include "BitMath.h"
#include "Servo.h"
#include "Ultrasonic.h"
#include "L298N.h"

int left = 4850;
int straight = 3080;
int right = 1350;

char string[10];
double dist = 100;
double distanceright;
double distanceleft;

double lookright(void);
double lookleft(void);
double readPing(void);
void moveRight(void);
void moveLeft(void);
void moveForward(void);
void moveBackward(void);
void moveStop(void);

int main(void)
{
	Motor_Init();
	LCD_Init();
	Servo_Init(straight);
	_delay_ms(2000);
	dist = readPing();
	_delay_ms(100);
	dist = readPing();
	_delay_ms(100);
	dist = readPing();
	_delay_ms(100);
	dist = readPing();
	_delay_ms(100);
	
	while(1)
	{
		distanceleft = 0;
		distanceright = 0;
		_delay_ms(50);
		if(dist <=35)
		{
			moveStop();
			_delay_ms(300);
			moveBackward();
			_delay_ms(400);
			moveStop();
			_delay_ms(300);
			distanceright = lookright();
			_delay_ms(300);
			distanceleft = lookleft();
			_delay_ms(300);
			if(distanceright >= distanceleft)
			{
				moveRight();
				moveStop();
			}
			else
			{
				moveLeft();
				moveStop();
			}
		} 
		else
		{
			moveForward();
		}
		dist = readPing();
	} 
	
}

double lookright(void){
	Servo_Init(right);
	_delay_ms(500);
	int cm = readPing();
	_delay_ms(100);
	Servo_Init(straight);
	return cm;
}
double lookleft(void){
	Servo_Init(left);
	_delay_ms(500);
	int cm = readPing();
	_delay_ms(100);
	Servo_Init(straight);
	return cm;
}
double readPing(void){
	_delay_ms(70);
	Ultrasonic_Init();
	Ultrasonic_Ping();
	dtostrf(distance, 2, 2, string);
	LCD_String_Pos(0, 0, "Dist = ");
	LCD_String_Pos(0, 7, string);
	return distance;
}
void moveRight(void){
	LCD_Clear();
	LCD_String_Pos(1, 1, "TURNING RIGHT");
	Motor_Right();
	_delay_ms(500);
	Motor_Forward();
}
void moveLeft(void){
	LCD_Clear();
	LCD_String_Pos(1, 1, "TURNING LEFT");
	Motor_Left();
	_delay_ms(500);
	Motor_Forward();
}
void moveForward(void){
	LCD_Clear();
	LCD_String_Pos(1, 1, "FORWARD");
	Motor_Forward();
	
}
void moveBackward(void){
	LCD_Clear();
	LCD_String_Pos(1, 1, "BACKWARD");
	Motor_BackWard();
}
void moveStop(void){
	LCD_Clear();
	LCD_String_Pos(1, 1, "STOPPED");
	Motor_Stop();
}