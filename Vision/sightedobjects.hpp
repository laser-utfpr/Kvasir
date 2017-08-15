#ifndef SIGHTEDOBJECTS_HPP
#define SIGHTEDOBJECTS_HPP

#include "framesholder.hpp"
class FramesHolder;

#include "visionconstants.h"

typedef struct node
{
    double x;
    double y;
    double area;
    int color;
    struct node* next;
    struct node* prev;
}sightedObject;

class SightedObjects
{
private:
    sightedObject *object;
    int n_objects;
    void destroyList(sightedObject *node);
public:
    SightedObjects();
    ~SightedObjects();
    void addObject(double x, double y, double area, int color);
    void paintObjects(FramesHolder *frames);
};

#endif // SIGHTEDOBJECTS_HPP

