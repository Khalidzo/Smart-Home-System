

#include "LCD.h"

void LCD_Init(void) {
	
	DDRA |= 0xF0; //PA4 -> PA7
	DDRB |= 0x0E; //PB1 -> PB3
	PORTB &= ~(1<<2); //RW LOW
	_delay_ms(250);
	
	LCD_WriteCommand(0x33);
	LCD_WriteCommand(0x32);
	LCD_WriteCommand(0x28);
	
	LCD_WriteCommand(LCD_4_BIT_MODE);
	LCD_WriteCommand(DISPLAY_ON_CURSOR_OFF);
	LCD_WriteCommand(LCD_CLEAR);
	LCD_WriteCommand(LCD_RETURN_HOME);
}

void LCD_WriteChar(u8 Char) {
	
	PORTB |= 1<<1; //RS HIGH
	PORTA = (Char & 0xF0) | (PORTA & 0x0F);
	PORTB |= 1<<3; //ENABLE HIGH
	_delay_ms(2);
	PORTB &= ~(1<<3); //ENABLE LOW
	_delay_ms(5);
	PORTA = (Char << 4) | (PORTA & 0x0F);
	PORTB |= 1<<3; //ENABLE HIGH
	_delay_ms(2);
	PORTB &= ~(1<<3); //ENABLE LOW
	_delay_ms(5);
	
}
void LCD_WriteCommand(u8 Command) {
	
	PORTB &= ~(1<<1); //RS LOW
	PORTA = (Command & 0xF0) | (PORTA & 0x0F);
	PORTB |= 1<<3; //ENABLE HIGH
	_delay_ms(2);
	PORTB &= ~(1<<3); //ENABLE LOW
	_delay_ms(5);
	PORTA = (Command << 4) | (PORTA & 0x0F);
	PORTB |= 1<<3; //ENABLE HIGH
	_delay_ms(2);
	PORTB &= ~(1<<3); //ENABLE LOW
	_delay_ms(5);
}
void LCD_WriteString(u8* String) {
	while(*String != '\0') {
		LCD_WriteChar(*String);
		String++;
	}
};

void LCD_WriteNumber(int number) {
	int length = 0;
	int arr[10];
	if(number >= 0) {
		do{
			arr[length++] = number%10;
			number = number/10;

		} while(number != 0);
		_delay_ms(5);
		
		int i = length-1;
		for(int i = length-1; i >= 0; i--){
			LCD_WriteChar(arr[i] + '0');
			_delay_ms(1);
		}
	}
	else if(number < 0) {
		LCD_WriteChar('-');
		number = number * -1;
		do{
			arr[length++] = number%10;
			number = number/10;

		} while(number != 0);
		_delay_ms(5);
		
		int i = length-1;
		for(int i = length-1; i >= 0; i--){
			LCD_WriteChar(arr[i] + '0');
			_delay_ms(1);
		}
	}
}
void LCD_Clear(){
	LCD_WriteCommand(0x01);
}

void LCD_GoTo(u8 Row,u8 Column) {
	u8 Arr[2] = {0x80, 0xC0};
	LCD_WriteCommand(Arr[Row] + Column);
}

void LCD_ShiftRight(void) {
	LCD_WriteCommand(0x05);
}
void LCD_ShiftLeft(void) {
	LCD_WriteCommand(0x07);
}