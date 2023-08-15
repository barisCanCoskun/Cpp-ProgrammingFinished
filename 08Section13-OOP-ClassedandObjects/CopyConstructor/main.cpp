#include<iostream>
#include<string>

using namespace std;

class Player
{
private:
	string name;	
	int health;
	int xp;
public:
	void set_name(string n){
		name = n;
	}

	//getters
	string get_name() const {return name;}
	int get_health() {return health;}
	int get_xp() {return xp;}

	// Copy Constructor
	Player(const Player &source);

	Player(string n = "None", int h = 0, int xp_val = 0);

	~Player();		// cannot be overloaded.
					// useful to release memory and other resources
};

Player::Player(const Player &source)
	// : name{source.name}, health{source.health}, xp{source.xp} 
	: Player{source.name, source.health, source.xp} {		// as Delegating Ctor
	cout << "Copy constructor - made copy for: " + name << endl;	
}

Player::Player(string n, int h, int xp_val)
		: name{n}, health{h}, xp{xp_val} {
		cout << "Constructor called for: " + name << endl;
}

Player::~Player()
{
	cout << "Destructor for " << name << endl;	
}

void display_Player(Player p){
	cout << "Name: " << p.get_name() << endl;
	cout << "Health: " << p.get_health() << endl;
	cout << "Xp: " << p.get_xp() << endl;
}

Player create_enemy()
{
	Player e{"Enemy", 75, 5};

	return e;	// The compiler will usually use copy elision and optimize away the copy.
				// The compiler optimizes the copy away.
}

int main()
{	
	Player pole{"Pole"};

	Player north{pole};		// to Copy Constructor

	Player south{"South"};
	display_Player(south);		// to Copy Constructor

	Player enemy;
	enemy = create_enemy();

	const Player ahmet{"Ahmet", 80, 7};
	ahmet.get_name();

    return 0;
}










