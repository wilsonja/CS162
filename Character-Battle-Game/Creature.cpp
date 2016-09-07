/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * Program Filename: Assignment3
 * * Author: Jacob Wilson
 * * Date: 2/14/16
 * * Description: This program simulates a dice battle between two
 * *  characters. Each character has different attack, defense, armor,
 * *  and strength attributes. Some characters also have special
 * *  traits that are called at specific points.
 * * Input: choice of two characters
 * * Output: attack and defense values for each round
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Creature.hpp"

/* DEFAULT CONSTRUCTOR */
Creature::Creature()
{
    this->strength = 0;
    this->armor = 0;
    this->name = " ";
    this->type = 0;
}

/* DESTRUCTOR */
Creature::~Creature()
{
    /* intentionally empty */
}

/*SET functions */
void Creature::set_strength(int val)
{
    this->strength = val;
}

/* GET functions */
int Creature::get_strength()
{
    return strength;
}

int Creature::get_armor()
{
    return armor;
}

std::string Creature::get_name()
{
    return name;
}

int Creature::get_type()
{
    return type;
}
