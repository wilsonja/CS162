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

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.hpp"

int main()
{
    srand((unsigned int) time(NULL));
    int char1, char2;
    
    /* opening display of game */
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
    std::cout << "* *                                       * *" << std::endl;
    std::cout << "* *     Welcome to the Battle Arena!      * *" << std::endl;
    std::cout << "* *                                       * *" << std::endl;
    std::cout << "* *                                       * *" << std::endl;
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
    sleep(2);

    
    /* get choice for first character */
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
    std::cout << "* *                                       * *" << std::endl;
    std::cout << "* *   Please choose the first character:  * *" << std::endl;
    displayMenu();
    char1 = getChoice();
    
    /* then choice for second character */
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
    std::cout << "* *                                       * *" << std::endl;
    std::cout << "* *   Now choose the second character:    * *" << std::endl;
    displayMenu();
    std::cin.ignore();
    char2 = getChoice();
    
    /* send both choices to start the game */
    Game game(char1, char2);
    
    return 0;
}
