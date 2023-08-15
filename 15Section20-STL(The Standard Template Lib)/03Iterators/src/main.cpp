// Section 20
// Iterators
#include<iostream>
#include<vector>
#include<list>
#include<map>

// display any vector of ints using range-based for loop 
void display(const std::vector<int> &vec)
{
    std::cout << "[ ";
    for (const auto &i: vec)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "\n================================" << std::endl;
    std::vector<int> nums{1, 2, 3, 4, 5};
    std::vector<int>::iterator it = nums.begin();               // point to 1
    std::cout << "value of iterator it: " << *it << std::endl;

    ++it;               // point to 2
    std::cout << "value of iterator ++it: " << *it << std::endl;

    it += 2;               // point to 4
    std::cout << "value of iterator it + 2: " << *it << std::endl;

    it = nums.end() - 1;
    std::cout << "value of iterator it: " << *it << std::endl;
}

void test2()
{
    std::cout << "\n================================" << std::endl;
    std::vector<int> nums{1, 2, 3, 4, 5};
    std::vector<int>::iterator it = nums.begin();

    while(it != nums.end())
        std::cout << *(it++) << " ";
    std::cout << std::endl;

    it = nums.begin();
    while (it != nums.end())
        *(it++) = 0;
    
    std::cout << std::endl;
    display(nums);

}

void test3()
{
    std::cout << "\n================================" << std::endl;
    std::vector<int> nums{1, 2, 3, 4, 5};
    // std::vector<int>::const_iterator it = nums.begin();          // const_iterator olduğu için nums.begin() olabilir
    auto it = nums.cbegin();            // buradaki fark nums.cbegin() demek zorundayım
                                        // çünkü auto olarak belirtiyorum.

    while(it != nums.end())
        std::cout << *(it++) << " ";
    std::cout << std::endl;

    it = nums.begin();
    // while (it != nums.end())
    //     *(it++) = 0;
    
    std::cout << std::endl;
    display(nums);
}

void test4()
{
    std::cout << "\n================================" << std::endl;
    std::vector<int> nums{1, 2, 3, 4, 5};
    auto it = nums.rbegin();

    while(it != nums.rend())
        std::cout << *(it++) << " ";
    std::cout << std::endl;

    // const reverse iterator over a list
    std::list<std::string> name{"Ahmet", "Joe", "Ali"};
    auto it1 = name.crbegin();
    std::cout << *it1 << std::endl;
    ++it1;
    std::cout << *it1 << std::endl;

    std::cout << "\n--------------" << std::endl;
    // over a map
    std::map<std::string, std::string> favorites{
        {"Boris", "C"},
        {"Can", "C++"},
        {"Jo", "Python"}
    };

    auto it2 = favorites.begin();   // iterator over map of string, string pairs
    while(it2 != favorites.end()){
        std::cout << it2->first << ": " << it2->second << std::endl;
        ++it2;
    }
}

void test5()
{
    // iterate over a subset of a container
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto start = vec.begin() + 2;   // 3
    auto finish = vec.end() - 3;    // 8

    while(start != finish)
        std::cout << *(start++) << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}











