#ifndef SIGHTEDOBJECTS_HPP
#define SIGHTEDOBJECTS_HPP

#include "framesholder.hpp"
class FramesHolder;

#include "visionconstants.h"

#include <ctime>
#include <iostream>

typedef struct node
{
    double x;
    double y;
    double area;
    objectColor color;
    struct node* next;
    struct node* prev;
}sightedObject;

class SightedObjects
{
private:
    sightedObject *list;
    int n_objects;
    useconds_t micros;
    void destroyList(sightedObject *node);
    void printObjects(sightedObject *obj);
public:
    SightedObjects();
    ~SightedObjects();
    void addObject(double x, double y, double area, objectColor color);
    void paintObjects(FramesHolder *frames);
    void printObjects(void);
    void destroyList(void);
    void incrementTime(void);
};

#endif // SIGHTEDOBJECTS_HPP

