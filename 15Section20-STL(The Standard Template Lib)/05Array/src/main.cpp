// Section 20
// std::array
#include<iostream>
#include<array>
#include<algorithm>
#include<numeric>

// display the array 
void display(const std::array<int, 5> &arr)
{
    std::cout << "[ ";
    for (const auto &a: arr)
        std::cout << a << " ";
    std::cout << "]" << std::endl;
}

// arr1.size(), arr2.front(), arr1.at(7)
void test1()
{
    std::cout << "\nTest1 ======================" << std::endl;
    std::array<int, 5>arr1{1, 2, 3, 4, 5};
    std::array<int, 5>arr2;

    display(arr1);
    display(arr2);          // Elems are not initialized(contain 'garbage')

    arr2 = {7, 8, 9, 5, 3};
    display(arr2);

    std::cout << "Size of arr1: " << arr1.size() << std::endl;
    arr1.at(0) = 50000;
    arr1[1] = 40;
    display(arr1);

    arr1[7] = 5;        // not bounds checking...
    // arr1.at(7) = 3;     // bounds checking: out of range exception

    std::cout << "Front of arr2: " << arr2.front() << std::endl;
    std::cout << "Back of arr1: " << arr1.back() << std::endl;
}

// arr1.fill(0), arr1.swap(arr2)
void test2()
{
    std::cout << "\nTest2 ======================" << std::endl;
    std::array<int, 5>arr1{1, 2, 3, 4, 5};
    std::array<int, 5>arr2{7, 8, 9, 5, 3};

    std::cout << "\narr1: ";
    display(arr1);
    std::cout << "arr2: ";
    display(arr2); 

    arr1.fill(0);
    std::cout << "\nAfter filling 0 \narr1: ";
    display(arr1);
    
    arr1.swap(arr2);
    std::cout << "\nAfter swaping \narr1: ";
    display(arr1);
    std::cout << "arr2: ";
    display(arr2);

    std::cout << '\n';
}

// arr1.data()
void test3()
{
    std::cout << "\nTest3 ======================" << std::endl;
    std::array<int, 5>arr1{1, 2, 3, 4, 5};

    int *ptr = arr1.data();
    std::cout << "value of arr1: " << ptr << std::endl;
    *ptr = 88;

    display(arr1);

    std::cout << '\n';
}

// std::sort(arr1.begin(), arr1.end())
void test4()
{
    std::cout << "\nTest4 ======================" << std::endl;
    std::array<int, 5>arr1{4, 3, 1, 5, 2};
    std::cout << "Before sorting: ";
    display(arr1);
    
    std::sort(arr1.begin(), arr1.end());
    std::cout << "After sorting: ";
    display(arr1);

    std::cout << '\n';
}

// std::min_element(arr1.begin(), std::end(arr1))
void test5()
{
    std::cout << "\nTest5 ======================" << std::endl;
    std::array<int, 5>arr1{4, 3, 1, 5, 2};
    auto min_num = std::min_element(arr1.begin(), std::end(arr1));
    std::cout << "Min elem: " << *min_num << std::endl;
    
    auto max_num = std::max_element(arr1.begin(), std::end(arr1));
    std::cout << "Max elem: " << *max_num << std::endl;

    std::cout << '\n';
}

// std::adjacent_find(arr1.begin(), std::end(arr1))
void test6()
{
    std::cout << "\nTest6 ======================" << std::endl;
    std::array<int, 5>arr1{4, 3, 3, 5, 2};

    auto adjacent = std::adjacent_find(arr1.begin(), std::end(arr1));
    if(adjacent != std::end(arr1))
        std::cout << "Adjacent elem: " << *adjacent << std::endl;
    else    
        std::cout << "Adjacent elem not found" << std::endl;

    std::cout << '\n';
}

// std::accumulate(std::begin(arr1), arr1.end(), 0)
void test7()
{
    std::cout << "\nTest7 ======================" << std::endl;
    std::array<int, 5>arr1{4, 3, 1, 5, 2};

    int sum = std::accumulate(std::begin(arr1), arr1.end(), 0);
    std::cout << "Sum of elems: " << sum << std::endl;

    std::cout << '\n';
}

// std::count(arr1.begin(), std::end(arr1), 4)
void test8()
{
    std::cout << "\nTest8 ======================" << std::endl;
    std::array<int, 8>arr1{4, 3, 1, 5, 2, 4, 4, 4};
    
    int count = std::count(arr1.begin(), std::end(arr1), 4);
    std::cout << "Found 4: " << count << " times" << std::endl;

    std::cout << '\n';
}

// std::count_if(arr1.begin(), std::end(arr1), [] (int x){ return (x > 10 && x < 20);})
void test9()
{
    std::cout << "\nTest9 ======================" << std::endl;
    std::array<int, 8>arr1{4, 3, 1, 5, 11, 15, 34, 19};
    
    int count = std::count_if(arr1.begin(), std::end(arr1), [] (int x){ return (x > 10 && x < 20);});
    std::cout << "Found (x > 10 && x < 20): " << count << " times" << std::endl;

    std::cout << '\n';
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}









