/* Citation and Sources...
Final Project Milestone 1
Module: PosIO
Filename: PosIO.cpp
Version 1.0
Author: Jeongmi Lee
Student Id: 122442221
Revision History
-----------------------------------------------------------
Date Reason
20223/03/29 Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "PosIO.h"

using namespace std;

namespace sdds
{
    PosIO::~PosIO()
    {
        
    }
    ostream& operator<<(ostream& ostr, const PosIO& right)
    {
        return right.write(ostr);
    }
    
    istream& operator>>(istream& istr, PosIO& right)
    {
        return right.read(istr);
    }
    ofstream& operator<<(ofstream& ofst, const PosIO& right)
    {
        return right.save(ofst);
    }
    ifstream& operator>>(ifstream& ifst, PosIO& right)
    {
        return right.load(ifst);
    }
}


