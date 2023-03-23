/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File    Media.cpp
// Version 1.0
// Date       March 23, 2023
// Author    Jeongmi Lee
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date                 Reason
// Fardad          2023-03-19      Revision, correction
/////////////////////////////////////////////////////////////////
 ***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Media.h"

using namespace std;

namespace sdds
{
    
    Media::~Media()
    {
      
    }
    //Media Helper function
    ostream& operator<<(ostream& ostr, const Media& right)
    {
        return right.play(ostr);
    }
    istream& operator>>(istream& istr, Media& right)
    {
        right.load(istr);
        return istr;
    }
}
