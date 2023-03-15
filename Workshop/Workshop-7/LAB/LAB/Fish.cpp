/* Citation and Sources...
Final Project Milestone 1
Module: Fish
Filename: Fish.cpp
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
#include "Fish.h"

using namespace std;

namespace sdds
{
    Fish::Fish(const char* name, int age):Pet(name, age, FISH_COST_BASE)
    {
        //Pet(base class)이 가지고 있는 constructor를 통해서 Fish(derived class)가 필요한 기능을 해줄 수 있다. Pet.cpp 38을 보면 strncpy(for name), totalCahrges, age 생성한다.
    }
    
    
    void Fish::feed()
    {
        Pet::feed(); // Pet:: 즉 scope를 줘서 base class의 함수인지 derived class 함수인지 명시해줘야 한다.
        if(isAlive()) // 살아 있으면 밥주기
        {
            addCharge(FISH_COST_FEED);
            
        }
    }
    
    void Fish::reSpawn()
    {
        Pet::reSpawn();
        addCharge(FISH_COST_REVIVE);
    }
    
    void Fish::operator++ (int num)
    {
        if(isAlive())
        {
            double healthDelta = 0;
            healthDelta += 0.20 * (getFeeds() - 1);
            applyHealthDelta(healthDelta);
        }
        Pet::operator++(num);
    }
    
    Fish& Fish::operator=(const Fish& rhs)
    {
        Pet::operator=(rhs);
        addCharge(FISH_COST_BASE  * 2);
        return  *this;
    }
    
    ostream& operator<<(ostream& os, Fish& fish)
    {
        os << "** Generic Fish **" << endl;
        return fish.outputData(os);
    }
}
