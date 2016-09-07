/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * Program Filename: Assignment3
 * * Author: Jacob Wilson
 * * Date: 2/14/16
 * * Description: This program simulates a dice battle between two
 * *  characters. Each character has different attack, defense, armor,
 * *  and strength attributes. Some characters also have special
 * *  traits that are called at specific points.
 * * Input: choice of two characters
 * * Output: attack and defense values for each round
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <cstdlib>
#include <iostream>
#include "Game.hpp"

/* DEFAULT CONSTRUCTOR sets players to NULL and game tracker to false */
Game::Game()
{
    this->p1 = NULL;
    this->p2 = NULL;
    this->over = false;
}

/* DESTRUCTOR deletes pointers to game characters */
Game::~Game()
{
    delete p1;
    delete p2;
}

/* SECOND CONSTRUCTOR creates new characters when chosen */
Game::Game(int char1, int char2)
{
    this->over = false;
    
    /* assign player 1 */
    if(char1 == 1)
    {
        this->p1 = new Medusa();
    }
    else if(char1 == 2)
    {
        this->p1 = new Barbarian();
    }
    else if(char1 == 3)
    {
        this->p1 = new Vampire();
    }
    else if(char1 == 4)
    {
        this->p1 = new BlueMen();
    }
    else if(char1 == 5)
    {
        this->p1 = new HarryPotter();
    }
    
    /* assign player 2 */
    if(char2 == 1)
    {
        this->p2 = new Medusa();
    }
    else if(char2 == 2)
    {
        this->p2 = new Barbarian();
    }
    else if(char2 == 3)
    {
        this->p2 = new Vampire();
    }
    else if(char2 == 4)
    {
        this->p2 = new BlueMen();
    }
    else if(char2 == 5)
    {
        this->p2 = new HarryPotter();
    }
    
    /* display chosen characters to user */
    std::cout << p1->get_name() << " and " << p2->get_name() << " are set to fight!" << std::endl;
    std::cout << std::endl;
    sleep(2);
    
    /* call battle function */
    battle();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: battle
 * Description: The battle function calls attack and defense rolls,
 *  tracks player health values, and enacts special traits for all
 *  players.
 * Parameters: none
 * Pre-Conditions: game class object created in main
 * Post-Conditions: will display game as it progresses
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Game::battle()
{
    /* set Harry Potter and Blue Men special functions to false */
    bool hogwarts = false;
    bool mob1p1 = false;
    bool mob2p1 = false;
    bool mob1p2 = false;
    bool mob2p2 = false;

    /* loop through the game while there is no winner (for player 1 attacks, player 2 defends) */
    while(this->over== false)
    {
        /* variables to track attack, defense, damage, updated strength, and generic values */
        int att1, att2, def1, def2, damTo1, damTo2, up1s, up2s, val1, val2;
        
        /* set Medusa special to false */
        bool glare = false;
        bool charm = false;
    
        /* Vampire special; 50% chance of no attack */
        val1 = (rand() % 2);
        if((val1 == 1) && (p2->get_type() == 3))
        {
            charm = true;
        }
        else
        {
            charm = false;
        }
    
        /* if Vampire charm is successful */
        if(charm ==  true)
        {
            std::cout << "The Vampire has charmed " << p1->get_name() << ", " << p1->get_name() <<
                         " has no attack this round." << std::endl;
            att1 = 0;
            def2 = 0;
        }
        /* regular attack sequence */
        else
        {
            att1 = p1->attack();
            std::cout << p1->get_name() << " rolled " << att1 << " for attack." << std::endl;
            
            def2 = p2->defense();
            std::cout << p2->get_name() << " rolled "<< def2 << " for defense." << std::endl;
        }
        
        /* calculate damage to player 2 after player 1 attack */
        damTo2 = (att1 - def2) - p2->get_armor();
        
        /* if damage is positive, display and update */
        if(damTo2 >0)
        {
            std::cout << "Total damage inflicted on " << p2->get_name() << ": " << damTo2 << std::endl;
            up2s = p2->get_strength() - damTo2;
            p2->set_strength(up2s);
        }
        /* if damage is negative, no points are taken */
        else
        {
            std::cout << "No damage done to " << p2->get_name() << std::endl;
        }
        
        /* Blue Men special notification; will lose one die if the fall below 8 */
        if((p2->get_type() == 4) && (p2->get_strength() <= 8) && mob1p2 == false)
        {
            mob1p2 = true;
            std::cout << "The Blue Men have lost one of their mob! Down one defense die." << std::endl;
        }
        
        /* second part of Blue Men special notification, if they fall below 4 */
        if((p2->get_type() == 4) && (p2->get_strength() <= 4) && mob2p2 == false)
        {
            mob2p2 = true;
            std::cout << "The Blue Men have lost another of their mob! Down another defense die." << std::endl;
        }
        
        /* Medusa special; if she rolls a 12 */
        if((p1->get_type() == 2) && (att1 == 12))
        {
            glare = true;
        }
        
        /* Harry Potter special; regains 20 strength if he gets below 0, only called once */
        if((p2->get_type() == 5) && (p2->get_strength() <=0) && hogwarts == false)
        {
            hogwarts = true;
            p2->set_strength(20);
            std::cout << std::endl;
            std::cout << "Harry Potter has summoned Hogwarts and regained 20 strength!" << std::endl;
        }
        
        /* player 1 wins */
        if(p2->get_strength() <= 0 || glare == true)
        {
            this->over = true;
            std::cout << std::endl;
            sleep(3);
            
            /* if win with Medusa special */
            if(glare == true)
            {
                std::cout << "Player 1 wins! " << p1->get_name() << " has used glare." << std:: endl;
            }
            /* normal win */
            else
            {
                std::cout << "Player 1 wins! " << p1->get_name() << " has defeated " << p2->get_name() << "." << std::endl;
            }
        }
        
        std::cout << std::endl;
        sleep(5);
        
        /* loop through the game while there is no winner (for player 2 attacks, player 1 defends) */
        if(this->over == false)
        {
            /* charm special for player 2 attacking */
            val2 = (rand() % 2);
            if((val2 == 1) && (p1->get_type() == 3))
            {
                charm = true;
            }
            else
            {
                charm = false;
            }
            
            if(charm ==  true)
            {
                std::cout << "The Vampire has charmed " << p2->get_name() << ", " << p2->get_name() << " has no attack this round." << std::endl;
                att2 = 0;
                def1 = 0;
            }
            /* regular attack for player 2 */
            else
            {
                att2 = p2->attack();
                std::cout << p2->get_name() << " rolled " << att2<< " for attack." << std::endl;
                
                def1 = p1->defense();
                std::cout << p1->get_name() << " rolled "<< def1 << " for defense." << std::endl;
            }
            
            /* calculate damage to player 1, after player 2 attack */
            damTo1 = (att2 - def1) - p1->get_armor();
            
            if(damTo1 > 0)
            {
                std::cout << "Total damage inflicted on " << p1->get_name() << ": " << damTo1 << std::endl;
                up1s = p1->get_strength() - damTo1;
                p1->set_strength(up1s);
            }
            else
            {
                std::cout << "No damage done to " << p1->get_name() << std::endl;
            }
            
            /* player 1 Blue Men special */
            if((p1->get_type() == 4) && (p1->get_strength() <= 8) && mob1p1 == false)
            {
                mob1p1 = true;
                std::cout << "The Blue Men have lost one of their mob! Down one defense die." << std::endl;
            }
            
            if((p1->get_type() == 4) && (p1->get_strength() <= 4) && mob2p1 == false)
            {
                mob2p1 = true;
                std::cout << "The Blue Men have lost another of their mob! Down another defense die." << std::endl;
            }
            
            /* player 2 Medusa special */
            if((p2->get_type() == 2) && (att2 == 12))
            {
                glare = true;
            }
            
            /* player 1 Harry Potter special */
            if((p1->get_type() == 5) && (p1->get_strength() <=0) && hogwarts == false)
            {
                hogwarts = true;
                p1->set_strength(20);
                std::cout << std::endl;
                std::cout << "Harry Potter has summoned Hogwarts and regained 20 strength!" << std::endl;
                sleep(2);
            }
            
            /* player 2 wins */
            if(p1->get_strength() <= 0 || glare == true)
            {
                this->over = true;
                std::cout << std::endl;
                sleep(3);
                
                /* if win with Medusa special */
                if(glare == true)
                {
                    std::cout << "Player 2 wins! " << p2->get_name() << " has used glare." << std:: endl;
                }
                /* normal win */
                else
                {
                    std::cout << "Player 2 wins! " << p2->get_name() << " has defeated " << p1->get_name() << "." << std::endl;
                }
            }
            std::cout << std::endl;
            sleep(5);
        }
    }
}
