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
#include "Lake.hpp"
#include <cstdlib>
#include <iostream>

Lake::Lake() : Region()
{
    this->name = "lake";
}

/* SET methods */
void Lake::set_name(std::string name)
{
    this->name = name;
}

/* GET methods */
std::string Lake::get_name()
{
    return name;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: hunt
 * Description: This function returns the results of the hunt in a
 *  way that is specific to the Lake class.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displayed to user, adds result to stack
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Lake::hunt()
{
    /* generate random number */
    int huntVal = (rand() % 20) + 1;
    int choice;
    
    /* let user choose fishing set up */
    std::cout << "Choose a setup:" << std::endl;
    std::cout << "1. worm and bobber" << std::endl;
    std::cout << "2. bass lure" << std::endl;
    std::cout << "3. trout bait" << std::endl;
    std::cin >> choice;
    
    /* fish based on set up */
    if(choice == 1){
        /* determine result based on random number */
        if(huntVal == 11 || huntVal == 6){
            std::cout << "Casting..." << std::endl;
            sleep(2);
            std::cout << "You have a bite!" << std::endl;
            sleep(2);
            std::cout << "You caught a juicy bass! 8 lbs" << std::endl;
            std::cout << "＼　　　　　 ＿＿＿＿＿＿＿__／ゝ                           " << std::endl;
            std::cout << "　＼　,,‐‐丶;:;:;:;:;:;:;:;;:;:ヽ' 　ゝ                   " << std::endl;
            std::cout << "　　X/~゜ヾ （●）;:;:;:;:;:;:ヽ;:;:ヽ' ゝ                  " << std::endl;
            std::cout << "　　　ヽ＼　＼ゝ:;:;:;:;:;::　＿＿;:;:;:;ヽ' ゝ               " << std::endl;
            std::cout << "　　   ||＼　 》　　　　;:;:／　 ,／;:;:;:;:;＼/                " << std::endl;
            std::cout << "　　　　//,,＼〃ゝ　 　　丿(〆　 _／;i|!|;:;::;;＼              " << std::endl;
            std::cout << "　　 （二二ノゾ　 　 　 ノ　　 ⌒￣;:;::;:|!|;:;:;|              " << std::endl;
            std::cout << "　　　　ヽー-ニニーーー'''''´　　　　　 　 ;!|i|:;:;|            " << std::endl;
            std::cout << "　　　　　ヽーーヽ_　　_　　 　　　　　　 ;:;:;;|!|!:;:|       " << std::endl;
            std::cout << "　　´ 　　　　　　　￣＼_　　＜￣,,/ 　 　 ;;:;i|!::;|           " << std::endl;
            std::cout << "　　　　　゜ 　　　　　　　　 　｀＼_　＼/　　　.:;|i!|          " << std::endl;
            std::cout << "　　　　;　　　　　 　 　'　　　　 　 ｀`ヽ 　　.;:;:/　　　　　" << std::endl;
            std::cout << "　　　　　　　、　 　　 　゜　　　　　　　 ｀`ヽ　　,/　　｀　　　　　´" << std::endl;
            std::cout << "　　　。　 　　　　　　　　　　　　　　_＿＿__ソ:::　,/　　　。      " << std::endl;
            std::cout << "　　　　　　　　　　　　　　　　　　　＼:;;::;::;::;　 ,/　;゜　 、 " << std::endl;
            std::cout << "　　　　　　　　;´　　　　　　　゜　。　　 ゞ,;:;:;:;:/             " << std::endl;
            return 8;
        }else{
            std::cout << "Casting..." << std::endl;
            sleep(2);
            std::cout << "You have a bite!" << std::endl;
            sleep(2);
            std::cout << "You caught a bluegill! 1 lb" << std::endl;
            std::cout << "                  _ _ _                  " << std::endl;
            std::cout << "              ,='`/ / /'=.               " << std::endl;
            std::cout << "             / / / / / / /'.             " << std::endl;
            std::cout << "            /_/_/_/_/_/ / / |     _.='/  " << std::endl;
            std::cout << "         .-' - _ - _ -`'-,/ /|  .'_.='/  " << std::endl;
            std::cout << "        / -_ - _ - _ - _ -//.'|/_.=`/    " << std::endl;
            std::cout << "       / @    _='`} _- _- _|.=/_. =';    " << std::endl;
            std::cout << "      /     -'_='} - _  - _ -=_-''=;     " << std::endl;
            std::cout << "      {-.   '=._}          ,._--_=_;     " << std::endl;
            std::cout << "       `-._     ._        /;' | `'=.;    " << std::endl;
            std::cout << "           `'|`;-.}_ _ _.;/ // \'=._|    " << std::endl;
            std::cout << "             { =.}) ) ) } \'   '._=_.|  " << std::endl;
            std::cout << "               {_}`=._)_|.'`       '=.|  " << std::endl;
            return 1;
        }
    }
    /* for next set up choice */
    else if(choice == 2){
        /* determine result based on random number */
        if(huntVal >= 7 && huntVal <= 12){
            std::cout << "Casting..." << std::endl;
            sleep(2);
            std::cout << "You have a bite!" << std::endl;
            sleep(2);
            std::cout << "You caught a juicy bass! 8 lbs" << std::endl;
            std::cout << "＼　　　　　　 ＿＿＿＿＿＿＿__／ゝ                           " << std::endl;
            std::cout << "　＼　　,,‐‐丶;:;:;:;:;:;:;:;;:;:ヽ' 　ゝ                   " << std::endl;
            std::cout << "　　X/~゜`＼ヾ （●）;:;:;:;:;:;:ヽ;:;:ヽ' ゝ                  " << std::endl;
            std::cout << "　　　ヽ＼　　＼ゝ:;:;:;:;:;::　＿＿;:;:;:;ヽ' ゝ               " << std::endl;
            std::cout << "　　   ||＼　 》　　　　;:;:／　 ,／;:;:;:;:;＼/                " << std::endl;
            std::cout << "　　　　//,,＼〃ゝ　 　　丿(〆　 _／;i|!|;:;::;;＼              " << std::endl;
            std::cout << "　　 （二二ノゾ　 　 　 ノ　　 ⌒￣;:;::;:|!|;:;:;|              " << std::endl;
            std::cout << "　　　　ヽー-ニニーーー'''''´　　　　　 　 ;!|i|:;:;|            " << std::endl;
            std::cout << "　　　　　ヽーーヽ_　　_　　 　　　　　　 ;:;:;;|!|!:;:|       " << std::endl;
            std::cout << "　　´ 　　　　　　　￣＼_　　＜￣,,/ 　 　 ;;:;i|!::;|           " << std::endl;
            std::cout << "　　　　　゜ 　　　　　　　　 　｀＼_　＼/　　　.:;|i!|          " << std::endl;
            std::cout << "　　　　;　　　　　 　 　'　　　　 　 ｀`ヽ 　　.;:;:/　　　　　" << std::endl;
            std::cout << "　　　　　　　、　 　　 　゜　　　　　　　 ｀`ヽ　　,/　　｀　　　　　´" << std::endl;
            std::cout << "　　　。　 　　　　　　　　　　　　　　_＿＿__ソ:::　,/　　　。      " << std::endl;
            std::cout << "　　　　　　　　　　　　　　　　　　　＼:;;::;::;::;　 ,/　;゜　 、 " << std::endl;
            std::cout << "　　　　　　　　;´　　　　　　　゜　。　　 ゞ,;:;:;:;:/             " << std::endl;
            return 8;
        }else{
            std::cout << "Casting..." << std::endl;
            sleep(2);
            std::cout << "No luck this time!" << std::endl;
            return 0;
        }
    }
    /* for last set up choice */
    else if(choice == 3){
        /* determine result based on random number */
        if(huntVal >= 4 && huntVal <= 8){
            std::cout << "Casting..." << std::endl;
            sleep(2);
            std::cout << "You have a bite!" << std::endl;
            sleep(2);
            std::cout << "You caught a rainbow trout! 4 lbs" << std::endl;
            std::cout << "                          ,__                 " << std::endl;
            std::cout << "                          |  `'.              " << std::endl;
            std::cout << "      __           |`-._/_.:---`-.._          " << std::endl;
            std::cout << "      )='.       _/..--'`__         `'-._     " << std::endl;
            std::cout << "       )- '-.--``      ===        /   o  `',  " << std::endl;
            std::cout << "        )= ( ) ) ) ) ) ) ) ) .--_ |        .' " << std::endl;
            std::cout << "       /_=.'-._             {=_-_ |   .--`-.  " << std::endl;
            std::cout << "      /_.'    `)`'-._        '-=   {    _.'   " << std::endl;
            std::cout << "               )  _.-'`'-..       _..-'`      " << std::endl;
            std::cout << "              /_.'        `/';';`|            " << std::endl;
            std::cout << "                            )` .'/            " << std::endl;
            std::cout << "                             '--'             " << std::endl;
            return 4;
        }else{
            std::cout << "Casting..." << std::endl;
            sleep(2);
            std::cout << "You have a bite!" << std::endl;
            sleep(2);
            std::cout << "You caught a bluegill! 1 lb" << std::endl;
            std::cout << "                  _ _ _                  " << std::endl;
            std::cout << "              ,='`/ / /'=.               " << std::endl;
            std::cout << "             / / / / / / /'.             " << std::endl;
            std::cout << "            /_/_/_/_/_/ / / |     _.='/  " << std::endl;
            std::cout << "         .-' - _ - _ -`'-,/ /|  .'_.='/  " << std::endl;
            std::cout << "        / -_ - _ - _ - _ -//.'|/_.=`/    " << std::endl;
            std::cout << "       / @    _='`} _- _- _|.=/_. =';    " << std::endl;
            std::cout << "      /     -'_='} - _  - _ -=_-''=;     " << std::endl;
            std::cout << "      {-.   '=._}          ,._--_=_;     " << std::endl;
            std::cout << "       `-._     ._        /;' | `'=.;    " << std::endl;
            std::cout << "           `'|`;-.}_ _ _.;/ // \'=._|    " << std::endl;
            std::cout << "             { =.}) ) ) } \'   '._=_.|  " << std::endl;
            std::cout << "               {_}`=._)_|.'`       '=.|  " << std::endl;
            return 1;
        }
    }else{
        std::cout << "A fish jumped in your boat, but you couldn't hang onto it!" << std::endl;
        return 0;
    }
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: scavenge
 * Description: This function returns a result that is specific to
 *  the Lake class.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displayed to user, adds to stack
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Lake::scavenge()
{
    /* generate random number */
    int scavVal = (rand() % 20) + 1;
    
    /* determine result based on random number */
    if(scavVal >= 1 && scavVal <= 7){
        std::cout << "You gathered wet sticks, can't be used for fire :(" << std::endl;
        return 200;
    }
    else if(scavVal >= 12 && scavVal <= 20){
        std::cout << "You gathered trash, nice job." << std::endl;
        return 100;
    }
    else{
        std::cout << "Nothing gathered this time." << std::endl;
        return 0;
    }
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: photo
 * Description: This function a result specific to the Lake class.
 * Parameters: an int specific to each location
 * Pre-Conditions: called from main and Game
 * Post-Conditions: displayes image to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Lake::photo(int lake)
{
    /* display photo based on which lake user is at */
    if(lake == 1){
        std::cout << "|-------------------------------------------------|" << std::endl;
        std::cout << "| Beaver Dam Lake                                 |" << std::endl;
        std::cout << "|                     .--.-.                      |" << std::endl;
        std::cout << "|                   ( (    )__                    |" << std::endl;
        std::cout << "|    ^^            (_,  / ) ,_)                   |" << std::endl;
        std::cout << "|       ^^          '-'--`--'         |           |" << std::endl;
        std::cout << "|                                 (       )       |" << std::endl;
        std::cout << "|              ~,                   .-'-.         |" << std::endl;
        std::cout << "|              /|              --  |     |  --    |" << std::endl;
        std::cout << "|  ~^~`^~^`^~ / |) ~^~~^~`~^^~^~^-=======-~^~^~^~~|" << std::endl;
        std::cout << "| ~^~ ~^~ ^~ /__|_)~^~ ~^~^~^~^_~-=========- -~^~^|" << std::endl;
        std::cout << "|~^~ ~^~^ ~ '======' `~^--^~^_~^~~ -=====- ~^~^~^~|" << std::endl;
        std::cout << "|   ~^~ ~^ ~^~ ~^~^ ~^~~^~-~^~~-~^~^~-~^~~^-~^~^~^|" << std::endl;
        std::cout << "|~^~ ~^~ ~^~ ~^ ~^~^ ~^~-~^~~^~-~^~~-~^~^~-~^~~^-~|" << std::endl;
        std::cout << "|-------------------------------------------------|" << std::endl;
    }
    else if(lake == 2){
        std::cout << "|-------------------------------------------------|" << std::endl;
        std::cout << "| Granite Lake                                    |" << std::endl;
        std::cout << "|     .--.-.                                      |" << std::endl;
        std::cout << "|    ( (    )__         ^^              ^^        |" << std::endl;
        std::cout << "|  (_,  / ) ,_)                    ^^             |" << std::endl;
        std::cout << "|    '-'--`--'   |                                |" << std::endl;
        std::cout << "|            (       )      ^^              ^^    |" << std::endl;
        std::cout << "|              .-'-.               ^^             |" << std::endl;
        std::cout << "|         --  |     |  --                         |" << std::endl;
        std::cout << "|  ~^~`^~^`^-=======-~  ^~~-~^~~^~`~^^~^~^~^~^~^~~|" << std::endl;
        std::cout << "| ~^~ ~^~ ^~-=========- ^~~-~^~^~ ~^~^~^~^_~ -~^~^|" << std::endl;
        std::cout << "|~^~ ~^~^ ~ '-=====-^~~-~^~^`~^--^~^_~^~~  ~^~^~^~|" << std::endl;
        std::cout << "|   ~^~ ~^ ~^~ ~^~^ ~^~~^~-~^~~-~^~^~-~^~~^-~^~^~^|" << std::endl;
        std::cout << "|~^~ ~^~ ~^~ ~^ ~^~^ ~^~-~^~~^~-~^~~-~^~^~-~^~~^-~|" << std::endl;
        std::cout << "|-------------------------------------------------|" << std::endl;
    }else{
        /* can only take one picture at least location */
        std::cout << "You already took a picture here, don't waste the \n";
        std::cout << "cameras batteries." << std::endl;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: special
 * Description: This function display a rock skip or splash to user.
 * Parameters: an int specific to each location
 * Pre-Conditions: called from main and Game
 * Post-Conditions: displayes text to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Lake::special(int num)
{
    if(num == 4){
        std::cout << "skip" << std::endl;
        usleep(10000 * 100);
        std::cout << "skip" << std::endl;
        usleep(10000 * 50);
        std::cout << "skip" << std::endl;
        usleep(10000 * 30);
        std::cout << "skip" << std::endl;
        usleep(10000 * 30);
        std::cout << "skip" << std::endl;
        usleep(10000 * 20);
        std::cout << "skip" << std::endl;
        usleep(10000 * 10);
        std::cout << "skip" << std::endl;
        usleep(10000 * 5);
        std::cout << "skip" << std::endl;
        usleep(10000 * 4);
        std::cout << "skip" << std::endl;
        usleep(10000 * 3);
        std::cout << "skip" << std::endl;
        usleep(10000 * 1);
        std::cout << "skip" << std::endl;
        sleep(2);
        std::cout << "Nice one!" << std::endl;
        sleep(2);
    }else if(num == 5){
        std::cout << "SPLASH!!" << std::endl;
        sleep(1);
        std::cout << "SPLASH!!" << std::endl;
        sleep(1);
        std::cout << "SPLASH!!" << std::endl;
        sleep(2);
        std::cout << "Okay, that's enough horseplay for now." << std::endl;
        sleep(2);
    }
}

/* credit for images, although they were modified:
 * lake scenes: http://www.chris.com/ascii/joan/www.
 * geocities.com/SoHo/7373/nature.html
 * fish: http://www.ascii-art.de/ascii/def/fish.txt */
