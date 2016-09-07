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
#include "die.hpp"

/* DEFAULT CONSTRUCTOR sets die sides for both players to 0 */
Die::Die()
{
    this->p1sides = 0;
    this->p2sides = 0;
}

/* SET sides for p1 */
void Die::setp1sides(int p1sides)
{   this->p1sides = p1sides;    }

/* GET sides for p1 */
int Die::getp1sides()
{   return p1sides;   }

/* SET sides for p2 */
void Die::setp2sides(int p2sides)
{   this->p2sides = p2sides;    }

/* GET sides for p2 */
int Die::getp2sides()
{   return p2sides;   }

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Function: roll (regular die)
 * Description: This function takes in the number of sides chosed by
 *  the user and performs a simulated dice roll. A random number is
 *  used to determine the result of the roll.
 * Parameters: integer representing number of sides
 * Pre-Conditions: pass an int from the Game class
 * Post-Conditions: return an int
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Die::roll(int numSides)
{
    return (rand() % numSides) + 1;
}
