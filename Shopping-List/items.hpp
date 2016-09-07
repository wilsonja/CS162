#ifndef ITEMS_HPP
#define ITEMS_HPP
#include <string>
#include "menuFunctions.hpp"

class Items
{
private:
    std::string name;
    std::string unit;
    int quant;
    double unit_price;

public:
    /* CONSTRUCTORS */
    Items();
    Items(std::string, std::string, int, double);
    
    /* SET methods */
    void set_name(std::string);
    void set_unit(std::string);
    void set_quant(int);
    void set_unit_price(double);
    
    /* GET methods */
    std::string get_name();
    std::string get_unit();
    int get_quant();
    double get_unit_price();
    
    /* MEMBER functions */
    double item_subtotal();
    friend bool operator==(Items, Items);
};

#endif
