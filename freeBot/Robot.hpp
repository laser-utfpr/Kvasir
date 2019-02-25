//bilioteca responsavel por escrever a velocidade nos servos

#ifndef _ROBOT_HPP__
#define _ROBOT_HPP__

#include "BotConstants.h"
#include "RotaryServoMotor.hpp"
#include <Arduino.h>

class Robot{
private:
    RotaryServoMotor *motors[4];
    float velocity[4];
    void calculateMotorsVelocity(float vel_x, float vel_y, float vel_ang);

public:
    Robot();
    ~Robot() {};
    void move(float vel_x, float vel_y, float vel_ang);
};

#endif
