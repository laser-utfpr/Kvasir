#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

#include "coord.hpp"
#include "entity.hpp"
#include "movement.hpp"

class Player : public Entity
{
private:

public:
    Coord destination;

    Movement movement;

    std::string status;

    inline Player():Entity() {};
    inline Player& operator=(const Entity &copied)
    {
        if(static_cast<Entity*>(this) != &copied)
        {
            coord = copied.coord;
            angle = copied.angle;
            already_found = copied.already_found;
            found_last_frame = copied.found_last_frame;
        }
        return *this;
    }
};

#endif // PLAYER_HPP
