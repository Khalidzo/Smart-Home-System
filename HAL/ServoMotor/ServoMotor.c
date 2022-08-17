
#include "ServoMotor.h"

void ServoMotor_Init(void) {
	//Set OC1A pin as output
	SET_BIT(DDRD, PD5);
	//Set Mode 14 (Fast PWM) Mode
	SET_BIT(TCCR1B, WGM13);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1A, WGM11);
	CLEAR_BIT(TCCR1A, WGM10);
	//Choose non-inverting mode
	SET_BIT(TCCR1A, COM1A1);
	CLEAR_BIT(TCCR1A, COM1A0);
	//Set prescaler = 256
	SET_BIT(TCCR1B, CS12);
	CLEAR_BIT(TCCR1B, CS11);
	CLEAR_BIT(TCCR1B, CS10);
	//Set Top Value
	ICR1 = 1250; //This would give a 50Hz frequency (20ms period)
}

void ServoMotor_Rotate(u8 angle) {
	OCR1A = ((ICR1*angle) / 100) - 1;
}

void ServoMotor_OpenDoor(void) {
	ServoMotor_Rotate(Angle_AC90);
	_delay_ms(3000); //Wait for user to enter
	ServoMotor_Rotate(Angle_0);
}