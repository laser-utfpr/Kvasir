#include "Robot.hpp"

Robot::Robot(int _name, char *_rf_address)
{
    name = _name;
    rf_address = _rf_address;
    loader = VelocitiesLoader::getInstance();
}

char *Robot::getRFAddress()
{
    return rf_address;
}

int Robot::getName()
{
    return name;
}

float Robot::getVelX()
{
    loader->updateVelocities();
    return loader->getVelX(name);
}

float Robot::getVelY()
{
    loader->updateVelocities();
    return loader->getVelY(name);
}

float Robot::getVelAng()
{
    loader->updateVelocities();
    return loader->getVelAng(name);
}
