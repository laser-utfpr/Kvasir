#ifndef COLOROBJECT_H
#define COLOROBJECT_H

#include "obroconstants.h"
#include "../Vision/visionconstants.h"

typedef struct co_node
{
    double x;
    double y;
    double area;
    objectColor color;
    entityType entity_type;
    struct co_node *next;
    struct co_node *prev;
}colorObject;

#endif // COLOROBJECT_H
