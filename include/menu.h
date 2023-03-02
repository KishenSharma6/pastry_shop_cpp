#ifndef MENU_H
#define MENU_H

#include <iostream>

class Frontend
{

public:
    Frontend();
    void welcome_menu();
    void manager_login();
    void inventory_menu();
    void register_menu();
    void manager_menu();
    
};
bool verify_input_username(std::string input_username,  std::string path_to_data);
bool verify_input_pw(std::string input_username, std::string input_pw,  std::string path_to_data);
void view_inventory();

#endif