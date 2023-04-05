/* Citation and Sources...
Final Project Milestone 1
Module: PosIO
Filename: PosIO.h
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
#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H
#include <iostream>

namespace sdds
{
    class PosIO
    {
    public:
        
        virtual std::ostream& write(std::ostream& ostr = std::cout) const = 0;
        virtual std::istream& read(std::istream& istr = std::cin) = 0;
        virtual std::ofstream& save(std::ofstream& ofst) const = 0;
        virtual std::ifstream& load(std::ifstream&  ifst) = 0;
        virtual ~PosIO();
    };
    
    //Helper Function
    std::ostream& operator<<(std::ostream& ostr, const PosIO& right);
    std::istream& operator>>(std::istream& istr, PosIO& right);
    std::ofstream& operator<<(std::ofstream& ofst, const PosIO& right);
    std::ifstream& operator>>(std::ifstream& ifst, PosIO& right);
    
}

#endif
