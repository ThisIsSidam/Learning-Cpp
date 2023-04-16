// Author- Anshu Kumar Singh a.k.a Sidam
// Date- 15/04/2023
// Purpose- C++ Practice Program
// Name- Card Validator

#include <iostream>
#include <string>
#include <cmath>


bool check(std::string &num);
void display(std::string &num);
int getdigit(int num);

int main() {

    std::cout << "== Sidam's Card Validator Activated! =====\n" << std::endl;
    std::cout << "Note: Type 'QUIT' to end the program." << std::endl;

    while (true) 
    {
        std::string number;

        std::cout << "\nEnter Card Number: ";
        std::cin >> number;

        if ( number == "QUIT" )
        {
            std::cout << "GoodBye!\n";
            break;
        }
        else if (! check(number) )
        {
            std::cerr << "Your Card is Invalid :(" << std::endl;
        }
        else 
        {
            display(number);
        }
        
    }

    std::cout << "\n==========================================\n" << std::endl;

    return 0;
}

bool check(std::string &num) {

    // Using LUHN Algorithm

    if ( (num.size() < 13) or (num.size() > 19) )
    {
        return 0; 
    }
    
    int total {0};
    int digit;

    // Taking digits from right to left.
    for(int i {int(num.size() -1)}; i >= 0; i--)
    {
        // (-48) is used to turn it from ASCII to it's numerical value. 0 is 48 in ASCII.

        // First Digit
        digit = getdigit(num.at(i) - 48);
        total += digit;
        
        i--;
        if ( i >= 0 )
        {
            // Second Digit
            digit = getdigit( 2 * (num.at(i) - 48));
            total += digit;
        }
    }

    return ( total % 10 == 0 );
}

int getdigit(int num) {

    if ( num < 10 )
    {
        return num;
    }
    return static_cast<int>(std::floor(num/10)) + ( num % 10 );
}

void display(std::string &num) {

    std::cout << "Your Card is Valid :)" << std::endl;
    std::cout << "Provider: ";

    int first_digit {num.at(0) - 48};

    if ( first_digit == 3 )
    {
        std::cout << "American Express" << std::endl;
    }
    else if ( first_digit == 4 ) 
    {
        std::cout << "Visa" << std::endl;
    }
    else if ( ( first_digit == 5) or ( first_digit == 2 ) )
    {
        std::cout << "Mastercard" << std::endl;
    }
    else if ( first_digit == 6 )
    {
        std::cout << "Discover" << std::endl;
    }
    else{
        std::cout << "Unknown" << std::endl;
    }
}