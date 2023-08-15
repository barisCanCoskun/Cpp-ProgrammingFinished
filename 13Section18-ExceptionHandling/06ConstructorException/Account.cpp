#include "Account.h"
#include<iostream>
#include"IllegalBalancedException.h"

Account::Account(std::string n, double bal)
    : name{n}, balance{bal} {
    
    if(bal < 0)
		throw IllegalBalanceException{};

}

bool Account::deposit(double amount){
    if(amount >= 0){
        // std::cout << "After $" << amount << " deposit, balance: " << balance << std::endl;
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
        // std::cout << "After $" << amount << " withrawal, balance: " << balance << std::endl; 
        balance -= amount; 
        return true;
    } 
    else {
        std::cout << "Insufficient funds." << std::endl;
        return false;
    }
}

void Account::print(std::ostream &os) const 
{
    os << "[Account: " << name << " : $" << balance << " ]";
}










