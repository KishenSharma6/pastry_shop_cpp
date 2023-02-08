#include <iostream>
#include <fstream>

#include <stdexcept>
#include <string>

#include "../include/inventory.h"



Inventory::Inventory(){}

void Inventory::view_inventory()
    { /*Display current inventory to user*/
        std::fstream inventory_file;
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

void Inventory::update_count()
    {
        //function allows you to modify the current inventory quantitry 
        ;
    }

void Inventory::add_item()
    {
        
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

            if (input == "Y")
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
        std::string target;

        std::cout << "Which item would you like removed from inventory?" << std::endl;
        std::cin >> target;

        std::ifstream inventory_file("/home/kishen/documents/c++_projects/pastry_shop/data/inventory.txt");
        std::ofstream temp("/home/kishen/documents/c++_projects/pastry_shop/data/temp.txt");

        std::string line;

        while (getline(inventory_file, line))
        {
            if (line.find(target) == std::string::npos)
            {
                std::cout<<line<<"\n";
            }
        }

        temp.close();
        inventory_file.close();
        
        // rename("/home/kishen/documents/c++_projects/pastry_shop/data/temp.txt", "/home/kishen/documents/c++_projects/pastry_shop/data/inventory.txt");
        // remove("/home/kishen/documents/c++_projects/pastry_shop/data/inventory.txt");
    }
void write_inventory(std::string item, int quantity, float price)
    {
        std::fstream inventory_file;
        inventory_file.open("/home/kishen/documents/c++_projects/pastry_shop/data/inventory.txt", std::fstream::app);

        if (inventory_file.is_open())
        {
            inventory_file << item << "," << quantity << "," <<price <<std::endl;
            inventory_file.close();
        }
    }

;

