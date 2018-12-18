#include "Movimentacao.h"

Movimentacao::Movimentacao()
{
    motor1 = new ServoRotativo(MOTOR1_PINO, VELOCIDADE_MAXIMA, MOTOR1_VEL_AJUSTE);
    motor2 = new ServoRotativo(MOTOR2_PINO, VELOCIDADE_MAXIMA, MOTOR2_VEL_AJUSTE);
    motor3 = new ServoRotativo(MOTOR3_PINO, VELOCIDADE_MAXIMA, MOTOR3_VEL_AJUSTE);
    motor4 = new ServoRotativo(MOTOR4_PINO, VELOCIDADE_MAXIMA, MOTOR4_VEL_AJUSTE);

    velocidade.motor1 = 0;
    velocidade.motor2 = 0;
    velocidade.motor3 = 0;
    velocidade.motor4 = 0;
}

void Movimentacao::mover(float velX, float velY, float w)
{
    calculo(velX,velY, w);

    motor1->setVelocidade(velocidade.motor1);
    motor2->setVelocidade(velocidade.motor2);
    motor3->setVelocidade(velocidade.motor3);
    motor4->setVelocidade(velocidade.motor4);
}

//calculos feitos com base nos estudos da equipe UTBots.
//http://www.cbrobotica.org/mostravirtual/interna.php?id=15025
//usando SI, sentido de rotacao horaria
void Movimentacao::calculo(float velX, float velY, float w)
{
    //--Robô Visto de Cima
    //            _
    //      M1    /|
    //   ___|___ /
    //   |     |
    //M4-|CIMA!|-M2
    //   |     |
    //    -----
    //      |
    //      M3
    //

    float  vox=0, voy=0;
    vox=cos(ANG)*velX+sin(ANG)*velY;
    voy=-sin(ANG)*velX+cos(ANG)*velY;
    velocidade.motor1 = vox+w*RAIO_RODA;
    velocidade.motor2 = -voy+w*RAIO_RODA;
    velocidade.motor3 = -vox+w*RAIO_RODA;
    velocidade.motor4 = voy+w*RAIO_RODA;
}
