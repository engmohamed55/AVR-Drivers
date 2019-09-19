#ifndef UART_H_
#define UART_H_

#include "Macro.h"
#include "DIO.h"


#define F_CPU 8000000UL


#define UDR		(*((volatile uint8 *)0x2C))
#define UCSRA	(*((volatile uint8 *)0x2B))
#define UCSRB	(*((volatile uint8 *)0x2A))
#define UCSRC	(*((volatile uint8 *)0x40))
#define UBRRL	(*((volatile uint8 *)0x29))
#define UBRRH	(*((volatile uint8 *)0x40))
#define SREG 			(*((volatile uint8 *)0x5F))




typedef enum {Data_5=0,Data_6=1,Data_7=2,Data_8=3,Data_9=7}Datasize;
typedef enum {One_Stop,Two_Stop}Stopbits;
typedef enum {ParityDIS=0,EvenParity=2,OddParity=3}Parity;
typedef enum {EmptyIntDIS,EmptyIntEN}EmptyIntEn;
typedef enum {TxIntDIS,TxIntEN}TxIntEn;
typedef enum {RxIntDIS,RxIntEN}RxIntEn;
typedef enum {Normal,Double}Doublespeed;
typedef enum {UART0, UART1, UART2, UART3, UART4, UART5, UART6, UART7}UART_NUM;
typedef enum {RXC=7, TXC=6, UDRE=5, FE=4, DOR=3, PE=2, U2X=1, MPCM=0}UCSRA_BITS;
typedef enum {RXCIE=7, TXCIE=6, UDRIE=5, RXEN=4, TXEN=3, UCSZ2=2, RXB8=1, TXB8=0}UCSRB_BITS;
typedef enum {URSEL=7, UMSEL=6, UPM1=5, UPM0=4, USBS=3, UCSZ1=2, UCSZ0=1, UCPOL=0}UCSRC_BITS;
typedef enum {NOT_OK,OK}Status;
typedef enum{I=7 ,T=6, H=5, S=4, V=3, N=2, Z=1, C=0}SREG_REG;


typedef struct {
	uint16 Baudrate;
	Doublespeed speed;
	RxIntEn RX;
	TxIntEn TX;
	EmptyIntEn Empty;
	Datasize data;
	Parity Par;
	Stopbits STOP;
}UART_CFG_S;


Status UART_Init(void);
Status UART_sendChar_Pol(const uint8 Char);
Status UART_Send_Pol(const uint8 *Str);
uint8 UART_recChar_Pol(void);
Status UART_Receive_Pol(uint8 *Str);
Status UART_sendChar_Int(const uint8 Char);
Status UART_Send_Int(const uint8 *Str);

#endif
