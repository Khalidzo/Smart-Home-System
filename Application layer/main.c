

#include <avr/io.h>
#define F_CPU 16000000
#include "util\delay.h"
#include "avr/iom32.h"
#include "BitMath.h"
#include "StdTypes.h"
#include "LCD.h"
#include "TWI.h"

int main(void)
{
	LCD_Init();
	LCD_WriteString("Welcome to");
	LCD_GoTo(1,0);
	LCD_WriteString("Smart Home!");
	
    while (1) 
    {
		
    }
	
}

