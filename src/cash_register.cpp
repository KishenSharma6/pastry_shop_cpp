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

bool Cash_Register::verify_register(Cash_Register)
{

};

void Cash_Register::write_register(Cash_Register, std::string path_to_data)
{

};


void Cash_Register::read_register(Cash_Register, std::string path_to_data)
{

};

void Cash_Register::update_register()
{
    //write changes to data after giving customer change
    
}


