#ifndef COLOREDOBJECT_HPP
#define COLOREDOBJECT_HPP

#include "coord.hpp"
#include "smmcconstants.h"

class ColoredObject
{
private:

public:
    Coord coord;
    double area;
    Color color;
    bool linked_to_entity;
};

#endif // COLOREDOBJECT_HPP
