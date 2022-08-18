

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000
#include "util\delay.h"
#include "avr/iom32.h"
#include "BitMath.h"
#include "StdTypes.h"
#include "LCD.h"
#include "TWI.h"
#include "EEPROM.h"
#include "UserManagement.h"
#include "DCMotor.h"
#include "UART.h"
#include <stdlib.h>

u16 UART_RX_VALUE; //UART Receive value

/************************************************************************
 USER1 NAME: Khaled   USERPASSWORD: 1111
 USER2 NAME: Ahmed    USERPASSWORD: 4206
 USER3 NAME: Kitty    USERPASSWORD: 8012                                                                   
************************************************************************/

int main(void)
{
	
	LCD_Init();
	TWI_Init();
	
	DDRB  &= ~(1<<0);
	DDRC  |= (1<<2);
	
	while(1)
	{	
		
	}
}


//UART ISR
ISR(USART_RXC_vect){
	/*Read the data from buffer*/
	UART_RX_VALUE = UDR;
	if(UART_RX_VALUE == 'A') {
		LCD_Clear();
		LCD_WriteString("HELLO!");
		_delay_ms(1000);
		LCD_Clear();
	}
	/*Clear the interrupt flag*/
	UCSRA|=(1<<RXC);
}