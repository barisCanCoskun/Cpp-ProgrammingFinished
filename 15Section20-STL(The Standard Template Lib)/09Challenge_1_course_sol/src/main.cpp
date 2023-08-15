#include<iostream>
#include<deque>
#include<cctype>
#include<algorithm>

template<typename T>
void display(const std::deque<T> &deq)
{
    std::cout << "[ ";
    for (const auto &d: deq)
        std::cout << d << "  ";
    std::cout << "]" << std::endl;
}

bool is_palindrome(const std::string &s)
{
    std::deque<char> deq;
    std::copy_if(s.begin(), std::end(s), std::back_inserter(deq), [](char c) { return std::isalnum(c); });
    display(deq);

    char c1{};
    char c2{};
    
    while (deq.size() > 1){
        c1 = deq.front();
        c2 = deq.back();
        deq.pop_back();
        deq.pop_front();
        if(c1 != c2)
            return false;
    }

    return true;
}

int main()
{
    if(is_palindrome("abba"))
        std::cout << "abba " << "is palindrome" << std::endl;
    else
        std::cout << "abba " << "is NOT palindrome" << std::endl;
    
    if(is_palindrome("avid diva"))
        std::cout << "avid diva "  << "is palindrome" << std::endl;
    else
        std::cout << "avid diva " << "is NOT palindrome" << std::endl;

    return 0;
}














