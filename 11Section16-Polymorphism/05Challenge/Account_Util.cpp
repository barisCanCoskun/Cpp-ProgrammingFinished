#include "Account_Util.h"
#include<iostream>
#include<vector>

// Display Account objects in a vector of Account obj pointers
void display(const std::vector <Account *> &accounts)
{
    std::cout << "\n======Accounts====================" << std::endl;
    for (const auto a: accounts){
        std::cout << *a << std::endl;
    }
}

// Deposits supplied amount to each Account obj in the vector 
void deposit(std::vector <Account *> &accounts, double amount)
{
    std::cout << "\n======Depositing to Accounts====================" << std::endl;
    for (auto a: accounts){
        if (a->deposit(amount))
            std::cout << "Deposited " << amount << " to " << *a << std::endl;
        else
            std::cout << "Failed Deposited of " << amount << " to " << *a << std::endl; 
    }
}

// Withdraw amount from each Account obj in the vector
void withdraw(std::vector <Account *> &accounts, double amount)
{
    std::cout << "\n======Withdrawing from Accounts====================" << std::endl;
    for (auto a: accounts) {
        if(a->withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << *a << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << *a << std::endl; 
    }
}









