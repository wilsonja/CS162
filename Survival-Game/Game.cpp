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

#include "Game.hpp"
#include <iostream>

/* CONSTRUCTOR instantiates each region and links to four other regions */
Game::Game()
{
    /* instantiate new region objects */
    this->camp = new Field();
    this->westLake = new Lake();
    this->eastLake = new Lake();
    this->northForest = new Forest();
    this->southForest = new Forest();
    
    /* set all four directions to neighboring regions */
    this->camp->set_up(northForest);
    this->camp->set_down(southForest);
    this->camp->set_left(westLake);
    this->camp->set_right(eastLake);
    this->camp->set_name("Field Camp");
    
    this->westLake->set_up(northForest);
    this->westLake->set_down(southForest);
    this->westLake->set_left(eastLake);
    this->westLake->set_right(camp);
    this->westLake->set_name("Beaver Dam Lake");
    
    this->eastLake->set_up(northForest);
    this->eastLake->set_down(southForest);
    this->eastLake->set_left(camp);
    this->eastLake->set_right(westLake);
    this->eastLake->set_name("Granite Lake");
    
    this->northForest->set_up(southForest);
    this->northForest->set_down(camp);
    this->northForest->set_left(westLake);
    this->northForest->set_right(eastLake);
    this->northForest->set_name("The Northern Pine Forest");
    
    this->southForest->set_up(camp);
    this->southForest->set_down(northForest);
    this->southForest->set_left(westLake);
    this->southForest->set_right(eastLake);
    this->southForest->set_name("Cougar Mountain Forest");
    
    /* new player object */
    this->p1 = new Player();
    
    /* set player location to start at camp */
    p1->set_location(camp);
    
    /* all bools to false */
    fire = false;
    meal = false;
    wood = false;
    food = false;
    tnder = false;
    woodDone = false;
    picCamp = false;
    picNforest = false;
    picSforest = false;
    picElake = false;
    picWlake = false;
    allPics = false;
    alertTinder = false;
    alertWood = false;
    alertMeat = false;
    gameOver = false;
    
    /* all counts to zero */
    meats1 = 0;
    logs = 0;
    tinder = 0;
    supplyCount = 0;
    meatCount = 0;
    hours = 1;
}

