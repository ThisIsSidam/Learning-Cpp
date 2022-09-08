// --------------------------------------
// Author- Anshu Kumar Singh a.k.a. Sidam
// Purpose- Notes of Learning C++
// Date - 04/09/2022
//
// Problem12 of Learning C++
// After Day33
// Name- What of What?
// --------------------------------------


/*
Here you are gonna create a unique pointer that points to a vector of shared pointers
that point to Test Class objects. Test clas will have name and marks. You are gonna 
have to create three functions, make that creates that big unique pointer with deep roots,
then you are gonna asks the user through main for how many students' test results that 
vector will carry and then run the fill function, where you are gonna give it the big
thing along with the number you just asked for, the fill function will ask for the name
and marks of students that you'll make Test object of and push on the vector and then 
last but the beast, the display function that'll show the name and marks of all the
students. Now go.
*/

#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Test {
    std::string name;
    int marks;
public:
    Test(std::string n= "Unknown Student", int num = 0) 
        : name{n}, marks{num} {
            std::cout << "Test's Constructor is Saying \"Konichiwa!\"" << '\n';
        };
    ~Test() { std::cout << "Test's Destructor is saying \"Jaane!\"" << '\n';}
    void display() { std::cout << name << ": " << marks << '\n'; }

};

// Function Prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int);
void display(std::vector<std::shared_ptr<Test>> &vec);

int main()
{   std::unique_ptr<std::vector<std::shared_ptr<Test>>> english_marksheet;
    english_marksheet = make();

    int student_num;
    std::cout << "How many students' marks would you like to fill in: ";
    std::cin >> student_num;

    fill(*english_marksheet, student_num);
    display(*english_marksheet);
    


    return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
    std::string name;
    int marks;
    for(int i {0}; i < num; i++) {
        std::cout << "Enter the name of the student: ";
        std::getline(std::cin >> std::ws, name); 
        // Getline is for taking full names as inputs as normally cin would stop at a whitespace.
        // ws is for telling the cin to stop at the leading whitespaces in end of input.
        std::cout << "Enter " << name << "'s marks: ";
        std::cin >> marks;
        vec.push_back(std::make_shared<Test>(name, marks));
        std::cout << name << "'s marks are added on Marksheet!" << '\n';
    }
}

void display(std::vector<std::shared_ptr<Test>> &vec) {
    std::cout << "===== Marksheet ====================" << '\n';
    for(auto sheet: vec) {
        sheet->display();
    }
    std::cout << "====================================" << '\n';
}