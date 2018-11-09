//biblioteca responsavel por receber os dados do PC, e coloca-los num buffer local, para ser reenviados aos robos via rf

#ifndef _SERIALCOMMUNICATION_H_
#define _SERIALCOMMUNICATION_H_

#include <Arduino.h>
#include "TransConstants.h"
#include "Buffer.h"

class SerialCommunication{
private:
    Buffer* queue;
    uint8_t address[W_ADDRESS];
    unsigned char data[W_DATA];

public:
    SerialCommunication();
    int receberRS232();
    uint8_t* getAdress();
    unsigned char* getData();
    char getName();
    ~SerialCommunication() {};
};
#endif
