//biblioteca responsavel por receber os dados do PC, e coloca-los num buffer local, para ser reenviados aos robos via rf

#ifndef _SERIALCOMMUNICATION_H_
#define _SERIALCOMMUNICATION_H_

#include <Arduino.h>
#include "TransConstants.h"
#include "Buffer.h"

class SerialCommunication{
private:
    //Buffer* queue;
    uint8_t address[W_ADDRESS];
    unsigned char data[W_DATA];
    unsigned char received_data[W_DATA+W_ADDRESS+1];

public:
    SerialCommunication();
    int receiveRS232();
    void getAddress(uint8_t *_address);
    void getData(unsigned char *_data);
    char getName();
    ~SerialCommunication() {};
};
#endif
