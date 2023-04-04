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
    
    Item& Item::operator=(const Item& source) // 여기서 모든값을 = operator를 통해서 assign 해줘야 한다.
    {
        if(this !=&source) //Prevnet self copy 여기서 this에 무엇이 있나??
        {
            delete [] m_name;
            m_name = nullptr;
            setEmpty();
            if(source.m_name)
            {
                strcpy(m_sku, source.m_sku);
                m_name = new char[strlen(source.m_name + 1)];
                strcpy(m_name, source.m_name);
                m_price = source.m_price;
                m_taxed = source.m_taxed;
                m_quantity = source.m_quantity;
            }
            
        }
        return *this;
    }
    
    //Member operator overloads
    bool Item::operator==(const char* sku) const
    {
        return !strcmp(m_sku, sku); // 값이 비교해서 같으면 true 리턴
    }
    
//    ▶ 간단예시(strcmp)
//    char str1[] = “BlockDMask”;
//    char str2[] = “BlockDMask”;
//    strcmp(str1, str2);        // 문자열이 같으므로 0
//    strcmp(str1, BlockFMask”); // D < F 이므로 음수 반환
//    strcmp(str1, BlockAMask”); // D > A 이므로 양수 반환

    bool Item::operator>(const Item& right) const
    {
        return strcmp(m_name, right.m_name) > 0; // 알파벳 순서를 비교 a가 아스키 코드에서 가장 작은 수 그래서 앞에 value가 뒤에 value 보다 작으면 양수 값 리턴
    }
    
    int Item::operator+=(int value)
    {
        int sum;
        sum = m_quantity += value;
        //sum = m_quantity;
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
        sum = m_quantity -= value;
        //sum = m_quantity;
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
    bool Item::valid(char* sku, char* name, double price, bool taxed, int quantity)
    {
        bool ok = true;
        
        if(strlen(sku) >= MAX_SKU_LEN || strlen(sku) == 0 )
        {
            ok = false;
            m_error = ERROR_POS_SKU;
        }
        
        if(ok && (strlen(name) > MAX_NAME_LEN || strlen(name) == 0)) //m_name 이 있는지 먼저 체크 해야 m_name의 length를 체크할 수 있다.
        {
            ok = false;
            m_error = ERROR_POS_NAME;
        }
        if(ok && price < 0)
        {
            ok = false;
            m_error = ERROR_POS_PRICE;
        }
        if(ok && taxed != 0 && taxed != 1) // boolean을 validation 할때 1 = ture 0 = false
        {
            ok = false;
            m_error = ERROR_POS_TAX;
        }
        if(ok && (quantity > MAX_STOCK_NUMBER || quantity < 1) )
        {
            ok = false;
            m_error = ERROR_POS_QTY;
        }
        return ok;
    }
    
    void Item::setEmpty()
    {
        m_sku[0] = 0;
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
        if(m_taxed)
        {
            taxedPrice = m_price * (TAX + 1);
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
    
    //Write funciton
    ostream& Item::write(ostream& ostr) const
    {
        
        if(!m_error && m_name && m_diaplay == POS_LIST)
        {
            int numOfstr =0;
            char name[41]={0};
            numOfstr = strlen(m_name);
            
            ostr.width(MAX_SKU_LEN); ostr.fill(' '); ostr.setf(ios::left);
            ostr << m_sku; ostr.unsetf(ios::left); ostr << "|";
            if(numOfstr > 20)
            {
                numOfstr = 20;
            }
            strncpy(name, m_name, numOfstr);
            name[numOfstr] = 0;
            
            ostr.width(20); ostr.fill(' '); ostr.setf(ios::left);
            ostr << name; ostr.unsetf(ios::left); ostr << "|";
            ostr.width(7); ostr.fill(' '); ostr.setf(ios::right); ostr.setf(ios::fixed); ostr.precision(2);
            ostr << m_price; ostr.unsetf(ios::right); ostr << "|";
            
            if(m_taxed == true)
            {
                ostr << " " << "X" << " " << "|";
            }
            else
            {
                ostr << " " << " " << " " << "|";
            }
            ostr.width(4);ostr.fill(' ');ostr.setf(ios::right);
            ostr << m_quantity; ostr.unsetf(ios::right); ostr << "|";
    
            if(m_taxed == true)
            {
                ostr.width(9); ostr.fill(' '); ostr.setf(ios::right); ostr.precision(2);
                ostr << cost()*m_quantity; ostr.unsetf(ios::right); ostr << "|";
            }
            else
            {
                ostr.width(9); ostr.fill(' '); ostr.setf(ios::right); ostr.precision(2);
                ostr << cost()*m_quantity; ostr.unsetf(ios::right); ostr << "|";
            }
        }
        
        else if(m_name && m_diaplay == POS_FORM)
        {
            ostr.width(13); ostr.fill('='); ostr << "v" << endl;
            ostr.width(13); ostr.fill(' '); ostr.setf(ios::left);
            ostr << "Name:" << m_name; ostr.unsetf(ios::left); ostr << endl;
            ostr.width(13); ostr.fill(' '); ostr.setf(ios::left);
            ostr << "Sku:" << m_sku; ostr.unsetf(ios::left); ostr << endl;
            ostr.width(13); ostr.fill(' '); ostr.setf(ios::left);
            ostr << "Price:" << m_price; ostr.unsetf(ios::left); ostr << endl;
            if(m_taxed)
            {
                ostr.width(13); ostr.fill(' '); ostr.setf(ios::left);
                ostr << "Price + tax:" << cost(); ostr.unsetf(ios::left); ostr << endl;
            }
            else
            {
                ostr.width(13); ostr.fill(' '); ostr.setf(ios::left);
                ostr << "Price + tax:" << "N/A"; ostr.unsetf(ios::left);ostr << endl;
            }
            ostr.width(13); ostr.fill(' '); ostr.setf(ios::left);
            ostr << "Stock Qty:" << m_quantity; ostr.unsetf(ios::left); ostr << endl;
        }
        else if (m_error)
        {
            ostr << m_error;
        }
        return ostr;
    }
    
    //Read function
    istream& Item::read(istream& istr)
    {
        bool ok = true;
        char ch;
        char tempSku[100]={0};
        char tempName[100]={0};
        
        if(!m_error)
        {
            clear();
            setEmpty();
        }
        
        // Read Sku
        cout << "Sku" <<endl;
        do // validation한 값이 들어 올때까지
        {
            tempSku[0] = '\0';
            ok = true;
            cout << "> ";
            istr.getline(tempSku,100,'\n'); // char는 바로 istr로 받아오지 못한다. temp에 저장한후 strcpy에 값을 복사 해줘야 한다.
            if(!istr || strlen(tempSku) > MAX_SKU_LEN || strlen(tempSku) == 0 )// istr이 내가 입력한 데이타 타입을 확인해준다.
            {
                if(!istr)
                {
                    istr.clear();
                    istr.ignore(1000, '\n');
                }
                
                ok = false;
                cout << ERROR_POS_SKU << endl;
            }
            else
            {
                strcpy(m_sku, tempSku);
                ok = true;
            }
        }
        while(!ok);
        
        //Read Name
        cout << "Name" << endl;
        do
        {
            tempName[0] = '\0';
            ok = true;
            cout << "> ";
            istr.getline(tempName,41,'\n') ;
            if(!istr || (strlen(tempName) > MAX_NAME_LEN || strlen(tempName) == 0))
            {
                if(!istr)
                {
                    istr.clear();
                    istr.ignore(1000, '\n');
                }
                
                ok = false;
                cout << ERROR_POS_NAME << endl;
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
        
        //Read Price
        cout << "Price" << endl;
        do
        {
            ok = true;
            cout << "> ";
            istr >> m_price;
            if(!istr || m_price < 0)
            {
                if(!istr)
                {
                    istr.clear();
                }
                istr.ignore(1000, '\n');
                ok = false;
                cout << ERROR_POS_PRICE << endl;
            }
        }
        while(!ok);
        
        //Read Tax
        cout << "Taxed?" << endl;
        cout << "(Y)es/(N)o: ";
        do
        {
            ch = '\0';
            ok = true;
            istr.ignore(1000, '\n');
            istr >> ch;
            if(!istr || (ch!= 'Y' && ch !='y' && ch !='N' && ch != 'n') )
            {
                if(!istr)
                {
                    istr.clear();
                    istr.ignore(1000, '\n');
                }
                else
                {
                    cout << "Only 'y' and 'n' are acceptable: ";
                    ok = false;
                }
            }
            
        }
        while(!ok);
        
        //Read Quantity
        cout << "Quantity" << endl;
       do
       {
           ok = true;
           cout << "> ";
           //istr.ignore(1000, '\n');
           istr >> m_quantity;
           if(!istr || m_quantity >= MAX_STOCK_NUMBER + 1 || m_quantity == 0)
           {
               if(!istr)
               {
                   istr.clear();
                   //istr.ignore(1000, '\n');
               }
               istr.ignore(1000, '\n');
               ok = false;
               cout << ERROR_POS_QTY << endl;
           }
       }
        while(!ok);
      return istr;
    }
    
    //Save function
    ofstream& Item::save(ofstream& ofst) const
    {
        ofst << itemType()<< "," << m_sku << "," << m_name << ",";
        ofst.setf(ios::fixed); ofst.precision(2);
        ofst << m_price << "," << m_taxed << "," << m_quantity;
        
      return ofst;
    }
    
    //Load function
    ifstream& Item::load(ifstream&  ifst)
    {
        //ifst로 받아올 값 변수에 저장하기 위해서 tmep 변수 만들어줌
        char tempSku[100]={0};
        char tempName[100]={0};
        double tempPrice = 0;
        bool tempTaxed = false;
        int tempQuantity = 0;
        bool ok = true;
        clear(); // error status clear 해준다
       
        //Load Sku
        tempSku[0] = '\0'; // array 초기화
        ifst.getline(tempSku, MAX_SKU_LEN + 1, ',');
        if(!ifst) //  파일을 리딩할때 ifstream 값이 오류 인지 확인하기
        {
            ifst.clear(); // 보통 clear() ignore() 앞에 붙는다. 그리고 오류값 들어오면 clear
            ifst.ignore(1000, ','); // ignore 줄때 getline 이랑 같은 delemination 줘야한다. 그래서 여기는 , 로
            m_error = ERROR_POS_SKU;
            ok = false;
        }
        
        //Load Name
        if(ok)
        {
            tempName[0] = '\0';
            ifst.getline(tempName, MAX_NAME_LEN + 1, ',');
            if(!ifst)
            {
                ifst.clear();
                ifst.ignore(1000,',');
                m_error = ERROR_POS_NAME;
                ok = false;
            }
        }
        
        //Load Price
        if(ok)
        {
            ifst >> tempPrice;
            if(!ifst)
            {
                ifst.clear();
                ifst.ignore(100, ',');
                m_error = ERROR_POS_PRICE;
                ok = false;
            }
        }
            
        //Load Tax
        if(ok)
        {
            ifst.ignore(1, ',');
            ifst >> tempTaxed;
            if(!ifst)
            {
                ifst.clear();
                ifst.ignore(100, ',');
                m_error = ERROR_POS_TAX;
                ok = false;
            }
           
        }
        
        //Load Quantity
        if(ok)
        {
            ifst.ignore(1, ',');
            ifst >> tempQuantity;
            if(!ifst)
            {
                ifst.clear();
                ifst.ignore(100, ',');
                m_error = ERROR_POS_QTY;
                ok = false;
            }
        }
        
        valid(tempSku, tempName, tempPrice, tempTaxed, tempQuantity);
        
        if(*this)
        {
            strcpy(m_sku, tempSku);
            if(m_name)
            {
                delete[] m_name;
                m_name = nullptr;
            }
            m_name = new char[strlen(tempName) + 1];
            strcpy(m_name, tempName);
            m_price = tempPrice;
            m_taxed = tempTaxed;
            m_quantity = tempQuantity;
        }
        
      return ifst;
    }
    
    ostream& Item::bprint(ostream& ostr) const
    {
        size_t numOfstr = strlen(m_name);
        char name[41]={0};
        if(numOfstr > 20)
        {
            numOfstr = 20;
        }
        strncpy(name, m_name, numOfstr);
        name[numOfstr] = 0;
        
        ostr << "|";
        ostr.width(20); ostr.fill(' '); ostr.setf(ios::left);
        ostr << name; ostr.unsetf(ios::left); ostr << "|";
        
        ostr.width(7); ostr.fill(' '); ostr.setf(ios::right);
        ostr.setf(ios::fixed); ostr.precision(2);
        ostr << cost(); ostr.unsetf(ios::right); ostr << "|";
        if(m_taxed == true)
        {
            ostr << "  " << "T" << "  " << "|";
        }
        else
        {
            ostr << "  " << " " << "  " << "|";
        }
        ostr << endl;
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
