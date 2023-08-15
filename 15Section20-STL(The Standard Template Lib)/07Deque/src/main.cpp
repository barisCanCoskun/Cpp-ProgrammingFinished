#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>

// display any deque
template<typename T>
void display(const std::deque<T> &deq)
{
    std::cout << "[ ";
    for (const auto &d: deq)
        std::cout << d << "  ";
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "\nTest1======================" << std::endl;
    std::deque<int> deq {1, 2, 3, 4, 5};
    display(deq);

    deq = {2, 4, 7, 8};
    display(deq);

    std::deque<int> deq1(5, 50);
    display(deq1);

    deq.at(3) = 7;
    deq[2] = 88;
    display(deq);

}

// push and pops
void test2()
{
    std::cout << "\nTest2======================" << std::endl;
    std::deque<int> deq {1, 2, 3, 4, 5};
    display(deq);

    deq.push_back(6);
    display(deq);

    deq.push_front(7);
    display(deq);

    std::cout << "Front:" << deq.front() << std::endl;
    std::cout << "Back:" << deq.back() << std::endl;
    std::cout << "Size:" << deq.size() << std::endl;
    
    deq.pop_back();
    deq.pop_front();
    display(deq);

}

// insert even and odd numbers to front and back
void test3()
{
    std::cout << "\nTest3======================" << std::endl;
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::deque<int> deq;

    for(const auto &v: vec){
        if(v % 2 == 0)
            deq.push_back(v);
        else    
            deq.push_front(v);
    }
    
    display(deq);

}

int main()
{
    // test1();
    // test2();
    test3();

    return 0;
}









