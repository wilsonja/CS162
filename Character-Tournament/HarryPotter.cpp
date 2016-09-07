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
#include "HarryPotter.hpp"

/* DEFAULT CONSTRUCTOR */
HarryPotter::HarryPotter() : Creature()
{
    this->strength = 10;
    this->armor = 0;
    this->name = "Harry Potter";
    this->type = 5;
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

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: regen
 * Description: Adds 5 strength points to the creatures current
 *  strength.
 * Parameters: none
 * Pre-Conditions: creature wins in battle
 * Post-Conditions: winning creature has 5 strength points added
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void HarryPotter::regen()
{
    this->strength = this->get_strength() + 5;
}

/* SET functions */
void HarryPotter::set_strength(int val)
{
    this->strength = val;
}

void HarryPotter::set_user_name(std::string name)
{
    this->user_name = name;
}

void HarryPotter::set_team_name(std::string name)
{
    this->team_name = name;
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

std::string HarryPotter::get_user_name()
{
    return user_name;
}

std::string HarryPotter::get_team_name()
{
    return team_name;
}

int HarryPotter::get_type()
{
    return type;
}
