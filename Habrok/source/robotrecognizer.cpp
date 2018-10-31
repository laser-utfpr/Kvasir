#include "robotrecognizer.hpp"

RobotRecognizer::RobotRecognizer(VisionFieldHandler &vfh) : vision_field_handler(vfh)
{

}

RobotRecognizer::~RobotRecognizer()
{

}

void RobotRecognizer::recognizeRobots(std::vector<ColoredObject> &object)
{

    findBall();

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

    findEnemies();
}

static bool RobotRecognizer::compareColoredObjectDistance(ColoredObject c1, ColoredObject c2)
{
    return (compared_object_coord.distance(c1.coord) < compared_object_coord.distance(c1.coord));
}

void RobotRecognizer::findBall(std::vector<ColoredObject> &object)
{
    
}

void RobotRecognizer::findRobot1(std::vector<ColoredObject> &object)
{

}

void RobotRecognizer::findRobot2(std::vector<ColoredObject> &object)
{

}

void RobotRecognizer::findRobot3(std::vector<ColoredObject> &object)
{

}

void RobotRecognizer::findRobot4(std::vector<ColoredObject> &object)
{

}

void RobotRecognizer::findRobot5(std::vector<ColoredObject> &object)
{

}

void RobotRecognizer::findRobot6(std::vector<ColoredObject> &object)
{

}

void RobotRecognizer::findEnemies(std::vector<ColoredObject> &object)
{

}

#include "moc_robotrecognizer.cpp"
