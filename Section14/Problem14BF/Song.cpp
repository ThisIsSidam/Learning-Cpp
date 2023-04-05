#include "Song.h"
#include <string>
#include <iostream>
#include <iomanip>

Song::Song()
    : name{"Unknown"}, creator{"Unknown"}, rating{0} {};

Song::Song(std::string s, std::string c, int r)
    : name{s}, creator{c}, rating{r} {};

std::string Song::get_name() {
    return name;
}

std::ostream& operator<< (std::ostream &os, const Song &obj) {
    os << std::setw(20) << std::left << obj.name 
       << std::setw(25) << std::right << obj.creator
       << std::setw(5) << std::right << obj.rating << '\n';
    
    return os;
}