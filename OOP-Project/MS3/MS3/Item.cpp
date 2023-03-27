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
        return strcmp(m_sku, sku);
    }
    
//    ▶ 간단예시(strcmp)
//    char str1[] = “BlockDMask”;
//    char str2[] = “BlockDMask”;
//    strcmp(str1, str2);        // 문자열이 같으므로 0
//    strcmp(str1, BlockFMask”); // D < F 이므로 음수 반환
//    strcmp(str1, BlockAMask”); // D > A 이므로 양수 반환


    bool Item::operator>(const Item& right)
    {
        return strcmp(m_name, right.m_name) > 0;
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
        
        if(m_quantity < value)
        {
            m_quantity = 0;
            m_error = ERROR_POS_QTY;
        }
        return m_quantity;
    }
    
    //Conversion
    Item::operator bool() const
    {
        return !bool(m_error);
    }
    
    //Helper function
    double operator+=(double& left, const Item& right)
    {
        double totalPrice;
        totalPrice = right.cost() * right.quantity();
        totalPrice+=left;
        return totalPrice;
    }
    
    //Member function
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
        m_error = Error();
        return *this;
    }
    
    ostream& Item::write(ostream& ostr) const
    {
        if(POS_LIST)
        {
            size_t nameOfStr = strlen(m_name);
            if(nameOfStr > 20)
            {
                nameOfStr = 20;
            }
            if()
            
        }
    }
}
