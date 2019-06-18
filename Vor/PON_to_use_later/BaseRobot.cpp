#include "BaseRobot.h"
#include "CommunicationSystem.h"
#include "RobocupConsts.h"

BaseRobot::BaseRobot() : ANGLE_DIRECTION ( 40 * PI / 180), RADIUS(590) {
}

void BaseRobot::initRobot(int id, int number, TeamColor color, FieldSide side, CommunicationSystem *comSystem, Team* team)
{
    this->id = id;
    this->fieldSide = side;
    this->number = number;
    this->team = team;
    this->teamColor = color;
    this->position = new Point();
    this->ball = new Ball();

    // Velocity:
    this->velocity = new MVector();

    // Environment Perception:
    this->distances = new double[ROBOT_DISTANCES];

    // Assign Communication system
    this->comSystem = comSystem;

    // Team and Enemy Robots:
    this->teamRobots = new vector<BaseRobot*>();
    this->enemyRobots = new vector<EnemyRobot*>();

    // Fuzzy LIBS
    LoadDynamicLibrary *loadLib = new LoadDynamicLibrary ;
    fuzzyController = loadLib->loadLibFlie();
    rangeHigh = fuzzyController->getRHigh();

    // Init Goals:
    initGoals(side);

    // Init Field Settings:
    initFieldSettings(side);
}

// init goals based on team's field side.
void BaseRobot::initGoals(FieldSide side)
{
    if (side == LEFT)
    {
        ownGoal = new Point(-3025, 0);
        enemyGoal = new Point(3025, 0);
    }
    else
    {
        ownGoal = new Point(3025, 0);
        enemyGoal = new Point(-3025, 0);
    }
}

// Init Field Settings
void BaseRobot::initFieldSettings(FieldSide side)
{
    int DIST_MIN = 500;
    this->distanceForBall = DIST_MIN + ROBOT_RADIUS;
    this->distanceToBallEnemy = this->distanceForBall + ROBOT_RADIUS;    
    this->fieldHorizontalMin = -3025;
    this->fieldHorizontalMax = 3025;
    this->fieldVerticalMin = -2025;
    this->fieldVerticalMax = 2025;
    this->penaltyMark = 750;
    this->penaltyGoalPoint = 200;
    this->robotDistancePenalty = penaltyMark + 400;

    this->distToBallAngle2Pl = atan2 ( 2.2 * ROBOT_RADIUS, this->distanceForBall );
    this->distToBallAngle3Pl = atan2 ( 4.7 * ROBOT_RADIUS, this->distanceForBall);

    this->goalWidth = 700;

    this->goalkeeperAreaRadius = 800;
    this->distanceMinStop = 1800;
    this->distanceGoalMin = goalWidth /2 + 2 * ROBOT_RADIUS;
    this->strickerDistance = DIST_MIN + ROBOT_RADIUS;
    this->distMidfieldAttacking = 1400 + ROBOT_RADIUS;
    this->distMinToOurGoal = goalkeeperAreaRadius + ROBOT_RADIUS_ERROR;

    this->kickMax = 8.0;
    if (side == LEFT)
    {
        this->goalkeeperPenalty = fieldHorizontalMin + 65;
        goalPostLeft = new Point ( getGoal()->getPointX(), goalWidth / 2 );
        goalPostRight = new Point ( getGoal()->getPointX(), - (goalWidth / 2) );
        enemyGoalPostLeft = new Point ( getEnemyGoal()->getPointX(), - (goalWidth / 2) );
        enemyGoalPostRight = new Point ( getEnemyGoal()->getPointX(), (goalWidth / 2) );
    }
    else
    {
        this->goalkeeperPenalty = fieldHorizontalMax - 65;
        goalPostLeft = new Point ( getGoal()->getPointX(), - (goalWidth / 2) );
        goalPostRight = new Point ( getGoal()->getPointX(), goalWidth / 2 );
        enemyGoalPostLeft = new Point ( getEnemyGoal()->getPointX(), (goalWidth / 2) );
        enemyGoalPostRight = new Point ( getEnemyGoal()->getPointX(), -(goalWidth / 2) );
    }
}

/**************************************
  *************************************
  GETTER and SETTERS:
  *************************************
  *************************************/

int BaseRobot::getId() {
    return this->id;
}

int BaseRobot::getNumber() {
    return this->number;
}

Team* BaseRobot::getTeam(){
    return this->team;
}

void BaseRobot::setPlayerRole(PlayerRole role) {
    this->role = role;
    switch(role) {
        case GOALKEEPER:
            this->setatRole("GOALKEEPER");
            break;
        case GOALKEAPER_ONLY:
            this->setatRole("GOALKEAPER_ONLY");
            break;
        case DEFENDER_ONLY:
            this->setatRole("DEFENDER_ONLY");
            break;
        case DEFENDER_LEFT:
            this->setatRole("DEFENDER_LEFT");
            break;
        case DEFENDER_RIGHT:
            this->setatRole("DEFENDER_RIGHT");
            break;
        case MIDFIELD_ONLY:
            this->setatRole("MIDFIELD_ONLY");
            break;
        case STRIKER_ONLY:
            this->setatRole("STRIKER_ONLY");
            break;
        case STRIKER_LEFT:
            this->setatRole("STRIKER_LEFT");
            break;
        case STRIKER_RIGHT:
            this->setatRole("STRIKER_RIGHT");
            break;

    }
}

