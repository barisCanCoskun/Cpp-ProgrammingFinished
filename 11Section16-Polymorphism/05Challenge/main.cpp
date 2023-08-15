#include<iostream>
#include<vector>

#include"Trust_Account.h"
#include"Checking_Account.h"
// #include"Savings_Account.h"
#include"Account_Util.h"

using namespace std;

int main()
{
    // Account mo;
    Checking_Account baris_check;
    cout << baris_check << endl;

    Savings_Account ahmet{"Ahmet", 1000.0};

    Account *ptr = new Trust_Account("Leo", 10000, 2.6);
    cout << *ptr << endl;

    Account *p1 = new Checking_Account("Larry", 10000);
    Account *p2 = new Savings_Account("Moe", 2000);
    Account *p3 = new Trust_Account("Curly", 252);

    std::vector <Account *> accounts{p1, p2, p3};

    display(accounts);
    deposit(accounts, 250);
    withdraw(accounts, 100);

    display(accounts);

    delete p1;
    delete p2;
    delete p3;

    return 0;
}










