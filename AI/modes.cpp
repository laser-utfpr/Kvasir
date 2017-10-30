#include "modes.hpp"



Mode::Mode()
{

}

Mode::~Mode()
{

}





AttackMode::AttackMode() : Mode()
{

}

AttackMode::~AttackMode()
{

}

/**
    void AttackMode::calculateVelocities(void)

    to do

    @author Lucca Rawlyk
    @version 2017.10.29-1
*/

void AttackMode::calculateVelocities(Strategy* strat)
{
    entity goalkeeper_destination;
    field seen_field = strat.getLastSeenField();
    if(SIDE == LEFT)
    {
        //if goalkeeper is out of the goalkeeper area in the x axis
        if(seen_field.robot[GOALKEEPER].x > seen_field.image_width - GOAL_X ||
           seen_field.robot[GOALKEEPER].x < seen_field.image_width - (GOAL_X + GOALKEEPER_AREA_X) ||
        //or goalkeeper is out of the goalkeeper area in the y axis
           seen_field.robot[GOALKEEPER].y > (seen_field.image_width/2.0) + (GOAL_Y/2.0) ||
           seen_field.robot[GOALKEEPER].y < (seen_field.image_width/2.0) - (GOAL_Y/2.0))
        {
            //goalkeeper goes to the goalkeeper area
        }
        else
        {
            //goalkeeper goes in position to intercept the ball
        }
    }
    else //if(SIDE == RIGHT)
}

bool AttackMode::inProgress(Strategy* strat)
{
    //AttackMode is not sequencial
    return false;
}





DefendMode::DefendMode() : Mode()
{

}

DefendMode::~DefendMode()
{

}

/**
    void DefendMode::calculateVelocities(void)

    to do

    @author Lucca Rawlyk
    @version 2017.10.25-1
*/

void DefendMode::calculateVelocities(Strategy* strat)
{

}

bool DefendMode::inProgress(Strategy* strat)
{
    //AttackMode is not sequencial
    return false;
}





InterruptMode::InterruptMode() : Mode()
{

}

InterruptMode::~InterruptMode()
{

}

/**
    void InterruptMode::calculateVelocities(void)

    Sets all velocities to zero.

    @author Lucca Rawlyk
    @version 2017.10.25-1
*/

void InterruptMode::calculateVelocities(Strategy* strat)
{
    int i;
    for(i=0; i<N_PLAYERS; i++)
    {
        strat->setDesiredXVel(i,0.0);
        strat->setDesiredYVel(i,0.0);
        strat->setDesiredAngVel(i,0.0);
    }
}

bool InterruptMode::inProgress(Strategy* strat)
{
    if(_kbhit())
    {
        char key = std::cin.get();
        if(key == 'r')
            return false;
        else
            return true;
    }
    else
        return true;
}





FreeBallMode::FreeBallMode() : Mode()
{

}

FreeBallMode::~FreeBallMode()
{

}

/**
    void FreeBallMode::calculateVelocities(void)

    to do

    @author Lucca Rawlyk
    @version 2017.10.25-1
*/

void FreeBallMode::calculateVelocities(Strategy* strat)
{

}

bool FreeBallMode::inProgress(Strategy* strat)
{
    //if(done)
        //return false;
    //else
        //return true;
}
