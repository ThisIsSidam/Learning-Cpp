#ifndef DAY20ADDITIONAL_H
#define DAY20ADDITIONAL_H

#include <string>
// #pragma once

class Day20Additional
{
private:
    std::string name;
    int age;

public:
    // Day20Additional();
    // ~Day20Additional();
    void set_name(std::string);
    std::string get_name();
    void set_age(int);
    int get_age();
};

#endif