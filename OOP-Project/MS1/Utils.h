/* Citation and Sources...
Final Project Milestone 1
Module: Utils
Filename: Utils.h
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
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds
{
   class Utils
    {
    public:
      int getInt();
      int getInt( int min, int max, const char* prompt = nullptr);
    };
    extern Utils U;// prototype for U in Utils.cpp 글로벌로 선언된것이라서 include 하면 다른 cpp 파일에서 U. 하고 접근 가능
}

#endif // !SDDS_UTILS_H
