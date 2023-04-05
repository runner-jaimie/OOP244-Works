/* Citation and Sources...
Final Project Milestone 1
Module: NonPerishable
Filename: NonPerishable.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "NonPerishable.h"

using namespace std;

namespace sdds
{
    char NonPerishable::itemType() const
    {
        return 'N';
    }
    ostream& NonPerishable::write(ostream& ostr) const
    {
        // item에 write 가져와야 한다. 

        
        if (*this && ostr)
        {
            Item::write(ostr);
            if (m_diaplay == POS_LIST)
            {
                ostr << "     ";
                ostr << "N / A" << "   |";
            }
            if (m_diaplay == POS_FORM)
            {
                ostr << "=============^" << endl;
            }
        }
        return ostr;
    }
}
