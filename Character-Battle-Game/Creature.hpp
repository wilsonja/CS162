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

#include <string>
#include "Menu.hpp"
#ifndef CREATURE_HPP
#define CREATURE_HPP

/* Creature class is parent class */
class Creature
{
private:
    
protected:
    int strength,
        armor,
        type;
    std::string name;
public:
    /* CONSTRUCTOR/DESCTRUCTOR */
    Creature();
    virtual ~Creature();
    
    /* VIRTUAL functions */
    virtual int attack() = 0;
    virtual int defense() = 0;
    
    /* SET functions */
    void set_strength(int);
    
    /* GET functions */
    int get_strength();
    int get_armor();
    std::string get_name();
    int get_type();
};

#endif
