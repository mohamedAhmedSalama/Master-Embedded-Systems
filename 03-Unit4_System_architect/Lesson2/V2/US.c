/* Author: ENG: Mohamed Ahmed*/

#include "US.h"

//Variables
int US_distance = 0 ;
//State pointer is a pointer to function
void (*US_state) ();


int get_random(int l , int r , int count){
     int i ;
     for(i =0 ; i<count ; i++){
         int rand_num = (rand()%(r-l+1))+l;
         return rand_num;
     }
}

void US_init(){

    printf("US init \n");
}

STATE_define(US_busy){
    //State name
    US_state_id = US_busy;

    //state action

    US_distance = get_random(45,55,1);

    //event check

    printf("US_waiting_state : distance : %d \n",US_distance);
    US_Set_distance(US_distance);
    US_state = STATE(US_busy);
}
