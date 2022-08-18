

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
#include "Buzzer.h"

u16 UART_RX_VALUE; //Store UART Receive value with each reception

/************************************************************************
		Burn usernames and password into the EEPROM
 manageUser("Khaled", "1111", USER1);
 manageUser("Ahmed", "4206", USER2);
 manageUser("Kitty", "8012", USER3);
************************************************************************/

/************************************************************************
 USER1 NAME: Khaled   USERPASSWORD: 1111 (SEND 'A' TO ACCESS THIS USER)
 USER2 NAME: Ahmed    USERPASSWORD: 4206 (SEND 'B' TO ACCESS THIS USER)
 USER3 NAME: Kitty    USERPASSWORD: 8012 (SEND 'C' TO ACCESS THIS USER)                                                                 
************************************************************************/

int main(void)
{
	//Buzzer_Init();
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