// Mohamed ahmed Salama
#include "Uart.h"
unsigned char string_buffer[100]= "learn-in-depth: <Mohamed>";
const unsigned char string_buffer2[100]= "Create Rodata section";
void main(void)
{
	UART_SendString(string_buffer);
}