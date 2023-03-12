// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 04/03/2023
//
// Day38 Of Learning C++
// --------------------------------------

/*
== Input Files == 

fstream and ifstream are commonly used for inputting files.

Method:-

i) include the fstream file..
ii) Declare an object of fstream or ifstream.
iii) Connect it to a file on your file system (opens it for reading).
iv) Read data from the file via the stream.
v) Close the stream (Very Important).

*/


#include <iostream>
#include <fstream>
#include <string>

int main() {
    
{
    /* 
    This is declaration along with initialisation.
    Arguments-> File path, Mode("in" means input mode).
    fstream has capabilities for both input and output mode, so we have to
    specify mode. For, only input mode, use ifstream object and then specifying 
    mode will be optional.
    */

    std::fstream in_file {"../Example.txt", std::ios::in};
    in_file.close(); // Closing the file.

    // Sometimes we need to access file in binary mode. For that:
    // std::fstream in_file ("../Example.txt", std::ios::in | std::ios::binary);
    // That in the middle is called Bitwise Operator
    // Again, specifying input mode will be optional in ifstream.

}



    // We're going to use this in multiple blocks.
    std::string file_name;
    std::cout << "Enter File path: ";
    std::cin >> file_name;

{
    // For times when we don't have the file path and have to ask from the user.

    std::ifstream in_file2;

    // Open function opens files and we can add other modes like binary with a comma.
    in_file2.open(file_name);

    // We also need to check if the file opened successfully or not.

    if (in_file2.is_open()) {
        // If true, means that the file opened and we can access it.
        std::string word;
        in_file2 >> word; // Getting an input from the file.
        std::cout << word << '\n';
    } else {
        std::cerr << "File isn't opened!" << '\n';
    } // Note that we took input just like cin, and similarily the input stops
    // at whitespace taking only one word.

    in_file2.close();
}





{
    // In case of getting full line, we should do this.
    std::ifstream in_file2 {file_name};

    if (in_file2){ // Only this is also enough to check opening
        std::string line;
        std::getline(in_file2, line); // We have used this function before with cin.
        std::cout << line << '\n';
    } else {
        std::cerr << "File didn't open" << '\n';
    }

    in_file2.close();
}





{   
    // To get the whole file, we can do this
    std::ifstream in_file2 {file_name};

    std::cout << "First method of Printing whole file=================" << '\n';
    std::string line2;
    if (in_file2) { 
        while(!in_file2.eof()){
            std::getline(in_file2, line2);
            std::cout << line2 << '\n';
        }
    } else {
        std::cerr << "Error Opening File!" << '\n';
        std::cerr << "Error Opening File!" << '\n';
    }

    in_file2.close();
}





{
    // Or we can use this method: Not a different method but shortening the 
    // first one. The getline actually returns a reference that will act like a
    // false when the file reaches its end.

    std::ifstream in_file2 {file_name}; 

    std::cout << "Second method of Printing whole file=================" << '\n';
    std::string line3;
    if (in_file2) {
        while (std::getline(in_file2, line3)) {
            std::cout << line3 << '\n';
        }
    } else {
        std::cerr << "File says it won't open!" << '\n';
    }

    in_file2.close();
}





{
    // Or this method: We use the get method that takes only one character from
    // the file. This way we can take the whole file bit by bit. 
    std::ifstream in_file2 {file_name};


    std::cout << "Third method of Printing whole file=================" << '\n';
    char c;
    while (in_file2.get(c)) {
        std::cout << c;
    }

    in_file2.close();
}

    return 0;
}