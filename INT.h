#ifndef INT_H_
#define INT_H_

#include "DIO.h"

#define MCUCR 			(*((volatile uint8 *)0x55))
#define MCUCSR 			(*((volatile uint8 *)0x54))
#define GICR 			(*((volatile uint8 *)0x5B))
#define GIFR 			(*((volatile uint8 *)0x5A))
#define SREG 			(*((volatile uint8 *)0x5F))


//#define INTR0
//#define INTR1
#define INTR2


enum{SE=7, SM2=6, SM1=5, SM0=4,ISC11=3 ,ISC10=2 ,ISC01=1 ,ISC00=0}MCUCR_REG;
enum{JTD=7, ISC2=6, JTRF=4, WDRF=3, BORF=2, EXTRF=1, PORF=0}MCUCSR_REG;
enum{INT1=7, INT0=6, INT2=5, IVSEL=1, IVCE=0}GICR_REG;
enum{INTF1=7, INTF0=6, INTF2=5}GIFR_REG;
enum{I=7 ,T=6, H=5, S=4, V=3, N=2, Z=1, C=0}SREG_REG;
enum{LowL=0,HighL=1,Fedge=2,Redge=3}Sense_CTL;


void INT_Init(uint8 level);






#endif