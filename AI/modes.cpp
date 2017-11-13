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
    std::pair<double,double> attacker_destination = findAttackerDestination(strat);

    field seen_field = strat->getLastSeenField();

    int i, goalkeeper, defender, attacker;

    for(i=0; i<N_PLAYERS; i++)
    {
        if(strat->getRole(i) == GOALKEEPER)
        {
            goalkeeper = i;
            break;
        }
    }
    //std::cout << std::endl << "goalkeeper = " << goalkeeper << std::endl;
    //std::cout << std::endl << "goalkeeper dest = " << goalkeeper_destination.first << ',' << goalkeeper_destination.second << std::endl;
    velocity goalkeeper_vel = calculateVelocity(seen_field.robot[goalkeeper],goalkeeper_destination);

    for(i=0; i<N_PLAYERS; i++)
    {
        if(strat->getRole(i) == DEFENDER)
        {
            defender = i;
            break;
        }
    }
    //std::cout << std::endl << "defender = " << defender << std::endl;
    //std::cout << std::endl << "defender dest = " << defender_destination.first << ',' << defender_destination.second << std::endl;
    velocity defender_vel = calculateVelocity(seen_field.robot[defender],defender_destination);

    for(i=0; i<N_PLAYERS; i++)
    {
        if(strat->getRole(i) == ATTACKER)
        {
            attacker = i;
            break;
        }
    }

    //std::cout << std::endl << "attacker = " << attacker << std::endl;
    //std::cout << std::endl << "attacker dest = " << attacker_destination.first << ',' << attacker_destination.second << std::endl;
    velocity attacker_vel = calculateVelocity(seen_field.robot[attacker],attacker_destination);

    /*entity lol;
    std::pair<double,double> lul(seen_field.ball.x,seen_field.ball.y);
    lol.found = true;
    lol.x = 600.0;
    lol.y = 600.0;
    lol.angle = 0.0;
    velocity attacker_vel = calculateVelocity(lol,lul);*/

    strat->setDesiredXVel(goalkeeper,goalkeeper_vel.x);
    strat->setDesiredYVel(goalkeeper,goalkeeper_vel.y);
    strat->setDesiredAngVel(goalkeeper,goalkeeper_vel.ang);

    strat->setDesiredXVel(defender,defender_vel.x);
    strat->setDesiredYVel(defender,defender_vel.y);
    strat->setDesiredAngVel(defender,defender_vel.ang);

    strat->setDesiredXVel(attacker,attacker_vel.x);
    strat->setDesiredYVel(attacker,attacker_vel.y);
    strat->setDesiredAngVel(attacker,attacker_vel.ang);
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
    field seen_field = strat->getLastSeenField();

    double gk_outer_x_offset = GOAL_X + OFFSET_X;
    double gk_inner_x_offset = GOAL_X + GOALKEEPER_AREA_X + OFFSET_X;
    double gk_y_offset = GOAL_Y/2.0;

    //finds the goalkeeper, assumes that there is one and only one
    int i, goalkeeper;
    for(i=0; i<N_PLAYERS; i++)
    {
        if(strat->getRole(i) == GOALKEEPER)
        {
            goalkeeper = i;
            break;
        }
    }
    if(seen_field.robot[goalkeeper].found && seen_field.ball.found)
    {
        if(SIDE == LEFT)
        {
            //if goalkeeper is out of the goalkeeper area in the x axis
            if(seen_field.robot[goalkeeper].x < gk_outer_x_offset ||
               seen_field.robot[goalkeeper].x > gk_inner_x_offset ||
            //or goalkeeper is out of the goalkeeper area in the y axis
               seen_field.robot[goalkeeper].y > (seen_field.image_height/2.0) + gk_y_offset ||
               seen_field.robot[goalkeeper].y < (seen_field.image_height/2.0) - gk_y_offset)
            {
                //sets destination as the middle of the goalkeeper area
                //to be changed to the minimum distance to the area at some point
                goalkeeper_destination.first = seen_field.image_width - GOAL_X - OFFSET_X
                                               - (GOALKEEPER_AREA_X/2.0);
                goalkeeper_destination.second = seen_field.image_height/2.0;
            }
            else
            {
                //goalkeeper goes in position to intercept the ball
                if(seen_field.ball.x < seen_field.image_width/2.0)
                {
                    goalkeeper_destination.first = seen_field.image_width - GOAL_X - OFFSET_X
                                                   - (GOALKEEPER_AREA_X/2.0);
                    goalkeeper_destination.second = seen_field.ball.y;
                }
                else
                {
                    goalkeeper_destination.first = seen_field.robot[goalkeeper].x;
                    goalkeeper_destination.second = seen_field.robot[goalkeeper].y;
                }
            }
        }
        else //if(SIDE == RIGHT)
        {
            //if goalkeeper is out of the goalkeeper area in the x axis
            if(seen_field.robot[goalkeeper].x < seen_field.image_width - gk_outer_x_offset ||
               seen_field.robot[goalkeeper].x > seen_field.image_width - gk_inner_x_offset ||
            //or goalkeeper is out of the goalkeeper area in the y axis
               seen_field.robot[goalkeeper].y > (seen_field.image_height/2.0) + gk_y_offset ||
               seen_field.robot[goalkeeper].y < (seen_field.image_height/2.0) - gk_y_offset)
            {
                //sets destination as the middle of the goalkeeper area
                //to be changed to the minimum distance to the area at some point
                goalkeeper_destination.first = GOAL_X + (GOALKEEPER_AREA_X/2.0) + OFFSET_X;
                goalkeeper_destination.second = seen_field.image_height/2.0;
            }
            else
            {
                //goalkeeper goes in position to intercept the ball
                if(seen_field.ball.x < seen_field.image_width/2.0)
                {
                    goalkeeper_destination.first = GOAL_X + (GOALKEEPER_AREA_X/2.0) + OFFSET_X;
                    goalkeeper_destination.second = seen_field.ball.y;
                }
                else
                {
                    goalkeeper_destination.first = seen_field.robot[goalkeeper].x;
                    goalkeeper_destination.second = seen_field.robot[goalkeeper].y;
                }
            }
        }
    }
    else
    {
        goalkeeper_destination.first = -1.0;
        goalkeeper_destination.second = -1.0;
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
    field seen_field = strat->getLastSeenField();

    //finds the defender, assumes that there is one and only one
    int i, defender;
    for(i=0; i<N_PLAYERS; i++)
    {
        if(strat->getRole(i) == DEFENDER)
        {
            defender = i;
            break;
        }
    }

    if(seen_field.robot[defender].found && seen_field.ball.found)
    {
        if(SIDE == LEFT)
        {
            //if the ball is in the enemy´s side
            if(seen_field.ball.x > seen_field.image_width/2.0)
            {
                //the defender moves in the y axis
                defender_destination.first = seen_field.robot[defender].x;
                defender_destination.second = adjustYToLineSeg(seen_field.robot[defender].x,
                                              seen_field.ball.x, seen_field.ball.y,
                                              seen_field.image_width - OFFSET_X - GOAL_X, seen_field.image_height/2.0);
            }
            else
            {
                //destination is the midpoint between the ball and the goal
                defender_destination.first = (seen_field.robot[defender].x - (seen_field.image_width - OFFSET_X - GOAL_X))/2.0;
                defender_destination.second = (seen_field.robot[defender].y - seen_field.image_height/2.0)/2.0;
            }
        }
        else //if(SIDE == RIGHT)
        {
            //if the ball is in the enemy´s side
            if(seen_field.ball.x < seen_field.image_width/2.0)
            {
                defender_destination.first = seen_field.robot[defender].x;
                defender_destination.second = adjustYToLineSeg(seen_field.robot[defender].x,
                                              seen_field.ball.x, seen_field.ball.y,
                                              OFFSET_X + GOAL_X, seen_field.image_height/2.0);
            }
            else
            {
                //destination is the midpoint between the ball and the goal
                defender_destination.first = (seen_field.robot[defender].x - (OFFSET_X + GOAL_X))/2.0;
                defender_destination.second = (seen_field.robot[defender].y - seen_field.image_height/2.0)/2.0;
            }
        }
    }
    else
    {
        defender_destination.first = -1.0;
        defender_destination.second = -1.0;
    }

    return defender_destination;
}

