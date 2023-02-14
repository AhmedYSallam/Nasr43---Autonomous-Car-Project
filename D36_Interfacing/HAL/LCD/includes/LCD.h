/*
 * LCD.h
 *
 * Created: 2/3/2023 11:31:13 AM
 *  Author: Ahmed Yasser
 */ 
#ifndef LCD_H_
#define LCD_H_

#include "Clock.h"
#include "DIO.h"
#include <avr/io.h>

#define LCD_Dir  DDRA_Reg			
#define LCD_Port PORTA_Reg		
#define LCD_PortB PORTB_Reg	
#define RS 1			
#define EN 3

void LCD_Init (void);
void LCD_Command( unsigned char cmnd );
void LCD_Char( unsigned char data );
void LCD_String (char *str);		
void LCD_String_Pos (char row, char pos, char *str);	
void LCD_Clear();


#endif 
