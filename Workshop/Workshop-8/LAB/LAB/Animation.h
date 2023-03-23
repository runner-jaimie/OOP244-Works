/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File    Animation.h
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
#ifndef SDDS_ANIMATION_H
#define SDDS_ANIMATION_H
#include "Video.h"

namespace sdds
{
    class Animation : public Video
    {
        int m_dimension;
        
    public:
        Animation();
        Animation(int length, int dimension);
        void load(std::istream& istr = std::cin);
        std::ostream& play(std::ostream& ostr = std::cout) const;
    };
}
#endif
