#include "Robot.hpp"

Robot::Robot()
{
    int i;
    for(i=0; i<4; i++)
    {
        velocity[i] = 0;
    }
    motors[0] = new RotaryServoMotor(MOTOR1_PIN, MAX_SPEED, MOTOR1_ADJUST_SPEED);
    motors[1] = new RotaryServoMotor(MOTOR2_PIN, MAX_SPEED, MOTOR2_ADJUST_SPEED);
    motors[2] = new RotaryServoMotor(MOTOR3_PIN, MAX_SPEED, MOTOR3_ADJUST_SPEED);
    motors[3] = new RotaryServoMotor(MOTOR4_PIN, MAX_SPEED, MOTOR4_ADJUST_SPEED);
}

void Robot::move(float vel_x, float vel_y, float vel_ang)
{
    //Serial.print("vel x");
    //Serial.print(vel_x);
    //Serial.print("vel y");
    //Serial.println(vel_y);
    calculateMotorsVelocity(vel_x, vel_y, vel_ang);
    for(int i=0; i<4; i++)
    {
        motors[i]->setSpeed(velocity[i]);
    }
}

void Robot::calculateMotorsVelocity(float vel_x, float vel_y, float vel_ang)
{
    //--Robô Visto de Cima
    //            _
    //      M1    /|
    //   ___|___ /
    //   |     |
    //M4-|CIMA!|-M2
    //   |     |
    //    -----
    //      |
    //      M3
    //

    float  vox=0, voy=0;
    vox = cos(ANG)*vel_x + sin(ANG)*vel_y;
    voy = -sin(ANG)*vel_x + cos(ANG)*vel_y;
    velocity[0]  = vox + vel_ang*WHEEL_RADIUS;
    velocity[1] = -voy + vel_ang*WHEEL_RADIUS;
    velocity[2] = -vox + vel_ang*WHEEL_RADIUS;
    velocity[3] = voy + vel_ang*WHEEL_RADIUS;
}
