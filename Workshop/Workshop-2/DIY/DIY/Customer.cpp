#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "Customer.h"
#include "Tools.h"

namespace sdds {

// complete

    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }

    // complete

    void EmptyRecord(Customers& c_rec) {
        struct Customers empty = {{0}};
        c_rec = empty;
    }

    void EmptyRecord(CustomersRecord& t_rec) {
        struct CustomersRecord empty = {nullptr, 0};
        t_rec = empty;
    }

    bool read(Customers& rec) {
        
        bool check = false;
        cout << " Enter User name: ";
        read(rec.user_name, 21); // function for getting user name and count user's name length
        if( rec.user_name[0] !='\0') { // checking user name is not empty and if it is true get the other user's information.
            
            cout << " Enter likes_count: ";
            cin >> rec.likes_count;
            cout << " Enter retweets_count: ";
            cin >> rec.retweets_count;
            cout << " Enter replies_count: ";
            cin >> rec.retweets_count;
            cout << " Enter share videos (y/n): ";
            cin >> rec.share_videos;
            
            check = true;
            
        }
        return check;
    }

    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {
        int i;
        t_rec.noOfRecords++; // new size (old size = new size -1) ✔️main 함수에서 while 문을 돌면서 customer record 더해 준다. 그런데 add 함수가 실행 됐다는 것은 이미 customer record가 1 있다는 의미 그래서 t_rec.noOfRecords를 먼저 증가 시켜야 함
        
        if (t_rec.noOfRecords == 1) { // t_rec.noOfRecords가 1이라는 의미는 처음 더할 레코드가 있다는 말 그래서 담을 동적 메모리 생성
            
            t_rec.ptr_rec = nullptr; // t_rec.ptr_rec에 초기화 해준 거는 .h파일에 이미 포인터 있음
            t_rec.ptr_rec = new Customers[1];
            t_rec.ptr_rec[0] = c_rec;
        }else { // if가 아닌 다른 조건은 t_rec.noOfRecords > 1 이상일때 그러면 동적메모리의 사이즈를 다시 설정 해줘야 한다.
            
            Customers* newPtr_rec;
            newPtr_rec = nullptr;
            newPtr_rec = new Customers[t_rec.noOfRecords]; // 기존 사이즈 값에 + 1 해야 하는데 t_rec.noOfRecords값이 기존 사이즈 값
            
            for(i = 0;  i < t_rec.noOfRecords - 1; i++) { // 값 하나하나 넣어주기 새로운 사이즈로 동적 메모리에
                
                newPtr_rec[i] = t_rec.ptr_rec[i];
            }
            
            newPtr_rec[t_rec.noOfRecords - 1] = c_rec;
            delete [] t_rec.ptr_rec;
            t_rec.ptr_rec = nullptr;
            t_rec.ptr_rec = newPtr_rec;
        }
        
    }

    void display(const Customers& c_rec) {
        cout << c_rec.user_name << ", " << c_rec.likes_count << ", "  << c_rec.retweets_count << ", "  << c_rec.replies_count<< ", "  << c_rec.share_videos << '\n' << endl;
    
    }
    void display(const CustomersRecord& t_rec) {
        int i, j;
            for(i = 0, j = 1; i < t_rec.noOfRecords; i++)
            {
                cout << j++ << ". ";
                display(t_rec.ptr_rec[i]);
              
            }
    }
    

}
