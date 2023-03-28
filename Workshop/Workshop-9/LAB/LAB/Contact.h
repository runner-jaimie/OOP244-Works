/***********************************************************************
// OOP244 Workshop #9: tester program
//
// File    Contact.h
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

#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include "Person.h"

namespace sdds
{
  class Contact : public Person 
  {
    char* m_address{};
    char* m_city{};
    char m_province[2 + 1]{};
    char m_postalCode[6 + 1]{};

  public:

  //Constructor Rule of three
  Contact();
  Contact(const Contact& source);
  Contact& operator =(const Contact& source);
  ~Contact();

  //Operator
  operator bool()const;
  void operator~();

  //Rean and Write
  std::istream& read(std::istream& istr);
  std::ostream& write(std::ostream& ostr)const;
  
  };
//  
//  //Helper function
//  std::istream& operator>>(std::istream& leftOperand, Person& rightOperand);
//  std::ostream& operator<<(std::ostream& leftOperand, const Person& rightOperand);
}

#endif
