

#ifndef USERMANAGEMENT_H_
#define USERMANAGEMENT_H_

/*******************************************_INCLUDES_***************************************/
#include "EEPROM.h"
#include "StdTypes.h"
#include "util\delay.h"
#include <stdlib.h>
#include <avr/io.h>
#include "string.h"
#include "ServoMotor.h"
#include "Buzzer.h"
#include "Bluetooth.h"
/*******************************************_MACROS_***************************************/
#define USER1 1
#define USER2 2
#define USER3 3
/****************************************_USER_STRUCT_***************************************/
struct user {
	u8 name[8];		//Name is 8 char long
	u8 password[4]; //Password is 4 digits
};
/****************************************_PROTOTYPES_***************************************/
void manageUser(u8* userName, u8* userPassword, u8 userNumber);
void storeName(u8* name, u8* memoryAddress);
u8* getName(u8 userNumber);
void storePassword(u8* Password, u8* memoryAddress);
u8* getPassword(u8 userNumber);
void enterPassword(u8 userNumber);
void setAlarm(void);
u8* receivePassword(void);


#endif /* USERMANAGEMENT_H_ */