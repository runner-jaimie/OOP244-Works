/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File    Video.h
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
#ifndef SDDS_VIDEO_H
#define SDDS_VIDEO_H
#include "Media.h"

namespace sdds
{
    class Video : public Media
    {
        int m_length;
      
    protected:
        int get() const;
        
    public:
        void load(std::istream& istr = std::cin);
        Video();
        Video(int length);
        Video(const Video& source) = delete;
        Video& operator=(const Video& source) = delete;
        
    };
}
#endif
