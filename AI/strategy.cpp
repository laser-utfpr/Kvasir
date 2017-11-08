#include "strategy.hpp"

using namespace boost::interprocess;

Strategy* Strategy::instance = nullptr;

Strategy* Strategy::getInstance(void)
{
    if(instance==nullptr)
        instance = new Strategy;
    return instance;
}

Strategy::Strategy()
{
    role[ROBOT_1-ROBOT_1] = ATTACKER;
    role[ROBOT_2-ROBOT_1] = DEFENDER;
    role[ROBOT_3-ROBOT_1] = GOALKEEPER;

    mode[ATTACK_MODE] = new AttackMode;
    mode[DEFEND_MODE] = new DefendMode;
    mode[INTERRUPT_MODE] = new InterruptMode;
    mode[FREEBALL_MODE] = new FreeBallMode;

    shared_memory_object::remove(AI_SHARED_MEMORY_NAME);
    shared_memory = new managed_shared_memory(open_or_create,AI_SHARED_MEMORY_NAME,AI_SHARED_MEMORY_SIZE);
    shared_memory_velocities = shared_memory->construct<velocity>(VELOCITIES_MEMORY_NAME)[N_PLAYERS]();
}

Strategy::~Strategy()
{
    int i;
    for(i=0; i<N_MODES; i++)
      delete mode[i];
    shared_memory_object::remove(AI_SHARED_MEMORY_NAME);
    delete shared_memory;
}

/**
    void Strategy::shouldWeDefend(void)

    Decides if the defend mode should be activated based if there aren't
    any allies near the ball and there is an enemy.

    @author Lucca Rawlyk
    @version 2017.10.27-1
*/

bool Strategy::shouldWeDefend(void)
{
    int i,j;
    //This part of the code assumes 3 Players,
    //one with each role and a fixed Goalkeeper
    if(last_seen_field.ball.found)
    {
        for(i=0; i<N_PLAYERS; i++)
        {
            if(role[i] != GOALKEEPER &&
              distance(last_seen_field.robot[i].x, last_seen_field.robot[i].y,
                       last_seen_field.ball.x, last_seen_field.ball.y) < MIN_ATTACKING_DIST)
            {
                role[i] = ATTACKER;
                for(j=0; j<N_PLAYERS; j++)
                {
                    //if it's the left player set it as defender
                    if(role[j] != GOALKEEPER && j != i)
                        role[j] = DEFENDER;
                }
                return false;
            }
        }

        for(i=0; i<N_PLAYERS; i++)
        {
            if(last_seen_field.enemy_robot[i].found)
                if(distance(last_seen_field.enemy_robot[i].x, last_seen_field.enemy_robot[i].y,
                            last_seen_field.ball.x, last_seen_field.ball.y) < MIN_ATTACKING_DIST)
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
                active_mode = INTERRUPT_MODE; return; break;

                /*case 'f':
                active_mode = FREEBALL_MODE; return; break;*/

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

field Strategy::getCurrentField(void)
{
    return current_field;
}

field Strategy::getLastSeenField(void)
{
    return last_seen_field;
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

roles Strategy::getRole(int i)
{
    return role[i];
}

void Strategy::calculateVelocities(void)
{
    mode[active_mode]->calculateVelocities(this);
}

void Strategy::saveVelocities(void)
{
    int i;
    for(i=0; i<N_PLAYERS; i++)
    {
        shared_memory_velocities[i] = desired_vel[i];
    }
}

void Strategy::printMode(void)
{
    std::cout << std::endl << "Mode: ";
    switch(active_mode)
    {
        case ATTACK_MODE:
            std::cout << "ATTACK_MODE" << std::endl; break;
        case DEFEND_MODE:
            std::cout << "DEFEND_MODE" << std::endl; break;
        case INTERRUPT_MODE:
            std::cout << "INTERRUPT_MODE" << std::endl; break;
        case FREEBALL_MODE:
            std::cout << "FREEBALL_MODE" << std::endl; break;
        default:
            break;
    }
}

void Strategy::printVelocities(void)
{
    int i;
    std::cout << std::endl;
    for(i=0; i<N_PLAYERS; i++)
    {
        std::cout << "Robot " << i << " Velocities:" << std::endl;
        std::cout << "x = " << desired_vel[i].x << std::endl;
        std::cout << "y = " << desired_vel[i].y << std::endl;
        std::cout << "ang = " << desired_vel[i].ang << std::endl;
    }
}
