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
            case 1:
                findRobot1(object);
                break;
            case 2:
                findRobot2(object);
                break;
            case 3:
                findRobot3(object);
                break;
            case 4:
                findRobot4(object);
                break;
            case 5:
                findRobot5(object);
                break;
            case 6:
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
            //std::cout << tags_nearby << std::endl;
            if(tags_nearby == 1)
            {
                ally_found[0] = true;
                last_ally_coord[0] = i->coord;
                robot1.coord = i->coord;
                Coord center_tag_vector = tag.coord - robot1.coord;
                robot1.angle = atan2(center_tag_vector.y, center_tag_vector.x) + 3*M_PI_4;
                robot1.already_found = true;
                robot1.found_last_frame = true;
            }
        }
    if(ally_found[0])
    {
        vision_field_handler.setAlly(robot1, 0);
        std::cout << robot1.angle << std::endl;
    }
    else
        vision_field_handler.setAllyAsNotFound(0);
}

void RobotRecognizer::findRobot2(std::vector<ColoredObject> object)
{

}

void RobotRecognizer::findRobot3(std::vector<ColoredObject> object)
{

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
            //std::cout << tags_nearby << std::endl;
            if(tags_nearby == 1)
            {
                ally_found[3] = true;
                last_ally_coord[3] = i->coord;
                robot4.coord = i->coord;
                Coord center_tag_vector = tag.coord - robot4.coord;
                robot4.angle = atan2(center_tag_vector.y, center_tag_vector.x) + 3*M_PI_4;
                robot4.already_found = true;
                robot4.found_last_frame = true;
            }
        }
    if(ally_found[3])
    {
        vision_field_handler.setAlly(robot4, 3);
        std::cout << robot4.angle << std::endl;
    }
    else
        vision_field_handler.setAllyAsNotFound(0);
}

void RobotRecognizer::findRobot5(std::vector<ColoredObject> object)
{

}

void RobotRecognizer::findRobot6(std::vector<ColoredObject> object)
{

}

void RobotRecognizer::findEnemies(std::vector<ColoredObject> object)
{

}

#include "moc_robotrecognizer.cpp"
