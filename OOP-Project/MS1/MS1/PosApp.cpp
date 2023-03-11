#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "PosApp.h"
#include "Utils.h"

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
                    m_fileName[0] = '\0';
                    strcpy(m_fileName, fileName);
                }
                else
                {
                    m_fileName[0] = '\0';
                }
    }
    
    PosApp::~PosApp()
    {
        
    }
    
    int PosApp::menu()
    {
        int sel = U.getInt(0, 5,"> ");
        cout << "The Sene-Store" << endl
             << "1- List items" << endl
             << "2- Add item" << endl
             << "3- Remove item" << endl
             << "4- Stock item" << endl
             << "5- Point of Sale" << endl
             << "0- exit program" << endl;

                switch (sel)
                    {
                    case 1:
                        cout.fill('.');
                        cout.width(77);
                        cout.setf(ios::left);
                        cout << ">>>> Listing Items" << endl;
                        listItems();
                      break;
                    case 2:
                        cout.fill('.');
                        cout.width(77);
                        cout.setf(ios::left);
                        cout << ">>>> Adding Item to the store" << endl;
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
                        cout.fill('.');
                        cout.width(77);
                        cout.setf(ios::left);
                        cout << ">>>> Saving Data" << endl;
                        saveRecs();
                        cout << "Goodbye!" << endl;
                      break;
                    }

         return sel;
    }
    
    void PosApp::listItems()
    {
        cout << "Running listItems()" << endl;
    }
    
    void PosApp::addItem()
    {
        cout << "Running addItem()" << endl;
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
        cout << "Saving data in " << m_fileName << endl;
    }
    
    void PosApp::loadRecs()
    {
        cout << "Loading data from " << m_fileName << endl;
    }
    
    void PosApp::run()
    {
        //int sel;
        cout.fill('.');
        cout.width(77);
        cout.setf(ios::left);
        cout << ">>>> Loading Items" << endl;
        loadRecs();
        while(menu());
    }
    
}
