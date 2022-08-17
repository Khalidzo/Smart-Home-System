

#include "UART.h"

void UART_Init(void) {
	u16 UBRR;
	UBRR  = (F_CPU/(16*BAUD_RATE)) - 1; //Set Baudrate 
	UBRRH = (u16)(UBRR>>8);
	UBRRL = (u16)(UBRR);
	//Enable Receive and Transmit interrupts
	SET_BIT(UCSRB,RXCIE);
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	//Choose Asynchronous Mode, 8 Bit data, and 1 Stop bit
	SET_BIT(UCSRC,URSEL);
	SET_BIT(UCSRC,UCSZ1);
	SET_BIT(UCSRC,UCSZ0);
	sei(); //Enable global interrupts
}

void UART_Transmit(u8 Data) {
	while(!(UCSRA&(1<<UDRE))); //Wait until buffer is empty
	UDR = Data; //Send data
}
