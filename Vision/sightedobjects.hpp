#ifndef SIGHTEDOBJECTS_HPP
#define SIGHTEDOBJECTS_HPP

#include "framesholder.hpp"
class FramesHolder;

#include <ctime>
#include <iostream>

#include "sightedobject.h"

#include "visionconstants.h"

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/offset_ptr.hpp>

class SightedObjects
{
private:
    boost::interprocess::offset_ptr<sightedObject> list;
    boost::interprocess::offset_ptr<sightedObject> *list_head;
    int *n_objects;
    useconds_t *time_us;
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
    void incrementTime(useconds_t time_increment);
    void saveListHead(void);
    void sharedMemoryTest(void);
};

#endif // SIGHTEDOBJECTS_HPP

