#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>
#include <string>

class Inventory
{
public:

    Inventory();
    void update_count();
    void add_item();
    void remove_item();
};
void write_inventory(std::string item, int quantity, float price);


#endif