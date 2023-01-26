/***********************************************************************
// OOP244 Workshop 1 p2: GPA header file
//
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
#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds 
{
  bool openFile(const char filename[]);
  void closeFile();
  bool readName(char name[]);
  bool readStno(int*  stno);
  bool readGpa(double* gpa);  
}

#endif