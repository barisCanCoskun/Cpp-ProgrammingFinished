#include<iostream>

using namespace std;

class Base
{
private:
    int value;
public:
    Base()
        : value{0} {
        cout << "Base no-args ctor" << endl;
    }
    Base(int x)     // non-special ctor
        : value{x} {
        cout << "Base int arg ctor" << endl;
    }
    ~Base(){
        cout << "Base dtor" << endl;
    }
    // Copy Ctor
    Base(const Base &source)
        : value{source.value} {
        cout << "Base copy ctor" << endl;
    }

    // Overloaded assignment operator copy
    Base &operator=(const Base &rhs){
        if (this != &rhs){
            value = rhs.value;
        }
        return *this;
    }

    // Overloaded assignment operator move
    Base &operator=(Base &&rhs){
        if (this != &rhs){
            value = rhs.value;
        }
        return *this;
    }
};

class Derived: public Base
{
// using Base::Base;    
private:
    int doubled_value;
public:
    Derived()
        : Base{}, doubled_value{0} {
        cout << "Derived no-args ctor" << endl;
    }
    Derived(int d)     // control go to non-special base ctor
        : Base{d}, doubled_value{d * 2} {
        cout << "Derived int arg ctor" << endl;
    }
    ~Derived(){
        cout << "Derived dtor" << endl;
    }
    // Copy Ctor
    Derived(const Derived &source)
        : Base(source), doubled_value{source.doubled_value} {
        cout << "Derived copy ctor" << endl;
    }

    // Overloaded assignment operator copy
    Derived &operator=(const Derived &rhs){
        if (this != &rhs){
            Base::operator=(rhs);
            doubled_value = rhs.doubled_value;
        }
        return *this;
    }

    // Overloaded assignment operator move
    Derived &operator=(Derived &&rhs){
        if (this != &rhs){
            Base::operator=(rhs);
            doubled_value = rhs.doubled_value;
        }
        return *this;
    }
};

int main()
{
    // Base b;
    // Base b1{7};

    Derived d{8};

    return 0;
}










