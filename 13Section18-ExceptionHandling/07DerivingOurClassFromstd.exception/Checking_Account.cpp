#include "Checking_Account.h"
#include<iostream>

Checking_Account::Checking_Account(std::string n, double bal)
    : Account(n, bal) {
    
}

bool Checking_Account::deposit(double amount){
    return Account::deposit(amount);
}

bool Checking_Account::withdraw(double amount){
    amount += per_check_fee;
    return Account::withdraw(amount);
}

void Checking_Account::print(std::ostream &os) const 
{
    os << "[Checking Account: " << name << " : $" << balance << " ]";
}












