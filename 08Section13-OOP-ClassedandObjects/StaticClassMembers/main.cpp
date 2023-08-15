#include<iostream>
#include<string>
#include"Player.h"

using namespace std;

void display_Player(Player p){
	cout << "Name: " << p.name << endl;		// testing purpose
	
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

void display_active_players()
{
	cout << "Active players: " << Player::get_num_players() << endl;
}

int main()
{	
	Player pole{"Pole"};
	display_active_players();

	Player north{pole};		// to Copy Constructor
	display_active_players();

	{
		Player ahmet{"Ahmet"};
		display_active_players();
	}
	// ahmet object is going out of scope and be destroyed 
	display_active_players();

	// Player south{"South"};
	// display_Player(south);		// to Copy Constructor

	// Player enemy;
	// enemy = create_enemy();

	Player *mahmut{new Player{"Mahmut", 55, 4}};
	display_active_players();

	delete mahmut;
	mahmut = nullptr;
	display_active_players();
    return 0;
}










