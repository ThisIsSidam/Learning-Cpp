#include "Movies.h"
#include <vector>
#include <iostream>

Movies::Movies(const Movie &film)
{
    list.push_back(film);
}

int Movies::search_movie(const Movie film) const
{
    for (size_t i {0}; i < list.size(); i++)
    {
        if ((list.at(i)).get_name() == film.get_name())
        {
            return i;
        } 
    }
    return -1;

}

void Movies::add_movie(const Movie &film)
{
    if (search_movie(film) != -1)
    {
        std::cout << "Movie Already Present!" << '\n';
    }
    else
    {
        list.push_back(film);
        std::cout << "Movie Added To List" << '\n';
    }
}

void Movies::remove_movie(const Movie film)
{
    int const movie_index {search_movie(film)};

    if (movie_index == -1)
    {
        std::cout << "Movie Not Found!" << '\n';
    }
    else
    {
        list.erase(list.begin() + movie_index);
        std::cout << "Movie Removed From List" << '\n';
    }
}

void Movies::print_movies_list() const
{
    for(Movie i: list)
    {
        std::cout << i.get_name() << '\n';
    }
}

Movies::~Movies()
{};