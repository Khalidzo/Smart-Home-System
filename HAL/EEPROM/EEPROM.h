

#ifndef EEPROM_H_
#define EEPROM_H_

#include "StdTypes.h"
#include "BitMath.h"

u8 EEPROM_ReadByte(u8 DeviceAddress, u8 WordAddress);
void EEPROM_WriteByte(u8 DeviceAddress, u8 WordAddress, u8 data);

#endif /* EEPROM_H_ */