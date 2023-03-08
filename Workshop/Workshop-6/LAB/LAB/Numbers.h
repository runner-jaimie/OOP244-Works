#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>

namespace sdds
{
    class Numbers
    {
        //Member data
        double* m_collection{};
        char m_fileName[255 + 1]{};
        int m_collectionSize{};
        bool m_originalFlag=false; // 로드할때만 true
        bool m_addedFlag=false; // 숫자가 더해지면 true
        
        //Member function
        unsigned int countLines(const char* filename);
        void sort(double* collectionPtr, unsigned int size);
        void setEmpty();
        bool load();
        void save();
        double max() const;
        double min() const;
        double average() const;

    public:
        //Constructor
        Numbers();
        Numbers(const char* fileName);
        Numbers(const Numbers& N);
        Numbers& operator=(const Numbers& N);
        ~Numbers();
        void sort();
        
        //Conversion
        operator bool() const;
        
        //Binary operator
        Numbers& operator+=(const double value);
        
        //Display
        std::ostream& display(std::ostream& ostr = std::cout) const;
        
        
    };
    
    //Helper function binary operator overload
    std::ostream& operator<<(std::ostream& ostr, const Numbers& Ro);
    std::istream& operator>>(std::istream& istr, Numbers& Ro);
}
#endif // !SDDS_NUMBERS_H_

