#ifndef _PRINCIPAL_HPP_
#define _PRINCIPAL_HPP_

#include <Arduino.h>
#include "Robot.hpp"
#include "RFreceiver.hpp"

class Principal{
    RFreceiver *rf_receiver;
    Robot *robot;

public:
    Principal();
    ~Principal(){}
    void start();

};

#endif
