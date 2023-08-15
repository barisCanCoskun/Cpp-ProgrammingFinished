#include "Savings_Account.h"
#include<iostream>

Savings_Account::Savings_Account(std::string n, double bal, double int_rate)
    : Account(n, bal), interest_rate{int_rate} {
    
}

bool Savings_Account::deposit(double amount){
    amount += (amount*interest_rate / 100);
    return Account::deposit(amount);
}

bool Savings_Account::withdraw(double amount){
    return Account::withdraw(amount);
}

void Savings_Account::print(std::ostream &os) const  
{
    os << "[Savings Account: " << name << " : $" << balance << " ]";
}









