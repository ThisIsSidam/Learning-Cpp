// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 00/00/0000
//
// Problem8 of Learning C++
// After Day23
// Name- The Movie Manager
// --------------------------------------

/*
* Here, we'll making a movie manager program, where there will be a class called
* movies, that will be like a folder/section/family of movies. So, it's only
* attribute will be a vector of other class called movie, and that class will 
* be movie class, it's a class with details about a specific movie. It's must 
* attributes will be it's name, rating, and the no. of times you have watched the
* movie. You can add more data members as you want. And yeah make the
* classes and else in different files and since there are two different classes 
* there will be a total of 5 files including the main. So, let's go.                                                                              
*/

#include <iostream>
#include "Movie.h"
#include "Movies.h"
#include <vector>

int main()
{
    Movie iron_man("Iron Man", "E", 50);
    iron_man.print_details();

    Movie first_avenger("Captain America: The First Avenger", "PG13", 60);

    Movies Marvel(iron_man);
    Marvel.add_movie(first_avenger);
    Marvel.print_movies_list();

    first_avenger.print_details();

    Movie nemo("Finding Nemo", "E");

    Marvel.add_movie(nemo);
    Marvel.print_movies_list();

    Marvel.remove_movie(nemo);
    Marvel.print_movies_list();
    nemo.print_details();


    
    return 0;
}