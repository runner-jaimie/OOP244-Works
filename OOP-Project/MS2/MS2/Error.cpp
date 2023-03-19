/* Citation and Sources...
Final Project Milestone 1
Module: Error
Filename: Error.cpp
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
#include "Error.h"
#include "Utils.h"

using namespace std;

namespace sdds
{
    //Constructor
    Error::Error() //No Error state
    {
        clear();
    }
    
    Error::Error(const char* errorMsg)
    {
        if(errorMsg != nullptr)
        {
            m_errorMsg = new char[strlen(errorMsg) + 1];
            strcpy(m_errorMsg, errorMsg);
        }
        
    }
    
    Error::Error(const Error& source) //Copy constructor
    {
        operator=(source);
        
    }
    
    Error& Error::operator=(const Error& source) //Copy assignment
    {
        if(this != &source) //Prevent self copy -> Error class 자신과 source가 같으면 
        {
            delete[] m_errorMsg;
            clear();
            
            if(source.m_errorMsg)
            {
                m_errorMsg = new char[strlen(source.m_errorMsg) + 1];
                strcpy(m_errorMsg, source.m_errorMsg);
//                delete [] m_errorMsg; 지우면 안된다 복사하고 데이트를 없애면 복사할 필요 없는거임
//                m_errorMsg = nullptr;
            }
        }
        return *this;
    }
    
    Error::~Error()
    {
        delete [] m_errorMsg;
        m_errorMsg = nullptr;
    }
    
    Error& Error::clear()
    {
        m_errorMsg = nullptr;
        return *this;
    }
    
    Error& Error::operator=(const char* value)
    {
        if(value != nullptr)
        {
            m_errorMsg = new char[strlen(value) + 1];
            strcpy(m_errorMsg, value);
        }
        else
        {
            value = nullptr;
        }
        
        return *this;
    }
    
    Error::operator bool()const
    {
        bool check = false;
        
        if(m_errorMsg != nullptr) // nullptr이 아니면 에러가 있다는 것
        {
            check = true; //에러가 있으면 true;
        }
        return check;
    }
    
    
    ostream& Error::display(ostream& ostr) const
    {
        if(m_errorMsg) // null 이면 출력하면 안되니깐 null이 아닐때 출력
        {
            ostr << m_errorMsg;
        }
            return ostr;
    }
    
    ostream& operator<<(ostream& ostr, const Error& right)
    {
        right.display(ostr);
        return (ostr);
    }
};
