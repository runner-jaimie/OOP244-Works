#include <iostream>
#include <cstring>
#include "Tournament.h"

using namespace std;

namespace sdds
{
// Constructor
    Tournament::Tournament()
    {
        setEmpty();
    }

    Tournament::Tournament(const char* name, int noOfteam,const SoccerTeam* soccer)
    {
        setTournament(name, noOfteam, soccer);
    }

    Tournament::~Tournament()
    {
        delete [] m_soccer;
        delete [] m_name;
        setEmpty();
       
    }

// Function 1
    void Tournament::setTournament(const char* name, int noOfteam, const SoccerTeam* soccer)
    {
        int i;
        if(name != nullptr && name[0] !='\0' && noOfteam >= 0)
        {
            m_num = noOfteam;
            m_name = nullptr;
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
            m_soccer = new SoccerTeam[m_num];
            for(i = 0; i < m_num; i++)
            {
                m_soccer[i] = soccer[i];
            }
        }
        else
        {
            setEmpty();
        }
    }

// Function 2
    void Tournament::setEmpty()
    {
        m_soccer = nullptr;
        m_name = nullptr;
        m_num = 0;
    }

// Function 3
    bool Tournament::isEmpty() const
    {
        bool empty = false;
        if(m_name != nullptr && m_name[0] != '\0' && m_soccer != nullptr && m_num > 0)
        {
            empty = true;
        }
        return empty;
    }

// Function 4
    Tournament& Tournament::match(const SoccerTeam* ls)
    {
        for (int i = 0; i <1; i++)
        {
            if (m_soccer[i].fouls() < m_soccer[i + 1].fouls())
            {
                m_soccer[i + 1].m_noFouls *= 2;
                m_soccer[i + 1].calFines();
                m_soccer[i].m_golas++;
                
                if (m_soccer[i + 1].m_noFouls > MAX_FOUL)
                {
                    m_soccer[i + 1].m_noFouls = -1;

                }
            }
        }
          return *this;
    }

// Function 5
    ostream& Tournament::display() const
    {
        if(isEmpty())
        {
            cout << "Tournament name: " << m_name << endl;
            cout << "list of the teams" << endl;
            cout.width(45); cout.fill(' '); cout << "Fines";
            cout.width(10); cout.fill(' '); cout << "Fouls";
            cout.width(10); cout.fill(' '); cout << "Goals"<< endl;
            
            int i;
            for( i = 0; i < m_num; i++)
            {
               cout.width(0);
               cout << "Team[" << i+1 << "] :";
               m_soccer[i].display();
            }

        }
        else
        {
            cout << "Invalid Tournament";
        }
        
        return  cout;
    }

}
