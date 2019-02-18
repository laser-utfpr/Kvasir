//biblioteca responsavel por ativar a comunicacao e a movimentacao do robo. Salva os dados na espinha dorsal para leitura pelo Software

#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include "Comunicacao.h"
#include "Movimentacao.h"

#include "BotConstantes.h"
#include "EspinhaDorsal.h"

class Hardware{
private:
    Comunicacao* comunicacao;  //--Abriga o modulo xbee e a serial
    Movimentacao* movimentacao;//--Abriga os motores e os calculos

public:
    Hardware();
    //--Comunicacao com o Software
    void atualizar(EspinhaDorsal *espinhaDorsal);
    ~Hardware() {};
};
#endif
