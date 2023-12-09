#include "shooter.h"
#include<iostream>

//Public Functions
    Roll* Shooter::throw_die(Die& d1, Die& d2)
    {

        //Create a dynamic instance of Roll, call roll_die(), add roll to vector and return the roll instance
        Roll *roll = new Roll(d1, d2);
        roll->roll_die();
        rolls.push_back(roll);
        return roll;
    }

    void Shooter::display_rolls()
    {
        for( auto i: rolls)
        {
            cout<<i->roll_value()<<"\n";
        }
    }

    Shooter::~Shooter()
    {
        for( auto i: rolls)
        {
            delete i;
        }
    }