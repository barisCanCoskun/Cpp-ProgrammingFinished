#include "Savings_Account.h"
#include<iostream>

Savings_Account::Savings_Account(double amount, double int_rate)
    : Account(amount), interest_rate{int_rate} {
    
}

Savings_Account::Savings_Account()
    : Savings_Account{0.0, 0.0} {

}

bool Savings_Account::deposit(double amount){
    if(amount >= 0){
        std::cout << "After $" << amount << " deposit,";
        amount += (amount*interest_rate / 100);
        Account::deposit(amount); 
        // balance += amount;
        std::cout << " balance: " << balance << std::endl;
        return 1;
    } 
    else {
        std::cout << "Deposit Amount cant be negative.";
        return 0;
    }
}

std::ostream &operator<<(std::ostream &os, const Savings_Account&acc)
{
    os << "Savings account balance: " << acc.balance << ". Interest rate: " << acc.interest_rate << std::endl;
    return os;
}









