/* Author: ENG: Mohamed Ahmed*/

#include <stdio.h>
#include <stdlib.h>
#include "CA.h"

void setup()
{
    CA_state = STATE(CA_Waiting);
}

int main()
{
    volatile int x;
    setup();
    while(1)
    {
        CA_state();
        for(x = 0 ; x <100000;x++);
    }
    return 0;
}