/**
    std::pair<double,double> AttackMode::findAttackerDestination(Strategy *strat)

    to do

    @author Lucca Rawlyk
    @version 2017.11.01-1
*/

std::pair<double,double> AttackMode::findAttackerDestination(Strategy* strat)
{
    std::pair<double,double> attacker_destination, shooting_point;
    field seen_field = strat->getLastSeenField();

    //finds the attacker, assumes that there is one and only one
    int i, attacker;
    for(i=0; i<N_PLAYERS; i++)
    {
        if(strat->getRole(i) == ATTACKER)
        {
            attacker = i;
            break;
        }
    }

    if(seen_field.robot[attacker].found && seen_field.ball.found)
    {
        if(SIDE == LEFT)
        {
            shooting_point.first = seen_field.ball.x - SHOOTING_POINT_OFFSET_X;
            shooting_point.second = adjustYToLineSeg(shooting_point.first,
                                                     seen_field.ball.x, seen_field.ball.y,
                                                     seen_field.image_width - OFFSET_X - GOAL_X, seen_field.image_height/2.0);
        }
        else //if(SIDE == RIGHT)
        {
            shooting_point.first = seen_field.ball.x + SHOOTING_POINT_OFFSET_X;
            shooting_point.second = adjustYToLineSeg(shooting_point.first,
                                                     seen_field.ball.x, seen_field.ball.y,
                                                     OFFSET_X + GOAL_X, seen_field.image_height/2.0);
        }

        if(distance(seen_field.robot[attacker].x, seen_field.robot[attacker].y,
                    shooting_point.first, shooting_point.second) > SHOOTING_POINT_RADIUS)
        {
            attacker_destination = shooting_point;
        }
        else
        {
            attacker_destination.first = seen_field.ball.x;
            attacker_destination.second = seen_field.ball.y;
        }
    }
    else
    {
        attacker_destination.first = -1.0;
        attacker_destination.second = -1.0;
    }

    return attacker_destination;
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
    std::pair<double,double> goalkeeper_destination = findGoalkeeperDestination(strat);
    std::pair<double,double> defender_destination = findDefenderDestination(strat);
    std::pair<double,double> attacker_destination = findAttackerDestination(strat);

    field seen_field = strat->getLastSeenField();

    int i, goalkeeper, defender, attacker;

    for(i=0; i<N_PLAYERS; i++)
    {
        if(strat->getRole(i) == GOALKEEPER)
        {
            goalkeeper = i;
            break;
        }
    }
    velocity goalkeeper_vel = calculateVelocity(seen_field.robot[goalkeeper],goalkeeper_destination);

    for(i=0; i<N_PLAYERS; i++)
    {
        if(strat->getRole(i) == DEFENDER)
        {
            defender = i;
            break;
        }
    }
    velocity defender_vel = calculateVelocity(seen_field.robot[defender],defender_destination);

    for(i=0; i<N_PLAYERS; i++)
    {
        if(strat->getRole(i) == ATTACKER)
        {
            attacker = i;
            break;
        }
    }
    velocity attacker_vel = calculateVelocity(seen_field.robot[attacker],attacker_destination);

    strat->setDesiredXVel(goalkeeper,goalkeeper_vel.x);
    strat->setDesiredYVel(goalkeeper,goalkeeper_vel.y);
    strat->setDesiredAngVel(goalkeeper,goalkeeper_vel.ang);

    strat->setDesiredXVel(defender,defender_vel.x);
    strat->setDesiredYVel(defender,defender_vel.y);
    strat->setDesiredAngVel(defender,defender_vel.ang);

    strat->setDesiredXVel(attacker,attacker_vel.x);
    strat->setDesiredYVel(attacker,attacker_vel.y);
    strat->setDesiredAngVel(attacker,attacker_vel.ang);
}

