/* Author: ENG: Mohamed Ahmed*/

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

//Automatic state function

#define STATE_DEFINE(_staFUN_) void ST_##_staFUN_()
#define STATE(_staFUN_) ST_##_staFUN_




#endif // STATE_H_
