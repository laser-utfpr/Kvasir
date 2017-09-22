#ifndef FIELDHOLDER_HPP
#define FIELDHOLDER_HPP

#include "../Vision/visionconstants.h"

#include "obroconstants.h"
#include "field.h"
#include "colorobject.h"
#include "objectlist.hpp"

#include <iostream>
#include <cmath>

class FieldHolder
{
private:
    field sighted_field;
    std::pair<double,double> expected_ball_coord;
    std::pair<double,double> expected_player_coord[N_PLAYERS];
    std::pair<double,double> expected_enemy_coord[N_PLAYERS];
    double distanceSquared(double x1, double y1, double x2, double y2);
    void findEntity(entity* ent, entityType num, ObjectList *objects);
    void setFoundEntity(entity* ent, ObjectList *objects,
                        colorObject *obj, std::pair<double,double> *expected_coord, entityType type);
    colorObject* findBestCandidate(colorObject *candidates, std::pair<double,double> *expected_coord);
    void destroyList(colorObject* list);
    int countColorObjectNodes(colorObject *list);
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
    useconds_t getTimeUs(void);
    void printField(void);
};

#endif // FIELDHOLDER_HPP