BaseRobot::PlayerRole BaseRobot::getPlayerRole() {
    return this->role;
}

vector<BaseRobot*>* BaseRobot::getTeamRobots() {
    return this->teamRobots;
}

vector<BaseRobot*>* BaseRobot::getTeamPartners() {
    vector<BaseRobot*>* partners = new vector<BaseRobot*>;
    BaseRobot* robot;

    for (int i = 0; i < this->getTeamRobots()->size(); i++) {
        robot = this->getTeamRobots()->at(i);
        if (robot->getId() != this->getId() &&
            robot->getPlayerRole() != GOALKEEPER &&
            robot->getPlayerRole() != DEFENDER_LEFT &&
            robot->getPlayerRole() != DEFENDER_RIGHT) {

            partners->push_back(robot);
        }
    }

    return partners;
}

BaseRobot* BaseRobot::getTeamPartnerById(int id) {
    BaseRobot* robot;
    for (int i = 0; i < this->getTeamRobots()->size(); i++) {

        robot = teamRobots->at(i);
        if (robot->getId() == id) {        
            return robot;
        }
    }

    return NULL;
}

void BaseRobot::setTeamRobots(vector<BaseRobot*> *robots) {
    this->teamRobots = robots;
}

vector<EnemyRobot*>* BaseRobot::getEnemyRobots() {
    return this->enemyRobots;
}

void BaseRobot::setEnemyRobots(vector<EnemyRobot*> *robots) {
    this->enemyRobots = robots;
}

Point* BaseRobot::getPosition() {
    return this->position;
}

void BaseRobot::setPosition(Point* position) {
    this->position = position;

    this->setatPosX(position->getPointX());
    this->setatPosY(position->getPointY());

    calcTargetAngle();
}

Point* BaseRobot::getPosToGo() {
    return this->posToGo;
}

void BaseRobot::setPosToGo(Point* position) {
    this->posToGo = position;

    this->setatPosToGoX(position->getPointX());
    this->setatPosToGoY(position->getPointY());
}

double BaseRobot::getAngle() {
    return this->angle;
}

void BaseRobot::setAngle(double angle) {
    this->angle = angle;
    this->setatAngle(angle);
}

Point* BaseRobot::getTarget() {
    return this->target;
}

void BaseRobot::setTarget(Point* target) {
    this->target = target;
    this->calcTargetAngle();
}

MVector* BaseRobot::getVelocity() {
    return this->velocity;
}

void BaseRobot::setVelocity(MVector* velocity) {
    this->velocity = velocity;
}

double BaseRobot::getAngularVelocity() {
    return this->angularVelocity;
}

void BaseRobot::setAngularVelocity(double velocity) {
    this->angularVelocity = velocity;
}

double BaseRobot::getKick() {
    return this->kick;
}

void BaseRobot::setKick(double kick) {
    this->kick = kick;
}

double BaseRobot::getDribble() {
    return this->dribble;
}

void BaseRobot::setDribble(double dribble) {
    this->dribble = dribble;
}

TeamColor BaseRobot::getTeamColor() {
    return this->teamColor;
}

void BaseRobot::setTeamColor(TeamColor color) {
    this->teamColor = color;

    if (this->teamColor == BLUE)
        this->setatTeamColor("BLUE");
    else
        this->setatTeamColor("YELLOW");
}

FieldSide BaseRobot::getFieldSide() {
    return this->fieldSide;
}

void BaseRobot::setFieldSide(FieldSide side) {
    this->fieldSide = side;
}

Point* BaseRobot::getGoal() {
    return this->ownGoal;
}

void BaseRobot::setGoal(Point* goal) {
    this->ownGoal = goal;
}

Point* BaseRobot::getEnemyGoal() {
    return this->enemyGoal;
}

void BaseRobot::setEnemyGoal(Point* goal) {
    this->enemyGoal = goal;
}

Point* BaseRobot::getBallPosition() {
    return this->ball->getPosition();
}

void BaseRobot::setBallPosition(Point* ballPos) {
    this->ball->setPosition(ballPos);    
    this->setatBallPosY(ballPos->getPointY());
    this->setatDistanceToBall(this->getPosition()->getDistanceTo(ballPos));
    this->setatBallDistTeamGoal(this->ball->getPosition()->getDistanceTo(this->getGoal()));

    if (this->getFieldSide() == LEFT) {
        this->setatBallEnemyField(ballPos->getPointX() > 0);
    } else {
        this->setatBallEnemyField(ballPos->getPointX() < 0);
    }
}

bool BaseRobot::getGoingToBall() {
    return this->goingToBall;
}

void BaseRobot::setGoingToBall(bool going) {
    this->goingToBall = going;
}


/**************************************
***************************************
        Communication METHOD
***************************************
***************************************/

void BaseRobot::sendCommand() {
    this->comSystem->sendCommand(this);
}

/**************************************
***************************************
  Robot Status Methods
***************************************
***************************************/

bool BaseRobot::isReady() {
    if (this->posToGo == NULL)
        return false;

    return (this->getPosition()->getDistanceTo ( this->posToGo ) < ROBOT_RADIUS &&
            this->getAngularVelocity() == 0.0 &&
            this->getVelocity()->getModule() == 0.0);
}


/**************************************
***************************************
            PON METHODS
***************************************
***************************************/

void BaseRobot::executeMove() {
    if (posToGo != NULL && target != NULL)
    {
        calculateDistances ();
        calculateVelocities();
        sendCommand();
    }
}

