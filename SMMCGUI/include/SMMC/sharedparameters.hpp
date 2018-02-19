#ifndef SHAREDPARAMETERS_HPP
#define SHAREDPARAMETERS_HPP

#include <QtCore>

#include <iostream>
#include <fstream>

#include "field.hpp"

class SharedParameters
{
private:
    //Vision
    Field field;
    //AI
    //Communication
public:
    SharedParameters();
    ~SharedParameters();
};

#endif // SHAREDPARAMETERS_HPP
