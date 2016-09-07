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

#include <iostream>
#include "game.hpp"

/* DEFAULT CONSTRUCTOR sets all values to 0 or NULL */
Game::Game()
{
    this->numRounds = 0;
    p1->setp1sides(0);
    p2->setp2sides(0);
    this->p1score = 0;
    this->p2score = 0;
    this->p1 = NULL;
    this->p2 = NULL;
}

/* CUSTOM CONSTRUCTOR accepts 3 ints and 2 bools from main */
Game::Game(int rounds, bool p1die, int p1sides, bool p2die, int p2sides)
{
    /* sets the number of rounds and starts scores at 0 */
    this->numRounds = rounds;
    this->p1score = 0;
    this->p2score = 0;
    
    /* create new Die or LoadedDie class objects dependent on user choice */
    if(p1die)
    {
        this->p1 = new Die();
    }
    else if(!p1die)
    {
        this->p1 = new LoadedDie();
    }
    
    if(p2die)
    {
        this->p2 = new Die();
    }
    else if(!p2die)
    {
        this->p2 = new LoadedDie();
    }
    
    /* set die sides after new objects are created */
    p1->setp1sides(p1sides);
    p2->setp2sides(p2sides);
    
    /* A loop will run according to the number of rounds chosen by the user.
     * Each round will make a call to the roll function depending on the type
     * of die that was chosen. The players score will increment if they win.*/
    for(int count = 0; count < numRounds; count++)
    {
        int p1roll = p1->roll(p1->getp1sides());
        int p2roll = p2->roll(p2->getp2sides());
        
        if(p1roll > p2roll)
        {
            p1score++;
        }
        else if(p1roll < p2roll)
        {
            p2score++;
        }
        
        //std::cout << p1roll << " " << p2roll << std::endl;   /* output roll result for testing */
    }
    
    /* If player 1 score is highest */
    if(p1score > p2score)
    {
        std::cout << "Player 1 is the winner!" << std::endl;
        std::cout << "Score:" << std::endl;
        std::cout << "\t" << "player 1: " << p1score << std::endl;
        std::cout << "\t" << "player 2: " << p2score << std::endl;
        std::cout << "Type of die used:" << std::endl;
        if(p1die)
        {
            std::cout << "\t" << "Player 1 used a " << p1->getp1sides() << "-sided regular die" << std::endl;
        }
        else
        {
            std::cout << "\t" << "Player 1 used a " << p1->getp1sides() << "-sided loaded die" << std::endl;
        }
        if(p2die)
        {
            std::cout << "\t" << "Player 2 used a " << p2->getp2sides() << "-sided regular die" << std::endl;
        }
        else
        {
            std::cout << "\t" << "Player 2 used a " << p2->getp2sides() << "-sided loaded die" << std::endl;
        }
    }
    /* If player 2 score is highest */
    else if(p1score < p2score)
    {
        std::cout << "Player 2 is the winner!" << std::endl;
        std::cout << "Score:" << std::endl;
        std::cout << "\t" << "player 1: " << p1score << std::endl;
        std::cout << "\t" << "player 2: " << p2score << std::endl;
        std::cout << "Type of die used:" << std::endl;
        if(p1die)
        {
            std::cout << "\t" << "Player 1 used a " << p1->getp1sides() << "-sided regular die" << std::endl;
        }
        else
        {
            std::cout << "\t" << "Player 1 used a " << p1->getp1sides() << "-sided loaded die" << std::endl;
        }
        if(p2die)
        {
            std::cout << "\t" << "Player 2 used a " << p2->getp2sides() << "-sided regular die" << std::endl;
        }
        else
        {
            std::cout << "\t" << "Player 2 used a " << p2->getp2sides() << "-sided loaded die" << std::endl;
        }
    }
}

/* DECONSTRUCTOR deletes the Die objects */
Game::~Game()
{
    delete this->p1;
    delete this->p2;
}
