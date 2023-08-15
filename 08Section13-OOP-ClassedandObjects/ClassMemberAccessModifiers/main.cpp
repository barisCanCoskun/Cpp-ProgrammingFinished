#include<iostream>

using namespace std;

class Account
{
private:
    //attributes
	string name{"Account"};
	double balance{0.0};

public:
	//methods
	bool withdraw(double amount) {
		cout << "After $" << amount << " withrawal." << endl; 
		balance -= amount; if(balance >= 0)return 1; else return 0;}
	bool deposit(double amount){
		cout << "After $" << amount << " deposit." << endl;
		balance += amount; if(balance >= 0)return 1; else return 0;}
};

int main()
{
	
    return 0;
}










