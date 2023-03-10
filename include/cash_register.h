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
    bool verify_register(Cash_Register);
    void write_register(Cash_Register, std::string path_to_data);
    void read_register(Cash_Register, std::string path_to_data);
    void update_register();
    

};



#endif