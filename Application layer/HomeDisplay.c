
#define F_CPU 16000000
#include "util\delay.h"
#include <avr/io.h>
#include "HomeDisplay.h"

void sendWelcomeMessage(void) {
	_delay_ms(30);
	LCD_GoTo(0,0);
	LCD_WriteString("2022/08/18");
}

void displayTemperature(void) {
	_delay_ms(30);
	LCD_GoTo(1,0);
	LCD_WriteString("Temperature ");
	LCD_WriteNumber(TempSensor_Read());
	LCD_WriteChar('C');
}