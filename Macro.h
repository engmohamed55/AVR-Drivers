#ifndef MACROS_H_
#define MACROS_H_

#include "Types.h"

#define Set_Bit(PORT,PIN) ((PORT) |= (1<<(PIN)))
#define Clear_Bit(PORT,PIN) ((PORT) &= (~(1<<(PIN))))
#define Get_Bit(PORT,PIN) ((PORT) & (1<<PIN))
#define Toggle_Bit(PORT,PIN) ((PORT) ^= (1<<(PIN))


#endif