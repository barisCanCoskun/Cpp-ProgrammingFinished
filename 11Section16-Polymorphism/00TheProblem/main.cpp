#include<iostream>
#include<memory>

using namespace std;

class Base{
public:
    virtual void say_hello() const{
        cout << "Hello - I'm a Base class object" << endl;
    }
    virtual ~Base() = default;
};

class Derived: public Base {
public:
    void say_hello() const {
        cout << "Hello - I'm a Derived class object" << endl;
    }
};

void greetings(const Base &obj){
    cout << "Greetings:";
    obj.say_hello();
}

int main()
{
    Base obj1;
    greetings(obj1);

    Derived obj2;
    greetings(obj2);

    Base *p = new Derived();
    p->say_hello();
    greetings(*p);

    unique_ptr<Base> p1 = make_unique<Derived>();
    p1->say_hello();

    unique_ptr<Base> p2 {new Derived()};    // bu da olabilir 

    delete p;
    p = nullptr;

    return 0;   
}








