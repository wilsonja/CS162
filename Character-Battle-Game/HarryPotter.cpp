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
#include "HarryPotter.hpp"

/* DEFAULT CONSTRUCTOR */
HarryPotter::HarryPotter() : Creature()
{
    this->strength = 10;
    this->armor = 0;
    this->name = "Harry Potter";
    this->type = 5;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: attack
 * Description: Rolls die according to their character properties.
 * Parameters: none
 * Pre-Conditions: object created in game class
 * Post-Conditions: return attack value integer
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int HarryPotter::attack()
{
    int attack_val = 0;
    /* Harry Potter rolls two 6-sided die for attack */
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

int HarryPotter::defense()
{
    int defense_val = 0;
    /* Harry Potter rolls two 6-sided die for defense */
    for(int i = 0; i < 2; i++)
    {
        int val = (rand() % 6) + 1;
        defense_val += val;
    }
    return defense_val;
}

/* SET functions */
void HarryPotter::set_strength(int val)
{
    this->strength = val;
}
 
/* GET functions */
int HarryPotter::get_strength()
{
    return strength;
}
 
int HarryPotter::get_armor()
{
    return armor;
}
 
std::string HarryPotter::get_name()
{
    return name;
}

int HarryPotter::get_type()
{
    return type;
}