void BaseRobot::angleMove() {
    mapAngularVelocity();
    sendCommand();
}

void BaseRobot::resetKickAndDribble() {
    this->setKick(0.0);
    this->setDribble(0.0);
    this->setGoingToBall(false);    
    this->setatSetPassBall(false);
}

void BaseRobot::behaviorGkBallOutsideArea() {
    double dist = this->getBallPosition()->getDistanceTo( this->getGoal() );
    double angleBall = this->ball->getVelocity()->getAngle();
    double valueY = this->ball->getPosition()->getPointY()  + dist * sin ( angleBall );

    changeSideAngle ( angleBall );

    Point *position;
    if ( abs ( valueY ) <= ( goalkeeperAreaRadius + ROBOT_RADIUS_ERROR ) / 2 &&
         this->ball->getVelocity()->getModule() > 0
         && abs ( angleBall ) > PI / 2 )
    {
        dist = 0;
        double oppAngle = this->ball->getVelocity()->getOppositeAngle();
        double rectX = this->getGoal()->getPointX() + dist * cos ( oppAngle );
        double rectY = valueY + dist * sin ( oppAngle );

        position = new Point ( rectX, rectY );

        this->setTarget(this->getBallPosition());
        this->setPosToGo(position);
    }
    else
    {
        double angle = this->getGoal()->calculateAngleTo ( this->getBallPosition() );
        position = new Point (    this->getGoal()->getPointX() + distanceGoalMin * cos ( angle ),
                                this->getGoal()->getPointY() + distanceGoalMin * sin ( angle ) );

        this->setTarget(this->getBallPosition());
        this->setPosToGo(position);
    }
}

void BaseRobot::behaviorGkPenalty() {   

    EnemyRobot *kicker = getEnemyKicker();
    double x = this->goalkeeperPenalty;

    this->setTarget(this->getBallPosition());
    this->changeSide(x);    

    if ( kicker != NULL )
    {
        double y = this->penaltyMark * sin ( kicker->getAngle() );
        this->setPosToGo(new Point ( x, y ));
    }
    else
    {
        this->setPosToGo(new Point ( x, 0 ));
    }
}

void BaseRobot::moveToStopPosition() {
    double angle = this->getGoal()->calculateAngleTo( this->getBallPosition() );
    Point *position = new Point (   this->getBallPosition()->getPointX() - distanceForBall * cos ( angle ),
                                    this->getBallPosition()->getPointY() - distanceForBall* sin ( angle ) );
    moveToStopPosition(position);
}

void BaseRobot::moveToStopPositionPositiveAngle() {
    double angle = this->getGoal()->calculateAngleTo( this->getBallPosition() );
    Point *position = new Point (   this->getBallPosition()->getPointX() - distanceForBall * cos ( angle + this->distToBallAngle2Pl ),
                                    this->getBallPosition()->getPointY() - distanceForBall* sin ( angle + this->distToBallAngle2Pl ) );
    moveToStopPosition(position);
}

void BaseRobot::moveToStopPositionPositiveAngle3pl() {
    double angle = this->getGoal()->calculateAngleTo( this->getBallPosition() );
    Point *position = new Point (   this->getBallPosition()->getPointX() - distanceForBall * cos ( angle + this->distToBallAngle3Pl ),
                                    this->getBallPosition()->getPointY() - distanceForBall* sin ( angle + this->distToBallAngle3Pl ) );
    moveToStopPosition(position);
}

void BaseRobot::moveToStopPositionNegativeAngle() {
    double angle = this->getGoal()->calculateAngleTo( this->getBallPosition() );
    Point *position = new Point (   this->getBallPosition()->getPointX() - distanceForBall * cos ( angle - this->distToBallAngle2Pl ),
                                    this->getBallPosition()->getPointY() - distanceForBall* sin ( angle - this->distToBallAngle2Pl ) );
    moveToStopPosition(position);
}

void BaseRobot::moveToStopPositionNegativeAngle3pl() {
    double angle = this->getGoal()->calculateAngleTo( this->getBallPosition() );
    Point *position = new Point (   this->getBallPosition()->getPointX() - distanceForBall * cos ( angle - this->distToBallAngle3Pl ),
                                    this->getBallPosition()->getPointY() - distanceForBall* sin ( angle - this->distToBallAngle3Pl ) );
    moveToStopPosition(position);
}

void BaseRobot::moveToStopPosition(Point* position) {    
    this->setTarget(this->getBallPosition());
    this->setPosToGo(position);
}

void BaseRobot::moveToLeftPost() {    
    double angle = this->goalPostLeft->calculateAngleTo(this->getBallPosition());
    double dist = auxDistanceToBall(true);
    Point *position = new Point( this->goalPostLeft->getPointX() + dist * cos ( angle ),
                                 this->goalPostLeft->getPointY() + dist * sin ( angle ) );

    this->setPosToGo(position);
    this->setTarget(this->getBallPosition());
}

void BaseRobot::moveToRightPost() {
    double angle = this->goalPostRight->calculateAngleTo(this->getBallPosition());
    double dist = auxDistanceToBall(false);
    Point *position = new Point( this->goalPostRight->getPointX() + dist * cos ( angle ),
                                 this->goalPostRight->getPointY() + dist * sin ( angle ) );

    this->setPosToGo(position);
    this->setTarget(this->getBallPosition());
}

