#ifndef _LISTAROBOS_H_
#define _LISTAROBOS_H_

#include "Robo.h"

class ListaRobos{
private:
    Robo* primeiroRobo; //--Sinaliza o primeiro item, para iniciar inserção, e remoção dos itens
    Robo* roboAtual; //--Sinalisa o ultimo, o mais atual, para poder adicionar o ultimo e ganhar tempo
    Robo* roboExibido;//-- Serve para armazenar os dados de robôs exibido pelo método Percorre Lista

    int tamanhoDaEstrutura;
public:
    ListaRobos();
    ~ListaRobos();

    Robo* percorreLista();//-- a função retorna 0 ao chegar ao fim da lista
    void adicionarRobo(int nameIN, char* MACIN);
};

#endif
