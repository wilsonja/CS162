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

#include <iostream>
#include "Team2cue.hpp"

/* DEFAULT CONSTRUCTOR */
Team2cue::Team2cue()
{
    head = NULL;
    tail = NULL;
    t2points = 0;
}

/* DESTRUCTOR */
Team2cue::~Team2cue()
{
    Node *nodePtr = head;
    
    while(nodePtr != NULL){
        Node *trash = nodePtr;
        nodePtr = nodePtr->next;
        
        delete trash;
    }
    delete nodePtr;
}

/* SET functions */
void Team2cue::set_points(int points)
{
    t2points += points;
}

/* GET functions */
int Team2cue::get_points()
{
    return t2points;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: add
 * Description: Adds a new creature pointer to the back of the team
 *  queue.
 * Parameters: Creature pointer
 * Pre-Conditions: pass a Creature pointer to a list object
 * Post-Conditions: builds the queue
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Team2cue::add(Creature *player1)
{
    if(head == NULL){
        head = new Node(player1);
        tail = head;
    }
    else{
        Node *nodePtr = head;
        
        while(nodePtr->next != NULL){
            nodePtr = nodePtr->next;
        }
        
        nodePtr->next = new Node(player1);
        nodePtr->prev = nodePtr;
        tail = nodePtr->next;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: remove
 * Description: The function removes the front node from the queue.
 * Parameters: none
 * Pre-Conditions: existing queue containing nodes
 * Post-Conditions: top node will have been removed from the queue
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Team2cue::remove()
{
    Node *nodePtr = head;
    head = head->next;
    
    if(head != NULL){
        head->prev = NULL;
    }
    delete nodePtr;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: peek
 * Description: The functions returns the Creature pointer that exists
 *  in the team queue.
 * Parameters: none
 * Pre-Conditions: object existing in team queue
 * Post-Conditions: return Creature pointer at head of queue
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

Creature* Team2cue::peek()
{
    if(head == NULL){
        return NULL;
    }
    else{
        return head->player;
    }
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: display
 * Description: Displays player names for Creature pointers in the
 *  team queue.
 * Parameters: none
 * Pre-Conditions: Queue holding Creature pointers
 * Post-Conditions: names are displayed
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Team2cue::display()
{
    Node *nodePtr = head;
    while(nodePtr != NULL){
        std::cout << nodePtr->player->get_user_name() << " the "
        << nodePtr->player->get_name() << std::endl;
        nodePtr = nodePtr->next;
    }
    delete nodePtr;
}
