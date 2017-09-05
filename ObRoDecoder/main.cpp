#include "objectlist.hpp"

int main()
{
    ObjectList *objects = ObjectList::getInstance();
    while(1)
    {
        objects->updateObjects();
        objects->printObjects();
        usleep(700000);
    }
    return 0;
}

