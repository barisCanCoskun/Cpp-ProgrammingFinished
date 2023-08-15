#ifndef _PLAYER_H_
#define _PLAYER_H_

#include<string>

class Player
{
private:
    friend void display_Player(Player p);		// testing purpose
    static int num_players;
	std::string name;	
	int health;
	int xp;
public:
	void set_name(std::string n){
		name = n;
	}
	//getters
	std::string get_name() {return name;}
	int get_health() {return health;}
	int get_xp() {return xp;}

	// Copy Constructor
	Player(const Player &source);
	Player(std::string n = "None", int h = 0, int xp_val = 0);
	~Player();		

    static int get_num_players();
};

#endif  // _PLAYER_H_










 