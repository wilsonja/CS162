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

#include "BlueMen.hpp"
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

/* HarryPotter class is child of Creature */
class HarryPotter : public Creature
{
private:
    
protected:
    
public:
    /* CONSTRUCTOR */
    HarryPotter();
    
    /* MEMBER functions */
    int attack();
    int defense();
    
    /* SET functions */
    void set_strength(int);
    
    /* GET functions */
    int get_strength();
    int get_armor();
    std::string get_name();
    int get_type();
};

#endif
