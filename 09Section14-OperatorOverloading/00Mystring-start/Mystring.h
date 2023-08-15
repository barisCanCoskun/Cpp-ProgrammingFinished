#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include<string>

class Mystring
{
private:
    char *str;      // pointer to char[] that holds a C-style string 

public:
	// No-args ctor
    Mystring();
    // Overloaded ctor
    Mystring(const char *s);
    // Copy ctor
    Mystring(const Mystring &source);
    // Move ctor
    Mystring(Mystring &&source) noexcept;
    // Destructor
    ~Mystring();
    
    // Display
    void display() const;
    // getter str
    char * get_str() const;
    // getter length
    int get_length() const;

    // Assignment Operator overloading copy
    Mystring &operator=(const Mystring &);
    // Assignment Operator overloading move
    Mystring &operator=(Mystring &&);
    // Minus operator overloading
    Mystring operator-() const;
    
};

#endif  // _MYSTRING_H_










 