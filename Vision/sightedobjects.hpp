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
    boost::interprocess::offset_ptr<struct node> next;
    boost::interprocess::offset_ptr<struct node> prev;
}sightedObject;

class SightedObjects
{
private:
    boost::interprocess::offset_ptr<sightedObject> list;
    boost::interprocess::offset_ptr<int> n_objects;
    boost::interprocess::offset_ptr<useconds_t> micros;
    boost::interprocess::managed_shared_memory* shared_memory;
    static SightedObjects* instance;
    SightedObjects();
    void destroyList(boost::interprocess::offset_ptr<sightedObject> node);
    void printObjects(boost::interprocess::offset_ptr<sightedObject> obj);
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

