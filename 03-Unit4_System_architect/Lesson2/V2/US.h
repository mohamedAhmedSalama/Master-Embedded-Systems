/* Author: ENG: Mohamed Ahmed*/
#ifndef US_H_
#define US_H_

#include "State.h"

//Define states
enum {
   US_busy
}US_state_id;


//declare state functions for CA
STATE_define(US_busy);

void US_init();
//State pointer is a pointer to function
extern void (*US_state) ();

#endif // US_H_
