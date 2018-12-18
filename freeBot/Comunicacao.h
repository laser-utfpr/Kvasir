//biblioteca que recebe as velocidades recebidas do transmissor

#ifndef _COMUNICACAO_H_
#define _COMUNICACAO_H_

#include "RFreceiver.h"
#include "BotConstantes.h"

class Comunicacao{
private:
    RFreceiver rReceiver;
    float velocidadeEixoX;
    float velocidadeEixoY;
    float velAng;
    int aux, tempo, a;
public:
    Comunicacao();
    //--Obter Dados recebidos:
    float getVelocidadeEixoX();
    float getVelocidadeEixoY();
    float getVelocidadeAng();
    int aguardarDados(int captar);
    ~Comunicacao() {};
};
#endif
