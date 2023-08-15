#include<iostream>
#include"Player.h"

int Player::num_players{0};

Player::Player(const Player &source)
	: Player{source.name, source.health, source.xp} {		
	std::cout << "Copy constructor - made copy for: " + name << std::endl;	
}

Player::Player(std::string n, int h, int xp_val)
		: name{n}, health{h}, xp{xp_val} {
        num_players++;
		std::cout << "Constructor called for: " + name << std::endl;
}

Player::~Player()
{
    num_players--;  
	std::cout << "Destructor for " << name << std::endl;	
}

int Player::get_num_players()
{
    return num_players; 
}





