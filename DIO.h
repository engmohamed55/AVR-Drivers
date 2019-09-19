#ifndef DIO_H_
#define DIO_H_

#include "Macro.h"

#define PINA 			(*((volatile uint8 *)0x39))
#define PINB 			(*((volatile uint8 *)0x36))
#define PINC 			(*((volatile uint8 *)0x33))
#define PIND 			(*((volatile uint8 *)0x30))
#define PORTA 			(*((volatile uint8 *)0x3B))
#define PORTB			(*((volatile uint8 *)0x38))
#define PORTC 			(*((volatile uint8 *)0x35))
#define PORTD			(*((volatile uint8 *)0x32))
#define DDRA			(*((volatile uint8 *)0x3A))
#define DDRB 			(*((volatile uint8 *)0x37))
#define DDRC 			(*((volatile uint8 *)0x34))
#define DDRD 			(*((volatile uint8 *)0x31))

#define OUT 1
#define IN  0
#define HIGH 1
#define LOW 0

enum{PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,PIN8,PIN9,PIN10,PIN11,PIN12,PIN13,PIN14,PIN15,PIN16,PIN17,PIN18,PIN19,
PIN20,PIN21,PIN22,PIN23,PIN24,PIN25,PIN26,PIN27,PIN28,PIN29,PIN30,PIN31};

void  DIO_WritePin(uint8 PinNum,uint8 PinValue);
uint8 DIO_ReadPin(uint8 PinNum);
void  DIO_SetPinDirection(uint8 PinNum, uint8 PinDirection);



#endif