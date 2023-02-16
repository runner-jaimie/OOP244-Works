#ifndef EGGCARTON_H
#define EGGCARTON_H


namespace sdds
{
    // weight are in grams
    const int RegularEggWieght = 50;
    const int JumboEggWieght = 75;
    
    class EggCarton
    {
        int m_size;
        int m_numOfEggs;
        bool m_jumboSize;
        std::ostream& displayCarton(int size, int noOfEggs, bool jumbo, std::ostream& ostr)const;
        
        public:
        //Constructor
        EggCarton(int size=6, int noOfEggs=0, bool jumboSize=false);
        
        //Member function
        EggCarton& set(int size, int noOfEggs, bool jumboSize);
        void setBroken();
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& display(std::ostream& ostr = std::cout) const;
        
        
        //Conversion
        operator bool() const;
        operator int() const;
        operator double() const;
        
        //Unary operator
        EggCarton& operator--();
        EggCarton& operator++();
        EggCarton operator--(int);
        EggCarton operator++(int);
        
        //Binary operator
        EggCarton& operator=(int value);
        EggCarton& operator+=(int value);
        EggCarton& operator+=(EggCarton& right);
        bool operator==(const EggCarton& right) const;
         
    };

//Helper binary operator overload
int operator+(int left, const EggCarton& right);
std::ostream& operator<<(std::ostream& ostr, const EggCarton& right);
std::istream& operator>>(std::istream& istr, EggCarton& right);

}

#endif
