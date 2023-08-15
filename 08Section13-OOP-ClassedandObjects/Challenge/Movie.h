#ifndef _MOVIE_H_
#define _MOVIE_H_

#include<string>

class Movie
{
    // friend class Movies;	
	std::string name;	
	std::string rating;		// G, PG, PG-13, R
	int num_watched;
public:
	Movie(std::string n = "None", std::string r = "None", int w = 0);
	// Copy Constructor
	Movie(const Movie &source);
	~Movie();

	void set_name(std::string n) {name = n;}
	std::string get_name() const {return name;}

	void set_rating(std::string r) {rating = r;}
	std::string get_rating() const {return rating;}

	void set_watched(int w) {num_watched = w;}
	int get_watched() const {return num_watched;}

	void increment_watched() {num_watched++;}

	void display() const;
};

#endif  // _MOVIE_H_










 