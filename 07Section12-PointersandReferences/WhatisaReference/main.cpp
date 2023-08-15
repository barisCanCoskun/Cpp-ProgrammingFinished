#include<iostream>
#include<vector>

using namespace std;

void print_vector(const vector<string> &v);
void change_vector(vector<string> v);

int main()
{
    vector<string> vector1{"Joe", "hu", "ok"};

    string x{"kale"};
    print_vector(vector1);

    change_vector(vector1);
    cout << "printing reference to auto in func: " << endl;
    print_vector(vector1);

    for (auto &str: vector1)
        str = "Dunham";
    cout << "\nprinting reference to auto in main: " << endl;
    print_vector(vector1);

    int num{7};
    int &ref{num};

    cout << "\nnum: " << num << endl;
    cout << "ref: " << ref << endl;
    
    num = 8;
    cout << "\nnum: " << num << endl;
    cout << "ref: " << ref << endl;
    
    ref = 9;
    cout << "\nnum: " << num << endl;
    cout << "ref: " << ref << endl;
    

    return 0;

// When we use the range based for loop we aren't passing any values at all. 
// We iterating through the container and using the container elements one at a time 
// in each iteration.
// If we don't use an ampersand, then a copy of the container element is made each time. 
// If we use an ampersand (a reference) then no copy will be made and 
// the container element will be accessed by reference.
}

void change_vector(vector<string> v)
{
    for (auto &str: v)
        str = "Dunham";
    
}

void print_vector(const vector<string> &v)
{
    for (auto const &str: v)        // If we don't use an ampersand, then a copy of the container element is made each time.
    {
        cout << str << endl;
    }
    
}











