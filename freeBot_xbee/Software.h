//biblioteca responsavel por receber a velocidade final e setar na espinha dorsal, e tambem pelos testes

#ifndef _SOFTWARE_H_
#define _SOFTWARE_H_

#include <Arduino.h>
#include "BotConstantes.h"
#include "EspinhaDorsal.h"

class Software{
private:
    int tempo;
    void teste(EspinhaDorsal *espinhaDorsalIN);

public:
    Software();
    //--Comunicacao com o HardWare
    void atualizar(EspinhaDorsal *espinhaDorsalIN);
    ~Software() {};
};
#endif


