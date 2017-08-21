#include "sightedobjects.hpp"

SightedObjects::SightedObjects()
{
    list = NULL;
    n_objects = 0;
    micros = 0;
}

SightedObjects::~SightedObjects()
{
    if(list!=NULL)
        destroyList(list);
}

/**
    void SightedObjects::destroyList(sightedObject* node)

    Recursively destroys the list.

    @author Lucca Rawlyk
    @version 2017.08.16-1
*/

void SightedObjects::destroyList(sightedObject* node)
{
    if(node->next!=NULL)
        destroyList(node->next);
    delete node;
}

void SightedObjects::destroyList(void)
{
    if(list!=NULL)
        destroyList(list);
    list = NULL;
    n_objects = 0;
}

/**
    void SightedObjects::addObject(double x, double y, double area, int color)

    Adds an object to the list.

    @author Lucca Rawlyk
    @version 2017.08.16-1
*/

void SightedObjects::addObject(double x, double y, double area, objectColor color)
{
    sightedObject *new_object = new sightedObject;
    new_object->x = x;
    new_object->y = y;
    new_object->area = area;
    new_object->color = color;
    new_object->prev = NULL;
    new_object->next = list;
    if(list!=NULL)
        list->prev = new_object;
    list = new_object;
    n_objects++;
}

/**
    void SightedObjects::paintObjects(FramesHolder *frames)

    Paints all the objects of the list.

    @author Lucca Rawlyk
    @version 2017.08.17-1
*/

void SightedObjects::paintObjects(FramesHolder *frames)
{
    sightedObject *obj;
    if(list!=NULL)
    {
        obj = list;
        while(obj!=NULL)
        {
            frames->paintObject((int)obj->x,(int)obj->y,(int)obj->area,obj->color);
            obj = obj->next;
        }
    }
}

/**
    void printObjects(void)

    Recursively prints the parameters of all the objects in the list.

    @author Lucca Rawlyk
    @version 2017.08.17-1
*/

void SightedObjects::printObjects(void)
{
    if(list!=NULL)
        printObjects(list);
    else
        std::cout << std::endl << "No objects found" << std::endl;
}

void SightedObjects::printObjects(sightedObject *obj)
{
    if(obj!=NULL)
    {
        std::cout << std::endl;
        std::cout << "x=" << obj->x << std::endl;
        std::cout << "y=" << obj->y << std::endl;
        std::cout << "area=" << obj->area << std::endl;
        std::cout << "color=";
        switch(obj->color)
        {
            case RED:
                std::cout << "RED"; break;
            case ORANGE:
                std::cout << "ORANGE"; break;
            case YELLOW:
                std::cout << "YELLOW"; break;
            case GREEN:
                std::cout << "GREEN"; break;
            case BLUE:
                std::cout << "BLUE"; break;
            case VIOLET:
                std::cout << "VIOLET"; break;
            default:
                std::cout << "ERROR"; break;
        }
        std::cout << std::endl;
        printObjects(obj->next);
    }
}

void SightedObjects::incrementTime(void)
{
    micros += SAMPLING_PERIOD;
}
