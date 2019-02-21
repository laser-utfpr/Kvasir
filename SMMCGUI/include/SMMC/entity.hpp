#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "coord.hpp"

class Entity
{
private:

public:
    Coord coord;
    double angle;
    bool already_found;
    bool found_last_frame;

    inline Entity() : angle(0.0), already_found(false),
    found_last_frame(false) {};

    inline Entity& operator=(const Entity &copied)
    {
        if(this != &copied)
        {
            coord = copied.coord;
            angle = copied.angle;
            already_found = copied.already_found;
            found_last_frame = copied.found_last_frame;
        }
        return *this;
    }
};

#endif // ENTITY_HPP
