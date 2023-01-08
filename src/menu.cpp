#include <iostream>
#include <string>

#include "../include/menu.h"

Frontend::Frontend(){}
void Frontend::welcome_menu()
    {
        std::cout<< "~~Welcome to Magnifique Pastries~~\n"
                    "====================================\n"
                    
                    "Please select from the following menu" << std::endl;
        
        std::cout << "1) Show our menu for today\n"
                     "What can we do for you today?\n" << std::endl;
        int user_input;

        std::cin >> user_input;

        if (user_input == 1)
        {
            food_menu();
        }


    }

void Frontend::food_menu()
{
  std::cout << "Here is what we have available today\n" << std::endl;
  /* Some code that creates a menu from inventory class*/  
}