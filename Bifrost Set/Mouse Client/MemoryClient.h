#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

#define CONSTANTE_DA_CHAVE 5678
#include "RobotMsg.h"

//struct RobotMsg{
//    char process[20]; //--Nome do processo!
//    int nameOfRobot;//--Numero do Robô!
//    float velX;//--Velocidade em X
//    float velY;//--Velocidade em Y
//    int chute;//--Chute (sim ou não);
//    int status;//--"reserva técnica", se necessário, usa-se esse espaço.
//};

class MemoryClient{
private:
        struct RobotMsg *_pacote;
        char _nameProcess [20];
        size_t _shmsize;
        int _shmid;
        key_t _key;

        void _setup(int nameIN);
        void _unSetup();
public:
        MemoryClient();
        MemoryClient(char nameIN[20]);
        ~MemoryClient(){};

        int getID();
        void setNameOfProcess(char nameIN[20]);
        void sendVelX(int nameOfRobotIN, float velXIN);
        void sendVelY(int nameOfRobotIN, float velYIN);
        void sendChute(int nameOfRobotIN, int chuteIN);
        void sendStatus(int nameOfRobotIN, int statusIN);
};

