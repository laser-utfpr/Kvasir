#ifndef ROBOTMSG_H
#define ROBOTMSG_H

struct RobotMsg{
    char process[20]; //--Nome do processo!
    float velX;//--Velocidade em X
    float velY;//--Velocidade em Y
    float velAng;
    char chute;//--Chute (sim ou não);
    char status;//--"reserva técnica", se necessário, usa-se esse espaço.
};
#endif
