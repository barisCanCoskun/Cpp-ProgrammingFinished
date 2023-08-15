#include<iostream>
#include"Savings_Account.h"

using namespace std;

int main()
{
    Account a;
    a.deposit(1000);
    a.withdraw(200);

    Savings_Account s{300, 1};
    s.deposit(300);
    s.withdraw(100);

    return 0;
}










