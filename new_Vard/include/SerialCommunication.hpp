//biblioteca feita para comunicacao serial com um radio diretamente conectado a porta, ou com um intermediario

#ifndef _SERIALCOMMUNICATION_HPP_
#define _SERIALCOMMUNICATION_HPP_

#include "VardConstats.h"
#include "rs232.h"

class SerialCommunication{
    unsigned char data[PACKET_SIZE];

public:
    SerialCommunication();
    ~SerialCommunication();
    void sendData();
    void mountPacket(int name, char *rf_address, float vel_x, float vel_y, float vel_ang);
};

#endif
