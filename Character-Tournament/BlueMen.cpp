/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * Program Filename: assignment4
 * * Author: Jacob Wilson
 * * Date: 2/28/14
 * * Description: This program is a modification of Assignment 3. A
 * *  user is now able to enter a team size which can then be
 * *  populated with multiple team members. Each team member is also
 * *  now able to be given a unique name. Players rotate throught their
 * *  lineup as they battle. A stack is created which holds the
 * *  players as they lose.
 * * Input: int from user serves as team size
 * * Output: display lineups, battles, and results
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
    this->user_name = " ";
    this->team_name = " ";
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

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: regen
 * Description: Adds 5 strength points to the creatures current
 *  strength.
 * Parameters: none
 * Pre-Conditions: creature wins in battle
 * Post-Conditions: winning creature has 5 strength points added
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void BlueMen::regen()
{
    this->strength = this->get_strength() + 5;
}

/* SET functions */
void BlueMen::set_strength(int val)
{
    this->strength = val;
}

void BlueMen::set_user_name(std::string name)
{
    this->user_name = name;
}

void BlueMen::set_team_name(std::string name)
{
    this->team_name = name;
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

std::string BlueMen::get_user_name()
{
    return user_name;
}

std::string BlueMen::get_team_name()
{
    return team_name;
}

int BlueMen::get_type()
{
    return type;
}
