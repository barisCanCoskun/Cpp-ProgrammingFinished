#include<iostream>
#include<string>

using namespace std;

class Player
{
private:
	string name{"XXXX"};
	int health;
	int xp;
public:
	void set_name(string n){
		name = n;
	}

	// Overloaded Constructors
	Player(){		// No Args constructor
		name = "None";		// assignment not initialization
		health = 0;
		xp = 0;
		cout << "No args constructor called" << endl;
	}
	Player(string n){
		name = n;
		health = 0;
		xp = 0;
		cout << "String arg constructor called" << endl;
	}
	Player(int h, string n, int xp_val){
		name = n;
		health = h;
		xp = xp_val;
		cout << "Three args constructor, first:int called" << endl;
	}
	Player(string n, int h, int xp_val){
		name = n;
		health = h;
		xp = xp_val;
		cout << "Three args constructor, first:str called" << endl;
	}
	Player(int h){
		name = "None";		// assignment not initialization
		health = h;
		xp = 0;
		cout << "Int arg constructor called" << endl;
	}
	// Destructor
	~Player();		// cannot be overloaded.
					// useful to release memory and other resources
};

// Player::Player(int h)
// {
// 	health = h;
// }

Player::~Player()
{
	cout << "Destructor for " << name << endl;	
}

class Account
{
private:
	string name;
	double balance;
public:
	// Overloaded Constructors
	Account();		// No Args constructor
	Account(string name);
	Account(double balance);
	Account(string name, double balance);
	// Destructor
	~Account();		// cannot be overloaded
					// useful to release memory and other resources
};

Account::Account(/* args */)
{
}

Account::~Account()
{
}

int main()
{	
	// mehmet object is within the scope of this block. 
	// When it goes out of scope, the destructor will be called automatically. 
	{Player mehmet{100};}
	
	{
		Player ahmet;
		ahmet.set_name("Ahmet");
	}
	
	{
		Player ali{80, "Ali", 70};
		Player veli{"Veli"};
	}

	// Player test{95, 5, "Test"};

	Player *enemy{new Player};
	enemy->set_name("Enemy");

	delete enemy;
	enemy = nullptr;	

    return 0;
}










