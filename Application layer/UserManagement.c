
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

void enterPassword(u8 userNumber) {
	LCD_WriteString("Welcome ");
	LCD_WriteString(getName(userNumber));
	_delay_ms(1500);
	LCD_Clear();
	u8 nTrials = 0;
	u8* password = getPassword(userNumber);
	u8* currentPassword = receivePassword();
	u8 counter = 0;
	while(strcmp(getPassword(userNumber), currentPassword) != 0) {
		LCD_Clear();
		LCD_WriteString("Wrong Password");
		_delay_ms(1500);
		LCD_Clear();
		LCD_WriteString("Try again!");
		_delay_ms(1000);
		LCD_Clear();
		currentPassword = receivePassword();
		nTrials++;
		if(nTrials >= 0) {
			setAlarm();
			break;
		}
	}
	if(nTrials < 3) {
		LCD_Clear();
		LCD_WriteString("Welcome home!");
		ServoMotor_OpenDoor();
		_delay_ms(1500);
		LCD_Clear();
	}
}

void setAlarm(void) {
	LCD_Clear();
	_delay_ms(2000);
	LCD_WriteString("Login Failure");
	_delay_ms(2000);
	LCD_Clear();
	LCD_WriteString("System Alarm ON!");
	_delay_ms(1500);
	LCD_Clear();
	PORTA |= 1<<3;
	_delay_ms(1000);
	PORTA &= ~(1<<3);
	_delay_ms(500);
	PORTA |= 1<<3;
	_delay_ms(1000);
	PORTA &= ~(1<<3);
	_delay_ms(500);
	PORTA |= 1<<3;
	_delay_ms(1000);
	PORTA &= ~(1<<3);
	_delay_ms(500);
}

u8* receivePassword(void) {
	u8 counter = 0;
	u8* tmpPassowrd  = (char*)(malloc(sizeof(char) * 5));
	u8* password = tmpPassowrd;
	u8 rChar;
	LCD_WriteString("Enter password:");
	while(counter != 4) {
		
		rChar = Bluetooth_Receive();
		_delay_ms(25);
		if(rChar >= 48 && rChar <= 57) {
			_delay_ms(25);
			*tmpPassowrd = rChar;
			LCD_GoTo(1,counter);
			LCD_WriteChar('*');
			tmpPassowrd++;
			counter++;
		}
	}
	*tmpPassowrd = '\0';
	return password;
}