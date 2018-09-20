/*
 * GPIO Driver.h
 *
 * Created: 2018-09-19 6:00:00 PM
 * Author : Mohammed
 */ 

//---------------------------constants----------------------
#ifndef GPIO_H_
#define GPIO_H_
#include <avr/io.h>

#define PINA 			(*((volatile unsigned long *)0x39)	
#define PINB 			(*((volatile unsigned long *)0x36)	
#define PINC 			(*((volatile unsigned long *)0x33)	
#define PIND 			(*((volatile unsigned long *)0x30)	
#define PORTA 			(*((volatile unsigned long *)0x3B)	
#define PORTB			(*((volatile unsigned long *)0x38)	
#define PORTC 			(*((volatile unsigned long *)0x35)	
#define PORTD			(*((volatile unsigned long *)0x32)	
#define DDRA			(*((volatile unsigned long *)0x3A)	
#define DDRB 			(*((volatile unsigned long *)0x37)	
#define DDRC 			(*((volatile unsigned long *)0x34)	
#define DDRD 			(*((volatile unsigned long *)0x31)	





typedef enum{ PA0=0, PA1=1, PA2=2, PA3=3, PA4=4, PA5=5, PA6=6, PA7=7 }PORT_A_PINS;
typedef enum{ PB0=0, PB1=1, PB2=2, PB3=3, PB4=4, PB5=5, PB6=6, PB7=7 }PORT_B_PINS;
typedef enum{ PC0=0, PC1=1, PC2=2, PC3=3, PC4=4, PC5=5, PC6=6, PC7=7 }PORT_C_PINS;
typedef enum{ PD0=0, PD1=1, PD2=2, PD3=3, PD4=4, PD5=5, PD6=6, PD7=7 }PORT_D_PINS;


//------------------------macros--------------------------------

#define SET_BIT(PORT,PIN) ((PORT) |= (1<<(PIN)))
#define CLEAR_BIT(PORT,PIN) ((PORT) &= (~(1<<(PIN))))
#define SET_PORT(PORT) (PORT=0xFF)
#define CLEAR_PORT(PORT) (PORT=0x00)
#define BIT_IS_SET(PORT,PIN) ((PORT&(1<<PIN)))

#endif
