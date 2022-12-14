
#include "TempSensor.h"

void TempSensor_Init(void){
	ADC_Init();
}

u16  TempSensor_Read(void){
	u16 ADCValue  = ADC_Read();
	u16 Temperature = ((u32)ADCValue * 500) / 1023;
	if(Temperature > 35){
		DCMotor_Start();
		Buzzer_Beep();
	}
	else {
		DCMotor_Stop();
	}
	return Temperature;
}
