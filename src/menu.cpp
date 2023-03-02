#include <iostream>
#include <assert.h>

#include <string>
#include <fstream>

#include "../include/menu.h"
#include "../include/inventory.h"

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
        view_inventory(); //Probably should make a fancy menu for the user
    }
    // else if (user_input ==2)
    // {
    //     /* code */
    // }
    else if (user_input ==0)
    {
        manager_login();
    }
    else
    {
        std::cout<<"Goodbye!" << std::endl;
    }
    
}
void Frontend::manager_login()
{
    std::string input_id;
    std::string input_pw;

    std::cout << "Welcome to Magnifique Pastries' inventory management system.\n"
                 "Let's first verify your credentials. Please enter your 5-digit user ID:" << std::endl;
    std::cin >> input_id;
    assert(input_id.length() == 5);

    if (verify_input_username(input_id, "data/passwords.txt") == false)
    {
        welcome_menu();
    }
    
    int i = 0;
    bool pw_validated = false;
    while (i < 3 & pw_validated == false)
    {
        std::cout << "Please input your 10-character password" << std::endl;
        std::cin >> input_pw;
        assert(input_pw.length() == 10);
    
        pw_validated = verify_input_pw(input_id, input_pw, "data/passwords.txt");
        i ++;
    }

    if (pw_validated == false)
    {
        std::cout << "Sorry, you have too many failed sign-in attempts."
                     "Returning to main menu\n" << std::endl;
        welcome_menu();
    }
    else
    {
        manager_menu();
    }
}

void Frontend::manager_menu()
{
    /*Allow verified manger to select whether to make changes to inventory or register*/
    int user_input;
    
    std::cout << "Which of the following would you like to do?\n"
                 "1) Make updates to the inventory\n" 
                 "2) Make updated to the register\n" <<std::endl;

    std::cin >> user_input;

    if (user_input ==1)
    {
        inventory_menu();
    } else if (user_input == 2)
    {
        register_menu();
    } else
    {
        throw std::invalid_argument("Incorrect input");
    }
}
void Frontend::inventory_menu()
{
    /*Take manager input to modify data/inventory.txt*/
    Inventory curr_inventory;
    int user_input;

    std::cout << "Welcome to the inventory menu. Please select on of the following:\n"
                 "1) Add new item to inventory\n"
                 "2) Remove current item in inventory\n"
                 "3) Make updates to a current item in inventory\n"
                 "4) Return to main menu"<< std::endl;
    std::cin >> user_input;

    if (user_input == 1)
    {
        curr_inventory.add_item();
    } else if (user_input == 2)
    {
        curr_inventory.remove_item();
    } else if (user_input == 3)
    {
        curr_inventory.update_count();
    } else if (user_input == 4)
    {
        welcome_menu();
    } else
    {
        throw std::invalid_argument("Received incorrect input");
    }
    
    
    
}
void Frontend::register_menu()
{
    std::cout << "return to later" ;
}
bool verify_input_username(std::string input_username, std::string path_to_data)
{
    /*Checks if password/username exists in data/passwords.txt*/
    std::string line;
    int offset;
    std::ifstream data(path_to_data);

    if (data.is_open())
    {
        while (!data.eof())
        {
            getline(data, line, ',');
            if ((offset = line.find(input_username,0)) != std::string::npos)
            {
                data.close();
                return true;
            }
        }
        data.close();
    }
    std::cout << "Username not found, please try again.\n"
                 "RETURNING TO MAIN MENU \n" << std::endl;
    return false;

}
bool verify_input_pw(std::string input_username, std::string input_pw,  std::string path_to_data)
{
    /*Checks if password/username exists in data/passwords.txt*/
    std::string line;
    int offset;
    std::ifstream data(path_to_data);
    if (data.is_open())
    {
        while (!data.eof())
        {
            getline(data, line);
            if ((offset = line.find(input_username + "," + input_pw,0)) != std::string::npos)
            {
                data.close();
                return true;
            }
        data.close();
        }
    }
    std::cout << "Incorrect Password, please try again.\n" << std::endl;
    return false;
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