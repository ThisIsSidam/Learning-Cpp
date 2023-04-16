// Author- Anshu Kumar Singh a.k.a Sidam
// Date- 13/04/2023
// Purpose- C++ Practice Program
// Name- Currency Converter

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <exception>

class IllegalValues : public std::exception {

public: 
    virtual const char* what () const noexcept {
        return "Illegal Values Entered\n";
    }
};

// I don't know how to get real time exchange rates. And I want to just do 
// things mostly with what I learned on the Udemy Course. 
std::map<std::string, double> currencies {
    {"INR", 1}, {"USD", 81.93}, {"EUR", 89.42}, {"GBP", 101.76}, {"KWD", 266.75},
    {"AED", 22.31}, {"JPY",0.62} 
};


void guidebook();
double currency_changer(const double&, const std::string &, const std::string &);

int main() {

    const std::string guide {"GUIDE"};
    const std::string quit {"QUIT"};

    std::cout << "\n== Sidam's Currency Converter Activated ========" << std::endl;
    
    bool guide_seen {false};

    while (true) {

        if (!guide_seen)
        {
            guidebook();
            guide_seen = true;
        }

        std::string primary_currency;
        std::string secondary_currency;
        double amount;

        std::string str;

        std::cout << "Enter: ";
        std::getline(std::cin, str);

        std::stringstream ss {str};

        try 
        { 
            if (! (ss >> amount) )
            {
                if ( ss.str() == guide )
                {
                    guidebook();
                    continue;
                }
                else if ( ss.str() == quit )
                {
                    std::cout << "Goodbye!" << std::endl;
                    break;
                }
                else 
                {
                    throw IllegalValues();
                }
            }
            else 
            {
                if (! (ss >> primary_currency) )
                {
                    throw IllegalValues();
                }
                else 
                {
                    if (! (ss >> secondary_currency) )
                    {
                        throw IllegalValues();
                    }
                }
            }

            double secondary_amount = currency_changer(amount, primary_currency, secondary_currency);
            std::cout << amount << " " << primary_currency << " = "
                    << secondary_amount << " " << secondary_currency << std::endl;
        }
        catch (const IllegalValues &ex)
        {
            std::cerr << ex.what();
        } 

    } //While Loop ends here.

    return 0;
}

void guidebook() {
    std::cout << "\n== Guide =====";

    std::cout << "\nEnter Amount, Currency of Amount and the Currency you wish to change to."
              << "\nAll Separated with spaces."
              << "\nUse all capital Currency Codes only."
              << "\nSupported Currencies: INR, USD, EUR, GBP, KWD, AED, JPY." 
              << "\n\nEnter 'GUIDE' to see the guide again."
              << "\nEnter 'QUIT' to end the program."
              << "\nRemember that these commands are all capital.";

    std::cout << "\n==============\n" << std::endl;

}

double currency_changer(const double &amount, const std::string &primary, const std::string &secondary) {
    
    double new_amount;
    auto it = currencies.begin();

    bool part_one_complete {0};
    while ( it != currencies.end() )
    {
        if ( (it->first == primary) and (!part_one_complete) ) 
        {
            new_amount = amount * (it->second);
            part_one_complete = true;
            it = currencies.begin();
        }

        if ( (it->first == secondary) and (part_one_complete) )
        {
            return new_amount/(it->second);
        }
        it++;
    }

    throw IllegalValues();
}