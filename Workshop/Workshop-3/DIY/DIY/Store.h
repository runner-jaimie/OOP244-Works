#ifndef STORE_H
#define STORE_H
#include "Toys.h"
#define MAX_NUM_TOYS 10
#define MAX_SNAME 31

namespace sdds
{

    //class Department does here
    class Store
    {
                
        char m_sName[MAX_SNAME + 1];// Store name, up to MAX_SNAME size
        int m_noOfToys;//Num of toys;
        int m_addToys;//Num of toys added 증가 시키기(index number)
        Toys m_toy[MAX_NUM_TOYS];// statically array of toys with size MAX_NUM_TOYS
        
        // Function
        public:
        void setStore(const char* sName, int no);
        void setToys(const char* tname, int sku, double price,int age);
        void display()const;
        void find(int sku);
        void setEmpty();
    };

}


#endif
