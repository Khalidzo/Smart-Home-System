

#ifndef SERVOMOTOR_H_
#define SERVOMOTOR_H_

/******************************************_INCLUDES_***************************************/
#include "BitMath.h"
#include <avr/io.h>
#include "StdTypes.h"
#define F_CPU 16000000
#include "util\delay.h"

typedef enum {
	Angle_0 = 5,
	Angle_C90 = 7,
	Angle_AC90 = 10
} Servo_Angle;
/******************************************_PROTOTYPES_***************************************/
void ServoMotor_Rotate(u8 angle);
void ServoMotor_Init(void);
void ServoMotor_OpenDoor(void);

#endif /* SERVOMOTOR_H_ */