#ifndef TOYS_H
#define TOYS_H
#define MAX_TNAME 31

namespace sdds {

  //class Department does here
    class Toys
    {
        
        char m_tname[MAX_TNAME];// toy name, up to MAX_TNAME size
        int m_sku; //SKU number, maximum 8 digits long
        double m_price;//toy price
        int m_age;//toy according to age group
        bool m_onSale;// keep track, if toys are on sale or not
        
       public:
    // Function
        void addToys(const char* tname, int sku, double price,int age);
        int validSku(int sku);
        bool findToysSku(int sku);
        void isSale(bool sale);
        void calSale();
        void display()const;
        void emptyToys();
    };

}

#endif
