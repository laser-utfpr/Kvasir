#ifndef SIGHTEDOBJECT_H
#define SIGHTEDOBJECT_H

#include "visionconstants.h"

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/offset_ptr.hpp>

typedef struct so_node
{
    double x;
    double y;
    double area;
    objectColor color;
    boost::interprocess::offset_ptr<struct so_node> next;
    boost::interprocess::offset_ptr<struct so_node> prev;
}sightedObject;

typedef struct temp_so_node
{
    double x;
    double y;
    double area;
    objectColor color;
    struct temp_so_node *next;
    struct temp_so_node *prev;
}tempSightedObject;

#endif // SIGHTEDOBJECT_H
