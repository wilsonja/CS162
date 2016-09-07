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

#include "HarryPotter.hpp"
#ifndef GAME_HPP
#define GAME_HPP

/* the Game class runs the battles */
class Game
{
private:
    
protected:
    /* two pointers to Creatures will be set to the characters */
    Creature *p1;
    Creature *p2;
    
    /* a bool tracks whether game continues */
    bool over;
    
public:
    /* CONSTRUCTOR/DESTRUCTOR */
    Game();
    ~Game();
    Game(int, int);
    
    /* MEMBER functions */
    void battle();
};

#endif
