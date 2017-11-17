#ifndef _RELACAOROBOS_H_
#define _RELACAOROBOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ServerConstantes.h"

class RelacaoRobos{
private:
    char fileMAC[LINHAS_ROBOS][COLUNAS_MAC];
    char fileNumbers[LINHAS_ROBOS][COLUNAS_NUMBERS];
    void resetFileMatrix();
    char url[30];
    FILE *arq;
    void openArchive();
    int acesso;
    char MAC[20];

public:
    RelacaoRobos();
    ~RelacaoRobos() {};

    int getNextLine();
    char* getMAC();
    int getNumero();
};
#endif
