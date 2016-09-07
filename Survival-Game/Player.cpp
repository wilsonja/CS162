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

#include "Player.hpp"

/* CONSTRUCTOR */
Player::Player()
{
    this->name = "Player 1";
}

/* SET methods */
void Player::set_name(std::string name)
{
    this->name = name;
}

void Player::set_location(Region* place)
{
    location = place;
}

/* GET methods */
Region* Player::get_location()
{
    return location;
}

std::string Player::loc_name()
{
    return location->get_name();
}
