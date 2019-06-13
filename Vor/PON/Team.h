#ifndef TEAM_H
#define TEAM_H

#include "EnemyRobot.h"
#include "ComSysSimulator.h"
#include "../MainClient/messages/robocup_ssl_client.h"
#include "pon/cppcompilados/Robotrobot1.h"
#include "pon/cppcompilados/Robotrobot2.h"
#include "pon/cppcompilados/Robotrobot3.h"
#include "pon/cppcompilados/Robotrobot4.h"
#include "pon/cppcompilados/Robotrobot5.h"
#include "pon/cppcompilados/Robotrobot6.h"

#include <list>
using namespace std;
using std::list;

class FactoryRobot;
class Team
{
private:
    vector < BaseRobot *>* teamPlayers;
    vector < EnemyRobot *>* enemyPlayers;
    FieldSide fieldSide;
    TeamColor teamColor;    

    // Robots:
    Robotrobot1 * robot1;
    Robotrobot2 * robot2;
    Robotrobot3 * robot3;
    Robotrobot4 * robot4;
    Robotrobot5 * robot5;
    Robotrobot6 * robot6;
public:       
    Team(TeamColor color, FieldSide side, int numPlayers);
    ~Team();
    void createTeamRobots(int numRobots);
    void initRobot(BaseRobot *robot, int id, CommunicationSystem *comSystem, BaseRobot::PlayerRole role);
    TeamColor getTeamColor();
    FieldSide getSide();    
    vector< BaseRobot* >* getTeamPlayers();
    void updateTeamPerception(SSL_DetectionFrame detectedFrame);
    void updateCmdReferee(char cmd);
    char checkCommand(char cmd);
    bool closerToBall(BaseRobot* robot);
};

#endif // TEAM_H
