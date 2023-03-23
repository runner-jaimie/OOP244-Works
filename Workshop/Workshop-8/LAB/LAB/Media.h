/***********************************************************************
// OOP244 Workshop # p1: tester program
//
// File    Media.h
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
#ifndef SDDS_MEDIA_H
#define SDDS_MEDIA_H

namespace sdds
{
    class Media
    {
        
    public:
        virtual std::ostream& play(std::ostream& ostr = std::cout) const = 0;
        virtual void load(std::istream& istr = std::cin) = 0;
        virtual ~Media();
        
    };
    
    //Media Helper functions
    std::ostream& operator<<(std::ostream& ostr, const Media& right);
    std::istream& operator>>(std::istream& istr, Media& right);
}
#endif
