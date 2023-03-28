/***********************************************************************
// OOP244 Workshop #9: tester program
//
// File    Contact.cpp
// Version 1.0
// Date       March 28, 2023
// Author    Jeongmi Lee
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date                 Reason
// Fardad          2023-03-19      Revision, correction
/////////////////////////////////////////////////////////////////
 ***********************************************************************/
#include <iostream>
#include "Contact.h"
#include "Tools.h"

using namespace std;

namespace sdds
{
  //Constructor Rule of three
  Contact::Contact() : Person()
  {
      
  }
  Contact::Contact(const Contact& source) 
  {
    operator=(source);
  }
  Contact& Contact::operator=(const Contact& source)
  {
    if (this != &source) 
    {
      Person::operator=(source); // 이름을 받아야 하기 때문에 부모클래스 호출 해야지 이름 카피 할 수 있다. 
      delAlloCopy(m_address, source.m_address);
      delAlloCopy(m_city, source.m_city);
      strCpy(m_province, source.m_province);
      strCpy(m_postalCode, source.m_postalCode);
    }
    return *this;
  }
  Contact::~Contact()
  {
    ~*this;
  }

  //Operator
  Contact::operator bool()const
  {
    return m_address && m_address[0] && m_city && m_city[0]
           && strLen(m_province) == 2 && m_province[0]  && strLen(m_postalCode) == 6 && m_postalCode[0];
  }
  void Contact::operator~()
  {
    delete[] m_address;
    delete[] m_city;
    m_province[0] = '\0';
    m_postalCode[0] = '\0';
    m_address = m_city = nullptr;
  }

  //Read and Write
  istream& Contact::read(istream& istr) 
  {
    ~*this;
    Person::read(istr);
    m_address= dynRead(istr, ',');
    m_city = dynRead(istr, ',');
    istr.getline(m_province,3,',');
    istr.getline(m_postalCode, 7,'\n');
    if (istr.fail()) ~*this;
    return istr;
  }
  ostream& Contact::write(ostream& ostr) const 
  {
    if (*this) {
        Person::write(ostr) << endl;
        ostr << m_address << endl << m_city
        <<" " <<m_province << endl
        << m_postalCode[0] <<m_postalCode[1]<<m_postalCode[2]<<" "
        <<m_postalCode[3]<<m_postalCode[4]<<m_postalCode[5]<<endl;
    }
    return ostr;
  }
//
//  //Helper function
//  istream& operator>>(istream& leftOperand, Contact& rightOperand) 
//  {
//    return rightOperand.read(leftOperand);
//  }
//
//  ostream& operator<<(ostream& leftOperand, const Contact rightOperand) 
//  {
//    return rightOperand.write(leftOperand);
//  }
}
