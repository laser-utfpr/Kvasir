#include "Robot.hpp"

Robot::Robot(int _name, std::string _rf_address)
{
    name = _name;
    rf_address = _rf_address;
    loader = VelocitiesLoader::getInstance();//estranho
}

char *Robot::getRFAddress()
{
    return (char*)rf_address.c_str();
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
