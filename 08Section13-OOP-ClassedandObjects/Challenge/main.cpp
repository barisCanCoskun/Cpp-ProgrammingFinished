#include<iostream>
#include<string>

#include"Movies.h"

using namespace std;

void increment_watched(Movies &movies, string name)
{
	if(movies.increment_watched(name))
		cout << name << " watch incremented" << endl;
	else
		cout << name << " not found\n" << endl;
}

void add_movie(Movies &movies, string name, string rating, int watched)
{
	if(movies.add_movie(name, rating, watched))
		cout << name << " added" << endl;
	else	
		cout << name << " already exists\n" << endl;
}

int main()
{	
	Movies movies;

	movies.display();

	add_movie(movies, "BIG", "PG-13", 2);
	add_movie(movies, "THE GODFATHER", "PG", 5);
	add_movie(movies, "MATRIX", "G", 7);
	
	movies.display();

	add_movie(movies, "BIG", "PG-13", 2);

	increment_watched(movies, "MATRIX");
	movies.display();

	increment_watched(movies, "zzzz");

    return 0;
}










