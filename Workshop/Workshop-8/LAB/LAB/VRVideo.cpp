/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File
 VRVideo.cpp
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
#include "VRVideo.h"

using namespace std;

namespace sdds
{
    VRVideo::VRVideo() :Video() //Base class의 constructor를 기본으로 사용한다 라는 것
    {
        m_equipment = nullptr;
        
    }
    
    VRVideo::VRVideo(int length, const char* equipment) :Video(length), m_equipment{nullptr} // length를 Video class의 매겨변수가 하나인 constructor를 사용한 다는 것
    {
        if(equipment != nullptr && length > 0)
        {
            m_equipment = new char[strlen(equipment) + 1];
            strcpy(m_equipment,equipment);
        }
        else
        {
            m_equipment = nullptr; // Empty state
        }
    }
    
    VRVideo::~VRVideo()
    {
        delete [] m_equipment; //Delete meory
    }
    
    void VRVideo::load(istream& istr)
    {
      Video::load(istr);
      if(m_equipment != nullptr)
      {
        delete [] m_equipment;
        char temp[200]={0}; // char string을 temp 로 변수 선언 할때 static만 가능하다.
        istr.getline(temp, 200, '\n'); // getline(담을 변수, 몇글자까지, 어디까지)
        m_equipment = new char[strlen(temp) + 1];
        strcpy(m_equipment, temp); 
      }
    }

    ostream& VRVideo::play(ostream& ostr) const
    {
      if(m_equipment != nullptr)
      {
        ostr << "VRVideo requires " << m_equipment << endl
          << "Video Length = " <<  Video::get();
      }
      return ostr;
    }
}
