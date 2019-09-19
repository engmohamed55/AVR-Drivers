#ifndef TIMER_H_
#define TIMER_H_


#include "DIO.h"


#define TCNT0			(*((volatile uint8 *)0x52))
#define TCNT1L			(*((volatile uint8 *)0x4C))
#define TCNT1H			(*((volatile uint8 *)0x4D))
#define TCCR0			(*((volatile uint8 *)0x53))
#define TIMSK			(*((volatile uint8 *)0x59))
#define TIFR			(*((volatile uint8 *)0x58))
#define OCR0			(*((volatile uint8 *)0x5C))
#define SFIOR			(*((volatile uint8 *)0x50))
#define TCCR1A 			(*((volatile uint8 *)0x4F))
#define TCCR1B 			(*((volatile uint8 *)0x4E))
#define ICR1L 			(*((volatile uint8 *)0x46))
#define ICR1H 			(*((volatile uint8 *)0x47))
#define SREG 			(*((volatile uint8 *)0x5F))


//#define Normal 
#define Phase_PWM 
//#define CTC 
//#define PWM 

#define Duty 100

typedef enum{FOC0=7, WGM00=6, COM01=5, COM00=4, WGM01=3, CS02=2, CS01=1, CS00=0}TCCR0_REG;
typedef enum{OCIE2=7, TOIE2=6, TICIE1=5, OCIE1A=4, OCIE1B=3, TOIE1=2, OCIE0=1, TOIE0=0}TIMSK_REG;
typedef enum{OCF2=7, TOV2=6, ICF1=5, OCF1A=4, OCF1B=3, TOV1=2, OCF0=1, TOV0=0}TIFR_REG;
typedef enum{ADTS2=7, ADTS1=6, ADTS0=5,  ACME=3, PUD=2, PSR2=1, PSR10=0}SFIOR_REG;
typedef enum{COM1A1=7, COM1A0=6, COM1B1=5, COM1B0=4, FOC1A=3, FOC1B=2, WGM11=1, WGM10=0}TCCR1A_REG;
typedef enum{ICNC1=7, ICES1=6, WGM13=4, WGM12=3, CS12=2, CS11=1, CS10=0}TCCR1B_REG;


typedef enum{CLK_1=1, CLK_8=2, CLK_64=3, CLK_256=4, CLK_1024=5}Prescaler;
typedef enum{I=7 ,T=6, H=5, S=4, V=3, N=2, Z=1, C=0}SREG_REG;

void Timer_Init(uint8 pre, uint8 delay);
void Timer_Delay(void);

#endif