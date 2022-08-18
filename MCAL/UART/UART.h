

#ifndef UART_H_
#define UART_H_
/******************************************_INCLUDES_***************************************/
#include "UARTCfg.h"
#include "BitMath.h"
#include "StdTypes.h"
#include <avr/io.h>
#include "util\delay.h"
#include <avr/interrupt.h>
/******************************************_MACROS_***************************************/
#define PARITY_DISABLE            1
#define PARITY_ODD                2
#define PARITY_EVEN               3
#define F_CPU 16000000
/******************************************_PROTOTYPES_***************************************/
void UART_Transmit(u8 Data);
void UART_Init(void);


#endif /* UART_H_ */