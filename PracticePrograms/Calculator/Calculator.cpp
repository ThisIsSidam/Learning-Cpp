// Author- Anshu Kumar Singh a.k.a Sidam
// Date- 16/04/2023
// Purpose- C++ Practice Program
// Name- Calculator

#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <exception>

class IllegalValueError : public std::exception {

public:     
    virtual const char* what () const noexcept {
        return "Illegal Value Entered!";
    }
};


std::stringstream ask();
double get_operand(std::stringstream&);
char get_operator(std::stringstream&);
double calculate(const double&, const double&, const char);

int main() {

    std::cout << "== Sidam's Calculator Activated =====" << std::endl;
    std::cout << "\nNote: Enter 'Quit' to exit the program." << std::endl;
    std::cout << "Enter Queries in this format: 5 + 8 or 5+8." << std::endl;
    std::cout << "Supported Operators: +, -, *, /\n" << std::endl;

    double first_operand;
    double second_operand;
    char sign;
    std::stringstream statement;
    double total;

    while (true) 
    {
        try {    
            statement = ask();

            if ( statement.str() == "QUIT" )
            {
                std::cout << "Goodbye!" << std::endl;
                break;
            }

            first_operand = get_operand(statement);
            sign = get_operator(statement);
            second_operand = get_operand(statement);

            total = calculate(first_operand, second_operand, sign);
            std::cout << first_operand << " " << sign << " " << "= " << total << std::endl;
        }
        catch (const IllegalValueError ex) 
        {
            std::cerr << ex.what() << std::endl;
        }
        catch (...) 
        {
            std::cerr << "Something Went Wrong!" << std::endl;
        }

    }

    std::cout << "\n=====================================\n";

    return 0;
}

std::stringstream ask() {

    std::string query;
    std::cout << "Enter: ";
    std::getline(std::cin, query);

    std::stringstream statement {query};
    return statement; 
}

double get_operand(std::stringstream &ss) {
    double operand;

    if ( ss >> operand ) 
    {
        return operand;
    }
    throw IllegalValueError();
} 

char get_operator(std::stringstream &ss) {
    char sign;

    if ( ss >> sign )   
    {
        return sign;
    }
    throw IllegalValueError();
}

double calculate(const double& op1, const double& op2, const char op) {

    if ( op == '+' )
    {
        return op1 + op2;
    }
    else if ( op == '-' )
    {
        return op1 - op2;
    }
    else if ( op == '*' )
    {
        return op1 * op2;
    }
    else if ( op == '/')
    {
        return op1 / op2;
    }
    else 
    {
        throw 0;
    }

}