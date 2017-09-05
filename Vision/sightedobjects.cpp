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
    shared_memory = new managed_shared_memory(create_only,SHARED_MEMORY_NAME,SHARED_MEMORY_SIZE);

    n_objects = shared_memory->construct<int>(N_OBJECTS_MEMORY_NAME)();
    *n_objects = 0;
    time_us = shared_memory->construct<useconds_t>(TIME_US_MEMORY_NAME)();
    *time_us = 0;

    list_head = shared_memory->construct< offset_ptr<sightedObject> >(LIST_HEAD_MEMORY_NAME)();

    list = NULL;
}

SightedObjects::~SightedObjects()
{
    if(list.get()!=NULL)
        destroyList(list);
    shared_memory_object::remove(SHARED_MEMORY_NAME);
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
    shared_memory->deallocate(node.get());
}

void SightedObjects::destroyList(void)
{
    if(list!=NULL)
        destroyList(list);
    list = NULL;
    *n_objects = 0;
}

/**
    void SightedObjects::addObject(double x, double y, double area, int color)

    Adds an object to the list.

    @author Lucca Rawlyk
    @version 2017.08.28-1
*/

void SightedObjects::addObject(double x, double y, double area, objectColor color)
{
    offset_ptr<sightedObject> new_object = 
            static_cast<sightedObject*>(shared_memory->allocate(sizeof(sightedObject)));
    new_object->x = x;
    new_object->y = y;
    new_object->area = area;
    new_object->color = color;
    new_object->prev = NULL;
    new_object->next = list;
    if(list!=NULL)
        list->prev = new_object;
    list = new_object;
    (*n_objects)++;
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
    void SightedObjects::printObjects(void)

    Recursively prints the parameters of all the objects in the list.

    @author Lucca Rawlyk
    @version 2017.08.29-1
*/

void SightedObjects::printObjects(void)
{
    std::cout << std::endl << "n_objects=" << *n_objects << std::endl;
    std::cout << "time_us=" << *time_us << std::endl;
    printObjects(list);
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
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

void SightedObjects::incrementTime(useconds_t time_increment)
{
    *time_us += time_increment;
}

/**
    void SightedObjects::saveListHead(void)

    Saves list head as a named shared memory object to allow other processes to find it.

    @author Lucca Rawlyk
    @version 2017.08.29-1
*/

void SightedObjects::saveListHead(void)
{
    *list_head = list;
}

/**
    void SightedObjects::shareMemoryTest(void)

    Accesses the shared memory.

    @author Lucca Rawlyk
    @version 2017.08.29-1
*/

void SightedObjects::sharedMemoryTest(void)
{
    std::pair<int*, managed_shared_memory::size_type> num_objects;
    num_objects = shared_memory->find<int>(N_OBJECTS_MEMORY_NAME);
    std::cout << std::endl << "n_objects=" << *(num_objects.first) << std::endl;
    std::pair<useconds_t*, managed_shared_memory::size_type> micro_secs;
    micro_secs = shared_memory->find<useconds_t>(TIME_US_MEMORY_NAME);
    std::cout << "time_us=" << *(micro_secs.first) << std::endl;

    std::pair<offset_ptr<sightedObject>*, managed_shared_memory::size_type> objects;
    objects = shared_memory->find< offset_ptr<sightedObject> >(LIST_HEAD_MEMORY_NAME);
    printObjects(*(objects.first));
}
