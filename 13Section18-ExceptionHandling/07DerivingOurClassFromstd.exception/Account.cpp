#include "Account.h"
#include<iostream>
#include"IllegalBalancedException.h"
#include"InsufficientFundsException.h"

Account::Account(std::string n, double bal)
    : name{n}, balance{bal} {
    
    if(bal < 0)
		throw IllegalBalanceException{};

}

bool Account::deposit(double amount){
    if(amount >= 0){
        balance += amount; 
        return true;
    } 
    else {
        std::cout << "Deposit Amount cant be negative.";
        return false;
    }
}

bool Account::withdraw(double amount){
    if(balance >= amount){
        balance -= amount; 
        return true;
    } 
    else {
        throw InsufficientFundsException{};
    }
}

void Account::print(std::ostream &os) const 
{
    os << "[Account: " << name << " : $" << balance << " ]";
}