void BaseRobot::moveToKickPosition() {
   double angle = this->getBallPosition()->calculateAngleTo ( this->getEnemyGoal());
   Point *position = new Point ( this->getBallPosition()->getPointX() - ROBOT_RADIUS_ERROR * cos ( angle ),
                                 this->getBallPosition()->getPointY() - ROBOT_RADIUS_ERROR * sin ( angle ) );
   this->setPosToGo(position);
   this->setTarget(this->getEnemyGoal());
   this->mapAngularVelocity();
}

void BaseRobot::moveToDirectKickPosition() {
    moveToKickPosition();
    this->makeRobotShot();
}

void BaseRobot::moveToIndirectKickPosition() {
    BaseRobot *partner= getTeamPartnerById( getFreePartnerId() );
    if (partner == NULL) return;

    double angle = this->getBallPosition()->calculateAngleTo ( partner->getPosToGo());

    if (angle == NULL) {
        angle = this->getBallPosition()->calculateAngleTo( partner->getPosition() );
    }

    Point *position = new Point ( this->getBallPosition()->getPointX() - 1.3*ROBOT_RADIUS_ERROR * cos ( angle ),
                                  this->getBallPosition()->getPointY() - 1.3*ROBOT_RADIUS_ERROR * sin ( angle ) );

    this->setTarget(partner->getPosition());
    this->setPosToGo(position);

    if (this->isReady() && this->ball->getVelocity()->getModule() < 10.0) {
        this->setatSetPassBall(true);
    }
}

void BaseRobot::markEnemyPositiveY() {
    markEnemy(0, fieldVerticalMax);
}

void BaseRobot::markEnemyNegativeY() {
    markEnemy(fieldVerticalMin, 0);
}

void BaseRobot::moveStrikerPositionLeft() {    
    positionStricker(enemyGoalPostLeft, distMidfieldAttacking, strickerDistance, 160, 220);
}

void BaseRobot::moveStrikerPositionRight() {
    positionStricker(enemyGoalPostRight, goalWidth / 2 + ROBOT_RADIUS, goalWidth / 2 + 3 * ROBOT_RADIUS, 100, 140);
}

void BaseRobot::positionStricker(Point *enemyPostPosition, double dist_min, double dist_max, double angle_min, double angle_max) {
    double angle = this->getBallPosition()->calculateAngleTo ( this->getEnemyGoal() );
    opossiteAngle ( angle );
    Point *position;

    if ( abs ( angle * 180 / PI ) < 10 )
    {
        angle = abs ( angle * 180 / PI );
        angle = UtilGame::m_map ( angle, 0, 10, 170, 150 ) * PI / 180;
        opossiteAngle ( angle );
        position = new Point (  enemyPostPosition->getPointX() + strickerDistance * cos ( angle ),
                                enemyPostPosition->getPointY() + strickerDistance * sin ( angle ) );

        this->setTarget(this->getBallPosition());
        this->setPosToGo(position);
    }
    else
    {
        double dist;
        angle = abs ( angle * 180 / PI );
        dist =  UtilGame::m_map ( angle, 10, 90, dist_min, dist_max  );
        angle = UtilGame::m_map ( angle, 10, 90, angle_min, angle_max ) * PI / 180;
        adjustAngle ( angle );
        changeSideAngle ( angle );
        position = new Point (  this->getEnemyGoal()->getPointX() + dist * cos ( angle ),
                                this->getEnemyGoal()->getPointY() + dist * sin ( angle ) );

        this->setTarget(this->getBallPosition());
        this->setPosToGo(position);
    }
}

void BaseRobot::movePenaltyAttackLeftPosition() {
    movePenaltyAttackPosition(1);
}

void BaseRobot::movePenaltyAttackRightPosition() {
    movePenaltyAttackPosition(2);
}

void BaseRobot::movePenaltyAttackPosition(int index) {
    double distanceLine = robotDistancePenalty;
    this->changeSide(distanceLine);

    distanceLine = this->getEnemyGoal()->getPointX() - distanceLine;

    Point *position = new Point ( distanceLine, UtilGame::m_map ( index, 0, 2 + 1, fieldHorizontalMin, fieldHorizontalMax ) );

    this->setTarget(this->getEnemyGoal());
    this->setPosToGo(position);
}

void BaseRobot::movePenaltyDefenseLeftPosition() {
    movePenaltyDefensePosition(1);
}

void BaseRobot::movePenaltyDefenseRightPosition() {
    movePenaltyDefensePosition(3);
}

void BaseRobot::movePenaltyDefenseCenterPosition() {
    movePenaltyDefensePosition(2);
}

void BaseRobot::movePenaltyDefensePosition(int index) {
    double distanceLine = robotDistancePenalty;
    this->changeSide(distanceLine);
    distanceLine += this->getGoal()->getPointX();

    Point *position = new Point ( distanceLine, UtilGame::m_map ( index, 0, 3 + 1, fieldHorizontalMin, fieldHorizontalMax ) );

    this->setTarget(this->getGoal());
    this->setPosToGo(position);
}

void BaseRobot::markEnemy() {
    markEnemy(fieldVerticalMin, fieldVerticalMax);
}

