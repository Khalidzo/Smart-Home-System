

#include "Buzzer.h"

void Buzzer_Init(void){
	SET_BIT(BUZZER_DIR,BUZZER_PIN);
}
void Buzzer_Beep(void){
	SET_BIT(BUZZER_PORT,BUZZER_PIN);
	_delay_ms(500);
	CLEAR_BIT(BUZZER_PORT,BUZZER_PIN);
}
void Buzzer_SetAlarm(void){
	LCD_Clear();
	_delay_ms(2000);
	LCD_WriteString("Login Failure");
	_delay_ms(2000);
	LCD_Clear();
	LCD_WriteString("System Alarm ON!");
	_delay_ms(1500);
	LCD_Clear();
	
	SET_BIT(BUZZER_PORT,BUZZER_PIN);
	_delay_ms(1000);
	CLEAR_BIT(BUZZER_PORT,BUZZER_PIN);
	_delay_ms(500);
	
	SET_BIT(BUZZER_PORT,BUZZER_PIN);
	_delay_ms(1000);
	CLEAR_BIT(BUZZER_PORT,BUZZER_PIN);
	_delay_ms(500);
	
	SET_BIT(BUZZER_PORT,BUZZER_PIN);
	_delay_ms(1000);
	CLEAR_BIT(BUZZER_PORT,BUZZER_PIN);
	_delay_ms(500);
}
