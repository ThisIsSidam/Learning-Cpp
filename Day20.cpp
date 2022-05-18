// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 16/05/2022
//
// Day20 Of Learning C++
// --------------------------------------



#include <iostream>
#include <string>
#include "Day20Additional.h"
// #include "Day20Additional.cpp"

int main()
{
    Day20Additional hero;
    hero.set_name("Hero");
    std::cout << hero.get_name() << std::endl;

    hero.set_hp(89);
    std::cout << hero.get_hp() << std::endl;

    hero.double_hp();
    std::cout << hero.get_hp() << std::endl;

    hero.null_hp();
    std::cout << hero.get_hp() << std::endl;
    
    return 0;
}