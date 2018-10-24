#include "Robo.h"
using namespace std;

Robo::Robo(int nameIN, char* MACIN)
{
    ptrProx = NULL;
    nome = nameIN;
    strcpy(MAC,MACIN);
    loader = VelocitiesLoader::getInstance();
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
    loader->updateVelocities();
    return loader->getVelX(nome);
}

float Robo::getVelY()
{
    loader->updateVelocities();
    return loader->getVelY(nome);
}

float Robo::getVelAng()
{
    loader->updateVelocities();
    return loader->getVelAng(nome);
}

char *Robo::getMAC()
{
    return MAC;
}

char *Robo::getProcessName()
{

}
