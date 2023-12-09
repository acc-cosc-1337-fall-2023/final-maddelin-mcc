#include "die.h"
#include <random>
#include <math.h>
//public functions
    void Die::roll()
    {
        //Randomly assigns a value to roll_value in the range of 1 to 6
        roll_value =  (rand() % 6) + 1;
    }
    int Die::rolled_value()
    {
        //Returns roll_value
        return roll_value;
    }