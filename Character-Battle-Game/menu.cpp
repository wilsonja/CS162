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
#include "Menu.hpp"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: displayMenu
 * Description: This function displays menu choices for the user.
 * Parameters: none
 * Pre-Conditions: called from main
 * Post-Conditions: displayed to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void displayMenu()
{
    std::cout << "* *         1. Medusa                     * *" << std::endl;
    std::cout << "* *         2. Barbarian                  * *" << std::endl;
    std::cout << "* *         3. Vampire                    * *" << std::endl;
    std::cout << "* *         4. Blue Men                   * *" << std::endl;
    std::cout << "* *         5. Harry Potter               * *" << std::endl;
    std::cout << "* *                                       * *" << std::endl;
    std::cout << "* * * * * * * * * * * * * * * * * * * * * * *" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: getChoice
 * Description: This function accepts the choice made by the user. It
 *  then validates this input and sends it to main.
 * Parameters: none
 * Pre-Conditions: called from main
 * Post-Conditions: accepts and validates user input, sends to main
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int getChoice()
{
    int choice;
    
    std::cin >> choice;
    
    /* will validate user input expecting ints from 1-5 */
    while(choice < 1 || choice > 5)
    {
        std::cout << "Not a valid choice. Please enter 1, 2, 3, 4, or 5" << std::endl;
        std::cin.ignore();
        std::cin >> choice;
    }
    
    return choice;
}
