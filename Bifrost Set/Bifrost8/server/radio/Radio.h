#ifndef _RADIO_H_
#define _RADIO_H_
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <string>
#include <iostream>
#include "rs232.h"
#include "../ServerConstantes.h"

class Radio{
public:
    Radio();
    ~Radio() {};
    void setup();
    void send(unsigned char *transmitir);
    //char* receive();
};

#endif
