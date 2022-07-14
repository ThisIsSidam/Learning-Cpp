// Part of Problem8 file.
#ifndef MOVIE_H
#define MOVIE_H
#include <string>

class Movie
{
private:
    std::string name;
    std::string rating;
    int watch_num;  //The number of times a movie is watched.

public:
    //Constructor
    Movie(std::string n, std::string rate, int num = 0);
    //Copy Constructor
    Movie(const Movie &);
    //Methods
    std::string get_name() const { return name;};
    void watch_add(int num = 1);
    void print_details() const;
    //Destructor
    ~Movie();
};

#endif