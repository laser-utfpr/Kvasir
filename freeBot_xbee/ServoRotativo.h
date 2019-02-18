//bilioteca responsavel por escrever a velocidade nos servos

#ifndef _SERVOROTATIVO_H__
#define _SERVOROTATIVO_H__

#include "VarSpeedServo.h" //esta biblioteca eh usada para futuros aprimoramentos no controle da velocidade de cada motor. No momento, ela nao eh necessaria, podendo no lugar dela ser usada a Servo.h
#include "BotConstantes.h"

class ServoRotativo{
private:
    VarSpeedServo servo;
    int pinoPWM; 
    float velocidadeMaxima; 
    int velAjuste;

public:
    ServoRotativo(int _pinoPWM, float _velocidadeMaxima, int _VelAjuste);
    ~ServoRotativo() {};
    float getVelAjuste();
    void setVelocidade(float velocidadeIN);
    void setCalibragem();
};

#endif
