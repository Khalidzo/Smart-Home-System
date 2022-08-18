

#ifndef HOMEDISPLAY_H_
#define HOMEDISPLAY_H_

/*******************************************_INCLUDES_***************************************/
#define F_CPU 16000000
#include "util\delay.h"
#include <avr/io.h>
/*******************************************_PROTOTYPES_***************************************/
void sendWelcomeMessage(void);
void displayTemperature(void);

#endif /* HOMEDISPLAY_H_ */