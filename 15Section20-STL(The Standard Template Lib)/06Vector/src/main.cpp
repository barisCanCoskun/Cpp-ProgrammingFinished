#include<iostream>
#include<vector>
#include<algorithm>

class Person
{
private:
    friend std::ostream &operator<<(std::ostream &os ,const Person &p);
    std::string name;
    int age;

public:
    Person() = default;
    Person(std::string n = "None", int a = 0)
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

// display vector of ints using range-based for loop 
void display_vec_int(const std::vector<int> &vec)
{
    std::cout << "[ ";
    for (const auto &i: vec)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
}

// display vector of ints using for_each and lambda
void display_for_each(const std::vector<int> &vec)
{
    std::cout << "[ ";
    std::for_each(vec.begin(), vec.end(), 
    [] (int x){
        std::cout << x << " ";
    });
    std::cout << "]" << std::endl;
}

// display any vector using range-based for loop 
template<typename T>
void display(const std::vector<T> &vec)
{
    std::cout << "[ ";
    for (const auto &i: vec)
        std::cout << i << "  ";
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "\nTest1======================" << std::endl;
    std::vector<int> vec1 {1, 2, 3, 4, 5};
    display_for_each(vec1);
    std::cout << "vec1.size(): " << vec1.size() << std::endl;
    std::cout << "vec1.maxsize(): " << vec1.max_size() << std::endl;
    std::cout << "vec1.capacity(): " << vec1.capacity() << '\n' << std::endl;

    std::cout << "After exceeding max size: \n";
    vec1.push_back(6);
    display_for_each(vec1);
    std::cout << "vec1.size(): " << vec1.size() << std::endl;
    std::cout << "vec1.maxsize(): " << vec1.max_size() << std::endl;
    std::cout << "vec1.capacity(): " << vec1.capacity() << '\n' << std::endl;
    

    vec1.push_back(7);
    display_for_each(vec1);
    std::cout << "vec1.size(): " << vec1.size() << std::endl;
    std::cout << "vec1.maxsize(): " << vec1.max_size() << std::endl;
    std::cout << "vec1.capacity(): " << vec1.capacity() << '\n' << std::endl;

    std::cout << "After shrinking: \n";
    vec1.shrink_to_fit();       // C++11
    display_for_each(vec1);
    std::cout << "vec1.size(): " << vec1.size() << std::endl;
    std::cout << "vec1.maxsize(): " << vec1.max_size() << std::endl;
    std::cout << "vec1.capacity(): " << vec1.capacity() << '\n' << std::endl;

    std::cout << "After exceeding max size: \n";
    vec1.push_back(8);
    vec1.push_back(9);
    vec1.push_back(10);
    vec1.push_back(11);
    display_for_each(vec1);
    std::cout << "vec1.size(): " << vec1.size() << std::endl;
    std::cout << "vec1.maxsize(): " << vec1.max_size() << std::endl;
    std::cout << "vec1.capacity(): " << vec1.capacity() << '\n' << std::endl;

    std::cout << "After reserving 100: \n";         // this will make capacity 100 
                                                    // it wont expand until it hits 101 element
    vec1.reserve(100);
    display(vec1);
    std::cout << "vec1.size(): " << vec1.size() << std::endl;
    std::cout << "vec1.maxsize(): " << vec1.max_size() << std::endl;
    std::cout << "vec1.capacity(): " << vec1.capacity() << '\n' << std::endl;

}

// emplace_back
void test2()
{
    std::cout << "\nTest2==================" << std::endl;
    std::vector<Person> stooges;

    Person p1{"Baris", 20};
    display(stooges);

    stooges.push_back(p1);
    display(stooges);

    stooges.push_back({"Joe", 28});
    display(stooges);

    stooges.emplace_back("Ahmet", 27);      // Use emplace_back!
    display(stooges);

// push_back may construct a temporary object. 
// This temporary object wukk then get copied or moved into the container.

// emplace_back  forwards the arguments to the constructor for the object 
// and creates an initializes the object directly in place -- no copy or move requried!!!!
}

// stooges.front(), stooges.pop_back();
void test3()
{
    std::cout << "\nTest3==================" << std::endl;
    std::vector<Person> stooges{
        {"Ali", 40},
        {"Veli", 30},
        {"Kemal", 20}
    };

    display(stooges);
    std::cout << "Front: " << stooges.front() << std::endl;
    std::cout << "Back: " << stooges.back() << std::endl;

    stooges.pop_back();
    display(stooges);
}

// it = vec.erase(it);  vec.erase(vec.begin(), std::begin(vec) + 2);
void test4()
{
    std::cout << "\nTest4======================" << std::endl;
    std::vector<int> vec{1, 2, 3, 4, 5};
    display(vec);

    vec.clear();    // remove all elements
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(vec);
    vec.erase(vec.begin(), std::begin(vec) + 2);
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Erase all even numbers
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end();)
    {
        if (*it % 2 == 0)
            it = vec.erase(it);
        else
            ++it;
    }
    display(vec);
}

