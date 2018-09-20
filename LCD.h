/*
 * GPIO Driver.h
 *
 * Created: 2018-09-19 
 * Author : Mohammed
 */ 
#ifndef LCD_H_
#define LCD_H_

#include "LCD_CONF.h"


#define CONTROL_PORT 	PORTA
#define CONTROL_DDR 	DDRA
#define DATA_PORT 		PORTD
#define DATA_DDR 		DDRD


#define RS		PA5
#define RW		PA6
#define E 		PA7


#define LCD_4_BIT_MODE				0x02
#define LCD_8_BIT_2_LINES_COMMAND	0x38
#define LCD_4_BIT_2_LINES_COMMAND	0x28
#define LCD_CLEAR					0x01
#define CURSOR_OFF					0x0C
#define CURSOR_ON					0x0E
#define CURSOR_BLINKING				0x0F
#define CURSOR_RIGHT				0x14
#define CURSOR_LEFT					0x10




void LCD_sendCommand(uint8 Command);
void LCD_INIT(void);
void LCD_sendChar(uint8 Char);
void LCD_sendString( uint8 *str);
void LCD_Clear(void);







#endif
