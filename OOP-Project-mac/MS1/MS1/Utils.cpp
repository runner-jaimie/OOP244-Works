/* Citation and Sources...
Final Project Milestone 1
Module: Utils
Filename: Utils.cpp
Version 1.0
Author: Jeongmi Lee
Student Id: 122442221
Revision History
-----------------------------------------------------------
Date Reason
20223/03/11 Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
I get Utils.h and Utils.cpp files from Prof.Fardad's lecture note.
-----------------------------------------------------------
 */

#include <iostream>
#include "Utils.h"

using namespace std;
namespace sdds
{
   Utils U;  //file scope
   int Utils::getInt()
    {
      int value{};
      bool done = false;
       
      do
      {
         done = false;
         cin >> value;
          
         if (!cin)
         {
            cin.clear();
            cout << "Invalid Integer, try again: ";
         }
         else
         {
            if (cin.get() != '\n')
            {
               cout << "Invalid Integer, try again: ";
            }
            else
            {
               done = true;
            }
         }
         if(!done)
         {
             cin.ignore(10000, '\n');
         }
      } while (!done);
       
      return value;
    }
    
   int Utils::getInt(int min, int max,const char* prompt)
    {
      int value{};
      if (prompt)
      {
          cout << prompt;
      }
      do
      {
         value = getInt();
      }
       while ((value < min || value > max) && cout << "[" << min << "<=value<="<< max << "], retry: " << prompt);
      return value;
    }

}
