#include "Timer.h"

uint8 *ptr = (uint8 *) 0;

void Timer_Init(uint8 pre, uint8 delay)
{
	ptr=&delay;
	#ifdef Normal
	Clear_Bit(TCCR0,WGM01);
	Clear_Bit(TCCR0,WGM00);
	TCCR0  = (pre&0x7) | (TCCR0&0xF8);

	#elif defined Phase_PWM
	DIO_SetPinDirection(PIN11,OUT);
	Clear_Bit(TCCR0,TCCR0);
	Clear_Bit(TCCR0,WGM01);
	Set_Bit(TCCR0,WGM00);
	Set_Bit(TCCR0,COM01);
	Set_Bit(TCCR0,COM00);
	TCCR0  = (pre&0x7) | (TCCR0&0xF8);
	OCR0 = 255-(2.55*Duty);

	#elif defined CTC
	Set_Bit(TCCR0,WGM01);
	Clear_Bit(TCCR0,WGM00);
	TCCR0  = (pre&0x7) | (TCCR0&0xF8);
	OCR0 = delay;
	


	#elif defined PWM
	#endif
}


void Timer_Delay(void)
{
	#ifdef Normal
	TCNT0 = 256 - *ptr;
	while( ! (TIFR & (1<<TOV0)) );
	TIFR |= (1<<TOV0);


	#elif defined Phase_PWM


	#elif defined CTC
	TCNT0 = 0;
	while( ! (TIFR & (1<<OCF0)) );
	TIFR |= (1<<OCF0);

	#elif defined PWM
	#endif
	
}
