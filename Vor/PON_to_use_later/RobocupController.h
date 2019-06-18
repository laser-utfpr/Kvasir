#ifndef ROBOCUPCONTROLLER_H
#define ROBOCUPCONTROLLER_H

#include <QThread>
#include <pthread.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <iostream>
using namespace std;
#include "../MainClient/messages/robocup_ssl_client.h"
#include "Team.h"
#include "ComSysSimulator.h"

#define HELLO_PORT 10001            // NUM DA PORTA PARA RECEBER O PACOTE DO ÁRBITRO
#define HELLO_GROUP "224.5.23.1"    // NUM DA PORTA MULTICAST
#define MSGBUFSIZE 6                // TAMANHO DO PACOTE EM BYTES

class RobocupController
{
private:
    Team* teamObj;
    char refereeCommand;   
public:
    RobocupController();
    ~RobocupController();

    char getRefereeCmd();
    void setRefereeCmd(char cmd);
    void codeApplication();

private:
    void startRefereeCommunication();
    void initTeam();

};


#endif // ROBOCUPCONTROLLER_H
