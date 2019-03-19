#include "VelocitiesLoader.hpp"

using namespace boost::interprocess;

VelocitiesLoader* VelocitiesLoader::instance = NULL;

VelocitiesLoader* VelocitiesLoader::getInstance(void)
{
    if(instance==NULL)
        instance = new VelocitiesLoader;
    return instance;
}

VelocitiesLoader::VelocitiesLoader()
{
    shared_memory = NULL;
    openSharedMemory();
}

VelocitiesLoader::~VelocitiesLoader()
{
    delete instance;
}

void VelocitiesLoader::openSharedMemory(void)
{
    if(shared_memory!=NULL) //deletes the last opened vision shared memory if it exists
        delete shared_memory;

    try
    {
        shared_memory = new managed_shared_memory(open_only, SHARED_MEMORY_BLOCK_NAME);
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl << "Exception called while opening shared memory block:" << std::endl;
        std::cout << e.what() << std::endl;
        exit(1);
    }
}

void VelocitiesLoader::updateVelocities(void)
{
    try
    {
        robot_movement = (shared_memory->find<Movement>(ROBOT_MOVEMENT_MEMORY_NAME)).first;
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl << "Exception called while acessing robot movements:" << std::endl;
        std::cout << e.what() << std::endl;
        exit(1);
    }
}

double VelocitiesLoader::getVelX(int robot)
{
    if(robot >= N_ROBOTS || robot < 0)
        return 0.0;
    if(robot_movement[robot].stay_still)
        return 0.0;
    return MAX_LINEAR_VEL*robot_movement[robot].linear_vel_scaling*cos(robot_movement[robot].linear_vel_angle);
}

double VelocitiesLoader::getVelY(int robot)
{
    /*std::cout << "stay_still " << robot_movement[robot].stay_still << std::endl;
    std::cout << "linear_vel_scaling " << robot_movement[robot].linear_vel_scaling << std::endl;
    std::cout << "linear_vel_angle " << robot_movement[robot].linear_vel_angle << std::endl;
    std::cout << "angular_vel_scaling " << robot_movement[robot].angular_vel_scaling << std::endl << std::endl;*/

    if(robot >= N_ROBOTS || robot < 0)
        return 0.0;
    if(robot_movement[robot].stay_still)
        return 0.0;
    return MAX_LINEAR_VEL*robot_movement[robot].linear_vel_scaling*sin(robot_movement[robot].linear_vel_angle);
}

double VelocitiesLoader::getVelAng(int robot)
{
    if(robot >= N_ROBOTS || robot < 0)
        return 0.0;
    if(robot_movement[robot].stay_still)
        return 0.0;
    return MAX_ANGULAR_VEL*robot_movement[robot].angular_vel_scaling;
}