void BaseRobot::markEnemy(double yMin, double yMax) {
    EnemyRobot* dangerEnemy = getDangerousEnemy(yMin, yMax);

    if (dangerEnemy != NULL) {
        double angle = dangerEnemy->getPosition()->calculateAngleTo(this->getBallPosition());
        Point* position = new Point ( dangerEnemy->getPosition()->getPointX() + 2 * ROBOT_RADIUS_ERROR * cos ( angle ),
                                        dangerEnemy->getPosition()->getPointY() + 2 * ROBOT_RADIUS_ERROR * sin ( angle ));

        this->setPosToGo(position);
        this->setTarget(this->getBallPosition());
    }
}

void BaseRobot::readyKickoff() {
    this->setDribble(calculateMapDribble());
    this->setKick(calculateMapKick());
    this->setPosToGo ( target );
    this->mapAngularVelocity();

    // Forget the last Referee Command:
    this->setatLastRefereeCmd(this->getatRefereeCmd());
}

void BaseRobot::positionKickPenalty() {
    double y = penaltyGoalPoint;
    double x = this->getEnemyGoal()->getPointX();
    if ( rand() % 2 )
            y *= -1;

    Point *target = new Point ( x, y );

    double angle = this->getBallPosition()->calculateAngleTo (target);
    Point *position = new Point ( this->getBallPosition()->getPointX() - ROBOT_RADIUS_ERROR * cos ( angle ),
                                  this->getBallPosition()->getPointY() - ROBOT_RADIUS_ERROR * sin ( angle ) );

    this->setPosToGo(position);
    this->setTarget ( target );
    this->mapAngularVelocity();
}

void BaseRobot::readyPenalty() {    
    this->setPosToGo(this->getTarget());
    this->mapLinearVelocity();
    this->setKick(kickMax);

    // Forgot the last Referee Command:
    this->setatLastRefereeCmd(this->getatRefereeCmd());
}

void BaseRobot::positionTopassBallPartner() {
    BaseRobot* partner = getTeamPartnerById(this->getatPartnerFreeID());
    if (partner == NULL) return;

    double angle = this->getBallPosition()->calculateAngleTo ( partner->getPosToGo() );
    Point *position =
             new Point ( this->getBallPosition()->getPointX() - (ROBOT_RADIUS_ERROR-5) * cos ( angle ),
                         this->getBallPosition()->getPointY() - (ROBOT_RADIUS_ERROR-5) * sin ( angle ) );

    this->setTarget(partner->getPosToGo());
    this->setPosToGo(position);
    this->mapAngularVelocity();
}

void BaseRobot::passBallPartner() {
        this->setKick(calculateMapKickToPartner());
        this->setPosToGo ( this->getBallPosition() );
        this->setGoingToBall(true);
}

void BaseRobot::targetToBall() {
    this->setTarget(this->getBallPosition());
    mapAngularVelocity();
}

void BaseRobot::moveRightWarmUpPos() {
    Point *position = new Point( 0, this->fieldVerticalMin/4);
    this->setPosToGo(position);
    this->setTarget(this->getBallPosition());
}

void BaseRobot::moveLeftWarmUpPos() {
    Point *position = new Point( 0, this->fieldVerticalMax/4);
    this->setPosToGo(position);
    this->setTarget(this->getBallPosition());
}

/**************************************
***************************************
  Auxiliary calculus functions
***************************************
***************************************/

void BaseRobot::updateFieldPerceptions() {
    /*if (this->getatRefereeCmd() == ' ') {
        bool closeToBall = isClosestToBall();

        this->setatClosestToBall(closeToBall);

        if (closeToBall) {
            this->setatPartnerFreeID(getFreePartnerId());
        }
    }*/
    bool closeToBall = isClosestToBall();

    this->setatClosestToBall(closeToBall);

    this->setatPartnerFreeID(getFreePartnerId());

    this->setatIsReady(this->isReady());
}

bool BaseRobot::isClosestToBall() {
    double currentDistance = this->getPosition()->getDistanceTo(this->getBallPosition());
    BaseRobot *robot;

    for(int i = 0 ; i < this->getTeamRobots()->size(); i ++) {
        robot = this->getTeamRobots()->at(i);

        if (    robot->getId() != this->getId() &&
                robot->getPosition()->getDistanceTo(this->getBallPosition()) < currentDistance)  {
            return false;
        }
    }

    return true;
}

void BaseRobot::calculateDistances() {
    /*if ( this->isReady() )
            return;*/

    distances [ DIR_FORWARD ] = this->auxCalculateRobotDistances ( 0 );
    distances [ DIR_LEFT ] = this->auxCalculateRobotDistances ( ANGLE_DIRECTION );
    distances [ DIR_RIGHT ] = this->auxCalculateRobotDistances ( -ANGLE_DIRECTION );
}

double BaseRobot::auxCalculateRobotDistances(double angle)
{
    Point *nextPoint = this->getPosition();
    double distPosToGo = this->getPosition()->getDistanceTo ( this->getPosToGo() );
    double finalAngle = this->getPosition()->calculateAngleTo ( this->getPosToGo() ) + angle;

    UtilGame::adjustAngle ( finalAngle );

    Point *fPoint = new Point ( this->getPosition()->getPointX() + distPosToGo * cos ( finalAngle ),
                                this->getPosition()->getPointY() + distPosToGo * sin ( finalAngle ) );

    vector <double> *distances = new vector <double>;
    while ( nextPoint->getDistanceTo ( fPoint ) > ROBOT_RADIUS )
    {
        this->enemyObstacle ( distances, nextPoint );
        this->teamPartnerObstacle ( distances, nextPoint );
        this->ballObstacle ( distances, nextPoint );
        this->ourGoalObstacle ( distances, nextPoint );
        nextPoint = new Point ( nextPoint->getPointX() + ROBOT_RADIUS * cos ( finalAngle ),
                                nextPoint->getPointY() + ROBOT_RADIUS * sin ( finalAngle ) );
    }


    if ( distances->size() > 0 )
        return getSmallerDistance ( distances );
    return -1;
}

