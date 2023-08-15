#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1;                  //Empty : Unlike C-style strings, C++ strings are always initialized. s1 is initialized to empty string. 
    
    string s2{"Baris"};         // Baris
    
    string s3{s2};              // Baris
    
    string s4 {"Baris", 3};     // Bar

    string s5 {s3, 0, 2};       // Ba

    string s6 (3, 'Y');         // YYY

    string s7{"C++ Rocks!"};

    string s8{"Hello"};

    s8 = s7;
    cout << s8 << endl;

    string part1{"C++"};
    string part2{"is a powerful"};

    string sentence;

    sentence = part1 + " " + part2 + " " + "language";

    cout << "\n" << sentence << endl;

    // sentence = "C++ " + " is a powerful";               // illegal!!!

    cout << endl;

    string str1{"Baris"};
    size_t i{0};

    for(char c:str1){                    // range based for loop 
        i++;
        cout << c << endl;
    }
    cout << "i = " << i << endl;

    cout << endl;

    for(int c:str1)
        cout << c;

    cout << endl;

    string str{"This is a test"};

    cout << str.substr(0, 4);        // This 
    cout << str.substr(4, 3);        // is 
    cout << str.substr(9, 5);       // test 

    cout << endl;

    cout << str.erase(0, 5);

    cout << endl;
    cout << str.erase(3, 7);

    string fullname{};
    cout << "Enter full name: ";
    getline(cin, fullname);

    cout << "Fullname: " << fullname << endl; 

    string str2{"I'm in house too"};

    string word{};
    cout << "Enter word to find: ";
    cin >> word;

    size_t position = str2.find(word);
    if(position != string::npos)
        cout << "Found " << word << " at position " << position << endl;
    else 
        cout << word << " not found." << endl;

    

    return 0;
    
}