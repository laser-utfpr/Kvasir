#include "obro.hpp"
//#include "../include/obro.hpp"

void obroStart(bool printObjects, bool printField)
{
    ObjectList *objects = ObjectList::getInstance();
    FieldHolder *field = FieldHolder::getInstance();
    char quit = 0;
    while(quit != 'q')
    {
        objects->updateObjects();
        if(printObjects)
            objects->printObjects();
        if(objects->getTimeUs() != field->getTimeUs())
        {
            field->findEntities(objects);
            field->updateSharedMemory();
            if(printField)
                field->printField();
        }
        if(_kbhit())
            quit = std::cin.get();
    }
}
