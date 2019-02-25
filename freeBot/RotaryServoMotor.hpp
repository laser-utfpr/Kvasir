//bilioteca responsavel por escrever a velocidade nos servos

#ifndef _ROTARYSERVOMOTOR_HPP__
#define _ROTARYSERVOMOTOR_HPP__

#include "VarSpeedServo.h" //esta biblioteca eh usada para futuros aprimoramentos no controle da velocidade de cada motor. No momento, ela nao eh necessaria, podendo no lugar dela ser usada a Servo.h
#include "BotConstants.h"
#include <Arduino.h>

class RotaryServoMotor{
private:
    VarSpeedServo *servo;
    int pwm_pin;
    float max_speed;
    int adjust_speed;

public:
    RotaryServoMotor(int _pwm_pin, float _max_speed, int _adjust_speed);
    ~RotaryServoMotor() {};
    void setSpeed(float speed);
};

#endif
