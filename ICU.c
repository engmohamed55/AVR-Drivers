#include "ICU.h"

void ICU_Init(uint8 edge_select, uint8 pre)
{
	TCCR1A =0;
	TCNT1L =0;
	TCNT1H =0;
	ICR1L = 0;
	ICR1H = 0;
	Set_Bit(TIFR,ICF1);
	DIO_SetPinDirection(PIN30,IN); //PD6
	if(edge_select)
		Set_Bit(TCCR1B,ICES1);
	else
		Clear_Bit(TCCR1B,ICES1);
	TCCR1B = ( (pre&0x07) | (TCCR1B&0xF8) );	
	Clear_Bit(TIMSK,TICIE1);
	
}

uint16 ICU_Time(void)
{
	uint16 temp;
	while(!Get_Bit(TIFR,ICF1));
	Set_Bit(TIFR,ICF1);
	temp = (ICR1H<<8) | ICR1L;
	return temp;
}