#ifndef ROBOTRECOGNIZER_HPP
#define ROBOTRECOGNIZER_HPP

#include <QtCore>
#include <algorithm>

#include "habrokconstants.h"
#include "visionfieldhandler.hpp"

class RobotRecognizer
{
private:
    VisionFieldHandler &vision_field_handler;



    static Coord compared_object_coord;

    void findBall(void);
    void findEnemies(void);

    void findRobot1(void);
    void findRobot2(void);
    void findRobot3(void);
    void findRobot4(void);
    void findRobot5(void);
    void findRobot6(void);

public:
    RobotRecognizer(VisionFieldHandler &vfh);
    ~RobotRecognizer();

    void recognizeRobots(void);

    static bool compareColoredObjectDistance(ColoredObject c1, ColoredObject c2);
};

#endif //ROBOTRECOGNIZER_HPP
