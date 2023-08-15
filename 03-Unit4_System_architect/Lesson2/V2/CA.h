/* Author: ENG: Mohamed Ahmed*/

#ifndef CA_H_
#define CA_H_

#include "State.h"

//Define states
enum {
    CA_waiting , CA_driving
}CA_state_id;


//declare state functions for CA
STATE_define(CA_waiting);
STATE_define(CA_driving);


//State pointer is a pointer to function
extern void (*CA_state) ();



#endif // CA_H_
