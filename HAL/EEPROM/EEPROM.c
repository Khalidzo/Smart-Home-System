

#include "EEPROM.h"

void EEPROM_WriteByte(u8 DeviceAddress, u8 WordAddress, u8 data) {
	DeviceAddress = DeviceAddress & 0xFE;
	if(TWI_Send_StartBit() == 0x08){
		if(TWI_Send_Byte(DeviceAddress) == 0x18) {
			if(TWI_Send_Byte(WordAddress) == 0x28) {
				if(TWI_Send_Byte(data) == 0x28) {
					TWI_Send_StopBit();
				}
			}
		}
	}
}

u8 EEPROM_ReadByte(u8 DeviceAddress, u8 WordAddress){
	u8 wDeviceAdd = DeviceAddress & 0xFE;
	u8 rDeviceAdd = DeviceAddress | (1<<0);
	u8 rxData = 0;
	if(TWI_Send_StartBit() == 0x08){
		if(TWI_Send_Byte(wDeviceAdd) == 0x18){
			if(TWI_Send_Byte(WordAddress) == 0x28){
				if(TWI_Send_StartBit() == 0x10){
					if(TWI_Send_Byte(rDeviceAdd) == 0x40) {
						if(TWI_Read_NAck(&rxData) == 0x58){
							TWI_Send_StopBit();
						}
					}
				}
			}
		}
	}
	return rxData;
}