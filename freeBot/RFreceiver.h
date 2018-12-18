//biblioteca responsavel por receber os dados do transmissor, e coloca-los num buffer local, para ser transformado posteriormente em velocidades angular, x e y

#ifndef _XBEEROBO_H_
#define _XBEEROBO_H_

#include <Arduino.h>
#include "BotConstantes.h"
#include "Buffer.h"
#include "Radio.h"

class RFreceiver{
private:
    float velocidadeX;
    float velocidadeY;
    float velAng;
    Buffer* queue;
    Radio radio;
    uint8_t address;

public:
    RFreceiver();
    int atualizarBuffer();
    float getVelX();
    float getVelY();
    float getVelAng();
    int receber();
    void debug();
    ~RFreceiver() {};
};
#endif
