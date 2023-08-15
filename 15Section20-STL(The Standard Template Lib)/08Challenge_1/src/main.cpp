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

    size_t pos_half{deq.size() / 2};
    
    // for(const auto &d: deq){
    //     if(v % 2 == 0)
    //         deq.push_back(v);
    //     else    
    //         deq.push_front(v);
    // }

    auto it1 = deq.end();
    --it1;
    for (std::deque<char>::iterator it = deq.begin(); pos_half > 0; --pos_half)
    {
        if (*it != *it1)
            return false;
        ++it;
        --it1;
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














