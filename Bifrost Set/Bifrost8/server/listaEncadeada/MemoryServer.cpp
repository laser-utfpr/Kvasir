#include "MemoryServer.h"

MemoryServer::MemoryServer(char nameIN[20], int roboID)
{
    strcpy(nameProcess, nameIN);//--Seta nome do processo!
    setup(roboID);
}

MemoryServer::MemoryServer()
{
    strcpy(nameProcess, "Unnamed Process");
    setup(0);
}

void MemoryServer::setup(int roboID)
{
    key = CONSTANTE_DA_CHAVE + roboID; //--nome do segmento
    shmsize = sizeof(struct RobotMsg); //--define o tamanho do segmento
    printf("%d\n", key);

    //--Criando o segmento
    if ((shmid = shmget(key, shmsize, IPC_CREAT | 0666)) < 0)  //--substitui o valor constante!!
    {
        printf("Erro ao encontrar um segmento de memória disponível!\n");
        return;
    }
    //--Now we attach the segment to our data space.
    if ((pacote = (struct RobotMsg*)shmat(shmid, NULL, 0)) == ((struct RobotMsg*) -1))
    {
        printf("Erro ao acoplar as variaveis locais às compartilhadas");
        return;
    }
    printf("Segmento Criado na memória com sucesso!!\nAguardando clientes...");
}

struct RobotMsg* MemoryServer::getMsgSpace()
{
    return pacote;
}

char* MemoryServer::getNameOfProcess()
{
    return nameProcess;
}

