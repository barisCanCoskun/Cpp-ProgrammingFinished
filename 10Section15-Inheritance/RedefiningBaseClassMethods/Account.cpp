#include "Account.h"
#include<iostream>

Account::Account(double amount)
    : balance{amount} {
    
}

Account::Account()
    : Account{0.0} {

}

bool Account::deposit(double amount){
    if(amount >= 0){
        std::cout << "After $" << amount << " deposit, balance: " << balance << std::endl;
        balance += amount; 
        return 1;
    } 
    else {
        std::cout << "Deposit Amount cant be negative.";
        return 0;
    }
}

bool Account::withdraw(double amount){
    if(balance >= amount){
        std::cout << "After $" << amount << " withrawal, balance: " << balance << std::endl; 
        balance -= amount; 
        return 1;
    } 
    else {
        std::cout << "Insufficient funds." << std::endl;
        return 0;
    }
}

std::ostream &operator<<(std::ostream &os, const Account&acc)
{
    os << "Account balance: " << acc.balance << std::endl;
    return os;
}









