#ifndef MOVIES_H
#define MOVIES_H
#include "Movie.h"
#include <vector>
#include <string>

class Movies
{
private:
    std::vector<Movie> list;

public:
    //Constructor
    Movies(const Movie &);
    //Methods
    int search_movie(const Movie) const;
    void add_movie(const Movie &);
    void remove_movie(const Movie);
    void print_movies_list() const;
    //Destructor
    ~Movies();
};

#endif