/* Citation and Sources...
Final Project Milestone 1
Module: Perishable
Filename: Perishable.h
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
#ifndef PERISHABLE_H
#define PERISHABLE_H
#include "Item.h"
#include "Date.h"

namespace sdds
{
    class Perishable : public Item
    {
        Date m_date;
        char itemType() const;
        
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::ifstream& load(std::ifstream& ifst);
        std::ofstream& save(std::ofstream& ofst) const;
    };
    
}




#endif

