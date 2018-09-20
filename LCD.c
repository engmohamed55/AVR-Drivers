/*
 * GPIO Driver.h
 *
 * Created: 2018-09-20
 * Author : Mohammed
 */ 
 
 #include "LCD.h"




void LCD_sendCommand(uint8 Command)
{
	#ifdef EIGHT_BIT_MODE
		CLEAR_BIT(CONTROL_PORT,RS);
		CLEAR_BIT(CONTROL_PORT,RW);
		_delay_ms(1);
		SET_BIT(CONTROL_PORT,E);
		_delay_ms(1);
		DATA_PORT = Command;
		_delay_ms(1);
		CLEAR_BIT(CONTROL_PORT,E);
		_delay_ms(1);


	#elif defined FOUR_BIT_MODE
		CLEAR_BIT(CONTROL_PORT,RS);
		CLEAR_BIT(CONTROL_PORT,RW);
		_delay_ms(1);
		SET_BIT(CONTROL_PORT,E);
		_delay_ms(1);
		#ifdef LOWER_BITS
			DATA_PORT = (DATA_PORT & 0xF0) | ((0xF0 & Command)>>4);
		#elif defined HIGHER_BITS
			DATA_PORT = (DATA_PORT & 0x0F) | (0xF0 & Command);
		#endif
	_delay_ms(1);
	CLEAR_BIT(CONTROL_PORT,E);
	_delay_ms(1);	
	SET_BIT(CONTROL_PORT,E);
	_delay_ms(1);
		#ifdef LOWER_BITS
			DATA_PORT = (DATA_PORT & 0xF0) | (0x0F & Command);
		#elif defined HIGHER_BITS
			DATA_PORT = (DATA_PORT & 0x0F) | ((0x0F & Command)<<4);
		#endif
	CLEAR_BIT(CONTROL_PORT,E);
	_delay_ms(1);

	#endif
}

void LCD_INIT(void)
{
	#ifdef EIGHT_BIT_MODE

		DATA_DDR = 0xFF;
		SET_BIT(CONTROL_DDR,RS);
		SET_BIT(CONTROL_DDR,RW);
		SET_BIT(CONTROL_DDR,E);
		LCD_sendCommand(LCD_8_BIT_2_LINES_COMMAND);
		LCD_sendCommand(CURSOR_OFF);
		LCD_Clear();

	#elif defined FOUR_BIT_MODE

		#ifdef LOWER_BITS
		DATA_DDR = 0x0F;
		SET_BIT(CONTROL_DDR,RS);
		SET_BIT(CONTROL_DDR,RW);
		SET_BIT(CONTROL_DDR,E);
		LCD_sendCommand(LCD_4_BIT_MODE);
		LCD_sendCommand(LCD_4_BIT_2_LINES_COMMAND);
		LCD_sendCommand(CURSOR_OFF);
		LCD_Clear();

		#elif defined HIGHER_BITS
		DATA_DDR = 0xF0;
		SET_BIT(CONTROL_DDR,RS);
		SET_BIT(CONTROL_DDR,RW);
		SET_BIT(CONTROL_DDR,E);
		LCD_sendCommand(LCD_4_BIT_MODE);
		LCD_sendCommand(LCD_4_BIT_2_LINES_COMMAND);
		LCD_sendCommand(CURSOR_OFF);
		LCD_Clear();

		#endif

	#endif
}

void LCD_sendChar(uint8 Char)
{
#ifdef EIGHT_BIT_MODE
		SET_BIT(CONTROL_PORT,RS);
		CLEAR_BIT(CONTROL_PORT,RW);
		_delay_ms(1);
		SET_BIT(CONTROL_PORT,E);
		_delay_ms(1);
		DATA_PORT = Char;
		_delay_ms(1);
		CLEAR_BIT(CONTROL_PORT,E);
		_delay_ms(1);


	#elif defined FOUR_BIT_MODE
		SET_BIT(CONTROL_PORT,RS);
		CLEAR_BIT(CONTROL_PORT,RW);
		_delay_ms(1);
		SET_BIT(CONTROL_PORT,E);
		_delay_ms(1);
		#ifdef LOWER_BITS
			DATA_PORT = (DATA_PORT & 0xF0) | ((0xF0 & Char) >> 4);
		#elif defined HIGHER_BITS
			DATA_PORT = (DATA_PORT & 0x0F) | (0xF0 & Char);
		#endif
	_delay_ms(1);
	CLEAR_BIT(CONTROL_PORT,E);
	_delay_ms(1);	
	SET_BIT(CONTROL_PORT,E);
	_delay_ms(1);
		#ifdef LOWER_BITS
			DATA_PORT = (DATA_PORT & 0xF0) | (0x0F & Char);
		#elif defined HIGHER_BITS
			DATA_PORT = (DATA_PORT & 0x0F) | ((0x0F & Char) << 4);
		#endif
	CLEAR_BIT(CONTROL_PORT,E);
	_delay_ms(1);

	#endif

}


void LCD_sendString( uint8 *str)
{
	uint8 i =0;
	while(str[i]!= '\0')
	{
		LCD_sendChar(str[i]);
		i++;
	}
}


void LCD_Clear(void)
{
	LCD_sendCommand(LCD_CLEAR); 
}
