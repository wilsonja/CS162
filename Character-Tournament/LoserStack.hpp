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

#ifndef LOSERSTACK_HPP
#define LOSERSTACK_HPP
#include "Team2cue.hpp"

/* The LoserStack holds the losing players */
class LoserStack
{
protected:
    /* this struct forms the stack list */
    struct Node
    {
        Creature *player;
        Node *next;
        
        Node(Creature *play, Node *next1 = NULL)
        {
            player = play;
            next = next1;
        }
    };
    Node *head;
    
public:
    /* CONSTRUCTOR/DESTRUCTOR */
    LoserStack();
    ~LoserStack();
    
    /* MEMBER functions */
    Creature* peek();
    void add(Creature*);
    void remove();
    void display();
};

#endif