void BaseRobot::enemyObstacle(vector<double> *distances, Point *nextPoint)
{
    int size = enemyRobots->size();
    for ( int i = 0; i < size; i++ )
    {
        EnemyRobot* enemyRobot = enemyRobots->at(i);
        if ( enemyRobot->getPosition()->getDistanceTo ( nextPoint ) <= ROBOT_DIAMETER )
        {
            distances->push_back ( this->getPosition()->getDistanceTo ( enemyRobot->getPosition() ) );
        }
    }
}

bool BaseRobot::isEnemyInDirection(Point *nextPoint) {
    int size = enemyRobots->size();
    for ( int i = 0; i < size; i++ )
    {
        EnemyRobot* enemyRobot = enemyRobots->at(i);
        if ( enemyRobot->getPosition()->getDistanceTo ( nextPoint ) <= this->RADIUS )
        {
            return true;
        }
    }

    return false;
}

void BaseRobot::teamPartnerObstacle(vector<double> *distances, Point *nextPoint)
{
    vector < BaseRobot * > *team_robots = teamRobots;
    int size = team_robots->size();
    for ( int i = 0; i < size; i++ )
    {
        if (this->getId() != i) {
            if ( team_robots->at ( i )->getPosition()->getDistanceTo ( nextPoint ) <= ROBOT_DIAMETER )
            {
                distances->push_back ( this->getPosition()->getDistanceTo ( team_robots->at ( i )->getPosition() ) );
            }
        }
    }
}

void BaseRobot::ballObstacle(vector<double> *distances, Point *nextPoint)
{
    double dist = nextPoint->getDistanceTo ( this->getBallPosition());
    if ( !this->getGoingToBall() )
        if ( dist <= ROBOT_DIAMETER ) {
            distances->push_back ( this->getPosition()->getDistanceTo ( this->getBallPosition()) );
        }
}

void BaseRobot::ourGoalObstacle(vector<double> *distances, Point *nextPoint)
{
    double dist = nextPoint->getDistanceTo ( this->getGoal() );
    if ( dist <= FieldSetting::GK_AREA_RADIUS)
    {
        distances->push_back ( this->getPosition()->getDistanceTo ( this->getGoal() ) );
    }
}

double BaseRobot::getSmallerDistance(vector<double> *distances)
{
    double dist = distances->at ( 0 );
    double size = distances->size();
    for ( int i = 1; i < size; i++ )
        if ( dist > distances->at ( i ) )
            dist = distances->at ( i );
    return dist;
}

double BaseRobot::calculateAngleTo ()
{
    Point *goal_1 = new Point ( -3025, 0 );
    Point* ballPosition = this->getBallPosition();
    double x = ballPosition->getPointX() - goal_1->getPointX();
    double y = ballPosition->getPointY() - goal_1->getPointY();
    return atan2( y , x );
}

double BaseRobot::calculateAngleTo(Point* anotherPoint) {
    if ((anotherPoint == NULL) || (getPosition() == NULL))  return 0;

    double angle = this->getPosition()->calculateAngleTo( anotherPoint ) - this->getAngle();
    UtilGame::adjustAngle( angle );
    return angle;
}

void BaseRobot::calculateVelocities()
{
    Point *pointIntercp = this->ballInterception();
    if ( pointIntercp != NULL )
    {
        this->setPosToGo ( pointIntercp );
        this->setTarget ( this->getEnemyGoal() );
    }

   if ( notCallFuzzy() )
    {
        this->mapLinearVelocity();
    }
    else
    {        
        this->fuzzyLinearVelocity();
        this->mapAngularVelocity();
    }
}

Point *BaseRobot::ballInterception()
{
    Ball *ball = this->ball;
    if ( ball->getVelocity()->getModule() > 0 )
    {
        double angleBall = ball->getVelocity()->getAngle();
        double angleRobot = this->getPosition()->calculateAngleTo ( ball->getPosition() );
        if ( ( angleBall < 0 && angleRobot > 0 ) || ( angleBall > 0 && angleRobot < 0 ) )// bola está se aproximando da posição do robô
        {
//            if ( robot->getId() != 0 )//teste
//                cout << "vao colidir !!!!!!!!\n";
            Point *nextPoint = ball->getPosition();
            double distToRobot = this->getPosition()->getDistanceTo ( nextPoint );

            Point *fPoint = new Point ( nextPoint->getPointX() + distToRobot * cos ( angleBall ),
                                        nextPoint->getPointY() + distToRobot * sin ( angleBall ) );

            while ( nextPoint->getDistanceTo ( fPoint ) > ROBOT_RADIUS )
            {

                double dist = nextPoint->getDistanceTo ( this->getPosition() );

                if ( dist <= ROBOT_DIAMETER )
                {
                    return nextPoint;
                }

                nextPoint = new Point ( nextPoint->getPointX() + ROBOT_DIAMETER * cos ( angleBall ),
                                        nextPoint->getPointY() + ROBOT_DIAMETER * sin ( angleBall ) );
            }
        }
    }
    return NULL;
}

