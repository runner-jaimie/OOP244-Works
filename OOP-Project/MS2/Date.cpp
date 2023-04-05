/* Citation and Sources...
Final Project Milestone 1
Module: Date
Filename: Date.cpp
Version 1.0
Author: Jeongmi Lee
Student Id: 122442221
Revision History
-----------------------------------------------------------
Date Reason
20223/03/20 Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <ctime>
#include "Date.h"

using namespace std;

namespace sdds
{
    //Validation
    void Date::valid()
    {
        bool ok = true;
        
        if(m_year < MIN_YEAR || m_year > MAX_YEAR ) //false 조건문을 짜야함
        {
            ok = false;
            m_error = "Invalid Year";
        }
        if(ok && (m_month > 12 || m_month < 0) )
        {
            ok = false;
            m_error = "Invalid Month";
        }
        if(ok && (m_day < 0 || m_day > daysOfMonth(m_year, m_month)))
        {
            ok = false;
            m_error = "Invalid Day";
        }
        if(ok && (m_hour < 0 || m_hour > 23))
        {
            ok = false;
            m_error = "Invalid Hour";
        }
        if(ok && (m_minute < 0 || m_minute > 59))
        {
            ok = false;
            m_error = "Invlid Minute";
        }
    }
    
    //Constructor
    Date::Date()
    {
        m_dateOnly = false; //defalult constructor는 date only가 아니라서
        getSystemDate(m_year, m_month, m_day, m_hour, m_minute, m_dateOnly);
        m_error = Error(); // m_error 변수에 클래스 initialize 만듬
    }
    
    Date::Date(int year, int month, int day, int hour, int min)
    {
        m_year = year;
        m_month = month;
        m_day = day;
        m_hour = hour;
        m_minute = min;
        if(m_hour == 0 && m_minute == 0)
        {
            m_dateOnly = true;
        }
        m_error = Error(); //🍎 왜 해주는지 모름 질문 하자!!!!
    }
  
    //Comparison Operator Overloads
    bool Date::operator==(const Date& right) const
    {
        return int(*this) == int(right);
    }
    bool Date::operator!=(const Date& right) const
    {
        return int(*this) != int(right) ;
    }
    bool Date::operator<(const Date& right) const
    {
        return int(*this) < int(right) ;
    }
    bool Date::operator>(const Date& right) const
    {
        return int(*this)>int(right) ;
    }
    bool Date::operator<=(const Date& right) const
    {
        return int(*this)<=int(right) ;
    }
    bool Date::operator>=(const Date& right) const
    {
        return int(*this) >= int(right) ;
    }
    
    //Conversion
    Date::operator bool()const
    {
        return !bool(m_error); // 🍎디버깅 하기
    }
    Date::operator int() const
    {
        return uniqueDateValue(m_year, m_month, m_day, m_hour, m_minute);
    }
    
    Date& Date::dateOnly(bool dateOnly)
    {
        if(dateOnly)
        {
            m_dateOnly = dateOnly;
            m_hour = 0;
            m_minute = 0;
        }
        return *this;
    }
    
    //Error query
    const Error& Date::error() //🍎const가 앞에 붙은 이유는???
    {
        return m_error;
    }
    
    //Display
    ostream& Date::display(ostream& ostr) const
    {
        if(m_error)
        {
            ostr << m_error << "(";
        }
        ostr.width(1);
        ostr.fill('0');
        ostr << m_year;
        ostr << "/";
        ostr.width(2);
        ostr.fill('0');
        ostr << m_month;
        ostr << "/";
        ostr.width(2);
        ostr.fill('0');
        ostr << m_day;
        
        if(!m_dateOnly)
        {
            ostr << ", ";
            ostr.width(2);
            ostr.fill('0');
            ostr << m_hour;
            ostr << ":";
            ostr.width(2);
            ostr.fill('0');
            ostr << m_minute;
           
        }
        if(m_error)
        {
            ostr << ")";
        }
        
        return ostr;
    }

    //Read
    istream& Date::read(istream& istr)
    {
        bool ok = true;
        if(!m_error)
        {
            m_error.clear();
            m_year = 0;
            m_month = 0;
            m_day = 0;
            m_hour = 0;
            m_minute = 0;
        }
        
        istr >> m_year;
        if(!istr)
        {
            m_error = "Cannot read year entry";
            ok = false;
        }
        if(ok)
        {
            istr.ignore();
            istr >> m_month;
            if(!istr) //
            {
                m_error = "Cannot read month entry";
                ok = false;
            }
        }
        if(ok)
        {
            istr.ignore();
            istr >> m_day;
            if(!istr)
            {
                m_error = "Cannot read day entry";
                ok = false;
            }
        }
        if(!m_dateOnly)
        {
            if(ok)
            {
                istr.ignore(); istr.clear();
                istr >> m_hour;
                if(!istr)
                {
                    m_error = "Cannot read hour entry";
                    ok = false;
                }
            }
            if(ok)
            {
                istr.ignore();
                istr >> m_minute;
                if(!istr)
                {
                    m_error = "Cannot read minute entry";
                }
            }
        }
        if(ok)
        {
            valid();
        }
        
        return istr;
    }
    
    //Helper Functions
    istream& operator>>(istream& istr, Date& right)
    {
        return right.read(istr);
    }
    
    ostream& operator<<(ostream& ostr, const Date& right)
    {
        return right.display(ostr);
    }
    
    
    //Utility Functions
    void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly)
    {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        day = lt.tm_mday;
        mon = lt.tm_mon + 1;
        year = lt.tm_year + 1900;
        
        if(dateOnly)
        {
            hour = min = 0;
        } else
        {
            hour = lt.tm_hour;
            min = lt.tm_min;
        }
    }
    
    int uniqueDateValue(int year, int mon, int day, int hour, int min)
    {
        return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
    }
    
    int daysOfMonth(int year, int month)
    {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = month >= 1 && month <= 12 ? month : 13;
        mon--;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
}
    
    

