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
#include <iostream>
#include "BlueMen.hpp"

/* DEFAULT CONSTRUCTOR */
BlueMen::BlueMen() : Creature()
{
    this->strength = 12;
    this->armor = 3;
    this->name = "Blue Men";
    this->type = 4;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: attack
 * Description: Rolls die according to their character properties.
 * Parameters: none
 * Pre-Conditions: object created in game class
 * Post-Conditions: return attack value integer
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int BlueMen::attack()
{
    int attack_val = 0;
    
    /* BlueMen roll two 10-sided die for attack */
    for(int i = 0; i < 2; i++)
    {
        int val = (rand() % 10) + 1;
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

int BlueMen::defense()
{
    int defense_val = 0;
    
    /* this value determines the number of dice to roll */
    int mobFactor;
    
    /* after first mob is lost, roll two die */
    if(this->strength <=8 && this->strength >4)
    {
        mobFactor = 2;
    }
    /* after secodn mob is lost, roll one die */
    else if(this->strength <=4)
    {
        mobFactor = 1;
    }
    /* initially start with three dice */
    else
    {
        mobFactor = 3;
    }
    
    for(int i = 0; i < mobFactor; i++)
    {
        int val = (rand() % 6) + 1;
        defense_val += val;
    }
    return defense_val;
}

/* SET functions */
void BlueMen::set_strength(int val)
{
    this->strength = val;
}

/* GET functions */
int BlueMen::get_strength()
{
    return strength;
}

int BlueMen::get_armor()
{
    return armor;
}

std::string BlueMen::get_name()
{
    return name;
}

int BlueMen::get_type()
{
    return type;
}
