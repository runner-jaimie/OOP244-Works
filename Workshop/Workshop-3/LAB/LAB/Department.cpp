#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Department.h"

using namespace std;

namespace sdds {
    
// Function 1 ()
    void Department::updateName(const char* newname)
    {
        if(newname != nullptr && newname[0] !='\0')
        {
            delete [] m_deptName ; //Dynamic memory allocate 🍎 왜 지우고 메모리를 allocate 해주지??
            m_deptName = nullptr;
            m_deptName = new char[strlen(newname) + 1]; // Char라서 + 1
            strcpy(m_deptName, newname); // ✔️ string copy할때는 무조건 strcpy 함수 써야한다. 그냥 allocate 못한다.
        }
    }

// Function 2
    void Department::updateBudget(double change)
    {
        if(change > 0.0)
        {
            m_budgOfDept+= change;
        }
    }

// Function 3
    bool Department::addProject(Project& newproject)
    {
        bool check = false;
        int i;
        if(m_numOfCurProj == 0 && m_budgOfDept >= newproject.m_cost)
        {
            m_numOfCurProj++; // 🍎 이미 하나의 프로젝트가 있어서?? ++ 하고 시작하는 건가??
            m_deptProj = nullptr;
            m_deptProj = new Project[m_numOfCurProj];
            // 마지막 인덱스에 새로운 프로젝트 넣어야 해서
            m_deptProj[m_numOfCurProj-1] = newproject;
        }else
        {
            if(remainingBudget() >= newproject.m_cost)
            {
                m_numOfCurProj++;
                Project* new_m_deptProj; // 🍎
                new_m_deptProj = nullptr;
                new_m_deptProj = new Project[m_numOfCurProj]; // array가 작은 사이즈 만큼 돌아야 한다. 원래+1 더해 줘야 하는데 m_numOfCurProj를 하나 증가 하고 시작해서 + 1 안해준다. 
                for(i = 0; i < m_numOfCurProj -1; i++)
                {
                    new_m_deptProj[i] = m_deptProj[i];
                }
                // 마지막 인덱스에 새로운 값을 넣어준다.
                new_m_deptProj[m_numOfCurProj-1] = newproject;
                delete [] m_deptProj;
                m_deptProj = nullptr;
                m_deptProj = new_m_deptProj;
            }
            check = true;
        }
        return check;
    }

// Function 4
    void Department::createDepartment(const char* newname, Project& newproject, double change) {
        updateName(newname);
        addProject(newproject);
        updateBudget(change);
    }

// Function 5
    Project* Department::fetchProjects()const {
        return m_deptProj;
    }

// Function 6
    int Department::fetchNumProjects()const {
        return m_numOfCurProj;
    }

// Function 7
    double Department::fetchBudget()const {
        return m_budgOfDept;
    }

// Function 8
    char* Department::fetchName()const {
        return m_deptName;
    }

// Function 9 (dynamic memory allocate)
    double Department::totalexpenses() {
        int i;
        double totalExpenses = 0.0;
        for(i = 0; i < m_numOfCurProj; i++) {
            // ‼️ 꼭 기억 기존의 값을 계속 해서 더해 줄때 꼭 변수 선언하고 변수에 할당하기
            totalExpenses+= m_deptProj[i].m_cost;
        }
        return totalExpenses;
    }

// Function 10
    double Department:: remainingBudget() {
        //(✔️ 변수 - 함수 가능한 이유는 totalexpenses 함수는 리턴 값이 double이다. 그래서 연산이 가능하다.)
            return m_budgOfDept-totalexpenses();
    }

// Function 11
    void Department::clearDepartment() {
        delete [] m_deptProj;
        m_deptProj = nullptr;
        delete[] m_deptName;
        m_deptName = nullptr;
    }

    
//=================fully provided for students to display details of a project=======================
//===================================================================================================
    void display(const Project& project) {
        cout << "Project " << project.m_topic
            << " will cost a total of " << project.m_cost << " C$." << endl;
    }

    //fully provided for students to display details of a department
    void display(const Department& department) {
        Project* temp = department.fetchProjects();
        int projects = department.fetchNumProjects();
        cout << "Department " << department.fetchName() << " details:" << endl;
        cout << "Budget: " << department.fetchBudget()
            << " and the number of projects in progress is: " << projects << endl;
        cout << "Below are the details of the projects we are currently working on: " << endl;
        for (int i = 0; i < projects; i++) {
            display(temp[i]);
        }
    }

}
