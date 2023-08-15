#include<iostream>
#include<memory>

#include"Trust_Account.h"
#include"Checking_Account.h"
#include"Account_Util.h"
#include"IllegalBalancedException.h"
#include"InsufficientFundsException.h"

int main()
{
    std::unique_ptr<Account> moes_account;
    std::unique_ptr<Account> joes_account;

    try{
        moes_account = std::make_unique<Checking_Account>("Moe", -10.0);
        std::cout << *moes_account << std::endl;
    }

    catch(const IllegalBalanceException &ex){
        std::cerr << ex.what() << std::endl;
        // diplays "Illegal balance exception"
    }

    try{
        joes_account = std::make_unique<Savings_Account>("Joe", 100.0);
        std::cout << *joes_account << std::endl;

        joes_account->withdraw(50.0);
        std::cout << *joes_account << std::endl;
        joes_account->withdraw(60.0);

        std::cout << "\tdeneme" << std::endl;
        moes_account = std::make_unique<Checking_Account>("Moe", -10.0);
        std::cout << *moes_account << std::endl;
    }

    catch(const InsufficientFundsException &ex){
        std::cerr << ex.what() << std::endl;
        // diplays "Insufficient funds."
    }

    catch(const IllegalBalanceException &ex){
        std::cerr << ex.what() << std::endl;
        // diplays "Illegal balance exception"
    }

    std::cout << "Program completed succesfully" << std::endl;

    return 0;
}










