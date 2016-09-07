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

#ifndef DIE_HPP
#define DIE_HPP

/* The Die class contains variables for the number of sides on both
 * players dice. It also has functions to set and get this number, as
 * well as a roll function for the regular die. */
class Die
{
private:

protected:
    int p1sides,
        p2sides;
    
public:
    Die();
    void setp1sides(int);
    int getp1sides();
    void setp2sides(int);
    int getp2sides();
    virtual int roll(int);
};

#endif
