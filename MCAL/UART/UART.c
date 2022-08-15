

#include "UART.h"

void UART_Init(void) {
	CLEAR_BIT(DDRD,0);      // to enable input  circuit for Rx Pin
	SET_BIT(DDRD,1);      // to enable output circuit for Tx Pin
	u8  u8_UCSRC  = 0b10000000;
	u16 Local_u16_UBRRH = 0b00000000;
	// to select character size = 8 bits
	SET_BIT(u8_UCSRC,1);
	SET_BIT(u8_UCSRC,2);
	CLEAR_BIT(UCSRB,2);
	// to select Asynch. mode
	CLEAR_BIT(u8_UCSRC,6);
	#if   PARITY_MODE   ==    PARITY_DISABLE
	CLEAR_BIT(u8_UCSRC,4);
	CLEAR_BIT(u8_UCSRC,5);
	#elif PARITY_MODE   ==    PARITY_ODD
	SET_BIT(u8_UCSRC,4);
	SET_BIT(u8_UCSRC,5);
	#elif PARITY_MODE   ==    PARITY_EVEN
	CLEAR_BIT(u8_UCSRC,4);
	SET_BIT(u8_UCSRC,5);
	#endif
	CLEAR_BIT(u8_UCSRC,3);          // to select stop bit -> 1 bit
	UCSRC = u8_UCSRC;
	UBRRL = ((u32)F_OSC * 1000000 / ((u32)16 * BAUD_RATE)) - 1;
	Local_u16_UBRRH = (((u32)F_OSC * 1000000 / ((u32)16 * BAUD_RATE)) - 1) >> 8;
	UBRRH = Local_u16_UBRRH;
	SET_BIT(UCSRB,4);                  // to enable Rx. circuit
	SET_BIT(UCSRB,3);                  // to enable Tx. circuit
}

void UART_Transmit(u8 Local_u8_Data) {
	UDR = Local_u8_Data;
	while(READ_BIT(UCSRA,6) == 0);
}
u8   UART_Receive(void) {
	while(READ_BIT(UCSRA,7) == 0);
	return UDR;
}