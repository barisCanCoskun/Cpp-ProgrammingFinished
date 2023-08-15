#include "Account.h"
#include<iostream>

void Account::set_name(std::string n){
    name = n;
}

std::string Account::get_name(){
    return name;
}

void Account::set_balance(double amount){
    balance = amount;
}

double Account::get_balance(){
    return balance;
}

bool Account::deposit(double amount){
    if(amount >= 0){
        std::cout << "After $" << amount << " deposit." << std::endl;
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
        std::cout << "After $" << amount << " withrawal." << std::endl; 
        balance -= amount; 
        return 1;
    } 
    else {
        std::cout << "Withdrawal amount: $" << amount << " bigger than balance." << std::endl;
        return 0;
    }
}









