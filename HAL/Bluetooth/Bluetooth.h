




#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

/******************************************_INCLUDES_***************************************/
#include "UART.h"
#include <util/delay.h>
/*****************************************_MACROS_***************************************/
#define F_CPU 16000000
/****************************************_PROTOTYPES_**************************************/
u8 Bluetooth_Receive(void);
void Blutooth_SendString(char* string);
void Bluetooth_SendByte(u8 data);
void Bluetooth_Init(void);


#endif /* BLUETOOTH_H_ */