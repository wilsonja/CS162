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
Game::Game(int members)
{
    this->over = false;
    this->p1win = false;
    this->p2win = false;
    int choice1, choice2;
    
    /* obtain team 1 name */
    std::cout << "Enter a name for team 1." << std::endl;
    std::cin.ignore();
    getline(std::cin, team1);
    std::cout << std::endl;
    
    /* loop to obtain number of players as chosen by user */
    for(int i = 0; i < members; i++){
        std::cout << "Please choose character " << i + 1 << " for team 1." << std::endl;
        displayMenu();
        choice1 = getChoice();
    
        /* create a new object */
        if(choice1 == 1){
            this->p1 = new Medusa();
        }
        else if(choice1 == 2){
            this->p1 = new Barbarian();
        }
        else if(choice1 == 3){
            this->p1 = new Vampire();
        }
        else if(choice1 == 4){
            this->p1 = new BlueMen();
        }
        else if(choice1 == 5){
            this->p1 = new HarryPotter();
        }
        
        /* give a user name to the new player */
        std::cout << "Add a name for this "  << p1->get_name() << "." << std::endl;
        std::cin >> name1;
        std::cout << std::endl;
        
        /* set names */
        p1->set_team_name(team1);
        p1->set_user_name(name1);
        
        /* add to first queue */
        cue1.add(p1);
    }
    
    /* obtain team 2 name */
    std::cout << "Enter a name for team 2." << std::endl;
    std::cin.ignore();
    getline(std::cin, team2);
    std::cout << std::endl;
    
    /* loop to obtain number of players as chosen by user */
    for(int i = 0; i < members; i++){
        std::cout << "Please choose character " << i + 1 << " for team 2." << std::endl;
        displayMenu();
        choice2 = getChoice();
    
        /* create a new object */
        if(choice2 == 1){
            this->p2 = new Medusa();
        }
        else if(choice2 == 2){
            this->p2 = new Barbarian();
        }
        else if(choice2 == 3){
            this->p2 = new Vampire();
        }
        else if(choice2 == 4){
            this->p2 = new BlueMen();
        }
        else if(choice2 == 5){
            this->p2 = new HarryPotter();
        }
        
        /* give a user name to the new player */
        std::cout << "Add a name for this " << p2->get_name() << "." << std::endl;
        std::cin >> name2;
        std::cout << std::endl;
        
        /* set names */
        p2->set_team_name(team2);
        p2->set_user_name(name2);
        
        /* add to second queue */
        cue2.add(p2);
    }
    
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
    int round = 1;
    char losers;
    
    /* perform battles while there are still characters in both queues */
    while((cue1.peek() != NULL) && (cue2.peek() != NULL))
    {
        p1win = false;
        p2win = false;
        this->over = false;
        
        /* obtain chacters at the front of the queue */
        p1 = cue1.peek();
        p2 = cue2.peek();
        
        /* display the lineups */
        std::cout << "/*/ /*/ /*/ /*/ /*/ /*/ /*/ /*/" << std::endl;
        std::cout << "\t" << "The Lineups:" << std::endl;
        std::cout << std::endl;
        std::cout << "Team 1: "<< team1 << " (wins: " << cue1.get_points() << ")" << std::endl;
        cue1.display();
        std::cout << std::endl;
        
        std::cout << "Team 2: " << team2 << " (wins: " << cue2.get_points() << ")" << std::endl;
        cue2.display();
        std::cout << std::endl;
        std::cout << "/*/ /*/ /*/ /*/ /*/ /*/ /*/ /*/" << std::endl;
        std::cout << std::endl;
        
        /* display the round and who is battling */
        std::cout << "Round " << round << "!" << std::endl;
        std::cout << p1->get_user_name() << " the " << p1->get_name() <<
        " vs. " << p2->get_user_name() << " the " << p2->get_name() << std::endl;
        std::cout << std::endl;
        
        std::cout << "battling..." << std::endl;
        sleep(4);
        std::cout << std::endl;
    
        /* set Harry Potter and Blue Men special functions to false */
        bool hogwarts = false;
    
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
                att1 = 0;
                def2 = 0;
            }
            /* regular attack sequence */
            else
            {
                att1 = p1->attack();
                def2 = p2->defense();
            }
        
            /* calculate damage to player 2 after player 1 attack */
            damTo2 = (att1 - def2) - p2->get_armor();
        
            /* if damage is positive, display and update */
            if(damTo2 >0)
            {
                up2s = p2->get_strength() - damTo2;
                p2->set_strength(up2s);
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
            }
        
            /* player 1 wins */
            if(p2->get_strength() <= 0 || glare == true)
            {
                this->over = true;
                this->p1win = true;
            
                /* if win with Medusa special */
                if(glare == true)
                {
                    std::cout << "Player 1 wins! " << std::endl;
                    std::cout << p1->get_user_name() << " the " << p1->get_name() <<
                    " has used glare." << std:: endl;
                    std::cout << std::endl;
                }
                /* normal win */
                else
                {
                    std::cout << "Player 1 wins! " << std::endl;
                    std::cout << p1->get_user_name() << " the " << p1->get_name() <<
                    " has defeated " << p2->get_user_name() << " the " << p2->get_name() <<
                    "." << std::endl;
                    std::cout << std::endl;
                }
                sleep(3);
            }
        
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
                    att2 = 0;
                    def1 = 0;
                }
                /* regular attack for player 2 */
                else
                {
                    att2 = p2->attack();
                    def1 = p1->defense();
                }
            
                /* calculate damage to player 1, after player 2 attack */
                damTo1 = (att2 - def1) - p1->get_armor();
            
                if(damTo1 > 0)
                {
                    up1s = p1->get_strength() - damTo1;
                    p1->set_strength(up1s);
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
                }
            
                /* player 2 wins */
                if(p1->get_strength() <= 0 || glare == true)
                {
                    this->over = true;
                    this->p2win = true;
                
                    /* if win with Medusa special */
                    if(glare == true)
                    {
                        std::cout << "Player 2 wins! " << std::endl;
                        std::cout << p2->get_user_name() << " the " << p2->get_name() <<
                        " has used glare." << std:: endl;
                        std::cout << std::endl;
                    }
                    /* normal win */
                    else
                    {
                        std::cout << "Player 2 wins! " << std::endl;
                        std::cout << p2->get_user_name() << " the " << p2->get_name() <<
                        " has defeated " << p1->get_user_name() << " the " << p1->get_name() <<
                        "." << std::endl;
                        std::cout << std::endl;
                    }
                    sleep(3);
                }
            }
        }
        
        /* if player 1 wins, add 5 additional strength points, move player to back of
         * queue, and add a point for players team */
        if(p1win == true){
            p1->regen();
            cue1.remove();
            cue1.add(p1);
            cue1.set_points(1);
        }
        /* if player 1 loses, move them to the loser stack */
        else if (p1win == false){
            cue1.remove();
            loser.add(p1);
        }
        
        /* if player 2 wins, add 5 additional strength points, move player to back of
         * queue, and add a point for players team */
        if(p2win == true){
            p2->regen();
            cue2.remove();
            cue2.add(p2);
            cue2.set_points(1);
        }
        /* if player 2 loses, move them to the loser stack */
        else if(p2win == false){
            cue2.remove();
            loser.add(p2);
        }
        /* increment to the next round */
        round++;
    }
    
    /* display if team 2 wins */
    if(cue1.peek() == NULL){
        std::cout << "** Team " << team2 << " wins! **" << std::endl;
        /* display win totals */
        std::cout << "    -- " << cue2.get_points() << " wins to " << cue1.get_points() << " wins --" << std::endl;
        std::cout << std::endl;
        /* display first place winners */
        std::cout << "1st Place from team " << team2 << ":" << std::endl;
        cue2.display();
        std::cout << std::endl;
    }
    /* display if team 1 wins */
    else if(cue2.peek() == NULL){
        std::cout << "** Team " << team1 << " wins! **" << std::endl;
        /* display win totals */
        std::cout << "    -- " << cue1.get_points() << " wins to " << cue2.get_points() << " wins --" << std::endl;
        std::cout << std::endl;
        /* display first place winners */
        std::cout << "1st Place from team " << team1 << ":" << std::endl;
        cue1.display();
        std::cout << std::endl;
    }
    
    /* display second place from the loser stack */
    p3 = loser.peek();
    std::cout << "2nd Place:" << std::endl;
    std::cout << p3->get_user_name() << " the " << p3->get_name() << " from team " << p3->get_team_name() << std::endl;
    std::cout << std::endl;
    loser.remove();
    
    /* display third place from the loser stack */
    if(loser.peek() != NULL){
        p4 = loser.peek();
        std::cout << "3rd Place:" << std::endl;
        std::cout << p4->get_user_name() << " the " << p4->get_name() << " from team " << p4->get_team_name() << std::endl;
        std::cout << std::endl;
        loser.remove();
    }
    
    /* give user option to show remaining losers */
    std::cout << "Would you like to display the losing players? (y/n)" << std::endl;
    std::cin >> losers;
    
    if(losers == 'y' || losers == 'Y'){
        
        std::cout << "Losing players:" << std::endl;
    
        if(loser.peek() == NULL){
            std::cout << "loser stack is empty" << std::endl;
        }
        else{
            /* display all players in the loser stack */
            loser.display();
        }
    }
    std::cout << std::endl;
}
