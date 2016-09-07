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

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.hpp"

int main()
{
    int rounds,
        p1die,
        p2die,
        p1sides,
        p2sides;
    bool p1 = true,
         p2 = true;
    srand( (unsigned int) time(NULL));

    /* gather data from the user */
    std::cout << "Please enter the number of rounds." << std::endl;
    std::cin >> rounds;
    
    std::cout << "Please choose a die type for player 1:" << std::endl;
    std::cout << "\t" << "Enter 1 for Regular Die" << std::endl;
    std::cout << "\t" << "Enter 2 for Loaded Die" << std::endl;
    std::cin >> p1die;
    
    std::cout << "Please choose the number of sides for player 1:" << std::endl;
    std::cout << "Enter either 4, 6, or 10." << std::endl;
    std::cin >> p1sides;
    
    std::cout << "Please choose a die type for player 2:" << std::endl;
    std::cout << "\t" << "Enter 1 for Regular Die" << std::endl;
    std::cout << "\t" << "Enter 2 for Loaded Die" << std::endl;
    std::cin >> p2die;
    
    std::cout << "Please choose the number of sides for player 1:" << std::endl;
    std::cout << "Enter either 4, 6, or 10." << std::endl;
    std::cin >> p2sides;
    
    
    /* A bool variable is used to determine if the user chose a
     * regular die or loaded die. If the user chooses a loaded
     * die (enters a 2), the bool is sent to the Game object as
     * false, where it is recognized as a loaded die. */
    if(p1die == 2)
    {
        p1 = false;
    }
    
    if(p2die == 2)
    {
        p2 = false;
    }
    
    //std::cout << p1 << " " << p2 << std::endl;
    
    /* create the Game object passing the user-defined data */
    Game war(rounds, p1, p1sides, p2, p2sides);
    
    return 0;
}
