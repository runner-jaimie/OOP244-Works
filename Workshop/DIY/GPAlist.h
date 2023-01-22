/***********************************************************************
// OOP244 Workshop 1 p2: GPA header file
//
// File:    GPAlist.h
// Version: 1.0
// Date:    Jan 22, 2023
// Author:  Jeongmi Lee
// Id:      122442221
// email:   jlee723@myseneca.ca
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_GPALIST_H
#define SDDS_GPALIST_H

namespace sdds 
{
  // Function
  bool gpaQuery(const char* filename);
  void sortStudentStno(struct GPA* studentStno, int n);
  bool checkOption(const struct GPA* studentGpa, const char option, double gpaValue);
  void displayGpa(const struct GPA* displayGpa);
  void displayGpaWithOption(const char option, double gpa);
}

#endif // !SDDS_GPALIST_H
