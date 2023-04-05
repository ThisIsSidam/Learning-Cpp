#pragma once
#include <iostream>

class Song {

    friend std::ostream& operator<< (std::ostream&, const Song&);

private:
    std::string name;
    std::string creator;
    int rating;

public:
    Song();
    Song(std::string, std::string, int);

    std::string get_name();
};