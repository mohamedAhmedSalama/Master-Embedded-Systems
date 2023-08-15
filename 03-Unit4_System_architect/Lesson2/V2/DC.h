/* Author: ENG: Mohamed Ahmed*/

#ifndef DC_H_
#define DC_H_

#include"State.h"

//Define states
enum {
    DC_idle , DC_busy
}DC_state_id;


//declare state functions for CA
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();
void DC_motor(int s);
//State pointer is a pointer to function
extern void (*DC_state) ();


#endif // DC_H_
