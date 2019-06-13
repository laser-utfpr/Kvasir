#include "RobocupController.h"
#include "RefereeBoxCommunication.h"
//referencia pra ver o que fazer
RobocupController::RobocupController(){
}

RobocupController::~RobocupController() {
}

char RobocupController::getRefereeCmd() {
    return this->refereeCommand;
}

void RobocupController::setRefereeCmd(char cmd) {
    this->refereeCommand = cmd;
    this->teamObj->updateCmdReferee(cmd);
}


void RobocupController::startRefereeCommunication() {
    pthread_t refbox;
    pthread_create(&refbox, NULL, RefereeBoxCommunication::ComThread, this);
}

void RobocupController::initTeam() {
    int option = 0;

    cout << "Qual Time o usuário deseja controlar? leo2" << endl;
    cout << "1. Azul" << endl;
    cout << "2. Amarelo" << endl;
    cin >> option;

    switch (option) {
        case 1:
            this->teamObj = new Team(BLUE, LEFT, 6);
            break;
        case 2:
            this->teamObj = new Team(YELLOW, RIGHT, 6);
            break;
        default:
            initTeam();
    }
}

void RobocupController::codeApplication() {
    // Init Team objects
    initTeam();

    startRefereeCommunication();

    // Open connection to DataAcquisitionInterface:
    RoboCupSSLClient client;
    client.open(true);
    SSL_WrapperPacket packet;

    // Keep receiving packet from DataAcquisitionInterface:
    while(true) {
        if (client.receive(packet)) {
            if (packet.has_detection()) {
                SSL_DetectionFrame packetDetected = packet.detection();
                this->teamObj->updateTeamPerception(packetDetected);
            }
        }
    }
}
