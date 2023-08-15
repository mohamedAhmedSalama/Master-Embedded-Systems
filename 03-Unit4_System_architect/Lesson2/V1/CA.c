/* Author: ENG: Mohamed Ahmed*/

#include"CA.h"

//State pointer is a pointer to function
void (*CA_state) () = 0;

//Variables
int CA_speed = 0 ;
int CA_distance = 0 ;
int CA_threshold = 50 ;

/* State functions */

STATE_DEFINE(CA_Waiting)
{
    CA_State_t = CA_Waiting;
    CA_speed = 0 ;
    CA_distance = US_Get_Distance_Random(45,55);
    (CA_distance <= CA_threshold) ? (CA_state = STATE(CA_Waiting)) : (CA_state = STATE(CA_Driving));
        printf("Waiting state: distance=%d speed=%d \n", CA_distance, CA_speed);

}

STATE_DEFINE(CA_Driving)
{
    CA_State_t = CA_Driving;
	CA_speed = 30;
	CA_distance = US_Get_Distance_Random(45, 55);

	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_Waiting)) : (CA_state = STATE(CA_Driving));
        printf("Driving state: distance=%d speed=%d \n", CA_distance, CA_speed);
}

int US_Get_Distance_Random(int s , int f)
{
    int rand_num = (rand() % (f-s + 1))+1 ;
    return rand_num;
}

