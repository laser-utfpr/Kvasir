//biblioteca que contem as velocidades de cada motor, e o calculo da mesma

#ifndef _MOVIMENTACAO_H_
#define _MOVIMENTACAO_H_

#include <math.h>
#include "BotConstantes.h"
#include "ServoRotativo.h"

struct VelocidadeDosMotores{
    float motor1;
    float motor2;
    float motor3;
    float motor4;
};

class Movimentacao{
private:
    ServoRotativo* motor1;
    ServoRotativo* motor2;
    ServoRotativo* motor3;
    ServoRotativo* motor4;
    VelocidadeDosMotores velocidade;
    void calculo(float velX, float velY, float w);//calcula a velocidade de cada motor

public:
    Movimentacao();
    ~Movimentacao() {};
    void mover(float velX, float velY, float w);//envia a velocidade para o motor ler


};
#endif
