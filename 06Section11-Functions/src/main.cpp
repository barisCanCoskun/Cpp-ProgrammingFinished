#include<iostream>
#include<cmath>         // required

using namespace std;

int main()
{
    float num{};

    cout << "Enter a number(float): ";
    cin >> num;

    cout << "The sqrt of " << num << " is: " << sqrt(num) << endl;
    cout << "The cubed root of " << num << " is: " << cbrt(num) << endl;

    float power{};
    cout << "Enter a power to raise: " << num << " to: ";
    cin >> power;
    cout << num << " raised to the " << power << " power is: " << pow(num, power) << endl;

    return 0;
    
}