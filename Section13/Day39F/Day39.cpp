// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 10/03/2023
//
// Day39 Of Learning C++
// --------------------------------------

/*
== Output Files ==
We learnt about input files with which we took inputs. Now, it's time
for output files to which we'll give output now. 

fstream and ofstream are commonly used for output files.

Method:
1. #include <fstream>
2. Declare fstream or ofstream object.
3. Initialise while declaring or connect it to a file later via .open\
method.
4. Write data into file via stream.
5. Close.

===============Some things to note are that:
- If file that is to be opened, doesn't exist. It will be created. And
if a path is given, it must exist, or an error will be shown.

- By default, the opened file will be overwritten, but we can choose to 
append with a specific flag.

===============Lots of things are same as input files. Like: 
- Opening with .open() method.

- Checking if the file opened or not, with is_open() method, or just by
checking the data in the file by it's name in the if statement.

- Using the std::ios::out flag is only necessary when the object is of
fstream class. And it is optional for ofstream class.

- Opening file in binary mode is also same with the std::ios::binary flag
used with the bitwise operator.

- Closing file is also the same. Note that it is even more important to 
close the file now, since there is stuff in the buffer that should be 
cleared and that's what the close method does. It clears the buffer.

===============Now let's just see some syntax:

Normally opening file- std::ofstream out_file {"file_name"};

When file is normally opened, it is by default on std::ios::trunc mode, 
which means Truncation/Overwrite mode. .... {"file_name", std::ios::trunc};

We can set to append mode by using this: .... {"file_name", std::ios::app};

And there's another mode std::ios::ate. This mode leaves us at the end, but
after that we can write at the start or in the middle of text, anywhere, while
with append we can ony write at the end. Also that ios::ate truncates the file
and erased everything. So, it is a bit confusing for me because what's the 
meaning of going to the end when you erase the beginning itself. 

Now, outputting to file is same, just use insertion operator (<<) instead of
extraction operator (>>): out_file << "Hello there";


======= Copying File=====
Next we can learn to make a copy of a literal file by taking input from one 
and given output to another.
*/

#include <iostream>
#include <string>
#include <fstream>

int main() { 

    // First declare the objects:

    std::ifstream in_file {"hello.txt"};
    std::ofstream out_file {"hello_copy.txt"};
    
    // Now check if they opened successsfully.

    if (!in_file) {
        std::cout << "Error opening file" << '\n';
        return 1; // Returning anything other than 0 in main means Something 
        // went wrong and file closes.
    }
    if(!out_file) {
        std::cout << "Error writing to file" << '\n';
        return 1;
    }

    // Method one for copying- Line by line.
    // Check both one by one.

    std::string line;
    while (std::getline(in_file, line))
    {
        out_file << line << '\n';
    }

    // Method two- word by word

    // char c;
    // while (in_file.get(c))
    // {
        // out_file.put(c);
    // }


    return 0;
}