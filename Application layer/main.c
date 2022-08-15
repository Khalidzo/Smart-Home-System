

#include <avr/io.h>
#define F_CPU 16000000
#include "util\delay.h"
#include "avr/iom32.h"
#include "BitMath.h"
#include "StdTypes.h"
#include "LCD.h"
#include "TWI.h"
#include "EEPROM.h"
#include "UserManagement.h"
#include <stdlib.h>

int main(void)
{
	
	LCD_Init();
	TWI_Init();
	
	/*_delay_ms(50);
	EEPROM_WriteByte(0b10100000,0b11111111,'B');
	_delay_ms(50);
	LCD_WriteChar(EEPROM_ReadByte(0b10100000,0b11111111));*/
	
	/*manageUser("Khaled", "1111", USER1);
	_delay_ms(50);
	manageUser("Ahmed", "4206", USER2);
	_delay_ms(50);
	manageUser("Kitty", "8012", USER3);
	EEPROM_WriteByte(0b10100000,0b11111111,'B');
	_delay_ms(50);
	LCD_WriteChar(EEPROM_ReadByte(0b10100000,0b11111111));*/
	DDRB  &= ~(1<<0);
	DDRC  |= (1<<2);
	
	
	while(1)
	{	
		if(READ_BIT(PINB, 0) == 1) {
			LCD_WriteString("Welcome ");
			LCD_WriteString(getName(USER1));
			LCD_GoTo(1,0);
			LCD_WriteString("Password: ");
			LCD_WriteString(getPassword(USER1));
			PORTC |= (1<<2);
			_delay_ms(2500);
			LCD_Clear();
			PORTC &= ~(1<<2);
		}
		else if(READ_BIT(PIND, 6) == 1) {
			LCD_WriteString("Welcome ");
			LCD_WriteString(getName(USER2));
			LCD_GoTo(1,0);
			LCD_WriteString("Password: ");
			LCD_WriteString(getPassword(USER2));
			PORTC |= (1<<2);
			_delay_ms(2500);
			LCD_Clear();
			PORTC &= ~(1<<2);
		}
		else if(READ_BIT(PIND, 2) == 1) {
			LCD_WriteString("Welcome ");
			LCD_WriteString(getName(USER3));
			LCD_GoTo(1,0);
			LCD_WriteString("Password: ");
			LCD_WriteString(getPassword(USER3));
			PORTC |= (1<<2);
			_delay_ms(2500);
			LCD_Clear();
			PORTC &= ~(1<<2);
		}
	}
}
