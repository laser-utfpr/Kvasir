#include "objectlist.hpp"

using namespace boost::interprocess;

ObjectList* ObjectList::instance = nullptr;

/**
    ObjectList::ObjectList()

    The default constructor, initializes stuff and tries to open the shared memory.

    @author Lucca Rawlyk
    @version 2017.09.26-1
*/

ObjectList::ObjectList()
{
    bool opened = false;
    while(!opened)
    {
        try
        {
            shared_memory = new managed_shared_memory(open_only,VISION_SHARED_MEMORY_NAME);
            opened = true;
        }
        catch(interprocess_exception &ex)
        {
            ;
        }
    }
    list_head = nullptr;
    n_objects = 0;
    time_us = 0;
}

ObjectList::~ObjectList()
{
    if(list_head!=nullptr)
        destroyList(list_head);
}

/**
    ObjectList::getInstance(void)

    Returns the singleton's instance.

    @author Lucca Rawlyk
    @version 2017.09.26-1
*/

ObjectList* ObjectList::getInstance(void)
{
    if(instance==nullptr)
        instance = new ObjectList;
    return instance;
}

/**
    ObjectList::distance(double x1, double y1, double x2, double y2)

    Returns the distance between two coordinates.

    @author Lucca Rawlyk
    @version 2017.09.26-1
*/

double ObjectList::distance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

/**
    ObjectList::openSharedMemory(void)

    Tries to open the shared memory.

    @author Lucca Rawlyk
    @version 2017.09.26-1
*/

void ObjectList::openSharedMemory(void)
{
    bool opened = false;
    while(!opened)
    {
        try
        {
            shared_memory = new managed_shared_memory(open_only,VISION_SHARED_MEMORY_NAME);
            opened = true;
        }
        catch(...)
        {
            ;
        }
    }
}

/**
    ObjectList::updateObjects(void)

    Updates the objects from the shared memory.

    @author Lucca Rawlyk
    @version 2017.09.26-1
*/

void ObjectList::updateObjects(void)
{
    bool opened = false;
    std::pair<useconds_t*, managed_shared_memory::size_type> micro_secs;
    while(!opened)
    {
        try
        {
            micro_secs = shared_memory->find<useconds_t>(TIME_US_MEMORY_NAME);
            opened = true;
        }
        catch(...)
        {
            std::cout << std::endl << "trying to open memory again" << n_objects << std::endl;
            openSharedMemory();
        }
    }

    if(time_us != *(micro_secs.first))
    {
        time_us = *(micro_secs.first);

        std::pair<int*, managed_shared_memory::size_type> num_objects;
        opened = false;
        while(!opened)
        {
            try
            {
                num_objects = shared_memory->find<int>(N_OBJECTS_MEMORY_NAME);
                opened = true;
            }
            catch(...)
            {
                std::cout << std::endl << "trying to open memory again" << n_objects << std::endl;
                openSharedMemory();
            }
        }
        n_objects = *(num_objects.first);

        std::pair<offset_ptr<sightedObject>*, managed_shared_memory::size_type> vision_objects;
        offset_ptr<sightedObject> obj;

        opened = false;
        while(!opened)
        {
            try
            {
                vision_objects = shared_memory->find< offset_ptr<sightedObject> >(LIST_HEAD_MEMORY_NAME);
                opened = true;
            }
            catch(...)
            {
                std::cout << std::endl << "trying to open memory again" << n_objects << std::endl;
                openSharedMemory();
            }
        }
        obj = *(vision_objects.first);

        colorObject *new_object = nullptr, *prev_object = nullptr;
        destroyList();

        while(obj.get()!=nullptr)
        {
            new_object = new colorObject;

            new_object->x = obj->x;
            new_object->y = obj->y;
            new_object->area = obj->area;
            new_object->color = obj->color;
            new_object->entity_type = DEFAULT;

            new_object->next = prev_object;
            new_object->prev = nullptr;
            if(prev_object!=nullptr)
                prev_object->prev = new_object;
            prev_object = new_object;

            obj = obj->next;
        }
        list_head = new_object;
    }
}

/**
    ObjectList::destroyList(colorObject *node)

    Recursively destroys the list.

    @author Lucca Rawlyk
    @version 2017.09.26-1
*/

void ObjectList::destroyList(colorObject *node)
{
    if(node!=nullptr)
        destroyList(node->next);
    delete node;
}

void ObjectList::destroyList(void)
{
    destroyList(list_head);
    list_head = nullptr;
}

/**
    ObjectList::printObjects(void)

    Prints the objects.

    @author Lucca Rawlyk
    @version 2017.09.26-1
*/

void ObjectList::printObjects(void)
{

    std::cout << std::endl << "n_objects=" << n_objects << std::endl;
    std::cout << "time_us=" << time_us << std::endl;
    printObjects(list_head);
    std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << std::endl;
}

void ObjectList::printObjects(colorObject *obj)
{
    if(obj!=nullptr)
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

/**
    ObjectList::getTimeUs(void)

    Returns the time of the last sample.

    @author Lucca Rawlyk
    @version 2017.09.26-1
*/

useconds_t ObjectList::getTimeUs(void)
{
    return time_us;
}

/**
    ObjectList::findObjectsWithColor(objectColor color)

    Returns a list of objects with the searched color.

    @author Lucca Rawlyk
    @version 2017.09.26-1
*/

colorObject* ObjectList::findObjectsWithColor(objectColor color)
{
    colorObject *list = list_head, *new_list = nullptr, *prev = nullptr;

    while(list!=nullptr)
    {
        if(list->color == color && list->entity_type == DEFAULT)
        {
            new_list = new colorObject;
            new_list->next = prev;
            new_list->prev = nullptr;
            if(prev!=nullptr)
                prev->prev = new_list;

            new_list->x = list->x;
            new_list->y = list->y;
            new_list->area = list->area;
            new_list->color = list->color;
            new_list->entity_type = list->entity_type;
        }
        prev = new_list;
        list = list->next;
    }
    return new_list;
}

/**
    ObjectList::findIdentifiersWithinRange(colorObject *object)

    Finds all objects with the identifier colors within the range of another object.

    @author Lucca Rawlyk
    @version 2017.09.26-1
*/

colorObject* ObjectList::findIdentifiersWithinRange(colorObject *object)
{
    colorObject *list = list_head, *new_list = nullptr, *prev = nullptr;

    while(list!=nullptr)
    {
        if((list->color == IDENTIFIER_COLOR_1 || list->color == IDENTIFIER_COLOR_2)
            && distance(list->x,list->y,object->x,object->y) < MAX_IDENTIFIER_DISTANCE
            && (object->x != list->x || object->y != list->y) && list->entity_type == DEFAULT)
        {
            new_list = new colorObject;
            new_list->next = prev;
            new_list->prev = nullptr;
            if(prev!=nullptr)
                prev->prev = new_list;

            new_list->x = list->x;
            new_list->y = list->y;
            new_list->area = list->area;
            new_list->color = list->color;
            new_list->entity_type = list->entity_type;
        }
        prev = new_list;
        list = list->next;
    }
    return new_list;
}

/**
    ObjectList::setObjectEntityType(double x, double y, entityType type)

    Sets an object's entityType.

    @author Lucca Rawlyk
    @version 2017.09.26-1
*/

void ObjectList::setObjectEntityType(double x, double y, entityType type)
{
    colorObject* list = list_head;
    while(list!=nullptr)
    {
        if(x==list->x && y==list->y)
        {
            list->entity_type = type;
            break;
        }
        list = list->next;
    }
}
