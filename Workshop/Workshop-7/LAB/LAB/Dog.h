/* Citation and Sources...
Final Project Milestone 1
Module: Dog
Filename: Dog.h
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

#ifndef SDDS_DOG_H
#define SDDS_DOG_H
#include "Pet.h"

namespace sdds
{
    class Dog : public Pet
    {
        const double DOG_COST_BASE        = 4.00;        // Fee: Initial purchase
        const double DOG_COST_FEED        = 0.25;        // Fee: For each feeding
        const double DOG_COST_REVIVE      = 1.00;        // Fee: Respawn if perished
        
        int m_numWalks;
        
    public:
        Dog(const char* name, int age = 0);
        void feed();
        void walk();
        void reSpawn();
        int getWalks();
        void operator++ (int num);
        Dog& operator=(const Dog& rhs);
    };
    std::ostream& operator<<(std::ostream& os, Dog& dog);
}

#endif
