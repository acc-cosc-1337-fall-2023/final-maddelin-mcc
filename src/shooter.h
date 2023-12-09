#include "die.h"
#include "roll.h"
#include <vector>
#include <iostream>

using std::cout; using std::string;

#ifndef SHOOTER_H
#define SHOOTER_H

    class Shooter 
    {
        public:
            Roll* throw_die(Die& d1, Die& d2);
            //Shooter& operator<<(){};
            //I am stuck on the shooter << operator, so I will instead write a function to output the roll vector for my question 3 submissions so that I can move on
            void display_rolls();

            ~Shooter();
        private:
            std::vector<Roll*> rolls;

    };

#endif