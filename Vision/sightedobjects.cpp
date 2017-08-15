#include "sightedobjects.hpp"

#include <iostream>

SightedObjects::SightedObjects()
{
    object = NULL;
    n_objects = 0;
}

SightedObjects::~SightedObjects()
{
    destroyList(object);
}

/**
    void SightedObjects::destroyList(sightedObject* node)

    Recursively destroys the list.

    @author Lucca Rawlyk
    @version 2017.08.15-1
*/

void SightedObjects::destroyList(sightedObject* node)
{
    if(node->next!=NULL)
        destroyList(node->next);
    delete node;
}

/**
    void SightedObjects::addObject(double x, double y, double area, int color)

    Adds an object to the list.

    @author Lucca Rawlyk
    @version 2017.08.15-1
*/

void SightedObjects::addObject(double x, double y, double area, int color)
{
    sightedObject *new_object = new sightedObject;
    new_object->x = x;
    new_object->y = y;
    new_object->area = area;
    new_object->color = color;
    new_object->prev = NULL;
    new_object->next = object;
    if(object!=NULL)
        object->prev = new_object;
}

/**
    void SightedObjects::paintObjects(FramesHolder *frames)

    Paints all the objects of the list

    @author Lucca Rawlyk
    @version 2017.08.15-1
*/

void SightedObjects::paintObjects(FramesHolder *frames)
{
    sightedObject *obj;
    if(object!=NULL)
    {
        obj = object;
        while(obj!=NULL)
        {
            frames->paintObject(obj->x,obj->y,obj->area,obj->color);
            obj = obj->next;
        }
    }
}
