#ifndef SDDS_POSAPP_H_
#define SDDS_POSAPP_H_

namespace sdds
{
    class PosApp
    {
        char m_fileName[255 + 1]{};
        
    public:
        //Constructor
        PosApp();
        PosApp(const char* fileName);
        PosApp(const PosApp& source) = delete;
        PosApp& operator=(const PosApp& source) = delete;
        ~PosApp();
        
        //Member function
        int menu();
        void addItem();
        void removeItem();
        void stockItem();
        void listItems();
        void POS();
        void saveRecs();
        void loadRecs();
        void run();
        
        
    };
}

#endif