bool BaseRobot::notCallFuzzy()
{
    double distToPos = this->getPosition()->getDistanceTo ( this->getPosToGo() );

    return( !this->foundObstacle() || //nao achou nenhum obstaculo
            distances [ DIR_FORWARD ] < 0 || //achou algum obstaculo, mas o sensor da frente não
            distToPos < ROBOT_DIAMETER ||
            this->getGoingToBall() ||
            this->getVelocity()->getModule() <= MIN_VEL_FUZZY
           );
}

void BaseRobot::mapLinearVelocity ()
{
    double angDistance = this->calculateAngleTo ( this->getPosToGo() );
    double velocityMod = this->calculateMapLinearVelocity ();    

    this->getVelocity()->setTangentialDirection( velocityMod * cos ( angDistance ) );
    this->getVelocity()->setNormalDirection( velocityMod * sin ( angDistance ) );
}


void BaseRobot::mapAngularVelocity()
{
    double velocityAng = calculateMapAngularVelocity ();
    this->setAngularVelocity ( velocityAng);
}

double BaseRobot::calculateMapLinearVelocity()
{
    double velocity = 0.0;
    double distance = this->getPosition()->getDistanceTo ( this->getPosToGo() );    
    int velocityMax = 4;

    if ( distance > 2000 )
        velocity = velocityMax;
    else if ( distance < 15 )
        velocity = 0;
    else
        velocity = UtilGame::m_map ( distance, 0, 2000, 0.3, velocityMax );

    return velocity;
}

double BaseRobot::calculateMapAngularVelocity()
{
    double velocityAng = 0;
    double distMin;
    double distanceAngularBall = this->calculateAngleTo ( this->getTarget() ) * 180 / PI;

    if ( this->getBallPosition()->pointIsOnOurSide() )
        distMin = ControllerSettings::ANGLE_MIN_OUR_SIDE;
    else
        distMin = ControllerSettings::ANGLE_MIN;

    if ( abs ( distanceAngularBall ) > 90 )
        velocityAng = UtilGame::m_map ( abs ( distanceAngularBall ), 90, 180, 4, 8 );
    else if ( abs ( distanceAngularBall ) > 40 )
        velocityAng = UtilGame::m_map ( abs ( distanceAngularBall ), 40, 90, 2, 4 );
    else if ( abs ( distanceAngularBall ) > distMin )
        velocityAng = UtilGame::m_map ( abs ( distanceAngularBall ), distMin, 40, 1, 2 );
    return velocityAng * distanceAngularBall / abs ( distanceAngularBall );
}

void BaseRobot::calcTargetAngle() {
    double angleToTarget = this->calculateAngleTo ( this->getTarget() ) * 180 / PI;
    setatAngleToGo(angleToTarget);
}

void BaseRobot::fuzzyLinearVelocity()
{
    float flie_velocity, flie_direction;
    float se, sf, sd;//sensores virtuais
    double *distances = this->distances;

    if ( distances [ DIR_FORWARD ] < 0 || distances [ DIR_FORWARD ] > rangeHigh ||
         ( this->getPosition()->getDistanceTo ( this->getPosToGo() ) + ROBOT_RADIUS ) > rangeHigh )
        sf = rangeHigh;
    else
        sf = distances [ DIR_FORWARD ];

    se = distances [ DIR_LEFT ] <  0 || distances [ DIR_LEFT ] > rangeHigh ?  rangeHigh : distances [ DIR_LEFT ];
    sd = distances [ DIR_RIGHT ] <  0 || distances [ DIR_RIGHT ] > rangeHigh ?  rangeHigh : distances [ DIR_RIGHT ];

    fuzzyController->inference( se, sf, sd, flie_velocity, flie_direction );
    flie_direction -= 90;// a direcao esta definida entre 0 e 180 graus na logica fuzzy, correspondendo 90 a frente
    flie_direction *=  PI / 180;//conversão para radianos

    double angle = this->calculateAngleTo ( this->getPosToGo() ) + flie_direction;

    this->getVelocity()->setNormalDirection ( flie_velocity * sin ( angle ) );
    this->getVelocity()->setTangentialDirection ( flie_velocity * cos ( angle ) );
}

bool BaseRobot::foundObstacle()
{
    for ( int i = 0; i < ROBOT_DISTANCES; i++ )
        if (    distances [i] > 0 &&
                distances [ i ] <= fuzzyController->getRHigh() )
        {
            return true;            
        }
    return false;
}

EnemyRobot* BaseRobot::getEnemyKicker() {
    vector < EnemyRobot * > *enemies = this->getEnemyRobots();
    EnemyRobot *kicker = NULL;

    for ( int i = 0; i < enemies->size(); i++ )
        if ( enemies->at ( i )->getPosition()->getDistanceTo ( this->getBallPosition() ) <= RobocupConsts::KICKER_DISTANCE )
            kicker = enemies->at ( i );
    return kicker;
}

