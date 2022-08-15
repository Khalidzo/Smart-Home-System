

#include "TWI.h"

u8	TWI_Status(void);

void TWI_Init(void){
	/*****_MASTER_MODE_*****/
	TWBR = 12; //FSCL = 400 KHz
}
u8 TWI_Send_StartBit(void){
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(TWCR & (1<<TWINT))); //Wait for TWINT to set
	return TWI_Status();
}

u8 TWI_Send_Byte(u8 data){
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN); //Clear the interrupt flag and set enable
	while(!(TWCR & (1<<TWINT))); //Wait for TWINT to set
	return TWI_Status();
}
u8 TWI_Read_Ack(u8 *rxData){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA); //Clear the interrupt flag, set enable, and send Ack Bit
	while(!(TWCR & (1<<TWINT))); //Wait for TWINT to set
	*rxData = TWDR;
	return TWI_Status();
}
u8 TWI_Read_NAck(u8 *rxData){
	TWCR = (1<<TWINT)|(1<<TWEN); //Clear the interrupt flag, set enable, and ignore Ack Bit
	while(!(TWCR & (1<<TWINT))); //Wait for TWINT to set
	*rxData = TWDR;
	return TWI_Status();
}
void TWI_Send_StopBit(void){
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO); //Send the stop bit
}

u8	TWI_Status(void) {
	return (TWSR & 0xF8); //Return value of the status register
}