#ifndef _ROBO_H_
#define _ROBO_H_

#include "VelocitiesLoader.hpp"
#include "RobotMsg.h"

class Robo{
private:
    int nome;
    VelocitiesLoader *loader;
    RobotMsg* mensagem;
    char MAC[30];
    Robo* ptrProx;

    static boost::interprocess::managed_shared_memory *memoria_compartilhada;
public:
    Robo(int nameIN, char* MACIN);

    Robo* getProximoRobo();
    void setProximoRobo(Robo* roboIN);

    int getNome();
    float getVelX();
    float getVelY();
    float getVelAng();
    char getChute();
    char getStatus();
    //--Funções uteis para transmissão (já convertem para caracteres entre 0=< até <~)
    char *getMAC();
    char *getProcessName();
};
#endif
