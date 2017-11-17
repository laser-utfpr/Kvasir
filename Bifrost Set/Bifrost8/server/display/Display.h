#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include <stdio.h>
#include <string.h>
#include "Colors.h"
#include "../ServerConstantes.h"



//--BUGS: Não salva os ultimos!!!
//--      Não precerva o tamanho do log
class Display{
private:
    char url[];
    FILE *arq;

    char displayRobos[LINHAS][COLUNAS];
    char displayStatus[LINHAS][COLUNAS];
    char displayRecebido[LINHAS][COLUNAS];
    char displayRadio[LINHAS][COLUNAS];
    char matrixLog[TAMANHO_DO_LOG][COLUNAS];
    int bufferPronto;

    void reset();
    void includeOnLog(char* lineIN);
    void resetMatrixLog();
    void saveOnFile();
public:
    Display();
    ~Display();

    void print();
    void addLineRobos(char* lineIN);
    void addLineStatus(const char* lineIN);
    void addLineRecebido(char* lineIN);
    void addLineRadio(char* lineIN);
};

#endif
