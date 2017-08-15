#include "sightedobjects.hpp"

#include <iostream>

SightedObjects* SightedObjects::instance = NULL;

SightedObjects::SightedObjects(){}

SightedObjects* SightedObjects::getInstance(void)
{
    if (instance == NULL)
    {
        instance = new SightedObjects();
    }

    return instance;
}
