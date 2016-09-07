/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * Program Filename: final162
 * * Author: Jacob Wilson
 * * Date: 3/14/14
 * * Description: This program is a survival game. The player is able
 * *  to move between linked regions where they can performa number
 * *  of tasks. When the player achieves the tasks, the game will be
 * *  complete.
 * * Input: integers throughout game
 * * Output: display various results throughout
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <cstdlib>
#include "Game.hpp"

int main()
{
    srand((unsigned int) time(NULL));
    int choice;
    bool played = false;
    
    do{
        /* display opening menu to user. user chooses to view rules or start game */                                                                                                                                      
                                                                                                                                                                                                                                                                                           
        mainMenu();
        choice = getChoice();
        
        /* display objectives */
        if(choice == 1){
            std::cout << "Objectives:" << std::endl;
            std::cout << "1. Build a fire - In order to build a fire, you must collect \n";
            std::cout << "tinder from the field and wood from the forests.\n";
            std::cout << "Fire requirements: 1 bundle of tinder, 5 wood logs" << std::endl;
            std::cout << std::endl;
            std::cout << "2. Prepare a meal - After you have built your fire, you will need \n";
            std::cout << "to prepare a meal for your group. You will obtain meat by either \n";
            std::cout << "hunting in the field or forests, or by fishing in the lakes." << std::endl;
            std::cout << "Meal requirements: 20 lbs of meat, complete building a fire first" << std::endl;
            std::cout << std::endl;
            std::cout << "3. Photograph your locations - You have a camera and must take a photo \n";
            std::cout << "at each of the locations you visit. You will have to complete this task \n";
            std::cout << "before you settle in for the night." << std::endl;
            std::cout << "Photo requirements: one from each location, 5 in total" << std::endl;
            std::cout << std::endl;
            std::cout << "Limitations:" << std::endl;
            std::cout << "1. The game will only last for 12 hours. Moving from one region to the \n";
            std::cout << "next advances time by approximately one hour." << std::endl;
            std::cout << "2. You can only carry 10 meat items, you can remove items if needed" << std::endl;
            std::cout << "3. You can only carry 15 supply items, you can remove items if needed" << std::endl;
            std::cout << std::endl;
        }
        /* display strategies */
        else if(choice == 2){
            std::cout << "Tips:" << std::endl;
            std::cout << "- You will be more successful when catching fish, but they. \n";
            std::cout << "will be smaller in size. You can feed your entire group with \n";
            std::cout << "a single successful hunt, but you have to be pretty lucky to \n";
            std::cout << "haul in a wild boar on your first try. \n";
            std::cout << std::endl;
            std::cout << "- Some forests have more scrap wood lying around compared to \n";
            std::cout << "others. If you feel you aren't collecting enough wood, try the \n";
            std::cout << "other forest." << std::endl;
            std::cout << std::endl;
            std::cout << "- Check your supplies as you go to know if you need to continue \n";
            std::cout << "hunting or gathering. You will be alerted when you reach a goal,\n";
            std::cout << "but only once."<< std::endl;
            std::cout << std::endl;
            std::cout << "- Take photos as you go so that you don't have to return to a \n";
            std::cout << "region you've already visited." << std::endl;
            std::cout << std::endl;
            std::cout << "- Since your supply capacity is limited, don't try to stock up\n";
            std::cout << "on smaller items such as fish. Or plan toremove items if you need \n";
            std::cout << "space for a larger item." << std::endl;
            std::cout << std::endl;
        }
        /* start game */
        else if (choice == 3){
            Game start;
            start.play();
            played = true;
        }
        /* display photos if player has played the game */
        else if(choice == 4){
            /* game has to be completed before being able to view photos */
            if(!played){
                std::cout << "You have to play the game to take the photos." << std::endl;
            }else{
                Game photo;
                photo.photoShow();
            }
        }
    }while(choice != 5);
        
    return 0;
}
