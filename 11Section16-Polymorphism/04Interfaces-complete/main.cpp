#include<iostream>
#include<memory>

using namespace std;

class I_Printable {
    friend ostream &operator<<(ostream &os, const I_Printable &obj);
public:
    virtual void print(ostream &os) const = 0;
    virtual ~I_Printable() { }
};

ostream &operator<<(ostream &os, const I_Printable &obj)
{
    obj.print(os);
    return os;
}

class Account : public I_Printable{
public:
    virtual void print(ostream &os) const override {
        os << "Account display";
    }
    virtual void withdraw(float f){
        cout << "In Account::withdraw method" << endl;
    }
    virtual ~Account(){
        cout << "In Account::destructor" << endl;
    }
};

class Checking: public Account {
public:
    virtual void print(ostream &os) const override {
        os << "Checking display";
    }
    void withdraw(float f){
        cout << "In Checking::withdraw method" << endl;
    }
    ~Checking(){
        cout << "In Checking::destructor" << endl;
    }
};

class Savings: public Account {
public:
    virtual void print(ostream &os) const override {
        os << "Savings display";
    }
    void withdraw(float f){
        cout << "In Savings::withdraw method" << endl;
    }
    ~Savings(){
        cout << "In Savings::destructor" << endl;
    }
};

class Trust: public Savings {
public:
    virtual void print(ostream &os) const override {
        os << "Trust display";
    }
    void withdraw(float f){
        cout << "In Trust::withdraw method" << endl;
    }
    ~Trust(){
        cout << "In Trust::destructor" << endl;
    }
};

class Dog: public I_Printable{
public:
    virtual void print(ostream &os) const override {
        os << "Woof wwoof!";
    }
};

void print(const I_Printable &obj)
{
    cout << obj << endl;
}

int main()
{
    I_Printable *d = new Dog();
    cout << *d << endl;
    print(*d);

    Dog d1;
    d1.print(cout);
    cout<<"\n";

    Account *p1 = new Account();
    cout << *p1 << endl;

    Account *p2 = new Checking();
    cout << *p2 << endl;

    Account *p3 = new Savings();
    cout << *p3 << endl;

    Account *p4 = new Trust();
    cout << *p4 << endl;

    return 0;   
}











