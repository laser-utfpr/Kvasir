#include "strategy.hpp"

Strategy::Strategy()
{
    role[ROBOT_1-ROBOT_1] = GOALKEEPER;
    role[ROBOT_2-ROBOT_1] = DEFENDER;
    role[ROBOT_3-ROBOT_1] = ATTACKER;

    mode[ATTACK_MODE] = new AttackMode;
    mode[DEFEND_MODE] = new DefendMode;
    mode[INTERRUPT_MODE] = new InterruptMode;
    mode[FREEBALL_MODE] = new FreeBallMode;
}

Strategy::~Strategy()
{
    int i;
    for(i=0; i<N_MODES; i++)
      delete mode[i];
}

bool Strategy::shouldWeDefend(void)
{
    int i;
    for(i=0; i<N_PLAYERS; i++)
    {
        if(role[i] != GOALKEEPER &&
          distance(field.robot[i].x, field.robot[i].y,
                    field.ball.x, field.ball.y) < MIN_ATTACKING_DIST)
            return false;
    }
    else
    {
        for(i=0; i<N_PLAYERS; i++)
        {
            if(distance(field.enemy_robot[i].x, field.enemy_robot[i].y,
                      field.ball.x, field.ball.y) < MIN_ATTACKING_DIST)
                return true;
        }
    }
    return false;
}

/**
    void Strategy::updateField(void)

    Updates the current field using the FieldLoader class,
    then updates the found entities to the last seen field.

    @author Lucca Rawlyk
    @version 2017.10.27-1
*/

void Strategy::updateField(void)
{
    FieldLoader *loader = FieldLoader::getInstance();
    current_field = loader->getField();
    if(current_field.ball.found)
        last_seen_field.ball = current_field.ball;
    int i;
    for(i=0; i<N_PLAYERS; i++)
        if(current_field.robot[i].found)
            last_seen_field.robot[i] = current_field.robot[i];
    for(i=0; i<N_PLAYERS; i++)
        if(current_field.enemy_robot[i].found)
            last_seen_field.enemy_robot[i] = current_field.enemy_robot[i];
}

/**
    void Strategy::decideMode(void)

    Decides which mode to set based on the field and keyboard inputs.

    @author Lucca Rawlyk
    @version 2017.10.24-1
*/

void Strategy::decideMode(void)
{
    if(!mode[active_mode]->inProgress(this))
    {
        if(_kbhit())
        {
            char key = std::cin.get();
            switch(key)
            {
                case 'i':
                active_mode = INTERRUPT_MODE; break;

                case 'f':
                active_mode = FREEBALL_MODE; break;

                default:
                break;
            }
        }
        if(shouldWeDefend())
            active_mode = DEFEND_MODE;
        else
            active_mode = ATTACK_MODE;
    }
}

/**
    void Strategy::setDesiredXVel(int player, double x, double y, double ang)

    Sets a desired x velocity.

    @author Lucca Rawlyk
    @version 2017.10.25-1
*/

void Strategy::setDesiredXVel(int player, double x)
{
    if(player>0 && player<N_PLAYERS)
        desired_vel[player].x = x;
}

/**
    void Strategy::setDesiredYVel(int player, double y)

    Sets a desired y velocity.

    @author Lucca Rawlyk
    @version 2017.10.25-1
*/

void Strategy::setDesiredYVel(int player, double y)
{
    if(player>0 && player<N_PLAYERS)
        desired_vel[player].y = y;
}

/**
    void Strategy::setDesiredAngVel(int player, double ang)

    Sets a desired angular velocity.

    @author Lucca Rawlyk
    @version 2017.10.25-1
*/

void Strategy::setDesiredAngVel(int player, double ang)
{
    if(player>0 && player<N_PLAYERS)
        desired_vel[player].ang = ang;
}

field getCurrentField(void)
{
    return current_field;
}

field getLastSeenField(void)
{
    return last_seen_field;
}
