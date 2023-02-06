#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Store.h"

using namespace std;

namespace sdds
{
    
    void Store::setStore(const char* sName, int no)
    {
        if(strlen(sName) <= MAX_SNAME && sName != nullptr && no <= MAX_NUM_TOYS )
        {
            strcpy(m_sName, sName);
            m_noOfToys = no;
            m_addToys = 0;
            
        }
        else
        {
            setEmpty();
        }
    }
    
    void Store::setToys(const char* tname, int sku, double price,int age)
    {
        m_toy[m_addToys].addToys(tname, sku, price, age);
        m_addToys++;
    }
        
    void Store::find(int sku)
    {
        int i;
        for( i = 0; i < m_addToys; i++ )
        {
            if (m_toy[i].findToysSku(sku)) // findToysSku() 함수를 통해서 sku 번호를 찾았다면 찾은 sku가 onsale 이라는 것이다.
            {
                m_toy[i].isSale(true);
                m_toy[i].calSale();
                
            }
        }
    }

    void Store::setEmpty()
    {
        m_sName[0] = {0};
        m_noOfToys = {0};
        m_addToys = {0};
        m_toy[0].emptyToys(); // toys empty 하는 함수 만든 이유는
    }

    void Store::display()const
    {
        if(strlen(m_sName) <= MAX_SNAME && m_sName[0] != '\0' && m_noOfToys <= MAX_NUM_TOYS)
        {
            cout.width(60); cout.fill('*');
            cout << "*" <<  endl;
            cout << m_sName << endl;
            cout.width(60); cout.fill('*');
            cout << "*" <<  endl;
            cout << "list of the toys" <<  endl;
            cout.width(30); cout.fill(' '); cout << "SKU";
            cout.width(10); cout.fill(' '); cout << "Age";
            cout.width(11); cout.fill(' '); cout << "Price";
            cout.width(10); cout.fill(' '); cout << "Sale" << endl;
            
            int i;
            for( i = 0; i < m_addToys; i++)
            {
                cout.width(0);
                cout << "Toy[" << i+1 << "] :";
                m_toy[i].display();
            }

        }
        else
        {
            cout << "Invalid Store" << endl;
        }
    }

}
