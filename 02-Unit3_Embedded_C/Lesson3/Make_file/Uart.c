// Mohamed ahmed Salama

#include "Uart.h"

//uart registers
#define UART0DR	*((volatile unsigned int* const)((unsigned int*)0X101F1000))


void UART_SendString(unsigned char *p_tx_string)
{
	while(*p_tx_string != '\0')
	{
		UART0DR = (unsigned int)(*p_tx_string);
		p_tx_string++;
	}
}