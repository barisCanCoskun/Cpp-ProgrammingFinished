// Section 20
// Func Temps
#include<iostream>

template <typename T>
T min(T a, T b){
    return (a < b) ? a : b;
}

template <class T1, class T2>
void func(T1 a, T2 b){
    std::cout << a << " " << b << std::endl;
}

struct Person
{
    std::string name;
    int age;
    bool operator<(const Person &rhs) const{
        return (this->age < rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &per)
{
    os << per.name << ": " << per.age;
    return os;
}

template <class f>
void swap(f &a, f &b)
{
    f temp = a;
    a = b;
    b = temp;
}   

int main()
{
    std::cout << min<int>(2, 3) << std::endl;           // 2
    std::cout << min(3, 5) << std::endl;                // 3
    std::cout << min('A', 'B') << std::endl;            // A
    std::cout << min(12.5, 9.2) << std::endl;           // 9.2
    std::cout << min(5 + 2 * 2, 7 + 40) << std::endl;   // 9

    Person p1{"Ahmet", 17};
    Person p2{"Mehmet", 25};
    Person p3{min(p1, p2)};
    std::cout << min(p1, p2) << " is younger." << std::endl;

    func<int, int> (35, 67);
    func(35, 67);
    func<char, double>('A', 45.3);
    func('A', 45.3);
    func(567, "Test");
    func(3401, std::string{"Kemal"});

    func(p1, p2);

    int x{5};
    int y{9};
    std::cout << "\nx: " << x << " ,y: " << y << std::endl;
    swap(x, y);
    std::cout << "After swap" << std::endl;
    std::cout << "x: " << x << " ,y: " << y << std::endl;

    std::string s1{"Apple"};
    std::string s2{"Karpuz"};
    std::cout << "\ns1: " << s1 << " ,s2: " << s2 << std::endl;
    swap(s1, s2);
    std::cout << "After swap" << std::endl;
    std::cout << "s1: " << s1 << " ,s2: " << s2 << std::endl;

    Person per1{"God", 1000};
    Person per2{"Prophet", 2000};
    std::cout << "\nper1: " << per1 << " ,per2: " << per2 << std::endl;
    swap(per1, per2);
    std::cout << "After swap" << std::endl;
    std::cout << "per1: " << per1 << " ,per2: " << per2 << std::endl;
        
    std::cout << std::endl;
    return 0;
}









 