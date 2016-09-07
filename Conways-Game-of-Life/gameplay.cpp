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

#include "gameplay.hpp"
#include <iostream>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: startGrid
 * Description: This function takes in a 2-d array from the main
 *  function and fills all cells with 0 representing a grid of all dead
 *  cells in the simulation.
 * Parameters: pointer to a 2-d array of integers
 * Pre-Conditions: pass a 2-d array from main
 * Post-Conditions: values representing dead cells entered into array
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void startGrid(int (*tmpltArray)[120])
{
    int row, col, dead = 0;
    
    for(row = 0; row < 60; row++)
    {
        for(col = 0; col < 120; col++)
        {
            tmpltArray[row][col] = dead;    /* set all array locations to zero */
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: drawGamePiece
 * Description: The function takes in an array of all dead cells and
 *  adds 1 to the array positions according to the start positions
 *  and gamepiece defined by the user. These 1 added to the array
 *  position represent live cells and will be used for the rest
 *  of the simluation.
 * Parameters: pointer to a 2-d array of integers, integer representing
 *  user-defined x-coordinate, integer representing user-defined y-
 *  coordinate, and integer represeting user-defined gamepiece
 *  selection.
 * Pre-Conditions: pass a 2-d array and 3 integers from main
 * Post-Conditions: values in the array are changed to 1 representing
 *  living cells, drawn according to the chosen gamepiece shape.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void drawGamePiece(int (*tmpltArray)[120], int x, int y, int z)
{
    int alive = 1;
    
    /* based on the user choice, each gamepiece will be drawn differently */
    
    /* draw the oscillator */
    if(z == 1)
    {
        tmpltArray[x][y] = alive;
        tmpltArray[x + 1][y] = alive;
        tmpltArray[x - 1][y] = alive;
    }
    /* draw the glider */
    else if(z == 2)
    {
        tmpltArray[x - 1][y] = alive;
        tmpltArray[x][y + 1] = alive;
        tmpltArray[x + 1][y - 1] = alive;
        tmpltArray[x + 1][y] = alive;
        tmpltArray[x + 1][y + 1] = alive;
    }
    /* draw the glider cannon */
    else if(z == 3)
    {
        tmpltArray[x][y] = alive;
        tmpltArray[x - 1][y] = alive;
        tmpltArray[x + 1][y] = alive;
        tmpltArray[x][y + 1] = alive;
        tmpltArray[x - 2][y - 1] = alive;
        tmpltArray[x + 2][y - 1] = alive;
        tmpltArray[x][y - 2] = alive;
        tmpltArray[x - 3][y - 3] = alive;
        tmpltArray[x + 3][y - 3] = alive;
        tmpltArray[x - 3][y - 4] = alive;
        tmpltArray[x + 3][y - 4] = alive;
        tmpltArray[x - 2][y - 5] = alive;
        tmpltArray[x + 2][y - 5] = alive;
        tmpltArray[x - 1][y - 6] = alive;
        tmpltArray[x + 1][y - 6] = alive;
        tmpltArray[x][y - 6] = alive;
        tmpltArray[x - 1][y - 15] = alive;
        tmpltArray[x - 1][y - 16] = alive;
        tmpltArray[x][y - 15] = alive;
        tmpltArray[x][y - 16] = alive;
        tmpltArray[x - 1][y + 4] = alive;
        tmpltArray[x - 1][y + 5] = alive;
        tmpltArray[x - 2][y + 4] = alive;
        tmpltArray[x - 2][y + 5] = alive;
        tmpltArray[x - 3][y + 4] = alive;
        tmpltArray[x - 3][y + 5] = alive;
        tmpltArray[x][y + 6] = alive;
        tmpltArray[x - 4][y + 6] = alive;
        tmpltArray[x][y + 8] = alive;
        tmpltArray[x + 1][y + 8] = alive;
        tmpltArray[x - 4][y + 8] = alive;
        tmpltArray[x - 5][y + 8] = alive;
        tmpltArray[x - 2][y + 18] = alive;
        tmpltArray[x - 2][y + 19] = alive;
        tmpltArray[x - 3][y + 18] = alive;
        tmpltArray[x - 3][y + 19] = alive;
    }

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: neighborCheck
 * Description: The function uses two 2-d arrays. It checks the position
 *  of the first array, applies tests, and then updates the values at
 *  the same position of the second array depending on the test outcome.
 *  The end result is an array showing conditions before the
 *  tests, and an array showing the conditions after all tests have
 *  been performed.
 * Parameters: pointers to two 2-d arrays
 * Pre-Conditions: pass two 2-d array from main
 * Post-Conditions: values are checked in the tmpltArray and changed
 *  in the wrkngArray according to the rules listed below
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void neighborCheck(int (*tmpltArray)[120], int (*wrkngArray)[120])
{
    int row, col, dead = 0, alive = 1;
    
    for(row = 0; row < 60; row++)
    {
        for(col = 0; col < 120; col++)
        {
            int neighbor = 0;
            
            /* check each neighboring cell around a target cell */
            if(tmpltArray[row - 1][col] == alive)
                neighbor += 1;
            if(tmpltArray[row + 1][col] == alive)
                neighbor += 1;
            if(tmpltArray[row][col - 1] == alive)
                neighbor += 1;
            if(tmpltArray[row][col + 1] == alive)
                neighbor += 1;
            if(tmpltArray[row + 1][col + 1] == alive)
                neighbor += 1;
            if(tmpltArray[row - 1][col - 1] == alive)
                neighbor += 1;
            if(tmpltArray[row + 1][col - 1] == alive)
                neighbor += 1;
            if(tmpltArray[row - 1][col + 1] == alive)
                neighbor += 1;
            
            /* apply action to target cell depending on pre-defined rules */
            if(tmpltArray[row][col] == alive && (neighbor < 2 || neighbor > 3))
                wrkngArray[row][col] = dead;
            if(tmpltArray[row][col] == alive && (neighbor == 2 || neighbor == 3))
                wrkngArray[row][col] = alive;
            if(tmpltArray[row][col] == dead && (neighbor == 3))
                wrkngArray[row][col] = alive;
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: copyGrid
 * Description: The function loops through two 2-d array copying the
 *  values from one into the other.
 * Parameters: two pointers to two 2-d arrays
 * Pre-Conditions: pass two 2-d arrays from main
 * Post-Conditions: values are entered copied from one array to the other
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void copyGrid(int (*tmpltArray)[120], int (*wrkngArray)[120])
{
    int row, col;
    
    for(row = 0; row < 60; row++)
    {
        for(col = 0; col < 120; col++)
        {
            wrkngArray[row][col] = tmpltArray[row][col];
        }
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: displayGrid
 * Description: The function utilizes a 2-d array passed from main and
 *  outputs the values to the console to be viewed by the user.
 * Parameters: pointer to a 2-d array of integers
 * Pre-Conditions: pass a 2-d array from main
 * Post-Conditions: values of the array are outputted to console
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void displayGrid(int (*wrkngArray)[120])
{
    int row, col;
    
    for(row = 21; row < 41; row++)
    {
        for(col = 41; col < 81; col++)
        {
            if(wrkngArray[row][col] == 1)
               std::cout << "O" << " ";         /* draw 0 to represent living cells */
            else if(wrkngArray[row][col] == 0)
                std::cout << "." << " ";        /* draw period to represent dead cells */
        }
        std::cout << std::endl;
    }
}
