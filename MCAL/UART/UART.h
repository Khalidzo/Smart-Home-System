

#ifndef UART_H_
#define UART_H_

#include "UARTCfg.h"
#include "BitMath.h"
#include "StdTypes.h"
#include <avr/io.h>

#define PARITY_DISABLE            1
#define PARITY_ODD                2
#define PARITY_EVEN               3

void UART_Init(void);
void UART_Transmit(u8);
u8   UART_Receive(void);


#endif /* UART_H_ */