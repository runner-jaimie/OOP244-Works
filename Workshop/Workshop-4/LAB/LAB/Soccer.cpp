#include <iostream>
#include <cstring>
#include "Soccer.h"

using namespace std;


namespace sdds
{
// Constructor
    SoccerTeam::SoccerTeam()
    {
        setEmpty();
    }

    SoccerTeam::SoccerTeam(const char* tname, double fines, int foul)
    {
        if(tname != nullptr && tname[0] !='\0' && fines >= 0 && foul >= 0)
        {
            m_golas = 0;
            setName(tname);
            setFine(fines, foul);
        }
        else
        {
            setEmpty();
        }
    }

// Function 1
    void SoccerTeam::setTeam(const SoccerTeam& team)
    {
        setName(team.m_teamName);
        setFine(team.m_fines, team.m_noFouls);
    }
    
// Function 2
    void SoccerTeam::setName(const char* tname)
    {
        if(tname != nullptr && tname[0] != '\0')
        {
            strcpy(m_teamName, tname);
        }
    }

// Function 3
    void SoccerTeam::setFine(double fines, int foul)
    {
        if(fines >= 0 && foul >= 0)
        {
            m_fines = fines;
            m_noFouls = foul;
        }
    }

// Function 4
    void SoccerTeam::setEmpty()
    {
        m_teamName[0] = '\0';
        m_noFouls = -1;
        m_fines = -1;
        m_golas = 0;
    }

// Function 5
    bool SoccerTeam::isEmpty() const
    {
        bool empty = false;
        if(m_teamName[0] != '\0' && m_fines >= 0 && m_noFouls >= 0)
        {
            empty = true;
        }
        return  empty;
    }

// Function 6
    void SoccerTeam::calFines()
    {
        m_fines *= 1.2;
    }

// Function 7
    int SoccerTeam::fouls() const
    {
        return m_noFouls;
    }

// Function 8 
    ostream& SoccerTeam::display() const
    {
        if(isEmpty())
        {
            cout.width(30); cout.fill(' '); cout.setf(ios::left);
            cout << m_teamName; cout.unsetf(ios::left);
            cout.width(6); cout.setf(ios::fixed);
            cout.precision(2); cout << m_fines;
            cout.width(6); cout << m_noFouls;
            cout.width(10); cout << m_golas;
            //cout.width(6); cout << m_fines;
            if(m_golas > 0)
            {
                cout <<  "w";
            }
            else{
                cout << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Invalid Team";
            
        }
        
        return cout;
    }
}
