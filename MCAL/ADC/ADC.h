

#ifndef ADC_H_
#define ADC_H_

/******************************************_INCLUDES_***************************************/
#include "ADCCfg.h"
#include <avr/io.h>
#include "StdTypes.h"
#include <avr/interrupt.h>
#include "BitMath.h"
/*******************************************_MACROS_***************************************/
#define AVCC         1
#define AREF_PIN     2
#define _2V56        3
#define ADC_INT      1
#define ADC_POL      2
#define ADC_VALUE    *(volatile u16*)0x24
/******************************************_PROTOTYPES_***************************************/
void ADC_Init(void);
u16  ADC_Read(void);

#endif /* ADC_H_ */