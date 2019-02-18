//biblioteca que recebe as velocidades recebidas do transmissor

#ifndef _COMUNICACAO_H_
#define _COMUNICACAO_H_

#include "XbeeRobo.h"
#include "BotConstantes.h"

class Comunicacao{
private:
    XbeeRobo* radio;
    float velocidadeEixoX;
    float velocidadeEixoY;
    float velAng;
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
