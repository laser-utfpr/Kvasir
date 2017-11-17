#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#ifndef MEMORYSERVER_H
#define MEMORYSERVER_H

#include <string.h>
#include "RobotMsg.h"
#include "../ServerConstantes.h"

class MemoryServer{
private:
        struct RobotMsg *pacote;
        char nameProcess[20];
        size_t shmsize;
        int shmid;
        key_t key;
        void setup(int roboID);
public:
        MemoryServer();
        MemoryServer(char* nameIN, int roboID);
        ~MemoryServer(){};
        int getID();
        struct RobotMsg* getMsgSpace();
        char* getNameOfProcess();
};
#endif


