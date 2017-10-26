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

/**
    int Strategy::kbhit(void)

    Manual implementaion of conio.h's kbhit.

    @author Lucca Rawlyk
    @version 2017.10.24-1
*/



bool Strategy::shouldWeDefend(void)
{

}

/**
    void Strategy::updateField(void)

    Updates the field using the FieldLoader class.

    @author Lucca Rawlyk
    @version 2017.10.17-1
*/

void Strategy::updateField(void)
{
    FieldLoader *loader = FieldLoader::getInstance();
    current_field = loader->getField();
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
        if(kbhit())
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
