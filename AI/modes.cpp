#include "modes.hpp"



Mode::Mode()
{

}





AttackMode::AttackMode() : Mode()
{

}

/**
    void AttackMode::calculateVelocities(void)

    to do

    @author Lucca Rawlyk
    @version 2017.10.25-1
*/

void AttackMode::calculateVelocities(Strategy* strat)
{

}

bool AttackMode::inProgress(Strategy* strat)
{

}





DefendMode::DefendMode() : Mode()
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

}





InterruptMode::InterruptMode() : Mode()
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

}





FreeBallMode::FreeBallMode() : Mode()
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

}
