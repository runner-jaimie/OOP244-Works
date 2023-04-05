/* Citation and Sources...
Final Project Milestone 1
Module: Date
Filename: Date.h
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

#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include "POS.h"
#include "Error.h"

namespace sdds
{
    class Date
    {
        int m_year;
        int m_month;
        int m_day;
        int m_hour;
        int m_minute;
        bool m_dateOnly = false;
        Error m_error;
        
    public:
        void valid();
        
        //Constructor
        Date();
        Date(int year, int month, int day, int hour = 0, int min = 0); //Constructor 공부하장 !!!
        
        //Comparison Operator Overloads
        bool operator==(const Date& right) const;
        bool operator!=(const Date& right) const;
        bool operator<(const Date& right) const;
        bool operator>(const Date& right) const;
        bool operator<=(const Date& right) const;
        bool operator>=(const Date& right) const;
        
        //Conversion
        operator bool()const; //Boolean type conversion
        operator int() const; //Int type conversion
        
        const Error& error(); //The error query
        Date& dateOnly(bool dateOnly); //dateOnly modifier method
        std::istream& read(std::istream& istr = std::cin); //read는 읽어온 파일을 assign 해줘야 하기 때문에 const를 쓸수 없다. 값이 변하잖아 정미야 !!!
        std::ostream& display(std::ostream& ostr = std::cout) const;
    };
    
    //Helper Functions
    std::ostream& operator<<(std::ostream& ostr, const Date& right);
    std::istream& operator>>(std::istream& istr, Date& right);
    
    //Utility Functions
    void getSystemDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
    int uniqueDateValue(int year, int mon, int day, int hour, int min);
    int daysOfMonth(int year, int month);

}
#endif
