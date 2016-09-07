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

#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"

/* the Game class creates the game and controls gameplay */
class Game
{
private:
    
protected:
    /* object for each space */
    Region *camp;
    Region *westLake;
    Region *eastLake;
    Region *northForest;
    Region *southForest;
    
    /* supply stacks */
    MeatStack meats;
    SupplyStack supplies;
    
    /* pointer to player object */
    Player *p1;
    
    /* control the game flow */
    bool fire, meal, wood, food, tnder, woodDone,
          picCamp, picNforest, picSforest, picElake, picWlake,
          allPics, alertTinder, alertWood, alertMeat, gameOver;
    
    /* track game items */
    int meats1, logs, tinder, supplyCount, meatCount, hours;
public:
    /* CONSTRUCTOR/DESTRUCTOR */
    Game();
    ~Game();
    
    /* MEMBER methods */
    void play();
    void photoShow();
};

#endif
