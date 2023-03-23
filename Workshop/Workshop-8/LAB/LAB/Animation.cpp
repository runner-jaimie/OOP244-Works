/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File    Animation.cpp
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
#include "Animation.h"

using namespace std;

namespace sdds
{
  Animation::Animation()
  {
    m_dimension = 0;
  }

  Animation::Animation(int length, int dimension) : Video(length)
  {
    if((dimension == 2 || dimension == 3) && length > 0)
    {
      m_dimension = dimension;
    }
    else
    {
      m_dimension = 0;
    }
  }

  void Animation::load(istream& istr)
  {
    Video::load(istr);
    int temp;
    istr >> temp;
    istr.ignore(100,'\n');
    if(temp == 2 || temp == 3)
    {
      m_dimension = temp;
    }
  }

  ostream& Animation::play(ostream& ostr) const
  {
    if(m_dimension != 0)
    {
      ostr << "Animation is in " << m_dimension << "-D" << endl
        << "Video Length = " <<  Video::get();
    }
    return ostr;
  }
}
