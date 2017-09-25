#include "fieldholder.hpp"

FieldHolder::FieldHolder()
{
    int i;

    sighted_field.time_us = 0;
    sighted_field.image_height = FRAME_HEIGHT;
    sighted_field.image_width = FRAME_WIDTH;

    expected_ball_coord.first = -1.0;
    expected_ball_coord.second = -1.0;
    for(i=0; i<N_PLAYERS; i++)
    {
        expected_player_coord[i].first = -1.0;
        expected_player_coord[i].second = -1.0;

    }
    for(i=0; i<N_PLAYERS; i++)
    {
        expected_enemy_coord[i].first = -1.0;
        expected_enemy_coord[i].second = -1.0;
    }

    sighted_field.ball.type = BALL;
    for(i=0; i<N_PLAYERS; i++)
        sighted_field.robot[i].type = (entityType)((int)ROBOT_1 + i);
    for(i=0; i<N_PLAYERS; i++)
        sighted_field.enemy_robot[i].type = ENEMY_ROBOT;
}

double FieldHolder::distanceSquared(double x1, double y1, double x2, double y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void FieldHolder::findEntities(ObjectList *objects)
{
    int i;
    sighted_field.time_us = objects->getTimeUs();
    findEntity(&(sighted_field.ball),BALL,objects);
    for(i=ROBOT_1; i<ROBOT_1+N_PLAYERS; i++)
        findEntity(&(sighted_field.robot[i-(int)ROBOT_1]),(entityType)i,objects);
    /*for(i=0; i<N_PLAYERS; i++)
        findEntity(&(sighted_field.enemy_robot[i]),ENEMY_ROBOT,objects);*/

}

void FieldHolder::findEntity(entity* ent, entityType num, ObjectList *objects)
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

void FieldHolder::setNotFoundEntity(entity* ent)
{
    ent->x = NAN;
    ent->y = NAN;
    ent->angle = NAN;
    ent->found = false;
}


void FieldHolder::setFoundEntity(entity* ent, ObjectList *objects,
                                 colorObject *obj, std::pair<double,double> *expected_coord, entityType type)
{
    ent->x = obj->x;
    ent->y = obj->y;
    ent->found = true;
    expected_coord->first =  obj->x;
    expected_coord->second =  obj->y;
    objects->setObjectEntityType(obj->x,obj->y,type);
}

colorObject* FieldHolder::findBestCandidate(colorObject *candidates, std::pair<double,double> *expected_coord)
{
    colorObject *best_candidate = candidates;
    double min_distance_squared, current_distance_squared;
    if(candidates!=nullptr)
    {
        if(expected_coord->first>0)
        {
            min_distance_squared = distanceSquared(candidates->x,candidates->y,
                                       expected_coord->first,expected_coord->second);
            candidates = candidates->next;
            while(candidates!=nullptr)
            {
                current_distance_squared = distanceSquared(candidates->x,candidates->y,
                                           expected_coord->first,expected_coord->second);
                if(current_distance_squared < min_distance_squared)
                {
                    min_distance_squared = current_distance_squared;
                    best_candidate = candidates;
                }
                candidates = candidates->next;
            }
        }
    }
    return best_candidate;
}

int FieldHolder::countColorObjectNodes(colorObject *list)
{
    if(list!=nullptr)
        return (1 + countColorObjectNodes(list->next));
    else
        return 0;
}

colorObject* FieldHolder::findMiddleIdentifier(colorObject* identifiers)
{
    double sq_dist1, sq_dist2, sq_dist3;
    sq_dist1 = (identifiers->x-identifiers->next->x)*(identifiers->x-identifiers->next->x)+
            (identifiers->y-identifiers->next->y)*(identifiers->y-identifiers->next->y);
    sq_dist2 = (identifiers->x-identifiers->next->next->x)*(identifiers->x-identifiers->next->next->x)+
            (identifiers->y-identifiers->next->next->y)*(identifiers->y-identifiers->next->next->y);
    sq_dist3 = (identifiers->next->x-identifiers->next->next->x)*(identifiers->next->x-identifiers->next->next->x)+
            (identifiers->next->y-identifiers->next->next->y)*(identifiers->next->y-identifiers->next->next->y);
    if(sq_dist1>sq_dist2 && sq_dist1>sq_dist3)
        return identifiers->next->next;
    if(sq_dist2>sq_dist1 && sq_dist2>sq_dist3)
        return identifiers->next;
    if(sq_dist3>sq_dist1 && sq_dist3>sq_dist2)
        return identifiers;
}

std::pair<double,double> findBisector(double x_mid, double y_mid, double x1, double y1, double x2, double y2)
{
    std::pair<double,double> vec1, vec2;
    vec1.first = x1 - x_mid;
    vec1.second = y1 - y_mid;
    vec2.first = x2 - x_mid;
    vec2.second = y2 - y_mid;

    double norm1, norm2;
    norm1 = sqrt(vec1.first*vec1.first+vec1.second*vec1.second);
    norm2 = sqrt(vec2.first*vec2.first+vec2.second*vec2.second);

    std::pair<double,double> bisec;
    bisec.first = vec1.first/norm1 + vec2.first/norm2;
    bisec.second = vec1.second/norm1 + vec2.second/norm2;

    return bisec;
}

void FieldHolder::destroyList(colorObject* list)
{
    if(list!=nullptr)
    {
        destroyList(list->next);
        delete list;
    }
}

void FieldHolder::findBall(entity* ent, ObjectList *objects)
{
    colorObject *ball_candidates = objects->findObjectsWithColor(BALL_COLOR);
    colorObject *best_candidate = nullptr, *aux = nullptr;

    if(ball_candidates != nullptr)
    {
        best_candidate = findBestCandidate(ball_candidates,&(expected_ball_coord));
        if(best_candidate != nullptr)
        {
            if(best_candidate->area >= MIN_BALL_AREA && best_candidate->area <= MAX_BALL_AREA)
            {
                setFoundEntity(ent,objects,best_candidate,&expected_ball_coord,BALL);
                destroyList(ball_candidates);
                return;
            }
        }

        aux = ball_candidates;
        while(aux != nullptr)
        {
            if(aux->area >= MIN_BALL_AREA && aux->area <= MAX_BALL_AREA)
            {
                setFoundEntity(ent,objects,aux,&expected_ball_coord,BALL);
                destroyList(ball_candidates);
                return;
            }
            aux = aux->next;
        }
    }
    setNotFoundEntity(ent);
    destroyList(ball_candidates);
}

void FieldHolder::findRobot1(entity* ent, ObjectList *objects)
{
    colorObject *candidates = objects->findObjectsWithColor(ALLY_CENTER_COLOR);
    colorObject *best_candidate = nullptr, *aux = nullptr, *identifiers = nullptr;

    if(candidates!=nullptr)
    {
        best_candidate = findBestCandidate(candidates,&(expected_player_coord[0]));
        if(best_candidate != nullptr)
        {
            if(best_candidate->area >= MIN_CENTER_AREA && best_candidate->area <= MAX_CENTER_AREA)
            {
                identifiers = objects->findIdentifiersWithinRange(best_candidate);
                if(identifiers!=nullptr)
                {
                    if(countColorObjectNodes(identifiers) == 1)
                    {
                        if(identifiers->color == IDENTIFIER_COLOR_1)
                        {
                            setFoundEntity(ent,objects,best_candidate,&(expected_player_coord[0]),ROBOT_1);

                            //adjusting to reference listed in obroconstants.h
                            ent->angle = atan2(identifiers->x - best_candidate->x,identifiers->y - best_candidate->y)
                                    + 3.0*M_PI_4;
                            destroyList(candidates);
                            destroyList(identifiers);
                            return;
                        }
                    }
                    destroyList(identifiers);
                    identifiers = nullptr;
                }
            }
        }

        aux = candidates;
        while(aux!=nullptr)
        {
            if(aux->area >= MIN_CENTER_AREA && aux->area <= MAX_CENTER_AREA)
            {
                identifiers = objects->findIdentifiersWithinRange(aux);
                if(identifiers!=nullptr)
                {
                    if(countColorObjectNodes(identifiers) == 1)
                    {
                        if(identifiers->color == IDENTIFIER_COLOR_1)
                        {
                            setFoundEntity(ent,objects,aux,&(expected_player_coord[0]),ROBOT_1);

                            //adjusting to reference listed in obroconstants.h
                            ent->angle = atan2(identifiers->x - aux->x,identifiers->y - aux->y) + 3.0*M_PI_4;
                            destroyList(candidates);
                            destroyList(identifiers);
                            return;
                        }
                    }
                    destroyList(identifiers);
                    identifiers = nullptr;
                }
            }
            aux = aux->next;
        }
    }
    setNotFoundEntity(ent);
    destroyList(candidates);
    destroyList(identifiers);
}

void FieldHolder::findRobot2(entity* ent, ObjectList *objects)
{
    colorObject *candidates = objects->findObjectsWithColor(ALLY_CENTER_COLOR);
    colorObject *best_candidate = nullptr, *aux = nullptr, *identifiers = nullptr;

    if(candidates!=nullptr)
    {
        best_candidate = findBestCandidate(candidates,&(expected_player_coord[0]));
        if(best_candidate != nullptr)
        {
            if(best_candidate->area >= MIN_CENTER_AREA && best_candidate->area <= MAX_CENTER_AREA)
            {
                identifiers = objects->findIdentifiersWithinRange(best_candidate);
                if(identifiers!=nullptr)
                {
                    if(countColorObjectNodes(identifiers) == 2)
                    {
                        if(identifiers->color == IDENTIFIER_COLOR_1
                           && identifiers->next->color == IDENTIFIER_COLOR_1)
                        {
                            setFoundEntity(ent,objects,best_candidate,&(expected_player_coord[1]),ROBOT_2);

                            //adjusting to reference listed in obroconstants.h
                            std::pair<double,double> bisector =
                                    findBisector(best_candidate->x,best_candidate->y,identifiers->x,identifiers->y,
                                                 identifiers->next->x,identifiers->next->y);
                            ent->angle = atan2(bisector.second,bisector.first) + M_PI_2;
                            destroyList(candidates);
                            destroyList(identifiers);
                            return;
                        }
                    }
                    destroyList(identifiers);
                    identifiers = nullptr;
                }
            }
        }

        aux = candidates;
        while(aux!=nullptr)
        {
            if(aux->area >= MIN_CENTER_AREA && aux->area <= MAX_CENTER_AREA)
            {
                identifiers = objects->findIdentifiersWithinRange(aux);
                if(identifiers!=nullptr)
                {
                    if(countColorObjectNodes(identifiers) == 2)
                    {
                        if(identifiers->color == IDENTIFIER_COLOR_1
                           && identifiers->next->color == IDENTIFIER_COLOR_1)
                        {
                            setFoundEntity(ent,objects,aux,&(expected_player_coord[1]),ROBOT_2);

                            //adjusting to reference listed in obroconstants.h
                            std::pair<double,double> bisector =
                                    findBisector(aux->x,aux->y,identifiers->x,identifiers->y,
                                                 identifiers->next->x,identifiers->next->y);
                            ent->angle = atan2(bisector.second,bisector.first) + M_PI_2;
                            destroyList(candidates);
                            destroyList(identifiers);
                            return;
                        }
                    }
                    destroyList(identifiers);
                    identifiers = nullptr;
                }
            }
            aux = aux->next;
        }
    }
    setNotFoundEntity(ent);
    destroyList(candidates);
    destroyList(identifiers);
}

void FieldHolder::findRobot3(entity* ent, ObjectList *objects)
{
    colorObject *candidates = objects->findObjectsWithColor(ALLY_CENTER_COLOR);
    colorObject *best_candidate = nullptr, *aux = nullptr, *identifiers = nullptr;

    if(candidates!=nullptr)
    {
        best_candidate = findBestCandidate(candidates,&(expected_player_coord[0]));
        if(best_candidate != nullptr)
        {
            if(best_candidate->area >= MIN_CENTER_AREA && best_candidate->area <= MAX_CENTER_AREA)
            {
                identifiers = objects->findIdentifiersWithinRange(best_candidate);
                if(identifiers!=nullptr)
                {
                    if(countColorObjectNodes(identifiers) == 3)
                    {
                        if(identifiers->color == IDENTIFIER_COLOR_1
                           && identifiers->next->color == IDENTIFIER_COLOR_1
                           && identifiers->next->next->color == IDENTIFIER_COLOR_1)
                        {
                            setFoundEntity(ent,objects,best_candidate,&(expected_player_coord[1]),ROBOT_3);

                            //adjusting to reference listed in obroconstants.h
                            colorObject* middle = findMiddleIdentifier(identifiers);
                            ent->angle = atan2(middle->y-best_candidate->y,middle->x-best_candidate->x) + 3.0*M_PI_4;
                            destroyList(candidates);
                            destroyList(identifiers);
                            return;
                        }
                    }
                    destroyList(identifiers);
                    identifiers = nullptr;
                }
            }
        }

        aux = candidates;
        while(aux!=nullptr)
        {
            if(aux->area >= MIN_CENTER_AREA && aux->area <= MAX_CENTER_AREA)
            {
                identifiers = objects->findIdentifiersWithinRange(aux);
                if(identifiers!=nullptr)
                {
                    if(countColorObjectNodes(identifiers) == 3)
                    {
                        if(identifiers->color == IDENTIFIER_COLOR_1
                           && identifiers->next->color == IDENTIFIER_COLOR_1
                           && identifiers->next->next->color == IDENTIFIER_COLOR_1)
                        {
                            setFoundEntity(ent,objects,aux,&(expected_player_coord[1]),ROBOT_3);

                            //adjusting to reference listed in obroconstants.h
                            colorObject* middle = findMiddleIdentifier(identifiers);
                            ent->angle = atan2(middle->y-best_candidate->y,middle->x-best_candidate->x) + 3.0*M_PI_4;
                            destroyList(candidates);
                            destroyList(identifiers);
                            return;
                        }
                    }
                    destroyList(identifiers);
                    identifiers = nullptr;
                }
            }
            aux = aux->next;
        }
    }
    setNotFoundEntity(ent);
    destroyList(candidates);
    destroyList(identifiers);
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

useconds_t FieldHolder::getTimeUs(void)
{
    return sighted_field.time_us;
}

void FieldHolder::printField(void)
{
    int i;

    std::cout << std::endl << "TIME_US=" << sighted_field.time_us << std::endl;

    std::cout << std::endl << "BALL:" << std::endl;
    std::cout << "x=" << sighted_field.ball.x << std::endl;
    std::cout << "y=" << sighted_field.ball.y << std::endl;

    for(i=0;i<N_PLAYERS;i++)
    {
        std::cout << std::endl << "ROBOT_" << sighted_field.robot[i].type << ":" << std::endl;
        std::cout << "x=" << sighted_field.robot[i].x << std::endl;
        std::cout << "y=" << sighted_field.robot[i].y << std::endl;
        std::cout << "angle=" << sighted_field.robot[i].angle << std::endl;
    }

    /*for(i=0;i<N_PLAYERS;i++)
    {
        std::cout << std::endl << "ENEMY_ROBOT:" << std::endl;
        std::cout << "x=" << sighted_field.robot[i].x << std::endl;
        std::cout << "y=" << sighted_field.robot[i].y << std::endl;
        std::cout << "angle=" << sighted_field.robot[i].angle << std::endl;
    }*/
}
