#include "Movie.h"
#include <iostream>

Movie::Movie(std::string n, std::string rate, int num)
    : name{n}, rating{rate}, watch_num{num} {};

Movie::Movie(const Movie &film)
    : Movie{film.name, film.rating} {};

void Movie::watch_add(int num)
{
    watch_num += num;
    std::cout << "Watch Time No. For " << this << "Updated!!" << '\n';
};

void Movie::print_details() const
{   
    std::cout << "=======================================" << '\n';
    std::cout << "Name - " << name << '\n';
    std::cout << "Rating - " << rating << '\n';
    std::cout << "Watch Time No. - " << watch_num << '\n';
    std::cout << "=======================================" << '\n';
}

Movie::~Movie() {};