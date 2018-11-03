#include "robotrecognizer.hpp"

Coord RobotRecognizer::compared_object_coord;

RobotRecognizer::RobotRecognizer(VisionFieldHandler &vfh, ImageProcessingSettings &ips) :
vision_field_handler(vfh), image_processing_settings(ips)
{
    for(int i=0; i<N_ROBOTS; i++)
        ally_found[i] = false;
}

RobotRecognizer::~RobotRecognizer()
{

}

void RobotRecognizer::recognizeRobots(std::vector<ColoredObject> object)
{

    findBall(object);

    for(int i=0; i<N_ROBOTS; i++)
    {
        switch(i)
        {
            case 0:
                findRobot1(object);
                break;
            case 1:
                findRobot2(object);
                break;
            case 2:
                findRobot3(object);
                break;
            case 3:
                findRobot4(object);
                break;
            case 4:
                findRobot5(object);
                break;
            case 5:
                findRobot6(object);
                break;
        }
    }

    findEnemies(object);
}

bool RobotRecognizer::compareColoredObjectDistance(ColoredObject c1, ColoredObject c2)
{
    return (RobotRecognizer::compared_object_coord.distance(c1.coord) <
            RobotRecognizer::compared_object_coord.distance(c2.coord));
}

void RobotRecognizer::findBall(std::vector<ColoredObject> object)
{
    if(ball_found)
    {
        compared_object_coord = last_ball_coord;
        std::sort(object.begin(), object.end(), &RobotRecognizer::compareColoredObjectDistance);
    }
    ball_found = false;
    Color ball_color = vision_field_handler.getBallColor();
    Entity ball;
    for(auto i=object.begin(); i != object.end() && !ball_found; ++i)
        if(i->color == ball_color)
        {
            ball_found = true;
            last_ball_coord = i->coord;
            ball.coord = i->coord;
            ball.already_found = true;
            ball.found_last_frame = true;
        }
    if(ball_found)
        vision_field_handler.setBall(ball);
    else
        vision_field_handler.setBallAsNotFound();
}

void RobotRecognizer::findRobot1(std::vector<ColoredObject> object)
{
    if(ally_found[0])
    {
        compared_object_coord = last_ally_coord[0];
        std::sort(object.begin(), object.end(), &RobotRecognizer::compareColoredObjectDistance);
    }
    ally_found[0] = false;
    Color ally_center_color = vision_field_handler.getAllyCenterColor();
    Color tag_color = vision_field_handler.getTagColor(0);
    Entity robot1;
    for(auto i=object.begin(); i != object.end() && !ally_found[0]; ++i)
        if(i->color == ally_center_color)
        {
            int tags_nearby = 0;
            ColoredObject tag;
            for(auto j=object.begin(); j != object.end(); ++j)
                if(j->color == tag_color && i->coord.distance(j->coord) < image_processing_settings.getMaximumTagDistance())
                {
                    tags_nearby++;
                    tag = *j;
                }
            if(tags_nearby == 1)
            {
                ally_found[0] = true;
                last_ally_coord[0] = i->coord;
                robot1.coord = i->coord;
                robot1.angle = robot1.coord.angle(tag.coord) + 3*M_PI_4;
                robot1.already_found = true;
                robot1.found_last_frame = true;
            }
        }
    if(ally_found[0])
    {
        vision_field_handler.setAlly(robot1, 0);
    }
    else
        vision_field_handler.setAllyAsNotFound(0);
}

void RobotRecognizer::findRobot2(std::vector<ColoredObject> object)
{
    if(ally_found[1])
    {
        compared_object_coord = last_ally_coord[1];
        std::sort(object.begin(), object.end(), &RobotRecognizer::compareColoredObjectDistance);
    }
    ally_found[1] = false;
    Color ally_center_color = vision_field_handler.getAllyCenterColor();
    Color tag_color = vision_field_handler.getTagColor(0);
    Entity robot2;
    for(auto i=object.begin(); i != object.end() && !ally_found[1]; ++i)
        if(i->color == ally_center_color)
        {

            int tags_nearby = 0;
            ColoredObject tag1, tag2;
            bool tag1_found = false;
            for(auto j=object.begin(); j != object.end(); ++j)
                if(j->color == tag_color && i->coord.distance(j->coord) < image_processing_settings.getMaximumTagDistance())
                {
                    tags_nearby++;
                    if(!tag1_found)
                    {
                        tag1 = *j;
                        tag1_found = true;
                    }
                    else
                        tag2 = *j;
                }
            if(tags_nearby == 2)
            {
                ally_found[1] = true;
                last_ally_coord[1] = i->coord;
                robot2.coord = i->coord;
                Coord bisector = robot2.coord.bisector(tag1.coord, tag2.coord);
                robot2.angle = bisector.angle() + M_PI_2;
                robot2.already_found = true;
                robot2.found_last_frame = true;
            }
        }
    if(ally_found[1])
    {
        vision_field_handler.setAlly(robot2, 1);
    }
    else
        vision_field_handler.setAllyAsNotFound(1);
}

