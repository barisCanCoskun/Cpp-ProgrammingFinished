#include<iostream>
#include<vector>
#include<string>

using namespace std;

void pass_by_ref1(int &num);
void pass_by_ref2(string &s);
void pass_by_ref3(const vector<string> &);

void print(const vector<int> &);        // I've told the compiler to use pass by constant reference 

int main()
{
    vector<int> data {1, 2, 3, 4, 5};
    print(data);

    vector<string> vector1{"Ahmet", "Mehmet", "Huseyin"};
    pass_by_ref3(vector1);

    int num{7};
    cout << "Before pass_by_ref1 num: " << num << endl;
    pass_by_ref1(num);
    cout << "After pass_by_ref1 num: " << num << endl;

    string str{"Ahmet"};
    cout << "Before pass_by_ref2 str : " << str << endl;
    pass_by_ref2(str);
    cout << "After pass_by_ref2 num: " << str << endl;

    return 0;
}

void pass_by_ref2(string &s)
{
    s = "Mehmet";
}

void pass_by_ref1(int &num)
{
    num = 67;
}

void pass_by_ref3(const vector<string> &v)
{
    for (auto s: v)
        cout << s << endl;
    
}

void print(const vector<int> &v)        // I've told the compiler to use pass by constant reference 
{
    // v.at(0) = 25;               // compiler error
    for(const auto i: v)
        cout << i << endl;
}










