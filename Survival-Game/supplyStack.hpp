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

/* the supply stack store the users supplies in a stack */
#ifndef SUPPLYSTACK_HPP
#define SUPPLYSTACK_HPP
#include "Forest.hpp"

class SupplyStack
{
protected:
    struct Node
    {
        /* each node has a name and amount */
        std::string name;
        int amount;
        Node *next;
        
        Node(std::string name1, int amount1, Node *next1 = NULL)
        {
            name = name1;
            amount = amount1;
            next = next1;
        }
    };
    Node *head;
    
public:
    /* CONSTRUCTOR/DESTRUCTOR */
    SupplyStack();
    ~SupplyStack();
    
    /* MEMBER functions */
    void add(std::string, int);
    void remove();
    bool peek();
    std::string top();
    void display();
};

#endif
