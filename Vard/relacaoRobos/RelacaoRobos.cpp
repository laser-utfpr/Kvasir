#include "RelacaoRobos.h"

void RelacaoRobos::resetFileMatrix()
{
    int i, j;

    for(i=0; i<LINHAS_ROBOS; i++)
        for(j=0; j<COLUNAS_MAC; j++)
            fileMAC[i][j] = '\0';

    for(i=0; i<LINHAS_ROBOS; i++)
        for(j=0; j<COLUNAS_NUMBERS; j++)
            fileNumbers[i][j] = '\0';
}

RelacaoRobos::RelacaoRobos()
{
    resetFileMatrix();
    acesso = 1;
    QString a = qApp->applicationDirPath();
    a += "/../relacaoRobos/RELACAO.txt";
    std::cout << a.toStdString() << std::endl;
    strcpy(url,a.toStdString().c_str());
    arq = fopen(url, "r");
    openArchive();
    fclose(arq);
}


void RelacaoRobos::openArchive()
{
    char number[6];
    char MAC[20];
    char ch;
    int flag;
    int numberCounter = 0;
    int MACCounter = 0;

    if(arq == NULL)
    {
        printf("Não foi possível carregar o arquivo! Fechando o programa.\n");
        exit(1);
    }
    else
        while((ch=fgetc(arq))!= EOF)
        {
            if(ch == '#')
                flag = 1;//--Comentários Detectado
            else if(ch == ':')
                flag = 2;//--Nova linha detectada
            else if(ch == '@')//--MacDetectado
                flag = 3;
            else if(ch == '\n')//--Fim de linha detectato!
                flag = 0;
            switch (flag)
            {
            case 2://--Numero do Robo
                if(numberCounter<6 && ch != ':')
                {
                    number[numberCounter] = ch;
                    numberCounter++;//--pula a casinha
                    number[numberCounter+1] = '\0';//--adiona novo fim a cada loop
                }
                break;
            case 3://--Numero endereco
                if(MACCounter<6 && ch != '@')
                {
                    MAC[MACCounter] = ch;
                    MACCounter++; //--Pula a casinha
                    MAC[MACCounter+1] = '\0';
                }
                break;
            case 0:
                if((MACCounter != 0) || (numberCounter != 0)) //--Uma nova linha válida de robos foi lida!
                {
                    //--Reseta os contadores
                    //printf("%s:%s,%d,%d\n", number,MAC, MACCounter,numberCounter);
                    strcpy(fileMAC[acesso],MAC);
                    strcpy(fileNumbers[acesso],number);
                    MACCounter = 0;
                    numberCounter = 0;

                    if(acesso<LINHAS_ROBOS)//--se ficar dentro do espaço definido
                        acesso++;
                }//--fim do IF MACOUNTER
                break;
            case 1://--COMETARIOS
                while((ch=fgetc(arq))!= EOF && ch != '\n');
                break;


            }//--Fim Switch-Case
            //}//--fim do IF
        }//--Fim do While
}//--Fim da função


int RelacaoRobos::getNextLine()
{
    acesso--;
    return acesso;
}

char* RelacaoRobos::getMAC()
{
    return fileMAC[acesso];
}

int RelacaoRobos::getNumero()
{
    return atoi(fileNumbers[acesso]);
}
