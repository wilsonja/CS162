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

#ifndef TEAM2CUE_HPP
#define TEAM2CUE_HPP
#include "Team1cue.hpp"

/* Team2cue holds Creature pointers for team 2 */
class Team2cue
{
protected:
    /* this struct forms the doubly-linked list */
    struct Node
    {
        Creature *player;
        Node *prev;
        Node *next;
        
        Node(Creature *player2, Node *next1 = NULL, Node *prev1 = NULL)
        {
            player = player2;
            next = next1;
            prev = prev1;
        }
    };
    Node *head;
    Node *tail;
    int t2points;
    
public:
    /* CONSTRUCTOR/DESCTRUCTOR */
    Team2cue();
    ~Team2cue();
    
    /* SET functions */
    void set_points(int);
    
    /* GET functions */
    int get_points();
    
    /* MEMBER functions */
    Creature* peek();
    void add(Creature *);
    void remove();
    void display();
};

#endif
