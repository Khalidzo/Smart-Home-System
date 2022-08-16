


#ifndef LCD_H_
#define LCD_H_

/******************************************_INCLUDES_***************************************/
#include "StdTypes.h"
#include <avr/io.h>
#define F_CPU 16000000
#include "util\delay.h"
#include "avr/iom32.h"
/******************************************_MACROS_***************************************/
#define LCD_8_BIT_MODE			0x38
#define LCD_4_BIT_MODE			0x28
#define DISPLAY_ON_CURSOR_OFF	0x0C
#define LCD_CLEAR				0x01
#define LCD_RETURN_HOME			0x02
/****************************************_PROTOTYPES_***************************************/
void LCD_Init(void);
void LCD_WriteChar(u8);
void LCD_WriteCommand(u8);
void LCD_WriteString(u8*);
void LCD_WriteNumber(int);
void LCD_Clear();
void LCD_GoTo(u8,u8);
void LCD_ShiftRight(void);
void LCD_ShiftLeft(void);


#endif /* LCD_H_ */