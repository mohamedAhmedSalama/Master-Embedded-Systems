/* Author: ENG: Mohamed Ahmed*/

#ifndef CA_H_
#define CA_H_

#include "State.h"

/* states */
enum{
    CA_Waiting,
    CA_Driving
}CA_State_t;

/* State functions */
STATE_DEFINE(CA_Waiting);
STATE_DEFINE(CA_Driving);

extern void (*CA_state)();

int US_Get_Distance_Random(int s , int f);



#endif // CA_H_
