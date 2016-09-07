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
#include "Barbarian.hpp"

/* DEFAULT CONSTRUCTOR */
Barbarian::Barbarian() : Creature()
{
    this->strength = 12;
    this->armor = 0;
    this->name = "Barbarian";
    this->type = 1;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: attack
 * Description: Rolls die according to their character properties.
 * Parameters: none
 * Pre-Conditions: object created in game class
 * Post-Conditions: return attack value integer
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Barbarian::attack()
{
    int attack_val = 0;
    
    /* Barbarian rolls two 6-sided die for attack */
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

int Barbarian::defense()
{
    int defense_val = 0;
    
    /* Barbarian rolls two 6-sided die for defense */
    for(int i = 0; i < 2; i++)
    {
        int val = (rand() % 6) + 1;
        defense_val += val;
    }
    return defense_val;
}

/* SET functions */
void Barbarian::set_strength(int val)
{
    this->strength = val;
}

/* GET functions */
int Barbarian::get_strength()
{
    return strength;
}

int Barbarian::get_armor()
{
    return armor;
}

std::string Barbarian::get_name()
{
    return name;
}

int Barbarian::get_type()
{
    return type;
}
