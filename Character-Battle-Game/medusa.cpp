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

#include <cstdlib>
#include "Medusa.hpp"

/* DEFAULT CONSTRUCTOR */
Medusa::Medusa() : Creature()
{
    this->strength = 8;
    this->armor = 3;
    this->name = "Medusa";
    this->type = 2;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: attack
 * Description: Rolls die according to their character properties.
 * Parameters: none
 * Pre-Conditions: object created in game class
 * Post-Conditions: return attack value integer
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Medusa::attack()
{
    int attack_val = 0;
    
    /* Medusa rolls two 6-sided die for attack */
    for(int i = 0; i < 2; i++)
    {
        int val = (rand() % 6) + 1;
        attack_val += val;
    }
 
        return attack_val;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: defense
 * Description: Rolls die according to their character properties.
 * Parameters: none
 * Pre-Conditions: object created in game class
 * Post-Conditions: return attack value integer
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Medusa::defense()
{   
    int defense_val = 0;
    
    /* Medusa rolls one 6-sided dice for defense */
    for(int i = 0; i < 1; i++)
    {
        int val = (rand() % 6) + 1;
        defense_val += val;
    }
    return defense_val;
}

/* SET functions */
void Medusa::set_strength(int val)
{
    this->strength = val;
}

/* GET functions */
int Medusa::get_strength()
{
    return strength;
}

int Medusa::get_armor()
{
    return armor;
}

std::string Medusa::get_name()
{
    return name;
}

int Medusa::get_type()
{
    return type;
}
