

#include "ADC.h"

u16 x = 0;

void ADC_Init(void){
	#if   VREF   ==   AVCC
	SET_BIT(ADMUX,6);
	CLEAR_BIT(ADMUX,7);
	#elif VREF   ==   AREF_PIN
	CLEAR_BIT(ADMUX,6);
	CLEAR_BIT(ADMUX,7);
	#elif VREF   ==   _2V56
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
	#endif
	CLEAR_BIT(ADMUX,5);     // Select right adjust
	
	//Select channel -> ADC1
	CLEAR_BIT(ADMUX,4);
	CLEAR_BIT(ADMUX,3);
	CLEAR_BIT(ADMUX,2);
	CLEAR_BIT(ADMUX,1);
	SET_BIT(ADMUX,0);
	//Select 128 as devision factor -> ADC circuit -> 125 Khz
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	SET_BIT(ADCSRA,5);   //Enable auto trigger
	#if    ADC_OPERATION_MODE   ==   ADC_INT
	SET_BIT(ADCSRA,3);   //Enable local int
	SET_BIT(SREG,7);     //Enable global int
	SET_BIT(ADCSRA,6);   //Start conversion
	#endif
	SET_BIT(ADCSRA,7);   //Enable ADC circuit
}
#if  ADC_OPERATION_MODE   ==   ADC_POL
u16  ADC_Read(void)
{
	SET_BIT(ADCSRA,6);   // to start conversion
	while ((READ_BIT(ADCSRA,4)) == 0);
	return ADC_VALUE;
}
#elif  ADC_OPERATION_MODE   ==   ADC_INT
ISR(ADC_vect)
{
	x = ADC_VALUE;
}
#endif