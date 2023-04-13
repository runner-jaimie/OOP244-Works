/* Citation and Sources...
Final Project Milestone 1
Module: Perishable
Filename: Perishable.cpp
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
#include <fstream>
#include "Perishable.h"

using namespace std;

namespace sdds
{
	char Perishable::itemType() const
	{
		return 'P';
	}
	std::istream& Perishable::read(std::istream& istr)
	{
		Date D;

		Item::read(istr);

		if (*this && istr)
		{
			istr.ignore(100, '\n');
			cout << "Expiry date (YYYY/MM/DD)" << endl;
			cout << "> ";
			D.dateOnly(true); 
			istr >> D;

			if (D)
			{
				m_date = D;
			}
		}

	return istr;
	}
	std::ostream& Perishable::write(std::ostream& ostr) const
	{
		Item::write(ostr);

		if (*this && ostr)
		{
			
			if (m_diaplay == POS_LIST)
			{
				ostr << "  ";
				ostr << m_date << " |";
			}
			if (m_diaplay == POS_FORM)
			{
				ostr << "Expiry date: " << m_date << endl;
				ostr << "=============^" << endl;
			}
		}
		return ostr;
	}
	std::ifstream& Perishable::load(std::ifstream& ifst)
	{
		Date D;
		Item::load(ifst);

		if (*this && ifst)
		{
			D.dateOnly(true);
			ifst.ignore(1, ',');
			ifst >> D;

			if (D)
			{
				m_date = D;
			}
			
		}
		return ifst;
	}
	std::ofstream& Perishable::save(std::ofstream& ofst) const
	{
		Item::save(ofst);
		ofst << "," << m_date;

		return ofst;
	}
}
