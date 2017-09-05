#include "objectlist.hpp"

using namespace boost::interprocess;

ObjectList* ObjectList::instance = NULL;

ObjectList::ObjectList()
{
    bool opened = false;
    while(!opened)
    {
        try
        {
            shared_memory = new managed_shared_memory(open_only,SHARED_MEMORY_NAME);
            opened = true;
        }
        catch(interprocess_exception &ex)
        {
            ;
        }
    }
    list_head = NULL;
    n_objects = 0;
    time_us = 0;
}

ObjectList* ObjectList::getInstance(void)
{
    if(instance==NULL)
        instance = new ObjectList;
    return instance;
}

void ObjectList::openSharedMemory(void)
{
    shared_memory = new managed_shared_memory(open_only,SHARED_MEMORY_NAME);
}

void ObjectList::updateObjects(void)
{
    if(shared_memory->check_sanity())
    {
        std::pair<int*, managed_shared_memory::size_type> num_objects;
        bool opened = false;
        while(!opened)
        {
            try
            {
                num_objects = shared_memory->find<int>(N_OBJECTS_MEMORY_NAME);
                opened = true;
            }
            catch(interprocess_exception &ex)
            {
                ;
            }
        }
        n_objects = *(num_objects.first);

        std::pair<useconds_t*, managed_shared_memory::size_type> micro_secs;
        opened = false;
        while(!opened)
        {
            try
            {
                micro_secs = shared_memory->find<useconds_t>(TIME_US_MEMORY_NAME);
                opened = true;
            }
            catch(interprocess_exception &ex)
            {
                ;
            }
        }
        time_us = *(micro_secs.first);


        std::pair<offset_ptr<sightedObject>*, managed_shared_memory::size_type> vision_objects;
        offset_ptr<sightedObject> *obj;

        opened = false;
        while(!opened)
        {
            try
            {
                vision_objects = shared_memory->find< offset_ptr<sightedObject> >(LIST_HEAD_MEMORY_NAME);
                opened = true;
            }
            catch(interprocess_exception &ex)
            {
                ;
            }
        }
        obj = vision_objects.first;

        colorObject *new_object, *prev_object = NULL;
        destroyList();

        while((*obj).get()!=NULL)
        {
            new_object = new colorObject;
            new_object->x = (*obj)->x;
            new_object->y = (*obj)->y;
            new_object->area = (*obj)->area;
            new_object->color = (*obj)->color;
            new_object->next = prev_object;
            new_object->prev = NULL;
            if(prev_object!=NULL)
                prev_object->prev = new_object;
            prev_object = new_object;
            (*obj) = (*obj)->next;
        }
        list_head = new_object;
    }
    else
    {
        n_objects = 0;
        destroyList();
    }
}

void ObjectList::destroyList(colorObject *node)
{
    if(node!=NULL)
        destroyList(node->next);
    delete node;
}

void ObjectList::destroyList(void)
{
    destroyList(list_head);
    list_head = NULL;
}

void ObjectList::printObjects(void)
{
    std::cout << std::endl << "n_objects=" << n_objects << std::endl;
    std::cout << "time_us=" << time_us << std::endl;
    printObjects(list_head);
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
}

void ObjectList::printObjects(colorObject *obj)
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
