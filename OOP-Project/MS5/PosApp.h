/* Citation and Sources...
Final Project Milestone 1
Module: PosApp
Filename: PosApp.h
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

#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_
#include "Item.h"

namespace sdds
{
    class PosApp
    {
        char m_fileName[128 + 1]{};
        Item* Iptr[MAX_NO_ITEMS]{};
        int nptr = 0; // pointer count 
        char actionTitle[40 + 1]{};

        
    public:
        //Constructor
        PosApp();
        PosApp(const char* fileName);
        PosApp(const PosApp& source) = delete;
        PosApp& operator=(const PosApp& source) = delete;
        ~PosApp();
        
        //Member function
        int menu();
        void addItem();
        void removeItem();
        void stockItem();
        void listItems();
        void POS();
        void saveRecs();
        void loadRecs();
        void printTitle();
        void setEmpty();
        void sort(Item* Iptr[MAX_NO_ITEMS], int nptr);
        void run();
        
        
    };
}

#endif
