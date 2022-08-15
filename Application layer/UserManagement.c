
#include "UserManagement.h"
//Button 0 will log into user 1
//Button 1 will log into user 2
//Button 2 will log into user 3


u8 userNameAddressSpace[4]     = {0x00, 0x08, 0x10}; //3 memory locations (8 bytes each) to store 3 different usernames
u8 userPasswordAddressSpace[4] = {0x23, 0x27, 0x2C}; //3 memory locations (4 bytes each) to store 3 different passwords
struct user user1;
struct user user2;
struct user user3;
struct user users[] = {0};

void manageUser(u8* userName, u8* userPassword, u8 userNumber) {
	switch(userNumber){
		case 1:
		strcpy(user1.name, userName);
		strcpy(user1.password, userPassword);
		storeName(user1.name, userNameAddressSpace[userNumber-1]);
		storePassword(userPassword, userPasswordAddressSpace[userNumber-1]);
		break;
		case 2:
		strcpy(user2.name, userName);
		strcpy(user2.password, userPassword);
		storeName(user2.name, userNameAddressSpace[userNumber-1]);
		storePassword(userPassword, userPasswordAddressSpace[userNumber-1]);
		break;
		case 3:
		strcpy(user3.name, userName);
		strcpy(user3.password, userPassword);
		storeName(user3.name, userNameAddressSpace[userNumber-1]);
		storePassword(userPassword, userPasswordAddressSpace[userNumber-1]);
		break;
		default:
		break;
	}
}

void storeName(u8* name, u8* memoryAddress) {
	//Starting address space 0x00
	u8 deviceAddress = 0xA0;
	while(*name != '\0') {
		EEPROM_WriteByte(deviceAddress,memoryAddress, *name);
		name++;
		memoryAddress++;
		_delay_ms(50);
	}
	_delay_ms(50);
	EEPROM_WriteByte(deviceAddress,memoryAddress, '\0'); //Terminate string
	_delay_ms(50);
}

u8* getName(u8 userNumber) {
	u8 memoryAddress = userNameAddressSpace[userNumber-1];
	u8 deviceAddress = 0xA0;
	u8* tmp  = (char*)(malloc(sizeof(char) * 8));
	u8* name = tmp;
	int i=0;
	while(EEPROM_ReadByte(deviceAddress,memoryAddress) != '\0') {
		tmp[i] = EEPROM_ReadByte(deviceAddress,memoryAddress);
		_delay_ms(50);
		memoryAddress++;
		i++;
		_delay_ms(50);
	}
	tmp[i] = '\0';
	return name;
}

void storePassword(u8* Password, u8* memoryAddress) {
	//Starting address space 0x00
	u8 deviceAddress = 0xA0;
	while(*Password != '\0') {
		EEPROM_WriteByte(deviceAddress,memoryAddress, *Password);
		Password++;
		memoryAddress++;
		_delay_ms(50);
	}
	_delay_ms(50);
	EEPROM_WriteByte(deviceAddress,memoryAddress, '\0'); //Terminate string
	_delay_ms(50);
}

u8* getPassword(u8 userNumber) {
	u8 memoryAddress = userPasswordAddressSpace[userNumber-1];
	u8 deviceAddress = 0xA0;
	u8* tmp  = (char*)(malloc(sizeof(char) * 8));
	u8* password = tmp;
	int i=0;
	while(EEPROM_ReadByte(deviceAddress,memoryAddress) != '\0') {
		tmp[i] = EEPROM_ReadByte(deviceAddress,memoryAddress);
		_delay_ms(50);
		memoryAddress++;
		i++;
		_delay_ms(50);
		if(i == 4) break;
	}
	tmp[i] = '\0';
	return password;
}