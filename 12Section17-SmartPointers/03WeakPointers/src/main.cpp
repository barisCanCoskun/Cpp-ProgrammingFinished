// Section 17
// Weak Ptrs
#include<iostream>
#include<memory>

// using namespace std;

class B;    // forward decleration ; similar to func prototype

class A
{
    std::shared_ptr<B> b_ptr;
public:
    void set_B(std::shared_ptr<B> &b){
        b_ptr = b;
    }
    A() {std::cout << "A Constructor" << std::endl;}
    ~A() {std::cout << "A Dtor" << std::endl;}
};

class B
{
    std::weak_ptr<A> a_ptr;           // make weak to break the strong circular reference
public:
    void set_A(std::shared_ptr<A> &a){
        a_ptr = a;
    }
    B() {std::cout << "B Ctor" << std::endl;}
    ~B() {std::cout << "B Dtor" << std::endl;}
};

int main()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    
    a->set_B(b);
    b->set_A(a);

    return 0;
}











