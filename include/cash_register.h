#ifndef CASH_REGISTER_H
#define CASH_REGISTER_H

#include <iostream>

class Cash_Register
{
private: 
    int twenties;
    int tens;
    int fives;
    int ones;
    
public:
    Cash_Register();
    bool verify_register(const Cash_Register& cash_reg);
    int write_register(const Cash_Register& cash_reg, std::string path_to_data);
    int read_register(Cash_Register, std::string path_to_data);
    void update_register();
    

};



#endif