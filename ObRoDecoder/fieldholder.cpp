#include "fieldholder.hpp"

FieldHolder::FieldHolder()
{
    sighted_field.image_height = FRAME_HEIGHT;
    sighted_field.image_width = FRAME_WIDTH;
    expected_ball_coord.first = -1.0;
    expected_ball_coord.second = -1.0;
}

double FieldHolder::distanceSquared(double x1, double y1, double x2, double y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
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
    colorObject *ball_candidates = objects->findObjectsWithColor(BALL_COLOR), *aux, *best_cadidate = nullptr;

    aux = ball_candidates;
    double min_distance_squared, current_distance_squared;
    if(expected_ball_coord.first>0)
    {
        if(aux!=nullptr)
            min_distance_squared = distanceSquared(aux->x,aux->y,
                                   expected_ball_coord.first,expected_ball_coord.second);
        aux = aux->next;
        while(aux!=nullptr)
        {
            current_distance_squared = distanceSquared(aux->x,aux->y,
                                       expected_ball_coord.first,expected_ball_coord.second);
            if(current_distance_squared < min_distance_squared)
            {
                min_distance_squared = current_distance_squared;
                best_cadidate = aux;
            }
        }
    }

    if(best_cadidate->area >= MIN_BALL_AREA && best_cadidate->area <= MAX_BALL_AREA)
    {
        sighted_field.ball.x = best_cadidate->x;
        sighted_field.ball.y = best_cadidate->y;
        sighted_field.ball.found = true;
        expected_ball_coord.first =  sighted_field.ball.x;
        expected_ball_coord.second =  sighted_field.ball.y;
        objects->setObjectEntityType(sighted_field.ball.x,sighted_field.ball.y,BALL);
        delete ball_candidates;
        return;
    }
    else
    {
        aux = ball_candidates;
        while(aux!=nullptr)
        {
            if(aux->area >= MIN_BALL_AREA && aux->area <= MAX_BALL_AREA)
            {
                sighted_field.ball.x = aux->x;
                sighted_field.ball.y = aux->y;
                sighted_field.ball.found = true;
                expected_ball_coord.first =  sighted_field.ball.x;
                expected_ball_coord.second =  sighted_field.ball.y;
                objects->setObjectEntityType(sighted_field.ball.x,sighted_field.ball.y,BALL);
                delete ball_candidates;
                return;
            }
            aux = aux->next;
        }
    }

    sighted_field.ball.x = -1.0;
    sighted_field.ball.y = -1.0;
    sighted_field.ball.found = false;
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
