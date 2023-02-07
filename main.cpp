#include <iostream>
#include <list>
#include <string>


#include "include/menu.h"
#include "include/inventory.h"

int main(){
    //Frontend test;
    //test.welcome_menu();
    std::list<std::string> food;
    std::list<std::string> drink;
    
    food.push_back("apples");
    food.push_back("pies");

    Inventory test(food, drink);
    test.write_inventory();
    return 0;
}