//biblioteca responsavel pela leitura da memoria compartilhada criada pela AI ou pelo MouseClient

#ifndef VELOCITIESLOADER_HPP
#define VELOCITIESLOADER_HPP

#include <iostream>
#include <smmclib.hpp>
#include <cmath>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/allocators/allocator.hpp>

#define MAX_LINEAR_VEL 0.3
#define MAX_ANGULAR_VEL 5.0*M_PI_2

class VelocitiesLoader
{
private:
    boost::interprocess::managed_shared_memory *shared_memory;
    Movement *robot_movement;
    static VelocitiesLoader* instance;
    void openSharedMemory(void);
    VelocitiesLoader();
public:
    ~VelocitiesLoader();
    static VelocitiesLoader* getInstance(void);
    void updateVelocities(void);
    double getVelX(int robot);
    double getVelY(int robot);
    double getVelAng(int robot);
};

#endif // VELOCITIESLOADER_HPP
