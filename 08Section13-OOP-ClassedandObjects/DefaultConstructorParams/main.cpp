#include<iostream>
#include<string>

using namespace std;

class Player
{
private:
	string name{"XXXXX"};	// order of initialization is order of declaration in the class
	int health;
	int xp;
public:
	void set_name(string n){
		name = n;
	}

	// Constructor with DEfault param values
	// Player(string n = "None", int h = 0, int xp_val = 0){
	// 	cout << "Three args constructor, first:str called" << endl;
	// }

	Player(string n = "None", int h = 0, int xp_val = 0)
		: name{n}, health{h}, xp{xp_val} {
		cout << "Three args constructor, first:str called" << endl;
	}

	Player(int h, string n, int xp_val)
		: Player{n, h, xp_val} {
		cout << "Three args constructor, first:int called" << endl;
	}
	Player(int h)
		: Player{"None", h} {
		cout << "Int arg constructor called" << endl;
	}
	// Destructor
	~Player();		// cannot be overloaded.
					// useful to release memory and other resources
};

Player::~Player()
{
	cout << "Destructor for " << name << endl;	
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










