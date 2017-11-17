#include "Display.h"

Display::Display()
{
    strcpy(url,"log.txt");
    bufferPronto = 0;
    remove(url);//--reseta a bagaça
    arq = fopen(url, "w");
    reset();
    resetMatrixLog();
}
Display::~Display()
{
    saveOnFile();
    fclose(arq);
    style(RESETALL);
}

void Display::reset()
{
    int i, j;
    for(i=0; i<LINHAS; i++)
        for(j=0; j<COLUNAS; j++)
        {
            displayRobos[i][j] = 0;
            displayStatus[i][j] = 0;
            displayRecebido[i][j] = 0;
            displayRadio[i][j] = 0;
        }
}

void Display::print()
{
    int i,j;
    printf("\e[1;1H\e[2J");//--Limpa a tela!
    //--Atividade dos robos
    foreground(RED);
    printf("-----------------------------------ROBOS ATIVOS-----------------------------------");
    for(i=0; i<LINHAS; i++)
    {
        printf("%s\n",displayRobos[i]);
    }
    //--Esteticamente achei melhor zerar a matriz de robos ativos para formar tabelas!
    for(i=0; i<LINHAS; i++)
        for(j=0; j<COLUNAS; j++)
            displayRobos[i][j] = 0;
    //--status:
    foreground(BLUE);
    printf("--------------------------------------STATUS--------------------------------------\n");
    for(i=0; i<LINHAS; i++)
        printf("%s\n",displayStatus[i]);

    foreground(YELLOW);
    printf("----------------------------------PACOTES REBIDOS---------------------------------\n");
    for(i=0; i<LINHAS; i++)
        printf("%s\n",displayRecebido[i]);

    foreground(GREEN);
    printf("-----------------------------PACOTES ENVIADOS POR RADIO-----------------------------\n");
    for(i=0; i<LINHAS; i++)
        printf("%s\n",displayRadio[i]);
    style(RESETALL);
}

void Display::addLineRobos(char* lineIN)
{
    int i;
    for(i=1; i<(LINHAS); i++)
        strcpy(displayRobos[i-1],displayRobos[i]);
    strcpy(displayRobos[LINHAS-1],"");
    strcat(displayRobos[LINHAS-1],lineIN);
    includeOnLog(displayRobos[LINHAS-1]);
}

void Display::addLineStatus(const char* lineIN)
{
    int i;
    for(i=1; i<(LINHAS); i++)
        strcpy(displayStatus[i-1],displayStatus[i]);

    strcpy(displayStatus[LINHAS-1],"STATS:");
    strcat(displayStatus[LINHAS-1],lineIN);
    includeOnLog(displayStatus[LINHAS-1]);
}
void Display::addLineRecebido(char* lineIN)
{
    int i;
    for(i=1; i<(LINHAS); i++)
        strcpy(displayRecebido[i-1],displayRecebido[i]);

    strcpy(displayRecebido[LINHAS-1],"RECEB: ");
    strcat(displayRecebido[LINHAS-1],lineIN);
    includeOnLog(displayRecebido[LINHAS-1]);
}
void Display::addLineRadio(char* lineIN)
{
    int i;
    for(i=1; i<(LINHAS); i++)
        strcpy(displayRadio[i-1],displayRadio[i]);

    strcpy(displayRadio[LINHAS-1],"RADIO: ");
    strcat(displayRadio[LINHAS-1],lineIN);
    includeOnLog(displayRadio[LINHAS-1]);
}

void Display::includeOnLog(char* lineIN)
{

    int i;
//char *entrada;
    for(i=1; i<(TAMANHO_DO_LOG); i++)
        strcpy(matrixLog[i-1],matrixLog[i]);

    strcpy(matrixLog[TAMANHO_DO_LOG-1],lineIN);
    strcat(matrixLog[TAMANHO_DO_LOG-1],"\n\n-----------------------------------\n\n");

    if(bufferPronto < TAMANHO_DO_LOG)
        bufferPronto++;
    else
    {
        saveOnFile();
        bufferPronto = 0;
    }
}

void Display::saveOnFile() //--Para evita acessos ao disco rigido!
{
    int i;
    remove(url);//--Deleta o Arquivo (Não estourar o tamanho)
    if(arq == NULL)
        printf("NãoCriado");
    else
    {
        for(i=0; i<TAMANHO_DO_LOG; i++)
            fprintf(arq,"%s",matrixLog[i]);
    }
    resetMatrixLog();
}

void Display::resetMatrixLog()
{
    int i, j;
    for(i=0; i<TAMANHO_DO_LOG; i++)
        for(j=0; j<COLUNAS; j++)
            matrixLog[i][j] = 0;
}
