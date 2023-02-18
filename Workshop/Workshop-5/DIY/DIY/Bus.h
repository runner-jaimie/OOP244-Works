/***********************************************************************
// OOP244 Workshop 5 Part2: Operators
// File Bus.h
// Version 1.0
// Date    2023/02/16
// Author Jeongmi Lee
// Description
// Tests the Bus module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef BUS_H
#define BUS_H

namespace sdds
{
    const double priceOfBusTicket = 125.34;
    
    class Bus
    {
        int m_numOfSeats;
        int m_numOfPassengers;
        void drawBus(int seats, int noOfPassengers, std::ostream& ostr) const;
        
    public:
        //Constructor
        Bus (int numOfSeats = 20, int numOfPassengers = 0);
        
        //Member function
        Bus& set(int numOfSeats, int numOfPassengers);
        void setOutOfService();
        std::istream& read(std::istream& istr = std::cin);
        std::ostream& display(std::ostream& ostr = std::cout) const;
        
        //Conversion
        operator bool() const;
        operator int() const;
        operator double() const;
        
        //Unary operator(prefix)
        bool operator--();
        bool operator++();
        
        //Unary operator(postfix)
        bool operator--(int value);
        bool operator++(int value);
        
        //Binary operator
        Bus& operator=(int value);
        Bus& operator+=(int value);
        Bus& operator+=(Bus& right);
        bool operator==(const Bus& right) const; // == 연산자는 operand값이 변하면 안된다.(!=, >, < )
        
        
    };
    //Helper binary operator overload (helper operator는 class 밖)
    int operator+(int left, const Bus& right);
    std::ostream& operator<<(std::ostream& ostr, const Bus& right);
    std::istream& operator>>(std::istream& istr, Bus& right);
}
#endif
