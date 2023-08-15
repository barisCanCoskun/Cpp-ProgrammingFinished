#include<iostream>
#include<memory>

using namespace std;

class Account{
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

class Checking: public Account {
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
    cout << "Pointers===============" << endl;
    Account *p1 = new Account();
    Account *p2 = new Checking();
    Account *p3 = new Savings();
    Account *p4 = new Trust();

    p1->withdraw(100);
    p2->withdraw(100);
    p3->withdraw(100);
    p4->withdraw(100);

    p3->say_hello();
    p4->say_hello();
    
    cout << "\n===Clean up pointers===\n" << endl;  
    delete p1;
    delete p2;
    delete p3;
    delete p4;
    
    Account obj1;
    greetings(obj1);

    Checking obj2;
    greetings(obj2);

    Account &ref1 = obj1;
    ref1.say_hello();

    Checking &ref2 = obj2;
    ref2.say_hello();

    return 0;   
}

void greetings(const Account &obj){
    cout << "Greetings:";
    obj.say_hello();
}









