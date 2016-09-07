/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * Program Filename: Lab3
 * * Author: Jacob Wilson
 * * Date: 1/23/16
 * * Description: This program creates a dice version of the game war.
 * *  A single user provides details for a two-person game. Options
 * *  for die type and size are available. After running for the user-
 * *  specified number of rounds, a winner is declared.
 * * Input: die type and size, number of rounds
 * * Output: winner of game, final score, die type and size used
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "die.hpp"

/* The LoadedDie class contains a modified roll function */
class LoadedDie : public Die
{
protected:
    
public:
    LoadedDie();
    void setp1sides(int);
    int getp1sides();
    void setp2sides(int);
    int getp2sides();
    int roll(int);
};

#endif