/**
    std::pair<double,double> DefendMode::findGoalkeeperDestination(Strategy *strat)

    Calculates the goalkeeper destination as: the middle of the goalkeeper area
    if the goalkeeper is outside of that area, or else the current goalkeeper
    position if the ball is on the other side of the field, or else ajusts it
    to the balls y.

    @author Lucca Rawlyk
    @version 2017.11.01-1
*/

std::pair<double,double> DefendMode::findGoalkeeperDestination(Strategy* strat)
{
    std::pair<double,double> goalkeeper_destination;
    field seen_field = strat->getLastSeenField();

    double gk_outer_x_offset = GOAL_X + OFFSET_X;
    double gk_inner_x_offset = GOAL_X + GOALKEEPER_AREA_X + OFFSET_X;
    double gk_y_offset = GOAL_Y/2.0;

    //finds the goalkeeper, assumes that there is one and only one
    int i, goalkeeper;
    for(i=0; i<N_PLAYERS; i++)
    {
        if(strat->getRole(i) == GOALKEEPER)
        {
            goalkeeper = i;
            break;
        }
    }
    if(seen_field.robot[goalkeeper].found && seen_field.ball.found)
    {
        if(SIDE == LEFT)
        {
            //if goalkeeper is out of the goalkeeper area in the x axis
            if(seen_field.robot[goalkeeper].x < gk_outer_x_offset ||
               seen_field.robot[goalkeeper].x > gk_inner_x_offset ||
            //or goalkeeper is out of the goalkeeper area in the y axis
               seen_field.robot[goalkeeper].y > (seen_field.image_height/2.0) + gk_y_offset ||
               seen_field.robot[goalkeeper].y < (seen_field.image_height/2.0) - gk_y_offset)
            {
                //sets destination as the middle of the goalkeeper area
                //to be changed to the minimum distance to the area at some point
                goalkeeper_destination.first = seen_field.image_width - GOAL_X - OFFSET_X
                                               - (GOALKEEPER_AREA_X/2.0);
                goalkeeper_destination.second = seen_field.image_height/2.0;
            }
            else
            {
                //goalkeeper goes in position to intercept the ball
                if(seen_field.ball.x < seen_field.image_width/2.0)
                {
                    goalkeeper_destination.first = seen_field.image_width - GOAL_X - OFFSET_X
                                                   - (GOALKEEPER_AREA_X/2.0);
                    goalkeeper_destination.second = seen_field.ball.y;
                }
                else
                {
                    goalkeeper_destination.first = seen_field.robot[goalkeeper].x;
                    goalkeeper_destination.second = seen_field.robot[goalkeeper].y;
                }
            }
        }
        else //if(SIDE == RIGHT)
        {
            //if goalkeeper is out of the goalkeeper area in the x axis
            if(seen_field.robot[goalkeeper].x < seen_field.image_width - gk_outer_x_offset ||
               seen_field.robot[goalkeeper].x > seen_field.image_width - gk_inner_x_offset ||
            //or goalkeeper is out of the goalkeeper area in the y axis
               seen_field.robot[goalkeeper].y > (seen_field.image_height/2.0) + gk_y_offset ||
               seen_field.robot[goalkeeper].y < (seen_field.image_height/2.0) - gk_y_offset)
            {
                //sets destination as the middle of the goalkeeper area
                //to be changed to the minimum distance to the area at some point
                goalkeeper_destination.first = GOAL_X + (GOALKEEPER_AREA_X/2.0) + OFFSET_X;
                goalkeeper_destination.second = seen_field.image_height/2.0;
            }
            else
            {
                //goalkeeper goes in position to intercept the ball
                if(seen_field.ball.x < seen_field.image_width/2.0)
                {
                    goalkeeper_destination.first = GOAL_X + (GOALKEEPER_AREA_X/2.0) + OFFSET_X;
                    goalkeeper_destination.second = seen_field.ball.y;
                }
                else
                {
                    goalkeeper_destination.first = seen_field.robot[goalkeeper].x;
                    goalkeeper_destination.second = seen_field.robot[goalkeeper].y;
                }
            }
        }
    }
    else
    {
        goalkeeper_destination.first = -1.0;
        goalkeeper_destination.second = -1.0;
    }

    return goalkeeper_destination;
}

