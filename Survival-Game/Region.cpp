/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * Program Filename: final162
 * * Author: Jacob Wilson
 * * Date: 3/14/14
 * * Description: This program is a survival game. The player is able
 * *  to move between linked regions where they can performa number
 * *  of tasks. When the player achieves the tasks, the game will be
 * *  complete.
 * * Input: integers throughout game
 * * Output: various results throughout
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Region.hpp"

/* CONSTRUCTOR sets region pointers to NULL */
Region::Region()
{
    this->name = " ";
    this->up = NULL;
    this->down = NULL;
    this->left = NULL;
    this->right = NULL;
}

/* VIRTUAL DESTRUCTOR */
Region::~Region()
{
    /* virtual, intentionally left empty */
}

/* SET methods - set variables */
void Region::set_name(std::string name)
{
    this->name = name;
}

void Region::set_up(Region* place)
{
    this->up = place;
}

void Region::set_down(Region* place)
{
    this->down = place;
}

void Region::set_left(Region* place)
{
    this->left = place;
}

void Region::set_right(Region* place)
{
    this->right = place;
}

/* GET methods - return variables */
Region* Region::get_up()
{
    return this->up;
}

Region* Region::get_down()
{
    return this->down;
}

Region* Region::get_left()
{
    return this->left;
}

Region* Region::get_right()
{
    return this->right;
}

std::string Region::get_name()
{
    return name;
}
