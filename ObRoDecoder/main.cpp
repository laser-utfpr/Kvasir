#include "objectlist.hpp"

int main()
{
    ObjectList *objects = ObjectList::getInstance();
    while(1)
    {
        objects->updateObjects();
        objects->printObjects();
    }
    return 0;
}

