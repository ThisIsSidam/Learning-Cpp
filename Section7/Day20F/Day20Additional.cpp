#include "Day20Additional.h"

// Day20Additonal::Day20Additonal()
// {}

// Day20Additonal::~Day20Additonal()
// {}

void Day20Additional::set_hp(int i)
{
    hp = i;
}

int Day20Additional::get_hp()
{
    return hp;
}

void Day20Additional::double_hp()
{
    hp *= 2;
}

void Day20Additional::null_hp()
{
    hp = 0;
}