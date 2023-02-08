#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include <iostream>
#include "Soccer.h"

using namespace std;

namespace sdds
{
    struct  Tournament
    {
    // Member variables(attributes)
        char* m_name;  //points to a dynamically allocated Cstring
        int m_num;     //size of the dynamically allocated array of soccer team. It should be more then zero.
        SoccerTeam* m_soccer = nullptr;   //pointer to the dynamically allocated array of soccerTeam
        
    // Constructor
        Tournament();
        Tournament(const char* name, int noOfteam,const SoccerTeam* soccer);
        ~Tournament();
        
    // Member functions(methods)
        void setTournament(const char* name, int noOfteam,const SoccerTeam* soccer);
        void setEmpty();
        bool isEmpty() const;
        Tournament& match(const SoccerTeam* ls);
        ostream& display() const;
    };

}

#endif /* Tournament_h */
