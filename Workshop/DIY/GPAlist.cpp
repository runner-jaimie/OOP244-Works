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
#include <iostream>
#include "GPA.h"
#include "GPAlist.h"
#include "File.h"
#include "UI.h"


using namespace std;

namespace sdds 
{
  GPA gpas[86];

  //loads all the gpas into the global array of structures.

  bool gpaQuery(const char* filename) 
  {
    GPA studentGpa = {0}; // Temporary
    int gpaNum = 0;  // number of gpas read
    bool ok = true;
    if (openFile(filename)) 
    {
      while (ok && gpaNum < 86) 
      {
        ok = readName(studentGpa.name) &&
             readStno(&studentGpa.stno)&&
             readGpa(&studentGpa.gpa);
        
        if(ok) 
        {
          gpas[gpaNum++] = studentGpa;
        }

        // Check File data with cout
        //cout << "Data: " << gpas[gpaNum-1].name << gpas[gpaNum-1].stno<< gpas[gpaNum-1].gpa<< endl;
      }
      closeFile();

    // Call sorting function
    sortStudentStno(gpas, 86);

    // Call uimodule function
    displayUi();

    }
    return gpaNum == 86;
  }

  // Sorting by student number
  void sortStudentStno(struct GPA* studentStno, int n)
    {
      int i = 0, j = 0;
      GPA sortTempo = {0};

      for (i = 0; i < n - 1; i++)
      {
        for (j = 0; j < n - i - 1; j++)
        {
          if (studentStno[j].stno > studentStno[j + 1].stno)
          {
            sortTempo = studentStno[j];
            studentStno[j] = studentStno[j + 1];
            studentStno[j + 1] = sortTempo;
          }
        }
      }
    }

  bool checkOption(const struct GPA* studentGpa, const char option, double gpaValue)
  {
    int i = 0;
    bool found = false;
    
    if(option == '<')
    {
      if(studentGpa->gpa < gpaValue) 
      {
        found = true;
      }
    }
    if(option == '>')
    {
      if(studentGpa->gpa > gpaValue)
      {
        found = true;
      }
    }
    if(option == '~')
    {
      if(studentGpa->gpa >= gpaValue - 0.05 && studentGpa->gpa <= gpaValue + 0.05)
      {
        found = true;
      }
    }
    return found;
  }

  void displayGpa(const struct GPA* displayGpa)
  {
    cout.precision(1);
    cout << fixed << displayGpa->stno << ": " 
         << displayGpa->gpa << " (" 
         << displayGpa->name <<")" << endl;
  }

  void displayGpaWithOption(const char option, double gpa)
  {
    int i, j;
    for(i = 0, j = 1; i < 86; i++)
    {
      if(checkOption(&gpas[i], option, gpa))
      {
        cout << "[" << j++ << "] ";
        displayGpa(&gpas[i]);
      }
    }
  }
}