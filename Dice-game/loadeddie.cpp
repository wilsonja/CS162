/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * Program Filename: Lab3
 * * Author: Jacob Wilson
 * * Date: 1/23/16
 * * Description: This program creates a dice version of the game war.
 * *  A single user provides details for a two-person game. Options
 * *  for die type and size are available. After running for the user-
 * *  specified number of rounds, a winner is declared.
 * * Input: die type and size, number of rounds
 * * Output: winner of game, final score, die type and size used
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <cstdlib>
#include <ctime>
#include "loadeddie.hpp"

/* DEFAULT CONSTRUCTOR same as the Die class default */
LoadedDie::LoadedDie() : Die()
{
    this->p1sides = 0;
    this->p2sides = 0;
}

/* SET sides for p1 */
void LoadedDie::setp1sides(int p1sides)
{   this->p1sides = p1sides;    }

/* GET sides for p1 */
int LoadedDie::getp1sides()
{   return p1sides;   }

/* SET sides for p2 */
void LoadedDie::setp2sides(int p2sides)
{   this->p2sides = p2sides;    }

/* GET sides for p2 */
int LoadedDie::getp2sides()
{   return p2sides;   }

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: roll (loaded die)
 * Description: This function takes in the number of sides chosed by
 *  the user and performs a simulated dice roll. A random number is
 *  used to determine the result of the roll. This function is a
 *  modification from the regular die roll, in that it only returns
 *  the top 50% of number available from the die size.
 * Parameters: integer representing number of sides
 * Pre-Conditions: pass an int from the Game class
 * Post-Conditions: return an int
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int LoadedDie::roll(int numSides)
{
    return ((rand() % (numSides / 2)) + (numSides / 2) + 1);
}
