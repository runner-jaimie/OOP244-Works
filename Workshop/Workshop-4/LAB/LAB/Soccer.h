#ifndef SOCCER_H
#define SOCCER_H
#include <iostream>




namespace sdds
{
    const int MAX_FOUL = 4; //maximum number of fouls

    struct SoccerTeam
    {
    // Member variables(attributes)
        char m_teamName[41];// a statically allocated Cstring with size 41. Remember, nam
                            // maximum 40 characters long and 1 byte is for the null byte.
        int m_noFouls;//number of fouls, it can be zero or more but cannot be a negative
        double m_fines;//it can be equal to and more than zero.
        int m_golas;//can be zero or more
        
    // Constructor
        SoccerTeam();
        SoccerTeam(const char* tname, double fines, int foul);
        
    // Member functions(methods)
        void setTeam(const SoccerTeam& team);
        void setName(const char* tname);
        void setFine(double fines, int foul);
        void setEmpty();
        bool isEmpty() const;
        void calFines();
        int fouls() const;
        std::ostream& display() const;
    };

}


#endif
