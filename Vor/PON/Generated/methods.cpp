#include "methods.h"
#include "instances.h"
#include <string>
#include <iostream>

namespace method {
	namespace main {
		namespace robot1 {
			namespace mtAngleMove {
				void mtAngleMove() {
					
            angleMove();
        
				}
			}
			namespace mtExecuteMove {
				void mtExecuteMove() {
					
            executeMove();
        
				}
			}
			namespace mtGkEnemyPenalty {
				void mtGkEnemyPenalty() {
					
            behaviorGkPenalty();
        
				}
			}
			namespace mtGkOutArea {
				void mtGkOutArea() {
					
            behaviorGkBallOutsideArea();
        
				}
			}
			namespace mtInfo {
				void mtInfo() {
					
            cout << "Method DEBUG called from Robot! "<< endl;
        
				}
			}
			namespace mtMoveIndirectKick {
				void mtMoveIndirectKick() {
					
            moveToIndirectKickPosition();
        
				}
			}
			namespace mtMoveLeftPost {
				void mtMoveLeftPost() {
					
            moveToLeftPost();
        
				}
			}
			namespace mtMoveLeftWarmUp {
				void mtMoveLeftWarmUp() {
					
            moveLeftWarmUpPos();
        
				}
			}
			namespace mtMovePenaltyDefLeft {
				void mtMovePenaltyDefLeft() {
					
            movePenaltyDefenseLeftPosition();
        
				}
			}
			namespace mtMovePenaltyDefRight {
				void mtMovePenaltyDefRight() {
					
            movePenaltyDefenseRightPosition();
        
				}
			}
			namespace mtMovePenaltyKick {
				void mtMovePenaltyKick() {
					
            positionKickPenalty();
        
				}
			}
			namespace mtMovePosAngleNeg {
				void mtMovePosAngleNeg() {
					
            moveToStopPositionNegativeAngle();
        
				}
			}
			namespace mtMovePosAngleNeg3pl {
				void mtMovePosAngleNeg3pl() {
					
            moveToStopPositionNegativeAngle3pl();
        
				}
			}
			namespace mtMovePosAnglePos {
				void mtMovePosAnglePos() {
					
            moveToStopPositionPositiveAngle();
        
				}
			}
			namespace mtMovePosAnglePos3pl {
				void mtMovePosAnglePos3pl() {
					
            moveToStopPositionNegativeAngle3pl();
        
				}
			}
			namespace mtMovePositionToKick {
				void mtMovePositionToKick() {
					
            moveToKickPosition();
        
				}
			}
			namespace mtMoveRightPost {
				void mtMoveRightPost() {
					
            moveToRightPost();
        
				}
			}
			namespace mtMoveRightWarmUp {
				void mtMoveRightWarmUp() {
					
            moveRightWarmUpPos();
        
				}
			}
			namespace mtMoveStopPosition {
				void mtMoveStopPosition() {
					
            moveToStopPosition();
        
				}
			}
			namespace mtPassBallPartner {
				void mtPassBallPartner() {
					
            passBallPartner();
        
				}
			}
			namespace mtPenaltyAttackLeft {
				void mtPenaltyAttackLeft() {
					
            movePenaltyAttackLeftPosition();
        
				}
			}
			namespace mtPenaltyAttackRight {
				void mtPenaltyAttackRight() {
					
            movePenaltyAttackRightPosition();
        
				}
			}
			namespace mtPenaltyDefCenter {
				void mtPenaltyDefCenter() {
					
            movePenaltyDefenseCenterPosition();
        
				}
			}
			namespace mtPosPassBall {
				void mtPosPassBall() {
					
            positionTopassBallPartner();
        
				}
			}
			namespace mtReadyKickoff {
				void mtReadyKickoff() {
					
            readyKickoff();
        
				}
			}
			namespace mtReadyPenalty {
				void mtReadyPenalty() {
					
            readyPenalty();
        
				}
			}
			namespace mtResetKick {
				void mtResetKick() {
					
            resetKickAndDribble();
        
				}
			}
			namespace mtStrickerLeftDirect {
				void mtStrickerLeftDirect() {
					
            moveStrikerPositionLeft();
        
				}
			}
			namespace mtStrickerRightDirect {
				void mtStrickerRightDirect() {
					
            moveStrikerPositionRight();
        
				}
			}
			namespace mtTargetToBall {
				void mtTargetToBall() {
					
            targetToBall();
        
				}
			}
		}
		namespace robot2 {
			namespace mtAngleMove {
				void mtAngleMove() {
					
            angleMove();
        
				}
			}
			namespace mtExecuteMove {
				void mtExecuteMove() {
					
            executeMove();
        
				}
			}
			namespace mtGkEnemyPenalty {
				void mtGkEnemyPenalty() {
					
            behaviorGkPenalty();
        
				}
			}
			namespace mtGkOutArea {
				void mtGkOutArea() {
					
            behaviorGkBallOutsideArea();
        
				}
			}
			namespace mtInfo {
				void mtInfo() {
					
            cout << "Method DEBUG called from Robot! "<< endl;
        
				}
			}
			namespace mtMoveIndirectKick {
				void mtMoveIndirectKick() {
					
            moveToIndirectKickPosition();
        
				}
			}
			namespace mtMoveLeftPost {
				void mtMoveLeftPost() {
					
            moveToLeftPost();
        
				}
			}
			namespace mtMoveLeftWarmUp {
				void mtMoveLeftWarmUp() {
					
            moveLeftWarmUpPos();
        
				}
			}
			namespace mtMovePenaltyDefLeft {
				void mtMovePenaltyDefLeft() {
					
            movePenaltyDefenseLeftPosition();
        
				}
			}
			namespace mtMovePenaltyDefRight {
				void mtMovePenaltyDefRight() {
					
            movePenaltyDefenseRightPosition();
        
				}
			}
			namespace mtMovePenaltyKick {
				void mtMovePenaltyKick() {
					
            positionKickPenalty();
        
				}
			}
			namespace mtMovePosAngleNeg {
				void mtMovePosAngleNeg() {
					
            moveToStopPositionNegativeAngle();
        
				}
			}
			namespace mtMovePosAngleNeg3pl {
				void mtMovePosAngleNeg3pl() {
					
            moveToStopPositionNegativeAngle3pl();
        
				}
			}
			namespace mtMovePosAnglePos {
				void mtMovePosAnglePos() {
					
            moveToStopPositionPositiveAngle();
        
				}
			}
			namespace mtMovePosAnglePos3pl {
				void mtMovePosAnglePos3pl() {
					
            moveToStopPositionNegativeAngle3pl();
        
				}
			}
			namespace mtMovePositionToKick {
				void mtMovePositionToKick() {
					
            moveToKickPosition();
        
				}
			}
			namespace mtMoveRightPost {
				void mtMoveRightPost() {
					
            moveToRightPost();
        
				}
			}
			namespace mtMoveRightWarmUp {
				void mtMoveRightWarmUp() {
					
            moveRightWarmUpPos();
        
				}
			}
			namespace mtMoveStopPosition {
				void mtMoveStopPosition() {
					
            moveToStopPosition();
        
				}
			}
			namespace mtPassBallPartner {
				void mtPassBallPartner() {
					
            passBallPartner();
        
				}
			}
			namespace mtPenaltyAttackLeft {
				void mtPenaltyAttackLeft() {
					
            movePenaltyAttackLeftPosition();
        
				}
			}
			namespace mtPenaltyAttackRight {
				void mtPenaltyAttackRight() {
					
            movePenaltyAttackRightPosition();
        
				}
			}
			namespace mtPenaltyDefCenter {
				void mtPenaltyDefCenter() {
					
            movePenaltyDefenseCenterPosition();
        
				}
			}
			namespace mtPosPassBall {
				void mtPosPassBall() {
					
            positionTopassBallPartner();
        
				}
			}
			namespace mtReadyKickoff {
				void mtReadyKickoff() {
					
            readyKickoff();
        
				}
			}
			namespace mtReadyPenalty {
				void mtReadyPenalty() {
					
            readyPenalty();
        
				}
			}
			namespace mtResetKick {
				void mtResetKick() {
					
            resetKickAndDribble();
        
				}
			}
			namespace mtStrickerLeftDirect {
				void mtStrickerLeftDirect() {
					
            moveStrikerPositionLeft();
        
				}
			}
			namespace mtStrickerRightDirect {
				void mtStrickerRightDirect() {
					
            moveStrikerPositionRight();
        
				}
			}
			namespace mtTargetToBall {
				void mtTargetToBall() {
					
            targetToBall();
        
				}
			}
		}
		namespace robot3 {
			namespace mtAngleMove {
				void mtAngleMove() {
					
            angleMove();
        
				}
			}
			namespace mtExecuteMove {
				void mtExecuteMove() {
					
            executeMove();
        
				}
			}
			namespace mtGkEnemyPenalty {
				void mtGkEnemyPenalty() {
					
            behaviorGkPenalty();
        
				}
			}
			namespace mtGkOutArea {
				void mtGkOutArea() {
					
            behaviorGkBallOutsideArea();
        
				}
			}
			namespace mtInfo {
				void mtInfo() {
					
            cout << "Method DEBUG called from Robot! "<< endl;
        
				}
			}
			namespace mtMoveIndirectKick {
				void mtMoveIndirectKick() {
					
            moveToIndirectKickPosition();
        
				}
			}
			namespace mtMoveLeftPost {
				void mtMoveLeftPost() {
					
            moveToLeftPost();
        
				}
			}
			namespace mtMoveLeftWarmUp {
				void mtMoveLeftWarmUp() {
					
            moveLeftWarmUpPos();
        
				}
			}
			namespace mtMovePenaltyDefLeft {
				void mtMovePenaltyDefLeft() {
					
            movePenaltyDefenseLeftPosition();
        
				}
			}
			namespace mtMovePenaltyDefRight {
				void mtMovePenaltyDefRight() {
					
            movePenaltyDefenseRightPosition();
        
				}
			}
			namespace mtMovePenaltyKick {
				void mtMovePenaltyKick() {
					
            positionKickPenalty();
        
				}
			}
			namespace mtMovePosAngleNeg {
				void mtMovePosAngleNeg() {
					
            moveToStopPositionNegativeAngle();
        
				}
			}
			namespace mtMovePosAngleNeg3pl {
				void mtMovePosAngleNeg3pl() {
					
            moveToStopPositionNegativeAngle3pl();
        
				}
			}
			namespace mtMovePosAnglePos {
				void mtMovePosAnglePos() {
					
            moveToStopPositionPositiveAngle();
        
				}
			}
			namespace mtMovePosAnglePos3pl {
				void mtMovePosAnglePos3pl() {
					
            moveToStopPositionNegativeAngle3pl();
        
				}
			}
			namespace mtMovePositionToKick {
				void mtMovePositionToKick() {
					
            moveToKickPosition();
        
				}
			}
			namespace mtMoveRightPost {
				void mtMoveRightPost() {
					
            moveToRightPost();
        
				}
			}
			namespace mtMoveRightWarmUp {
				void mtMoveRightWarmUp() {
					
            moveRightWarmUpPos();
        
				}
			}
			namespace mtMoveStopPosition {
				void mtMoveStopPosition() {
					
            moveToStopPosition();
        
				}
			}
			namespace mtPassBallPartner {
				void mtPassBallPartner() {
					
            passBallPartner();
        
				}
			}
			namespace mtPenaltyAttackLeft {
				void mtPenaltyAttackLeft() {
					
            movePenaltyAttackLeftPosition();
        
				}
			}
			namespace mtPenaltyAttackRight {
				void mtPenaltyAttackRight() {
					
            movePenaltyAttackRightPosition();
        
				}
			}
			namespace mtPenaltyDefCenter {
				void mtPenaltyDefCenter() {
					
            movePenaltyDefenseCenterPosition();
        
				}
			}
			namespace mtPosPassBall {
				void mtPosPassBall() {
					
            positionTopassBallPartner();
        
				}
			}
			namespace mtReadyKickoff {
				void mtReadyKickoff() {
					
            readyKickoff();
        
				}
			}
			namespace mtReadyPenalty {
				void mtReadyPenalty() {
					
            readyPenalty();
        
				}
			}
			namespace mtResetKick {
				void mtResetKick() {
					
            resetKickAndDribble();
        
				}
			}
			namespace mtStrickerLeftDirect {
				void mtStrickerLeftDirect() {
					
            moveStrikerPositionLeft();
        
				}
			}
			namespace mtStrickerRightDirect {
				void mtStrickerRightDirect() {
					
            moveStrikerPositionRight();
        
				}
			}
			namespace mtTargetToBall {
				void mtTargetToBall() {
					
            targetToBall();
        
				}
			}
		}
		namespace robot4 {
			namespace mtAngleMove {
				void mtAngleMove() {
					
            angleMove();
        
				}
			}
			namespace mtExecuteMove {
				void mtExecuteMove() {
					
            executeMove();
        
				}
			}
			namespace mtGkEnemyPenalty {
				void mtGkEnemyPenalty() {
					
            behaviorGkPenalty();
        
				}
			}
			namespace mtGkOutArea {
				void mtGkOutArea() {
					
            behaviorGkBallOutsideArea();
        
				}
			}
			namespace mtInfo {
				void mtInfo() {
					
            cout << "Method DEBUG called from Robot! "<< endl;
        
				}
			}
			namespace mtMoveIndirectKick {
				void mtMoveIndirectKick() {
					
            moveToIndirectKickPosition();
        
				}
			}
			namespace mtMoveLeftPost {
				void mtMoveLeftPost() {
					
            moveToLeftPost();
        
				}
			}
			namespace mtMoveLeftWarmUp {
				void mtMoveLeftWarmUp() {
					
            moveLeftWarmUpPos();
        
				}
			}
			namespace mtMovePenaltyDefLeft {
				void mtMovePenaltyDefLeft() {
					
            movePenaltyDefenseLeftPosition();
        
				}
			}
			namespace mtMovePenaltyDefRight {
				void mtMovePenaltyDefRight() {
					
            movePenaltyDefenseRightPosition();
        
				}
			}
			namespace mtMovePenaltyKick {
				void mtMovePenaltyKick() {
					
            positionKickPenalty();
        
				}
			}
			namespace mtMovePosAngleNeg {
				void mtMovePosAngleNeg() {
					
            moveToStopPositionNegativeAngle();
        
				}
			}
			namespace mtMovePosAngleNeg3pl {
				void mtMovePosAngleNeg3pl() {
					
            moveToStopPositionNegativeAngle3pl();
        
				}
			}
			namespace mtMovePosAnglePos {
				void mtMovePosAnglePos() {
					
            moveToStopPositionPositiveAngle();
        
				}
			}
			namespace mtMovePosAnglePos3pl {
				void mtMovePosAnglePos3pl() {
					
            moveToStopPositionNegativeAngle3pl();
        
				}
			}
			namespace mtMovePositionToKick {
				void mtMovePositionToKick() {
					
            moveToKickPosition();
        
				}
			}
			namespace mtMoveRightPost {
				void mtMoveRightPost() {
					
            moveToRightPost();
        
				}
			}
			namespace mtMoveRightWarmUp {
				void mtMoveRightWarmUp() {
					
            moveRightWarmUpPos();
        
				}
			}
			namespace mtMoveStopPosition {
				void mtMoveStopPosition() {
					
            moveToStopPosition();
        
				}
			}
			namespace mtPassBallPartner {
				void mtPassBallPartner() {
					
            passBallPartner();
        
				}
			}
			namespace mtPenaltyAttackLeft {
				void mtPenaltyAttackLeft() {
					
            movePenaltyAttackLeftPosition();
        
				}
			}
			namespace mtPenaltyAttackRight {
				void mtPenaltyAttackRight() {
					
            movePenaltyAttackRightPosition();
        
				}
			}
			namespace mtPenaltyDefCenter {
				void mtPenaltyDefCenter() {
					
            movePenaltyDefenseCenterPosition();
        
				}
			}
			namespace mtPosPassBall {
				void mtPosPassBall() {
					
            positionTopassBallPartner();
        
				}
			}
			namespace mtReadyKickoff {
				void mtReadyKickoff() {
					
            readyKickoff();
        
				}
			}
			namespace mtReadyPenalty {
				void mtReadyPenalty() {
					
            readyPenalty();
        
				}
			}
			namespace mtResetKick {
				void mtResetKick() {
					
            resetKickAndDribble();
        
				}
			}
			namespace mtStrickerLeftDirect {
				void mtStrickerLeftDirect() {
					
            moveStrikerPositionLeft();
        
				}
			}
			namespace mtStrickerRightDirect {
				void mtStrickerRightDirect() {
					
            moveStrikerPositionRight();
        
				}
			}
			namespace mtTargetToBall {
				void mtTargetToBall() {
					
            targetToBall();
        
				}
			}
		}
		namespace robot5 {
			namespace mtAngleMove {
				void mtAngleMove() {
					
            angleMove();
        
				}
			}
			namespace mtExecuteMove {
				void mtExecuteMove() {
					
            executeMove();
        
				}
			}
			namespace mtGkEnemyPenalty {
				void mtGkEnemyPenalty() {
					
            behaviorGkPenalty();
        
				}
			}
			namespace mtGkOutArea {
				void mtGkOutArea() {
					
            behaviorGkBallOutsideArea();
        
				}
			}
			namespace mtInfo {
				void mtInfo() {
					
            cout << "Method DEBUG called from Robot! "<< endl;
        
				}
			}
			namespace mtMoveIndirectKick {
				void mtMoveIndirectKick() {
					
            moveToIndirectKickPosition();
        
				}
			}
			namespace mtMoveLeftPost {
				void mtMoveLeftPost() {
					
            moveToLeftPost();
        
				}
			}
			namespace mtMoveLeftWarmUp {
				void mtMoveLeftWarmUp() {
					
            moveLeftWarmUpPos();
        
				}
			}
			namespace mtMovePenaltyDefLeft {
				void mtMovePenaltyDefLeft() {
					
            movePenaltyDefenseLeftPosition();
        
				}
			}
			namespace mtMovePenaltyDefRight {
				void mtMovePenaltyDefRight() {
					
            movePenaltyDefenseRightPosition();
        
				}
			}
			namespace mtMovePenaltyKick {
				void mtMovePenaltyKick() {
					
            positionKickPenalty();
        
				}
			}
			namespace mtMovePosAngleNeg {
				void mtMovePosAngleNeg() {
					
            moveToStopPositionNegativeAngle();
        
				}
			}
			namespace mtMovePosAngleNeg3pl {
				void mtMovePosAngleNeg3pl() {
					
            moveToStopPositionNegativeAngle3pl();
        
				}
			}
			namespace mtMovePosAnglePos {
				void mtMovePosAnglePos() {
					
            moveToStopPositionPositiveAngle();
        
				}
			}
			namespace mtMovePosAnglePos3pl {
				void mtMovePosAnglePos3pl() {
					
            moveToStopPositionNegativeAngle3pl();
        
				}
			}
			namespace mtMovePositionToKick {
				void mtMovePositionToKick() {
					
            moveToKickPosition();
        
				}
			}
			namespace mtMoveRightPost {
				void mtMoveRightPost() {
					
            moveToRightPost();
        
				}
			}
			namespace mtMoveRightWarmUp {
				void mtMoveRightWarmUp() {
					
            moveRightWarmUpPos();
        
				}
			}
			namespace mtMoveStopPosition {
				void mtMoveStopPosition() {
					
            moveToStopPosition();
        
				}
			}
			namespace mtPassBallPartner {
				void mtPassBallPartner() {
					
            passBallPartner();
        
				}
			}
			namespace mtPenaltyAttackLeft {
				void mtPenaltyAttackLeft() {
					
            movePenaltyAttackLeftPosition();
        
				}
			}
			namespace mtPenaltyAttackRight {
				void mtPenaltyAttackRight() {
					
            movePenaltyAttackRightPosition();
        
				}
			}
			namespace mtPenaltyDefCenter {
				void mtPenaltyDefCenter() {
					
            movePenaltyDefenseCenterPosition();
        
				}
			}
			namespace mtPosPassBall {
				void mtPosPassBall() {
					
            positionTopassBallPartner();
        
				}
			}
			namespace mtReadyKickoff {
				void mtReadyKickoff() {
					
            readyKickoff();
        
				}
			}
			namespace mtReadyPenalty {
				void mtReadyPenalty() {
					
            readyPenalty();
        
				}
			}
			namespace mtResetKick {
				void mtResetKick() {
					
            resetKickAndDribble();
        
				}
			}
			namespace mtStrickerLeftDirect {
				void mtStrickerLeftDirect() {
					
            moveStrikerPositionLeft();
        
				}
			}
			namespace mtStrickerRightDirect {
				void mtStrickerRightDirect() {
					
            moveStrikerPositionRight();
        
				}
			}
			namespace mtTargetToBall {
				void mtTargetToBall() {
					
            targetToBall();
        
				}
			}
		}
		namespace robot6 {
			namespace mtAngleMove {
				void mtAngleMove() {
					
            angleMove();
        
				}
			}
			namespace mtExecuteMove {
				void mtExecuteMove() {
					
            executeMove();
        
				}
			}
			namespace mtGkEnemyPenalty {
				void mtGkEnemyPenalty() {
					
            behaviorGkPenalty();
        
				}
			}
			namespace mtGkOutArea {
				void mtGkOutArea() {
					
            behaviorGkBallOutsideArea();
        
				}
			}
			namespace mtInfo {
				void mtInfo() {
					
            cout << "Method DEBUG called from Robot! "<< endl;
        
				}
			}
			namespace mtMoveIndirectKick {
				void mtMoveIndirectKick() {
					
            moveToIndirectKickPosition();
        
				}
			}
			namespace mtMoveLeftPost {
				void mtMoveLeftPost() {
					
            moveToLeftPost();
        
				}
			}
			namespace mtMoveLeftWarmUp {
				void mtMoveLeftWarmUp() {
					
            moveLeftWarmUpPos();
        
				}
			}
			namespace mtMovePenaltyDefLeft {
				void mtMovePenaltyDefLeft() {
					
            movePenaltyDefenseLeftPosition();
        
				}
			}
			namespace mtMovePenaltyDefRight {
				void mtMovePenaltyDefRight() {
					
            movePenaltyDefenseRightPosition();
        
				}
			}
			namespace mtMovePenaltyKick {
				void mtMovePenaltyKick() {
					
            positionKickPenalty();
        
				}
			}
			namespace mtMovePosAngleNeg {
				void mtMovePosAngleNeg() {
					
            moveToStopPositionNegativeAngle();
        
				}
			}
			namespace mtMovePosAngleNeg3pl {
				void mtMovePosAngleNeg3pl() {
					
            moveToStopPositionNegativeAngle3pl();
        
				}
			}
			namespace mtMovePosAnglePos {
				void mtMovePosAnglePos() {
					
            moveToStopPositionPositiveAngle();
        
				}
			}
			namespace mtMovePosAnglePos3pl {
				void mtMovePosAnglePos3pl() {
					
            moveToStopPositionNegativeAngle3pl();
        
				}
			}
			namespace mtMovePositionToKick {
				void mtMovePositionToKick() {
					
            moveToKickPosition();
        
				}
			}
			namespace mtMoveRightPost {
				void mtMoveRightPost() {
					
            moveToRightPost();
        
				}
			}
			namespace mtMoveRightWarmUp {
				void mtMoveRightWarmUp() {
					
            moveRightWarmUpPos();
        
				}
			}
			namespace mtMoveStopPosition {
				void mtMoveStopPosition() {
					
            moveToStopPosition();
        
				}
			}
			namespace mtPassBallPartner {
				void mtPassBallPartner() {
					
            passBallPartner();
        
				}
			}
			namespace mtPenaltyAttackLeft {
				void mtPenaltyAttackLeft() {
					
            movePenaltyAttackLeftPosition();
        
				}
			}
			namespace mtPenaltyAttackRight {
				void mtPenaltyAttackRight() {
					
            movePenaltyAttackRightPosition();
        
				}
			}
			namespace mtPenaltyDefCenter {
				void mtPenaltyDefCenter() {
					
            movePenaltyDefenseCenterPosition();
        
				}
			}
			namespace mtPosPassBall {
				void mtPosPassBall() {
					
            positionTopassBallPartner();
        
				}
			}
			namespace mtReadyKickoff {
				void mtReadyKickoff() {
					
            readyKickoff();
        
				}
			}
			namespace mtReadyPenalty {
				void mtReadyPenalty() {
					
            readyPenalty();
        
				}
			}
			namespace mtResetKick {
				void mtResetKick() {
					
            resetKickAndDribble();
        
				}
			}
			namespace mtStrickerLeftDirect {
				void mtStrickerLeftDirect() {
					
            moveStrikerPositionLeft();
        
				}
			}
			namespace mtStrickerRightDirect {
				void mtStrickerRightDirect() {
					
            moveStrikerPositionRight();
        
				}
			}
			namespace mtTargetToBall {
				void mtTargetToBall() {
					
            targetToBall();
        
				}
			}
		}
	}
}
