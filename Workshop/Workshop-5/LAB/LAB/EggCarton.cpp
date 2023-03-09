#include <iostream>
#include <cstring>
#include "EggCarton.h"

using namespace std;

namespace  sdds
{
    //Constructor
    EggCarton::EggCarton(int size, int noOfEggs, bool jumboSize)
    {
        if(size % 6 == 0  &&  size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size)
        {
            set(size, noOfEggs, jumboSize);
        }
        else
        {
            setBroken();
        }
    }
    //Member function
    EggCarton& EggCarton::set(int size, int noOfEggs, bool jumboSize)
    {
        m_size = size;
        m_numOfEggs = noOfEggs;
        m_jumboSize= jumboSize;
        
        return *this;
    }

    void EggCarton::setBroken()
    {
        m_size = -1;
        m_numOfEggs = -1;
        m_jumboSize = false;
    }

    istream& EggCarton::read(istream& istr)
    {
        char jumboFlag;
        int size;
        int noOfEggs;
        bool jumboSize = false;
        
        istr >> jumboFlag;
        istr.clear();
        istr.ignore(100, ',');
        
        if(jumboFlag == 'j')
        {
            jumboSize = true;
        }
        
        istr >> size;
        istr.clear();
        istr.ignore(100, ',');
        
        istr >> noOfEggs;
        istr.clear();
        istr.ignore(100, '\n');
        
        if(size % 6 == 0  &&  size >= 6 && size <= 36 && noOfEggs >= 0 && noOfEggs <= size)
        {
            set(size, noOfEggs, jumboSize);
        }
        else
        {
            setBroken();
        }
        
        return istr;
        
    }

    ostream& EggCarton::display(ostream& ostr) const
    {  // operator로 조건문에 true, false 체크 할 수 있다. current object 라서 *this 씀
        return (bool(*this)) ? displayCarton(m_size, m_numOfEggs, m_jumboSize, ostr) : cout << "Broken Egg Carton!" << endl;
    }

    ostream& EggCarton::displayCarton(int size, int noOfEggs, bool jumbo, ostream& ostr)const
    {
      int cartonWidth = size == 6 ? 3 : 6;
      for(int i = 0; i < size; i++)
      {
         ostr << ((i % cartonWidth) ? '|' : '[') << ((i < noOfEggs) ? (jumbo ? 'O' : 'o') : ' ');
         ((i + 1) % cartonWidth == 0) && ostr << ']' << endl;
      }
      return ostr;
    }

    //Conversion
    EggCarton::operator bool() const
    {
        // object(EggCarton)의 값이 유효 하면 ture (is not broken)
        bool check = false;
        if(m_size > 0)
        {
            check = true;
        }
        return check;
    }

    EggCarton::operator int() const
    {
        return (bool(*this)) ? m_numOfEggs : -1;
    }

    EggCarton::operator double() const
    {
        double eggWieght;
        if(m_jumboSize)
        {
            eggWieght = JumboEggWieght / 1000.0;
        }
        else
        {
            eggWieght = RegularEggWieght / 1000.0;
        }
        return(bool(*this)) ?  m_numOfEggs * eggWieght : -1.0;
    }

    //Unary operator
    //Prefix
    EggCarton& EggCarton::operator--()
    {
        if(m_numOfEggs > 0 && *this)
        {
            m_numOfEggs -= 1;
        }
       
        return *this;
    }

    EggCarton& EggCarton::operator++()
    {
        if(*this)
        {
            m_numOfEggs += 1;
        }
        else if(m_numOfEggs > m_size)
        {
            setBroken();
        }
        return *this;
    }
    
    //Postfix
    //postfix는 일단 리턴을 해준 다음에 값을 바꿔줘야 하기 때문에 temp로 현재 값을 저장하고 temp를 리턴 하는데 자기 자신은 -- 해준다.
    EggCarton EggCarton::operator--(int) // 이거 왜워야함 pre인지 post인지 구분하기 위해서 파리미터에 더미로 아무거나 들어간다.
    {
        EggCarton old(m_size, m_numOfEggs); // temp로 현재값 저장
        --(*this); // 자기 자신 --
        return old; // temp 리턴
    }

    EggCarton EggCarton::operator++(int)
    {
        EggCarton old(m_size, m_numOfEggs);
        ++(*this);
        return old;
    }

    //Binary operator
    EggCarton& EggCarton::operator=(int value)
    {
        if(value  > m_size)
        {
            setBroken();
        }
        else
        {
            m_numOfEggs = value;
        }
        return *this;
    }
    EggCarton& EggCarton::operator+=(int value)
    {
        if(m_numOfEggs + value > m_size)
        {
            setBroken();
        }
        else
        {
            m_numOfEggs += value;
        }
        return *this;
    }
    EggCarton& EggCarton::operator+=(EggCarton& right)
    {
        if(*this )
        {
            if(m_size - m_numOfEggs < right.m_numOfEggs)
            {
                right.m_numOfEggs -= m_size - m_numOfEggs;
                // m_numOfEggs = m_numOfEggs + (m_size - m_numOfEggs)
                m_numOfEggs = m_size;
            }
            else
            {
                m_numOfEggs+=right.m_numOfEggs;
                right.m_numOfEggs = 0;
            }
        }
        return *this;
    }
    bool EggCarton::operator==(const EggCarton& right) const
    {
        // && 연산자를 쓰면 bool을 return 한다.
        // return true double conversion을 이용해서 비교 그냥 변수로 비교 할수 없음 
        return double(*this) - double(right) <= 0.001 && double(*this) - double(right) >= -0.001;
        
    }

    //Helper binary operator overload
    int operator+(int left, const EggCarton& right)
    {
        return bool(right)? int(right)+left : left;
    }

    ostream& operator<<(ostream& ostr, const EggCarton& right) // cout 대신 ostr을 쓴다.
    {
        return right.display(ostr); // display the EggCarton and return ostr.
    }

    istream& operator>>(istream& istr, EggCarton& right) // 입력 받을떄는 const를 하면 안된다. 
    {
        return right.read(istr);
    }
};
