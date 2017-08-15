#ifndef SIGHTEDOBJECTS_HPP
#define SIGHTEDOBJECTS_HPP

#include "visionconstants.h"

typedef struct
{
    double x;
    double y;
    double area;
    objectColor color;
}sightedObject;

class SightedObjects
{
private:
    sightedObject *object;
    int n_objects;

    static SightedObjects* instance;
    SightedObjects();
public:
    static SightedObjects* getInstance(void);
};

#endif // SIGHTEDOBJECTS_HPP

