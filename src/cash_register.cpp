#include <iostream>
#include <string>
#include <fstream>

#include "../include/cash_register.h"

Cash_Register::Cash_Register()
{
    int twenties;
    int tens;
    int fives;
    int ones;

    

    std::cout << "We will now be adding dollar bills to this cash register\n"
                 "How many twenty dollar bills are you putting into the register?" <<std::endl;
    std::cin >> twenties;

    std::cout << "\nHow many ten dollar bills are you putting into the register?" <<std::endl;
    std::cin >> tens;

    std::cout << "\nHow many five dollar bills are you putting into the register?" <<std::endl;
    std::cin >> fives;

    std::cout << "\nHow many one dollar bills are you putting into the register?" <<std::endl;
    std::cin >> ones;
                
};

bool Cash_Register::verify_register(const Cash_Register& cash_reg)
{
    char user_input;

    std::cout << "Please confirm that the contents of the register are correct: \n" 
                 "Number of TWENTIES: " + std::to_string(cash_reg.twenties) + "\n" 
                 "Number of TENS: " + std::to_string(cash_reg.tens) + "\n" 
                 "Number of FIVES: " + std::to_string(cash_reg.fives) + "\n" 
                 "Number of ONES: " + std::to_string(cash_reg.ones) + "\n" << std::endl;
    std::cout << "Is this correct?(Y/N)" << std::endl;
    std::cin >> user_input;

    if (std::toupper(user_input) == 'Y')
    {
        return true;
    } else if (std::toupper(user_input) == 'N')
    {
        return false;
    } else
    {
        throw std::invalid_argument( "received incorrect value" );
    }
    
};

int Cash_Register::write_register(const Cash_Register& cash_reg, std::string path_to_data)
{
    std::ofstream register_data(path_to_data);
    register_data << cash_reg.twenties << "," << cash_reg.tens << "," << cash_reg.fives << ","<<
                     cash_reg.ones << std::endl;

    register_data.close();
    return 0;

};


int Cash_Register::read_register(Cash_Register, std::string path_to_data)
{
    std::ifstream register_data(path_to_data);


    return 0;
};

void Cash_Register::update_register()
{
    //write changes to data after giving customer change
    
}


