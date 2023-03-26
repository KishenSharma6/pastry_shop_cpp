#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "../include/cash_register.h"

Cash_Register::Cash_Register()
{
    int twenties = 0;
    int tens = 0;
    int fives = 0;
    int ones = 0;

    

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
    /*Takes register object and writes attributes to path_to_data*/
    
    std::ofstream register_data(path_to_data);
    register_data << cash_reg.twenties << "," << cash_reg.tens << "," << cash_reg.fives << ","<<
                     cash_reg.ones << std::endl;

    register_data.close();
    return 0;

};

int Cash_Register::read_register(std::string path_to_data)
{
    /*Read and display register data to user*/
    std::ifstream register_data(path_to_data);
    std::vector <std::string> bill_counts;
    std:: vector <std::string> bills = {"twenties", "tens", "fives", "ones"};

    
    std::string line;

    while (std::getline(register_data, line, ','))
    {
        bill_counts.push_back(line);
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << bills[i] << ".........." << bill_counts[i];
    }


    return 0;
};

void Cash_Register::update_register()
{
    //write changes to data after giving customer change
    std::cout << "Still work to do" << std::endl;
    
}


