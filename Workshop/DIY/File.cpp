/***********************************************************************
// OOP244 Workshop 1 p2: GPA header file
//
// File  File.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "File.h"

using namespace std;

namespace sdds 
{
  FILE* fptr;

  // opens the data file and returns true is successful
  bool openFile(const char filename[])
  {
    fptr = fopen(filename, "r");
    return fptr != NULL;
  }

  // closes the data file
  void closeFile()
  {
    if (fptr)
      fclose(fptr);
  }

  // reads the title of the GPA from the global fptr File pointer
  // returns true if successful
  bool readName(char name[])
  {
    return fscanf(fptr, "%[^,],", name) == 1;
  }

  // reads the stunedts number of the GPA from the global fptr File pointer
  // returns true if successful
  bool readStno(int* stno) 
  {
    return fscanf(fptr, "%d,", stno) == 1;
  }

    // reads the gpa of the GPA from the global fptr File pointer
  // returns true if successful
  bool readGpa(double* gpa) 
  {
    return fscanf(fptr, "%lf\n", gpa) == 1;
  }
}