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

void func(std::shared_ptr<Test> p){
    std::cout << "func use count: " << p.use_count() << std::endl;
}

int main()
{
    // use_count; the number of shared_ptr objs
    std::shared_ptr<int> ptr{new int{20}};
    std::cout << *ptr << std::endl;
    std::cout << ptr.use_count() << std::endl;

    std::shared_ptr<int> p0{ptr};       // shared ownership
    // this is one of the things that we could not do with unique ptrs 
    std::cout << ptr.use_count() << std::endl;
    std::cout << p0.use_count() << std::endl;

    ptr.reset();    //decrement the use_count; ptr is nulled out. 
    std::cout << ptr.use_count() << std::endl;
    std::cout << p0.use_count() << std::endl;
    
    std::shared_ptr<Account> p1 {new Savings_Account{"Veli"}};
    std::cout << *p1 << std::endl;

    p1->deposit(500);
    p1->withdraw(100);
    std::cout << *p1 << std::endl;

    std::vector<std::shared_ptr<int>> vec;
    std::shared_ptr<int> ptr1{new int{30}};

    vec.push_back(ptr1);    // copy is allowed

    std::cout << "use count: " << ptr1.use_count() << std::endl;

    // use std::make_shared<> , it's more EFFICIENT! 
    std::shared_ptr<int> ptr2 = std::make_shared<int>(50); // use count: 1
    std::shared_ptr<int> ptr3{ptr2};                       // use count: 2
    std::shared_ptr<int> ptr4;                            
    ptr4 = ptr2;                                           // use count: 3

    std::shared_ptr<Test> ptr5 = std::make_shared<Test>(30); 
    func(ptr5);
    std::cout << "ptr5 use count: " << ptr5.use_count() << std::endl;

    std::cout << "=====Vectors of shared ptrs to accounts===============" << std::endl;
    std::shared_ptr<Account> acc1 = std::make_shared<Savings_Account> ("Zoey", 1000);
    std::shared_ptr<Account> acc2 = std::make_shared<Trust_Account> ("James", 3000, 1.5);
    std::shared_ptr<Account> acc3 = std::make_shared<Checking_Account> ("Adams", 4000);

    std::vector<std::shared_ptr<Account>> accounts;
    accounts.push_back(acc1);
    accounts.push_back(acc2);
    accounts.push_back(acc3);
    
    std::cout << "=====copying account obj===============" << std::endl;
    for (const auto a: accounts){
        std::cout << *a << std::endl;
        std::cout << "use count:" << a.use_count() << std::endl;
    }
    
    std::cout << "=====reference to account obj===============" << std::endl;
    for (const auto &a: accounts){
        std::cout << *a << std::endl;
        std::cout << "use count:" << a.use_count() << std::endl;
    }

    return 0;
}










