// Section 17
// Custom deleters
#include<iostream>
#include<memory>

class Test
{
private:
    int data;
public:
    Test() :data{0} {std::cout << "Test ctor (" << data << ") " << std::endl; }
    Test(int d) :data{d} {std::cout << "Int arg Test ctor (" << data << ") " << std::endl; }
    int get_data() const {return data;}
    ~Test() {std::cout << "Test dtor (" << data << ") " << std::endl; }
};

void my_deleter(Test *ptr){
    std::cout << "\tIn my custom func deleter for: " << ptr->get_data() << std::endl;
    delete ptr;
}

int main()
{
    {
    std::shared_ptr<Test> p {new Test{40}, my_deleter};
    }
    std::shared_ptr<Test> p1 {new Test{30}, [] (Test *ptr){
        std::cout << "\tLambda Using my custom deleter for: " << ptr->get_data() << std::endl;
        delete ptr;
    }};

    std::shared_ptr<Test> p2 {new Test{60}, my_deleter};


    return 0;
}














