#include<iostream>
#include"Movies.h"
#include<string>

// Movies::Movies(const Movies &source)
// 	: Movies{source.name, source.health, source.xp} {		
// 	std::cout << "Copy constructor - made copy for: " + name << std::endl;	
// }

// Movies::Movies(std::string n, std::string r, int w)
// 	: name{n}, rating{r} {
// 	std::cout << "Constructor called for: " + name << std::endl;
// }

Movies::Movies()
{

}

Movies::~Movies()
{
	// std::cout << "Destructor for " << name << std::endl;	
}

bool Movies::increment_watched(std::string n){
	for (auto &m : movies)
	{
		if(m.get_name() == n){		// string compare
			m.increment_watched();
			return true;
		}
	}
	return false;
}

bool Movies::add_movie(std::string n, std::string r, int w){
	for (auto &m : movies)
	{
		if(m.get_name() == n){		// string compare
			return false;
		}
	}
	movies.push_back(Movie{n, r, w});
	return true;
}

void Movies::display() const
{
	std::cout << "\n================" << std::endl;

	if(movies.size() == 0)
		std::cout << "Sorry no movies here." << std::endl;

	for (auto &m : movies)
	{
		m.display();
	}
	
	std::cout << "================\n" << std::endl;
}







