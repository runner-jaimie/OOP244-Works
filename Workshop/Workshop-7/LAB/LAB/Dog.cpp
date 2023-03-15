/* Citation and Sources...
Final Project Milestone 1
Module: Dog
Filename: Dog.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Dog.h"

using namespace std;

namespace sdds
{
    Dog::Dog(const char* name, int age):Pet(name, age, DOG_COST_BASE)
    {
        m_numWalks = 0;
    }
    
    void Dog::feed()
    {
        Pet::feed();
        if(isAlive())
        {
            addCharge(DOG_COST_FEED);
        }
    }
    
    void Dog::walk()
    {
        if(isAlive())
        {
            m_numWalks++;
        }
    }
    
    void Dog::reSpawn()
    {
        Pet::reSpawn();
        addCharge(DOG_COST_REVIVE);
        m_numWalks = 0;
    }
    
    int Dog::getWalks()
    {
        return m_numWalks;
    }
    
    void Dog::operator++ (int num)
    {
        if(isAlive())
        {
            double healthDelta = 0;
            healthDelta += 0.15 * (getHugs() - 1);
            healthDelta += 0.10 * (getFeeds() - 2);
            healthDelta += 0.10 * (getGrooms() - 1);
            healthDelta += 0.20 * (m_numWalks - 2);
            applyHealthDelta(healthDelta);
            m_numWalks = 0; // each day 다음날 초기화 해야한다.
        }
        Pet::operator++(num);
    }
    
    Dog& Dog::operator=(const Dog& rhs)
    {
        Pet::operator=(rhs);
        addCharge(DOG_COST_BASE  * 2);
        m_numWalks = rhs.m_numWalks; // 
        return *this;
    }
    
    ostream& operator<<(ostream& os, Dog& dog)
    {
        //int numWalks = 0;
        //numWalks = dog.getWalks();
        os << "** Generic Dog **" << endl;
        os << "   Walks: " << dog.getWalks() << endl;
        return dog.outputData(os);
    }
}