/* DESCTRUCTOR deletes all objects */
Game::~Game()
{
    delete p1;
    delete camp;
    delete westLake;
    delete eastLake;
    delete northForest;
    delete southForest;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: play
 * Description: This function controls all gameplay aspects
 * Parameters: none
 * Pre-Conditions: called from main
 * Post-Conditions: various displays to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Game::play()
{
    /* loop while player has not made meal and fire */
    while(!fire && !meal){
        /* limits players to 12 moves */
        if(hours == 13){
            std::cout << "You took too long to gather your items. It's dark and cold.\n";
            std::cout << "Your group will not survive the night." << std::endl;
            std::cout << "GAME OVER" << std::endl;
            return;
        }
        /* while player is at camp */
        while(p1->get_location() == camp){
            
            /* show location */
            std::cout << "|--------------------------------------------|" << std::endl;
            std::cout << "|  Current location: " << p1->loc_name() << std::endl;
            std::cout << "|  Time: " << hours << " o'clock" << std::endl;
            
            /* determine if player able to make fire and meal */
            if(tinder >= 1){
                tnder = true;
            }
            if (logs >= 5){
                wood = true;
            }
            if(meats1 >= 20){
                food = true;
            }
            if(picCamp == true && picNforest == true  && picSforest == true &&
               picElake == true && picWlake == true){
                allPics = true;
            }
            
            int choice;
            campMenu();
            choice = campChoice();
            
            /* chooses to build fire */
            if(choice == 1){
                /* needs all pics and wood to build fire */
                if(allPics == true){
                    if(wood == true){
                        std::cout << "         You have built a fire!          " << std::endl;
                        std::cout << "                                         " << std::endl;
                        std::cout << "               (  .      )               " << std::endl;
                        std::cout << "           )           (                 " << std::endl;
                        std::cout << "                .  '   .   '  .          " << std::endl;
                        std::cout << "        (  , )       (.   )  (           " << std::endl;
                        std::cout << "         .' ) ( . )    ,  ( ,   )        " << std::endl;
                        std::cout << "      ). , ( .   (  ) ( , ')  .' (,      " << std::endl;
                        std::cout << "     (_,) . ), ) _) _,')  (, ) '. )      " << std::endl;
                        std::cout << " ___(_,) . ), (, ) ) (.')  (, ) '. )___  " << std::endl;
                        std::cout << "()__  (_,) . ), ) _) _,')  (, ) '. ) __()" << std::endl;
                        std::cout << "       .`/``||``[ ]  .`/``||``[ ]        " << std::endl;
                        std::cout << "      ()/   ()   (()()/   ()   (()       " << std::endl;
                        std::cout << " " << std::endl;
                        fire = true;
                    }
                    else{
                        std::cout << "You need to gather more supplies." << std::endl;
                    }
                }else{
                        std::cout << "You must take all pictures before you settle \n";
                        std::cout << "down for the night." << std::endl;
                }
            }
            /* chooses to make meal */
            else if(choice == 2){
                /* requires all fire and food */
                if(fire == true){
                    if(food == true){
                        std::cout << "You have prepared a meal!" << std::endl;
                        std::cout << "Your group will survive the night!" << std::endl;
                        std::cout << "                      _______                  " << std::endl;
                        std::cout << "                   .-' _____ '-.       /|      " << std::endl;
                        std::cout << "         ||||    .' .-'.  ':'-. '.    | |  __  " << std::endl;
                        std::cout << "    |||| ||||   / .''::: .:    '. }   | | /  ) " << std::endl;
                        std::cout << "    |||| {__/  / /   :::::'      ) )  | | |(_| " << std::endl;
                        std::cout << "    {__/  ||  | ;.    ':' `       ; | ( | (__/ " << std::endl;
                        std::cout << "     ||   ||  | |       '..       | |  ||  ||  " << std::endl;
                        std::cout << "     ##   ##  | ; '      ::::.    ; |  ##  ##  " << std::endl;
                        std::cout << "     ##   ##   ( (       '::::   / /   ##  ##  " << std::endl;
                        std::cout << "     j#   ##    ( '.      :::  .' /    ##  ##  " << std::endl;
                        std::cout << "     g#   ##     '. '-.___'_.-' .'     ##  ##  " << std::endl;
                        std::cout << "     s#   ##       '-._______.-'       ##  ##  " << std::endl;
                        std::cout << "                                               " << std::endl;
                        std::cout << "   d88888b d88888b  .d8b.  .d8888. d888888b db " << std::endl;
                        std::cout << "   88'     88'     d8' `8b 88'  YP `~~88~~' 88 " << std::endl;
                        std::cout << "   88ooo   88ooooo 88ooo88 `8bo.      88    YP " << std::endl;
                        std::cout << "   88~~~   88~~~~~ 88~~~88   `Y8b.    88       " << std::endl;
                        std::cout << "   88      88.     88   88 db   8D    88    db " << std::endl;
                        std::cout << "   YP      Y88888P YP   YP `8888Y'    YP    YP " << std::endl;
                        sleep(3);
                        std::cout << "GAME OVER" << std::endl;
                        sleep(3);
                        meal = true;
                        return;
                    }else{
                        std::cout << "You need to collect more food." << std::endl;
                    }
                }else{
                    std::cout << "You must build a fire first." << std::endl;
                }
            }
            /* chooses to gather supplies */
            else if(choice == 3){
                /* if supplies aren't full */
                if(supplyCount < 15){
                    /* gather and add supply */
                    int gather = p1->get_location()->scavenge();
                
                    if(gather == 1){
                        supplies.add("Tinder", 1);
                        tinder += 1;
                        supplyCount++;
                    }
                }else{
                    std::cout << "You must remove supplies before you can add more." << std::endl;
                }
                
                /* if player has collected all necessary tinder */
                if(tinder >= 1 && !alertTinder){
                    std::cout << "You've collected all the tinder you need." << std::endl;
                    sleep(2);
                    alertTinder = true;
                }
            }
            /* chooses to hunt */
            else if(choice == 4){
                /* needs to be able to store more meat */
                if(meatCount < 10){
                    /* hunts at their location */
                    int meat = p1->get_location()->hunt();
                
                    if(meat == 35){
                        meats.add("Wild Boar", 35);
                        meats1 += 35;
                        meatCount++;
                    }
                    else if(meat == 15){
                        meats.add("Turkey", 15);
                        meats1 += 15;
                        meatCount++;
                    }
                    else if(meat == 3){
                        meats.add("Rabbit", 2);
                        meats1 += 3;
                        meatCount++;
                    }
                }else{
                    std::cout << "You must remove meat before you can add more." << std::endl;
                }
                
                /* if player has collected all necessary meat */
                if(meats1 >= 20 && !alertMeat){
                    std::cout << "You've collected all the meat you need." << std::endl;
                    sleep(2);
                    alertMeat = true;
                }
            }
            /* chooses to check supplies */
            else if(choice == 5){
                meats.display();
                std::cout << std::endl;
                supplies.display();
                std::cout << std::endl;
            }
            /* chooses to remove supplies */
            else if(choice == 6){
                int rmvChoice;
                std::cout << "Choose where to remove from" << std::endl;
                std::cout << "1. Remove the top meat item." << std::endl;
                std::cout << "2. Remove the top supply item." << std::endl;
                std::cin >> rmvChoice;
                
                /* shows item removed */
                if(rmvChoice == 1){
                    if(!meats.peek()){
                        std::cout << "You removed the top " << meats.top() << "." << std::endl;
                        meats.remove();
                        --meatCount;
                    }else{
                        std::cout << "Your meat supply is already empty." << std::endl;
                    }
                    
                }else if(rmvChoice == 2){
                    if(!supplies.peek()){
                        std::cout << "You removed the top " << supplies.top() << "." << std::endl;
                        supplies.remove();
                        --supplyCount;
                    }else{
                        std::cout << "Your supplies are already empty." << std::endl;
                    }
                }
            }
            /* chooses to take picture */
            else if(choice == 7){
                if(!picCamp){
                    p1->get_location()->photo(1);
                    picCamp = true;
                }
                else{
                    std::cout << "You already took a picture here, don't waste the \n";
                    std::cout << "cameras batteries." << std::endl;
                }
            }
            /* call special function for region */
            else if(choice == 8){
                p1->get_location()->special(1);
            }
            /* chooses to check map */
            else if(choice == 9){
                hours++;
                int choice;
                campMap();
                choice = mapChoice();
                
                /* set new location if player decides to move */
                if(choice == 1){
                    p1->set_location(camp->get_up());
                }
                else if(choice == 2){
                    p1->set_location(camp->get_right());
                }
                else if(choice == 3){
                    p1->set_location(camp->get_down());
                }
                else if(choice == 4){
                    p1->set_location(camp->get_left());
                }
                else if(choice == 5){
                    p1->set_location(camp);
                    hours--;
                }
            }
        }
        /* checks overall time */
        if(hours == 13){
            std::cout << "You took too long to gather your items. It's dark and cold.\n";
            std::cout << "Your group will not survive the night." << std::endl;
            std::cout << "GAME OVER" << std::endl;
            return;
        }
        /* when player is at north forest */
        while(p1->get_location() == northForest){
            
            /* display location */
            std::cout << "|--------------------------------------------|" << std::endl;
            std::cout << "|  Current location: " << p1->loc_name() << std::endl;
            std::cout << "|  Time: " << hours << " o'clock" << std::endl;
            
            int choice;
            northForestMenu();
            choice = regionChoice();
            
            /* chooses to gather wood */
            if(choice == 1){
                /* area is limited in amount of wood */
                if(woodDone){
                    std::cout << "Looks like you've gathered all the wood from this forest." << std::endl;
                }else{
                    if(supplyCount < 15){
                        int gather = p1->get_location()->scavenge();
                    
                        if(gather == 1){
                            supplies.add("Wood logs", 1);
                            logs += 1;
                            woodDone = true;
                            supplyCount++;
                        }
                        else if(gather == 2){
                            supplies.add("Wood logs", 2);
                            logs += 2;
                            woodDone = true;
                            supplyCount++;
                        }
                        else if(gather == 3){
                            supplies.add("Wood logs", 3);
                            logs += 3;
                            woodDone = true;
                            supplyCount++;
                        }
                    }else{
                        std::cout << "You must remove supplies before you can add more.\n";
                        std::cout << "Return to camp to drop off supplies." << std::endl;
                    }
                }
                /* if player has collected all necessary wood */
                if(logs >= 5 && !alertWood){
                    std::cout << "You've collected all the wood you need." << std::endl;
                    sleep(2);
                    alertWood = true;
                }
            }
            /* chooses to hunt */
            else if(choice == 2){
                /* as long as meat stack not full */
                if(meatCount < 10){
                    /* hunts in region */
                    int meat = p1->get_location()->hunt();
                
                    if(meat == 35){
                        meats.add("Wild Board", 35);
                        meats1 += 35;
                        meatCount++;
                    }
                    else if(meat == 15){
                        meats.add("Turkey", 15);
                        meats1 += 15;
                        meatCount++;
                    }
                }else{
                    std::cout << "You must remove meat before you can add more.\n";
                    std::cout << "Return to camp to drop off meat." << std::endl;
                }
                
                if(meats1 >= 20 && !alertMeat){
                    std::cout << "You've collected all the meat you need." << std::endl;
                    sleep(2);
                    alertMeat = true;
                }
            }
            /* chooses to check items */
            else if(choice == 3){
                meats.display();
                std::cout << std::endl;
                supplies.display();
                std::cout << std::endl;
            }
            /* chooses to take picture */
            else if(choice == 4){
                if(!picNforest){
                    p1->get_location()->photo(1);
                    picNforest = true;
                }
                /* can only take one picture */
                else{
                    std::cout << "You already took a picture here, don't waste the \n";
                    std::cout << "cameras batteries." << std::endl;
                }
            }
            /* call special function */
            else if(choice == 5){
                p1->get_location()->special(2);
            }
            /* chooses to view map */
            else if(choice == 6){
                hours++;
                int choice;
                nForestMap();
                choice = mapChoice();
                
                /* sets new location if player leaves */
                if(choice == 1){
                    p1->set_location(northForest->get_right());
                }
                else if(choice == 2){
                    p1->set_location(northForest->get_down());
                }
                else if(choice == 3){
                    p1->set_location(northForest->get_up());
                }
                else if(choice == 4){
                    p1->set_location(northForest->get_left());
                }
                else if(choice == 5){
                    p1->set_location(northForest);
                    hours--;
                }
            }
        }
        /* check overall time */
        if(hours == 13){
            std::cout << "You took too long to gather your items. It's dark and cold.\n";
            std::cout << "Your group will not survive the night." << std::endl;
            std::cout << "GAME OVER" << std::endl;
            return;
        }
        /* if player is at east lake */
        while(p1->get_location() == eastLake){
            
            /* display location */
            std::cout << "|--------------------------------------------|" << std::endl;
            std::cout << "|  Current location: " << p1->loc_name() << std::endl;
            std::cout << "|  Time: " << hours << " o'clock" << std::endl;
            
            int choice;
            eastLakeMenu();
            choice = regionChoice();
            
            /* chooses to hunt */
            if(choice == 1){
                if(meatCount < 10){
                    int meat = p1->get_location()->hunt();
                
                    if(meat == 8){
                        meats.add("Bass", 8);
                        meats1 += 8;
                        meatCount++;
                    }
                    else if(meat == 4){
                        meats.add("Rainbow Trout", 4);
                        meats1 += 4;
                        meatCount++;
                    }
                    else if(meat == 1){
                        meats.add("Bluegill", 1);
                        meats1 += 1;
                        meatCount++;
                    }
                }else{
                    std::cout << "You must remove meat before you can add more.\n";
                    std::cout << "Return to camp to drop off meat." << std::endl;
                }
                
                if(meats1 >= 20 && !alertMeat){
                    std::cout << "You've collected all the meat you need." << std::endl;
                    sleep(2);
                    alertMeat = true;
                }
            }
            /* chooses to gather supplies */
            else if(choice == 2){
                if(supplyCount < 15){
                    int gather = p1->get_location()->scavenge();
                
                    if(gather == 100){
                        supplies.add("Trash", 1);
                        supplyCount++;
                    }
                    else if(gather == 200){
                        supplies.add("Wet Sticks", 1);
                        supplyCount++;
                    }
                }else{
                    std::cout << "You must remove supplies before you can add more.\n";
                    std::cout << "Return to camp to drop off supplies." << std::endl;
                }
            }
            /* chooses to check item */
            else if(choice == 3){
                meats.display();
                std::cout << std::endl;
                supplies.display();
                std::cout << std::endl;
            }
            /* chooses to take photo */
            else if(choice == 4){
                if(!picElake){
                    p1->get_location()->photo(1);
                    picElake = true;
                }
                else{
                    std::cout << "You already took a picture here, don't waste the \n";
                    std::cout << "cameras batteries." << std::endl;
                }
            }
            /* call special function */
            else if(choice == 5){
                p1->get_location()->special(5);
            }
            /* chooses to view map */
            else if(choice == 6){
                hours++;
                int choice;
                eLakeMap();
                choice = mapChoice();
                
                /* change to new location */
                if(choice == 1){
                    p1->set_location(eastLake->get_up());
                }
                else if(choice == 2){
                    p1->set_location(eastLake->get_left());
                }
                else if(choice == 3){
                    p1->set_location(eastLake->get_down());
                }
                else if(choice == 4){
                    p1->set_location(eastLake->get_right());
                }
                else if(choice == 5){
                    p1->set_location(eastLake);
                    hours--;
                }
            }
        }
        /* check overall time */
        if(hours == 13){
            std::cout << "You took too long to gather your items. It's dark and cold.\n";
            std::cout << "Your group will not survive the night." << std::endl;
            std::cout << "GAME OVER" << std::endl;
            return;
        }
        /* if player is at south forest */
        while(p1->get_location() == southForest){
            
            std::cout << "|--------------------------------------------|" << std::endl;
            std::cout << "|  Current location: " << p1->loc_name() << std::endl;
            std::cout << "|  Time: " << hours << " o'clock" << std::endl;
            
            int choice;
            southForestMenu();
            choice = regionChoice();
            
            /* chooses to pick up new items */
            if(choice == 1){
                if(supplyCount < 15){
                    int gather = p1->get_location()->scavenge();
                
                    if(gather == 1){
                        supplies.add("Wood logs", 1);
                        logs += 1;
                        supplyCount++;
                    }
                    else if(gather == 2){
                        supplies.add("Wood logs", 2);
                        logs += 2;
                        supplyCount++;
                    }
                    else if(gather == 3){
                        supplies.add("Wood logs", 3);
                        logs += 3;
                        supplyCount++;
                    }
                }else{
                    std::cout << "You must remove supplies before you can add more.\n";
                    std::cout << "Return to camp to drop off supplies." << std::endl;
                }
                
                if(logs >= 5 && !alertWood){
                    std::cout << "You've collected all the wood you need." << std::endl;
                    sleep(2);
                    alertWood = true;
                }
            }
            /* chooses to hunt */
            else if(choice == 2){
                if(meatCount < 10){
                    int meat = p1->get_location()->hunt();
                
                    if(meat == 35){
                        meats.add("Wild Boar", 35);
                        meats1 += 35;
                        meatCount++;
                    }
                    else if(meat == 15){
                        meats.add("Turkey", 15);
                        meats1 += 15;
                        meatCount++;
                    }
                }else{
                    std::cout << "You must remove meat before you can add more.\n";
                    std::cout << "Return to camp to drop off meat." << std::endl;
                }
                
                if(meats1 >= 20 && !alertMeat){
                    std::cout << "You've collected all the meat you need." << std::endl;
                    sleep(2);
                    alertMeat = true;
                }
            }
            /* chooses to check items */
            else if(choice == 3){
                meats.display();
                std::cout << std::endl;
                supplies.display();
                std::cout << std::endl;
            }
            /* choose to take photo */
            else if(choice == 4){
                /* different photo based on location */
                if(!picSforest){
                    p1->get_location()->photo(2);
                    picSforest = true;
                }else{
                    std::cout << "You already took a picture here, don't waste the \n";
                    std::cout << "cameras batteries." << std::endl;
                }
            }
            /* call special function */
            else if(choice == 5){
                p1->get_location()->special(3);
            }
            /* chooses to view map */
            else if(choice == 6){
                hours++;
                int choice;
                sForestMap();
                choice = mapChoice();
                
                /* moves to new location */
                if(choice == 1){
                    p1->set_location(southForest->get_up());
                }
                else if(choice == 2){
                    p1->set_location(southForest->get_right());
                }
                else if(choice == 3){
                    p1->set_location(southForest->get_left());
                }
                else if(choice == 4){
                    p1->set_location(southForest->get_down());
                }
                else if(choice == 5){
                    p1->set_location(southForest);
                    hours--;
                }
            }
        }
        /* check overall time */
        if(hours == 13){
            std::cout << "You took too long to gather your items. It's dark and cold.\n";
            std::cout << "Your group will not survive the night." << std::endl;
            std::cout << "GAME OVER" << std::endl;
            return;
        }
        /* if player is at west lake */
        while(p1->get_location() == westLake){
            
            std::cout << "|--------------------------------------------|" << std::endl;
            std::cout << "|  Current location: " << p1->loc_name() << std::endl;
            std::cout << "|  Time: " << hours << " o'clock" << std::endl;
            
            int choice;
            westLakeMenu();
            choice = regionChoice();
            
            /* chooses to fish */
            if(choice == 1){
                if(meatCount < 10){
                    int meat = p1->get_location()->hunt();
                
                    /* results are different at west lake */
                    if(meat == 8){
                        int huntVal = (rand() % 20) + 1;
                        if(huntVal >= 15){
                            meats.add("Bass", 8);
                            meats1 += 8;
                            meatCount++;
                        }else{
                            std::cout << std::endl;
                            std::cout << "The bass spit out the lure!" << std::endl;
                            std::cout << "You lost the bass! Keep fishing!" << std::endl;
                        }
                    }
                    else if(meat == 15){
                        meats.add("Rainbow Trout", 4);
                        meats1 += 4;
                        meatCount++;
                    }
                    else if(meat == 1){
                        meats.add("Bluegill", 1);
                        meats1 += 1;
                        meatCount++;
                    }
                }else{
                    std::cout << "You must remove meat before you can add more.\n";
                    std::cout << "Return to camp to drop off meat." << std::endl;
                }
                
                /* supply space is limited */
                if(meats1 >= 20 && !alertMeat){
                    std::cout << "You've collected all the meat you need." << std::endl;
                    sleep(2);
                    alertMeat = true;
                }
            }
            /* chooses to gather supplies */
            else if(choice == 2){
                if(supplyCount < 15){
                    int gather = p1->get_location()->scavenge();
                
                    if(gather == 100){
                        supplies.add("Trash", 1);
                        supplyCount++;
                    }
                    else if(gather == 200){
                        supplies.add("Wet Sticks", 1);
                        supplyCount++;
                    }
                }else{
                    std::cout << "You must remove supplies before you can add more.\n";
                    std::cout << "Return to camp to drop off supplies." << std::endl;
                }
            }
            /* chooses to display items */
            else if(choice == 3){
                meats.display();
                std::cout << std::endl;
                supplies.display();
                std::cout << std::endl;
            }
            /* chooses to take photo */
            else if(choice == 4){
                /* different picture based on different lake */
                if(!picWlake){
                    p1->get_location()->photo(2);
                    picWlake = true;
                }
                else{
                    p1->get_location()->photo(3);
                }
            }
            /* call special function */
            else if(choice == 5){
                p1->get_location()->special(4);
            }
            /* choose to view map */
            else if(choice == 6){
                hours++;
                int choice;
                wLakeMap();
                choice = mapChoice();
                
                /* goes to new location */
                if(choice == 1){
                    p1->set_location(westLake->get_up());
                }
                else if(choice == 2){
                    p1->set_location(westLake->get_right());
                }
                else if(choice == 3){
                    p1->set_location(westLake->get_down());
                }
                else if(choice == 4){
                    p1->set_location(westLake->get_left());
                }
                else if(choice == 5){
                    p1->set_location(westLake);
                    hours--;
                }
            }
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: photoShow
 * Description: This function photos taken at each region.
 * Parameters: none
 * Pre-Conditions: called from main
 * Post-Conditions: displays all photos
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Game::photoShow(){
    camp->photo(1);
    westLake->photo(1);
    eastLake->photo(2);
    northForest->photo(1);
    southForest->photo(2);
}

/* credit for images: http://www.chris.com/ascii/joan/www.
 * geocities.com/SoHo/7373/food.html
 * http://patorjk.com/software/taag */
