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

#ifndef ITEM_H
#define ITEM_H
#include "POS.h"
#include "PosIO.h"
#include "Error.h"

namespace sdds
{
    class Item : public PosIO
    {
        char m_sku[MAX_SKU_LEN + 1];
        char* m_name;
        double m_price;
        bool m_taxed;
        int m_quantity;
        
    protected:
        int m_diaplay;
        Error m_error; // class 가져오는 방법
        
    public:
        Item();
        Item(const Item& source);
        Item& operator=(const Item& source);
        
    //Member operator overloads
        bool operator==(const char* sku) const;
        bool operator>(const Item& right);
        int operator+=(int value);
        int operator-=(int value);
        
    //Conversion
        operator bool() const;
    
    //Member function
        void setEmpty();
        char itemType();
        Item& displayType(int displayType);
        double cost() const;
        int quantity() const;
        Item& clear();
        
    //Pure virtual function
        std::ostream& write(std::ostream& ostr = std::cout) const;
        std::istream& read(std::istream& istr = std::cin);
        std::ofstream& save(std::ofstream& ofst) const;
        std::ifstream& load(std::ifstream&  ifst);
        std::ostream& bprint(std::ostream& ostr = std::cout) const;
    };
    double operator+=(double left, const Item& right);
}
#endif
