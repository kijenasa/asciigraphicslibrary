#include<stdlib.h>
#include "../include/window.h"

#ifndef INPUT_H
#define INPUT_H

#define INPUT_COUNT 4 // The amount of inputs
                      //
// The position in window.input[] that the key value is held
#define INPUT_UP 0 
#define INPUT_DOWN 1
#define INPUT_LEFT 2
#define INPUT_RIGHT 3


void update_input(window *win); // TODO

#endif
