// Section 17
// Unique Pointers
#include<iostream>
#include<memory>
#include<vector>

#include"Trust_Account.h"
#include"Checking_Account.h"
#include"Account_Util.h"
#include"Account.h"

// using namespace std;

class Test
{
private:
    int data;
public:
    Test() :data{0} {std::cout << "Test ctor (" << data << ") " << std::endl; }
    Test(int d) :data{d} {std::cout << "Int arg Test ctor (" << data << ") " << std::endl; }
    int get_data() const {return data;}
    ~Test() {std::cout << "Test dtor (" << data << ") " << std::endl; }
};

int main()
{
    std::unique_ptr<int> p1{new int{100}};
    std::cout << *p1 << std::endl;
    std::cout << p1.get() << std::endl;
    // std::cout << p1 << std::endl;

    // p1.reset();     // p1 is now nullptr 

    // // *p1 = 200;    
    // if(p1)
    //     std::cout << *p1 << std::endl;      
    
    // std::unique_ptr<Account> p2{new Savings_Account{"Joe"}};
    // std::cout << *p2 << std::endl;

    // p2->deposit(1000);
    // p2->withdraw(200);
    // std::cout << *p2 << std::endl;

    std::vector<std::unique_ptr<int>> vec;
    std::unique_ptr<int> ptr{new int{100}};

    // vec.push_back(ptr);  // copy not allowed
    vec.push_back(std::move(ptr));

    if(!ptr)
        std::cout << "ptr is null" << std::endl;

    // std::unique_ptr<int> p3 = std::make_unique<int> (100);
    // std::unique_ptr<Account> p4 = std::make_unique<Checking_Account> ("Joey", 100);
    // auto p5 = std::make_unique<Savings_Account>("ok");

    // std::unique_ptr<Test> t1{new Test};
    // std::unique_ptr<Test> t2 = std::make_unique<Test>(300);
    // std::unique_ptr<Test> t3;

    // t3 = std::move(t1);      // t3 now owns that obj, t1 is null. 
    // if(!t1)                  // it cant own the obj bec we r not sharing ownership.
    //     std::cout << "t1 is nullptr" << std::endl;    

    std::vector<std::unique_ptr<Account>> accounts;

    accounts.push_back(std::make_unique<Checking_Account>("Ahmet", 300));
    accounts.push_back(std::make_unique<Savings_Account>("Cevdet", 250));
    accounts.push_back(std::make_unique<Trust_Account>("Fehmi", 400));

    // this is doing copy. 
    // for (auto a: accounts){
    //     std::cout << *a << std::endl;
    // }
    
    for (const auto &a: accounts){
        std::cout << *a << std::endl;
    }

    return 0;
}










