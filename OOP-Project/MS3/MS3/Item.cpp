/* Citation and Sources...
Final Project Milestone 1
Module: Item
Filename: Item.h
Version 1.0
Author: Jeongmi Lee
Student Id: 122442221
Revision History
-----------------------------------------------------------
Date Reason
20223/03/29 Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "Item.h"

using namespace std;

namespace sdds
{
    Item::Item()
    {
        setEmpty();
    }
    
    Item::Item(const Item& source)
    {
        operator=(source); // 정확히 하는 기능에 대해서 질문 ??
    }
    
    Item& Item::operator=(const Item& source)
    {
        if(this !=&source)
        {
            delete [] m_name;
            m_name = nullptr;
            setEmpty();
            
            if(source.m_name)
            {
                m_name = new char[strlen(m_name + 1)];
                strcpy(m_name, source.m_name);
            }
        }
        return *this;
    }
    
    //Member operator overloads
    bool Item::operator==(const char* sku) const
    {
        return strcmp(m_sku, sku); // 값이 비교해서 같으면 true 리턴
    }
    
//    ▶ 간단예시(strcmp)
//    char str1[] = “BlockDMask”;
//    char str2[] = “BlockDMask”;
//    strcmp(str1, str2);        // 문자열이 같으므로 0
//    strcmp(str1, BlockFMask”); // D < F 이므로 음수 반환
//    strcmp(str1, BlockAMask”); // D > A 이므로 양수 반환

    bool Item::operator>(const Item& right)
    {
        return strcmp(m_name, right.m_name) > 0; // 알파벳 순서를 비교 a가 아스키 코드에서 가장 작은 수 그래서 앞에 value가 뒤에 value 보다 작으면 양수 값 리턴
    }
    
    int Item::operator+=(int value)
    {
        int sum;
        m_quantity+=value;
        sum = m_quantity;
        if(sum > MAX_STOCK_NUMBER)
        {
            m_quantity = MAX_STOCK_NUMBER;
            m_error = ERROR_POS_QTY;
        }
        return m_quantity;
    }
    
    int Item::operator-=(int value)
    {
        int sum;
        m_quantity-=value;
        sum = m_quantity;
        if( sum < value)
        {
            m_quantity = 0;
            m_error = ERROR_POS_QTY;
        }
        return m_quantity;
    }
    
    //Conversion
    Item::operator bool() const
    {
        return !bool(m_error); // m_error가 없으면 true 리턴
    }

    //Member function
    void Item::valid()
    {
        bool ok = true;
        
        if(strlen(m_sku) > MAX_SKU_LEN || strlen(m_sku) == 0 )
        {
            ok = false;
            m_error = ERROR_POS_SKU;
        }
        if(strlen(m_name) > MAX_NAME_LEN || strlen(m_name) == 0)
        {
            ok = false;
            m_error = ERROR_POS_NAME;
        }
        if(m_price < 0)
        {
            ok = false;
            m_error = ERROR_POS_PRICE;
        }
        if(m_taxed == 0) // boolean을 validation 할때 1 = ture 0 = false
        {
            ok = false;
            m_error = ERROR_POS_TAX;
        }
        if(m_quantity > MAX_STOCK_NUMBER )
        {
            ok = false;
            m_error = ERROR_POS_QTY;
        }
    }
    
    void Item::setEmpty()
    {
        m_sku[0] = {0};
        m_name = nullptr;
        m_price = 0.0;
        m_taxed = false;
        m_quantity = 0;
        m_diaplay = 0;
    }
    
    Item& Item::displayType(int displayType)
    {
        m_diaplay = displayType;
        return *this;
    }
    
    double Item::cost() const
    {
        double taxedPrice;
        if(!m_taxed)
        {
            taxedPrice = m_price * TAX;
        }
        else
        {
            taxedPrice = m_price;
        }
        return taxedPrice;
    }
    
    int Item::quantity() const
    {
        return m_quantity;
    }
    
    Item& Item::clear()
    {
        m_error.clear();
        return *this;
    }
    
    ostream& Item::write(ostream& ostr) const
    {
//        if(POS_LIST)
//        {
//
//            if(nameOfStr > 20)
//            {
//                nameOfStr = 20;
//            }
//            // if()
//            // {
//            //   // name 이름 받아와서 dynamic allocate 해주고 글자수만큼 m_name에 copy해줘야 할껄????
//            // }
//
//        }
        return ostr;
    }
    istream& Item::read(istream& istr) //1
    {
        bool ok = true;
        char tempSku[100]={0};
        char tempName[100]={0};
        
        if(!m_error)
        {
            m_error.clear();
            setEmpty();
        }
        cout << "Sku" <<endl;
        
        do // validation한 값이 들어 올때까지
        {
            tempSku[0] = '\0';
            ok = true;
            cout << "> ";
            istr.getline(tempSku,100,'\n'); // char는 바로 istr로 받아오지 못한다. temp에 저장한후 strcpy에 값을 복사 해줘야 한다.
            if(!istr || strlen(tempSku) > MAX_SKU_LEN || strlen(tempSku) == 0 )// istr이 내가 입력한 데이타 타입을 확인해준다.
            {
                istr.ignore(1000, '\n');
                istr.clear();
                ok = false;
                cout << ERROR_POS_SKU << endl;
            }
            else
            {
                strcpy(m_sku,tempSku);
                ok = true;
            }
        }
        while(!ok);
        
        cout << "Name" << endl;
        do
        {
            tempName[0] = '\0';
            ok = true;
            cout << "> ";
            istr.getline(tempName,41,'\n') ;
            if(!istr || (strlen(tempName) > MAX_NAME_LEN || strlen(tempName) == 0))
            {
                istr.ignore(1000, '\n');
                istr.clear();
                ok = false;
                m_error = ERROR_POS_NAME;
                cout << m_error << endl;
            }
            else
            {
                if(m_name)
                {
                    delete[] m_name;
                    m_name = nullptr;
                }
                m_name = new char[strlen(tempName) + 1];
                strcpy(m_name,tempName);
                ok = true;
            }
        }
        while(!ok);
        cout << "Price" << endl;
        do
        {
            //istr.ignore();
            ok = true;
            cout << "> ";
            istr >> m_price;
            if(!istr || m_price < 0)
            {
                istr.ignore(1000, '\n');
                istr.clear();
                ok = false;
                cout << ERROR_POS_PRICE << endl;
            }
        }
        while(!ok);
        
        cout << "Taxed?" << endl;
        do
        {
            istr.ignore();
            ok = true;
            cout << "> ";
            istr >> m_taxed;
            if(!istr || m_taxed == 0)
            {
                istr.ignore(1000, '\n');
                istr.clear();
                ok = false;
                m_error = ERROR_POS_TAX;
                cout << m_error << endl;
            }
        }
        while(!ok);
        
        cout << "Quantity" << endl;
       do
       {
           istr.ignore();
           ok = true;
           cout << "> ";
           istr >> m_quantity;
           if(!istr || m_quantity > MAX_STOCK_NUMBER)
           {
               istr.ignore();
               istr.clear();
               ok = false;
               m_error = ERROR_POS_QTY;
               cout << m_error << endl;
           }
       }
        while(!ok);
      return istr;
    }
    
    
    
    
    ofstream& Item::save(ofstream& ofst) const
    {
      return ofst;
    }
    
    ifstream& Item::load(ifstream&  ifst) //2
    {
        m_error.clear(); // error status clear 해준다
        char tempSku[100]={0};
        char tempName[100]={0};
        
        tempSku[0] = '\0'; // array 초기화
        ifst.getline(tempSku, MAX_SKU_LEN + 1, ',');
        if(!ifst) //  파일을 리딩할때 ifstream 값이 오류 인지 확인하기
        {
            ifst.clear(); // 보통 클리어가 이글노얼 앞에 붇는다.
            ifst.ignore(1000, ','); // ignore 줄때 getline 이랑 같은 delemination 줘야한다.
        }
        else
        {
            
        }
        
        
        
      return ifst;
    }
    
    ostream& Item::bprint(ostream& ostr) const
    {
      return ostr;
    }
    
    //Helper function
    double operator+=(double& left, const Item& right)
    {
        double totalPrice;
        totalPrice = right.cost() * right.quantity();
        totalPrice+=left;
        return totalPrice;
    }
}
