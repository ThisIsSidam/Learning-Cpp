// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 03/03/2023
//
// Problem13A Of Learning C++
// After Day37
// Name - I am a Tour Guide
// --------------------------------------

/* 
This time we gotta show a chart thingy that will show the name of the tourism 
group/company. Below it, it will have coutry names with categorized city names,
with their population and price for traveling there. It's just a simple decorated
chart thiny. Go!

Structs are basically just classes where everything is kept public. So, if you don't 
wanna mess with contructors and stuff, and just want your data to be in a better 
form that doesn't seem cluttered. Use struct.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

struct City {
    std::string name;
    long population;
    int fee;
    int rating;
};

struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Travel {
    std::string name;
    std::vector<Country> countries;
};

void show_board(const Travel);

int main() {

    // City first {"Kolkata", 50000000, 8000, 4};
    // std::vector<City> second {first};
    // Country third {"India", second};
    // std::vector<Country> fourth {third};
    // Travel tour {"Anshu", fourth};

    // conti.push_back(City{})

    Travel tour { "Anshu Tourism Group", {
        Country{ "India", {
            City{ "Delhi", 120000000, 10000, 3}, 
            City{ "Mumbai", 60000000, 15000, 4},
            City{ "Kolkata", 50000000, 8000, 4} 
            } 
        }, 
        Country{ "Japan", {
            City{ "Tokyo", 200000, 200000, 5},
            City{ "Kyoto", 150000, 175000, 4} }
        }, 
        Country{ "France", {
            City{ "Paris", 1000000, 250000, 4} }
        } 
        }
    };

    show_board(tour);



    return 0;
}

void show_board(const Travel obj) {

    std::cout << "================================================================================\n";

    std::cout << std::setw(45) << obj.name << '\n';

    std::cout << "================================================================================\n";

    std::cout << std::setw(15) << std::left << "Country" 
              << std::setw(15) << std::left << "City" 
              << std::setw(15) << std::left << "Population"
              << std::setw(15) << std::right << "Fee"
              << std::setw(15) << std::right << "Rating" << '\n';

    for (auto country: obj.countries) {

        std::cout << std::setw(15) << std::left << country.name << '\n';

        for (auto city: country.cities) {
            std::cout << "               ";
            std::cout << std::setw(15) << std::left << city.name
                      << std::setw(15) << std::left << city.population
                      << std::setw(15) << std::right << city.fee
                      << std::setw(13) << std::right << city.rating 
                      << "/5" << '\n';
        }
    }
}