#ifndef BASEROBOT_H
#define BASEROBOT_H
#define MIN_VEL_FUZZY 0.4
#define INFINITE 99999

#include "Point.h"
#include "MVector.h"
#include "Point.h"
#include "Ball.h"
#include "EnemyRobot.h"
#include "UtilGame.h"
using namespace SpaceGameSettings;

class CommunicationSystem;
class ComSysSimulator;
class Team;


class BaseRobot
{

public:
    // Soccer Roles:
    enum PlayerRole{GOALKEEPER, GOALKEAPER_ONLY, DEFENDER_ONLY, DEFENDER_LEFT, DEFENDER_RIGHT, MIDFIELD_ONLY, MIDFIELD_LEFT, MIDFIELD_RIGHT, STRIKER_ONLY, STRIKER_LEFT, STRIKER_RIGHT};
    enum RobotDirections { DIR_FORWARD, DIR_LEFT, DIR_RIGHT };
    double const ANGLE_DIRECTION;
    const int RADIUS;


protected:    
    // Robot Identification:
    int id;
    int number;
    Team* team;
    PlayerRole role;

    // Robot control:
    double kick;
    double dribble;

    // Socket Communication
    CommunicationSystem *comSystem;

    // Fuzzy Controller
    flie *fuzzyController;
    float rangeHigh;

    // Soccer Attributes:
    TeamColor teamColor;
    FieldSide fieldSide;
    Point* ownGoal;
    Point* enemyGoal;
    Ball* ball;

    // Team members and enemies:
    vector<BaseRobot*> *teamRobots;
    vector <EnemyRobot*> *enemyRobots;

    // Environment Perception Attributes:
    double* distances;

    // Position Attributes:
    Point* position;
    double angle;
    Point* target;
    Point* posToGo;    

    // Movement Attributes:
    MVector* velocity;
    double angularVelocity;
    bool goingToBall;

    // Field Settings:
    int distanceForBall;
    double goalkeeperAreaRadius;
    double distMinToOurGoal;
    double distanceGoalMin;
    double distanceMinStop;
    double strickerDistance;
    double distMidfieldAttacking;
    double distanceToBallEnemy;
    double fieldHorizontalMin;   
    double fieldHorizontalMax;
    double fieldVerticalMin;
    double fieldVerticalMax;
    double goalkeeperPenalty;
    double penaltyMark;    
    double penaltyGoalPoint;
    double robotDistancePenalty;
    double distToBallAngle2Pl;
    double distToBallAngle3Pl;
    int goalWidth;
    double kickMax;
    Point *goalPostLeft;
    Point *goalPostRight;
    Point *enemyGoalPostLeft;
    Point *enemyGoalPostRight;

public:
    BaseRobot();
    // Default Constructor:
    void initRobot(int id, int number, TeamColor color, FieldSide side, CommunicationSystem* comSystem, Team* team);

    void initGoals(FieldSide side);
    void initFieldSettings(FieldSide side);

     //**************************************
    //
    // Status Methods
    //
    //*************************************
    bool isReady();


    //**************************************
    //
    // Communication Methods
    //
    //*************************************
    void sendCommand();


    //**************************************
    //
    // PON Methods
    //
    //*************************************
    void executeMove();
    void angleMove();
    void resetKickAndDribble();    
    void behaviorGkBallOutsideArea();
    void behaviorGkPenalty();
    void moveToStopPosition();
    void moveToStopPositionPositiveAngle();
    void moveToStopPositionPositiveAngle3pl();
    void moveToStopPositionNegativeAngle();
    void moveToStopPositionNegativeAngle3pl();
    void moveToStopPosition(Point *pos);
    void moveToLeftPost();
    void moveToRightPost();
    void moveToKickPosition();    
    void moveToDirectKickPosition();
    void moveToIndirectKickPosition();
    void markEnemyPositiveY();
    void markEnemyNegativeY();
    void moveStrikerPositionLeft();
    void moveStrikerPositionRight();
    void movePenaltyAttackLeftPosition();
    void movePenaltyAttackRightPosition();
    void movePenaltyAttackPosition(int index);
    void movePenaltyDefenseCenterPosition();
    void movePenaltyDefenseLeftPosition();
    void movePenaltyDefenseRightPosition();
    void movePenaltyDefensePosition(int index);
    void positionStricker(Point *enemyPostPosition, double dist_min, double dist_max, double angle_min, double angle_max);
    void markEnemy();
    void markEnemy(double yMin, double yMax);
    void readyKickoff();
    void positionKickPenalty();
    void readyPenalty();
    void positionTopassBallPartner();
    void passBallPartner();
    void targetToBall();
    void moveLeftWarmUpPos();
    void moveRightWarmUpPos();


    //**************************************
    //
    // Getters and Setters:
    //
    //*************************************

    // Id:
    int getId();

    // Number:
    int getNumber();

