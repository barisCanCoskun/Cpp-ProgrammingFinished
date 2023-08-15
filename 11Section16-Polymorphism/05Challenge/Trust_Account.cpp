#include "Trust_Account.h"
#include<iostream>

Trust_Account::Trust_Account(std::string n, double bal, double int_rate)
    : Savings_Account(n, bal, int_rate), num_withdrawals{0} {
    
}

// Deposits of $5000.0 or more will receive $50 bonus
bool Trust_Account::deposit(double amount){
    if(amount >= bonus_threshold){
        std::cout << "\nBecause your deposit bigger than $";
        std::cout << bonus_threshold << ", you will get $" << bonus_amount << " bonus." << std::endl;

        amount += bonus_amount;
        std::cout << "\nBalance: " << balance << std::endl;
    } 
    
    return Savings_Account::deposit(amount);
}

// Only allowed maximum of 3 withdrawals, each can be up to a max 0f 20% of the account's value
bool Trust_Account::withdraw(double amount){
    if((++num_withdrawals <= max_withdrawals) && (amount < balance * max_withdraw_percent)){
        std::cout << "Max 20'%' of balance can be withdraw." << std::endl;
        return Savings_Account::withdraw(amount);
    }
    return false;
}

void Trust_Account::print(std::ostream &os) const  
{
    os << "[Trust Account: " << name << " : $" << balance << ", " << interest_rate
     << "%, withdrawals: " << num_withdrawals << " ]";
}









