// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 29/04/2022
//
// Day20 Of Learning C++
// --------------------------------------


#include <iostream>
#include "Day20Additional.h"

int main()
{

    Day20Additional franky;
    franky.set_name("Frank");
    franky.set_age(77);
    std::cout << franky.get_name() << std::endl;
    std::cout << franky.get_age() << std::endl;

    return 0;

};