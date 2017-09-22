#include "objectlist.hpp"
#include "fieldholder.hpp"

int main()
{
    ObjectList *objects = ObjectList::getInstance();
    FieldHolder field;
    while(1)
    {
        objects->updateObjects();
        //objects->printObjects();
        if(objects->getTimeUs() != field.getTimeUs())
        {
            field.findEntities(objects);
            field.printField();
        }
    }
    return 0;
}

