#include<iostream>

using namespace std;

int main()
{
    string s1 {"Baris"};
    string s2 {"Baris"};

    string *p1{&s1};
    string *p2{&s2};
    string *p3{&s1};

    cout << boolalpha;

    cout << "(p1 == p2) : " << (p1 == p2) << endl; // false
    cout << "(p1 == p3) : " << (p1 == p3) << endl; // true

    cout << "(*p1 == *p3) : " << (*p1 == *p3) << endl; // true
    cout << "(*p1 == *p2) : " << (*p1 == *p2) << endl; // true
    cout << endl;

    int scores[]{100, 90, 75, 55, -1};
    int *score_ptr{scores};

    while(*score_ptr != -1){
        cout << *score_ptr++ << endl;
    }
    

// pointer arithmetic only makes sense with raw arrays

    return 0;
}