void RobotRecognizer::findRobot3(std::vector<ColoredObject> object)
{
    if(ally_found[2])
    {
        compared_object_coord = last_ally_coord[2];
        std::sort(object.begin(), object.end(), &RobotRecognizer::compareColoredObjectDistance);
    }
    ally_found[2] = false;
    Color ally_center_color = vision_field_handler.getAllyCenterColor();
    Color tag_color = vision_field_handler.getTagColor(0);
    Entity robot3;
    for(auto i=object.begin(); i != object.end() && !ally_found[2]; ++i)
        if(i->color == ally_center_color)
        {
            int tags_nearby = 0;
            ColoredObject tag1, tag2, tag3;
            bool tag1_found = false, tag2_found = false;
            for(auto j=object.begin(); j != object.end(); ++j)
                if(j->color == tag_color && i->coord.distance(j->coord) < image_processing_settings.getMaximumTagDistance())
                {
                    tags_nearby++;
                    if(!tag1_found)
                    {
                        tag1 = *j;
                        tag1_found = true;
                    }
                    else if(!tag2_found)
                    {
                        tag2 = *j;
                        tag2_found = true;
                    }
                    else
                        tag3 = *j;
                }
            if(tags_nearby == 3)
            {
                ally_found[2] = true;
                last_ally_coord[2] = i->coord;
                robot3.coord = i->coord;
                if(tag2.coord.distance(tag3.coord) > tag1.coord.distance(tag3.coord) &&
                   tag2.coord.distance(tag3.coord) > tag1.coord.distance(tag2.coord))
                    robot3.angle = robot3.angle = robot3.coord.angle(tag1.coord) + M_PI_4;
                else if(tag3.coord.distance(tag1.coord) > tag2.coord.distance(tag3.coord) &&
                        tag3.coord.distance(tag1.coord) > tag2.coord.distance(tag1.coord))
                    robot3.angle = robot3.angle = robot3.coord.angle(tag2.coord) + M_PI_4;
                else
                    robot3.angle = robot3.angle = robot3.coord.angle(tag3.coord) + M_PI_4;
                robot3.already_found = true;
                robot3.found_last_frame = true;
            }
        }
    if(ally_found[2])
    {
        vision_field_handler.setAlly(robot3, 2);
    }
    else
        vision_field_handler.setAllyAsNotFound(2);
}

void RobotRecognizer::findRobot4(std::vector<ColoredObject> object)
{
    if(ally_found[3])
    {
        compared_object_coord = last_ally_coord[3];
        std::sort(object.begin(), object.end(), &RobotRecognizer::compareColoredObjectDistance);
    }
    ally_found[3] = false;
    Color ally_center_color = vision_field_handler.getAllyCenterColor();
    Color tag_color = vision_field_handler.getTagColor(1);
    Entity robot4;
    for(auto i=object.begin(); i != object.end() && !ally_found[3]; ++i)
        if(i->color == ally_center_color)
        {
            int tags_nearby = 0;
            ColoredObject tag;
            for(auto j=object.begin(); j != object.end(); ++j)
                if(j->color == tag_color && i->coord.distance(j->coord) < image_processing_settings.getMaximumTagDistance())
                {
                    tags_nearby++;
                    tag = *j;
                }
            if(tags_nearby == 1)
            {
                ally_found[3] = true;
                last_ally_coord[3] = i->coord;
                robot4.coord = i->coord;
                robot4.angle = robot4.coord.angle(tag.coord) + 3*M_PI_4;
                robot4.already_found = true;
                robot4.found_last_frame = true;
            }
        }
    if(ally_found[3])
    {
        vision_field_handler.setAlly(robot4, 3);
    }
    else
        vision_field_handler.setAllyAsNotFound(3);
}

