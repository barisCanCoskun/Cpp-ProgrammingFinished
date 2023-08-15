#include<iostream>
#include "Account.h"

using namespace std;

int main()
{
	Account baris_account;
	baris_account.set_name("Baris' Account");
	baris_account.set_balance(1000.0);

	if(baris_account.deposit(200.0))
		cout << "Deposit OK. balance: " << baris_account.get_balance() << endl;
	else
		cout << "Deposit not allowed. balance: " << baris_account.get_balance() << endl;

	if(baris_account.withdraw(700))
		cout << "Withdraw OK. balance: " << baris_account.get_balance() << endl; 
	else
		cout << "Withdraw not allowed. balance: " << baris_account.get_balance() << endl;

	if(baris_account.withdraw(600))
		cout << "Withdraw OK. balance: " << baris_account.get_balance() << endl; 
	else
		cout << "Withdraw not allowed. balance: " << baris_account.get_balance() << endl;


    return 0;
}










