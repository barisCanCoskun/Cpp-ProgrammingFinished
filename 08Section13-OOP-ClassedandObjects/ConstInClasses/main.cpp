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

	string get_name() const {return name;}

	Player(string n, int h, int xp_val);

};

Player::Player(string n, int h, int xp_val)
		: name{n}, health{h}, xp{xp_val} {
		cout << "Constructor called for: " + name << endl;
}

void display_Player(Player p){
	cout << "Name: " << p.get_name() << endl;
	// cout << "Health: " << p.get_health() << endl;
	// cout << "Xp: " << p.get_xp() << endl;
}

int main()
{	
	const Player juan{"Juan", 90, 7};
	
	cout << juan.get_name() << endl;

    return 0;
}










