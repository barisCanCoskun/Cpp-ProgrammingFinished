#include<iostream>
#include<string>
#include<vector>

using namespace std;

void pass_by_value2(string s);
void pass_by_value3(vector<string> v);
void print_vector(vector<string> v);

int main()
{
    string name{"Baris"};

    cout << "name before calling pass_by_value2: " << name << endl;
    pass_by_value2(name);
    cout << "name after calling pass_by_value2: " << name << endl;

    vector<string> stooges{"Lary", "Moe", "Curly"};
    cout << "\nstooges before calling pass_by_value3: ";
    print_vector(stooges);

    pass_by_value3(stooges);
    cout << "\nstooges after calling pass_by_value3: ";
    print_vector(stooges);

    return 0;
    
}

void pass_by_value2(string s)
{
    s = "Changed";              
}

void pass_by_value3(vector<string> v)
{
    v.clear();      // delete all vector elements
}

void print_vector(vector<string> v)
{
    for(auto s: v)
        cout << s << " ";
    
    cout << endl;
}











