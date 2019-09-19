#ifndef ICU_H_
#define ICU_H_

#include "DIO.h"
#include "Timer.h"
	
	
typedef enum{falling=0,rising=1}edge_state;

void ICU_Init(uint8 edge_select, uint8 pre);
uint16 ICU_Time(void);



#endif