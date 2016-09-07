#include "items.hpp"

/* DEFAULT CONSTRUCTOR sets all variables to empty strings or 0 */
Items::Items()
{
    set_name(" ");
    set_unit(" ");
    set_quant(0);
    set_unit_price(0.0);
}

/* CUSTOM CONSTRUCTOR sets according to user input */
Items::Items(std::string name, std::string unit, int quant, double unit_price)
{
    set_name(name);
    set_unit(unit);
    set_quant(quant);
    set_unit_price(unit_price);
}

/* SET methods */
void Items::set_name(std::string name)
{
    this->name = name;
}

void Items::set_unit(std::string unit)
{
    this->unit = unit;
}

void Items::set_quant(int quant)
{
    this->quant = quant;
}

void Items::set_unit_price(double unit_price)
{
    this->unit_price = unit_price;
}

/* GET methods */
std::string Items::get_name()
{
    return name;
}

std::string Items::get_unit()
{
    return unit;
}

int Items::get_quant()
{
    return quant;
}

double Items::get_unit_price()
{
    return unit_price;
}

/* MEMBER functions */

/* SUBTOTAL function */
double Items::item_subtotal()
{
    double item_total = quant * unit_price;
    
    return item_total;
}

/* overloaded == operator */
bool operator==(Items a, Items b)
{
    return a.get_name() == b.get_name();
}
