

#ifndef EEPROM_H_
#define EEPROM_H_

/******************************************_INCLUDES_***************************************/
#include "StdTypes.h"
#include "BitMath.h"
/******************************************_PROTOTYPES_***************************************/
u8 EEPROM_ReadByte(u8 DeviceAddress, u8 WordAddress);
void EEPROM_WriteByte(u8 DeviceAddress, u8 WordAddress, u8 data);

#endif /* EEPROM_H_ */