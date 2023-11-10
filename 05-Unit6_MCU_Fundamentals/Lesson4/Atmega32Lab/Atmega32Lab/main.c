/*
 * Atmega32Lab.c
 *
 * Created: 11/10/2023 11:28:27 PM
 * Author : Eng. Mohamed Ahmed Salama
 */ 

#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/io.h>

ISR(INT0_vect)
{
	//Turn ON LED0
	PORTD |= (1<<5);
	
	//1 Second delay
	_delay_ms(1000);
}

ISR(INT1_vect)
{
	//Turn ON LED1
	PORTD |= (1<<6);
	
	//1 Second delay
	_delay_ms(1000);
}

ISR(INT2_vect)
{
	//Turn ON LED0
	PORTD |= (1<<7);
	
	//1 Second delay
	_delay_ms(1000);
}

void INT_init(void){
	
	// enable SREG [global interrupt enable]
	sei();
	
	//External Interrupt request enable [INT0,INT1,INT2]
	GICR |= (0b111 << 5);
	
	//INT0 Trigger setting (Any Logical Change)
	MCUCR |= 1 << 0;
	//INT1 Trigger setting (Rising Edge)
	MCUCR |= (0b11 << 2);
	//INT2 Trigger setting (Falling Edge)
	MCUCSR &= ~(1 << 6);
	
}

void DIO_init(void){
	
	//Port B Pin 2 INPUT
	DDRB &= ~(1<<2);
	//Port D Pins 2,3 INPUT
	DDRD &= ~(0b11<<2);
	//Port D Pins 5,6,7 OUTPUT
	DDRD |= (0b111<<5);
	
}


int main(void)
{
	
	INT_init();
	DIO_init();
	
	while (1)
	{
		//Turn OFF LEDs
		PORTD &= ~(0b111<<5);
	}
}
