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
#include "LoserStack.hpp"

/* DEFAULT CONSTRUCTOR */
LoserStack::LoserStack()
{
    head = NULL;
}

/* DESTRUCTOR */
LoserStack::~LoserStack()
{
    Node *nodePtr = head;
    while(nodePtr != NULL){
        Node *trash = nodePtr;
        
        nodePtr = nodePtr->next;
        
        delete trash;
    }
    delete nodePtr;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: add
 * Description: Adds a new creature pointer to the front of the loser
 *  stack
 * Parameters: Creature pointer
 * Pre-Conditions: pass a Creature pointer to a list object
 * Post-Conditions: builds the stack
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void LoserStack::add(Creature *player)
{
    if(head == NULL){
        head = new Node(player);
    }
    else{
        Node *nodePtr = head;
        
        head = new Node(player);
        
        head->next = nodePtr;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: remove
 * Description: The function removes the top node from the stack.
 * Parameters: none
 * Pre-Conditions: existing stack containing nodes
 * Post-Conditions: top node will have been removed from the stack
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void LoserStack::remove()
{
    Node *nodePtr = head;
    
    head = head->next;
    
    delete nodePtr;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: peek
 * Description: The functions returns the Creature pointer that exists
 *  in the loser stack.
 * Parameters: none
 * Pre-Conditions: object existing in loser stack
 * Post-Conditions: return Creature pointer at head of the stack
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

Creature* LoserStack::peek()
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
 *  loser stack.
 * Parameters: none
 * Pre-Conditions: Stack holding Creature pointers
 * Post-Conditions: names are displayed
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void LoserStack::display()
{
    Node *nodePtr = head;
    while(nodePtr){
        std::cout << nodePtr->player->get_user_name() << " the "
        << nodePtr->player->get_name() << std::endl;
        nodePtr = nodePtr->next;
    }
    delete nodePtr;
}
