#include<iostream>
#include<set>
#include<string>

class Person
{
private:
    friend std::ostream &operator<<(std::ostream &os ,const Person &p);
    std::string name;
    int age;

public:
    Person() : name{"Unknown"}, age{0} {}
    Person(std::string n, int a)
        : name{n}, age{a} {}
    bool operator==(const Person &rhs) const{
        return ((this->name == rhs.name) && (this->age == rhs.age));
    }
    bool operator<(const Person &rhs) const{
        return ((this->age <= rhs.age) && (this->name != rhs.name));
    }
    std::string get_name(){
        return name;
    }
};

std::ostream &operator<<(std::ostream &os ,const Person &p)
{
    os << p.name << ":" << p.age;
    return os;
}

template<typename T>
void display(const std::set<T> &set)
{
    std::cout << "[ ";
    for (const auto &s: set)
        std::cout << s << "  ";
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "Test1=======================" << std::endl;

    std::set<int> s{4, 2, 1, 5, 3};
    display(s);

    s = {2, 2, 5, 3, 3, 1, 4, 1, 5};
    display(s);

    s.emplace(0);
    s.emplace(10);
    display(s);

    if(s.count(10))
        std::cout << "10 is in set" << std::endl;
    else    
        std::cout << "10 is NOT in set" << std::endl;
    
    auto it = s.find(3);
    if(it != s.end())
        std::cout << *it << std::endl;
    
    s.clear();
    display(s);

}

void test2()
{
    std::cout << "Test2=======================" << std::endl;

    std::set<Person> duman{{"Kaan", 40}, {"Ali", 45}, {"Veli", 35}};
    display(duman);

    duman.emplace(Person{"Ari", 42});
    display(duman);

    duman.emplace(Person("Barkan", 42));
    display(duman);

    auto it = duman.find(Person{"Veli", 35});               // uses operator<
    std::cout << *it << std::endl;
    if(it != duman.end())
        duman.erase(it);
    display(duman);

    it = duman.find(Person{"Barkan", 42});                 // silinmiyor anlamadım...
    // std::cout << *it << std::endl;
    if(it != duman.end())
        duman.erase(it);
    display(duman);

    it = duman.find(Person{"Ari", 42});               // uses operator<
    std::cout << *it << std::endl;
    if(it != duman.end())
        duman.erase(it);
    display(duman);

}

void test3()
{
    std::cout << "Test3=======================" << std::endl;

    std::set<std::string> s{"A", "B", "C"};
    display(s);

    auto p = s.emplace("D");
    display(s);

    std::cout << std::boolalpha << std::endl;
    std::cout << "p.first: " << *(p.first) << std::endl;
    std::cout << "p.second: " << p.second << std::endl;

    p = s.emplace("B");
    display(s);

    std::cout << "p.first: " << *(p.first) << std::endl;
    std::cout << "p.second: " << p.second << std::endl;

}

int main()
{
    // test1();
    // test2();
    test3();

    std::cout << "" << std::endl;
    return 0;
}









