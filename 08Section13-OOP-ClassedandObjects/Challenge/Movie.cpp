#include<iostream>
#include"Movie.h"

Movie::Movie(std::string n, std::string r, int w)
	: name{n}, rating{r}, num_watched{w} {
	// std::cout << "Constructor called for: " + name << std::endl;
}

Movie::Movie(const Movie &source)
	: Movie{source.name, source.rating, source.num_watched} {		
	// std::cout << "Copy constructor - made copy for: " + name << std::endl;	
}

Movie::~Movie()
{
	// std::cout << "Destructor for " << name << std::endl;	
}

void Movie::display() const
{
	std::cout << name << ", " << rating << ", " << num_watched << std::endl;
}





