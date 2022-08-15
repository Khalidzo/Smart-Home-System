

#ifndef TWI_H_
#define TWI_H_


#include <avr/io.h>
#define F_CPU 16000000
#include "StdTypes.h"
#include "BitMath.h"


void TWI_Send_StopBit(void);
u8	TWI_Status(void);
u8 TWI_Read_NAck(u8 *rxData);
u8 TWI_Read_Ack(u8 *rxData);
u8 TWI_Send_Byte(u8 data);
u8 TWI_Send_StartBit(void);
void TWI_Init(void);




#endif /* TWI_H_ */