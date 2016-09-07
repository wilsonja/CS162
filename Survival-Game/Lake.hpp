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

/* The Lake class is derived from region */
#ifndef LAKE_HPP
#define LAKE_HPP
#include "Field.hpp"

class Lake : public Region
{
private:
    
protected:
    
public:
    /* CONSTRUCTOR */
    Lake();
    
    /* SET methods */
    void set_name(std::string);
    
    /* GET methods */
    std::string get_name();
    
    /* MEMBER methods */
    int hunt();
    int scavenge();
    void photo(int);
    void special(int);
};

#endif
