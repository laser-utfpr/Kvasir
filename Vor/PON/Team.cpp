#include "Team.h"
#include "PONRobot.h"
#include "pon/cppcompilados/Robotrobot1.h"
#include "pon/cppcompilados/Robotrobot2.h"
#include "pon/cppcompilados/Robotrobot3.h"
#include "pon/cppcompilados/Robotrobot4.h"
#include "pon/cppcompilados/Robotrobot5.h"
#include "pon/cppcompilados/Robotrobot6.h"
#include "pon/cppcompilados/rlAngleMove0.h"
#include "pon/cppcompilados/rlAngleMove1.h"
#include "pon/cppcompilados/rlAngleMove2.h"
#include "pon/cppcompilados/rlAngleMove3.h"
#include "pon/cppcompilados/rlAngleMove4.h"
#include "pon/cppcompilados/rlAngleMove5.h"
#include "pon/cppcompilados/rlBallFar0.h"
#include "pon/cppcompilados/rlBallFar1.h"
#include "pon/cppcompilados/rlBallFar2.h"
#include "pon/cppcompilados/rlBallFar3.h"
#include "pon/cppcompilados/rlBallFar4.h"
#include "pon/cppcompilados/rlBallFar5.h"
#include "pon/cppcompilados/rlDLBlueDirectKickBlue0.h"
#include "pon/cppcompilados/rlDLBlueDirectKickBlue1.h"
#include "pon/cppcompilados/rlDLBlueDirectKickBlue2.h"
#include "pon/cppcompilados/rlDLBlueDirectKickBlue3.h"
#include "pon/cppcompilados/rlDLBlueDirectKickBlue4.h"
#include "pon/cppcompilados/rlDLBlueDirectKickBlue5.h"
#include "pon/cppcompilados/rlDLStartNotClose0.h"
#include "pon/cppcompilados/rlDLStartNotClose1.h"
#include "pon/cppcompilados/rlDLStartNotClose2.h"
#include "pon/cppcompilados/rlDLStartNotClose3.h"
#include "pon/cppcompilados/rlDLStartNotClose4.h"
#include "pon/cppcompilados/rlDLStartNotClose5.h"
#include "pon/cppcompilados/rlDLStopBallClose0.h"
#include "pon/cppcompilados/rlDLStopBallClose1.h"
#include "pon/cppcompilados/rlDLStopBallClose2.h"
#include "pon/cppcompilados/rlDLStopBallClose3.h"
#include "pon/cppcompilados/rlDLStopBallClose4.h"
#include "pon/cppcompilados/rlDLStopBallClose5.h"
#include "pon/cppcompilados/rlDLYellowDirectKickYellow0.h"
#include "pon/cppcompilados/rlDLYellowDirectKickYellow1.h"
#include "pon/cppcompilados/rlDLYellowDirectKickYellow2.h"
#include "pon/cppcompilados/rlDLYellowDirectKickYellow3.h"
#include "pon/cppcompilados/rlDLYellowDirectKickYellow4.h"
#include "pon/cppcompilados/rlDLYellowDirectKickYellow5.h"
#include "pon/cppcompilados/rlDLYellowIndirectYellow0.h"
#include "pon/cppcompilados/rlDLYellowIndirectYellow1.h"
#include "pon/cppcompilados/rlDLYellowIndirectYellow2.h"
#include "pon/cppcompilados/rlDLYellowIndirectYellow3.h"
#include "pon/cppcompilados/rlDLYellowIndirectYellow4.h"
#include "pon/cppcompilados/rlDLYellowIndirectYellow5.h"
#include "pon/cppcompilados/rlDLYellowPenaltyBlue0.h"
#include "pon/cppcompilados/rlDLYellowPenaltyBlue1.h"
#include "pon/cppcompilados/rlDLYellowPenaltyBlue2.h"
#include "pon/cppcompilados/rlDLYellowPenaltyBlue3.h"
#include "pon/cppcompilados/rlDLYellowPenaltyBlue4.h"
#include "pon/cppcompilados/rlDLYellowPenaltyBlue5.h"
#include "pon/cppcompilados/rlDLtBlueIndirectBlue0.h"
#include "pon/cppcompilados/rlDLtBlueIndirectBlue1.h"
#include "pon/cppcompilados/rlDLtBlueIndirectBlue2.h"
#include "pon/cppcompilados/rlDLtBlueIndirectBlue3.h"
#include "pon/cppcompilados/rlDLtBlueIndirectBlue4.h"
#include "pon/cppcompilados/rlDLtBlueIndirectBlue5.h"
#include "pon/cppcompilados/rlDLtBluePenaltyYellow0.h"
#include "pon/cppcompilados/rlDLtBluePenaltyYellow1.h"
#include "pon/cppcompilados/rlDLtBluePenaltyYellow2.h"
#include "pon/cppcompilados/rlDLtBluePenaltyYellow3.h"
#include "pon/cppcompilados/rlDLtBluePenaltyYellow4.h"
#include "pon/cppcompilados/rlDLtBluePenaltyYellow5.h"
#include "pon/cppcompilados/rlDLtStopBallFar0.h"
#include "pon/cppcompilados/rlDLtStopBallFar1.h"
#include "pon/cppcompilados/rlDLtStopBallFar2.h"
#include "pon/cppcompilados/rlDLtStopBallFar3.h"
#include "pon/cppcompilados/rlDLtStopBallFar4.h"
#include "pon/cppcompilados/rlDLtStopBallFar5.h"
#include "pon/cppcompilados/rlDRBlueDirectKickBlue0.h"
#include "pon/cppcompilados/rlDRBlueDirectKickBlue1.h"
#include "pon/cppcompilados/rlDRBlueDirectKickBlue2.h"
#include "pon/cppcompilados/rlDRBlueDirectKickBlue3.h"
#include "pon/cppcompilados/rlDRBlueDirectKickBlue4.h"
#include "pon/cppcompilados/rlDRBlueDirectKickBlue5.h"
#include "pon/cppcompilados/rlDRBlueIndirectKickBlue0.h"
#include "pon/cppcompilados/rlDRBlueIndirectKickBlue1.h"
#include "pon/cppcompilados/rlDRBlueIndirectKickBlue2.h"
#include "pon/cppcompilados/rlDRBlueIndirectKickBlue3.h"
#include "pon/cppcompilados/rlDRBlueIndirectKickBlue4.h"
#include "pon/cppcompilados/rlDRBlueIndirectKickBlue5.h"
#include "pon/cppcompilados/rlDRBluePenaltyYellow0.h"
#include "pon/cppcompilados/rlDRBluePenaltyYellow1.h"
#include "pon/cppcompilados/rlDRBluePenaltyYellow2.h"
#include "pon/cppcompilados/rlDRBluePenaltyYellow3.h"
#include "pon/cppcompilados/rlDRBluePenaltyYellow4.h"
#include "pon/cppcompilados/rlDRBluePenaltyYellow5.h"
#include "pon/cppcompilados/rlDRStartBallNotClose0.h"
#include "pon/cppcompilados/rlDRStartBallNotClose1.h"
#include "pon/cppcompilados/rlDRStartBallNotClose2.h"
#include "pon/cppcompilados/rlDRStartBallNotClose3.h"
#include "pon/cppcompilados/rlDRStartBallNotClose4.h"
#include "pon/cppcompilados/rlDRStartBallNotClose5.h"
#include "pon/cppcompilados/rlDRStopBallClose0.h"
#include "pon/cppcompilados/rlDRStopBallClose1.h"
#include "pon/cppcompilados/rlDRStopBallClose2.h"
#include "pon/cppcompilados/rlDRStopBallClose3.h"
#include "pon/cppcompilados/rlDRStopBallClose4.h"
#include "pon/cppcompilados/rlDRStopBallClose5.h"
#include "pon/cppcompilados/rlDRStopBallFar0.h"
#include "pon/cppcompilados/rlDRStopBallFar1.h"
#include "pon/cppcompilados/rlDRStopBallFar2.h"
#include "pon/cppcompilados/rlDRStopBallFar3.h"
#include "pon/cppcompilados/rlDRStopBallFar4.h"
#include "pon/cppcompilados/rlDRStopBallFar5.h"
#include "pon/cppcompilados/rlDRYellowDirectKickYellow0.h"
#include "pon/cppcompilados/rlDRYellowDirectKickYellow1.h"
#include "pon/cppcompilados/rlDRYellowDirectKickYellow2.h"
#include "pon/cppcompilados/rlDRYellowDirectKickYellow3.h"
#include "pon/cppcompilados/rlDRYellowDirectKickYellow4.h"
#include "pon/cppcompilados/rlDRYellowDirectKickYellow5.h"
#include "pon/cppcompilados/rlDRYellowPenaltyBlue0.h"
#include "pon/cppcompilados/rlDRYellowPenaltyBlue1.h"
#include "pon/cppcompilados/rlDRYellowPenaltyBlue2.h"
#include "pon/cppcompilados/rlDRYellowPenaltyBlue3.h"
#include "pon/cppcompilados/rlDRYellowPenaltyBlue4.h"
#include "pon/cppcompilados/rlDRYellowPenaltyBlue5.h"
#include "pon/cppcompilados/rlDRtYellowIndirectKickYellow0.h"
#include "pon/cppcompilados/rlDRtYellowIndirectKickYellow1.h"
#include "pon/cppcompilados/rlDRtYellowIndirectKickYellow2.h"
#include "pon/cppcompilados/rlDRtYellowIndirectKickYellow3.h"
#include "pon/cppcompilados/rlDRtYellowIndirectKickYellow4.h"
#include "pon/cppcompilados/rlDRtYellowIndirectKickYellow5.h"
#include "pon/cppcompilados/rlGkBluePenaltyYellow0.h"
#include "pon/cppcompilados/rlGkBluePenaltyYellow1.h"
#include "pon/cppcompilados/rlGkBluePenaltyYellow2.h"
#include "pon/cppcompilados/rlGkBluePenaltyYellow3.h"
#include "pon/cppcompilados/rlGkBluePenaltyYellow4.h"
#include "pon/cppcompilados/rlGkBluePenaltyYellow5.h"
#include "pon/cppcompilados/rlGkStartInsideArea0.h"
#include "pon/cppcompilados/rlGkStartInsideArea1.h"
#include "pon/cppcompilados/rlGkStartInsideArea2.h"
#include "pon/cppcompilados/rlGkStartInsideArea3.h"
#include "pon/cppcompilados/rlGkStartInsideArea4.h"
#include "pon/cppcompilados/rlGkStartInsideArea5.h"
#include "pon/cppcompilados/rlGkStartInsideAreaClosestBall0.h"
#include "pon/cppcompilados/rlGkStartInsideAreaClosestBall1.h"
#include "pon/cppcompilados/rlGkStartInsideAreaClosestBall2.h"
#include "pon/cppcompilados/rlGkStartInsideAreaClosestBall3.h"
#include "pon/cppcompilados/rlGkStartInsideAreaClosestBall4.h"
#include "pon/cppcompilados/rlGkStartInsideAreaClosestBall5.h"
#include "pon/cppcompilados/rlGkStartInsideAreaClosestBallKick0.h"
#include "pon/cppcompilados/rlGkStartInsideAreaClosestBallKick1.h"
#include "pon/cppcompilados/rlGkStartInsideAreaClosestBallKick2.h"
#include "pon/cppcompilados/rlGkStartInsideAreaClosestBallKick3.h"
#include "pon/cppcompilados/rlGkStartInsideAreaClosestBallKick4.h"
#include "pon/cppcompilados/rlGkStartInsideAreaClosestBallKick5.h"
#include "pon/cppcompilados/rlGkStartOutsideArea0.h"
#include "pon/cppcompilados/rlGkStartOutsideArea1.h"
#include "pon/cppcompilados/rlGkStartOutsideArea2.h"
#include "pon/cppcompilados/rlGkStartOutsideArea3.h"
#include "pon/cppcompilados/rlGkStartOutsideArea4.h"
#include "pon/cppcompilados/rlGkStartOutsideArea5.h"
#include "pon/cppcompilados/rlGkStopCloseGoal0.h"
#include "pon/cppcompilados/rlGkStopCloseGoal1.h"
#include "pon/cppcompilados/rlGkStopCloseGoal2.h"
#include "pon/cppcompilados/rlGkStopCloseGoal3.h"
#include "pon/cppcompilados/rlGkStopCloseGoal4.h"
#include "pon/cppcompilados/rlGkStopCloseGoal5.h"
#include "pon/cppcompilados/rlGkStopFarGoal0.h"
#include "pon/cppcompilados/rlGkStopFarGoal1.h"
#include "pon/cppcompilados/rlGkStopFarGoal2.h"
#include "pon/cppcompilados/rlGkStopFarGoal3.h"
#include "pon/cppcompilados/rlGkStopFarGoal4.h"
#include "pon/cppcompilados/rlGkStopFarGoal5.h"
#include "pon/cppcompilados/rlGkYellowPenaltyBlue0.h"
#include "pon/cppcompilados/rlGkYellowPenaltyBlue1.h"
#include "pon/cppcompilados/rlGkYellowPenaltyBlue2.h"
#include "pon/cppcompilados/rlGkYellowPenaltyBlue3.h"
#include "pon/cppcompilados/rlGkYellowPenaltyBlue4.h"
#include "pon/cppcompilados/rlGkYellowPenaltyBlue5.h"
#include "pon/cppcompilados/rlMOBlueDirectKick0.h"
#include "pon/cppcompilados/rlMOBlueDirectKick1.h"
#include "pon/cppcompilados/rlMOBlueDirectKick2.h"
#include "pon/cppcompilados/rlMOBlueDirectKick3.h"
#include "pon/cppcompilados/rlMOBlueDirectKick4.h"
#include "pon/cppcompilados/rlMOBlueDirectKick5.h"
#include "pon/cppcompilados/rlMOBlueIndirectKick0.h"
#include "pon/cppcompilados/rlMOBlueIndirectKick1.h"
#include "pon/cppcompilados/rlMOBlueIndirectKick2.h"
#include "pon/cppcompilados/rlMOBlueIndirectKick3.h"
#include "pon/cppcompilados/rlMOBlueIndirectKick4.h"
#include "pon/cppcompilados/rlMOBlueIndirectKick5.h"
#include "pon/cppcompilados/rlMOBlueKickoff0.h"
#include "pon/cppcompilados/rlMOBlueKickoff1.h"
#include "pon/cppcompilados/rlMOBlueKickoff2.h"
#include "pon/cppcompilados/rlMOBlueKickoff3.h"
#include "pon/cppcompilados/rlMOBlueKickoff4.h"
#include "pon/cppcompilados/rlMOBlueKickoff5.h"
#include "pon/cppcompilados/rlMOBluePenaltyBlue0.h"
#include "pon/cppcompilados/rlMOBluePenaltyBlue1.h"
#include "pon/cppcompilados/rlMOBluePenaltyBlue2.h"
#include "pon/cppcompilados/rlMOBluePenaltyBlue3.h"
#include "pon/cppcompilados/rlMOBluePenaltyBlue4.h"
#include "pon/cppcompilados/rlMOBluePenaltyBlue5.h"
#include "pon/cppcompilados/rlMOBluePenaltyYellow0.h"
#include "pon/cppcompilados/rlMOBluePenaltyYellow1.h"
#include "pon/cppcompilados/rlMOBluePenaltyYellow2.h"
#include "pon/cppcompilados/rlMOBluePenaltyYellow3.h"
#include "pon/cppcompilados/rlMOBluePenaltyYellow4.h"
#include "pon/cppcompilados/rlMOBluePenaltyYellow5.h"
#include "pon/cppcompilados/rlMOBlueReadyKickoffBlue0.h"
#include "pon/cppcompilados/rlMOBlueReadyKickoffBlue1.h"
#include "pon/cppcompilados/rlMOBlueReadyKickoffBlue2.h"
#include "pon/cppcompilados/rlMOBlueReadyKickoffBlue3.h"
#include "pon/cppcompilados/rlMOBlueReadyKickoffBlue4.h"
#include "pon/cppcompilados/rlMOBlueReadyKickoffBlue5.h"
#include "pon/cppcompilados/rlMOBlueReadyPenaltyBlue0.h"
#include "pon/cppcompilados/rlMOBlueReadyPenaltyBlue1.h"
#include "pon/cppcompilados/rlMOBlueReadyPenaltyBlue2.h"
#include "pon/cppcompilados/rlMOBlueReadyPenaltyBlue3.h"
#include "pon/cppcompilados/rlMOBlueReadyPenaltyBlue4.h"
#include "pon/cppcompilados/rlMOBlueReadyPenaltyBlue5.h"
#include "pon/cppcompilados/rlMOStop0.h"
#include "pon/cppcompilados/rlMOStop1.h"
#include "pon/cppcompilados/rlMOStop2.h"
#include "pon/cppcompilados/rlMOStop3.h"
#include "pon/cppcompilados/rlMOStop4.h"
#include "pon/cppcompilados/rlMOStop5.h"
#include "pon/cppcompilados/rlMOYellowDirectKick0.h"
#include "pon/cppcompilados/rlMOYellowDirectKick1.h"
#include "pon/cppcompilados/rlMOYellowDirectKick2.h"
#include "pon/cppcompilados/rlMOYellowDirectKick3.h"
#include "pon/cppcompilados/rlMOYellowDirectKick4.h"
#include "pon/cppcompilados/rlMOYellowDirectKick5.h"
#include "pon/cppcompilados/rlMOYellowIndirectKick0.h"
#include "pon/cppcompilados/rlMOYellowIndirectKick1.h"
#include "pon/cppcompilados/rlMOYellowIndirectKick2.h"
#include "pon/cppcompilados/rlMOYellowIndirectKick3.h"
#include "pon/cppcompilados/rlMOYellowIndirectKick4.h"
#include "pon/cppcompilados/rlMOYellowIndirectKick5.h"
#include "pon/cppcompilados/rlMOYellowKickoff0.h"
#include "pon/cppcompilados/rlMOYellowKickoff1.h"
#include "pon/cppcompilados/rlMOYellowKickoff2.h"
#include "pon/cppcompilados/rlMOYellowKickoff3.h"
#include "pon/cppcompilados/rlMOYellowKickoff4.h"
#include "pon/cppcompilados/rlMOYellowKickoff5.h"
#include "pon/cppcompilados/rlMOYellowPenaltyBlue0.h"
#include "pon/cppcompilados/rlMOYellowPenaltyBlue1.h"
#include "pon/cppcompilados/rlMOYellowPenaltyBlue2.h"
#include "pon/cppcompilados/rlMOYellowPenaltyBlue3.h"
#include "pon/cppcompilados/rlMOYellowPenaltyBlue4.h"
#include "pon/cppcompilados/rlMOYellowPenaltyBlue5.h"
#include "pon/cppcompilados/rlMOYellowPenaltyYellow0.h"
#include "pon/cppcompilados/rlMOYellowPenaltyYellow1.h"
#include "pon/cppcompilados/rlMOYellowPenaltyYellow2.h"
#include "pon/cppcompilados/rlMOYellowPenaltyYellow3.h"
#include "pon/cppcompilados/rlMOYellowPenaltyYellow4.h"
#include "pon/cppcompilados/rlMOYellowPenaltyYellow5.h"
#include "pon/cppcompilados/rlMOYellowReadyKickoffYellow0.h"
#include "pon/cppcompilados/rlMOYellowReadyKickoffYellow1.h"
#include "pon/cppcompilados/rlMOYellowReadyKickoffYellow2.h"
#include "pon/cppcompilados/rlMOYellowReadyKickoffYellow3.h"
#include "pon/cppcompilados/rlMOYellowReadyKickoffYellow4.h"
#include "pon/cppcompilados/rlMOYellowReadyKickoffYellow5.h"
#include "pon/cppcompilados/rlMOYellowReadyPenaltyYellow0.h"
#include "pon/cppcompilados/rlMOYellowReadyPenaltyYellow1.h"
#include "pon/cppcompilados/rlMOYellowReadyPenaltyYellow2.h"
#include "pon/cppcompilados/rlMOYellowReadyPenaltyYellow3.h"
#include "pon/cppcompilados/rlMOYellowReadyPenaltyYellow4.h"
#include "pon/cppcompilados/rlMOYellowReadyPenaltyYellow5.h"
#include "pon/cppcompilados/rlRobotMoveX0.h"
#include "pon/cppcompilados/rlRobotMoveX1.h"
#include "pon/cppcompilados/rlRobotMoveX2.h"
#include "pon/cppcompilados/rlRobotMoveX3.h"
#include "pon/cppcompilados/rlRobotMoveX4.h"
#include "pon/cppcompilados/rlRobotMoveX5.h"
#include "pon/cppcompilados/rlRobotMoveY0.h"
#include "pon/cppcompilados/rlRobotMoveY1.h"
#include "pon/cppcompilados/rlRobotMoveY2.h"
#include "pon/cppcompilados/rlRobotMoveY3.h"
#include "pon/cppcompilados/rlRobotMoveY4.h"
#include "pon/cppcompilados/rlRobotMoveY5.h"
#include "pon/cppcompilados/rlSLBlueDirectKick0.h"
#include "pon/cppcompilados/rlSLBlueDirectKick1.h"
#include "pon/cppcompilados/rlSLBlueDirectKick2.h"
#include "pon/cppcompilados/rlSLBlueDirectKick3.h"
#include "pon/cppcompilados/rlSLBlueDirectKick4.h"
#include "pon/cppcompilados/rlSLBlueDirectKick5.h"
#include "pon/cppcompilados/rlSLBlueIndirectKick0.h"
#include "pon/cppcompilados/rlSLBlueIndirectKick1.h"
#include "pon/cppcompilados/rlSLBlueIndirectKick2.h"
#include "pon/cppcompilados/rlSLBlueIndirectKick3.h"
#include "pon/cppcompilados/rlSLBlueIndirectKick4.h"
#include "pon/cppcompilados/rlSLBlueIndirectKick5.h"
#include "pon/cppcompilados/rlSLBluePenaltyBlue0.h"
#include "pon/cppcompilados/rlSLBluePenaltyBlue1.h"
#include "pon/cppcompilados/rlSLBluePenaltyBlue2.h"
#include "pon/cppcompilados/rlSLBluePenaltyBlue3.h"
#include "pon/cppcompilados/rlSLBluePenaltyBlue4.h"
#include "pon/cppcompilados/rlSLBluePenaltyBlue5.h"
#include "pon/cppcompilados/rlSLBluePenaltyYellow0.h"
#include "pon/cppcompilados/rlSLBluePenaltyYellow1.h"
#include "pon/cppcompilados/rlSLBluePenaltyYellow2.h"
#include "pon/cppcompilados/rlSLBluePenaltyYellow3.h"
#include "pon/cppcompilados/rlSLBluePenaltyYellow4.h"
#include "pon/cppcompilados/rlSLBluePenaltyYellow5.h"
#include "pon/cppcompilados/rlSLHaltClose0.h"
#include "pon/cppcompilados/rlSLHaltClose1.h"
#include "pon/cppcompilados/rlSLHaltClose2.h"
#include "pon/cppcompilados/rlSLHaltClose3.h"
#include "pon/cppcompilados/rlSLHaltClose4.h"
#include "pon/cppcompilados/rlSLHaltClose5.h"
#include "pon/cppcompilados/rlSLHaltCloseReady0.h"
#include "pon/cppcompilados/rlSLHaltCloseReady1.h"
#include "pon/cppcompilados/rlSLHaltCloseReady2.h"
#include "pon/cppcompilados/rlSLHaltCloseReady3.h"
#include "pon/cppcompilados/rlSLHaltCloseReady4.h"
#include "pon/cppcompilados/rlSLHaltCloseReady5.h"
#include "pon/cppcompilados/rlSLHaltNotClose0.h"
#include "pon/cppcompilados/rlSLHaltNotClose1.h"
#include "pon/cppcompilados/rlSLHaltNotClose2.h"
#include "pon/cppcompilados/rlSLHaltNotClose3.h"
#include "pon/cppcompilados/rlSLHaltNotClose4.h"
#include "pon/cppcompilados/rlSLHaltNotClose5.h"
#include "pon/cppcompilados/rlSLStartBallNotClose0.h"
#include "pon/cppcompilados/rlSLStartBallNotClose1.h"
#include "pon/cppcompilados/rlSLStartBallNotClose2.h"
#include "pon/cppcompilados/rlSLStartBallNotClose3.h"
#include "pon/cppcompilados/rlSLStartBallNotClose4.h"
#include "pon/cppcompilados/rlSLStartBallNotClose5.h"
#include "pon/cppcompilados/rlSLStopTeamLeft0.h"
#include "pon/cppcompilados/rlSLStopTeamLeft1.h"
#include "pon/cppcompilados/rlSLStopTeamLeft2.h"
#include "pon/cppcompilados/rlSLStopTeamLeft3.h"
#include "pon/cppcompilados/rlSLStopTeamLeft4.h"
#include "pon/cppcompilados/rlSLStopTeamLeft5.h"
#include "pon/cppcompilados/rlSLStopTeamRight0.h"
#include "pon/cppcompilados/rlSLStopTeamRight1.h"
#include "pon/cppcompilados/rlSLStopTeamRight2.h"
#include "pon/cppcompilados/rlSLStopTeamRight3.h"
#include "pon/cppcompilados/rlSLStopTeamRight4.h"
#include "pon/cppcompilados/rlSLStopTeamRight5.h"
#include "pon/cppcompilados/rlSLYellowDirectKick0.h"
#include "pon/cppcompilados/rlSLYellowDirectKick1.h"
#include "pon/cppcompilados/rlSLYellowDirectKick2.h"
#include "pon/cppcompilados/rlSLYellowDirectKick3.h"
#include "pon/cppcompilados/rlSLYellowDirectKick4.h"
#include "pon/cppcompilados/rlSLYellowDirectKick5.h"
#include "pon/cppcompilados/rlSLYellowIndirectKick0.h"
#include "pon/cppcompilados/rlSLYellowIndirectKick1.h"
#include "pon/cppcompilados/rlSLYellowIndirectKick2.h"
#include "pon/cppcompilados/rlSLYellowIndirectKick3.h"
#include "pon/cppcompilados/rlSLYellowIndirectKick4.h"
#include "pon/cppcompilados/rlSLYellowIndirectKick5.h"
#include "pon/cppcompilados/rlSLYellowPenaltyBlue0.h"
#include "pon/cppcompilados/rlSLYellowPenaltyBlue1.h"
#include "pon/cppcompilados/rlSLYellowPenaltyBlue2.h"
#include "pon/cppcompilados/rlSLYellowPenaltyBlue3.h"
#include "pon/cppcompilados/rlSLYellowPenaltyBlue4.h"
#include "pon/cppcompilados/rlSLYellowPenaltyBlue5.h"
#include "pon/cppcompilados/rlSLYellowPenaltyYellow0.h"
#include "pon/cppcompilados/rlSLYellowPenaltyYellow1.h"
#include "pon/cppcompilados/rlSLYellowPenaltyYellow2.h"
#include "pon/cppcompilados/rlSLYellowPenaltyYellow3.h"
#include "pon/cppcompilados/rlSLYellowPenaltyYellow4.h"
#include "pon/cppcompilados/rlSLYellowPenaltyYellow5.h"
#include "pon/cppcompilados/rlSRBlueDirectKick0.h"
#include "pon/cppcompilados/rlSRBlueDirectKick1.h"
#include "pon/cppcompilados/rlSRBlueDirectKick2.h"
#include "pon/cppcompilados/rlSRBlueDirectKick3.h"
#include "pon/cppcompilados/rlSRBlueDirectKick4.h"
#include "pon/cppcompilados/rlSRBlueDirectKick5.h"
#include "pon/cppcompilados/rlSRBlueIndirectKick0.h"
#include "pon/cppcompilados/rlSRBlueIndirectKick1.h"
#include "pon/cppcompilados/rlSRBlueIndirectKick2.h"
#include "pon/cppcompilados/rlSRBlueIndirectKick3.h"
#include "pon/cppcompilados/rlSRBlueIndirectKick4.h"
#include "pon/cppcompilados/rlSRBlueIndirectKick5.h"
#include "pon/cppcompilados/rlSRBluePenaltyBlue0.h"
#include "pon/cppcompilados/rlSRBluePenaltyBlue1.h"
#include "pon/cppcompilados/rlSRBluePenaltyBlue2.h"
#include "pon/cppcompilados/rlSRBluePenaltyBlue3.h"
#include "pon/cppcompilados/rlSRBluePenaltyBlue4.h"
#include "pon/cppcompilados/rlSRBluePenaltyBlue5.h"
#include "pon/cppcompilados/rlSRBluePenaltyYellow0.h"
#include "pon/cppcompilados/rlSRBluePenaltyYellow1.h"
#include "pon/cppcompilados/rlSRBluePenaltyYellow2.h"
#include "pon/cppcompilados/rlSRBluePenaltyYellow3.h"
#include "pon/cppcompilados/rlSRBluePenaltyYellow4.h"
#include "pon/cppcompilados/rlSRBluePenaltyYellow5.h"
#include "pon/cppcompilados/rlSRHaltClose0.h"
#include "pon/cppcompilados/rlSRHaltClose1.h"
#include "pon/cppcompilados/rlSRHaltClose2.h"
#include "pon/cppcompilados/rlSRHaltClose3.h"
#include "pon/cppcompilados/rlSRHaltClose4.h"
#include "pon/cppcompilados/rlSRHaltClose5.h"
#include "pon/cppcompilados/rlSRHaltCloseReady0.h"
#include "pon/cppcompilados/rlSRHaltCloseReady1.h"
#include "pon/cppcompilados/rlSRHaltCloseReady2.h"
#include "pon/cppcompilados/rlSRHaltCloseReady3.h"
#include "pon/cppcompilados/rlSRHaltCloseReady4.h"
#include "pon/cppcompilados/rlSRHaltCloseReady5.h"
#include "pon/cppcompilados/rlSRHaltNotClose0.h"
#include "pon/cppcompilados/rlSRHaltNotClose1.h"
#include "pon/cppcompilados/rlSRHaltNotClose2.h"
#include "pon/cppcompilados/rlSRHaltNotClose3.h"
#include "pon/cppcompilados/rlSRHaltNotClose4.h"
#include "pon/cppcompilados/rlSRHaltNotClose5.h"
#include "pon/cppcompilados/rlSRStartBallNotClose0.h"
#include "pon/cppcompilados/rlSRStartBallNotClose1.h"
#include "pon/cppcompilados/rlSRStartBallNotClose2.h"
#include "pon/cppcompilados/rlSRStartBallNotClose3.h"
#include "pon/cppcompilados/rlSRStartBallNotClose4.h"
#include "pon/cppcompilados/rlSRStartBallNotClose5.h"
#include "pon/cppcompilados/rlSRStopTeamLeft0.h"
#include "pon/cppcompilados/rlSRStopTeamLeft1.h"
#include "pon/cppcompilados/rlSRStopTeamLeft2.h"
#include "pon/cppcompilados/rlSRStopTeamLeft3.h"
#include "pon/cppcompilados/rlSRStopTeamLeft4.h"
#include "pon/cppcompilados/rlSRStopTeamLeft5.h"
#include "pon/cppcompilados/rlSRStopTeamRight0.h"
#include "pon/cppcompilados/rlSRStopTeamRight1.h"
#include "pon/cppcompilados/rlSRStopTeamRight2.h"
#include "pon/cppcompilados/rlSRStopTeamRight3.h"
#include "pon/cppcompilados/rlSRStopTeamRight4.h"
#include "pon/cppcompilados/rlSRStopTeamRight5.h"
#include "pon/cppcompilados/rlSRYellowDirectKick0.h"
#include "pon/cppcompilados/rlSRYellowDirectKick1.h"
#include "pon/cppcompilados/rlSRYellowDirectKick2.h"
#include "pon/cppcompilados/rlSRYellowDirectKick3.h"
#include "pon/cppcompilados/rlSRYellowDirectKick4.h"
#include "pon/cppcompilados/rlSRYellowDirectKick5.h"
#include "pon/cppcompilados/rlSRYellowIndirectKick0.h"
#include "pon/cppcompilados/rlSRYellowIndirectKick1.h"
#include "pon/cppcompilados/rlSRYellowIndirectKick2.h"
#include "pon/cppcompilados/rlSRYellowIndirectKick3.h"
#include "pon/cppcompilados/rlSRYellowIndirectKick4.h"
#include "pon/cppcompilados/rlSRYellowIndirectKick5.h"
#include "pon/cppcompilados/rlSRYellowsPenaltyBlue0.h"
#include "pon/cppcompilados/rlSRYellowsPenaltyBlue1.h"
#include "pon/cppcompilados/rlSRYellowsPenaltyBlue2.h"
#include "pon/cppcompilados/rlSRYellowsPenaltyBlue3.h"
#include "pon/cppcompilados/rlSRYellowsPenaltyBlue4.h"
#include "pon/cppcompilados/rlSRYellowsPenaltyBlue5.h"
#include "pon/cppcompilados/rlSRYellowsPenaltyYellow0.h"
#include "pon/cppcompilados/rlSRYellowsPenaltyYellow1.h"
#include "pon/cppcompilados/rlSRYellowsPenaltyYellow2.h"
#include "pon/cppcompilados/rlSRYellowsPenaltyYellow3.h"
#include "pon/cppcompilados/rlSRYellowsPenaltyYellow4.h"
#include "pon/cppcompilados/rlSRYellowsPenaltyYellow5.h"
#include "pon/cppcompilados/rlStartEnemyFieldKick0.h"
#include "pon/cppcompilados/rlStartEnemyFieldKick1.h"
#include "pon/cppcompilados/rlStartEnemyFieldKick2.h"
#include "pon/cppcompilados/rlStartEnemyFieldKick3.h"
#include "pon/cppcompilados/rlStartEnemyFieldKick4.h"
#include "pon/cppcompilados/rlStartEnemyFieldKick5.h"
#include "pon/cppcompilados/rlStartEnemyFieldPositionKick0.h"
#include "pon/cppcompilados/rlStartEnemyFieldPositionKick1.h"
#include "pon/cppcompilados/rlStartEnemyFieldPositionKick2.h"
#include "pon/cppcompilados/rlStartEnemyFieldPositionKick3.h"
#include "pon/cppcompilados/rlStartEnemyFieldPositionKick4.h"
#include "pon/cppcompilados/rlStartEnemyFieldPositionKick5.h"
#include "pon/cppcompilados/rlStartFreePartner0.h"
#include "pon/cppcompilados/rlStartFreePartner1.h"
#include "pon/cppcompilados/rlStartFreePartner2.h"
#include "pon/cppcompilados/rlStartFreePartner3.h"
#include "pon/cppcompilados/rlStartFreePartner4.h"
#include "pon/cppcompilados/rlStartFreePartner5.h"
#include "pon/cppcompilados/rlStartFreePartnerPass0.h"
#include "pon/cppcompilados/rlStartFreePartnerPass1.h"
#include "pon/cppcompilados/rlStartFreePartnerPass2.h"
#include "pon/cppcompilados/rlStartFreePartnerPass3.h"
#include "pon/cppcompilados/rlStartFreePartnerPass4.h"
#include "pon/cppcompilados/rlStartFreePartnerPass5.h"
#include "pon/cppcompilados/rlStartNoFreePartner0.h"
#include "pon/cppcompilados/rlStartNoFreePartner1.h"
#include "pon/cppcompilados/rlStartNoFreePartner2.h"
#include "pon/cppcompilados/rlStartNoFreePartner3.h"
#include "pon/cppcompilados/rlStartNoFreePartner4.h"
#include "pon/cppcompilados/rlStartNoFreePartner5.h"
#include "pon/cppcompilados/rlStartNoFreePartnerKick0.h"
#include "pon/cppcompilados/rlStartNoFreePartnerKick1.h"
#include "pon/cppcompilados/rlStartNoFreePartnerKick2.h"
#include "pon/cppcompilados/rlStartNoFreePartnerKick3.h"
#include "pon/cppcompilados/rlStartNoFreePartnerKick4.h"
#include "pon/cppcompilados/rlStartNoFreePartnerKick5.h"
#include "pon/cppcompilados/rlStartTargetToBall0.h"
#include "pon/cppcompilados/rlStartTargetToBall1.h"
#include "pon/cppcompilados/rlStartTargetToBall2.h"
#include "pon/cppcompilados/rlStartTargetToBall3.h"
#include "pon/cppcompilados/rlStartTargetToBall4.h"
#include "pon/cppcompilados/rlStartTargetToBall5.h"
#include "pon/cppcompilados/rlTeste.h"