    // Team:
    Team* getTeam();

    // Player Roles
    void setPlayerRole(PlayerRole role);
    PlayerRole getPlayerRole();

    // Team Robots:
    vector<BaseRobot*>* getTeamRobots();
    vector<BaseRobot*>* getTeamPartners();
    BaseRobot *getTeamPartnerById(int id);
    void setTeamRobots(vector<BaseRobot*> *robots);

    // Enemy Robots:
    vector<EnemyRobot*>* getEnemyRobots();
    void setEnemyRobots(vector<EnemyRobot*> *robots);

    // Position:
    Point* getPosition();
    void setPosition(Point* position);

    // Position To Go:
    Point* getPosToGo();
    void setPosToGo(Point* position);

    // Robot Angle:
    double getAngle();
    void setAngle(double angle);

    // Target Position:
    Point* getTarget();
    void setTarget(Point* target);

    // Velocity:
    MVector* getVelocity();
    void setVelocity(MVector* velocity);

    // Angular Velocity:
    double getAngularVelocity();
    void setAngularVelocity(double velocity);

    // Kick
    double getKick();
    void setKick(double kick);

    // Dribble
    double getDribble();
    void setDribble(double dribble);

    // Team Color:
    TeamColor getTeamColor();
    void setTeamColor(TeamColor color);

    // Field Side:
    FieldSide getFieldSide();
    void setFieldSide(FieldSide side);

    // Team's Goal Point:
    Point* getGoal();
    void setGoal(Point* goal);

    // Enemy Goal Point:
    Point* getEnemyGoal();
    void setEnemyGoal(Point* goal);

    // Ball Position;
    Point* getBallPosition();
    void setBallPosition(Point* ballPos);

    // Robot going to ball?
    bool getGoingToBall();
    void setGoingToBall(bool going);


    //**************************************
    //
    // Calc Functions
    //
    //*************************************
    void updateFieldPerceptions();
    bool isClosestToBall();
    void calculateDistances();
    double auxCalculateRobotDistances(double angle);
    void enemyObstacle(vector<double> *distances, Point *nextPoint);
    bool isEnemyInDirection(Point *nextPoint);
    void teamPartnerObstacle(vector<double> *distances, Point *nextPoint);
    void ballObstacle(vector<double> *distances, Point *nextPoint);
    void ourGoalObstacle(vector<double> *distances, Point *nextPoint);
    double getSmallerDistance(vector<double> *distances);
    double calculateAngleTo ();
    double calculateAngleTo(Point* anotherPoint);
    void calculateVelocities();
    Point *ballInterception();
    bool notCallFuzzy();
    void mapLinearVelocity();
    void mapAngularVelocity();
    double calculateMapLinearVelocity();
    double calculateMapAngularVelocity();
    void calcTargetAngle();
    void fuzzyLinearVelocity();
    bool foundObstacle();
    EnemyRobot *getEnemyKicker();
    EnemyRobot *getDangerousEnemy(double minY, double maxY);
    double auxDistanceToBall ( bool isLeftSide );
    double calculateMapKick();
    double calculateMapDribble();
    double calculateMapKickToPartner();
    void makeRobotShot();
    double enemyOnTheLine(Point *bPoint, Point *fPoint);
    double opossiteAngle(double &angle);
    double adjustAngle ( double &angle );
    void changeSideAngle ( double &angle );
    void changeSide ( double &angle );
    bool ballUpperField();
    int getFreePartnerId();



    //**************************************
    //
    // Virtual Methods
    //
    //*************************************

    void virtual setatPosX(float x) = 0;
    void virtual setatPosY(float y) = 0;
    void virtual setatAngle(float angle) = 0;
    void virtual setatPosToGoX(float x) = 0;
    void virtual setatPosToGoY(float y) = 0;
    void virtual setatAngleToGo(float angle) = 0;
    void virtual setatIsReady(bool isReady) = 0;
    void virtual setatBallEnemyField(bool value) = 0;
    void virtual setatBallPosY(float posX) = 0;
    void virtual setatClosestToBall(bool closer) = 0;
    void virtual setatEnemyOnGoalLine(bool value) = 0;
    void virtual setatDistanceToBall(float dist) = 0;
    void virtual setatBallDistTeamGoal(float dist) = 0;
    void virtual setatRefereeCmd(char cmd) = 0;
    void virtual setatLastRefereeCmd(char cmd) = 0;
    char virtual getatRefereeCmd() = 0;
    void virtual setatRole(string role) = 0;
    void virtual setatTeamSide(string side) = 0;
    void virtual setatTeamColor(string color) = 0;
    void virtual setatNumPlayers(int numPlayers) = 0;
    void virtual setatPartnerFreeID(int partnerId) = 0;
    int virtual getatPartnerFreeID() = 0;
    void virtual setatSetPassBall(bool value)= 0;
};

#endif // BASEROBOT_H
