


#ifndef DCMOTOR_H_
#define DCMOTOR_H_

/******************************************_INCLUDES_***************************************/
#include <avr/io.h>
#include "avr/iom32.h"
#include "StdTypes.h"
#include "Bitmath.h"
/*******************************************_MACROS_***************************************/
#define DC_MOTOR_CONTROL_PORT_D	    DDRD
#define DC_MOTOR_DIRECTION_PORT_D   DDRC
#define DC_MOTOR_CONTROL_PORT_C	    PORTD
#define DC_MOTOR_DIRECTION_PORT_C   PORTC
#define ENABLE_PIN				  4
#define DIRECTION_PIN			  3
/******************************************_PROTOTYPES_***************************************/
void DCMotor_Init(void);
void DCMotor_Start(void);
void DCMotor_Stop(void);

#endif /* DCMOTOR_H_ */