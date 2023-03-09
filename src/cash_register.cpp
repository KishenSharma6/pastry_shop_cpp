#include <iostream>
#include <string>
#include <fstream>

#include "../include/cash_register.h"

Cash_Register::Cash_Register(std::string path_to_data)
{
    int twenties;
    int tens;
    int fives;
    int ones;

    std::ifstream register_file(path_to_data);
    std::string line;
    register_file.open()
    
    while (getline(path_to_data, line, ","))
    {
        std::cout << line << std::endl;
    }
};


