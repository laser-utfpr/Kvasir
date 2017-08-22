#ifndef SIGHTEDOBJECTS_HPP
#define SIGHTEDOBJECTS_HPP

#include "framesholder.hpp"
class FramesHolder;

#include "visionconstants.h"

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/offset_ptr.hpp>
//#include <boost/interprocess/mapped_region.hpp>

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
    boost::interprocess::managed_shared_memory* shared_memory;
    static SightedObjects* instance;
    SightedObjects();
    void destroyList(sightedObject *node);
    void printObjects(sightedObject *obj);
public:
    static SightedObjects* getInstance(void);
    ~SightedObjects();
    void addObject(double x, double y, double area, objectColor color);
    void paintObjects(FramesHolder *frames);
    void printObjects(void);
    void destroyList(void);
    void incrementTime(void);
};

#endif // SIGHTEDOBJECTS_HPP

