// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 24/03/2023
//
// Day49 Of Learning C++
// --------------------------------------

/*
== Associative Containers == 

- Collectiion of stored objects that allow fast retrieval using a key.
- STL provides Sets and Maps.
- Usually implemented as a balanced binary tree or hashsets
- Most operations are very efficient.

= Types of Maps = 

- std::map
- std::unordered_map
- std::multimap
- std::unordered_multimap

= std::map =

- Need to include <map>
- Similar to dictionary.
- Elements are stored as Key, value pairs (std::pair).
- Ordered by key and no duplicate keys are allowed.
- Elements can be directly accessed using keys.
- All iterators are available and invalidate when corresponding element
is deleted.

- Here too

= std::multi_map =

- Include <map>
- Orderd by key.
- Allows duplicate elements.
- All iterators are available.

= std::unordered_map =

- Include <unordered_map>
- Elements are unordered.
- No duplicate elements are allowed.
- No reverse iterators are allowed.

= std::unordered_multimap = 

- Include <unordered_map>
- Elements are unordered.
- Allows duplicate elements.
- No reverse iterators are allowed.
*/

#include <iostream>
#include <map>
#include <string>
#include <iomanip>

void display (std::map<int, std::string> mp) {
    auto it = mp.begin();

    std::cout << "===============\n";
    while (it != mp.end() ) 
    {
        std::cout << std::setw(10) << std::left 
                  << it->first << it->second << '\n'; 
        
        it++;
    }
    std::cout << "===============\n";
}

int main() {

    // Making this like a student register, first is Roll no. and second is
    // name of student.
    std::map<int, std::string> reg {
        {1, "Sanjana"},
        {4, "Satya"},
        {5, "Sneha"},
        {3, "Sonu"}
    };

    // Here int, the first type given, is the key while the other one is the
    // value, they can be anything. There aren't specific combinations that you 
    // have to use. Put any two in there. 

    display(reg);

    // I'm not gonna repeat methods that work the same way as prior classes.
    // Which are, size, max_size, clear, empty, count.

    // Maps dont support front and back.

    // Maps consist of std::pair objects, so we can insert elements these ways.

    // Make a std:pair object, and insert.

    std::pair<int, std::string> s1 {2, "Raushan"};
    reg.insert(s1);

    display(reg);

    // Or just use make_pair. It doesn't ask for tyes, it detects them.

    reg.insert(std::make_pair(6, "Sachin"));

    display(reg);

    // We can also use the indexing operator or .at method with Keys.

    reg[9] = "Aditya Aman";
    display(reg);

    reg[8] = "Aditya"; // Can also update it this way.
    display(reg);

    reg.at(9) = "Mukesh"; // Same with the .at method.
    display(reg);

    reg.erase(8); // Everything is done via Keys.
    display(reg);

    if (reg.find(1) != reg.end() ) 
    {
        reg.erase(1);
    }
    else 
    {
        std::cout << "Roll no. 1 not found.\n";
    }
    display(reg);

    // Always use the class provided find functions when available. They
    // are just better.

    return 0;
}