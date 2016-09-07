/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * Program Filename: assignment1
 * * Author: Jacob Wilson
 * * Date: 1/17/16
 * * Description: This program is a version of Conway's Game of Life.
 * *  The user chooses a starting position and a gamepiece, then the
 * *  simulation proceeds according to established rules.
 * * Input: starting points and user chosen gamepiece
 * * Output: grids showing gamepiece movement
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

/* list of prototypes for all functions */

void startGrid(int (*array)[120]);
void drawGamePiece(int (*tmpltArray)[120], int x, int y, int z);
void neighborCheck(int (*tmpltArray)[120], int (*wrkngArray)[120]);
void copyGrid(int (*tmpltArray)[120], int (*wrkngArray)[120]);
void displayGrid(int (*wrkngArray)[120]);

#endif
