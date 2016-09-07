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

#include "Field.hpp"
#include <cstdlib>
#include <iostream>

/* DEFAULT CONSTRUCTOR sets name */
Field::Field() : Region()
{
    this->name = "field";
}

/* SET methods */
void Field::set_name(std::string name)
{
    this->name = name;
}

/* GET methods */
std::string Field::get_name()
{
    return name;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: hunt
 * Description: This function returns the results of the hunt in a
 *  way that is specific to the Field class.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displayed to user, adds weight result to stack
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Field::hunt()
{
    /* create random number */
    int huntVal = (rand() % 20) + 1;

    /* determine result of hunt based on random number */
    if(huntVal == 12){
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
    else if(huntVal >= 1 && huntVal <= 5){
        std::cout << "You have a turkey in your sights!" << std::endl;
        sleep(2);
        std::cout << "Keep steady..." << std::endl;
        sleep(2);
        std::cout << "BANG!!!" << std::endl;
        sleep(2);
        std::cout << "You shot a turkey! 12 lbs" << std::endl;
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
    else if(huntVal >=13 && huntVal <=20){
        std::cout << "You caught a rabbit with your bare hands! 2 lbs" << std::endl;
        std::cout << "　          　_ - 、                 " << std::endl;
        std::cout << "　　　　　　　 ///^ l                 " << std::endl;
        std::cout << "　　　　　　 ///　　l                 " << std::endl;
        std::cout << "　　　　　 / /ｌ l_ //-－　'''''-     " << std::endl;
        std::cout << "　　　　 / ￣_　　　ヽ　　　　　　　 ＼  " << std::endl;
        std::cout << "　　　 /　　(o)　　　　ｌ　l    　　　ｌ " << std::endl;
        std::cout << "　　　 lY:::　　　　　　  ｌ 　　　　　ｌ" << std::endl;
        std::cout << "　　　ヽヽ　　　　　 /　　　 　　　　　ｌ " << std::endl;
        std::cout << "　　　 　>－－　　　　　　l　　　　　/   " << std::endl;
        std::cout << "　　　　　/ 　＼ _/　　　／　 ヽ＿　／   " << std::endl;
        std::cout << "　　　　((＿／　 /　　／￣　((＿／      " << std::endl;
        std::cout << "            ((＿／                  " << std::endl;
        return 3;
    }else{
        std::cout << "No luck this time!" << std::endl;
        return 0;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: scavenge
 * Description: This function returns a result that is specific to
 *  the Field class.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displayed to user, adds to stack
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Field::scavenge()
{
    /* create a random number */
    int scavVal = (rand() % 20) + 1;
    
    /* determine result of scavenge based on number */
    if(scavVal >= 3 && scavVal <= 17){
        std::cout << " You gathered a bundle of tinder! " << std::endl;
        std::cout << "             @                  " << std::endl;
        std::cout << "      xX  %//#$ /*$^#           " << std::endl;
        std::cout << "       &////x////               " << std::endl;
        std::cout << "      //x/;#*&                  " << std::endl;
        std::cout << "     $%/  // #$/                " << std::endl;
        return 1;
    }
    else{
        std::cout << "Nothing gathered this time." << std::endl;
        return 0;
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: photo
 * Description: This function a result specific to the Field class.
 * Parameters: an int specific to each location
 * Pre-Conditions: called from main and Game
 * Post-Conditions: displayes image to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Field::photo(int place)
{
    /* display photo of region */
    std::cout << "|---------------------------------------------------|" << std::endl;
    std::cout << "| FIELD CAMP                                        |" << std::endl;
    std::cout << "|                .-.       |         _              |" << std::endl;
    std::cout << "|               /   }    -(_)-     _/ )             |" << std::endl;
    std::cout << "|  _        .--'|/|_ }     |      /    )       ___  |" << std::endl;
    std::cout << "| / }_    _/ ^      }/|'__        /|/}  /}  __/   ) |" << std::endl;
    std::cout << "|/    |  /    .'   _/  /  |  *' /    }/  }/ .`'}_/ }|" << std::endl;
    std::cout << "|}/}  /}/ :' __  ^/  ^/    `--./.'  ^  `-.| _    _: |" << std::endl;
    std::cout << "|   }/  /  _/  }-' __/.' ^ _   |_   .'/   _/ | .  __|" << std::endl;
    std::cout << "| .-   `. |/     } / -.   _/ } -. `_/   } /    `._/ |" << std::endl;
    std::cout << "|-.__ ^   / .-'.--'    . /    `--./ .-'  `-.  `-. `.|" << std::endl;
    std::cout << "|    `.  / /      `-.   /  .-'   / .   .'   }    |  |" << std::endl;
    std::cout << "|@)&@&(88&@.-_=_-=_-=_-=_-=_.8@% &@&&8(8%@%8)(8@%8 8|" << std::endl;
    std::cout << "|8:::&::%&`.~-_~~-~~_~-~_~-~~=.'@(&%::::%@8&8)::&#@8|" << std::endl;
    std::cout << "|::::::@%&8:`.=~~-.~~-.~~=..~'8::::::::&@8:::::&8:::|" << std::endl;
    std::cout << "|:::::::::::::::::::::::::::::::::::::::::::::::::::|" << std::endl;
    std::cout << "|---------------------------------------------------|" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: special
 * Description: This function displays a nap for the user.
 * Parameters: an int specific to each location
 * Pre-Conditions: called from main and Game
 * Post-Conditions: displayes text to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Field::special(int num)
{
    if(num == 1){
        std::cout << "ZZZZ..." << std::endl;
        sleep(2);
        std::cout << "ZZZZZZZ..." << std::endl;
        sleep(2);
        std::cout << "ZZZZZZZZZZZ..." << std::endl;
        sleep(2);
        std::cout << "Time to wake up!" << std::endl;
        sleep(2);
    }
}

/* credit for field images: http://www.ascii-code.com/ascii-
 * art/nature/mountains.php */
