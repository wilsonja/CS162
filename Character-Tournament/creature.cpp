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

#include "Creature.hpp"

/* DEFAULT CONSTRUCTOR */
Creature::Creature()
{
    this->strength = 0;
    this->armor = 0;
    this->name = " ";
    this->type = 0;
    this->user_name = " ";
    this->team_name = " ";
}

/* DESTRUCTOR */
Creature::~Creature()
{
    /* virtual, intentionally empty */
}

/*SET functions */
void Creature::set_strength(int val)
{
    this->strength = val;
}

void Creature::set_user_name(std::string name)
{
    this->user_name = name;
}

void Creature::set_team_name(std::string name)
{
    this->team_name = name;
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

std::string Creature::get_user_name()
{
    return user_name;
}

std::string Creature::get_team_name()
{
    return team_name;
}

int Creature::get_type()
{
    return type;
}