Team::Team(TeamColor color, FieldSide side, int numPlayers) {
    this->teamColor = color;
    this->fieldSide = side;

    this->teamPlayers = new vector < BaseRobot * >;
    this->enemyPlayers = new vector < EnemyRobot * >;

    createTeamRobots(numPlayers);
}

Team::~Team() {

}

void Team::createTeamRobots(int numRobots) {

    rlAngleMove0 * conditionrlAngleMove0 = new rlAngleMove0();
    rlAngleMove1 * conditionrlAngleMove1 = new rlAngleMove1();
    rlAngleMove2 * conditionrlAngleMove2 = new rlAngleMove2();
    rlAngleMove3 * conditionrlAngleMove3 = new rlAngleMove3();
    rlAngleMove4 * conditionrlAngleMove4 = new rlAngleMove4();
    rlAngleMove5 * conditionrlAngleMove5 = new rlAngleMove5();
    rlBallFar0 * conditionrlBallFar0 = new rlBallFar0();
    rlBallFar1 * conditionrlBallFar1 = new rlBallFar1();
    rlBallFar2 * conditionrlBallFar2 = new rlBallFar2();
    rlBallFar3 * conditionrlBallFar3 = new rlBallFar3();
    rlBallFar4 * conditionrlBallFar4 = new rlBallFar4();
    rlBallFar5 * conditionrlBallFar5 = new rlBallFar5();
    rlDLBlueDirectKickBlue0 * conditionrlDLBlueDirectKickBlue0 = new rlDLBlueDirectKickBlue0();
    rlDLBlueDirectKickBlue1 * conditionrlDLBlueDirectKickBlue1 = new rlDLBlueDirectKickBlue1();
    rlDLBlueDirectKickBlue2 * conditionrlDLBlueDirectKickBlue2 = new rlDLBlueDirectKickBlue2();
    rlDLBlueDirectKickBlue3 * conditionrlDLBlueDirectKickBlue3 = new rlDLBlueDirectKickBlue3();
    rlDLBlueDirectKickBlue4 * conditionrlDLBlueDirectKickBlue4 = new rlDLBlueDirectKickBlue4();
    rlDLBlueDirectKickBlue5 * conditionrlDLBlueDirectKickBlue5 = new rlDLBlueDirectKickBlue5();
    rlDLStartNotClose0 * conditionrlDLStartNotClose0 = new rlDLStartNotClose0();
    rlDLStartNotClose1 * conditionrlDLStartNotClose1 = new rlDLStartNotClose1();
    rlDLStartNotClose2 * conditionrlDLStartNotClose2 = new rlDLStartNotClose2();
    rlDLStartNotClose3 * conditionrlDLStartNotClose3 = new rlDLStartNotClose3();
    rlDLStartNotClose4 * conditionrlDLStartNotClose4 = new rlDLStartNotClose4();
    rlDLStartNotClose5 * conditionrlDLStartNotClose5 = new rlDLStartNotClose5();
    rlDLStopBallClose0 * conditionrlDLStopBallClose0 = new rlDLStopBallClose0();
    rlDLStopBallClose1 * conditionrlDLStopBallClose1 = new rlDLStopBallClose1();
    rlDLStopBallClose2 * conditionrlDLStopBallClose2 = new rlDLStopBallClose2();
    rlDLStopBallClose3 * conditionrlDLStopBallClose3 = new rlDLStopBallClose3();
    rlDLStopBallClose4 * conditionrlDLStopBallClose4 = new rlDLStopBallClose4();
    rlDLStopBallClose5 * conditionrlDLStopBallClose5 = new rlDLStopBallClose5();
    rlDLYellowDirectKickYellow0 * conditionrlDLYellowDirectKickYellow0 = new rlDLYellowDirectKickYellow0();
    rlDLYellowDirectKickYellow1 * conditionrlDLYellowDirectKickYellow1 = new rlDLYellowDirectKickYellow1();
    rlDLYellowDirectKickYellow2 * conditionrlDLYellowDirectKickYellow2 = new rlDLYellowDirectKickYellow2();
    rlDLYellowDirectKickYellow3 * conditionrlDLYellowDirectKickYellow3 = new rlDLYellowDirectKickYellow3();
    rlDLYellowDirectKickYellow4 * conditionrlDLYellowDirectKickYellow4 = new rlDLYellowDirectKickYellow4();
    rlDLYellowDirectKickYellow5 * conditionrlDLYellowDirectKickYellow5 = new rlDLYellowDirectKickYellow5();
    rlDLYellowIndirectYellow0 * conditionrlDLYellowIndirectYellow0 = new rlDLYellowIndirectYellow0();
    rlDLYellowIndirectYellow1 * conditionrlDLYellowIndirectYellow1 = new rlDLYellowIndirectYellow1();
    rlDLYellowIndirectYellow2 * conditionrlDLYellowIndirectYellow2 = new rlDLYellowIndirectYellow2();
    rlDLYellowIndirectYellow3 * conditionrlDLYellowIndirectYellow3 = new rlDLYellowIndirectYellow3();
    rlDLYellowIndirectYellow4 * conditionrlDLYellowIndirectYellow4 = new rlDLYellowIndirectYellow4();
    rlDLYellowIndirectYellow5 * conditionrlDLYellowIndirectYellow5 = new rlDLYellowIndirectYellow5();
    rlDLYellowPenaltyBlue0 * conditionrlDLYellowPenaltyBlue0 = new rlDLYellowPenaltyBlue0();
    rlDLYellowPenaltyBlue1 * conditionrlDLYellowPenaltyBlue1 = new rlDLYellowPenaltyBlue1();
    rlDLYellowPenaltyBlue2 * conditionrlDLYellowPenaltyBlue2 = new rlDLYellowPenaltyBlue2();
    rlDLYellowPenaltyBlue3 * conditionrlDLYellowPenaltyBlue3 = new rlDLYellowPenaltyBlue3();
    rlDLYellowPenaltyBlue4 * conditionrlDLYellowPenaltyBlue4 = new rlDLYellowPenaltyBlue4();
    rlDLYellowPenaltyBlue5 * conditionrlDLYellowPenaltyBlue5 = new rlDLYellowPenaltyBlue5();
    rlDLtBlueIndirectBlue0 * conditionrlDLtBlueIndirectBlue0 = new rlDLtBlueIndirectBlue0();
    rlDLtBlueIndirectBlue1 * conditionrlDLtBlueIndirectBlue1 = new rlDLtBlueIndirectBlue1();
    rlDLtBlueIndirectBlue2 * conditionrlDLtBlueIndirectBlue2 = new rlDLtBlueIndirectBlue2();
    rlDLtBlueIndirectBlue3 * conditionrlDLtBlueIndirectBlue3 = new rlDLtBlueIndirectBlue3();
    rlDLtBlueIndirectBlue4 * conditionrlDLtBlueIndirectBlue4 = new rlDLtBlueIndirectBlue4();
    rlDLtBlueIndirectBlue5 * conditionrlDLtBlueIndirectBlue5 = new rlDLtBlueIndirectBlue5();
    rlDLtBluePenaltyYellow0 * conditionrlDLtBluePenaltyYellow0 = new rlDLtBluePenaltyYellow0();
    rlDLtBluePenaltyYellow1 * conditionrlDLtBluePenaltyYellow1 = new rlDLtBluePenaltyYellow1();
    rlDLtBluePenaltyYellow2 * conditionrlDLtBluePenaltyYellow2 = new rlDLtBluePenaltyYellow2();
    rlDLtBluePenaltyYellow3 * conditionrlDLtBluePenaltyYellow3 = new rlDLtBluePenaltyYellow3();
    rlDLtBluePenaltyYellow4 * conditionrlDLtBluePenaltyYellow4 = new rlDLtBluePenaltyYellow4();
    rlDLtBluePenaltyYellow5 * conditionrlDLtBluePenaltyYellow5 = new rlDLtBluePenaltyYellow5();
    rlDLtStopBallFar0 * conditionrlDLtStopBallFar0 = new rlDLtStopBallFar0();
    rlDLtStopBallFar1 * conditionrlDLtStopBallFar1 = new rlDLtStopBallFar1();
    rlDLtStopBallFar2 * conditionrlDLtStopBallFar2 = new rlDLtStopBallFar2();
    rlDLtStopBallFar3 * conditionrlDLtStopBallFar3 = new rlDLtStopBallFar3();
    rlDLtStopBallFar4 * conditionrlDLtStopBallFar4 = new rlDLtStopBallFar4();
    rlDLtStopBallFar5 * conditionrlDLtStopBallFar5 = new rlDLtStopBallFar5();
    rlDRBlueDirectKickBlue0 * conditionrlDRBlueDirectKickBlue0 = new rlDRBlueDirectKickBlue0();
    rlDRBlueDirectKickBlue1 * conditionrlDRBlueDirectKickBlue1 = new rlDRBlueDirectKickBlue1();
    rlDRBlueDirectKickBlue2 * conditionrlDRBlueDirectKickBlue2 = new rlDRBlueDirectKickBlue2();
    rlDRBlueDirectKickBlue3 * conditionrlDRBlueDirectKickBlue3 = new rlDRBlueDirectKickBlue3();
    rlDRBlueDirectKickBlue4 * conditionrlDRBlueDirectKickBlue4 = new rlDRBlueDirectKickBlue4();
    rlDRBlueDirectKickBlue5 * conditionrlDRBlueDirectKickBlue5 = new rlDRBlueDirectKickBlue5();
    rlDRBlueIndirectKickBlue0 * conditionrlDRBlueIndirectKickBlue0 = new rlDRBlueIndirectKickBlue0();
    rlDRBlueIndirectKickBlue1 * conditionrlDRBlueIndirectKickBlue1 = new rlDRBlueIndirectKickBlue1();
    rlDRBlueIndirectKickBlue2 * conditionrlDRBlueIndirectKickBlue2 = new rlDRBlueIndirectKickBlue2();
    rlDRBlueIndirectKickBlue3 * conditionrlDRBlueIndirectKickBlue3 = new rlDRBlueIndirectKickBlue3();
    rlDRBlueIndirectKickBlue4 * conditionrlDRBlueIndirectKickBlue4 = new rlDRBlueIndirectKickBlue4();
    rlDRBlueIndirectKickBlue5 * conditionrlDRBlueIndirectKickBlue5 = new rlDRBlueIndirectKickBlue5();
    rlDRBluePenaltyYellow0 * conditionrlDRBluePenaltyYellow0 = new rlDRBluePenaltyYellow0();
    rlDRBluePenaltyYellow1 * conditionrlDRBluePenaltyYellow1 = new rlDRBluePenaltyYellow1();
    rlDRBluePenaltyYellow2 * conditionrlDRBluePenaltyYellow2 = new rlDRBluePenaltyYellow2();
    rlDRBluePenaltyYellow3 * conditionrlDRBluePenaltyYellow3 = new rlDRBluePenaltyYellow3();
    rlDRBluePenaltyYellow4 * conditionrlDRBluePenaltyYellow4 = new rlDRBluePenaltyYellow4();
    rlDRBluePenaltyYellow5 * conditionrlDRBluePenaltyYellow5 = new rlDRBluePenaltyYellow5();
    rlDRStartBallNotClose0 * conditionrlDRStartBallNotClose0 = new rlDRStartBallNotClose0();
    rlDRStartBallNotClose1 * conditionrlDRStartBallNotClose1 = new rlDRStartBallNotClose1();
    rlDRStartBallNotClose2 * conditionrlDRStartBallNotClose2 = new rlDRStartBallNotClose2();
    rlDRStartBallNotClose3 * conditionrlDRStartBallNotClose3 = new rlDRStartBallNotClose3();
    rlDRStartBallNotClose4 * conditionrlDRStartBallNotClose4 = new rlDRStartBallNotClose4();
    rlDRStartBallNotClose5 * conditionrlDRStartBallNotClose5 = new rlDRStartBallNotClose5();
    rlDRStopBallClose0 * conditionrlDRStopBallClose0 = new rlDRStopBallClose0();
    rlDRStopBallClose1 * conditionrlDRStopBallClose1 = new rlDRStopBallClose1();
    rlDRStopBallClose2 * conditionrlDRStopBallClose2 = new rlDRStopBallClose2();
    rlDRStopBallClose3 * conditionrlDRStopBallClose3 = new rlDRStopBallClose3();
    rlDRStopBallClose4 * conditionrlDRStopBallClose4 = new rlDRStopBallClose4();
    rlDRStopBallClose5 * conditionrlDRStopBallClose5 = new rlDRStopBallClose5();
    rlDRStopBallFar0 * conditionrlDRStopBallFar0 = new rlDRStopBallFar0();
    rlDRStopBallFar1 * conditionrlDRStopBallFar1 = new rlDRStopBallFar1();
    rlDRStopBallFar2 * conditionrlDRStopBallFar2 = new rlDRStopBallFar2();
    rlDRStopBallFar3 * conditionrlDRStopBallFar3 = new rlDRStopBallFar3();
    rlDRStopBallFar4 * conditionrlDRStopBallFar4 = new rlDRStopBallFar4();
    rlDRStopBallFar5 * conditionrlDRStopBallFar5 = new rlDRStopBallFar5();
    rlDRYellowDirectKickYellow0 * conditionrlDRYellowDirectKickYellow0 = new rlDRYellowDirectKickYellow0();
    rlDRYellowDirectKickYellow1 * conditionrlDRYellowDirectKickYellow1 = new rlDRYellowDirectKickYellow1();
    rlDRYellowDirectKickYellow2 * conditionrlDRYellowDirectKickYellow2 = new rlDRYellowDirectKickYellow2();
    rlDRYellowDirectKickYellow3 * conditionrlDRYellowDirectKickYellow3 = new rlDRYellowDirectKickYellow3();
    rlDRYellowDirectKickYellow4 * conditionrlDRYellowDirectKickYellow4 = new rlDRYellowDirectKickYellow4();
    rlDRYellowDirectKickYellow5 * conditionrlDRYellowDirectKickYellow5 = new rlDRYellowDirectKickYellow5();
    rlDRYellowPenaltyBlue0 * conditionrlDRYellowPenaltyBlue0 = new rlDRYellowPenaltyBlue0();
    rlDRYellowPenaltyBlue1 * conditionrlDRYellowPenaltyBlue1 = new rlDRYellowPenaltyBlue1();
    rlDRYellowPenaltyBlue2 * conditionrlDRYellowPenaltyBlue2 = new rlDRYellowPenaltyBlue2();
    rlDRYellowPenaltyBlue3 * conditionrlDRYellowPenaltyBlue3 = new rlDRYellowPenaltyBlue3();
    rlDRYellowPenaltyBlue4 * conditionrlDRYellowPenaltyBlue4 = new rlDRYellowPenaltyBlue4();
    rlDRYellowPenaltyBlue5 * conditionrlDRYellowPenaltyBlue5 = new rlDRYellowPenaltyBlue5();
    rlDRtYellowIndirectKickYellow0 * conditionrlDRtYellowIndirectKickYellow0 = new rlDRtYellowIndirectKickYellow0();
    rlDRtYellowIndirectKickYellow1 * conditionrlDRtYellowIndirectKickYellow1 = new rlDRtYellowIndirectKickYellow1();
    rlDRtYellowIndirectKickYellow2 * conditionrlDRtYellowIndirectKickYellow2 = new rlDRtYellowIndirectKickYellow2();
    rlDRtYellowIndirectKickYellow3 * conditionrlDRtYellowIndirectKickYellow3 = new rlDRtYellowIndirectKickYellow3();
    rlDRtYellowIndirectKickYellow4 * conditionrlDRtYellowIndirectKickYellow4 = new rlDRtYellowIndirectKickYellow4();
    rlDRtYellowIndirectKickYellow5 * conditionrlDRtYellowIndirectKickYellow5 = new rlDRtYellowIndirectKickYellow5();
    rlGkBluePenaltyYellow0 * conditionrlGkBluePenaltyYellow0 = new rlGkBluePenaltyYellow0();
    rlGkBluePenaltyYellow1 * conditionrlGkBluePenaltyYellow1 = new rlGkBluePenaltyYellow1();
    rlGkBluePenaltyYellow2 * conditionrlGkBluePenaltyYellow2 = new rlGkBluePenaltyYellow2();
    rlGkBluePenaltyYellow3 * conditionrlGkBluePenaltyYellow3 = new rlGkBluePenaltyYellow3();
    rlGkBluePenaltyYellow4 * conditionrlGkBluePenaltyYellow4 = new rlGkBluePenaltyYellow4();
    rlGkBluePenaltyYellow5 * conditionrlGkBluePenaltyYellow5 = new rlGkBluePenaltyYellow5();
    rlGkStartInsideArea0 * conditionrlGkStartInsideArea0 = new rlGkStartInsideArea0();
    rlGkStartInsideArea1 * conditionrlGkStartInsideArea1 = new rlGkStartInsideArea1();
    rlGkStartInsideArea2 * conditionrlGkStartInsideArea2 = new rlGkStartInsideArea2();
    rlGkStartInsideArea3 * conditionrlGkStartInsideArea3 = new rlGkStartInsideArea3();
    rlGkStartInsideArea4 * conditionrlGkStartInsideArea4 = new rlGkStartInsideArea4();
    rlGkStartInsideArea5 * conditionrlGkStartInsideArea5 = new rlGkStartInsideArea5();
    rlGkStartInsideAreaClosestBall0 * conditionrlGkStartInsideAreaClosestBall0 = new rlGkStartInsideAreaClosestBall0();
    rlGkStartInsideAreaClosestBall1 * conditionrlGkStartInsideAreaClosestBall1 = new rlGkStartInsideAreaClosestBall1();
    rlGkStartInsideAreaClosestBall2 * conditionrlGkStartInsideAreaClosestBall2 = new rlGkStartInsideAreaClosestBall2();
    rlGkStartInsideAreaClosestBall3 * conditionrlGkStartInsideAreaClosestBall3 = new rlGkStartInsideAreaClosestBall3();
    rlGkStartInsideAreaClosestBall4 * conditionrlGkStartInsideAreaClosestBall4 = new rlGkStartInsideAreaClosestBall4();
    rlGkStartInsideAreaClosestBall5 * conditionrlGkStartInsideAreaClosestBall5 = new rlGkStartInsideAreaClosestBall5();
    rlGkStartInsideAreaClosestBallKick0 * conditionrlGkStartInsideAreaClosestBallKick0 = new rlGkStartInsideAreaClosestBallKick0();
    rlGkStartInsideAreaClosestBallKick1 * conditionrlGkStartInsideAreaClosestBallKick1 = new rlGkStartInsideAreaClosestBallKick1();
    rlGkStartInsideAreaClosestBallKick2 * conditionrlGkStartInsideAreaClosestBallKick2 = new rlGkStartInsideAreaClosestBallKick2();
    rlGkStartInsideAreaClosestBallKick3 * conditionrlGkStartInsideAreaClosestBallKick3 = new rlGkStartInsideAreaClosestBallKick3();
    rlGkStartInsideAreaClosestBallKick4 * conditionrlGkStartInsideAreaClosestBallKick4 = new rlGkStartInsideAreaClosestBallKick4();
    rlGkStartInsideAreaClosestBallKick5 * conditionrlGkStartInsideAreaClosestBallKick5 = new rlGkStartInsideAreaClosestBallKick5();
    rlGkStartOutsideArea0 * conditionrlGkStartOutsideArea0 = new rlGkStartOutsideArea0();
    rlGkStartOutsideArea1 * conditionrlGkStartOutsideArea1 = new rlGkStartOutsideArea1();
    rlGkStartOutsideArea2 * conditionrlGkStartOutsideArea2 = new rlGkStartOutsideArea2();
    rlGkStartOutsideArea3 * conditionrlGkStartOutsideArea3 = new rlGkStartOutsideArea3();
    rlGkStartOutsideArea4 * conditionrlGkStartOutsideArea4 = new rlGkStartOutsideArea4();
    rlGkStartOutsideArea5 * conditionrlGkStartOutsideArea5 = new rlGkStartOutsideArea5();
    rlGkStopCloseGoal0 * conditionrlGkStopCloseGoal0 = new rlGkStopCloseGoal0();
    rlGkStopCloseGoal1 * conditionrlGkStopCloseGoal1 = new rlGkStopCloseGoal1();
    rlGkStopCloseGoal2 * conditionrlGkStopCloseGoal2 = new rlGkStopCloseGoal2();
    rlGkStopCloseGoal3 * conditionrlGkStopCloseGoal3 = new rlGkStopCloseGoal3();
    rlGkStopCloseGoal4 * conditionrlGkStopCloseGoal4 = new rlGkStopCloseGoal4();
    rlGkStopCloseGoal5 * conditionrlGkStopCloseGoal5 = new rlGkStopCloseGoal5();
    rlGkStopFarGoal0 * conditionrlGkStopFarGoal0 = new rlGkStopFarGoal0();
    rlGkStopFarGoal1 * conditionrlGkStopFarGoal1 = new rlGkStopFarGoal1();
    rlGkStopFarGoal2 * conditionrlGkStopFarGoal2 = new rlGkStopFarGoal2();
    rlGkStopFarGoal3 * conditionrlGkStopFarGoal3 = new rlGkStopFarGoal3();
    rlGkStopFarGoal4 * conditionrlGkStopFarGoal4 = new rlGkStopFarGoal4();
    rlGkStopFarGoal5 * conditionrlGkStopFarGoal5 = new rlGkStopFarGoal5();
    rlGkYellowPenaltyBlue0 * conditionrlGkYellowPenaltyBlue0 = new rlGkYellowPenaltyBlue0();
    rlGkYellowPenaltyBlue1 * conditionrlGkYellowPenaltyBlue1 = new rlGkYellowPenaltyBlue1();
    rlGkYellowPenaltyBlue2 * conditionrlGkYellowPenaltyBlue2 = new rlGkYellowPenaltyBlue2();
    rlGkYellowPenaltyBlue3 * conditionrlGkYellowPenaltyBlue3 = new rlGkYellowPenaltyBlue3();
    rlGkYellowPenaltyBlue4 * conditionrlGkYellowPenaltyBlue4 = new rlGkYellowPenaltyBlue4();
    rlGkYellowPenaltyBlue5 * conditionrlGkYellowPenaltyBlue5 = new rlGkYellowPenaltyBlue5();
    rlMOBlueDirectKick0 * conditionrlMOBlueDirectKick0 = new rlMOBlueDirectKick0();
    rlMOBlueDirectKick1 * conditionrlMOBlueDirectKick1 = new rlMOBlueDirectKick1();
    rlMOBlueDirectKick2 * conditionrlMOBlueDirectKick2 = new rlMOBlueDirectKick2();
    rlMOBlueDirectKick3 * conditionrlMOBlueDirectKick3 = new rlMOBlueDirectKick3();
    rlMOBlueDirectKick4 * conditionrlMOBlueDirectKick4 = new rlMOBlueDirectKick4();
    rlMOBlueDirectKick5 * conditionrlMOBlueDirectKick5 = new rlMOBlueDirectKick5();
    rlMOBlueIndirectKick0 * conditionrlMOBlueIndirectKick0 = new rlMOBlueIndirectKick0();
    rlMOBlueIndirectKick1 * conditionrlMOBlueIndirectKick1 = new rlMOBlueIndirectKick1();
    rlMOBlueIndirectKick2 * conditionrlMOBlueIndirectKick2 = new rlMOBlueIndirectKick2();
    rlMOBlueIndirectKick3 * conditionrlMOBlueIndirectKick3 = new rlMOBlueIndirectKick3();
    rlMOBlueIndirectKick4 * conditionrlMOBlueIndirectKick4 = new rlMOBlueIndirectKick4();
    rlMOBlueIndirectKick5 * conditionrlMOBlueIndirectKick5 = new rlMOBlueIndirectKick5();
    rlMOBlueKickoff0 * conditionrlMOBlueKickoff0 = new rlMOBlueKickoff0();
    rlMOBlueKickoff1 * conditionrlMOBlueKickoff1 = new rlMOBlueKickoff1();
    rlMOBlueKickoff2 * conditionrlMOBlueKickoff2 = new rlMOBlueKickoff2();
    rlMOBlueKickoff3 * conditionrlMOBlueKickoff3 = new rlMOBlueKickoff3();
    rlMOBlueKickoff4 * conditionrlMOBlueKickoff4 = new rlMOBlueKickoff4();
    rlMOBlueKickoff5 * conditionrlMOBlueKickoff5 = new rlMOBlueKickoff5();
    rlMOBluePenaltyBlue0 * conditionrlMOBluePenaltyBlue0 = new rlMOBluePenaltyBlue0();
    rlMOBluePenaltyBlue1 * conditionrlMOBluePenaltyBlue1 = new rlMOBluePenaltyBlue1();
    rlMOBluePenaltyBlue2 * conditionrlMOBluePenaltyBlue2 = new rlMOBluePenaltyBlue2();
    rlMOBluePenaltyBlue3 * conditionrlMOBluePenaltyBlue3 = new rlMOBluePenaltyBlue3();
    rlMOBluePenaltyBlue4 * conditionrlMOBluePenaltyBlue4 = new rlMOBluePenaltyBlue4();
    rlMOBluePenaltyBlue5 * conditionrlMOBluePenaltyBlue5 = new rlMOBluePenaltyBlue5();
    rlMOBluePenaltyYellow0 * conditionrlMOBluePenaltyYellow0 = new rlMOBluePenaltyYellow0();
    rlMOBluePenaltyYellow1 * conditionrlMOBluePenaltyYellow1 = new rlMOBluePenaltyYellow1();
    rlMOBluePenaltyYellow2 * conditionrlMOBluePenaltyYellow2 = new rlMOBluePenaltyYellow2();
    rlMOBluePenaltyYellow3 * conditionrlMOBluePenaltyYellow3 = new rlMOBluePenaltyYellow3();
    rlMOBluePenaltyYellow4 * conditionrlMOBluePenaltyYellow4 = new rlMOBluePenaltyYellow4();
    rlMOBluePenaltyYellow5 * conditionrlMOBluePenaltyYellow5 = new rlMOBluePenaltyYellow5();
    rlMOBlueReadyKickoffBlue0 * conditionrlMOBlueReadyKickoffBlue0 = new rlMOBlueReadyKickoffBlue0();
    rlMOBlueReadyKickoffBlue1 * conditionrlMOBlueReadyKickoffBlue1 = new rlMOBlueReadyKickoffBlue1();
    rlMOBlueReadyKickoffBlue2 * conditionrlMOBlueReadyKickoffBlue2 = new rlMOBlueReadyKickoffBlue2();
    rlMOBlueReadyKickoffBlue3 * conditionrlMOBlueReadyKickoffBlue3 = new rlMOBlueReadyKickoffBlue3();
    rlMOBlueReadyKickoffBlue4 * conditionrlMOBlueReadyKickoffBlue4 = new rlMOBlueReadyKickoffBlue4();
    rlMOBlueReadyKickoffBlue5 * conditionrlMOBlueReadyKickoffBlue5 = new rlMOBlueReadyKickoffBlue5();
    rlMOBlueReadyPenaltyBlue0 * conditionrlMOBlueReadyPenaltyBlue0 = new rlMOBlueReadyPenaltyBlue0();
    rlMOBlueReadyPenaltyBlue1 * conditionrlMOBlueReadyPenaltyBlue1 = new rlMOBlueReadyPenaltyBlue1();
    rlMOBlueReadyPenaltyBlue2 * conditionrlMOBlueReadyPenaltyBlue2 = new rlMOBlueReadyPenaltyBlue2();
    rlMOBlueReadyPenaltyBlue3 * conditionrlMOBlueReadyPenaltyBlue3 = new rlMOBlueReadyPenaltyBlue3();
    rlMOBlueReadyPenaltyBlue4 * conditionrlMOBlueReadyPenaltyBlue4 = new rlMOBlueReadyPenaltyBlue4();
    rlMOBlueReadyPenaltyBlue5 * conditionrlMOBlueReadyPenaltyBlue5 = new rlMOBlueReadyPenaltyBlue5();
    rlMOStop0 * conditionrlMOStop0 = new rlMOStop0();
    rlMOStop1 * conditionrlMOStop1 = new rlMOStop1();
    rlMOStop2 * conditionrlMOStop2 = new rlMOStop2();
    rlMOStop3 * conditionrlMOStop3 = new rlMOStop3();
    rlMOStop4 * conditionrlMOStop4 = new rlMOStop4();
    rlMOStop5 * conditionrlMOStop5 = new rlMOStop5();
    rlMOYellowDirectKick0 * conditionrlMOYellowDirectKick0 = new rlMOYellowDirectKick0();
    rlMOYellowDirectKick1 * conditionrlMOYellowDirectKick1 = new rlMOYellowDirectKick1();
    rlMOYellowDirectKick2 * conditionrlMOYellowDirectKick2 = new rlMOYellowDirectKick2();
    rlMOYellowDirectKick3 * conditionrlMOYellowDirectKick3 = new rlMOYellowDirectKick3();
    rlMOYellowDirectKick4 * conditionrlMOYellowDirectKick4 = new rlMOYellowDirectKick4();
    rlMOYellowDirectKick5 * conditionrlMOYellowDirectKick5 = new rlMOYellowDirectKick5();
    rlMOYellowIndirectKick0 * conditionrlMOYellowIndirectKick0 = new rlMOYellowIndirectKick0();
    rlMOYellowIndirectKick1 * conditionrlMOYellowIndirectKick1 = new rlMOYellowIndirectKick1();
    rlMOYellowIndirectKick2 * conditionrlMOYellowIndirectKick2 = new rlMOYellowIndirectKick2();
    rlMOYellowIndirectKick3 * conditionrlMOYellowIndirectKick3 = new rlMOYellowIndirectKick3();
    rlMOYellowIndirectKick4 * conditionrlMOYellowIndirectKick4 = new rlMOYellowIndirectKick4();
    rlMOYellowIndirectKick5 * conditionrlMOYellowIndirectKick5 = new rlMOYellowIndirectKick5();
    rlMOYellowKickoff0 * conditionrlMOYellowKickoff0 = new rlMOYellowKickoff0();
    rlMOYellowKickoff1 * conditionrlMOYellowKickoff1 = new rlMOYellowKickoff1();
    rlMOYellowKickoff2 * conditionrlMOYellowKickoff2 = new rlMOYellowKickoff2();
    rlMOYellowKickoff3 * conditionrlMOYellowKickoff3 = new rlMOYellowKickoff3();
    rlMOYellowKickoff4 * conditionrlMOYellowKickoff4 = new rlMOYellowKickoff4();
    rlMOYellowKickoff5 * conditionrlMOYellowKickoff5 = new rlMOYellowKickoff5();
    rlMOYellowPenaltyBlue0 * conditionrlMOYellowPenaltyBlue0 = new rlMOYellowPenaltyBlue0();
    rlMOYellowPenaltyBlue1 * conditionrlMOYellowPenaltyBlue1 = new rlMOYellowPenaltyBlue1();
    rlMOYellowPenaltyBlue2 * conditionrlMOYellowPenaltyBlue2 = new rlMOYellowPenaltyBlue2();
    rlMOYellowPenaltyBlue3 * conditionrlMOYellowPenaltyBlue3 = new rlMOYellowPenaltyBlue3();
    rlMOYellowPenaltyBlue4 * conditionrlMOYellowPenaltyBlue4 = new rlMOYellowPenaltyBlue4();
    rlMOYellowPenaltyBlue5 * conditionrlMOYellowPenaltyBlue5 = new rlMOYellowPenaltyBlue5();
    rlMOYellowPenaltyYellow0 * conditionrlMOYellowPenaltyYellow0 = new rlMOYellowPenaltyYellow0();
    rlMOYellowPenaltyYellow1 * conditionrlMOYellowPenaltyYellow1 = new rlMOYellowPenaltyYellow1();
    rlMOYellowPenaltyYellow2 * conditionrlMOYellowPenaltyYellow2 = new rlMOYellowPenaltyYellow2();
    rlMOYellowPenaltyYellow3 * conditionrlMOYellowPenaltyYellow3 = new rlMOYellowPenaltyYellow3();
    rlMOYellowPenaltyYellow4 * conditionrlMOYellowPenaltyYellow4 = new rlMOYellowPenaltyYellow4();
    rlMOYellowPenaltyYellow5 * conditionrlMOYellowPenaltyYellow5 = new rlMOYellowPenaltyYellow5();
    rlMOYellowReadyKickoffYellow0 * conditionrlMOYellowReadyKickoffYellow0 = new rlMOYellowReadyKickoffYellow0();
    rlMOYellowReadyKickoffYellow1 * conditionrlMOYellowReadyKickoffYellow1 = new rlMOYellowReadyKickoffYellow1();
    rlMOYellowReadyKickoffYellow2 * conditionrlMOYellowReadyKickoffYellow2 = new rlMOYellowReadyKickoffYellow2();
    rlMOYellowReadyKickoffYellow3 * conditionrlMOYellowReadyKickoffYellow3 = new rlMOYellowReadyKickoffYellow3();
    rlMOYellowReadyKickoffYellow4 * conditionrlMOYellowReadyKickoffYellow4 = new rlMOYellowReadyKickoffYellow4();
    rlMOYellowReadyKickoffYellow5 * conditionrlMOYellowReadyKickoffYellow5 = new rlMOYellowReadyKickoffYellow5();
    rlMOYellowReadyPenaltyYellow0 * conditionrlMOYellowReadyPenaltyYellow0 = new rlMOYellowReadyPenaltyYellow0();
    rlMOYellowReadyPenaltyYellow1 * conditionrlMOYellowReadyPenaltyYellow1 = new rlMOYellowReadyPenaltyYellow1();
    rlMOYellowReadyPenaltyYellow2 * conditionrlMOYellowReadyPenaltyYellow2 = new rlMOYellowReadyPenaltyYellow2();
    rlMOYellowReadyPenaltyYellow3 * conditionrlMOYellowReadyPenaltyYellow3 = new rlMOYellowReadyPenaltyYellow3();
    rlMOYellowReadyPenaltyYellow4 * conditionrlMOYellowReadyPenaltyYellow4 = new rlMOYellowReadyPenaltyYellow4();
    rlMOYellowReadyPenaltyYellow5 * conditionrlMOYellowReadyPenaltyYellow5 = new rlMOYellowReadyPenaltyYellow5();
    rlRobotMoveX0 * conditionrlRobotMoveX0 = new rlRobotMoveX0();
    rlRobotMoveX1 * conditionrlRobotMoveX1 = new rlRobotMoveX1();
    rlRobotMoveX2 * conditionrlRobotMoveX2 = new rlRobotMoveX2();
    rlRobotMoveX3 * conditionrlRobotMoveX3 = new rlRobotMoveX3();
    rlRobotMoveX4 * conditionrlRobotMoveX4 = new rlRobotMoveX4();
    rlRobotMoveX5 * conditionrlRobotMoveX5 = new rlRobotMoveX5();
    rlRobotMoveY0 * conditionrlRobotMoveY0 = new rlRobotMoveY0();
    rlRobotMoveY1 * conditionrlRobotMoveY1 = new rlRobotMoveY1();
    rlRobotMoveY2 * conditionrlRobotMoveY2 = new rlRobotMoveY2();
    rlRobotMoveY3 * conditionrlRobotMoveY3 = new rlRobotMoveY3();
    rlRobotMoveY4 * conditionrlRobotMoveY4 = new rlRobotMoveY4();
    rlRobotMoveY5 * conditionrlRobotMoveY5 = new rlRobotMoveY5();
    rlSLBlueDirectKick0 * conditionrlSLBlueDirectKick0 = new rlSLBlueDirectKick0();
    rlSLBlueDirectKick1 * conditionrlSLBlueDirectKick1 = new rlSLBlueDirectKick1();
    rlSLBlueDirectKick2 * conditionrlSLBlueDirectKick2 = new rlSLBlueDirectKick2();
    rlSLBlueDirectKick3 * conditionrlSLBlueDirectKick3 = new rlSLBlueDirectKick3();
    rlSLBlueDirectKick4 * conditionrlSLBlueDirectKick4 = new rlSLBlueDirectKick4();
    rlSLBlueDirectKick5 * conditionrlSLBlueDirectKick5 = new rlSLBlueDirectKick5();
    rlSLBlueIndirectKick0 * conditionrlSLBlueIndirectKick0 = new rlSLBlueIndirectKick0();
    rlSLBlueIndirectKick1 * conditionrlSLBlueIndirectKick1 = new rlSLBlueIndirectKick1();
    rlSLBlueIndirectKick2 * conditionrlSLBlueIndirectKick2 = new rlSLBlueIndirectKick2();
    rlSLBlueIndirectKick3 * conditionrlSLBlueIndirectKick3 = new rlSLBlueIndirectKick3();
    rlSLBlueIndirectKick4 * conditionrlSLBlueIndirectKick4 = new rlSLBlueIndirectKick4();
    rlSLBlueIndirectKick5 * conditionrlSLBlueIndirectKick5 = new rlSLBlueIndirectKick5();
    rlSLBluePenaltyBlue0 * conditionrlSLBluePenaltyBlue0 = new rlSLBluePenaltyBlue0();
    rlSLBluePenaltyBlue1 * conditionrlSLBluePenaltyBlue1 = new rlSLBluePenaltyBlue1();
    rlSLBluePenaltyBlue2 * conditionrlSLBluePenaltyBlue2 = new rlSLBluePenaltyBlue2();
    rlSLBluePenaltyBlue3 * conditionrlSLBluePenaltyBlue3 = new rlSLBluePenaltyBlue3();
    rlSLBluePenaltyBlue4 * conditionrlSLBluePenaltyBlue4 = new rlSLBluePenaltyBlue4();
    rlSLBluePenaltyBlue5 * conditionrlSLBluePenaltyBlue5 = new rlSLBluePenaltyBlue5();
    rlSLBluePenaltyYellow0 * conditionrlSLBluePenaltyYellow0 = new rlSLBluePenaltyYellow0();
    rlSLBluePenaltyYellow1 * conditionrlSLBluePenaltyYellow1 = new rlSLBluePenaltyYellow1();
    rlSLBluePenaltyYellow2 * conditionrlSLBluePenaltyYellow2 = new rlSLBluePenaltyYellow2();
    rlSLBluePenaltyYellow3 * conditionrlSLBluePenaltyYellow3 = new rlSLBluePenaltyYellow3();
    rlSLBluePenaltyYellow4 * conditionrlSLBluePenaltyYellow4 = new rlSLBluePenaltyYellow4();
    rlSLBluePenaltyYellow5 * conditionrlSLBluePenaltyYellow5 = new rlSLBluePenaltyYellow5();
    rlSLHaltClose0 * conditionrlSLHaltClose0 = new rlSLHaltClose0();
    rlSLHaltClose1 * conditionrlSLHaltClose1 = new rlSLHaltClose1();
    rlSLHaltClose2 * conditionrlSLHaltClose2 = new rlSLHaltClose2();
    rlSLHaltClose3 * conditionrlSLHaltClose3 = new rlSLHaltClose3();
    rlSLHaltClose4 * conditionrlSLHaltClose4 = new rlSLHaltClose4();
    rlSLHaltClose5 * conditionrlSLHaltClose5 = new rlSLHaltClose5();
    rlSLHaltCloseReady0 * conditionrlSLHaltCloseReady0 = new rlSLHaltCloseReady0();
    rlSLHaltCloseReady1 * conditionrlSLHaltCloseReady1 = new rlSLHaltCloseReady1();
    rlSLHaltCloseReady2 * conditionrlSLHaltCloseReady2 = new rlSLHaltCloseReady2();
    rlSLHaltCloseReady3 * conditionrlSLHaltCloseReady3 = new rlSLHaltCloseReady3();
    rlSLHaltCloseReady4 * conditionrlSLHaltCloseReady4 = new rlSLHaltCloseReady4();
    rlSLHaltCloseReady5 * conditionrlSLHaltCloseReady5 = new rlSLHaltCloseReady5();
    rlSLHaltNotClose0 * conditionrlSLHaltNotClose0 = new rlSLHaltNotClose0();
    rlSLHaltNotClose1 * conditionrlSLHaltNotClose1 = new rlSLHaltNotClose1();
    rlSLHaltNotClose2 * conditionrlSLHaltNotClose2 = new rlSLHaltNotClose2();
    rlSLHaltNotClose3 * conditionrlSLHaltNotClose3 = new rlSLHaltNotClose3();
    rlSLHaltNotClose4 * conditionrlSLHaltNotClose4 = new rlSLHaltNotClose4();
    rlSLHaltNotClose5 * conditionrlSLHaltNotClose5 = new rlSLHaltNotClose5();
    rlSLStartBallNotClose0 * conditionrlSLStartBallNotClose0 = new rlSLStartBallNotClose0();
    rlSLStartBallNotClose1 * conditionrlSLStartBallNotClose1 = new rlSLStartBallNotClose1();
    rlSLStartBallNotClose2 * conditionrlSLStartBallNotClose2 = new rlSLStartBallNotClose2();
    rlSLStartBallNotClose3 * conditionrlSLStartBallNotClose3 = new rlSLStartBallNotClose3();
    rlSLStartBallNotClose4 * conditionrlSLStartBallNotClose4 = new rlSLStartBallNotClose4();
    rlSLStartBallNotClose5 * conditionrlSLStartBallNotClose5 = new rlSLStartBallNotClose5();
    rlSLStopTeamLeft0 * conditionrlSLStopTeamLeft0 = new rlSLStopTeamLeft0();
    rlSLStopTeamLeft1 * conditionrlSLStopTeamLeft1 = new rlSLStopTeamLeft1();
    rlSLStopTeamLeft2 * conditionrlSLStopTeamLeft2 = new rlSLStopTeamLeft2();
    rlSLStopTeamLeft3 * conditionrlSLStopTeamLeft3 = new rlSLStopTeamLeft3();
    rlSLStopTeamLeft4 * conditionrlSLStopTeamLeft4 = new rlSLStopTeamLeft4();
    rlSLStopTeamLeft5 * conditionrlSLStopTeamLeft5 = new rlSLStopTeamLeft5();
    rlSLStopTeamRight0 * conditionrlSLStopTeamRight0 = new rlSLStopTeamRight0();
    rlSLStopTeamRight1 * conditionrlSLStopTeamRight1 = new rlSLStopTeamRight1();
    rlSLStopTeamRight2 * conditionrlSLStopTeamRight2 = new rlSLStopTeamRight2();
    rlSLStopTeamRight3 * conditionrlSLStopTeamRight3 = new rlSLStopTeamRight3();
    rlSLStopTeamRight4 * conditionrlSLStopTeamRight4 = new rlSLStopTeamRight4();
    rlSLStopTeamRight5 * conditionrlSLStopTeamRight5 = new rlSLStopTeamRight5();
    rlSLYellowDirectKick0 * conditionrlSLYellowDirectKick0 = new rlSLYellowDirectKick0();
    rlSLYellowDirectKick1 * conditionrlSLYellowDirectKick1 = new rlSLYellowDirectKick1();
    rlSLYellowDirectKick2 * conditionrlSLYellowDirectKick2 = new rlSLYellowDirectKick2();
    rlSLYellowDirectKick3 * conditionrlSLYellowDirectKick3 = new rlSLYellowDirectKick3();
    rlSLYellowDirectKick4 * conditionrlSLYellowDirectKick4 = new rlSLYellowDirectKick4();
    rlSLYellowDirectKick5 * conditionrlSLYellowDirectKick5 = new rlSLYellowDirectKick5();
    rlSLYellowIndirectKick0 * conditionrlSLYellowIndirectKick0 = new rlSLYellowIndirectKick0();
    rlSLYellowIndirectKick1 * conditionrlSLYellowIndirectKick1 = new rlSLYellowIndirectKick1();
    rlSLYellowIndirectKick2 * conditionrlSLYellowIndirectKick2 = new rlSLYellowIndirectKick2();
    rlSLYellowIndirectKick3 * conditionrlSLYellowIndirectKick3 = new rlSLYellowIndirectKick3();
    rlSLYellowIndirectKick4 * conditionrlSLYellowIndirectKick4 = new rlSLYellowIndirectKick4();
    rlSLYellowIndirectKick5 * conditionrlSLYellowIndirectKick5 = new rlSLYellowIndirectKick5();
    rlSLYellowPenaltyBlue0 * conditionrlSLYellowPenaltyBlue0 = new rlSLYellowPenaltyBlue0();
    rlSLYellowPenaltyBlue1 * conditionrlSLYellowPenaltyBlue1 = new rlSLYellowPenaltyBlue1();
    rlSLYellowPenaltyBlue2 * conditionrlSLYellowPenaltyBlue2 = new rlSLYellowPenaltyBlue2();
    rlSLYellowPenaltyBlue3 * conditionrlSLYellowPenaltyBlue3 = new rlSLYellowPenaltyBlue3();
    rlSLYellowPenaltyBlue4 * conditionrlSLYellowPenaltyBlue4 = new rlSLYellowPenaltyBlue4();
    rlSLYellowPenaltyBlue5 * conditionrlSLYellowPenaltyBlue5 = new rlSLYellowPenaltyBlue5();
    rlSLYellowPenaltyYellow0 * conditionrlSLYellowPenaltyYellow0 = new rlSLYellowPenaltyYellow0();
    rlSLYellowPenaltyYellow1 * conditionrlSLYellowPenaltyYellow1 = new rlSLYellowPenaltyYellow1();
    rlSLYellowPenaltyYellow2 * conditionrlSLYellowPenaltyYellow2 = new rlSLYellowPenaltyYellow2();
    rlSLYellowPenaltyYellow3 * conditionrlSLYellowPenaltyYellow3 = new rlSLYellowPenaltyYellow3();
    rlSLYellowPenaltyYellow4 * conditionrlSLYellowPenaltyYellow4 = new rlSLYellowPenaltyYellow4();
    rlSLYellowPenaltyYellow5 * conditionrlSLYellowPenaltyYellow5 = new rlSLYellowPenaltyYellow5();
    rlSRBlueDirectKick0 * conditionrlSRBlueDirectKick0 = new rlSRBlueDirectKick0();
    rlSRBlueDirectKick1 * conditionrlSRBlueDirectKick1 = new rlSRBlueDirectKick1();
    rlSRBlueDirectKick2 * conditionrlSRBlueDirectKick2 = new rlSRBlueDirectKick2();
    rlSRBlueDirectKick3 * conditionrlSRBlueDirectKick3 = new rlSRBlueDirectKick3();
    rlSRBlueDirectKick4 * conditionrlSRBlueDirectKick4 = new rlSRBlueDirectKick4();
    rlSRBlueDirectKick5 * conditionrlSRBlueDirectKick5 = new rlSRBlueDirectKick5();
    rlSRBlueIndirectKick0 * conditionrlSRBlueIndirectKick0 = new rlSRBlueIndirectKick0();
    rlSRBlueIndirectKick1 * conditionrlSRBlueIndirectKick1 = new rlSRBlueIndirectKick1();
    rlSRBlueIndirectKick2 * conditionrlSRBlueIndirectKick2 = new rlSRBlueIndirectKick2();
    rlSRBlueIndirectKick3 * conditionrlSRBlueIndirectKick3 = new rlSRBlueIndirectKick3();
    rlSRBlueIndirectKick4 * conditionrlSRBlueIndirectKick4 = new rlSRBlueIndirectKick4();
    rlSRBlueIndirectKick5 * conditionrlSRBlueIndirectKick5 = new rlSRBlueIndirectKick5();
    rlSRBluePenaltyBlue0 * conditionrlSRBluePenaltyBlue0 = new rlSRBluePenaltyBlue0();
    rlSRBluePenaltyBlue1 * conditionrlSRBluePenaltyBlue1 = new rlSRBluePenaltyBlue1();
    rlSRBluePenaltyBlue2 * conditionrlSRBluePenaltyBlue2 = new rlSRBluePenaltyBlue2();
    rlSRBluePenaltyBlue3 * conditionrlSRBluePenaltyBlue3 = new rlSRBluePenaltyBlue3();
    rlSRBluePenaltyBlue4 * conditionrlSRBluePenaltyBlue4 = new rlSRBluePenaltyBlue4();
    rlSRBluePenaltyBlue5 * conditionrlSRBluePenaltyBlue5 = new rlSRBluePenaltyBlue5();
    rlSRBluePenaltyYellow0 * conditionrlSRBluePenaltyYellow0 = new rlSRBluePenaltyYellow0();
    rlSRBluePenaltyYellow1 * conditionrlSRBluePenaltyYellow1 = new rlSRBluePenaltyYellow1();
    rlSRBluePenaltyYellow2 * conditionrlSRBluePenaltyYellow2 = new rlSRBluePenaltyYellow2();
    rlSRBluePenaltyYellow3 * conditionrlSRBluePenaltyYellow3 = new rlSRBluePenaltyYellow3();
    rlSRBluePenaltyYellow4 * conditionrlSRBluePenaltyYellow4 = new rlSRBluePenaltyYellow4();
    rlSRBluePenaltyYellow5 * conditionrlSRBluePenaltyYellow5 = new rlSRBluePenaltyYellow5();
    rlSRHaltClose0 * conditionrlSRHaltClose0 = new rlSRHaltClose0();
    rlSRHaltClose1 * conditionrlSRHaltClose1 = new rlSRHaltClose1();
    rlSRHaltClose2 * conditionrlSRHaltClose2 = new rlSRHaltClose2();
    rlSRHaltClose3 * conditionrlSRHaltClose3 = new rlSRHaltClose3();
    rlSRHaltClose4 * conditionrlSRHaltClose4 = new rlSRHaltClose4();
    rlSRHaltClose5 * conditionrlSRHaltClose5 = new rlSRHaltClose5();
    rlSRHaltCloseReady0 * conditionrlSRHaltCloseReady0 = new rlSRHaltCloseReady0();
    rlSRHaltCloseReady1 * conditionrlSRHaltCloseReady1 = new rlSRHaltCloseReady1();
    rlSRHaltCloseReady2 * conditionrlSRHaltCloseReady2 = new rlSRHaltCloseReady2();
    rlSRHaltCloseReady3 * conditionrlSRHaltCloseReady3 = new rlSRHaltCloseReady3();
    rlSRHaltCloseReady4 * conditionrlSRHaltCloseReady4 = new rlSRHaltCloseReady4();
    rlSRHaltCloseReady5 * conditionrlSRHaltCloseReady5 = new rlSRHaltCloseReady5();
    rlSRHaltNotClose0 * conditionrlSRHaltNotClose0 = new rlSRHaltNotClose0();
    rlSRHaltNotClose1 * conditionrlSRHaltNotClose1 = new rlSRHaltNotClose1();
    rlSRHaltNotClose2 * conditionrlSRHaltNotClose2 = new rlSRHaltNotClose2();
    rlSRHaltNotClose3 * conditionrlSRHaltNotClose3 = new rlSRHaltNotClose3();
    rlSRHaltNotClose4 * conditionrlSRHaltNotClose4 = new rlSRHaltNotClose4();
    rlSRHaltNotClose5 * conditionrlSRHaltNotClose5 = new rlSRHaltNotClose5();
    rlSRStartBallNotClose0 * conditionrlSRStartBallNotClose0 = new rlSRStartBallNotClose0();
    rlSRStartBallNotClose1 * conditionrlSRStartBallNotClose1 = new rlSRStartBallNotClose1();
    rlSRStartBallNotClose2 * conditionrlSRStartBallNotClose2 = new rlSRStartBallNotClose2();
    rlSRStartBallNotClose3 * conditionrlSRStartBallNotClose3 = new rlSRStartBallNotClose3();
    rlSRStartBallNotClose4 * conditionrlSRStartBallNotClose4 = new rlSRStartBallNotClose4();
    rlSRStartBallNotClose5 * conditionrlSRStartBallNotClose5 = new rlSRStartBallNotClose5();
    rlSRStopTeamLeft0 * conditionrlSRStopTeamLeft0 = new rlSRStopTeamLeft0();
    rlSRStopTeamLeft1 * conditionrlSRStopTeamLeft1 = new rlSRStopTeamLeft1();
    rlSRStopTeamLeft2 * conditionrlSRStopTeamLeft2 = new rlSRStopTeamLeft2();
    rlSRStopTeamLeft3 * conditionrlSRStopTeamLeft3 = new rlSRStopTeamLeft3();
    rlSRStopTeamLeft4 * conditionrlSRStopTeamLeft4 = new rlSRStopTeamLeft4();
    rlSRStopTeamLeft5 * conditionrlSRStopTeamLeft5 = new rlSRStopTeamLeft5();
    rlSRStopTeamRight0 * conditionrlSRStopTeamRight0 = new rlSRStopTeamRight0();
    rlSRStopTeamRight1 * conditionrlSRStopTeamRight1 = new rlSRStopTeamRight1();
    rlSRStopTeamRight2 * conditionrlSRStopTeamRight2 = new rlSRStopTeamRight2();
    rlSRStopTeamRight3 * conditionrlSRStopTeamRight3 = new rlSRStopTeamRight3();
    rlSRStopTeamRight4 * conditionrlSRStopTeamRight4 = new rlSRStopTeamRight4();
    rlSRStopTeamRight5 * conditionrlSRStopTeamRight5 = new rlSRStopTeamRight5();
    rlSRYellowDirectKick0 * conditionrlSRYellowDirectKick0 = new rlSRYellowDirectKick0();
    rlSRYellowDirectKick1 * conditionrlSRYellowDirectKick1 = new rlSRYellowDirectKick1();
    rlSRYellowDirectKick2 * conditionrlSRYellowDirectKick2 = new rlSRYellowDirectKick2();
    rlSRYellowDirectKick3 * conditionrlSRYellowDirectKick3 = new rlSRYellowDirectKick3();
    rlSRYellowDirectKick4 * conditionrlSRYellowDirectKick4 = new rlSRYellowDirectKick4();
    rlSRYellowDirectKick5 * conditionrlSRYellowDirectKick5 = new rlSRYellowDirectKick5();
    rlSRYellowIndirectKick0 * conditionrlSRYellowIndirectKick0 = new rlSRYellowIndirectKick0();
    rlSRYellowIndirectKick1 * conditionrlSRYellowIndirectKick1 = new rlSRYellowIndirectKick1();
    rlSRYellowIndirectKick2 * conditionrlSRYellowIndirectKick2 = new rlSRYellowIndirectKick2();
    rlSRYellowIndirectKick3 * conditionrlSRYellowIndirectKick3 = new rlSRYellowIndirectKick3();
    rlSRYellowIndirectKick4 * conditionrlSRYellowIndirectKick4 = new rlSRYellowIndirectKick4();
    rlSRYellowIndirectKick5 * conditionrlSRYellowIndirectKick5 = new rlSRYellowIndirectKick5();
    rlSRYellowsPenaltyBlue0 * conditionrlSRYellowsPenaltyBlue0 = new rlSRYellowsPenaltyBlue0();
    rlSRYellowsPenaltyBlue1 * conditionrlSRYellowsPenaltyBlue1 = new rlSRYellowsPenaltyBlue1();
    rlSRYellowsPenaltyBlue2 * conditionrlSRYellowsPenaltyBlue2 = new rlSRYellowsPenaltyBlue2();
    rlSRYellowsPenaltyBlue3 * conditionrlSRYellowsPenaltyBlue3 = new rlSRYellowsPenaltyBlue3();
    rlSRYellowsPenaltyBlue4 * conditionrlSRYellowsPenaltyBlue4 = new rlSRYellowsPenaltyBlue4();
    rlSRYellowsPenaltyBlue5 * conditionrlSRYellowsPenaltyBlue5 = new rlSRYellowsPenaltyBlue5();
    rlSRYellowsPenaltyYellow0 * conditionrlSRYellowsPenaltyYellow0 = new rlSRYellowsPenaltyYellow0();
    rlSRYellowsPenaltyYellow1 * conditionrlSRYellowsPenaltyYellow1 = new rlSRYellowsPenaltyYellow1();
    rlSRYellowsPenaltyYellow2 * conditionrlSRYellowsPenaltyYellow2 = new rlSRYellowsPenaltyYellow2();
    rlSRYellowsPenaltyYellow3 * conditionrlSRYellowsPenaltyYellow3 = new rlSRYellowsPenaltyYellow3();
    rlSRYellowsPenaltyYellow4 * conditionrlSRYellowsPenaltyYellow4 = new rlSRYellowsPenaltyYellow4();
    rlSRYellowsPenaltyYellow5 * conditionrlSRYellowsPenaltyYellow5 = new rlSRYellowsPenaltyYellow5();
    rlStartEnemyFieldKick0 * conditionrlStartEnemyFieldKick0 = new rlStartEnemyFieldKick0();
    rlStartEnemyFieldKick1 * conditionrlStartEnemyFieldKick1 = new rlStartEnemyFieldKick1();
    rlStartEnemyFieldKick2 * conditionrlStartEnemyFieldKick2 = new rlStartEnemyFieldKick2();
    rlStartEnemyFieldKick3 * conditionrlStartEnemyFieldKick3 = new rlStartEnemyFieldKick3();
    rlStartEnemyFieldKick4 * conditionrlStartEnemyFieldKick4 = new rlStartEnemyFieldKick4();
    rlStartEnemyFieldKick5 * conditionrlStartEnemyFieldKick5 = new rlStartEnemyFieldKick5();
    rlStartEnemyFieldPositionKick0 * conditionrlStartEnemyFieldPositionKick0 = new rlStartEnemyFieldPositionKick0();
    rlStartEnemyFieldPositionKick1 * conditionrlStartEnemyFieldPositionKick1 = new rlStartEnemyFieldPositionKick1();
    rlStartEnemyFieldPositionKick2 * conditionrlStartEnemyFieldPositionKick2 = new rlStartEnemyFieldPositionKick2();
    rlStartEnemyFieldPositionKick3 * conditionrlStartEnemyFieldPositionKick3 = new rlStartEnemyFieldPositionKick3();
    rlStartEnemyFieldPositionKick4 * conditionrlStartEnemyFieldPositionKick4 = new rlStartEnemyFieldPositionKick4();
    rlStartEnemyFieldPositionKick5 * conditionrlStartEnemyFieldPositionKick5 = new rlStartEnemyFieldPositionKick5();
    rlStartFreePartner0 * conditionrlStartFreePartner0 = new rlStartFreePartner0();
    rlStartFreePartner1 * conditionrlStartFreePartner1 = new rlStartFreePartner1();
    rlStartFreePartner2 * conditionrlStartFreePartner2 = new rlStartFreePartner2();
    rlStartFreePartner3 * conditionrlStartFreePartner3 = new rlStartFreePartner3();
    rlStartFreePartner4 * conditionrlStartFreePartner4 = new rlStartFreePartner4();
    rlStartFreePartner5 * conditionrlStartFreePartner5 = new rlStartFreePartner5();
    rlStartFreePartnerPass0 * conditionrlStartFreePartnerPass0 = new rlStartFreePartnerPass0();
    rlStartFreePartnerPass1 * conditionrlStartFreePartnerPass1 = new rlStartFreePartnerPass1();
    rlStartFreePartnerPass2 * conditionrlStartFreePartnerPass2 = new rlStartFreePartnerPass2();
    rlStartFreePartnerPass3 * conditionrlStartFreePartnerPass3 = new rlStartFreePartnerPass3();
    rlStartFreePartnerPass4 * conditionrlStartFreePartnerPass4 = new rlStartFreePartnerPass4();
    rlStartFreePartnerPass5 * conditionrlStartFreePartnerPass5 = new rlStartFreePartnerPass5();
    rlStartNoFreePartner0 * conditionrlStartNoFreePartner0 = new rlStartNoFreePartner0();
    rlStartNoFreePartner1 * conditionrlStartNoFreePartner1 = new rlStartNoFreePartner1();
    rlStartNoFreePartner2 * conditionrlStartNoFreePartner2 = new rlStartNoFreePartner2();
    rlStartNoFreePartner3 * conditionrlStartNoFreePartner3 = new rlStartNoFreePartner3();
    rlStartNoFreePartner4 * conditionrlStartNoFreePartner4 = new rlStartNoFreePartner4();
    rlStartNoFreePartner5 * conditionrlStartNoFreePartner5 = new rlStartNoFreePartner5();
    rlStartNoFreePartnerKick0 * conditionrlStartNoFreePartnerKick0 = new rlStartNoFreePartnerKick0();
    rlStartNoFreePartnerKick1 * conditionrlStartNoFreePartnerKick1 = new rlStartNoFreePartnerKick1();
    rlStartNoFreePartnerKick2 * conditionrlStartNoFreePartnerKick2 = new rlStartNoFreePartnerKick2();
    rlStartNoFreePartnerKick3 * conditionrlStartNoFreePartnerKick3 = new rlStartNoFreePartnerKick3();
    rlStartNoFreePartnerKick4 * conditionrlStartNoFreePartnerKick4 = new rlStartNoFreePartnerKick4();
    rlStartNoFreePartnerKick5 * conditionrlStartNoFreePartnerKick5 = new rlStartNoFreePartnerKick5();
    rlStartTargetToBall0 * conditionrlStartTargetToBall0 = new rlStartTargetToBall0();
    rlStartTargetToBall1 * conditionrlStartTargetToBall1 = new rlStartTargetToBall1();
    rlStartTargetToBall2 * conditionrlStartTargetToBall2 = new rlStartTargetToBall2();
    rlStartTargetToBall3 * conditionrlStartTargetToBall3 = new rlStartTargetToBall3();
    rlStartTargetToBall4 * conditionrlStartTargetToBall4 = new rlStartTargetToBall4();
    rlStartTargetToBall5 * conditionrlStartTargetToBall5 = new rlStartTargetToBall5();
    rlTeste * conditionrlTeste = new rlTeste();

    Robotrobot1 * robot1 = new Robotrobot1(conditionrlAngleMove0,conditionrlBallFar0,conditionrlStartTargetToBall0,conditionrlDLBlueDirectKickBlue0,conditionrlDLtBlueIndirectBlue0,conditionrlDLtBluePenaltyYellow0,conditionrlDRBlueDirectKickBlue0,conditionrlDRBlueIndirectKickBlue0,conditionrlDRBluePenaltyYellow0,conditionrlGkBluePenaltyYellow0,conditionrlMOBlueDirectKick0,conditionrlMOBlueIndirectKick0,conditionrlMOBlueKickoff0,conditionrlMOBluePenaltyBlue0,conditionrlMOBluePenaltyYellow0,conditionrlMOBlueReadyKickoffBlue0,conditionrlMOBlueReadyPenaltyBlue0,conditionrlSLBlueDirectKick0,conditionrlSLBlueIndirectKick0,conditionrlSLBluePenaltyBlue0,conditionrlSLBluePenaltyYellow0,conditionrlSRBlueDirectKick0,conditionrlSRBlueIndirectKick0,conditionrlSRBluePenaltyBlue0,conditionrlSRBluePenaltyYellow0,conditionrlDLStartNotClose0,conditionrlDLStopBallClose0,conditionrlDLYellowDirectKickYellow0,conditionrlDLYellowIndirectYellow0,conditionrlDLYellowPenaltyBlue0,conditionrlDLtStopBallFar0,conditionrlDRStartBallNotClose0,conditionrlGkStartInsideArea0,conditionrlSLHaltNotClose0,conditionrlSLStartBallNotClose0,conditionrlSRHaltNotClose0,conditionrlSRStartBallNotClose0,conditionrlGkStartInsideAreaClosestBall0,conditionrlGkStartInsideAreaClosestBallKick0,conditionrlGkStartOutsideArea0,conditionrlMOYellowReadyKickoffYellow0,conditionrlMOYellowReadyPenaltyYellow0,conditionrlStartEnemyFieldPositionKick0,conditionrlStartFreePartner0,conditionrlStartFreePartnerPass0,conditionrlStartNoFreePartner0,conditionrlDRStopBallClose0,conditionrlGkStopCloseGoal0,conditionrlDRStopBallFar0,conditionrlGkStopFarGoal0,conditionrlMOStop0,conditionrlSLStopTeamLeft0,conditionrlSLStopTeamRight0,conditionrlSRStopTeamLeft0,conditionrlSRStopTeamRight0,conditionrlDRYellowDirectKickYellow0,conditionrlDRYellowPenaltyBlue0,conditionrlDRtYellowIndirectKickYellow0,conditionrlGkYellowPenaltyBlue0,conditionrlMOYellowDirectKick0,conditionrlMOYellowIndirectKick0,conditionrlMOYellowKickoff0,conditionrlMOYellowPenaltyBlue0,conditionrlMOYellowPenaltyYellow0,conditionrlSLYellowDirectKick0,conditionrlSLYellowIndirectKick0,conditionrlSLYellowPenaltyBlue0,conditionrlSLYellowPenaltyYellow0,conditionrlSRYellowDirectKick0,conditionrlSRYellowIndirectKick0,conditionrlSRYellowsPenaltyBlue0,conditionrlSRYellowsPenaltyYellow0,conditionrlSLHaltClose0,conditionrlSLHaltCloseReady0,conditionrlSRHaltClose0,conditionrlSRHaltCloseReady0,conditionrlStartEnemyFieldKick0,conditionrlStartNoFreePartnerKick0,conditionrlRobotMoveX0,conditionrlRobotMoveY0,conditionrlTeste);
    Robotrobot2 * robot2 = new Robotrobot2(conditionrlAngleMove1,conditionrlBallFar1,conditionrlStartTargetToBall1,conditionrlDLBlueDirectKickBlue1,conditionrlDLtBlueIndirectBlue1,conditionrlDLtBluePenaltyYellow1,conditionrlDRBlueDirectKickBlue1,conditionrlDRBlueIndirectKickBlue1,conditionrlDRBluePenaltyYellow1,conditionrlGkBluePenaltyYellow1,conditionrlMOBlueDirectKick1,conditionrlMOBlueIndirectKick1,conditionrlMOBlueKickoff1,conditionrlMOBluePenaltyBlue1,conditionrlMOBluePenaltyYellow1,conditionrlMOBlueReadyKickoffBlue1,conditionrlMOBlueReadyPenaltyBlue1,conditionrlSLBlueDirectKick1,conditionrlSLBlueIndirectKick1,conditionrlSLBluePenaltyBlue1,conditionrlSLBluePenaltyYellow1,conditionrlSRBlueDirectKick1,conditionrlSRBlueIndirectKick1,conditionrlSRBluePenaltyBlue1,conditionrlSRBluePenaltyYellow1,conditionrlDLStartNotClose1,conditionrlDLStopBallClose1,conditionrlDLYellowDirectKickYellow1,conditionrlDLYellowIndirectYellow1,conditionrlDLYellowPenaltyBlue1,conditionrlDLtStopBallFar1,conditionrlDRStartBallNotClose1,conditionrlGkStartInsideArea1,conditionrlSLHaltNotClose1,conditionrlSLStartBallNotClose1,conditionrlSRHaltNotClose1,conditionrlSRStartBallNotClose1,conditionrlGkStartInsideAreaClosestBall1,conditionrlGkStartInsideAreaClosestBallKick1,conditionrlGkStartOutsideArea1,conditionrlMOYellowReadyKickoffYellow1,conditionrlMOYellowReadyPenaltyYellow1,conditionrlStartEnemyFieldPositionKick1,conditionrlStartFreePartner1,conditionrlStartFreePartnerPass1,conditionrlStartNoFreePartner1,conditionrlDRStopBallClose1,conditionrlGkStopCloseGoal1,conditionrlDRStopBallFar1,conditionrlGkStopFarGoal1,conditionrlMOStop1,conditionrlSLStopTeamLeft1,conditionrlSLStopTeamRight1,conditionrlSRStopTeamLeft1,conditionrlSRStopTeamRight1,conditionrlDRYellowDirectKickYellow1,conditionrlDRYellowPenaltyBlue1,conditionrlDRtYellowIndirectKickYellow1,conditionrlGkYellowPenaltyBlue1,conditionrlMOYellowDirectKick1,conditionrlMOYellowIndirectKick1,conditionrlMOYellowKickoff1,conditionrlMOYellowPenaltyBlue1,conditionrlMOYellowPenaltyYellow1,conditionrlSLYellowDirectKick1,conditionrlSLYellowIndirectKick1,conditionrlSLYellowPenaltyBlue1,conditionrlSLYellowPenaltyYellow1,conditionrlSRYellowDirectKick1,conditionrlSRYellowIndirectKick1,conditionrlSRYellowsPenaltyBlue1,conditionrlSRYellowsPenaltyYellow1,conditionrlSLHaltClose1,conditionrlSLHaltCloseReady1,conditionrlSRHaltClose1,conditionrlSRHaltCloseReady1,conditionrlStartEnemyFieldKick1,conditionrlStartNoFreePartnerKick1,conditionrlRobotMoveX1,conditionrlRobotMoveY1);
    Robotrobot3 * robot3 = new Robotrobot3(conditionrlAngleMove2,conditionrlBallFar2,conditionrlStartTargetToBall2,conditionrlDLBlueDirectKickBlue2,conditionrlDLtBlueIndirectBlue2,conditionrlDLtBluePenaltyYellow2,conditionrlDRBlueDirectKickBlue2,conditionrlDRBlueIndirectKickBlue2,conditionrlDRBluePenaltyYellow2,conditionrlGkBluePenaltyYellow2,conditionrlMOBlueDirectKick2,conditionrlMOBlueIndirectKick2,conditionrlMOBlueKickoff2,conditionrlMOBluePenaltyBlue2,conditionrlMOBluePenaltyYellow2,conditionrlMOBlueReadyKickoffBlue2,conditionrlMOBlueReadyPenaltyBlue2,conditionrlSLBlueDirectKick2,conditionrlSLBlueIndirectKick2,conditionrlSLBluePenaltyBlue2,conditionrlSLBluePenaltyYellow2,conditionrlSRBlueDirectKick2,conditionrlSRBlueIndirectKick2,conditionrlSRBluePenaltyBlue2,conditionrlSRBluePenaltyYellow2,conditionrlDLStartNotClose2,conditionrlDLStopBallClose2,conditionrlDLYellowDirectKickYellow2,conditionrlDLYellowIndirectYellow2,conditionrlDLYellowPenaltyBlue2,conditionrlDLtStopBallFar2,conditionrlDRStartBallNotClose2,conditionrlGkStartInsideArea2,conditionrlSLHaltNotClose2,conditionrlSLStartBallNotClose2,conditionrlSRHaltNotClose2,conditionrlSRStartBallNotClose2,conditionrlGkStartInsideAreaClosestBall2,conditionrlGkStartInsideAreaClosestBallKick2,conditionrlGkStartOutsideArea2,conditionrlMOYellowReadyKickoffYellow2,conditionrlMOYellowReadyPenaltyYellow2,conditionrlStartEnemyFieldPositionKick2,conditionrlStartFreePartner2,conditionrlStartFreePartnerPass2,conditionrlStartNoFreePartner2,conditionrlDRStopBallClose2,conditionrlGkStopCloseGoal2,conditionrlDRStopBallFar2,conditionrlGkStopFarGoal2,conditionrlMOStop2,conditionrlSLStopTeamLeft2,conditionrlSLStopTeamRight2,conditionrlSRStopTeamLeft2,conditionrlSRStopTeamRight2,conditionrlDRYellowDirectKickYellow2,conditionrlDRYellowPenaltyBlue2,conditionrlDRtYellowIndirectKickYellow2,conditionrlGkYellowPenaltyBlue2,conditionrlMOYellowDirectKick2,conditionrlMOYellowIndirectKick2,conditionrlMOYellowKickoff2,conditionrlMOYellowPenaltyBlue2,conditionrlMOYellowPenaltyYellow2,conditionrlSLYellowDirectKick2,conditionrlSLYellowIndirectKick2,conditionrlSLYellowPenaltyBlue2,conditionrlSLYellowPenaltyYellow2,conditionrlSRYellowDirectKick2,conditionrlSRYellowIndirectKick2,conditionrlSRYellowsPenaltyBlue2,conditionrlSRYellowsPenaltyYellow2,conditionrlSLHaltClose2,conditionrlSLHaltCloseReady2,conditionrlSRHaltClose2,conditionrlSRHaltCloseReady2,conditionrlStartEnemyFieldKick2,conditionrlStartNoFreePartnerKick2,conditionrlRobotMoveX2,conditionrlRobotMoveY2);
    Robotrobot4 * robot4 = new Robotrobot4(conditionrlAngleMove3,conditionrlBallFar3,conditionrlStartTargetToBall3,conditionrlDLBlueDirectKickBlue3,conditionrlDLtBlueIndirectBlue3,conditionrlDLtBluePenaltyYellow3,conditionrlDRBlueDirectKickBlue3,conditionrlDRBlueIndirectKickBlue3,conditionrlDRBluePenaltyYellow3,conditionrlGkBluePenaltyYellow3,conditionrlMOBlueDirectKick3,conditionrlMOBlueIndirectKick3,conditionrlMOBlueKickoff3,conditionrlMOBluePenaltyBlue3,conditionrlMOBluePenaltyYellow3,conditionrlMOBlueReadyKickoffBlue3,conditionrlMOBlueReadyPenaltyBlue3,conditionrlSLBlueDirectKick3,conditionrlSLBlueIndirectKick3,conditionrlSLBluePenaltyBlue3,conditionrlSLBluePenaltyYellow3,conditionrlSRBlueDirectKick3,conditionrlSRBlueIndirectKick3,conditionrlSRBluePenaltyBlue3,conditionrlSRBluePenaltyYellow3,conditionrlDLStartNotClose3,conditionrlDLStopBallClose3,conditionrlDLYellowDirectKickYellow3,conditionrlDLYellowIndirectYellow3,conditionrlDLYellowPenaltyBlue3,conditionrlDLtStopBallFar3,conditionrlDRStartBallNotClose3,conditionrlGkStartInsideArea3,conditionrlSLHaltNotClose3,conditionrlSLStartBallNotClose3,conditionrlSRHaltNotClose3,conditionrlSRStartBallNotClose3,conditionrlGkStartInsideAreaClosestBall3,conditionrlGkStartInsideAreaClosestBallKick3,conditionrlGkStartOutsideArea3,conditionrlMOYellowReadyKickoffYellow3,conditionrlMOYellowReadyPenaltyYellow3,conditionrlStartEnemyFieldPositionKick3,conditionrlStartFreePartner3,conditionrlStartFreePartnerPass3,conditionrlStartNoFreePartner3,conditionrlDRStopBallClose3,conditionrlGkStopCloseGoal3,conditionrlDRStopBallFar3,conditionrlGkStopFarGoal3,conditionrlMOStop3,conditionrlSLStopTeamLeft3,conditionrlSLStopTeamRight3,conditionrlSRStopTeamLeft3,conditionrlSRStopTeamRight3,conditionrlDRYellowDirectKickYellow3,conditionrlDRYellowPenaltyBlue3,conditionrlDRtYellowIndirectKickYellow3,conditionrlGkYellowPenaltyBlue3,conditionrlMOYellowDirectKick3,conditionrlMOYellowIndirectKick3,conditionrlMOYellowKickoff3,conditionrlMOYellowPenaltyBlue3,conditionrlMOYellowPenaltyYellow3,conditionrlSLYellowDirectKick3,conditionrlSLYellowIndirectKick3,conditionrlSLYellowPenaltyBlue3,conditionrlSLYellowPenaltyYellow3,conditionrlSRYellowDirectKick3,conditionrlSRYellowIndirectKick3,conditionrlSRYellowsPenaltyBlue3,conditionrlSRYellowsPenaltyYellow3,conditionrlSLHaltClose3,conditionrlSLHaltCloseReady3,conditionrlSRHaltClose3,conditionrlSRHaltCloseReady3,conditionrlStartEnemyFieldKick3,conditionrlStartNoFreePartnerKick3,conditionrlRobotMoveX3,conditionrlRobotMoveY3);
    Robotrobot5 * robot5 = new Robotrobot5(conditionrlAngleMove4,conditionrlBallFar4,conditionrlStartTargetToBall4,conditionrlDLBlueDirectKickBlue4,conditionrlDLtBlueIndirectBlue4,conditionrlDLtBluePenaltyYellow4,conditionrlDRBlueDirectKickBlue4,conditionrlDRBlueIndirectKickBlue4,conditionrlDRBluePenaltyYellow4,conditionrlGkBluePenaltyYellow4,conditionrlMOBlueDirectKick4,conditionrlMOBlueIndirectKick4,conditionrlMOBlueKickoff4,conditionrlMOBluePenaltyBlue4,conditionrlMOBluePenaltyYellow4,conditionrlMOBlueReadyKickoffBlue4,conditionrlMOBlueReadyPenaltyBlue4,conditionrlSLBlueDirectKick4,conditionrlSLBlueIndirectKick4,conditionrlSLBluePenaltyBlue4,conditionrlSLBluePenaltyYellow4,conditionrlSRBlueDirectKick4,conditionrlSRBlueIndirectKick4,conditionrlSRBluePenaltyBlue4,conditionrlSRBluePenaltyYellow4,conditionrlDLStartNotClose4,conditionrlDLStopBallClose4,conditionrlDLYellowDirectKickYellow4,conditionrlDLYellowIndirectYellow4,conditionrlDLYellowPenaltyBlue4,conditionrlDLtStopBallFar4,conditionrlDRStartBallNotClose4,conditionrlGkStartInsideArea4,conditionrlSLHaltNotClose4,conditionrlSLStartBallNotClose4,conditionrlSRHaltNotClose4,conditionrlSRStartBallNotClose4,conditionrlGkStartInsideAreaClosestBall4,conditionrlGkStartInsideAreaClosestBallKick4,conditionrlGkStartOutsideArea4,conditionrlMOYellowReadyKickoffYellow4,conditionrlMOYellowReadyPenaltyYellow4,conditionrlStartEnemyFieldPositionKick4,conditionrlStartFreePartner4,conditionrlStartFreePartnerPass4,conditionrlStartNoFreePartner4,conditionrlDRStopBallClose4,conditionrlGkStopCloseGoal4,conditionrlDRStopBallFar4,conditionrlGkStopFarGoal4,conditionrlMOStop4,conditionrlSLStopTeamLeft4,conditionrlSLStopTeamRight4,conditionrlSRStopTeamLeft4,conditionrlSRStopTeamRight4,conditionrlDRYellowDirectKickYellow4,conditionrlDRYellowPenaltyBlue4,conditionrlDRtYellowIndirectKickYellow4,conditionrlGkYellowPenaltyBlue4,conditionrlMOYellowDirectKick4,conditionrlMOYellowIndirectKick4,conditionrlMOYellowKickoff4,conditionrlMOYellowPenaltyBlue4,conditionrlMOYellowPenaltyYellow4,conditionrlSLYellowDirectKick4,conditionrlSLYellowIndirectKick4,conditionrlSLYellowPenaltyBlue4,conditionrlSLYellowPenaltyYellow4,conditionrlSRYellowDirectKick4,conditionrlSRYellowIndirectKick4,conditionrlSRYellowsPenaltyBlue4,conditionrlSRYellowsPenaltyYellow4,conditionrlSLHaltClose4,conditionrlSLHaltCloseReady4,conditionrlSRHaltClose4,conditionrlSRHaltCloseReady4,conditionrlStartEnemyFieldKick4,conditionrlStartNoFreePartnerKick4,conditionrlRobotMoveX4,conditionrlRobotMoveY4);
    Robotrobot6 * robot6 = new Robotrobot6(conditionrlAngleMove5,conditionrlBallFar5,conditionrlStartTargetToBall5,conditionrlDLBlueDirectKickBlue5,conditionrlDLtBlueIndirectBlue5,conditionrlDLtBluePenaltyYellow5,conditionrlDRBlueDirectKickBlue5,conditionrlDRBlueIndirectKickBlue5,conditionrlDRBluePenaltyYellow5,conditionrlGkBluePenaltyYellow5,conditionrlMOBlueDirectKick5,conditionrlMOBlueIndirectKick5,conditionrlMOBlueKickoff5,conditionrlMOBluePenaltyBlue5,conditionrlMOBluePenaltyYellow5,conditionrlMOBlueReadyKickoffBlue5,conditionrlMOBlueReadyPenaltyBlue5,conditionrlSLBlueDirectKick5,conditionrlSLBlueIndirectKick5,conditionrlSLBluePenaltyBlue5,conditionrlSLBluePenaltyYellow5,conditionrlSRBlueDirectKick5,conditionrlSRBlueIndirectKick5,conditionrlSRBluePenaltyBlue5,conditionrlSRBluePenaltyYellow5,conditionrlDLStartNotClose5,conditionrlDLStopBallClose5,conditionrlDLYellowDirectKickYellow5,conditionrlDLYellowIndirectYellow5,conditionrlDLYellowPenaltyBlue5,conditionrlDLtStopBallFar5,conditionrlDRStartBallNotClose5,conditionrlGkStartInsideArea5,conditionrlSLHaltNotClose5,conditionrlSLStartBallNotClose5,conditionrlSRHaltNotClose5,conditionrlSRStartBallNotClose5,conditionrlGkStartInsideAreaClosestBall5,conditionrlGkStartInsideAreaClosestBallKick5,conditionrlGkStartOutsideArea5,conditionrlMOYellowReadyKickoffYellow5,conditionrlMOYellowReadyPenaltyYellow5,conditionrlStartEnemyFieldPositionKick5,conditionrlStartFreePartner5,conditionrlStartFreePartnerPass5,conditionrlStartNoFreePartner5,conditionrlDRStopBallClose5,conditionrlGkStopCloseGoal5,conditionrlDRStopBallFar5,conditionrlGkStopFarGoal5,conditionrlMOStop5,conditionrlSLStopTeamLeft5,conditionrlSLStopTeamRight5,conditionrlSRStopTeamLeft5,conditionrlSRStopTeamRight5,conditionrlDRYellowDirectKickYellow5,conditionrlDRYellowPenaltyBlue5,conditionrlDRtYellowIndirectKickYellow5,conditionrlGkYellowPenaltyBlue5,conditionrlMOYellowDirectKick5,conditionrlMOYellowIndirectKick5,conditionrlMOYellowKickoff5,conditionrlMOYellowPenaltyBlue5,conditionrlMOYellowPenaltyYellow5,conditionrlSLYellowDirectKick5,conditionrlSLYellowIndirectKick5,conditionrlSLYellowPenaltyBlue5,conditionrlSLYellowPenaltyYellow5,conditionrlSRYellowDirectKick5,conditionrlSRYellowIndirectKick5,conditionrlSRYellowsPenaltyBlue5,conditionrlSRYellowsPenaltyYellow5,conditionrlSLHaltClose5,conditionrlSLHaltCloseReady5,conditionrlSRHaltClose5,conditionrlSRHaltCloseReady5,conditionrlStartEnemyFieldKick5,conditionrlStartNoFreePartnerKick5,conditionrlRobotMoveX5,conditionrlRobotMoveY5);

    conditionrlAngleMove0->robot1 = robot1;
    conditionrlAngleMove1->robot2 = robot2;
    conditionrlAngleMove2->robot3 = robot3;
    conditionrlAngleMove3->robot4 = robot4;
    conditionrlAngleMove4->robot5 = robot5;
    conditionrlAngleMove5->robot6 = robot6;
    conditionrlBallFar0->robot1 = robot1;
    conditionrlBallFar1->robot2 = robot2;
    conditionrlBallFar2->robot3 = robot3;
    conditionrlBallFar3->robot4 = robot4;
    conditionrlBallFar4->robot5 = robot5;
    conditionrlBallFar5->robot6 = robot6;
    conditionrlDLBlueDirectKickBlue0->robot1 = robot1;
    conditionrlDLBlueDirectKickBlue1->robot2 = robot2;
    conditionrlDLBlueDirectKickBlue2->robot3 = robot3;
    conditionrlDLBlueDirectKickBlue3->robot4 = robot4;
    conditionrlDLBlueDirectKickBlue4->robot5 = robot5;
    conditionrlDLBlueDirectKickBlue5->robot6 = robot6;
    conditionrlDLStartNotClose0->robot1 = robot1;
    conditionrlDLStartNotClose1->robot2 = robot2;
    conditionrlDLStartNotClose2->robot3 = robot3;
    conditionrlDLStartNotClose3->robot4 = robot4;
    conditionrlDLStartNotClose4->robot5 = robot5;
    conditionrlDLStartNotClose5->robot6 = robot6;
    conditionrlDLStopBallClose0->robot1 = robot1;
    conditionrlDLStopBallClose1->robot2 = robot2;
    conditionrlDLStopBallClose2->robot3 = robot3;
    conditionrlDLStopBallClose3->robot4 = robot4;
    conditionrlDLStopBallClose4->robot5 = robot5;
    conditionrlDLStopBallClose5->robot6 = robot6;
    conditionrlDLYellowDirectKickYellow0->robot1 = robot1;
    conditionrlDLYellowDirectKickYellow1->robot2 = robot2;
    conditionrlDLYellowDirectKickYellow2->robot3 = robot3;
    conditionrlDLYellowDirectKickYellow3->robot4 = robot4;
    conditionrlDLYellowDirectKickYellow4->robot5 = robot5;
    conditionrlDLYellowDirectKickYellow5->robot6 = robot6;
    conditionrlDLYellowIndirectYellow0->robot1 = robot1;
    conditionrlDLYellowIndirectYellow1->robot2 = robot2;
    conditionrlDLYellowIndirectYellow2->robot3 = robot3;
    conditionrlDLYellowIndirectYellow3->robot4 = robot4;
    conditionrlDLYellowIndirectYellow4->robot5 = robot5;
    conditionrlDLYellowIndirectYellow5->robot6 = robot6;
    conditionrlDLYellowPenaltyBlue0->robot1 = robot1;
    conditionrlDLYellowPenaltyBlue1->robot2 = robot2;
    conditionrlDLYellowPenaltyBlue2->robot3 = robot3;
    conditionrlDLYellowPenaltyBlue3->robot4 = robot4;
    conditionrlDLYellowPenaltyBlue4->robot5 = robot5;
    conditionrlDLYellowPenaltyBlue5->robot6 = robot6;
    conditionrlDLtBlueIndirectBlue0->robot1 = robot1;
    conditionrlDLtBlueIndirectBlue1->robot2 = robot2;
    conditionrlDLtBlueIndirectBlue2->robot3 = robot3;
    conditionrlDLtBlueIndirectBlue3->robot4 = robot4;
    conditionrlDLtBlueIndirectBlue4->robot5 = robot5;
    conditionrlDLtBlueIndirectBlue5->robot6 = robot6;
    conditionrlDLtBluePenaltyYellow0->robot1 = robot1;
    conditionrlDLtBluePenaltyYellow1->robot2 = robot2;
    conditionrlDLtBluePenaltyYellow2->robot3 = robot3;
    conditionrlDLtBluePenaltyYellow3->robot4 = robot4;
    conditionrlDLtBluePenaltyYellow4->robot5 = robot5;
    conditionrlDLtBluePenaltyYellow5->robot6 = robot6;
    conditionrlDLtStopBallFar0->robot1 = robot1;
    conditionrlDLtStopBallFar1->robot2 = robot2;
    conditionrlDLtStopBallFar2->robot3 = robot3;
    conditionrlDLtStopBallFar3->robot4 = robot4;
    conditionrlDLtStopBallFar4->robot5 = robot5;
    conditionrlDLtStopBallFar5->robot6 = robot6;
    conditionrlDRBlueDirectKickBlue0->robot1 = robot1;
    conditionrlDRBlueDirectKickBlue1->robot2 = robot2;
    conditionrlDRBlueDirectKickBlue2->robot3 = robot3;
    conditionrlDRBlueDirectKickBlue3->robot4 = robot4;
    conditionrlDRBlueDirectKickBlue4->robot5 = robot5;
    conditionrlDRBlueDirectKickBlue5->robot6 = robot6;
    conditionrlDRBlueIndirectKickBlue0->robot1 = robot1;
    conditionrlDRBlueIndirectKickBlue1->robot2 = robot2;
    conditionrlDRBlueIndirectKickBlue2->robot3 = robot3;
    conditionrlDRBlueIndirectKickBlue3->robot4 = robot4;
    conditionrlDRBlueIndirectKickBlue4->robot5 = robot5;
    conditionrlDRBlueIndirectKickBlue5->robot6 = robot6;
    conditionrlDRBluePenaltyYellow0->robot1 = robot1;
    conditionrlDRBluePenaltyYellow1->robot2 = robot2;
    conditionrlDRBluePenaltyYellow2->robot3 = robot3;
    conditionrlDRBluePenaltyYellow3->robot4 = robot4;
    conditionrlDRBluePenaltyYellow4->robot5 = robot5;
    conditionrlDRBluePenaltyYellow5->robot6 = robot6;
    conditionrlDRStartBallNotClose0->robot1 = robot1;
    conditionrlDRStartBallNotClose1->robot2 = robot2;
    conditionrlDRStartBallNotClose2->robot3 = robot3;
    conditionrlDRStartBallNotClose3->robot4 = robot4;
    conditionrlDRStartBallNotClose4->robot5 = robot5;
    conditionrlDRStartBallNotClose5->robot6 = robot6;
    conditionrlDRStopBallClose0->robot1 = robot1;
    conditionrlDRStopBallClose1->robot2 = robot2;
    conditionrlDRStopBallClose2->robot3 = robot3;
    conditionrlDRStopBallClose3->robot4 = robot4;
    conditionrlDRStopBallClose4->robot5 = robot5;
    conditionrlDRStopBallClose5->robot6 = robot6;
    conditionrlDRStopBallFar0->robot1 = robot1;
    conditionrlDRStopBallFar1->robot2 = robot2;
    conditionrlDRStopBallFar2->robot3 = robot3;
    conditionrlDRStopBallFar3->robot4 = robot4;
    conditionrlDRStopBallFar4->robot5 = robot5;
    conditionrlDRStopBallFar5->robot6 = robot6;
    conditionrlDRYellowDirectKickYellow0->robot1 = robot1;
    conditionrlDRYellowDirectKickYellow1->robot2 = robot2;
    conditionrlDRYellowDirectKickYellow2->robot3 = robot3;
    conditionrlDRYellowDirectKickYellow3->robot4 = robot4;
    conditionrlDRYellowDirectKickYellow4->robot5 = robot5;
    conditionrlDRYellowDirectKickYellow5->robot6 = robot6;
    conditionrlDRYellowPenaltyBlue0->robot1 = robot1;
    conditionrlDRYellowPenaltyBlue1->robot2 = robot2;
    conditionrlDRYellowPenaltyBlue2->robot3 = robot3;
    conditionrlDRYellowPenaltyBlue3->robot4 = robot4;
    conditionrlDRYellowPenaltyBlue4->robot5 = robot5;
    conditionrlDRYellowPenaltyBlue5->robot6 = robot6;
    conditionrlDRtYellowIndirectKickYellow0->robot1 = robot1;
    conditionrlDRtYellowIndirectKickYellow1->robot2 = robot2;
    conditionrlDRtYellowIndirectKickYellow2->robot3 = robot3;
    conditionrlDRtYellowIndirectKickYellow3->robot4 = robot4;
    conditionrlDRtYellowIndirectKickYellow4->robot5 = robot5;
    conditionrlDRtYellowIndirectKickYellow5->robot6 = robot6;
    conditionrlGkBluePenaltyYellow0->robot1 = robot1;
    conditionrlGkBluePenaltyYellow1->robot2 = robot2;
    conditionrlGkBluePenaltyYellow2->robot3 = robot3;
    conditionrlGkBluePenaltyYellow3->robot4 = robot4;
    conditionrlGkBluePenaltyYellow4->robot5 = robot5;
    conditionrlGkBluePenaltyYellow5->robot6 = robot6;
    conditionrlGkStartInsideArea0->robot1 = robot1;
    conditionrlGkStartInsideArea1->robot2 = robot2;
    conditionrlGkStartInsideArea2->robot3 = robot3;
    conditionrlGkStartInsideArea3->robot4 = robot4;
    conditionrlGkStartInsideArea4->robot5 = robot5;
    conditionrlGkStartInsideArea5->robot6 = robot6;
    conditionrlGkStartInsideAreaClosestBall0->robot1 = robot1;
    conditionrlGkStartInsideAreaClosestBall1->robot2 = robot2;
    conditionrlGkStartInsideAreaClosestBall2->robot3 = robot3;
    conditionrlGkStartInsideAreaClosestBall3->robot4 = robot4;
    conditionrlGkStartInsideAreaClosestBall4->robot5 = robot5;
    conditionrlGkStartInsideAreaClosestBall5->robot6 = robot6;
    conditionrlGkStartInsideAreaClosestBallKick0->robot1 = robot1;
    conditionrlGkStartInsideAreaClosestBallKick1->robot2 = robot2;
    conditionrlGkStartInsideAreaClosestBallKick2->robot3 = robot3;
    conditionrlGkStartInsideAreaClosestBallKick3->robot4 = robot4;
    conditionrlGkStartInsideAreaClosestBallKick4->robot5 = robot5;
    conditionrlGkStartInsideAreaClosestBallKick5->robot6 = robot6;
    conditionrlGkStartOutsideArea0->robot1 = robot1;
    conditionrlGkStartOutsideArea1->robot2 = robot2;
    conditionrlGkStartOutsideArea2->robot3 = robot3;
    conditionrlGkStartOutsideArea3->robot4 = robot4;
    conditionrlGkStartOutsideArea4->robot5 = robot5;
    conditionrlGkStartOutsideArea5->robot6 = robot6;
    conditionrlGkStopCloseGoal0->robot1 = robot1;
    conditionrlGkStopCloseGoal1->robot2 = robot2;
    conditionrlGkStopCloseGoal2->robot3 = robot3;
    conditionrlGkStopCloseGoal3->robot4 = robot4;
    conditionrlGkStopCloseGoal4->robot5 = robot5;
    conditionrlGkStopCloseGoal5->robot6 = robot6;
    conditionrlGkStopFarGoal0->robot1 = robot1;
    conditionrlGkStopFarGoal1->robot2 = robot2;
    conditionrlGkStopFarGoal2->robot3 = robot3;
    conditionrlGkStopFarGoal3->robot4 = robot4;
    conditionrlGkStopFarGoal4->robot5 = robot5;
    conditionrlGkStopFarGoal5->robot6 = robot6;
    conditionrlGkYellowPenaltyBlue0->robot1 = robot1;
    conditionrlGkYellowPenaltyBlue1->robot2 = robot2;
    conditionrlGkYellowPenaltyBlue2->robot3 = robot3;
    conditionrlGkYellowPenaltyBlue3->robot4 = robot4;
    conditionrlGkYellowPenaltyBlue4->robot5 = robot5;
    conditionrlGkYellowPenaltyBlue5->robot6 = robot6;
    conditionrlMOBlueDirectKick0->robot1 = robot1;
    conditionrlMOBlueDirectKick1->robot2 = robot2;
    conditionrlMOBlueDirectKick2->robot3 = robot3;
    conditionrlMOBlueDirectKick3->robot4 = robot4;
    conditionrlMOBlueDirectKick4->robot5 = robot5;
    conditionrlMOBlueDirectKick5->robot6 = robot6;
    conditionrlMOBlueIndirectKick0->robot1 = robot1;
    conditionrlMOBlueIndirectKick1->robot2 = robot2;
    conditionrlMOBlueIndirectKick2->robot3 = robot3;
    conditionrlMOBlueIndirectKick3->robot4 = robot4;
    conditionrlMOBlueIndirectKick4->robot5 = robot5;
    conditionrlMOBlueIndirectKick5->robot6 = robot6;
    conditionrlMOBlueKickoff0->robot1 = robot1;
    conditionrlMOBlueKickoff1->robot2 = robot2;
    conditionrlMOBlueKickoff2->robot3 = robot3;
    conditionrlMOBlueKickoff3->robot4 = robot4;
    conditionrlMOBlueKickoff4->robot5 = robot5;
    conditionrlMOBlueKickoff5->robot6 = robot6;
    conditionrlMOBluePenaltyBlue0->robot1 = robot1;
    conditionrlMOBluePenaltyBlue1->robot2 = robot2;
    conditionrlMOBluePenaltyBlue2->robot3 = robot3;
    conditionrlMOBluePenaltyBlue3->robot4 = robot4;
    conditionrlMOBluePenaltyBlue4->robot5 = robot5;
    conditionrlMOBluePenaltyBlue5->robot6 = robot6;
    conditionrlMOBluePenaltyYellow0->robot1 = robot1;
    conditionrlMOBluePenaltyYellow1->robot2 = robot2;
    conditionrlMOBluePenaltyYellow2->robot3 = robot3;
    conditionrlMOBluePenaltyYellow3->robot4 = robot4;
    conditionrlMOBluePenaltyYellow4->robot5 = robot5;
    conditionrlMOBluePenaltyYellow5->robot6 = robot6;
    conditionrlMOBlueReadyKickoffBlue0->robot1 = robot1;
    conditionrlMOBlueReadyKickoffBlue1->robot2 = robot2;
    conditionrlMOBlueReadyKickoffBlue2->robot3 = robot3;
    conditionrlMOBlueReadyKickoffBlue3->robot4 = robot4;
    conditionrlMOBlueReadyKickoffBlue4->robot5 = robot5;
    conditionrlMOBlueReadyKickoffBlue5->robot6 = robot6;
    conditionrlMOBlueReadyPenaltyBlue0->robot1 = robot1;
    conditionrlMOBlueReadyPenaltyBlue1->robot2 = robot2;
    conditionrlMOBlueReadyPenaltyBlue2->robot3 = robot3;
    conditionrlMOBlueReadyPenaltyBlue3->robot4 = robot4;
    conditionrlMOBlueReadyPenaltyBlue4->robot5 = robot5;
    conditionrlMOBlueReadyPenaltyBlue5->robot6 = robot6;
    conditionrlMOStop0->robot1 = robot1;
    conditionrlMOStop1->robot2 = robot2;
    conditionrlMOStop2->robot3 = robot3;
    conditionrlMOStop3->robot4 = robot4;
    conditionrlMOStop4->robot5 = robot5;
    conditionrlMOStop5->robot6 = robot6;
    conditionrlMOYellowDirectKick0->robot1 = robot1;
    conditionrlMOYellowDirectKick1->robot2 = robot2;
    conditionrlMOYellowDirectKick2->robot3 = robot3;
    conditionrlMOYellowDirectKick3->robot4 = robot4;
    conditionrlMOYellowDirectKick4->robot5 = robot5;
    conditionrlMOYellowDirectKick5->robot6 = robot6;
    conditionrlMOYellowIndirectKick0->robot1 = robot1;
    conditionrlMOYellowIndirectKick1->robot2 = robot2;
    conditionrlMOYellowIndirectKick2->robot3 = robot3;
    conditionrlMOYellowIndirectKick3->robot4 = robot4;
    conditionrlMOYellowIndirectKick4->robot5 = robot5;
    conditionrlMOYellowIndirectKick5->robot6 = robot6;
    conditionrlMOYellowKickoff0->robot1 = robot1;
    conditionrlMOYellowKickoff1->robot2 = robot2;
    conditionrlMOYellowKickoff2->robot3 = robot3;
    conditionrlMOYellowKickoff3->robot4 = robot4;
    conditionrlMOYellowKickoff4->robot5 = robot5;
    conditionrlMOYellowKickoff5->robot6 = robot6;
    conditionrlMOYellowPenaltyBlue0->robot1 = robot1;
    conditionrlMOYellowPenaltyBlue1->robot2 = robot2;
    conditionrlMOYellowPenaltyBlue2->robot3 = robot3;
    conditionrlMOYellowPenaltyBlue3->robot4 = robot4;
    conditionrlMOYellowPenaltyBlue4->robot5 = robot5;
    conditionrlMOYellowPenaltyBlue5->robot6 = robot6;
    conditionrlMOYellowPenaltyYellow0->robot1 = robot1;
    conditionrlMOYellowPenaltyYellow1->robot2 = robot2;
    conditionrlMOYellowPenaltyYellow2->robot3 = robot3;
    conditionrlMOYellowPenaltyYellow3->robot4 = robot4;
    conditionrlMOYellowPenaltyYellow4->robot5 = robot5;
    conditionrlMOYellowPenaltyYellow5->robot6 = robot6;
    conditionrlMOYellowReadyKickoffYellow0->robot1 = robot1;
    conditionrlMOYellowReadyKickoffYellow1->robot2 = robot2;
    conditionrlMOYellowReadyKickoffYellow2->robot3 = robot3;
    conditionrlMOYellowReadyKickoffYellow3->robot4 = robot4;
    conditionrlMOYellowReadyKickoffYellow4->robot5 = robot5;
    conditionrlMOYellowReadyKickoffYellow5->robot6 = robot6;
    conditionrlMOYellowReadyPenaltyYellow0->robot1 = robot1;
    conditionrlMOYellowReadyPenaltyYellow1->robot2 = robot2;
    conditionrlMOYellowReadyPenaltyYellow2->robot3 = robot3;
    conditionrlMOYellowReadyPenaltyYellow3->robot4 = robot4;
    conditionrlMOYellowReadyPenaltyYellow4->robot5 = robot5;
    conditionrlMOYellowReadyPenaltyYellow5->robot6 = robot6;
    conditionrlRobotMoveX0->robot1 = robot1;
    conditionrlRobotMoveX1->robot2 = robot2;
    conditionrlRobotMoveX2->robot3 = robot3;
    conditionrlRobotMoveX3->robot4 = robot4;
    conditionrlRobotMoveX4->robot5 = robot5;
    conditionrlRobotMoveX5->robot6 = robot6;
    conditionrlRobotMoveY0->robot1 = robot1;
    conditionrlRobotMoveY1->robot2 = robot2;
    conditionrlRobotMoveY2->robot3 = robot3;
    conditionrlRobotMoveY3->robot4 = robot4;
    conditionrlRobotMoveY4->robot5 = robot5;
    conditionrlRobotMoveY5->robot6 = robot6;
    conditionrlSLBlueDirectKick0->robot1 = robot1;
    conditionrlSLBlueDirectKick1->robot2 = robot2;
    conditionrlSLBlueDirectKick2->robot3 = robot3;
    conditionrlSLBlueDirectKick3->robot4 = robot4;
    conditionrlSLBlueDirectKick4->robot5 = robot5;
    conditionrlSLBlueDirectKick5->robot6 = robot6;
    conditionrlSLBlueIndirectKick0->robot1 = robot1;
    conditionrlSLBlueIndirectKick1->robot2 = robot2;
    conditionrlSLBlueIndirectKick2->robot3 = robot3;
    conditionrlSLBlueIndirectKick3->robot4 = robot4;
    conditionrlSLBlueIndirectKick4->robot5 = robot5;
    conditionrlSLBlueIndirectKick5->robot6 = robot6;
    conditionrlSLBluePenaltyBlue0->robot1 = robot1;
    conditionrlSLBluePenaltyBlue1->robot2 = robot2;
    conditionrlSLBluePenaltyBlue2->robot3 = robot3;
    conditionrlSLBluePenaltyBlue3->robot4 = robot4;
    conditionrlSLBluePenaltyBlue4->robot5 = robot5;
    conditionrlSLBluePenaltyBlue5->robot6 = robot6;
    conditionrlSLBluePenaltyYellow0->robot1 = robot1;
    conditionrlSLBluePenaltyYellow1->robot2 = robot2;
    conditionrlSLBluePenaltyYellow2->robot3 = robot3;
    conditionrlSLBluePenaltyYellow3->robot4 = robot4;
    conditionrlSLBluePenaltyYellow4->robot5 = robot5;
    conditionrlSLBluePenaltyYellow5->robot6 = robot6;
    conditionrlSLHaltClose0->robot1 = robot1;
    conditionrlSLHaltClose1->robot2 = robot2;
    conditionrlSLHaltClose2->robot3 = robot3;
    conditionrlSLHaltClose3->robot4 = robot4;
    conditionrlSLHaltClose4->robot5 = robot5;
    conditionrlSLHaltClose5->robot6 = robot6;
    conditionrlSLHaltCloseReady0->robot1 = robot1;
    conditionrlSLHaltCloseReady1->robot2 = robot2;
    conditionrlSLHaltCloseReady2->robot3 = robot3;
    conditionrlSLHaltCloseReady3->robot4 = robot4;
    conditionrlSLHaltCloseReady4->robot5 = robot5;
    conditionrlSLHaltCloseReady5->robot6 = robot6;
    conditionrlSLHaltNotClose0->robot1 = robot1;
    conditionrlSLHaltNotClose1->robot2 = robot2;
    conditionrlSLHaltNotClose2->robot3 = robot3;
    conditionrlSLHaltNotClose3->robot4 = robot4;
    conditionrlSLHaltNotClose4->robot5 = robot5;
    conditionrlSLHaltNotClose5->robot6 = robot6;
    conditionrlSLStartBallNotClose0->robot1 = robot1;
    conditionrlSLStartBallNotClose1->robot2 = robot2;
    conditionrlSLStartBallNotClose2->robot3 = robot3;
    conditionrlSLStartBallNotClose3->robot4 = robot4;
    conditionrlSLStartBallNotClose4->robot5 = robot5;
    conditionrlSLStartBallNotClose5->robot6 = robot6;
    conditionrlSLStopTeamLeft0->robot1 = robot1;
    conditionrlSLStopTeamLeft1->robot2 = robot2;
    conditionrlSLStopTeamLeft2->robot3 = robot3;
    conditionrlSLStopTeamLeft3->robot4 = robot4;
    conditionrlSLStopTeamLeft4->robot5 = robot5;
    conditionrlSLStopTeamLeft5->robot6 = robot6;
    conditionrlSLStopTeamRight0->robot1 = robot1;
    conditionrlSLStopTeamRight1->robot2 = robot2;
    conditionrlSLStopTeamRight2->robot3 = robot3;
    conditionrlSLStopTeamRight3->robot4 = robot4;
    conditionrlSLStopTeamRight4->robot5 = robot5;
    conditionrlSLStopTeamRight5->robot6 = robot6;
    conditionrlSLYellowDirectKick0->robot1 = robot1;
    conditionrlSLYellowDirectKick1->robot2 = robot2;
    conditionrlSLYellowDirectKick2->robot3 = robot3;
    conditionrlSLYellowDirectKick3->robot4 = robot4;
    conditionrlSLYellowDirectKick4->robot5 = robot5;
    conditionrlSLYellowDirectKick5->robot6 = robot6;
    conditionrlSLYellowIndirectKick0->robot1 = robot1;
    conditionrlSLYellowIndirectKick1->robot2 = robot2;
    conditionrlSLYellowIndirectKick2->robot3 = robot3;
    conditionrlSLYellowIndirectKick3->robot4 = robot4;
    conditionrlSLYellowIndirectKick4->robot5 = robot5;
    conditionrlSLYellowIndirectKick5->robot6 = robot6;
    conditionrlSLYellowPenaltyBlue0->robot1 = robot1;
    conditionrlSLYellowPenaltyBlue1->robot2 = robot2;
    conditionrlSLYellowPenaltyBlue2->robot3 = robot3;
    conditionrlSLYellowPenaltyBlue3->robot4 = robot4;
    conditionrlSLYellowPenaltyBlue4->robot5 = robot5;
    conditionrlSLYellowPenaltyBlue5->robot6 = robot6;
    conditionrlSLYellowPenaltyYellow0->robot1 = robot1;
    conditionrlSLYellowPenaltyYellow1->robot2 = robot2;
    conditionrlSLYellowPenaltyYellow2->robot3 = robot3;
    conditionrlSLYellowPenaltyYellow3->robot4 = robot4;
    conditionrlSLYellowPenaltyYellow4->robot5 = robot5;
    conditionrlSLYellowPenaltyYellow5->robot6 = robot6;
    conditionrlSRBlueDirectKick0->robot1 = robot1;
    conditionrlSRBlueDirectKick1->robot2 = robot2;
    conditionrlSRBlueDirectKick2->robot3 = robot3;
    conditionrlSRBlueDirectKick3->robot4 = robot4;
    conditionrlSRBlueDirectKick4->robot5 = robot5;
    conditionrlSRBlueDirectKick5->robot6 = robot6;
    conditionrlSRBlueIndirectKick0->robot1 = robot1;
    conditionrlSRBlueIndirectKick1->robot2 = robot2;
    conditionrlSRBlueIndirectKick2->robot3 = robot3;
    conditionrlSRBlueIndirectKick3->robot4 = robot4;
    conditionrlSRBlueIndirectKick4->robot5 = robot5;
    conditionrlSRBlueIndirectKick5->robot6 = robot6;
    conditionrlSRBluePenaltyBlue0->robot1 = robot1;
    conditionrlSRBluePenaltyBlue1->robot2 = robot2;
    conditionrlSRBluePenaltyBlue2->robot3 = robot3;
    conditionrlSRBluePenaltyBlue3->robot4 = robot4;
    conditionrlSRBluePenaltyBlue4->robot5 = robot5;
    conditionrlSRBluePenaltyBlue5->robot6 = robot6;
    conditionrlSRBluePenaltyYellow0->robot1 = robot1;
    conditionrlSRBluePenaltyYellow1->robot2 = robot2;
    conditionrlSRBluePenaltyYellow2->robot3 = robot3;
    conditionrlSRBluePenaltyYellow3->robot4 = robot4;
    conditionrlSRBluePenaltyYellow4->robot5 = robot5;
    conditionrlSRBluePenaltyYellow5->robot6 = robot6;
    conditionrlSRHaltClose0->robot1 = robot1;
    conditionrlSRHaltClose1->robot2 = robot2;
    conditionrlSRHaltClose2->robot3 = robot3;
    conditionrlSRHaltClose3->robot4 = robot4;
    conditionrlSRHaltClose4->robot5 = robot5;
    conditionrlSRHaltClose5->robot6 = robot6;
    conditionrlSRHaltCloseReady0->robot1 = robot1;
    conditionrlSRHaltCloseReady1->robot2 = robot2;
    conditionrlSRHaltCloseReady2->robot3 = robot3;
    conditionrlSRHaltCloseReady3->robot4 = robot4;
    conditionrlSRHaltCloseReady4->robot5 = robot5;
    conditionrlSRHaltCloseReady5->robot6 = robot6;
    conditionrlSRHaltNotClose0->robot1 = robot1;
    conditionrlSRHaltNotClose1->robot2 = robot2;
    conditionrlSRHaltNotClose2->robot3 = robot3;
    conditionrlSRHaltNotClose3->robot4 = robot4;
    conditionrlSRHaltNotClose4->robot5 = robot5;
    conditionrlSRHaltNotClose5->robot6 = robot6;
    conditionrlSRStartBallNotClose0->robot1 = robot1;
    conditionrlSRStartBallNotClose1->robot2 = robot2;
    conditionrlSRStartBallNotClose2->robot3 = robot3;
    conditionrlSRStartBallNotClose3->robot4 = robot4;
    conditionrlSRStartBallNotClose4->robot5 = robot5;
    conditionrlSRStartBallNotClose5->robot6 = robot6;
    conditionrlSRStopTeamLeft0->robot1 = robot1;
    conditionrlSRStopTeamLeft1->robot2 = robot2;
    conditionrlSRStopTeamLeft2->robot3 = robot3;
    conditionrlSRStopTeamLeft3->robot4 = robot4;
    conditionrlSRStopTeamLeft4->robot5 = robot5;
    conditionrlSRStopTeamLeft5->robot6 = robot6;
    conditionrlSRStopTeamRight0->robot1 = robot1;
    conditionrlSRStopTeamRight1->robot2 = robot2;
    conditionrlSRStopTeamRight2->robot3 = robot3;
    conditionrlSRStopTeamRight3->robot4 = robot4;
    conditionrlSRStopTeamRight4->robot5 = robot5;
    conditionrlSRStopTeamRight5->robot6 = robot6;
    conditionrlSRYellowDirectKick0->robot1 = robot1;
    conditionrlSRYellowDirectKick1->robot2 = robot2;
    conditionrlSRYellowDirectKick2->robot3 = robot3;
    conditionrlSRYellowDirectKick3->robot4 = robot4;
    conditionrlSRYellowDirectKick4->robot5 = robot5;
    conditionrlSRYellowDirectKick5->robot6 = robot6;
    conditionrlSRYellowIndirectKick0->robot1 = robot1;
    conditionrlSRYellowIndirectKick1->robot2 = robot2;
    conditionrlSRYellowIndirectKick2->robot3 = robot3;
    conditionrlSRYellowIndirectKick3->robot4 = robot4;
    conditionrlSRYellowIndirectKick4->robot5 = robot5;
    conditionrlSRYellowIndirectKick5->robot6 = robot6;
    conditionrlSRYellowsPenaltyBlue0->robot1 = robot1;
    conditionrlSRYellowsPenaltyBlue1->robot2 = robot2;
    conditionrlSRYellowsPenaltyBlue2->robot3 = robot3;
    conditionrlSRYellowsPenaltyBlue3->robot4 = robot4;
    conditionrlSRYellowsPenaltyBlue4->robot5 = robot5;
    conditionrlSRYellowsPenaltyBlue5->robot6 = robot6;
    conditionrlSRYellowsPenaltyYellow0->robot1 = robot1;
    conditionrlSRYellowsPenaltyYellow1->robot2 = robot2;
    conditionrlSRYellowsPenaltyYellow2->robot3 = robot3;
    conditionrlSRYellowsPenaltyYellow3->robot4 = robot4;
    conditionrlSRYellowsPenaltyYellow4->robot5 = robot5;
    conditionrlSRYellowsPenaltyYellow5->robot6 = robot6;
    conditionrlStartEnemyFieldKick0->robot1 = robot1;
    conditionrlStartEnemyFieldKick1->robot2 = robot2;
    conditionrlStartEnemyFieldKick2->robot3 = robot3;
    conditionrlStartEnemyFieldKick3->robot4 = robot4;
    conditionrlStartEnemyFieldKick4->robot5 = robot5;
    conditionrlStartEnemyFieldKick5->robot6 = robot6;
    conditionrlStartEnemyFieldPositionKick0->robot1 = robot1;
    conditionrlStartEnemyFieldPositionKick1->robot2 = robot2;
    conditionrlStartEnemyFieldPositionKick2->robot3 = robot3;
    conditionrlStartEnemyFieldPositionKick3->robot4 = robot4;
    conditionrlStartEnemyFieldPositionKick4->robot5 = robot5;
    conditionrlStartEnemyFieldPositionKick5->robot6 = robot6;
    conditionrlStartFreePartner0->robot1 = robot1;
    conditionrlStartFreePartner1->robot2 = robot2;
    conditionrlStartFreePartner2->robot3 = robot3;
    conditionrlStartFreePartner3->robot4 = robot4;
    conditionrlStartFreePartner4->robot5 = robot5;
    conditionrlStartFreePartner5->robot6 = robot6;
    conditionrlStartFreePartnerPass0->robot1 = robot1;
    conditionrlStartFreePartnerPass1->robot2 = robot2;
    conditionrlStartFreePartnerPass2->robot3 = robot3;
    conditionrlStartFreePartnerPass3->robot4 = robot4;
    conditionrlStartFreePartnerPass4->robot5 = robot5;
    conditionrlStartFreePartnerPass5->robot6 = robot6;
    conditionrlStartNoFreePartner0->robot1 = robot1;
    conditionrlStartNoFreePartner1->robot2 = robot2;
    conditionrlStartNoFreePartner2->robot3 = robot3;
    conditionrlStartNoFreePartner3->robot4 = robot4;
    conditionrlStartNoFreePartner4->robot5 = robot5;
    conditionrlStartNoFreePartner5->robot6 = robot6;
    conditionrlStartNoFreePartnerKick0->robot1 = robot1;
    conditionrlStartNoFreePartnerKick1->robot2 = robot2;
    conditionrlStartNoFreePartnerKick2->robot3 = robot3;
    conditionrlStartNoFreePartnerKick3->robot4 = robot4;
    conditionrlStartNoFreePartnerKick4->robot5 = robot5;
    conditionrlStartNoFreePartnerKick5->robot6 = robot6;
    conditionrlStartTargetToBall0->robot1 = robot1;
    conditionrlStartTargetToBall1->robot2 = robot2;
    conditionrlStartTargetToBall2->robot3 = robot3;
    conditionrlStartTargetToBall3->robot4 = robot4;
    conditionrlStartTargetToBall4->robot5 = robot5;
    conditionrlStartTargetToBall5->robot6 = robot6;
    conditionrlTeste->robot1 = robot1;

        CommunicationSystem* comSystem = new ComSysSimulator();

        initRobot(robot1, 0, comSystem, BaseRobot::GOALKEEPER);
        initRobot(robot2, 1, comSystem, BaseRobot::DEFENDER_LEFT);
        initRobot(robot3, 2, comSystem, BaseRobot::DEFENDER_RIGHT);
        initRobot(robot4, 3, comSystem, BaseRobot::MIDFIELD_ONLY);
        initRobot(robot5, 4, comSystem, BaseRobot::STRIKER_LEFT);
        initRobot(robot6, 5, comSystem, BaseRobot::STRIKER_RIGHT);

}

