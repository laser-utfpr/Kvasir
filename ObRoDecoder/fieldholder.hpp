#ifndef FIELDHOLDER_HPP
#define FIELDHOLDER_HPP

#include "../Vision/visionconstants.h"

#include "obroconstants.h"
#include "field.h"
#include "colorobject.h"
#include "objectlist.hpp"

#include <iostream>

class FieldHolder
{
private:
    field sighted_field;
    void findEntity(entity* ent, entityNum num, ObjectList *objects);
    void findBall(entity* ent, ObjectList *objects);
    void findRobot1(entity* ent, ObjectList *objects);
    void findRobot2(entity* ent, ObjectList *objects);
    void findRobot3(entity* ent, ObjectList *objects);
    void findRobot4(entity* ent, ObjectList *objects);
    void findRobot5(entity* ent, ObjectList *objects);
    void findRobot6(entity* ent, ObjectList *objects);
    void findRobot7(entity* ent, ObjectList *objects);
    void findRobot8(entity* ent, ObjectList *objects);
    void findRobot9(entity* ent, ObjectList *objects);
    void findRobot10(entity* ent, ObjectList *objects);
    void findRobot11(entity* ent, ObjectList *objects);
    void findRobot12(entity* ent, ObjectList *objects);
    void findRobot13(entity* ent, ObjectList *objects);
    void findRobot14(entity* ent, ObjectList *objects);
    void findRobot15(entity* ent, ObjectList *objects);
    void findRobot16(entity* ent, ObjectList *objects);
    void findRobot17(entity* ent, ObjectList *objects);
    void findRobot18(entity* ent, ObjectList *objects);
    void findEnemyRobot(entity* ent, ObjectList *objects);
public:
    FieldHolder();
    void findEntities(ObjectList *objects);
};

#endif // FIELDHOLDER_HPP
