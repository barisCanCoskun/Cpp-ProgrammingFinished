#include"Mystring.h"
#include<cstring>
#include<iostream>

// No -args ctor
Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str ='\0';
}

// Overloaded ctor
Mystring::Mystring(const char *s)
    : str{nullptr} {
    if(s == nullptr){
        str = new char[1];
        *str ='\0';
    }
    else{
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// Copy ctor
Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
    str = new char[strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// Move ctor
Mystring::Mystring(Mystring &&source) noexcept
    : str{source.str} {     // shallow copy
        source.str = nullptr;
}

// Destructor
Mystring::~Mystring()
{
    delete [] str;
    str = nullptr;      // move assignment için gerek yok.
}

// Display
void Mystring::display() const
{
    std::cout << str << ", length of str: " << strlen(str) << std::endl;
}

// getter str
char *Mystring::get_str() const
{
    return str;
}

// getter length
int Mystring::get_length() const
{
    return strlen(str);
}

// Assignment Operator overloading copy
// Return the current by reference to allow chain assignment 
// s1 = s2 = s3;
Mystring & Mystring::operator=(const Mystring &rhs)
{
    if(this != &rhs){
        delete [] str;
        str = new char[strlen(rhs.str) + 1];
        std::strcpy(str, rhs.str);
    }
    return *this;
}

// Assignment Operator overloading move
Mystring &Mystring::operator=(Mystring &&rhs)
{
    if(this != &rhs){
        delete [] str;    
        str = rhs.str;  // shallow copy
        rhs.str = nullptr;
    }
    return *this;
}

// Minus operator overloading
Mystring Mystring::operator-() const
{
    char *buff = new char [strlen(str) + 1];
    strcpy(buff, str);
    for (size_t i = 0; i < strlen(buff); i++)
    {
        buff[i] = tolower(buff[i]);
    }

    Mystring temp{buff};
    delete [] buff;
    
    return temp;
}











