/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File
 VRVideo.h
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
#ifndef SDDS_VRVIDEO_H
#define SDDS_VRVIDEO_H
#include "Video.h"

namespace sdds
{
    class VRVideo : public Video
    {
        char* m_equipment;
         
    public:
        VRVideo();
        VRVideo(int length, const char* equipment);
        ~VRVideo();
        
        void load(std::istream& istr = std::cin);
        std::ostream& play(std::ostream& ostr = std::cout) const;
        
    };
}
#endif