void RobotRecognizer::findRobot5(std::vector<ColoredObject> object)
{
    if(ally_found[4])
    {
        compared_object_coord = last_ally_coord[4];
        std::sort(object.begin(), object.end(), &RobotRecognizer::compareColoredObjectDistance);
    }
    ally_found[4] = false;
    Color ally_center_color = vision_field_handler.getAllyCenterColor();
    Color tag_color = vision_field_handler.getTagColor(1);
    Entity robot5;
    for(auto i=object.begin(); i != object.end() && !ally_found[4]; ++i)
        if(i->color == ally_center_color)
        {

            int tags_nearby = 0;
            ColoredObject tag1, tag2;
            bool tag1_found = false;
            for(auto j=object.begin(); j != object.end(); ++j)
                if(j->color == tag_color && i->coord.distance(j->coord) < image_processing_settings.getMaximumTagDistance())
                {
                    tags_nearby++;
                    if(!tag1_found)
                    {
                        tag1 = *j;
                        tag1_found = true;
                    }
                    else
                        tag2 = *j;
                }
            if(tags_nearby == 2)
            {
                ally_found[4] = true;
                last_ally_coord[4] = i->coord;
                robot5.coord = i->coord;
                Coord bisector = robot5.coord.bisector(tag1.coord, tag2.coord);
                robot5.angle = bisector.angle() + M_PI_2;
                robot5.already_found = true;
                robot5.found_last_frame = true;
            }
        }
    if(ally_found[4])
    {
        vision_field_handler.setAlly(robot5, 4);
    }
    else
        vision_field_handler.setAllyAsNotFound(4);
}

void RobotRecognizer::findRobot6(std::vector<ColoredObject> object)
{
    if(ally_found[5])
    {
        compared_object_coord = last_ally_coord[5];
        std::sort(object.begin(), object.end(), &RobotRecognizer::compareColoredObjectDistance);
    }
    ally_found[5] = false;
    Color ally_center_color = vision_field_handler.getAllyCenterColor();
    Color tag_color = vision_field_handler.getTagColor(1);
    Entity robot6;
    for(auto i=object.begin(); i != object.end() && !ally_found[5]; ++i)
        if(i->color == ally_center_color)
        {
            int tags_nearby = 0;
            ColoredObject tag1, tag2, tag3;
            bool tag1_found = false, tag2_found = false;
            for(auto j=object.begin(); j != object.end(); ++j)
                if(j->color == tag_color && i->coord.distance(j->coord) < image_processing_settings.getMaximumTagDistance())
                {
                    tags_nearby++;
                    if(!tag1_found)
                    {
                        tag1 = *j;
                        tag1_found = true;
                    }
                    else if(!tag2_found)
                    {
                        tag2 = *j;
                        tag2_found = true;
                    }
                    else
                        tag3 = *j;
                }
            if(tags_nearby == 3)
            {
                ally_found[5] = true;
                last_ally_coord[5] = i->coord;
                robot6.coord = i->coord;
                if(tag2.coord.distance(tag3.coord) > tag1.coord.distance(tag3.coord) &&
                   tag2.coord.distance(tag3.coord) > tag1.coord.distance(tag2.coord))
                    robot6.angle = robot6.angle = robot6.coord.angle(tag1.coord) + M_PI_4;
                else if(tag3.coord.distance(tag1.coord) > tag2.coord.distance(tag3.coord) &&
                        tag3.coord.distance(tag1.coord) > tag2.coord.distance(tag1.coord))
                    robot6.angle = robot6.angle = robot6.coord.angle(tag2.coord) + M_PI_4;
                else
                    robot6.angle = robot6.angle = robot6.coord.angle(tag3.coord) + M_PI_4;
                robot6.already_found = true;
                robot6.found_last_frame = true;
            }
        }
    if(ally_found[5])
    {
        vision_field_handler.setAlly(robot6, 5);
    }
    else
        vision_field_handler.setAllyAsNotFound(5);
}

void RobotRecognizer::findEnemies(std::vector<ColoredObject> object)
{
    std::vector<ColoredObject> enemy;
    Color enemy_center_color = vision_field_handler.getEnemyCenterColor();
    for(auto i=object.begin(); i != object.end(); ++i)
        if(i->color == enemy_center_color)
            enemy.push_back(*i);
    for(int i=0; i < N_ROBOTS; i++)
    {
        if(i < enemy.size())
        {
            Entity enemy_entity;
            enemy_entity.coord = enemy[i].coord;
            enemy_entity.already_found = true;
            enemy_entity.found_last_frame = true;
            vision_field_handler.setEnemy(enemy_entity, i);
        }
        else
            vision_field_handler.setEnemyAsNotFound(i);
    }
}

#include "moc_robotrecognizer.cpp"
