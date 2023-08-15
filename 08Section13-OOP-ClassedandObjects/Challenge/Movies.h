#ifndef _MOVIES_H_
#define _MOVIES_H_

#include"Movie.h"
#include<string>
#include<vector>

class Movies
{
private:
	std::vector<Movie> movies;
public:
	// Copy Constructor
	// Movies(const Movies &source);
	Movies();
	~Movies();	

	bool increment_watched(std::string n);
	bool add_movie(std::string n, std::string r, int w);

	void display() const;
};

#endif  // _MOVIES_H_










 