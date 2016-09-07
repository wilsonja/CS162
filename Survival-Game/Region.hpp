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

#ifndef REGION_HPP
#define REGION_HPP
#include "Menu.hpp"
#include <string>

/* The Region class is the base class representing the spaces in the game */
class Region
{
private:
    /* four pointers to nearby locations */
    Region *up, *down, *left, *right;
protected:
    std::string name;
public:
    /* CONSTRUCTOR/DESCTRUCTOR */
    Region();
    virtual ~Region();
    
    /* SET methods */
    void set_name(std::string);
    void set_up(Region*);
    void set_down(Region*);
    void set_left(Region*);
    void set_right(Region*);
    
    /* GET methods */
    Region* get_up();
    Region* get_down();
    Region* get_left();
    Region* get_right();
    std::string get_name();
    
    /* PURE VIRTUAL functions */
    virtual int hunt() = 0;
    virtual int scavenge() = 0;
    virtual void photo(int) = 0;
    virtual void special(int) = 0;
};

#endif
