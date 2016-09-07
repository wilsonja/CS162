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

#include "Vampire.hpp"
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

/* BlueMen class is a child of Creature */
class BlueMen : public Creature
{
private:
    
protected:
    
public:
    /* CONSTRUCTOR */
    BlueMen();
    
    /* MEMBER functions */
    int attack();
    int defense();
    void regen();
    
    /* SET functions */
    void set_strength(int);
    void set_user_name(std::string);
    void set_team_name(std::string);
    
    /* GET functions */
    int get_strength();
    int get_armor();
    std::string get_name();
    std::string get_user_name();
    std::string get_team_name();
    int get_type();
};

#endif
