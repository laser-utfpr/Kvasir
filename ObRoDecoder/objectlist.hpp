#ifndef OBJECTLIST_HPP
#define OBJECTLIST_HPP

#include "../Vision/visionconstants.h"
#include "../Vision/sightedobject.h"

#include "colorobject.h"
#include "obroconstants.h"

#include <iostream>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/offset_ptr.hpp>

class ObjectList
{
private:
    boost::interprocess::managed_shared_memory *shared_memory;
    colorObject *list_head;
    int n_objects;
    useconds_t time_us;
    static ObjectList* instance;
    double distance(double x1, double y1, double x2, double y2);
    void destroyList(colorObject *node);
    void printObjects(colorObject *obj);
    ObjectList();
public:
    static ObjectList* getInstance(void);
    void destroyList(void);
    void openSharedMemory(void);
    void updateObjects(void);
    void printObjects(void);
    useconds_t getTimeUs(void);
    colorObject* findObjectsWithColor(objectColor color);
    colorObject* findIdentifiersWithinRange(colorObject *object);
    void setObjectEntityType(double x, double y, entityType type);
};

#endif // OBJECTLIST_HPP
