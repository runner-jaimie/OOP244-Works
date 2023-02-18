/***********************************************************************
// OOP244 Workshop 5 Part2: Operators
// File Bus.cpp
// Version 1.0
// Date    2023/02/16
// Author Jeongmi Lee
// Description
// Tests the Bus module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include <cstring>
#include "Bus.h"

using namespace std;

namespace sdds
{
    //Constructor
    Bus::Bus(int numOfSeats, int numOfPassengers)
    {
        if((numOfSeats % 2 == 0) && (numOfSeats >= 10 && numOfSeats <= 40) && (numOfPassengers >= 0 && numOfPassengers <= numOfSeats))
        {
            set(numOfSeats, numOfPassengers);
        }
        else
        {
            setOutOfService();
        }
    }
    
    //Member function
    Bus& Bus::set(int numOfSeats, int numOfPassengers)
    {
        m_numOfSeats = numOfSeats;
        m_numOfPassengers = numOfPassengers;
        return *this;
    }
    void Bus::setOutOfService() // safe empty state
    {
        m_numOfSeats = -1;
        m_numOfPassengers = -1;
    }
    istream& Bus::read(std::istream& istr)
    {
        int numOfSeats, numOfPassengers;
        
        istr >> numOfSeats;
        istr.clear();
        istr.ignore(50, ',');
        
        istr >> numOfPassengers;
        istr.clear();
        istr.ignore(50,'\n');
        
        if((numOfSeats % 2 == 0) && (numOfSeats >= 10 && numOfSeats <= 40) && (numOfPassengers >= 0 && numOfPassengers <= numOfSeats))
        {
            set(numOfSeats, numOfPassengers);
        }
        else
        {
            setOutOfService();
        }
        return istr;
    }
    ostream& Bus::display(ostream& ostr) const
    {
        if(*this)
        {
            drawBus(m_numOfSeats, m_numOfPassengers, ostr);
            cout << fixed;
            cout.precision(2);
            cout << "Total Fare Price: " << double(*this) << endl;
            
        }
        else
        {
            cout << "Out of service!" << endl;
        }
        return ostr;
    }
    void Bus::drawBus(int seats, int noOfPassengers, ostream& ostr) const {
      int i, p;
      ostr.fill('_');
      ostr.width((seats / 2) * 3 + 4);
      ostr << "_";
      ostr << endl << "| ";
      for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
      ostr << "|_\\_" << endl;
      ostr << "| ";
      ostr.fill(' ');
      ostr.width(((seats / 2) * 3 - 14) / 2);
      ostr << " " << "Seneca College";
      ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
      ostr << " " << "    )" << endl;
      ostr << "`---OO";
      ostr.fill('-');
      ostr.width((seats / 2) * 3 - 5);
      ostr << "-" << "O---'" << endl;
    }
    
    //Conversion
    Bus::operator bool() const
    {
        bool check = false;
        if(m_numOfSeats > 0)
        {
            check = true;
        }
        return check;
    }
    Bus::operator int() const
    {
        return (bool(*this)) ? m_numOfPassengers : -1;
    }
    Bus::operator double() const
    {
        double totalFare = 0.00;
        
        if(m_numOfPassengers >= 0)
        {
            totalFare = double(priceOfBusTicket * m_numOfPassengers);
        }
        return (bool(*this)) ? double(totalFare) : -1;
    }
    
    //Unary operator (prefix)
    bool Bus::operator--()
    {
        bool check = false;
        if(m_numOfPassengers > 0 && *this)
        {
            m_numOfPassengers-=1;
            check = true;
        }
        return check;
    }
    bool Bus::operator++()
    {
        bool check = false;
        if(m_numOfPassengers != m_numOfSeats && m_numOfPassengers <= m_numOfSeats && *this )
        {
            m_numOfPassengers +=1;
            check = true;
        }
        return check;
    }
    
    //Unary operator(postfix)
    bool Bus::operator--(int)
    {
        bool check = false;
        if(m_numOfPassengers > 0 && m_numOfPassengers <= m_numOfSeats && *this)
        {
            m_numOfPassengers-=1;
            check = true;
        }
        return check;
    }
    bool Bus::operator++(int)
    {
        bool check = false;
        if(m_numOfPassengers != m_numOfSeats && m_numOfPassengers <= m_numOfSeats && *this )
        {
            m_numOfPassengers +=1;
            check = true;
        }
        return check;
    }
    

    //Binay operator(postfix)
    Bus& Bus::operator=(int value)
    {
        if(value < m_numOfSeats)
        {
            m_numOfPassengers = value;
        }
        else
        {
            setOutOfService();
        }
        return *this;
    }
    Bus& Bus::operator+=(int value)
    {
        if(m_numOfPassengers + value > m_numOfSeats)
        {
            setOutOfService();
        }
        else{
            m_numOfPassengers+=value;
        }
        return *this;
    }
    Bus& Bus::operator+=(Bus& right)
    {
        if(*this)
        {
            if(m_numOfSeats - m_numOfPassengers < right.m_numOfPassengers)
            {
                right.m_numOfPassengers = right.m_numOfPassengers-(m_numOfSeats - m_numOfPassengers);
                m_numOfPassengers = m_numOfPassengers + (m_numOfSeats - m_numOfPassengers);
            }
            else
            {
                m_numOfSeats+=right.m_numOfPassengers;
            }
            
        }
        return *this;
    }
    bool Bus::operator==(const Bus& right) const
    {
        return m_numOfPassengers == right.m_numOfPassengers;
    }
    
    //Helper binary operator overload
    int operator+(int left, const Bus& right)
    {
        // right값이 true야 라고 채크하기 위해서 bool(right)의 값을 넣으면 bool operator로 확인
        return bool(right) ? int(right)+left : left ;
    }
    ostream& operator<<(ostream& ostr, const Bus& right)
        {
            return right.display(ostr);
        }

    istream& operator>>(istream& istr, Bus& right)
    {
        return right.read(istr);
    }
}
