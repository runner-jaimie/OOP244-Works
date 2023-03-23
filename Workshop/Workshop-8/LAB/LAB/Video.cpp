/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File    Video.cpp
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
#include "Video.h"

using namespace std;

namespace sdds
{
    int Video::get() const
    {
        return  m_length;
    }
    
    //Constructor
    Video::Video()
    {
        m_length = 0;
    }
    
    Video::Video(int length)
    {
        if(length < 0)
        {
            m_length = 0; //set to be empty if the length is not valid
        }
        else
        {
          m_length = length;
        }
    }
    
    void Video::load(istream& istr)
    {   int temp;
        istr >> temp;
        m_length = temp;
        istr.ignore(100, ',');
    }
}