EnemyRobot* BaseRobot::getDangerousEnemy(double minY, double maxY) {
    vector < EnemyRobot * > * enemies = this->getEnemyRobots();
    int smallerDistanceFound =  INFINITE;

    EnemyRobot *kicker = NULL;

    for ( int i = 0; i < enemies->size(); i++ ) {
        int distToGoal = enemies->at(i)->getPosition()->getDistanceTo(this->getGoal());   
        int distToBall = enemies->at(i)->getPosition()->getDistanceTo(this->getBallPosition());
        double posY = enemies->at(i)->getPosition()->getPointY();

        if ( posY >= minY &&
             posY <= maxY &&
             //distToBall > distanceToBallEnemy &&
             distToGoal < smallerDistanceFound &&
             distToGoal < (RobocupConsts::HALF_FIELD_SIZE_HORIZONTAL - 2 * ROBOT_RADIUS) ) {

            kicker = enemies->at(i);
            smallerDistanceFound = distToGoal;

        }
    }

    return kicker;
}

double BaseRobot::auxDistanceToBall ( bool isLeftSide )
{
    double angle;
    if ( isLeftSide )
        angle = this->goalPostLeft->calculateAngleTo( this->getBallPosition() );
    else
        angle = this->goalPostRight->calculateAngleTo( this->getBallPosition() );

    double dist;
    double a = goalWidth / 2;
    double b = this->distMinToOurGoal + ROBOT_RADIUS;// "+ ROBOT_RADIUS" = gambiarra para não entrar na área do goleiro

    if ( isLeftSide )
    {
        if ( angle < 0 )
            angle = PI / 2 - abs ( angle );
        else
            angle = PI / 2 + abs ( angle );
    }
    else
    {
        if ( angle < 0 )
            angle = PI / 2 + abs ( angle );
        else
            angle = PI / 2 - abs ( angle );
    }
    double k = -2 * a * cos ( angle );
    double w = -b * b + a * a;
    dist = ( -k + sqrt ( k * k - 4 * w ) ) / 2;//baskara
    return dist;
}

double BaseRobot::calculateMapKick() {
    double distance = this->getPosition()->getDistanceTo ( this->getTarget() );
    return UtilGame::m_map ( distance, 2 * ROBOT_RADIUS_ERROR,
                               2 * fieldHorizontalMax, 4, kickMax);
}

double BaseRobot::calculateMapDribble() {
    double distance = this->getPosition()->getDistanceTo ( this->getTarget() );
    return UtilGame::m_map ( distance, 2 * ROBOT_RADIUS_ERROR,
                               2 * fieldHorizontalMax, 1, 4);
}

double BaseRobot::calculateMapKickToPartner()
{
    double distance = this->getPosition()->getDistanceTo ( this->getTarget() );
    return UtilGame::m_map ( distance, 2 * ROBOT_RADIUS_ERROR, 2 * fieldHorizontalMax, 2, 8 );
}

void BaseRobot::makeRobotShot()
{
    if ( this->enemyOnTheLine ( this->getBallPosition(), this->getTarget() ) > 0 )
    {
        this->setDribble(calculateMapDribble());
        this->setKick(calculateMapKick());
    }
    else
        this->setKick(kickMax);

    this->setGoingToBall(true);
}

double BaseRobot::enemyOnTheLine( Point *bPoint, Point *fPoint )
{
    vector < EnemyRobot * > *enemies = this->getEnemyRobots();
    double angle = bPoint->calculateAngleTo ( fPoint );
    Point *nextPoint = bPoint;
    while ( nextPoint->getDistanceTo ( fPoint ) > ROBOT_RADIUS )
    {
        for ( int i = 0; i < enemies->size(); i++ )
        {
            if ( enemies->at ( i )->getPosition()->getDistanceTo ( nextPoint ) <= ROBOT_RADIUS )
            {
                return bPoint->getDistanceTo ( enemies->at ( i )->getPosition() );
            }
        }
        nextPoint = new Point ( nextPoint->getPointX() + ROBOT_RADIUS * cos ( angle ),
                                nextPoint->getPointY() + ROBOT_RADIUS * sin ( angle ) );
    }
    return -1;
}

double BaseRobot::opossiteAngle ( double &angle )
{
    if ( this->getFieldSide() == RIGHT )
    {
        angle -= PI;
        adjustAngle ( angle );
    }
}

double BaseRobot::adjustAngle ( double &angle )
{
    if ( angle > PI )
        angle -= 2 * PI;
    else if ( angle < -PI )
        angle += 2 * PI;
}

void BaseRobot::changeSideAngle ( double &angle )
{
    this->opossiteAngle ( angle );
    if ( this->ballUpperField() )
        angle = -angle;
}

void BaseRobot::changeSide ( double &valueToChange )
{
    if ( getFieldSide() == RIGHT )
        valueToChange *= -1;
}

bool BaseRobot::ballUpperField()
{
    double y = this->getBallPosition()->getPointY();
    if (this->getFieldSide() == RIGHT) {
        y = y * (-1);
    }

    if ( y > 0 )
        return true;
    else
        return false;
}

int BaseRobot::getFreePartnerId() {

    if (this->getatRefereeCmd() != 'H') {
        vector<BaseRobot*>* partners = this->getTeamPartners();

        for (int i = 0 ; i < partners->size() ; i++) {
            BaseRobot *robot = partners->at(i);
            if (robot->getPosition()->getDistanceTo(this->getEnemyGoal()) < this->getPosition()->getDistanceTo(this->getEnemyGoal()) &&
                enemyOnTheLine(this->getBallPosition(), robot->getPosition()) < 0) {
                return robot->getId();
            }
        }

        return (-1);
    }

    if (this->getId() == 5) {
        return 4;
    }
    else {
        return 5;
    }
}
