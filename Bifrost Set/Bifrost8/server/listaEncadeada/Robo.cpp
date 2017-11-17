#include "Robo.h"

Robo::Robo()
{
    ptrProx = NULL;
}

Robo::Robo(int nameIN, char* MACIN)
{
    nome = nameIN;
    strcpy(MAC,MACIN);
    servidor = new MemoryServer("SERVIDOR",nome);//--Cria o bloco de memoria pro robo representado por tal número
    mensagem = servidor->getMsgSpace();//-- atribui o espaço reservado na memória ao robô
}

void Robo::setProximoRobo(Robo* roboIN)
{
    ptrProx = roboIN;
}

Robo* Robo::getProximoRobo()
{
    return ptrProx;
}

int Robo::getNome()
{
    return nome;
}

float Robo::getVelX()
{
    return mensagem->velX;
}

float Robo::getVelY()
{
    return mensagem->velY;
}

float Robo::getVelAng()
{
    return mensagem->velAng;
}

char *Robo::getMAC()
{
    return MAC;
}

char *Robo::getProcessName()
{
    return servidor->getNameOfProcess();
}
