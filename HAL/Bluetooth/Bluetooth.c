

#include "Bluetooth.h"

void Bluetooth_Init(void) {
	UART_Init();
}

void Bluetooth_SendByte(u8 data) {
	UART_Transmit(data);
}

void Blutooth_SendString(char* string) {
	while(*string != '\0') {
		UART_Transmit(*string);
		string++;
		_delay_ms(20);
	}
}
u8 Bluetooth_Receive(void) {
	while(READ_BIT(UCSRA,7) == 0);
	return UDR;
}