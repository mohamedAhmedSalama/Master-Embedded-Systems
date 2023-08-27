/*
 * Alarm_Monitor.h
 *
 *      Author: Eng.Mohamed Ahmed
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "State.h"

enum{
	AlarmOff,
	AlarmOn
}AM_state_id;

// state pointer to function
extern void (*AM_state)();

// state function for alarm monitor
STATE_define(AlarmOn);
STATE_define(AlarmOff);

#endif /* ALARM_MONITOR_H_ */