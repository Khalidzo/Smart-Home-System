


#ifndef BUZZER_H_
#define BUZZER_H_

/*******************************************_INCLUDES_***************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "util\delay.h"
#include "LCD.h"
#include "BitMath.h"
/*******************************************_MACROS_***************************************/
#define F_CPU 16000000
#define BUZZER_DIR			DDRA
#define BUZZER_PORT			PORTA
#define BUZZER_PIN			3
/*****************************************_PROTOTYPES_***************************************/
void Buzzer_Init(void);
void Buzzer_Beep(void);
void Buzzer_SetAlarm(void);

#endif /* BUZZER_H_ */