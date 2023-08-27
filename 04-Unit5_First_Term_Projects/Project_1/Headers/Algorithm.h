/*
 * Algorithm.h
 *
 *      Author: Eng.Mohamed Ahmed
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

// includes
#include "State.h"


enum{
	HighPreDetected
}alg_state_id;

// state Pointer to function
extern void (*alg_state)();

//declare state function for main algorithem
STATE_define(HighPreDetected);

#endif /* ALGORITHM_H_ */