#ifndef OBJECTLIST_HPP
#define OBJECTLIST_HPP

#include "../Vision/visionconstants.h"
#include "../Vision/sightedobject.h"

#include <iostream>
#include <ctime>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/offset_ptr.hpp>

typedef struct co_node
{
    double x;
    double y;
    double area;
    objectColor color;
    struct co_node* next;
    struct co_node* prev;
}colorObject;

class ObjectList
{
private:
    boost::interprocess::managed_shared_memory *shared_memory;
    colorObject *list_head;
    int n_objects;
    useconds_t time_us;
    static ObjectList* instance;
    void destroyList(colorObject *node);
    void printObjects(colorObject *obj);
    ObjectList();
public:
    static ObjectList* getInstance(void);
    void destroyList(void);
    void openSharedMemory(void);
    void updateObjects(void);
    void printObjects(void);
};

#endif // OBJECTLIST_HPP
