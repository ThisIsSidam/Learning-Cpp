// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 12/03/2023
//
// Day40 Of Learning C++
// --------------------------------------

/*
== String Streams ==

Allows us to read and write from strings in memory much as we would 
read and write from and to files. It is very powerful and works the
same as we work with input and output in files. It is very useful
in data validation.

Method:
1. #include <sstream>
2. Declare an object of any one of these classes: stringstream, 
istringstream and ostringstream.
3. Connect it to a std::string.
4. Read/Write data from/to the string stream using formatted I/O.
*/

#include <iostream>
#include <string>
#include <sstream>

int main() {

    std::string name {"Denji 29"}; 

    // Input String Stream
    std::istringstream iss {name}; // We connected the object to a string object.

    std::string ChainsawMan;
    int age;
    iss >> ChainsawMan >> age; // Inputing through that stringstream object.
    std::cout << ChainsawMan << " " << age << '\n';

    // Output String Stream
    std::ostringstream oss {}; // We didn't connect it to anything.
    oss << ChainsawMan << " " << age << '\n'; // Outputting data to this object now.
    std::cout << oss.str(); // Method to directly access the string in object.

    // A string stream that can do both
    std::stringstream ss {name};
    ss << "Hello there"; // Overwritting value in stream.
    std::cout << name << '\n'; // But it doesn't change the value in original object.
    std::cout << ss.str() << '\n'; // Will show overwritten value.

    // Data Validation with String Streams
    std::cout << "====================================\n";
    int value;
    std::string input;
    std::cout << "Enter your favourite number: ";
    std::cin >> input;
    std::stringstream ss2 {input};
    

    // Validating if the input was a number.
    if(ss2 >> value) {
        std::cout << "Mine is also " << value << '\n';
    }
    else {
        std::cout << "That ain't a number bro!" << '\n';
    }

    return 0;
}