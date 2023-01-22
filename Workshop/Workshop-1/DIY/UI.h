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

#ifndef SDDS_UI_H
#define SDDS_UI_H
/*
  while (!done)
  {
    cout << "Enter the movie genre to start the search: ";
    cin >> genre;
    flushkeys();
    displayMoviesWithGenre(genre);
    cout << "Do another search? (Y)es: ";
    done = !yes();
    cout << endl;
  } 
 */

namespace sdds 
{
  //Function
  void flushkeys();
  bool yes();
  void displayUi();
}

#endif