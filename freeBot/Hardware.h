//biblioteca responsavel por ativar a comunicacao e a movimentacao do robo. Salva os dados na espinha dorsal para leitura pelo Software

#ifndef _HARDWARE_H_
#define _HARDWARE_H_

#include "Comunicacao.h"
#include "Movimentacao.h"

#include "BotConstantes.h"
#include "EspinhaDorsal.h"

class Hardware{
private:
    Comunicacao comunicacao;  //--Abriga o modulo xbee e a serial
<<<<<<< HEAD
    Movimentacao* movimentacao;//--Abriga os motores e os calculos
=======
    Movimentacao movimentacao;//--Abriga os motores e os calculos
>>>>>>> cb7f1da065620fe6ff221ce749a10261c0cfc086

public:
    Hardware();
    //--Comunicacao com o Software
    void atualizar(EspinhaDorsal *espinhaDorsal);
    ~Hardware() {};
};
#endif
