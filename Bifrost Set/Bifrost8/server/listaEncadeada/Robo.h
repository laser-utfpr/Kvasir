#ifndef _ROBO_H_
#define _ROBO_H_

#include "MemoryServer.h"
#include "RobotMsg.h"

class Robo{
private:
    int nome;
    MemoryServer* servidor;
    RobotMsg* mensagem;
    char MAC[20];
    Robo* ptrProx;
public:
    Robo();
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
