/*
 * Sensor.h
 *
 *      Author: Eng.Mohamed Ahmed
 */

#ifndef SENSOR_H_
#define SENSOR_H_

// libs includes

#include "State.h"

// define the states
enum{
	PrS_Reading
}PrS_state_id;

// declare state functions for pressure sensor
STATE_define(PrS_Reading);

// State pointer to function
extern void (*PrS_state)();

// APIs
void PrSensor_init();


#endif /* PRSENSOR_H_ */