// vec2.swap(vec1);
void test5()
{
    std::cout << "\nTest5======================" << std::endl;
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{6, 7, 8, 9, 10};
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    vec2.swap(vec1);
    display(vec1);
    display(vec2);
}

// std::copy(vec1.begin(), std::end(vec1), std::back_inserter(vec2)); 
// std::copy_if(vec1.begin(), std::end(vec1), std::back_inserter(vec2), [](int x) { return x % 2 != 0; });
void test6()
{
    std::cout << "\nTest6======================" << std::endl;
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{6, 7};
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    std::copy(vec1.begin(), std::end(vec1), std::back_inserter(vec2));
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    vec1 = {1, 2, 3, 4, 5};
    vec2 = {6, 7};
    display(vec1);
    display(vec2);
    std::cout << std::endl;

    std::cout << "Adding odd numbers in vec1 to vec2 are: \n";
    std::copy_if(vec1.begin(), std::end(vec1), std::back_inserter(vec2), [](int x) { return x % 2 != 0; });
    display(vec1);
    display(vec2);
    std::cout << std::endl;

}

// std::transform(vec1.begin(), std::end(vec1), std::begin(vec2), std::back_inserter(vec3), 
                    // [](int x, int y) { return x * y; });
void test7()
{
    std::cout << "\nTest7======================" << std::endl;
    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{10, 20, 30, 40, 50};
    std::vector<int> vec3;
    display(vec1);
    display(vec2);
    display(vec3);
    std::cout << std::endl;

    std::transform(vec1.begin(), std::end(vec1), std::begin(vec2), std::back_inserter(vec3), 
                    [](int x, int y) { return x * y; });
    display(vec3);
    std::cout << std::endl;

}

// it = std::find(vec1.begin(), std::end(vec1), 2);
// vec1.insert(it, vec2.begin(), std::end(vec2));
void test()
{
    std::cout << "\nTest======================" << std::endl;
    std::vector<int> vec1 {1, 2, 3, 4, 5};
    std::vector<int> vec2 {7, 8, 2, 13, 21};
    display(vec1);
    display(vec2);
    std::cout << std::endl;
    
    std::cout << "Before inserting 7 to vec1: ";
    display(vec1);
    auto it = std::find(vec1.begin(), std::end(vec1), 4);
    vec1.insert(it, 7);
    std::cout << "After inserting 7 to vec1: ";
    display(vec1);

    std::cout << "\nBefore inserting vec2 to vec1: ";
    display(vec1);
    it = std::find(vec1.begin(), std::end(vec1), 2);
    vec1.insert(it, vec2.begin(), std::end(vec2));
    std::cout << "After inserting vec2 to vec1: ";
    display(vec1);

}

int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    test();

    return 0;
}









 