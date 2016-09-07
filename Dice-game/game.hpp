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

#ifndef GAME_HPP
#define GAME_HPP
#include <stdio.h>
#include "loadeddie.hpp"

/* The Game class controls all parts of the game. It accepts user-defined
 * variables from main and accesses the Die class roll functions. */
class Game
{
protected:
    Die *p1;
    Die *p2;
    int numRounds,
        p1score,
        p2score;
    
public:
    Game();
    ~Game();
    Game(int, bool, int, bool, int);
    void setNumRounds(int);
    int getNumRounds();
    int getTotScore();
};

#endif
