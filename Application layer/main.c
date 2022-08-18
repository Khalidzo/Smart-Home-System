
#include <stdio.h>
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
#include "HomeDisplay.h"

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
	/********************_Initializations_*****************/
	Buzzer_Init();
	LCD_Init();
	TWI_Init();
	UART_Init();
	DCMotor_Init();
	ServoMotor_Init();
	TempSensor_Init();
	
	
	while(1)
	{	
		sendWelcomeMessage();
		displayTemperature();
		_delay_ms(500);
	}
}


//UART ISR
ISR(USART_RXC_vect){
	/*Read the data from buffer*/
	UART_RX_VALUE = UDR;
	
	switch(UART_RX_VALUE) {
		case 'A':
		//THIS IS USER1 LOGIN
		enterPassword(USER1);
		break;
		case 'B':
		//THIS IS USER2 LOGIN
		enterPassword(USER2);
		break;
		case 'C':
		//THIS IS USER3 LOGIN
		enterPassword(USER3);
		break;
		default: break;
	}
	/*Clear the interrupt flag*/
	UCSRA|=(1<<RXC);
}