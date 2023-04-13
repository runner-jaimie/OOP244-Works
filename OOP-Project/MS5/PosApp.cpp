/* Citation and Sources...
Final Project Milestone 1
Module: PosApp
Filename: PosApp.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "PosApp.h"
#include "Utils.h"
#include "Perishable.h"
#include "NonPerishable.h"
#include "Item.h"


using namespace std;

namespace sdds
{
    //Constructor
    PosApp::PosApp()
    {
        m_fileName[0] = '\0';
    }
    
    PosApp::PosApp(const char* fileName)
    {
        if(fileName[0] !='\0' && fileName != nullptr)//if(fileName)
                {
                    m_fileName[0] = '\0'; // 새로운 파일 이름 받아 올꺼라서 비워주기
                    strcpy(m_fileName, fileName);
                }
                else
                {
                    m_fileName[0] = '\0';
                }
    }
    
    PosApp::~PosApp()
    {
        nptr = 0;
        for (int i = 0; i < MAX_NO_ITEMS; i++)
        {
            delete Iptr[i];
        }
        
    }
    
    int PosApp::menu()
    {
        int sel = 0;
        cout << "The Sene-Store" << endl
             << "1- List items" << endl
             << "2- Add item" << endl
             << "3- Remove item" << endl
             << "4- Stock item" << endl
             << "5- POS" << endl
             << "0- exit program" << endl;
        sel = U.getInt(0, 5,"> ");
                switch (sel)
                    {
                    case 1:
                        listItems();
                      break;
                    case 2:
                        addItem();
                      break;
                    case 3:
                        cout.fill('.');
                        cout.width(77);
                        cout.setf(ios::left);
                        cout << ">>>> Remove Item" << endl;
                        removeItem();
                      break;
                    case 4:
                        cout.fill('.');
                        cout.width(77);
                        cout.setf(ios::left);
                        cout << ">>>> Select an item to stock" << endl;
                        stockItem();
                      break;
                    case 5:
                        cout.fill('.');
                        cout.width(77);
                        cout.setf(ios::left);
                        cout << ">>>> Starting Point of Sale" << endl;
                        POS();
                      break;
                    case 0:
                        saveRecs();
                        cout << "Goodbye!" << endl;
                      break;
                    }

         return sel;
    }
    
    void PosApp::listItems()
    {
        double sum{};
        strcpy(actionTitle, "Listing Items");
        printTitle();
        sort(Iptr, nptr);
        cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
        cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;
        for (int i = 0; i < nptr; i++)
        {
            cout.width(4); cout.fill(' ');
            cout.setf(ios::right);
            cout << i + 1 << " | ";
            cout.unsetf(ios::right);
            cout << Iptr[i]->displayType(POS_LIST) << endl;
            sum += (Iptr[i]->cost())*(Iptr[i]->quantity());
        }
        cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
        cout << "                              Total Asset: $   |       " << sum << "| " << endl;
        cout << "-----------------------------------------------^--------------^" << endl;
        cout << endl;
    }
    
    void PosApp::addItem()
    {
        strcpy(actionTitle, "Adding Item to the store");
        printTitle();
        
        if (nptr < MAX_NO_ITEMS)
        {
            char cha;
            bool ok = true;
            Item* temp = nullptr;

            cout << "Is the Item perishable? (Y)es/(N)o: ";
            cin.get(cha);
            cin.ignore(1, '\n');
            if (cha == 'Y' || cha == 'y')
            {
                temp = new Perishable;
            }
            else if (cha == 'N' || cha == 'n')
            {
                temp = new NonPerishable;
            }

            do
            {
                cin >> *temp; // Iptr[nptr].read(cin);
                if (!cin && !(*temp))
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << ", try again...\n";
                    ok = false;
                }
                else
                {
                    Iptr[nptr] = temp;
                    nptr++;
                    strcpy(actionTitle, "DONE!");
                    printTitle();
                }

            } while (!ok);
        }
        else
        {
            cout << "Inventory Full!";
        }
    }
    
    void PosApp::removeItem()
    {
        cout << "Running removeItem()" << endl;
    }
    
    void PosApp::stockItem()
    {
        cout << "Running stockItem()" << endl;
    }
    
    void PosApp::POS()
    {
        cout << "Running POS()" << endl;
    }
    
    void PosApp::saveRecs()
    {
        strcpy(actionTitle, "Saving Data");
        printTitle();
        ofstream output(m_fileName); // data filename 으로 ofstream instance 만들기 
        int i;
        for (i = 0; i < nptr; i++)
        {
            output << *Iptr[i] << endl;
        }
    }
    
    void PosApp::loadRecs()
    {
        strcpy(actionTitle, "Loading Items");
        printTitle();
        ifstream input(m_fileName);
        setEmpty(); // PosApp 비우기
        if (input)
        {
            char cha;
            
            while (input && nptr < MAX_NO_ITEMS)
            {
                cha = 0;
                input.get(cha);
                input.ignore(1, ',');
                if (cha == 'P')
                {
                    Iptr[nptr] = new Perishable;
                    input >> *Iptr[nptr]; // Iptr[nptr] 이건 arry 0번째라 address
                    nptr++;
                }
                else if(cha == 'N')
                {
                    Iptr[nptr] = new NonPerishable;
                    input >> *Iptr[nptr]; // extract the item from the input 
                    nptr++; // add one to the nptr
                }
                input.ignore(1, '\n');
            }
        }
        else
        {
            input.close();
        }
    }
    void PosApp::printTitle()
    {
        cout << ">>>> ";
        cout.width(72); cout.fill('.'); cout.setf(ios::left);
        cout << actionTitle; cout.unsetf(ios::left); cout << endl;
    }
    void PosApp::setEmpty()
    {
        int i;
        nptr = 0;
        for (i = 0; i < MAX_NO_ITEMS; i++)
        {
            delete Iptr[i];
            Iptr[i] = nullptr;
        }
    }
    //void PosApp::sort(Item* Iptr[MAX_NO_ITEMS], int nptr) // 역순 
    //{
    //    int i, j, minIdx;
    //    Item* temp;

    //    for (i = 0; i < nptr; i++)
    //    {
    //        minIdx = i;

    //        for (j = i + 1; j < nptr; j++)
    //        {
    //            if (*Iptr[j] > *Iptr[minIdx]) 
    //            {
    //                minIdx = j;
    //            }
    //        }

    //        if (minIdx != i)
    //        {
    //            temp = Iptr[i];
    //            Iptr[i] = Iptr[minIdx];
    //            Iptr[minIdx] = temp;
    //        }
    //    }
    //}

        void PosApp::sort(Item* Iptr[MAX_NO_ITEMS], int nptr)
    {
        int i, j, maxIdx;
        Item* temp;

        for (i = 0; i < nptr; i++)
        {
            maxIdx = i;

            for (j = i + 1; j < nptr; j++)
            {
                if (!(*Iptr[j] > *Iptr[maxIdx]))
                {
                    maxIdx = j;
                }
            }

            if (maxIdx != i)
            {
                temp = Iptr[i];
                Iptr[i] = Iptr[maxIdx];
                Iptr[maxIdx] = temp;
            }
        }
    }
    void PosApp::run()
    {
        //int sel;
        loadRecs();
        while(menu());
    }
    
}
