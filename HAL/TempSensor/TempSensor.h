

#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_

/******************************************_INCLUDES_***************************************/
#include "ADC.h"
#include "Buzzer.h"
#include "DCMotor.h"
/*****************************************_PROTOTYPES_***************************************/
void TempSensor_Init(void);
u16  TempSensor_Read(void);

#endif /* TEMPSENSOR_H_ */