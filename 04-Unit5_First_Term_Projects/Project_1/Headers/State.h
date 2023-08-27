/*
 * state.h
 *
 *      Author: Eng.Mohamed Ahmed
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"
#include "Platform_Types.h"

// Automatic state function generator
#define STATE_define(_stFun_) void ST_##_stFun_()
#define STATE(_stFun_) ST_##_stFun_

// state connections
void setPressureVal(uint8 pressure);
void HighPressure();
void StartAlarm();
void StopAlarm();

#endif /* STATE_H_ */