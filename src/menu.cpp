#include <iostream>
#include <string>
#include <fstream>

#include "../include/menu.h"

Frontend::Frontend(){}
void Frontend::welcome_menu()
    {
        std::cout<< "~~Welcome to Magnifique Pastries~~\n"
                    "====================================\n"
                    
                    "Please select from the following menu" << std::endl;
        
        std::cout << "1) Show our menu for today\n"
                     "2) Place an order\n"
                     "What can we do for you today?\n" << std::endl;
        int user_input;

        std::cin >> user_input;

        if (user_input == 1)
        {
            view_inventory();
        }
        // else if (user_input ==2)
        // {
        //     /* code */
        // }
        // else if (user_input ==0)
        // {
        //     /* as for manager username and pin */
                /*changing cash in register or updating inventory*/
        // }

        // else
        // {
        //     std::cout<<"Goodbye!" << std::endl;
        // }
        
        


    }

void view_inventory()
{ /*Display current inventory to user*/
    std::fstream inventory_file;
    
    std::cout << "Here is the current inventory:\n" << std::endl;
    
    inventory_file.open("/home/kishen/documents/c++_projects/pastry_shop/data/inventory.txt", std::ios::in);
    if (inventory_file.is_open())
    {
        std::string line;
        while(getline(inventory_file, line))
        {
            std::cout << line << "/n" << std::endl;
        }
        inventory_file.close();
    }
}