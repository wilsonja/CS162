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
#include "Vampire.hpp"

/* DEFAULT CONSTRUCTOR */
Vampire::Vampire() : Creature()
{
    this->strength = 18;
    this->armor = 1;
    this->name = "Vampire";
    this->type = 3;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: attack
 * Description: Rolls die according to their character properties.
 * Parameters: none
 * Pre-Conditions: object created in game class
 * Post-Conditions: return attack value integer
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Vampire::attack()
{
    int attack_val = 0;
    
    /* Vampire rolls one 12-sided die for attack */
    for(int i = 0; i < 1; i++)
    {
        int val = (rand() % 12) + 1;
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

int Vampire::defense()
{
    int defense_val = 0;
    
    /* Vampire rolls one 6-sided die for defense */
    for(int i = 0; i < 1; i++)
    {
        int val = (rand() % 6) + 1;
        defense_val += val;
    }
    return defense_val;
}

/* SET functions */
void Vampire::set_strength(int val)
{
    this->strength = val;
}

/* GET functions */
int Vampire::get_strength()
{
    return strength;
}

int Vampire::get_armor()
{
    return armor;
}

std::string Vampire::get_name()
{
    return name;
}

int Vampire::get_type()
{
    return type;
}
