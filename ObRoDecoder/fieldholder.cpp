#include "fieldholder.hpp"

FieldHolder::FieldHolder()
{
    sighted_field.image_height = FRAME_HEIGHT;
    sighted_field.image_width = FRAME_WIDTH;
}

void FieldHolder::findEntities(ObjectList *objects)
{
    int i;
    findEntity(&(sighted_field.ball),BALL,objects);
    for(i=ROBOT_1; i<ROBOT_1+N_PLAYERS; i++)
        findEntity(&(sighted_field.robot[i-ROBOT_1]),(entityNum)i,objects);
    for(i=0; i<N_PLAYERS; i++)
        findEntity(&(sighted_field.enemy_robot[i]),ENEMY_ROBOT,objects);
}

void FieldHolder::findEntity(entity* ent, entityNum num, ObjectList *objects)
{
    switch(num)
    {
        case BALL:
            findBall(ent,objects); break;
        case ROBOT_1:
            findRobot1(ent,objects); break;
        case ROBOT_2:
            findRobot2(ent,objects); break;
        case ROBOT_3:
            findRobot3(ent,objects); break;
        case ROBOT_4:
            findRobot4(ent,objects); break;
        case ROBOT_5:
            findRobot5(ent,objects); break;
        case ROBOT_6:
            findRobot6(ent,objects); break;
        case ROBOT_7:
            findRobot7(ent,objects); break;
        case ROBOT_8:
            findRobot8(ent,objects); break;
        case ROBOT_9:
            findRobot9(ent,objects); break;
        case ROBOT_10:
            findRobot10(ent,objects); break;
        case ROBOT_11:
            findRobot11(ent,objects); break;
        case ROBOT_12:
            findRobot12(ent,objects); break;
        case ROBOT_13:
            findRobot13(ent,objects); break;
        case ROBOT_14:
            findRobot14(ent,objects); break;
        case ROBOT_15:
            findRobot15(ent,objects); break;
        case ROBOT_16:
            findRobot16(ent,objects); break;
        case ROBOT_17:
            findRobot17(ent,objects); break;
        case ROBOT_18:
            findRobot18(ent,objects); break;
        case ENEMY_ROBOT:
            findEnemyRobot(ent,objects); break;
    }
}

void FieldHolder::findBall(entity* ent, ObjectList *objects)
{
    colorObject *ball_candidates = objects->findObjectsWithColor(BALL_COLOR);

    delete ball_candidates;
}

void FieldHolder::findRobot1(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot2(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot3(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot4(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot5(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot6(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot7(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot8(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot9(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot10(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot11(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot12(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot13(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot14(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot15(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot16(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot17(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findRobot18(entity* ent, ObjectList *objects)
{

}

void FieldHolder::findEnemyRobot(entity* ent, ObjectList *objects)
{

}
