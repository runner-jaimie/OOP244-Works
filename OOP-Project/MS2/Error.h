/* Citation and Sources...
Final Project Milestone 1
Module: Error
Filename: Error.h
Version 1.0
Author: Jeongmi Lee
Student Id: 122442221
Revision History
-----------------------------------------------------------
Date Reason
20223/03/20 Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
 */

#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H

namespace sdds
{
    class Error
    {
        char* m_errorMsg = nullptr;
        
    public:
        //Constructor
        Error();
        Error(const char* errorMsg);
        Error(const Error& source);
        Error& operator=(const Error& source);
        ~Error();
        
        //Mandatory Operation
        Error& operator=(const char* value); //Assignment to a C-string(error messege)
        operator bool()const; //Boolean type conversion
        Error& clear();
        
        //Display
        std::ostream& display(std::ostream& ostr = std::cout) const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Error& right);
}

#endif

