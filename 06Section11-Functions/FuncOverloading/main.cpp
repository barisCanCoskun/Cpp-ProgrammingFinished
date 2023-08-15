//Section 11
//Function Overloading
#include<iostream>
#include<string>
#include<vector>

using namespace std;

void print(int = 22);
void print(float = 26.5F);
void print(string);
void print(string, string);
void print(vector<string>);


int main()
{
    // print();     // print() is amiguous
    print(100);     // int 

    print('A');     // character is always promoted to int should print 65 ASCII ('A')

    print(67.8F);   // default double. every float number is by default double

    print("Ahmet");

    print("gullu", "kamil");

    vector<string> v {"kirmizi", "sari", "lacivert"};
    print(v);

    return 0;
    
}

void print(int num)
{
    cout << "Printing int: " << num << endl;
}

void print(float num)
{
    cout << "Printing float: " << num << endl;
}

void print(string s)
{
    cout << "Printing string: " << s << endl;
}

void print(string s1, string s2)
{
    cout << "Printing 2 strings: " << s1 << " and " << s2 << endl;
}

void print(vector<string> v)
{
    cout << "Printing vector of strings: " << endl;
    for(auto s: v)
        cout << s + " ";
    
    cout << endl;
}











