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
    std::cout << "\t" << "1. Medusa" << std::endl;
    std::cout << "\t" << "2. Barbarian" << std::endl;
    std::cout << "\t" << "3. Vampire" << std::endl;
    std::cout << "\t" << "4. Blue Men" << std::endl;
    std::cout << "\t" << "5. Harry Potter" << std::endl;
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
