#include "obro.hpp"
//#include "../include/obro.hpp"

void obroStart(bool printObjects, bool printField)
{
    ObjectList *objects = ObjectList::getInstance();
    FieldHolder *field = FieldHolder::getInstance();
    while(1)
    {
        objects->updateObjects();
        if(printObjects)
            objects->printObjects();
        if(objects->getTimeUs() != field->getTimeUs())
        {
            field->findEntities(objects);
            //field->updateSharedMemory();
            if(printField)
                field->printField();
        }
    }
}
