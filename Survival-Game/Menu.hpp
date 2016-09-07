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

#ifndef MENU_HPP
#define MENU_HPP

/* prototypes for various menus */
void mainMenu();
void campMenu();
void northForestMenu();
void eastLakeMenu();
void southForestMenu();
void westLakeMenu();

/* prototypes for map displays */
void campMap();
void nForestMap();
void eLakeMap();
void sForestMap();
void wLakeMap();

/* prototypes for obtaining choices */
int getChoice();
int campChoice();
int regionChoice();
int mapChoice();

#endif
