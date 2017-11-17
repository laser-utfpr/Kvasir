#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#include <unistd.h>
#include "display/Display.h"
#include "listaEncadeada/ListaRobos.h"
#include "relacaoRobos/RelacaoRobos.h"
#include "listaEncadeada/Robo.h"
#include "radio/Radio.h"
#include "radio/XbeeAPI.h"
#include "string.h"
#include <iostream>

class Principal{
private:
    Display* display;
    ListaRobos* vetorRobos;
    RelacaoRobos* arquivo;
    Robo* acessado;
    Radio* radio;
    XbeeAPI* xbee;

    void checarRobosAtivos();
    void carregarRobos();
    void transmitir();

public:
    Principal();
    ~Principal();
};
#endif
