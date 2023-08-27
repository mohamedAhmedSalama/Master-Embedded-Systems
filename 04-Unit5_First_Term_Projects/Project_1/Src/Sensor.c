/*
 * Sensor.c
 * 
 *  	Author: Eng. Mohamed Ahmed
 */
 
#include "Sensor.h"
#include "driver.h"

// variables
uint8 pressure = 0;

// State pointer to function
void (*PrS_state)();

// Flow of the program

void PrSensor_init()
{
	// initialize of the pressure sensor will be called from driver.h
	PrS_state = STATE(PrS_Reading);
}

STATE_define(PrS_Reading)
{
	PrS_state_id = PrS_Reading;
	pressure = getPressureVal();
	setPressureVal(pressure);
	PrS_state = STATE(PrS_Reading);
}

