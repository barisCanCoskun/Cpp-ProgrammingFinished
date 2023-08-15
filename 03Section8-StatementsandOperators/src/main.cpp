#include<iostream>

using namespace std;

int main()
{
    bool equal_result{false};
    bool not_equal_result{false};

    int num1{}, num2{};

    cout << boolalpha;      // will display true/false instead of 1/0 for booleans

    // cout << "Enter 2 integers seperated by a space:";
    // cin >> num1 >> num2;

    // equal_result = (num1 == num2);
    // not_equal_result = (num1 != num2);

    // cout << "Comparison result(equals): " << equal_result << endl;
    // cout << "Comparison result(not equals): " << not_equal_result << endl;

    float num3{}, num4{};

    cout << "Enter an integer and a float seperated by a space:";
    cin >> num1 >> num3;

    equal_result = (num1 == num3);
    not_equal_result = (num1 != num3);

    cout << "Comparison result(equals): " << equal_result << endl;
    cout << "Comparison result(not equals): " << not_equal_result << endl;

    // cout << "Enter 2 floats seperated by a space:";
    // cin >> num4 >> num3;

    // equal_result = (num4 == num3);
    // not_equal_result = (num4 != num3);

    // cout << "Comparison result(equals): " << equal_result << endl;
    // cout << "Comparison result(not equals): " << not_equal_result << endl;

    cout << "Enter 2 integers seperated by a space:";
    cin >> num1 >> num2;

    // cout << num1 << " <=> " << num2 << " : " << (num1 <=> num2) << endl;        // (<=>) c++20 ile çalıştığı için compiler derlemiyor..

    return 0;
    
}