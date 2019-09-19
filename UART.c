#include "UART.h"
#include "UART_CFG.h"
#include <avr/interrupt.h>



extern  uint8 Data;
//uint8 Data_Index =0;







Status UART_Init(void)
{
	uint16 BAUDRATE;
	Clear_Bit(UCSRA,FE);
	Clear_Bit(UCSRA,DOR);
	Clear_Bit(UCSRA,PE);
	if(UART_CFG.speed)
		Set_Bit(UCSRA,U2X);
	else
		Clear_Bit(UCSRA,U2X);

	if(UART_CFG.RX)
		Set_Bit(UCSRB,RXCIE);
	else
		Clear_Bit(UCSRB,RXCIE);

	if(UART_CFG.TX)
		Set_Bit(UCSRB,TXCIE);
	else
		Clear_Bit(UCSRB,TXCIE);

	if(UART_CFG.Empty)
		Set_Bit(UCSRB,UDRIE);
	else
		Clear_Bit(UCSRB,UDRIE);

	Set_Bit(SREG,I);
	Set_Bit(UCSRB,TXEN);
	Set_Bit(UCSRB,RXEN);
	Set_Bit(UCSRC,URSEL);
	Clear_Bit(UCSRC,UMSEL);
	UCSRC =  ( (UART_CFG.Par<<4) & 0x30 ) | (UCSRC & 0xCF);

	if(UART_CFG.STOP)
		Set_Bit(UCSRC,USBS);
	else
		Clear_Bit(UCSRC,USBS);

	UCSRC = ( (UART_CFG.data <<1) & 0x6 ) | (UCSRC & 0xF9);
	UCSRB = (UART_CFG.data & 0x4) | (UCSRB & 0xFB);

	BAUDRATE =  (((F_CPU / (UART_CFG.Baudrate * 8UL))) - 1);
	UBRRL = BAUDRATE;



	return OK;

}



Status UART_sendChar_Int(const uint8 Char)
{
	uint8 Ret;

	UDR=Char;
	Ret = OK;
	return Ret;
}

Status UART_Send_Int(const uint8 *Str)
{
	uint8 i =0,Ret;
	while(Str[i] != '\0')
	{
		Ret=UART_sendChar_Int(Str[i]);
		if(Ret == OK)
		{
			i++;
		}
		else
		{
			Ret = NOT_OK;
			break;
		}
	}
	return Ret;
}



Status UART_sendChar_Pol(const uint8 Char)
{
	UDR=Char;
	while(!Get_Bit(UCSRA,TXC));
	Set_Bit(UCSRA,TXC);
	return OK;
}



Status UART_Send_Pol(const uint8 *Str)
{
	uint8 i =0;
	while(Str[i] != '\0')
	{
		UART_sendChar_Pol(Str[i]);
		i++;
	}
	return OK;
}


uint8 UART_recChar_Pol(void)
{
	while(!Get_Bit(UCSRA,RXC));
	return UDR;
}


Status UART_Receive_Pol(uint8 *Str)
{
	uint8 i = 0;
	Str[i] = UART_recChar_Pol();
	while(Str[i] != '#')
	{
		i++;
		Str[i] = UART_recChar_Pol();
	}
	Str[i] = '\0';
	return OK;
}



ISR(USART_RXC_vect)
{
	Data=UDR;
	//Data_Index++;
}

ISR(USART_TXC_vect)
{
	DDRB=0xff;
	PORTB ^= (1<<0 );
}
