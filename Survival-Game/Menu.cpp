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

#include "Menu.hpp"
#include <iostream>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: mainMenu
 * Description: This function displays menu choices for the user.
 * Parameters: none
 * Pre-Conditions: called from main
 * Post-Conditions: displayed to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void mainMenu()
{
    std::cout << "|--------------------------------------------|" << std::endl;
    std::cout << "|  Welcome to the Survivial Game" << std::endl;
    std::cout << "|  Choose an option:" << std::endl;
    std::cout << "|  1. View rules" << std::endl;
    std::cout << "|  2. View strategies" << std::endl;
    std::cout << "|  3. PLAY GAME" << std::endl;
    std::cout << "|  4. View your photos" << std::endl;
    std::cout << "|  5. quit" << std::endl;
    std::cout << "|--------------------------------------------|" << std::endl;
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

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: campMenu
 * Description: This function displays camp menu choices for the user.
 * Parameters: none
 * Pre-Conditions: called from main
 * Post-Conditions: displayed to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void campMenu()
{
    std::cout << "|  1. Build a Fire        6. Drop supplies" << std::endl;
    std::cout << "|  2. Prepare the meal    7. Take photo" << std::endl;
    std::cout << "|  3. Gather tinder       8. Take a nap" << std::endl;
    std::cout << "|  4. Go hunting          9. Go to map" << std::endl;
    std::cout << "|  5. Check supplies" << std::endl;
    std::cout << "|--------------------------------------------|" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: campChoice
 * Description: This function accepts the camp menu choice made by the
 *  user. It then validates this input and sends to the Game.
 * Parameters: none
 * Pre-Conditions: called from game
 * Post-Conditions: accepts and validates user input, sends to Game
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int campChoice()
{
    int choice;
    
    std::cin >> choice;
    
    /* will validate user input expecting ints from 1-9 */
    while(choice < 1 || choice > 9)
    {
        std::cout << "Not a valid choice. Please enter 1, 2, 3, 4, 5, 6, 7, 8, or 9" << std::endl;
        std::cin.ignore();
        std::cin >> choice;
    }
    
    return choice;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: campMap
 * Description: This function displays Camp map choices.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displayed to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void campMap()
{
    std::cout << "|--------------------------------------------|" << std::endl;
    std::cout << "|  Choose a direction to go:                 |" << std::endl;
    std::cout << "|  1. North to The Northern Pine Forest" << std::endl;
    std::cout << "|  2. East to Granite Lake" << std::endl;
    std::cout << "|  3. South fo Cougar Mtn. Forest" << std::endl;
    std::cout << "|  4. West to Beaver Dam Lake" << std::endl;
    std::cout << "|  5. Return to Field Camp menu" << std::endl;
    std::cout << "|--------------------------------------------|" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: northForestMenu
 * Description: This function displays Norther Forest menu choices for
 *  the user.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displayed to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void northForestMenu()
{
    std::cout << "|  1. Gather wood" << std::endl;
    std::cout << "|  2. Go hunting" << std::endl;
    std::cout << "|  3. Check supplies" << std::endl;
    std::cout << "|  4. Take photo" << std::endl;
    std::cout << "|  5. Practice your turkey call" << std::endl;
    std::cout << "|  6. Go to map" << std::endl;
    std::cout << "|--------------------------------------------|" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: nForestMap
 * Description: This function displays Norther Forest map choices for
 *  the user.
 * Parameters: none
 * Pre-Conditions: called from game
 * Post-Conditions: displayed to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void nForestMap()
{
    std::cout << "|--------------------------------------------|" << std::endl;
    std::cout << "|  Choose a direction to go:                 |" << std::endl;
    std::cout << "|  1. East to Granite Lake" << std::endl;
    std::cout << "|  2. South to Field Camp" << std::endl;
    std::cout << "|  3. Zipline to the Cougar Mtn. Forest" << std::endl;
    std::cout << "|  4. West to Beaver Dam Lake" << std::endl;
    std::cout << "|  5. Return to The Northern Pine Forest Menu" << std::endl;
    std::cout << "|--------------------------------------------|" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: eastLakeMenu
 * Description: This function displays the East Lake menu choices for
 *  the user.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displayed to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void eastLakeMenu()
{
    std::cout << "|  1. Go fishing" << std::endl;
    std::cout << "|  2. Gather supplies" << std::endl;
    std::cout << "|  3. Check supplies" << std::endl;
    std::cout << "|  4. Take photo" << std::endl;
    std::cout << "|  5. Splash in the water" << std::endl;
    std::cout << "|  6. Go to map" << std::endl;
    std::cout << "|--------------------------------------------|" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: eLakeMap
 * Description: This function displays East Lake Map choices for the user.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displayed to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void eLakeMap()
{
    std::cout << "|--------------------------------------------|" << std::endl;
    std::cout << "|  Choose a direction to go:                 |" << std::endl;
    std::cout << "|  1. North to The Northern Pine Forest" << std::endl;
    std::cout << "|  2. West to Field Camp" << std::endl;
    std::cout << "|  3. South to Cougar Mtn. Forest" << std::endl;
    std::cout << "|  4. Follow a stream to Granite Lake" << std::endl;
    std::cout << "|  5. Return to Granite Lake Menu" << std::endl;
    std::cout << "|--------------------------------------------|" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: southForestMenu
 * Description: This function displays the South Forest menu choices
 *  for the user.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displayed to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void southForestMenu()
{
    std::cout << "|  1. Gather wood" << std::endl;
    std::cout << "|  2. Go hunting" << std::endl;
    std::cout << "|  3. Check supplies" << std::endl;
    std::cout << "|  4. Take photo" << std::endl;
    std::cout << "|  5. Drink some water" << std::endl;
    std::cout << "|  6. Go to map" << std::endl;
    std::cout << "|--------------------------------------------|" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: sForestMap
 * Description: This function displays Southern Forest map for the user.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displayed to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void sForestMap()
{
    std::cout << "|--------------------------------------------|" << std::endl;
    std::cout << "|  Choose a direction to go:                 |" << std::endl;
    std::cout << "|  1. North to Field Camp" << std::endl;
    std::cout << "|  2. East to Granite Lake" << std::endl;
    std::cout << "|  3. West to Beaver Dam Lake" << std::endl;
    std::cout << "|  4. Zipline ot The Northern Pine Forest" << std::endl;
    std::cout << "|  5. Return to Cougar Mtn. Forest Menu" << std::endl;
    std::cout << "|--------------------------------------------|" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: westLakeMenu
 * Description: This function displays the West Lake menu choices for
 *  the user.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displayed to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void westLakeMenu()
{
    std::cout << "|  1. Go fishing" << std::endl;
    std::cout << "|  2. Gather supplies" << std::endl;
    std::cout << "|  3. Check supplies" << std::endl;
    std::cout << "|  4. Take photo" << std::endl;
    std::cout << "|  5. Skip a rock" << std::endl;
    std::cout << "|  6. Go to map" << std::endl;
    std::cout << "|--------------------------------------------|" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: wLakeMap
 * Description: This function displays the West Lake Map choices for
 *  the user.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: displayed to user
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void wLakeMap()
{
    std::cout << "|--------------------------------------------|" << std::endl;
    std::cout << "|  Choose a direction to go:                 |" << std::endl;
    std::cout << "|  1. North to The Northern Pine Forest" << std::endl;
    std::cout << "|  2. East to Field Camp" << std::endl;
    std::cout << "|  3. South to Cougar Mtn. Forest" << std::endl;
    std::cout << "|  4. Follow a stream to Granite Lake" << std::endl;
    std::cout << "|  5. Return to Beaver Dam Lake Menu" << std::endl;
    std::cout << "|--------------------------------------------|" << std::endl;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: mapChoice
 * Description: This function accepts the choice made by the user. It
 *  then validates this input and sends it to Game.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: accepts and validates user input, sends to Game
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int mapChoice()
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

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: regionChoice
 * Description: This function accepts the choice made by the user. It
 *  then validates this input and sends it to Game.
 * Parameters: none
 * Pre-Conditions: called from Game
 * Post-Conditions: accepts and validates user input, sends to Game
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int regionChoice()
{
    int choice;
    
    std::cin >> choice;
    
    /* will validate user input expecting ints from 1-6 */
    while(choice < 1 || choice > 6)
    {
        std::cout << "Not a valid choice. Please enter 1, 2, 3, 4, 5 or 6" << std::endl;
        std::cin.ignore();
        std::cin >> choice;
    }
    
    return choice;
}