void Team::initRobot(BaseRobot *robot, int id, CommunicationSystem *comSystem, BaseRobot::PlayerRole role) {
    robot->initRobot(id,id,this->getTeamColor(),this->getSide(),comSystem,this);
    robot->setTarget(robot->getBallPosition());

    teamPlayers->push_back(robot);
    enemyPlayers->push_back(new EnemyRobot());

    robot->setatTeamSide(this->getSide() == LEFT ? "LEFT" : "RIGHT");
    robot->setTeamColor( this->getTeamColor());
    robot->setPlayerRole(role);
}

TeamColor Team::getTeamColor() {
    return this->teamColor;
}

FieldSide Team::getSide() {
    return this->fieldSide;
}

vector<BaseRobot*> * Team::getTeamPlayers() {
    return this->teamPlayers;
}

//mexer nessa funcao
void Team::updateTeamPerception(SSL_DetectionFrame detectedFrame) {
    SSL_DetectionBall ball = detectedFrame.balls(0);
    ::google::protobuf::RepeatedPtrField< ::SSL_DetectionRobot > teamFrame;
    ::google::protobuf::RepeatedPtrField< ::SSL_DetectionRobot > enemyFrame;

    if (getTeamColor() == BLUE) {
        teamFrame = detectedFrame.robots_blue();
        enemyFrame = detectedFrame.robots_yellow();
    } else {
        teamFrame = detectedFrame.robots_yellow();
        enemyFrame = detectedFrame.robots_blue();
    }

    // Read Enemy Robots Information
    for (int i = 0; i < enemyFrame.size(); i++)
    {
        SSL_DetectionRobot robotFrame = enemyFrame.Get(i);
        EnemyRobot* robot = enemyPlayers->at(robotFrame.robot_id());
        robot->setPosition ( new Point ( robotFrame.x(), robotFrame.y() ) );
        robot->setAngle( robotFrame.orientation() );
    }


    BaseRobot::PlayerRole PLAYERS [] = {   BaseRobot::GOALKEEPER, BaseRobot::DEFENDER_LEFT, BaseRobot::DEFENDER_RIGHT, BaseRobot::MIDFIELD_ONLY,
                                           BaseRobot::STRIKER_LEFT, BaseRobot::STRIKER_RIGHT };


    // Read Team Robots Information
    for (int i = 0; i < teamFrame.size(); i++)
    {
        SSL_DetectionRobot robotFrame = teamFrame.Get(i);
        BaseRobot* robot = teamPlayers->at(robotFrame.robot_id());

        // Set Robot Position:
        robot->setPosition ( new Point ( robotFrame.x(), robotFrame.y() ) );

        // Set Player Roles:
        robot->setPlayerRole(PLAYERS[i]);

        // Set Robot Angle:
        robot->setAngle( robotFrame.orientation());

        // Set Ball Position:
        robot->setBallPosition(new Point(ball.x(), ball.y()));

        // Set Team Attributes:
        robot->setTeamRobots(this->getTeamPlayers());
        robot->setatNumPlayers(teamFrame.size());
        robot->setEnemyRobots(this->enemyPlayers);

        robot->setatIsReady( robot->isReady() );

        robot->updateFieldPerceptions();
    }
}

void Team::updateCmdReferee(char cmd) {
    cmd = checkCommand(cmd);
    for (int i = 0; i < teamPlayers->size(); i++)
    {
        BaseRobot* robot = teamPlayers->at(i);
        robot->setatLastRefereeCmd(robot->getatRefereeCmd());
        robot->setatRefereeCmd(cmd);
    }
}

//ninguem usa essa funcao por enquanto
char Team::checkCommand(char cmd) {
    if (this->getTeamColor() == BLUE &&
       (cmd == 'k' ||
        cmd == 'f' ||
        cmd == 'i'   )) {
        return 'S';
    }

    if (this->getTeamColor() == YELLOW &&
       (cmd == 'K' ||
        cmd == 'F' ||
        cmd == 'I'   )) {
        return 'S';
    }

    return cmd;
}
