#include "sightedobjects.hpp"

using namespace boost::interprocess;

SightedObjects* SightedObjects::instance = NULL;

SightedObjects* SightedObjects::getInstance(void)
{
    if(instance==NULL)
        instance = new SightedObjects;
    return instance;
}


SightedObjects::SightedObjects()
{
    shared_memory_object::remove(SHARED_MEMORY_NAME);
    shared_memory = new managed_shared_memory(open_or_create,SHARED_MEMORY_NAME,SHARED_MEMORY_SIZE);
    list = NULL;
    n_objects = static_cast<int*>(shared_memory->allocate(sizeof(int)));
    *n_objects = 0;
    micros = static_cast<useconds_t*>(shared_memory->allocate(sizeof(useconds_t)));
    *micros = 0;
}

SightedObjects::~SightedObjects()
{
    if(list.get()!=NULL)
        destroyList(list);
}

/**
    void SightedObjects::destroyList(offset_ptr<sightedObject*> node)

    Recursively destroys the list.

    @author Lucca Rawlyk
    @version 2017.08.25-1
*/

void SightedObjects::destroyList(boost::interprocess::offset_ptr<sightedObject> node)
{
    if((node->next).get()!=NULL)
        destroyList(node->next);
    //delete node;
    //std::cout << "node deleted" << std::endl;
    shared_memory->deallocate(node.get());
}

void SightedObjects::destroyList(void)
{
    //std::cout << "starting deletion" << std::endl;
    if(list!=NULL)
        destroyList(list);
    list = NULL;
    *n_objects = 0;
}

/**
    void SightedObjects::addObject(double x, double y, double area, int color)

    Adds an object to the list.

    @author Lucca Rawlyk
    @version 2017.08.22-1
*/

void SightedObjects::addObject(double x, double y, double area, objectColor color)
{
    //sightedObject *new_object = new sightedObject;
    offset_ptr<sightedObject> new_object = static_cast<sightedObject*>(shared_memory->allocate(sizeof(sightedObject)));
    new_object->x = x;
    new_object->y = y;
    new_object->area = area;
    new_object->color = color;
    new_object->prev = NULL;
    new_object->next = list;
    if(list!=NULL)
        list->prev = new_object;
    list = new_object;
    *n_objects++;
}

/**
    void SightedObjects::paintObjects(FramesHolder *frames)

    Paints all the objects of the list.

    @author Lucca Rawlyk
    @version 2017.08.25-1
*/

void SightedObjects::paintObjects(FramesHolder *frames)
{
    offset_ptr<sightedObject> obj;
    if(list.get()!=NULL)
    {
        obj = list;
        while(obj.get()!=NULL)
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
    @version 2017.08.25-1
*/

void SightedObjects::printObjects(void)
{
    if(list.get()!=NULL)
        printObjects(list);
    else
        std::cout << std::endl << "No objects found" << std::endl;
}

void SightedObjects::printObjects(boost::interprocess::offset_ptr<sightedObject> obj)
{
    if(obj.get()!=NULL)
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
    *micros += SAMPLING_PERIOD;
}