/**
    std::pair<double,double> DefendMode::findDefenderDestination(Strategy *strat)

    to do

    @author Lucca Rawlyk
    @version 2017.11.01-1
*/

std::pair<double,double> DefendMode::findDefenderDestination(Strategy* strat)
{
    std::pair<double,double> defender_destination;
    field seen_field = strat->getLastSeenField();

    //finds the defender, assumes that there is one and only one
    int i, defender;
    for(i=0; i<N_PLAYERS; i++)
    {
        if(strat->getRole(i) == DEFENDER)
        {
            defender = i;
            break;
        }
    }

    if(seen_field.robot[defender].found && seen_field.ball.found)
    {
        if(SIDE == LEFT)
        {
            //if the ball is in the enemy´s side
            if(seen_field.ball.x > seen_field.image_width/2.0)
            {
                //the defender moves in the y axis
                defender_destination.first = seen_field.robot[defender].x;
                defender_destination.second = adjustYToLineSeg(seen_field.robot[defender].x,
                                              seen_field.ball.x, seen_field.ball.y,
                                              seen_field.image_width - OFFSET_X - GOAL_X, seen_field.image_height/2.0);
            }
            else
            {
                //destination is the midpoint between the ball and the goal
                defender_destination.first = (seen_field.robot[defender].x - (seen_field.image_width - OFFSET_X - GOAL_X))/2.0;
                defender_destination.second = (seen_field.robot[defender].y - seen_field.image_height/2.0)/2.0;
            }
        }
        else //if(SIDE == RIGHT)
        {
            //if the ball is in the enemy´s side
            if(seen_field.ball.x < seen_field.image_width/2.0)
            {
                defender_destination.first = seen_field.robot[defender].x;
                defender_destination.second = adjustYToLineSeg(seen_field.robot[defender].x,
                                              seen_field.ball.x, seen_field.ball.y,
                                              OFFSET_X + GOAL_X, seen_field.image_height/2.0);
            }
            else
            {
                //destination is the midpoint between the ball and the goal
                defender_destination.first = (seen_field.robot[defender].x - (OFFSET_X + GOAL_X))/2.0;
                defender_destination.second = (seen_field.robot[defender].y - seen_field.image_height/2.0)/2.0;
            }
        }
    }
    else
    {
        defender_destination.first = -1.0;
        defender_destination.second = -1.0;
    }

    return defender_destination;
}

/**
    std::pair<double,double> DefendMode::findAttackerDestination(Strategy *strat)

    to do

    @author Lucca Rawlyk
    @version 2017.11.01-1
*/

std::pair<double,double> DefendMode::findAttackerDestination(Strategy* strat)
{
    std::pair<double,double> attacker_destination;
    field seen_field = strat->getLastSeenField();

    //finds the attacker, assumes that there is one and only one
    int i, attacker;
    for(i=0; i<N_PLAYERS; i++)
    {
        if(strat->getRole(i) == ATTACKER)
        {
            attacker = i;
            break;
        }
    }

    if(seen_field.robot[attacker].found && seen_field.ball.found)
    {
        attacker_destination.first = seen_field.ball.x;
        attacker_destination.second = seen_field.ball.y;
    }
    else
    {
        attacker_destination.first = -1.0;
        attacker_destination.second = -1.0;
    }

    return attacker_destination;
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
