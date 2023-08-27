/*
 * main.c
 *
 *      Author: Eng. Mohamed Ahmed
 */

#include "driver.h"
#include "Alarm_Monitor.h"
#include "Alarm_Actuator.h"
#include "Algorithm.h"
#include "Sensor.h"
#include "State.h"

void setup()
{
	//init all drivers
	GPIO_INITIALIZATION();
	//init block
	PrSensor_init();
	alg_state = STATE(HighPreDetected);
	AM_state = STATE(AlarmOff);
	Alarm_init();
}
void main()
{
	setup();
	while(1)
	{
		PrS_state();
		alg_state();
		AM_state();
		Led_state();
	}
}