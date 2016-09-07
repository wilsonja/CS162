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

#include <string>
#include "Menu.hpp"
#ifndef CREATURE_HPP
#define CREATURE_HPP

/* Creature class is parent class */
class Creature
{
private:
    
protected:
    int strength,
        armor,
        type;
    std::string name,
                user_name,
                team_name;
public:
    /* CONSTRUCTOR/DESCTRUCTOR */
    Creature();
    virtual ~Creature();
    
    /* VIRTUAL functions */
    virtual int attack() = 0;
    virtual int defense() = 0;
    virtual void regen() = 0;
    
    /* SET functions */
    void set_strength(int);
    void set_user_name(std::string);
    void set_team_name(std::string);
    
    /* GET functions */
    int get_strength();
    int get_armor();
    std::string get_name();
    std::string get_user_name();
    int get_type();
    std::string get_team_name();
};

#endif
