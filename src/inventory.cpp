#include <algorithm>
#include <iostream>
#include <fstream>

#include <stdexcept>
#include <string>

#include "../include/inventory.h"
#include "../include/menu.h"



Inventory::Inventory(){}


void Inventory::update_count()
    {
        //function allows you to modify the current inventory quantitry 

        
        bool continue_operation = true;

        do
        {
            std::string target_item = "";
            std::string updated_name = "";
            std::string updated_quant = "";
            std::string updated_price = "";

            view_inventory();

            std::cout << "\nWhich inventory item would you like to update?" << std::endl;
            std::cin >> std::ws;
            getline(std::cin,target_item);

            std::cout << "What is the correct name of " << target_item << "(s) in stock?" << std::endl;
            std::cin >> std::ws;
            getline(std::cin, updated_name);

            std::cout << "What is the correct number of " << updated_name << "(s) in stock?" << std::endl;
            std::cin >> updated_quant;

            std::cout << "What is the correct price of each " << updated_name << "(s) in stock?" << std::endl;
            std::cin >> updated_price;

            std::ifstream curr_inventory;
            std::ofstream new_inventory;

            curr_inventory.open("/home/kishen/documents/c++_projects/pastry_shop/data/inventory.txt");
            new_inventory.open("/home/kishen/documents/c++_projects/pastry_shop/data/temp.txt");


            std::string line;
            while (getline(curr_inventory, line))
            {
                if (line.rfind(target_item, 0) == 0)
                {
                    new_inventory << updated_name << "," << updated_quant << "," << updated_price << std::endl;
                }
                else
                {
                    new_inventory << line << std::endl;
                }
            }

            new_inventory.close();
            curr_inventory.close();

            remove("/home/kishen/documents/c++_projects/pastry_shop/data/inventory.txt");
            rename("/home/kishen/documents/c++_projects/pastry_shop/data/temp.txt", "/home/kishen/documents/c++_projects/pastry_shop/data/inventory.txt");
        

            

            std::string user_input;

            std::cout << "Would you like to update an additional item in inventory(Y/N)?" << std::endl;
            std::cin >> user_input;

            transform(user_input.begin(), user_input.end(), user_input.begin(), ::toupper);

            if ((user_input) == "Y")
            {
                ;
            }
            else if (user_input == "N")
            {
                continue_operation = false;
            }
            else
            {
                throw std::invalid_argument("Must enter Y or N, please try again");
            }
        }
        while (continue_operation);    
        
        


    }

void Inventory::add_item()
    {
        // add new item line to inventory.txt. Collects name, quant, price and saves to inventory.txt
        bool additional_item = true;

        while (additional_item)
        {
            std::string item;
            int quantity;
            float price;
            std::string input;

            std::cout << "What item would you like to add to the inventory?" <<std::endl;
            std::cin >> std::ws;
            getline(std::cin,item);
            std::cout << "How many " << item << "(s) would you like to add to the inventory?" <<std::endl;
            std::cin >> quantity;
            std::cout << "What price would you like to sell the " << item <<"(s)?" <<std::endl;
            std::cin >> price;
            
            write_inventory(item, quantity, price);

            std::cout << "Would you like to add another item to the inventory (Y/N)?" << std::endl;
            std::cin >> input;

            transform(input.begin(), input.end(), input.begin(), ::toupper);

            if ((input) == "Y")
            {
                ;
            }
            else if (input == "N")
            {
                additional_item = false;
            }
            else
            {
                throw std::invalid_argument("Must enter Y or N, please try again");
            }

        }
    }

void Inventory::remove_item()
    {
        // remove item line in inventory.txt. NOTE matches on beginning of item name string
        view_inventory();

        std::string target;

        std::cout << "\nWhich item would you like removed from inventory?" << std::endl;
        std::cin >> target;

        std::ifstream curr_inventory;
        std::ofstream new_inventory;

        curr_inventory.open("/home/kishen/documents/c++_projects/pastry_shop/data/inventory.txt");
        new_inventory.open("/home/kishen/documents/c++_projects/pastry_shop/data/temp.txt");
        

        std::string line;

        while (getline(curr_inventory, line))
        {
            if (line.rfind(target, 0) == 0)
            {
                continue;
            }
            new_inventory << line << std::endl;
        }

        new_inventory.close();
        curr_inventory.close();
        remove("/home/kishen/documents/c++_projects/pastry_shop/data/inventory.txt");
        rename("/home/kishen/documents/c++_projects/pastry_shop/data/temp.txt", "/home/kishen/documents/c++_projects/pastry_shop/data/inventory.txt");
        

    }

void write_inventory(std::string item, int quantity, float price)
    {   /**/
        std::fstream inventory_file;
        inventory_file.open("/home/kishen/documents/c++_projects/pastry_shop/data/inventory.txt", std::fstream::app);

        if (inventory_file.is_open())
        {
            inventory_file << item << "," << quantity << "," <<price <<std::endl;
            inventory_file.close();
        }
    }

;

