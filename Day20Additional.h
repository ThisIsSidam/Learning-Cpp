#ifndef DAY20ADDITIONAL_H
#define DAY20ADDITIONAL_H
#include <string>
// #pragma once

class Day20Additional
{
private:
    std::string name;
    int hp;

public:
    //Day20Additional();
    //~Day20Additional();
    void set_name(std::string str)
    {
        name = str;
    }
    std::string get_name()
    {
        return name;
    }
    void set_hp(int h);
    int get_hp();
    void double_hp();
    void null_hp();
};

#endif