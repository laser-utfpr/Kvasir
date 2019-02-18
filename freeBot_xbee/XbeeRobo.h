//biblioteca responsavel por receber os dados do transmissor, e coloca-los num buffer local, para ser transformado posteriormente em velocidades angular, x e y

#ifndef _XBEEROBO_H_
#define _XBEEROBO_H_

#include <Arduino.h>
#include "BotConstantes.h"
#include "Buffer.h"

class XbeeRobo{
private:
    float velocidadeX;
    float velocidadeY;
    float velAng;
    Buffer* queue;
    
public:
    XbeeRobo();
    int atualizarBuffer();
    float getVelX();
    float getVelY();
    float getVelAng();
    void receberRS232();
    ~XbeeRobo() {};
};
#endif


