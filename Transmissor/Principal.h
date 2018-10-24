#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#include <Arduino.h>
#include "SerialCommunication.h"
#include "RadioWriter.h"

class Principal{
    SerialCommunication* serial;
    RadioWriter* rWriter;
public:
    Principal();
    ~Principal() {}
    void PrincipalStart();
};

#endif
