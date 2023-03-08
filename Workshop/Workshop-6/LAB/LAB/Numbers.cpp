#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "Numbers.h"


using namespace std;

namespace sdds
{
    void Numbers::sort(double* nums, unsigned int size)
    {
      unsigned int i, j;
      double temp;
      for(i = size - 1; size && i > 0; i--)
      {
         for(j = 0; j < i; j++)
         {
            if(nums[j] > nums[j + 1])
            {
               temp = nums[j];
               nums[j] = nums[j + 1];
               nums[j + 1] = temp;
            }
         }
      }
    }

    unsigned int Numbers::countLines(const char* filename)
    { /**/
      unsigned int lines = 0u;
      ifstream nums(filename); // create instance for ifstream
        
      while(nums) // ‼️ nums는 ifstream의 class 인스턴스
      {
         lines += (nums.get() == '\n'); // == (비교 연산자)는 true, false를 리턴 (1 또는 0) 뉴라인이면 1을 리턴하고 더하기 때문에 우리가 라인의 수를 알 수 있다.
      }
      return lines;
    }
    
    //Private member function
    void Numbers::setEmpty()
    {
        m_collection = nullptr;
        m_fileName[0] = '\0'; // 어레이 초기화 할때 0번째 초기화 하면 된다.
        m_collectionSize = 0;
        m_originalFlag = false;
        m_addedFlag = false;
    }
    
    bool Numbers::load()
    {
        bool flag = false;
        int i = 0;
        delete [] m_collection;
        int numOfLines;
        numOfLines = countLines(m_fileName);
        
        if(numOfLines > 0)
        {
            m_collection = nullptr;
            m_collection = new double[numOfLines];
            
            ifstream fileIn(m_fileName); // create an instance of ifstream
            while(fileIn && i < numOfLines) // 파일이 유효할때 까지 계속 돌아서 m_collection에 넣어주는 기능
            {
                fileIn >> m_collection[i];
                i++;
            }
            if(numOfLines != i) // do not match
            {
                setEmpty();
            }
            else
            {
                m_collectionSize = i;
                m_originalFlag = true;
                flag = true;
            }
        }
        return flag;
    }
    
    void Numbers::save()
    {
        if(m_originalFlag && m_addedFlag)
        {
            ofstream fileOut(m_fileName);
            fileOut << fixed;
            fileOut.precision(2);
            for(int i = 0; i < m_collectionSize; i++)
            {
                fileOut << m_collection[i] << endl;
            }
            //fileOut.close();
        }
        
    }
    
    double Numbers::max() const
    {
        int i;
        double max = m_collection[0];
        for(i = 1; i < m_collectionSize; i++)
        {
            if(max < m_collection[i])
            {
                max = m_collection[i];
            }
        }
        return max;
    }
    
    double Numbers::min() const
    {
        int i;
        double min = m_collection[0];
        for(i = 1; i < m_collectionSize; i++) // for문 1부터 돌아도 된다 min, max 구할때
        {
            if(min > m_collection[i])
            {
                min = m_collection[i];
            }
        }
        return min;
    }
    
    double Numbers::average() const
    {
        int i;
        double sum = 0.0;
        for(i = 0; i < m_collectionSize; i++)
        {
            sum+=m_collection[i];
        }
        return sum/m_collectionSize;
    }
    
    //Constructor
    Numbers::Numbers()
    {
        setEmpty();
    }
    
    Numbers::Numbers(const char* fileName) // char fileName 하면 char 한글자만 받는 것이다. 그래서 char*로 받아야 어레이로 받는다.
    {
        if(fileName)
        {
            strcpy(m_fileName, fileName);
            load();
        }
    }
    
    //Rule of three
    //Copy constructor
    Numbers::Numbers(const Numbers& N)
    {
        //First set to safe empty state.
        setEmpty();
        operator=(N);
    }
    
    //Copy Assignment
    Numbers& Numbers::operator=(const Numbers& N)
    {
        if(this !=&N) //Prevnet self copy
        {
            save();
            delete[] m_collection;
            setEmpty();
            //m_collection = nullptr;
            if(N.m_collection)
            {
                m_originalFlag = false;
                m_collectionSize = N.m_collectionSize; // update collectionSize
                strcpy(m_fileName, N.m_fileName);
                m_collection = new double[N.m_collectionSize];
                for(int i=0; i < N.m_collectionSize; i++)
                {
                    m_collection[i] = N.m_collection[i]; // copy all the double value
                }
            }
            
        }
        return *this; // return the reference of the current object.
    }
    
    //Destructor
    Numbers::~Numbers()
    {
        save();
        delete [] m_collection;
        m_collection = nullptr;
    }
    
    void Numbers::sort()
    {
        sort(m_collection, m_collectionSize); // member 함수는 member data에 접근 가능
    }
    
    //Conversion
    Numbers::operator bool() const
    {
        bool check = false;
        if(m_collection != nullptr)
        {
            check = true;
        }
        return check;
    }
    
    //Binary operator
    Numbers& Numbers::operator+=(const double value)
    {
        if(*this)
        {
            int i;
            double* newData = nullptr;
            newData = new double [m_collectionSize + 1]; // 사이즈 선언
            for(i = 0; i < m_collectionSize; i++)
            {
                newData[i] = m_collection[i];
            }
            newData[m_collectionSize] = value; // 마지막 인덱스
            m_collectionSize++; // 늘어난 사이즈 기록
            delete [] m_collection;
            m_collection = nullptr;
            m_collection = newData;
            m_addedFlag = true;
        }
        return  *this;
    }
    
    //Display
    ostream& Numbers::display(ostream& ostr) const
    {
        if(*this)
        {
            ostr << fixed;
            ostr.precision(2);
            if(!m_originalFlag)
            {
                ostr << "Copy of ";
            }
            ostr << m_fileName << endl;
            int i;
            for(i = 0; i < m_collectionSize; i++)
            {
                ostr << m_collection[i];
                if(i < m_collectionSize - 1)
                {
                    ostr << ", ";
                }
                
            }
            ostr << endl;
            ostr.fill('-');
            ostr.width(76);
            ostr << ' ';
            ostr << "\nTotal of " << m_collectionSize <<" number(s),"
                 << " Largest: " << max() << ","
                 << " Smallest: " << min() << ","
                 << " Average: " << average() << endl;
            ostr.fill('=');
            ostr.width(76);
            ostr << ' ';
        }
        else
        {
            ostr << "Empty list";
        }
        
        return ostr;
    }
    
    //Helper function binary operator overload
    ostream& operator<<(ostream& ostr, const Numbers& Ro)
    {
        return Ro.display(ostr);
    }
    
    istream& operator>>(istream& istr, Numbers& Ro)
    {
        double tempDouble; // file 받아올 변수
        istr >> tempDouble; // cin 사용자 인풋 받음
        Ro += tempDouble; // 받은 파일을 Number 클래스 인스턴스인 Ro에 더해준다. 전해주는 이유가 Binary operator로 이미 구현을 했기 때문에
        
        return istr;
    }
}
