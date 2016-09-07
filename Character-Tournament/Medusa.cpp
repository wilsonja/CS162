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
#include "Medusa.hpp"

/* DEFAULT CONSTRUCTOR */
Medusa::Medusa() : Creature()
{
    this->strength = 8;
    this->armor = 3;
    this->name = "Medusa";
    this->type = 2;
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

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: regen
 * Description: Adds 5 strength points to the creatures current
 *  strength.
 * Parameters: none
 * Pre-Conditions: creature wins in battle
 * Post-Conditions: winning creature has 5 strength points added
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Medusa::regen()
{
    this->strength = this->get_strength() + 5;
}

/* SET functions */
void Medusa::set_strength(int val)
{
    this->strength = val;
}

void Medusa::set_user_name(std::string name)
{
    this->user_name = name;
}

void Medusa::set_team_name(std::string name)
{
    this->team_name = name;
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

std::string Medusa::get_user_name()
{
    return user_name;
}

std::string Medusa::get_team_name()
{
    return team_name;
}

int Medusa::get_type()
{
    return type;
}
