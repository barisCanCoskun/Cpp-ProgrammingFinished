#include<iostream>
#include<memory>

using namespace std;

class Account{
    friend ostream &operator<<(ostream &os, const Account &acc);
public:
    virtual void withdraw(float f){
        cout << "In Account::withdraw method" << endl;
    }
    virtual ~Account(){
        cout << "In Account::destructor" << endl;
    }
    virtual void say_hello() const{
        cout << "Hello - I'm an Account class object" << endl;
    }
};

ostream &operator<<(ostream &os, const Account &acc)
{
    os << "Account display";
    return os;
}

class Checking: public Account {
    friend ostream &operator<<(ostream &os, const Checking &acc);
public:
    void withdraw(float f){
        cout << "In Checking::withdraw method" << endl;
    }
    ~Checking(){
        cout << "In Checking::destructor" << endl;
    }
    void say_hello() const override{
        cout << "Hello - I'm a Checking class object" << endl;
    }
};

ostream &operator<<(ostream &os, const Checking &acc)
{
    os << "Checking display";
    return os;
}

class Savings: public Account {
public:
    void withdraw(float f){
        cout << "In Savings::withdraw method" << endl;
    }
    ~Savings(){
        cout << "In Savings::destructor" << endl;
    }
    void say_hello() {                                             // redifining methods!!!
        cout << "Hello - I'm a Savings class object" << endl;
    }
};

class Trust: public Savings {
public:
    void withdraw(float f){
        cout << "In Trust::withdraw method" << endl;
    }
    ~Trust(){
        cout << "In Trust::destructor" << endl;
    }
    void say_hello() const{
        cout << "Hello - I'm a Trust class object" << endl;
    }
};

void greetings(const Account &obj);

int main()
{
    Account *p1 = new Account();
    cout << *p1 << endl;

    Account *p2 = new Checking();
    cout << *p2 << endl;

    return 0;   
}

void greetings(const Account &obj){
    cout << "Greetings:";
    obj.say_hello();
}









