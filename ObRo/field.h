#ifndef FIELD_H
#define FIELD_H

#include <iostream>

#include "obroconstants.h"
#include "entity.h"

typedef struct
{
    entity ball;
    entity robot[N_PLAYERS];
    entity enemy_robot[N_PLAYERS];
    useconds_t time_us;
    double image_width;
    double image_height;
}field;

#endif //FIELD_H
