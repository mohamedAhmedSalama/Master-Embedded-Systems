/*
 * Algorithem.c
 *
 *      Author: Eng . Mohamed Ahmed
 */
 
#include "Algorithm.h"

//variabls
uint8 pVal = 0;
uint8 threshold = 20;

// state pointer to function
void (*alg_state)();

// connection abstraction
void setPressureVal(uint8 pressure)
{
	pVal = pressure;
	alg_state = STATE(HighPreDetected);
}

STATE_define(HighPreDetected)
{
	alg_state_id = HighPreDetected;
	if(pVal > threshold)
	{
		HighPressure();
		alg_state = STATE(HighPreDetected);
	}
	else
		alg_state = STATE(HighPreDetected);
}