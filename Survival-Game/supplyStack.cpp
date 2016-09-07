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

#include "supplyStack.hpp"
#include <iostream>

/* DEFAULT CONSTRUCTOR */
SupplyStack::SupplyStack()
{
    head = NULL;
}

/* DESTRUCTOR cleans up nodes */
SupplyStack::~SupplyStack()
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
 * Description: This function adds a new node to the supply stack
 * Parameters: string name and integer amount
 * Pre-Conditions: called from Game
 * Post-Conditions: new node is added
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void SupplyStack::add(std::string name, int amount)
{
    if(head == NULL){
        head = new Node(name, amount);
    }
    else{
        Node *nodePtr = head;
        
        head = new Node(name, amount);
        
        head->next = nodePtr;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: remove
 * Description: This function removes a node from the top of the
 *  supply stack
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: top node is removed
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void SupplyStack::remove()
{
    Node *nodePtr = head;
    
    head = head->next;
    
    delete nodePtr;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: peek
 * Description: This function returns whether the top node is filled
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: returns true/false based on top item contents
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

bool SupplyStack::peek()
{
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: top
 * Description: This function returns the name of the top item on
 *  the supply stack
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: returns name of item on top of stack
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

std::string SupplyStack::top()
{
    return head->name;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: display
 * Description: This function displays the entire stack
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displays name and weight of all stack items
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void SupplyStack::display()
{
    std::cout << "Supplies:" << std::endl;
    Node *nodePtr = head;
    while(nodePtr){
        std::cout << nodePtr->name << ": " << nodePtr->amount << std::endl;
        nodePtr = nodePtr->next;
    }
    delete nodePtr;
}
