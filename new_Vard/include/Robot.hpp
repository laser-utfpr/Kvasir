//biblioteca feita para guardar as componentes do robo

#ifndef _ROBOT_HPP_
#define _ROBOT_HPP_
#include "VelocitiesLoader.hpp"

class Robot{
    int name;
    char *rf_address;
    VelocitiesLoader *loader;

public:
    Robot(int _name, char *_rf_address);
    ~Robot(){};
    char *getRFAddress();
    int getName();
    float getVelX();
    float getVelY();
    float getVelAng();
};

#endif
