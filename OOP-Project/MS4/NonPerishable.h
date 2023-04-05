
/* Citation and Sources...
Final Project Milestone 1
Module: NonPerishable
Filename: NonPerishable.h
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
#ifndef NONPERISHABLE_H
#define NONPERISHABLE_H

#include "Item.h"

namespace sdds
{
    class NonPerishable : public Item
    {
        char itemType() const;
        std::ostream& write(std::ostream& ostr = std::cout) const;
    };
}

#endif
