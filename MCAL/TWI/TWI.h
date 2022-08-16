

#ifndef TWI_H_
#define TWI_H_

/******************************************_INCLUDES_****************************************/
#include <avr/io.h>
#include "StdTypes.h"
#include "BitMath.h"
/******************************************_MACROS_*****************************************/
#define F_CPU 16000000
/*****************************************_PROTOTYPES_***************************************/
void TWI_Send_StopBit(void);
u8	TWI_Status(void);
u8 TWI_Read_NAck(u8 *rxData);
u8 TWI_Read_Ack(u8 *rxData);
u8 TWI_Send_Byte(u8 data);
u8 TWI_Send_StartBit(void);
void TWI_Init(void);




#endif /* TWI_H_ */