/* Citation and Sources...
Final Project Milestone 1
Module: Fish
Filename: Fish.h
Version 1.0
Author: Jeongmi Lee
Student Id: 122442221
Revision History
-----------------------------------------------------------
Date Reason
20223/03/14 Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
I get Utils.h and Utils.cpp files from Prof.Fardad's lecture note.
-----------------------------------------------------------
 */

#ifndef SDDS_FISH_H
#define SDDS_FISH_H
#include "Pet.h"

namespace sdds
{
    class Fish : public Pet
    {
        const double FISH_COST_BASE        = 2.00;        // Fee: Initial purchase
        const double FISH_COST_FEED        = 0.10;        // Fee: For each feeding
        const double FISH_COST_REVIVE      = 0.50;        // Fee: Respawn if perished
    
    public:
        Fish(const char* name, int age = 0);
        void feed();
        void reSpawn();
        void operator++ (int num);
        Fish& operator=(const Fish& rhs);
    };
    std::ostream& operator<<(std::ostream& os, Fish& fish);
    
}
#endif
