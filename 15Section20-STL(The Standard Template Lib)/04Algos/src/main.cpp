// Section 20
// Algos
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<cctype>

class Person
{
private:
    std::string name;
    int age;

public:
    Person(std::string n = "None", int a = 0)
        : name{n}, age{a} {}
    bool operator==(const Person &rhs) const{
        return ((this->name == rhs.name) && (this->age == rhs.age));
    }
    std::string get_name(){
        return name;
    }
};

// Find an element in a container
void test0()
{
    std::vector<int> vec{1, 2, 3, 4};
    auto it = std::find(vec.begin(), vec.end(), 3);

    if(it != vec.end())
        std::cout << "your value: " << *it << std::endl;

    std::vector<Person> per_vec;
    per_vec.push_back({"Baris", 32});
    per_vec.push_back({"Can", 30});

    Person p0{"Jo", 35};

    auto it1 = std::find(per_vec.begin(), per_vec.end(), p0);
    if(it1 != per_vec.end())
        std::cout << "your person value: " << (*it1).get_name() << std::endl;
    
    Person p1{"Can", 30};

    auto it2 = std::find(std::begin(per_vec), std::end(per_vec), p1);                       // different syntax!
    if(it2 != std::end(per_vec))
        std::cout << "your person value: " << (*it2).get_name() << std::endl;
    
    std::list<Person> list_persons{{"Veli", 45}, {"Mehmet", 23}, {"Aydin", 40}};
    auto loc = std::find(std::begin(list_persons), std::end(list_persons), Person{"Aydin", 30});
    if(loc != std::end(list_persons))
        std::cout << "Aydin Bey bulundu." << std::endl;
    else 
        std::cout << "Aydin Bey yok." << std::endl;
}

// Count the number of occurrences of an elem in a container
void count_test()
{
    std::cout << "\n========================" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1};

    int num = std::count(vec.begin(), std::end(vec), 2);
    std::cout << num << " occurrences found" << std::endl;
}

// Count the number of occurrences of an elem in a container
// based on a predicate using a lambda expression
void count_if_test()
{
    std::cout << "\n========================" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1, 50};

    int num = std::count_if(vec.begin(), std::end(vec), [] (int i){return ((i % 2) == 0);});
    std::cout << num << " even numbers found" << std::endl;
    
    num = std::count_if(vec.begin(), std::end(vec), [] (int i){return ((i % 2) != 0);});
    std::cout << num << " odd numbers found" << std::endl;

    num = std::count_if(vec.begin(), std::end(vec), [] (int i){return (i >= 5);});
    std::cout << num << " numbers bigger than or equal 5" << std::endl;
}

void replace_test()
{
    std::cout << "\n========================" << std::endl;

    std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1, 50};
    for (int a: vec)
        std::cout << a << ' ';
    std::cout << '\n';

    std::replace(vec.begin(), std::end(vec), 1, 77);
    for (int a: vec)
        std::cout << a << ' ';
    std::cout << '\n';
    
    std::replace_if(vec.begin(), std::end(vec), [] (int i){return !(i % 2);}, 0);
    for (int a: vec)
        std::cout << a << ' ';
    std::cout << '\n';
}

void all_of_test()
{
    std::cout << "\n========================" << std::endl;

    std::vector<int> vec{1, 3, 5, 7, 9, 2, 4, 6, 17, 18};
    if( std::all_of(vec.begin(), std::end(vec), [] (int i){return !(i % 2);}))
        std::cout << "All the elems are even" << std::endl;
    else    
        std::cout << "Not all the elems are even" << std::endl;

    if( std::all_of(vec.begin(), std::end(vec), [] (int i){return (i < 20);}))
        std::cout << "All the elems are < 20" << std::endl;
    else    
        std::cout << "Not all the elems are < 20" << std::endl;
}

void string_transform_test()
{
    std::cout << "\n========================" << std::endl;

    std::string str{"This is a test"};
    std::cout << "\nBefore transform: " << str << std::endl;

    std::transform(std::begin(str), str.end(), str.begin(), ::toupper);
    std::cout << "After transform: " << str << '\n' << std::endl;
}

struct Square_Functor
{
    void operator()(int x){
        std::cout << (x * x) << " ";
    }
};

void test1()
{
    Square_Functor square;      // function object

    std::vector<int> vec{1, 2, 3, 4, 5};
    std::for_each(vec.begin(), vec.end(), square);
}

void square_function(int x)
{
    std::cout << (x * x) << " ";
}

void test2()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::for_each(vec.begin(), vec.end(), square_function);
}

void test3()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::for_each(vec.begin(), vec.end(), 
    [] (int x){
        std::cout << (x * x) << " ";
    });
}

int main()
{
    std::vector<int> v(10, 2);
    for(int a: v)
        std::cout << a << " ";
    // test0();
    // count_test();
    // count_if_test();
    // replace_test();
    // all_of_test();
    string_transform_test();
    // test1();
    // test2();
    // test3();

    return 0;
}











