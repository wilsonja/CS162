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

/* the Player class holds player location and items */
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "meatStack.hpp"
#include <string>
#include <vector>

class Player
{
private:
    std::string name;
    Region *location;
    
protected:
    
public:
    /* CONSTRUCTOR */
    Player();
    
    /* SET methods */
    void set_name(std::string);
    void set_location(Region*);
    
    /* GET methods */
    Region* get_location();
    std::string loc_name();
    
};

#endif
