#ifndef _SERVOROTATIVO_H__
#define _SERVOROTATIVO_H__

#include <Arduino.h>
#include "VarSpeedServo.h"
#include "Constantes.h"
class ServoRotativo{
    private:
          int _pinoPWM; //--pino que controla o motor
          int _pinoADJ; //--Pino do potenciometro que ajusta o "zero"
          int _potenciometroAjuste;
          int _velAjuste;
          float _velocidadeMaxima; //--Velocidade Máxima que o conjunto motor+rodas atinge
          int _motorNum;
          Constantes constante;
          
          VarSpeedServo _servo;
    public:  
    ServoRotativo(){};
    ~ServoRotativo(){};

    float getVelAjuste();

    void setServoMotor(int pinoIN, float velocidadeMaximaIN, int motorNum);
    void setVelocidade(float velocidadeIN);
    void setCalibragem();
};

#endif
