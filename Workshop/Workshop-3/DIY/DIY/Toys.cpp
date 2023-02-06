#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Toys.h"

using namespace std;

namespace sdds {

    void Toys::addToys(const char* tname, int sku, double price,int age)
    {
        
        int retunVal = validSku(sku);
        if(tname != nullptr && tname[0] !='\0' && retunVal == 8 && price >= 0 && age >= 0 )
        {
            strcpy(m_tname, tname);
            m_sku = sku;
            m_price = price;
            m_age = age;
            isSale(false);
        }
        else
        {
            emptyToys();
        }
    }
    
    int Toys::validSku(int sku)
    {
        string temp;
        temp = to_string(sku);
        return (int)temp.size();
         
    }

    bool Toys::findToysSku(int sku)
    {
//        bool find = false;
//        if(m_sku == sku)
//        {
//            find = true;
//        }
//        return find; ↓ 밑에 처럼 하면 코드를 줄일 수 있다.
        return m_sku == sku;
    }

    void Toys::isSale(bool sale)
    {
        m_onSale = sale;
    }

    void Toys::calSale()
    {
       m_price = m_price * 0.8;
    }
    
    void Toys::display()const
    {
        //int retunVal = validSku(m_sku);
        
        if(m_tname[0] !='\0' && m_price >= 0 && m_age >= 0 )
        {
            // setf (left or light)를 쓰면 꼭 unsetf 써야한다.
            cout.width(15); cout.fill(' '); cout.setf(ios::left);
            cout << m_tname; cout.unsetf(ios::left);
            cout.width(10); cout << m_sku;
            cout.width(6);  cout << m_age;
            cout.width(12); cout.setf(ios::fixed);
            cout.precision(2); cout << m_price;
            if (m_onSale == true)
            {
                cout.width(10);
                cout << "On Sale";
                cout << ' ';
            }
            else
            {
                cout.width(8); cout.fill(' ');
            }
        }
        else
        {
            cout << "Invalid Toy";
        }
        cout << endl;
    }
    
    void Toys::emptyToys()
    {
        m_tname[0] = {0};
        m_sku = 0;
        m_price = 0.0;
        m_age = 0;
        m_onSale = false;
    }

}
