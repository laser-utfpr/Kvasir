#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "visionconstants.h"
#include "coord.hpp"

class Entity
{
private:

public:
    Coord coord;
    double angle;
    bool already_found;
    bool found_last_frame;
};

#endif // ENTITY_HPP
