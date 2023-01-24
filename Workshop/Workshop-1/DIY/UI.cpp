/***********************************************************************
// OOP244 Workshop 1 p2: GPA header file
//
// File  UI.cpp
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
#include <cstring>                            
#include "UI.h"
#include "GPAlist.h"

using namespace std;

namespace sdds
{
  // clear buffer
  void flushkeys() 
  {
    while (cin.get() != '\n')
      ;
  }

  // returns true if user enter y or Y // input function 
  bool yes()
  {
    char ch;
    bool returnValue = true;
    cin >> ch;
    flushkeys();
    if (ch == 'y' || ch == 'Y')
    {
      returnValue = false;
    }
    return returnValue;
  } 

  void displayUi()
  {
    char option;
    double gpa;
    bool done = false;
    bool exitProgram = false;
    
    cout << "Enter GPA query..." << endl;

    while (!done)
    {
      cout << "? ";
      cin >> option;
      
      if(option == '!')
      {
        cout << "Exit the program? (Y)es/(N)o: ";
        done = !yes();
      }
      else
      {
        cin >> gpa;
        flushkeys();
          
        if(option == '>' || option == '<' || option == '~') 
        {
          displayGpaWithOption(option, gpa);
        }
        else if (option != '>' && option != '<' && option != '~' && option != '!') 
        {
          cout << "Syntax error: ? [Op][value]<ENTER>" << endl;
          cout << "Op: [>,<,~,!]" << endl;
          cout << "value: GPA value" << endl;
          cout << endl;
        }
      }
    }
  }            
}
