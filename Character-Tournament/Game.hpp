/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * Program Filename: assignment4
 * * Author: Jacob Wilson
 * * Date: 2/28/14
 * * Description: This program is a modification of Assignment 3. A
 * *  user is now able to enter a team size which can then be
 * *  populated with multiple team members. Each team member is also
 * *  now able to be given a unique name. Players rotate throught their
 * *  lineup as they battle. A stack is created which holds the
 * *  players as they lose.
 * * Input: int from user serves as team size
 * * Output: display lineups, battles, and results
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "LoserStack.hpp"
#ifndef GAME_HPP
#define GAME_HPP

/* the Game class runs the battles */
class Game
{
private:
    
protected:
    /* two pointers to Creatures will be set to the characters */
    Creature *p1, *p2, *p3, *p4;
    Team1cue cue1;
    Team2cue cue2;
    LoserStack loser;
    std::string team1, team2, name1, name2;
    
    /* a bool tracks whether game continues */
    bool over, p1win, p2win;
    
public:
    /* CONSTRUCTOR/DESTRUCTOR */
    Game();
    ~Game();
    Game(int);
    
    /* MEMBER functions */
    void battle();
};

#endif
