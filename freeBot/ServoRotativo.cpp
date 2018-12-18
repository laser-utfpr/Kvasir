#include "ServoRotativo.h"

ServoRotativo::ServoRotativo(int _pinoPWM, float _velocidadeMaxima, int _velAjuste)
{
    pinoPWM = _pinoPWM;
    velAjuste = _velAjuste;
    velocidadeMaxima = _velocidadeMaxima;
    servo.attach(pinoPWM);
    servo.write(velAjuste);//--Manda iniciar com o motor parado
}

void ServoRotativo::setVelocidade(float velocidade)
{
    float angulo;
    angulo = (velocidade*90)/velocidadeMaxima; //regra de tres para transformar a velocidade recebida num angulo
    if(velocidade==0)
    {
        Serial.println("estou parado");
        servo.detach(); //o servo eh desligado para melhor controle da velocidade de parada, ja que com a temperatura a mesma vai mudando, e tambem para economizar energia
    }
    else
    {
        servo.attach(pinoPWM);
        servo.write(angulo + velAjuste);//--sentido horário se angulo é positivo ou ~
        //Serial.println("estou andando");
    }
}

float ServoRotativo::getVelAjuste()
{
    return velAjuste;
}
