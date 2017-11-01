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
    std::pair<double,double> goalkeeper_destination = findGoalkeeperDestination(strat);
    std::pair<double,double> defender_destination = findDefenderDestination(strat);
}

/**
    std::pair<double,double> AttackMode::findGoalkeeperDestination(Strategy *strat)

    Calculates the goalkeeper destination as: the middle of the goalkeeper area
    if the goalkeeper is outside of that area, or else the current goalkeeper
    position if the ball is on the other side of the field, or else ajusts it
    to the balls y.

    @author Lucca Rawlyk
    @version 2017.11.01-1
*/

std::pair<double,double> AttackMode::findGoalkeeperDestination(Strategy* strat)
{
    std::pair<double,double> goalkeeper_destination;
    field seen_field = strat.getLastSeenField();

    double gk_outer_x_offset = GOAL_X + OFFSET_X;
    double gk_inner_x_offset = GOAL_X + GOALKEEPER_AREA_X + OFFSET_X;
    double gk_y_offset = GOAL_Y/2.0;

    if(SIDE == LEFT)
    {
        //if goalkeeper is out of the goalkeeper area in the x axis
        if(seen_field.robot[GOALKEEPER].x < gk_outer_x_offset ||
           seen_field.robot[GOALKEEPER].x > gk_inner_x_offset ||
        //or goalkeeper is out of the goalkeeper area in the y axis
           seen_field.robot[GOALKEEPER].y > (seen_field.image_height/2.0) + gk_y_offset ||
           seen_field.robot[GOALKEEPER].y < (seen_field.image_height/2.0) - gk_y_offset)
        {
            //sets destination as the middle of the goalkeeper area
            //to be changed to the minimum distance to the area at some point
            goalkeeper_destination.first = seen_field.image_width - GOAL_X - OFFSET_X
                                           - (GOALKEEPER_AREA_X/2);
            goalkeeper_destination.second = seen_field.image_height/2;
        }
        else
        {
            //goalkeeper goes in position to intercept the ball
            if(seen_field.ball.x < seen_field.image_width/2.0)
            {
                goalkeeper_destination.first = seen_field.image_width - GOAL_X - OFFSET_X
                                               - (GOALKEEPER_AREA_X/2);
                goalkeeper_destination.second = seen_field.ball.y;
            }
            else
            {
                goalkeeper_destination.first = seen_field.robot[GOALKEEPER].x;
                goalkeeper_destination.second = seen_field.robot[GOALKEEPER].y;
            }
        }
    }
    else //if(SIDE == RIGHT)
    {
        //if goalkeeper is out of the goalkeeper area in the x axis
        if(seen_field.robot[GOALKEEPER].x < seen_field.image_width - gk_outer_x_offset ||
           seen_field.robot[GOALKEEPER].x > seen_field.image_width - gk_inner_x_offset ||
        //or goalkeeper is out of the goalkeeper area in the y axis
           seen_field.robot[GOALKEEPER].y > (seen_field.image_height/2.0) + gk_y_offset ||
           seen_field.robot[GOALKEEPER].y < (seen_field.image_height/2.0) - gk_y_offset)
        {
            //sets destination as the middle of the goalkeeper area
            //to be changed to the minimum distance to the area at some point
            goalkeeper_destination.first = GOAL_X + (GOALKEEPER_AREA_X/2) + OFFSET_X;
            goalkeeper_destination.second = seen_field.image_height/2;
        }
        else
        {
            //goalkeeper goes in position to intercept the ball
            if(seen_field.ball.x < seen_field.image_width/2.0)
            {
                goalkeeper_destination.first = GOAL_X + (GOALKEEPER_AREA_X/2) + OFFSET_X;
                goalkeeper_destination.second = seen_field.ball.y;
            }
            else
            {
                goalkeeper_destination.first = seen_field.robot[GOALKEEPER].x;
                goalkeeper_destination.second = seen_field.robot[GOALKEEPER].y;
            }
        }
    }

    return goalkeeper_destination;
}

/**
    std::pair<double,double> AttackMode::findDefenderDestination(Strategy *strat)

    to do

    @author Lucca Rawlyk
    @version 2017.11.01-1
*/

std::pair<double,double> AttackMode::findDefenderDestination(Strategy* strat)
{
    std::pair<double,double> defender_destination;
    field seen_field = strat.getLastSeenField();

    double gk_outer_x_offset = GOAL_X + OFFSET_X;
    double gk_inner_x_offset = GOAL_X + GOALKEEPER_AREA_X + OFFSET_X;
    double gk_y_offset = GOAL_Y/2.0;

    if(SIDE == LEFT)
    {
        //if goalkeeper is out of the goalkeeper area in the x axis
        if(seen_field.robot[GOALKEEPER].x < gk_outer_x_offset ||
           seen_field.robot[GOALKEEPER].x > gk_inner_x_offset ||
        //or goalkeeper is out of the goalkeeper area in the y axis
           seen_field.robot[GOALKEEPER].y > (seen_field.image_height/2.0) + gk_y_offset ||
           seen_field.robot[GOALKEEPER].y < (seen_field.image_height/2.0) - gk_y_offset)
        {
            //sets destination as the middle of the goalkeeper area
            //to be changed to the minimum distance to the area at some point
            goalkeeper_destination.first = seen_field.image_width - GOAL_X - OFFSET_X
                                           - (GOALKEEPER_AREA_X/2);
            goalkeeper_destination.second = seen_field.image_height/2;
        }
        else
        {
            //goalkeeper goes in position to intercept the ball
            if(seen_field.ball.x < seen_field.image_width/2.0)
            {
                goalkeeper_destination.first = seen_field.image_width - GOAL_X - OFFSET_X
                                               - (GOALKEEPER_AREA_X/2);
                goalkeeper_destination.second = seen_field.ball.y;
            }
            else
            {
                goalkeeper_destination.first = seen_field.robot[GOALKEEPER].x;
                goalkeeper_destination.second = seen_field.robot[GOALKEEPER].y;
            }
        }
    }
    else //if(SIDE == RIGHT)
    {
        //if goalkeeper is out of the goalkeeper area in the x axis
        if(seen_field.robot[GOALKEEPER].x < seen_field.image_width - gk_outer_x_offset ||
           seen_field.robot[GOALKEEPER].x > seen_field.image_width - gk_inner_x_offset ||
        //or goalkeeper is out of the goalkeeper area in the y axis
           seen_field.robot[GOALKEEPER].y > (seen_field.image_height/2.0) + gk_y_offset ||
           seen_field.robot[GOALKEEPER].y < (seen_field.image_height/2.0) - gk_y_offset)
        {
            //sets destination as the middle of the goalkeeper area
            //to be changed to the minimum distance to the area at some point
            goalkeeper_destination.first = GOAL_X + (GOALKEEPER_AREA_X/2) + OFFSET_X;
            goalkeeper_destination.second = seen_field.image_height/2;
        }
        else
        {
            //goalkeeper goes in position to intercept the ball
            if(seen_field.ball.x < seen_field.image_width/2.0)
            {
                goalkeeper_destination.first = GOAL_X + (GOALKEEPER_AREA_X/2) + OFFSET_X;
                goalkeeper_destination.second = seen_field.ball.y;
            }
            else
            {
                goalkeeper_destination.first = seen_field.robot[GOALKEEPER].x;
                goalkeeper_destination.second = seen_field.robot[GOALKEEPER].y;
            }
        }
    }

    return goalkeeper_destination;
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
