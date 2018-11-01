#include "robotrecognizer.hpp"

Coord RobotRecognizer::compared_object_coord;

RobotRecognizer::RobotRecognizer(VisionFieldHandler &vfh) : vision_field_handler(vfh)
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
    for(auto i=object.begin(); i != object.end() && !ball_found; i++)
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
    Color ally_center_color = vision_field_handler.getAllyCenterColor();
    Color tag_color = vision_field_handler.getTag(0);
    Entity robot1;
    for(auto i=object.begin(); i != object.end(); i++)
        if(i->color == ally_center_color)
        {

            //to be done now - only assign robot1 if there's 1 tag in the range

            auto sorted_tags = object;
            compared_object_coord = i->coord;
            std::sort(sorted_tags.begin(), sorted_tags.end(), &RobotRecognizer::compareColoredObjectDistance);
            for(auto j=sorted_tags.begin(); j != sorted_tags.end(); j++)
                if(j->color == tag_color && i->coord.distance(j->coord) < TAG_MAX_DISTANCE)
                {
                    ally_found[0] = true;
                }
        }
}

void RobotRecognizer::findRobot2(std::vector<ColoredObject> object)
{

}

void RobotRecognizer::findRobot3(std::vector<ColoredObject> object)
{

}

void RobotRecognizer::findRobot4(std::vector<ColoredObject> object)
{

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
