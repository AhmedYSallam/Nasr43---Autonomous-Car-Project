/*
 * LCD.c
 *
 * Created: 2/3/2023 11:31:20 AM
 *  Author: Ahmed Yasser
 */ 
#include "LCD.h"

void LCD_Command( unsigned char cmnd )
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0); 
	ClearBit(LCD_PortB, RS)	;
	SetBit(LCD_PortB, EN);		
	_delay_us(1);
	ClearBit(LCD_PortB, EN);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4); 
	SetBit(LCD_PortB, EN);
	_delay_us(1);
	ClearBit(LCD_PortB, EN);
	_delay_ms(2);
}


void LCD_Char( unsigned char data )
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);
	SetBit(LCD_PortB, RS);
	SetBit(LCD_PortB, EN);
	_delay_us(1);
	ClearBit(LCD_PortB, EN);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (data << 4); 
	SetBit(LCD_PortB, EN);
	_delay_us(1);
	ClearBit(LCD_PortB, EN);
	_delay_ms(2);
}

void LCD_Init (void)			
{
	LCD_Dir = 0xFF;	
	SetBit(DDRB_Reg, 1);
	SetBit(DDRB_Reg, 2);
	SetBit(DDRB_Reg, 3);
	ClearBit(PORTB_Reg, 2);		
	_delay_ms(20);		
	LCD_Command(0x02);		
	LCD_Command(0x28);              
	LCD_Command(0x0c);            
	LCD_Command(0x06);              
	LCD_Command(0x01);            
	_delay_ms(2);
}


void LCD_String (char *str)		
{
	int i;
	for(i=0;str[i]!=0;i++)		
	{
		LCD_Char (str[i]);
	}
}

void LCD_String_Pos (char row, char pos, char *str)	
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);	
	LCD_String(str);	
}

void LCD_Clear()
{
	LCD_Command (0x01);		
	_delay_ms(2);
	LCD_Command (0x80);		
}
