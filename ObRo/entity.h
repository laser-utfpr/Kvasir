#ifndef ENTITY_H
#define ENTITY_H

#include "obroconstants.h"

typedef struct
{
    double x;
    double y;
    double angle;
    entityType type;
    bool found;
}entity;

#endif //ENTITY_H
