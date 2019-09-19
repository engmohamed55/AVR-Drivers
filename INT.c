#include "INT.h"



void INT_Init(uint8 level)
{
	#ifdef INTR0
	DIO_SetPinDirection(PIN26,IN);
	Set_Bit(GICR,INT0);
	MCUCR = (level&0x03) | (MCUCR&0xFC);
	Set_Bit(SREG,I);
	
	
	#elif defined INTR1
	DIO_SetPinDirection(PIN27,IN);
	Set_Bit(GICR,INT1);
	MCUCR = (level&0x03)<<2 | (MCUCR&0xF3);
	Set_Bit(SREG,I);
	
	
	#elif defined INTR2
	DIO_SetPinDirection(PIN10,IN);
	Set_Bit(GICR,INT2);
	if(level == Redge)
	{
		Set_Bit(MCUCSR,ISC2);
	}
	else
	{
		Clear_Bit(MCUCSR,ISC2);
	}
	Set_Bit(SREG,I);
	
	#endif
	
}