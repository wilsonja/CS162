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

#include <iostream>
#include <stdlib.h>     /* added for usleep function */
#include "gameplay.hpp"

int main()
{
    /* the array is larger than what is displayed to create the illusion
     * of an infinite grid */
    const int NUM_ROWS = 60,
              NUM_COLS = 120;
    int tmpltGrid[NUM_ROWS][NUM_COLS],
        wrkngGrid[NUM_ROWS][NUM_COLS];
    int startRow,
        startCol,
        gamePiece;
    bool cont = false;
    
    /* Introduce the simulation to the user and gather input. This information will be used by the drawGamePiece
     * method to produce an array that will be used in the simulation.*/
    
    std::cout << "Welcome to Conway's Game of Life. At any time press ctrl-c to quite the simulation." << std::endl;
    std::cout << "Start by choosing a starting position, this will be the center point of your gamepiece." << std::endl;
    std::cout << "Please choose a starting x-coordinate between 1 and 40." << std::endl;    /* specific range requested */
    std::cin >> startCol;
    std::cout << "Please choose a starting y-coordinate between 1 and 20." << std::endl;    /* specific range requested */
    std::cin >> startRow;
    std::cout << "Please enter the number of the game piece you would like to use:" << std::endl;
    std::cout << "\t" << "1 - oscillator" << std::endl;
    std::cout << "\t" << "2 - glider" << std::endl;
    std::cout << "\t" << "3 - glider cannon" << std::endl;
    std::cin >> gamePiece;
    
    
    /* create a blank array for both the template and working grids */
    
    startGrid(tmpltGrid);
    startGrid(wrkngGrid);
    
    /* Create a template grid with the user defined gamepiece and starting position. The offset is necessary due
     * to the large overall array vs. smaller visible array. */
    
    drawGamePiece(tmpltGrid, startRow + 20, startCol + 40, gamePiece);
    
    displayGrid(tmpltGrid);
    
    /* a loop will perform the simulation until the user enters ctrl-c to quit */
    
    while (!cont)
    {   neighborCheck(tmpltGrid, wrkngGrid);
        displayGrid(wrkngGrid);
        copyGrid(wrkngGrid, tmpltGrid);
        usleep(2000 * 10);  /* used to create a small delay */
    }
    return 0;
}
