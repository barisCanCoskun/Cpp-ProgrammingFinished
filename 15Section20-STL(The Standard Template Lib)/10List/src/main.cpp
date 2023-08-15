#include<iostream>
#include<list>
#include<algorithm>
#include<forward_list>
#include<iterator>      // for std::advance

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
        return (this->age < rhs.age);
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
void display(const std::list<T> &list)
{
    std::cout << "[ ";
    for (const auto &l: list)
        std::cout << l << "  ";
    std::cout << "]" << std::endl;
}

template<typename T>
void display_forward(const std::forward_list<T> &list)
{
    std::cout << "[ ";
    for (const auto &l: list)
        std::cout << l << "  ";
    std::cout << "]" << std::endl;
}

// std::forward_list<int> list_forward{1, 3, 5, 7, 9};  list_forward.max_size() ,     list_forward.front()
// list_forward_person.push_front(Person("Kadir", 22));     list_forward_person.pop_front();
// list_forward_person.emplace_front(Person("Semih", 34));
// list_forward.insert_after(it1, 700);
// list_forward.emplace_after(it1, 800);
void test1()
{
    std::forward_list<int> list_forward{1, 3, 5, 7, 9};

    // list_forward.size();    // NOT available
    std::cout << "list_forward.max_size(): " <<list_forward.max_size() << std::endl;

    std::cout << "list_forward.front(): " << list_forward.front() << std::endl;

    // list_forward.back();        // NOT available

    std::forward_list<Person> list_forward_person;
    list_forward_person.push_front(Person("Kadir", 22));
    list_forward_person.pop_front();

    list_forward_person.emplace_front(Person("Semih", 34));

    auto it1 =  std::find(list_forward.begin(), list_forward.end(), 7);
    list_forward.insert_after(it1, 700);
    display_forward(list_forward);

    list_forward.emplace_after(it1, 800);
    display_forward(list_forward);

    // list_forward.emplace_front(it1, 600);
    // display_forward(list_forward);

    list_forward.erase_after(it1);
    display_forward(list_forward);

}

void test2()
{
    std::list<int> l{1, 2, 3, 4};
    std::list<std::string> stooges{"Joe", std::string{"Haci"}};
    
    // l[2] = 5;        // not allowed

    l = {2, 4, 6};

    std::cout << "Size of l: " << l.size() << std::endl;
    std::cout << "Max Size of l: " << l.max_size() << std::endl;
    std::cout << "Front of l: " << l.front() << std::endl;

    std::list<int> l1(5, 25);
    display(l1);

    l1.clear();
    display(l1);
}

void test3()
{
    std::list<int> l = {1, 2, 3, 4, 5};
    auto it = std::find(l.begin(), l.end(), 4);
    l.insert(it, 90);
    display(l);

    // l.find   yok böyle bir şey. std::set teki gibi.

    l.erase(it);
    display(l);

    l.resize(4);
    display(l);

    l.resize(7);
    display(l);

    l = {1, 2, 3, 4, 5, 6, 7};
    display(l);

    it = std::find(l.begin(), l.end(), 5);
    l.insert(it, 50);
    display(l);

    std::advance(it, -2);
    l.erase(it);                // remove 4 - iterator becomes invalid
    display(l);
}

void test4()
{
    std::cout << '\n';
    Person p1{"Ahmet", 30};
    std::list<Person> list_person;
    list_person.push_back(p1);
    list_person.pop_back();

    list_person.push_front(Person{"Kadir", 19});
    list_person.pop_back();
    display(list_person);

    list_person.emplace_back(Person("Kemal", 15));
    list_person.emplace_front(Person("Mustafa", 5));
    display(list_person);

    std::string name;
    std::cout << "Enter name: " ;
    std::getline(std::cin, name);
    int age{};
    std::cout << "Enter age: ";
    std::cin >> age;

    list_person.emplace_back(name, age);
    display(list_person);

    list_person.resize(4);
    display(list_person);

    // insert Baris before Kemal
    auto it = std::find(list_person.begin(), std::end(list_person), Person("Kemal", 15));
    if(it != list_person.end())
        list_person.emplace(it, Person("Baris", 32));
    display(list_person);

}

void test5()
{
    std::list<Person> list{{"Namik", 35}, {"Vehbi", 55}, {"Cevdet", 20}};
    display(list);

    list.sort();
    display(list);

}

int main()
{
    // test3();
    // test4();
    test5();


    return 0;
}









