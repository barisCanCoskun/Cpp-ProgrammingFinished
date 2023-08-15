#include<iostream>
#include<vector>

using namespace std;

class Player
{
public:
    //attributes
	string name{"Player"};
	int health{100};
	int xp{3};
	
	//methods : what these look like are basically func prototypes
	void talk(string text_to_say);
	bool is_dead();
};

class Account
{
public:
    //attributes
	string name{"Account"};
	double balance{0.0};
	
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
	Account baris_account;
	Account frank_account;

	baris_account.name = "Baris' account";

	baris_account.balance = 12.7;
	cout << "baris's balance: $" << baris_account.balance << endl;

	if(baris_account.withdraw(10.0))
		cout << "\nbalance positive: $" << baris_account.balance << "\n" << endl;
	else 
		cout << "\nbalance negative: $" << baris_account.balance << "\n" << endl;

	if(baris_account.withdraw(10.0))
		cout << "\nbalance positive: $" << baris_account.balance << "\n" << endl;
	else 
		cout << "\nbalance negative: $" << baris_account.balance << "\n" << endl;

	Account *accountPtr{nullptr};

	accountPtr = new Account();

	accountPtr->balance = 20.4;
	cout << "accountPtr's balance: $" << accountPtr->balance << endl;
	
	if(accountPtr->deposit(10.0))
		cout << "\nbalance positive: $" << accountPtr->balance << "\n" << endl;
	else 
		cout << "\nbalance negative: $" << accountPtr->balance << "\n" << endl;
	
	if(accountPtr->deposit(-31.0))		// zaten negative miktar deposit yapamazsınız demesi gerekli...
		cout << "\nbalance positive: $" << accountPtr->balance << "\n" << endl;
	else 
		cout << "\nbalance negative: $" << accountPtr->balance << "\n" << endl;

    Player baris;
    Player hero;

    Player *enemy{new Player()};
    // enemy = new Player;

	// member of pointer operator or arrow operator
	enemy->health = 90;
	cout << "enemy's health: " << enemy->health << endl;

	(*enemy).name = "John";
	cout << "enemy's new name: " << (*enemy).name << endl;

	Player players[]{baris, hero};

	vector<Player> player_vec{baris};
	player_vec.push_back(hero);

	delete enemy;
	enemy = nullptr;

	delete accountPtr;
	accountPtr = nullptr;

    // When debugging, The only reason that the string member name is not garbage is 
    // because our C++ standard string class has a default initializer which initializes it to empty. 

    return 0;
}










