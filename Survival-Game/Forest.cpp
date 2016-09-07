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

/* DEFAULT CONSTRUCTOR sets name */
#include "Forest.hpp"
#include <cstdlib>
#include <iostream>

Forest::Forest() : Region()
{
    this->name = "forest";
}

/* SET methods */
void Forest::set_name(std::string name)
{
    this->name = name;
}

/* GET methods */
std::string Forest::get_name()
{
    return name;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: hunt
 * Description: This function returns the results of the hunt in a
 *  way that is specific to the Forest class.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displayed to user, adds result to stack
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Forest::hunt()
{
    /* generate random number */
    int huntVal = (rand() % 20) + 1;
    
    /* determine result of hunt based on random number */
    if(huntVal == 5 || huntVal == 12){
        std::cout << "You have a boar in your sights!" << std::endl;
        sleep(2);
        std::cout << "Keep steady..." << std::endl;
        sleep(2);
        std::cout << "BANG!!!" << std::endl;
        sleep(2);
        std::cout << "You shot a wild boar! 35 lbs" << std::endl;
        std::cout << "                                     ))   /|      " << std::endl;
        std::cout << "                                  .-/'-|_/ |      " << std::endl;
        std::cout << "               __            __,-' (   / )/       " << std::endl;
        std::cout << "           .-''  '''-..__,-'''          -o.`.^_    " << std::endl;
        std::cout << "          /                                 ||'/  " << std::endl;
        std::cout << "  *--._ ./                                 _.--   " << std::endl;
        std::cout << "         |                              _.-'      " << std::endl;
        std::cout << "         :                           .-/          " << std::endl;
        std::cout << "          {                       )_ /            " << std::endl;
        std::cout << "            {                _)   / ( (            " << std::endl;
        std::cout << "             `.   /-.___.---'(  /    ()            " << std::endl;
        std::cout << "              (  /   ( |      ( |     L}           " << std::endl;
        std::cout << "               | )    L}       ( |                 " << std::endl;
        std::cout << "                |(              ( )                " << std::endl;
        std::cout << "                 L}              L}               " << std::endl;
        return 35;
    }
    else if(huntVal >=13 && huntVal <= 16){
        std::cout << "You have a turkey in your sights!" << std::endl;
        sleep(2);
        std::cout << "Keep steady..." << std::endl;
        sleep(2);
        std::cout << "BANG!!!" << std::endl;
        sleep(2);
        std::cout << "You shot a turkey! 15 lbs" << std::endl;
        std::cout << "                    .--.     " << std::endl;
        std::cout << "   {}              / q /^    " << std::endl;
        std::cout << "   { `}            | (-(~`   " << std::endl;
        std::cout << "  { '.{`}          |   )    " << std::endl;
        std::cout << "  {'-{ ' }  .-""'-. }  }     " << std::endl;
        std::cout << "  {._{'.' }/       '.) }    " << std::endl;
        std::cout << "  {_.{.   {`            |   " << std::endl;
        std::cout << "  {._{ ' {   ;'-=-.     |   " << std::endl;
        std::cout << "   {-.{.' {  ';-=-.`    /   " << std::endl;
        std::cout << "    {._.{.;    '-=-   .'    " << std::endl;
        std::cout << "    {_.-' `'.__  _,-'       " << std::endl;
        std::cout << "               |||`         " << std::endl;
        std::cout << "              .='==,        " << std::endl;
        return 15;
    }
    else{
        std::cout << "No luck this time!" << std::endl;
        return 0;
    }
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: scavenge
 * Description: This function returns a result that is specific to
 *  the Forest class.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displayed to user, adds to stack
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Forest::scavenge()
{
    /* generate random number */
    int scavVal = (rand() % 20) + 1;
    
    /* determine result based on random number */
    if(scavVal >= 5 && scavVal <= 12){
        std::cout << "  You gathered 1 log!" << std::endl;
        std::cout << "    ____________     " << std::endl;
        std::cout << "   ()__'___'____)    " << std::endl;
        return 1;
    }
    else if(scavVal >=13 && scavVal <= 16){
        std::cout << "  You gathered 3 logs!" << std::endl;
        std::cout << "     ___________      " << std::endl;
        std::cout << "    ()___'___'__)     " << std::endl;
        std::cout << "   ()()_'___'__'_)    " << std::endl;
        return 3;
    }
    else if(scavVal >= 2 && scavVal <= 5){
        std::cout << "   You gathered 2 logs!" << std::endl;
        std::cout << "     ____________      " << std::endl;
        std::cout << "    ()__'___'____)     " << std::endl;
        std::cout << "     ()__'___'____)    " << std::endl;
        return 2;
    }
    else{
        std::cout << "Nothing gathered this time." << std::endl;
        return 0;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: photo
 * Description: This function a result specific to the Forest class.
 * Parameters: an int specific to each location
 * Pre-Conditions: called from main and Game
 * Post-Conditions: displayes image to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Forest::photo(int place)
{
    /* display photo based on user location */
    if(place == 1){
        std::cout << "|-------------------------------------------------|" << std::endl;
        std::cout << "| The Northern Pine Forest                        |" << std::endl;
        std::cout << "|                        @                        |" << std::endl;
        std::cout << "|    ^^                 @@@         8             |" << std::endl;
        std::cout << "|                      @@@@@        88            |" << std::endl;
        std::cout << "| ^^          %&     ,@@@@@@@,     8888           |" << std::endl;
        std::cout << "|           %%&%&   ,@@@@@@/@@,  .oo8888o.        |" << std::endl;
        std::cout << "|        ,&%%&%&&%,@@@@@/@@@@@@,8888|88/8o        |" << std::endl;
        std::cout << "|       ,%&|%&&%&&%,@@@|@@@/@@@88|88888/88'       |" << std::endl;
        std::cout << "|      %&&%&%&/%&&%@@%@@/ /@@@88888|88888'88      |" << std::endl;
        std::cout << "|     %&&%&&%/ %&%%&&@@| V /@@'8888|8 `/88'88     |" << std::endl;
        std::cout << "|    %%&%&&%| ` /%&'%&& |.|   88888* '|8888888'   |" << std::endl;
        std::cout << "|            |o|        | |         | |           |" << std::endl;
        std::cout << "|            |.|        | |         | |           |" << std::endl;
        std::cout << "| -o{]----__/ ._}//_/__/  ,}_//__0|/.  }_//__/_   |" << std::endl;
        std::cout << "|-------------------------------------------------|" << std::endl;
    }else if(place == 2){
        std::cout << "|-------------------------------------------------|" << std::endl;
        std::cout << "| Cougar Mtn. Forest                              |" << std::endl;
        std::cout << "|                        @                   ^^   |" << std::endl;
        std::cout << "|                       @@@         8             |" << std::endl;
        std::cout << "|           ^          @@@@@        88            |" << std::endl;
        std::cout << "|          &%&       ,@@@@@@@,     8888           |" << std::endl;
        std::cout << "|         &%&&%&    ,@@@@@@/@@,  .oo8888o.        |" << std::endl;
        std::cout << "|     ^  &%&&%&%&  ,@@@@@/@@@@@@,8888|88/8o       |" << std::endl;
        std::cout << "|    &/&&%&&/%*&%&,@@@@@|@@@/@@@88|88888/88'      |" << std::endl;
        std::cout << "|   7%&&% &%&&%&&,@@@@%@@/ /@@@88888|88888'88     |" << std::endl;
        std::cout << "|  &%&%&&%& ||  ,@@@@@@@| V /@@'8888|8 `/88'88    |" << std::endl;
        std::cout << "|     ||    || ,@@@@@&& |.| @888888* '|8888888'   |" << std::endl;
        std::cout << "|     ||    ||          | |         | |           |" << std::endl;
        std::cout << "|     ||    ||          | |         | |           |" << std::endl;
        std::cout << "|   _.||{/o|/ ._}//_/__/  ,}_//__o|/.  }_//__/_   |" << std::endl;
        std::cout << "|-------------------------------------------------|" << std::endl;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: special
 * Description: This function display a turkey call or drinking to user.
 * Parameters: an int specific to each location
 * Pre-Conditions: called from main and Game
 * Post-Conditions: displayes text to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Forest::special(int num)
{
    if(num == 2){
        std::cout << "gobble" << std::endl;
        usleep(10000 * 30);
        std::cout << "gobble" << std::endl;
        sleep(2);
        std::cout << "gobble" << std::endl;
        usleep(10000 * 30);
        std::cout << "gobble" << std::endl;
        usleep(10000 * 30);
        std::cout << "gobble" << std::endl;
        sleep(2);
        std::cout << "I think your turkey call could use some work!" << std::endl;
        sleep(2);
    }else if(num == 3){
        std::cout << "gulp" << std::endl;
        usleep(10000 * 50);
        std::cout << "gulp" << std::endl;
        usleep(10000 * 50);
        std::cout << "gulp" << std::endl;
        sleep(1);
        std::cout << "Ahhh, refreshing." << std::endl;
        sleep(2);
    }
}

/* credit for forest images: http://www.chris.com/ascii/index.
 * php?art=plants/trees */
