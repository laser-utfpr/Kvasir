#ifndef ROBOTRECOGNIZER_HPP
#define ROBOTRECOGNIZER_HPP

#include <QtCore>
#include <cmath>
#include <algorithm>

#include "habrokconstants.h"
#include "visionfieldhandler.hpp"
#include "imageprocessingsettings.hpp"

class RobotRecognizer
{
private:
    VisionFieldHandler &vision_field_handler;
    ImageProcessingSettings &image_processing_settings;

    Coord last_ball_coord;
    bool ball_found = false;
    Coord last_ally_coord[N_ROBOTS];
    bool ally_found[N_ROBOTS];

    static Coord compared_object_coord;

    void findBall(std::vector<ColoredObject> object);
    void findEnemies(std::vector<ColoredObject> object);

    void findRobot1(std::vector<ColoredObject> object);
    void findRobot2(std::vector<ColoredObject> object);
    void findRobot3(std::vector<ColoredObject> object);
    void findRobot4(std::vector<ColoredObject> object);
    void findRobot5(std::vector<ColoredObject> object);
    void findRobot6(std::vector<ColoredObject> object);

public:
    RobotRecognizer(VisionFieldHandler &vfh, ImageProcessingSettings &ips);
    ~RobotRecognizer();

    void recognizeRobots(std::vector<ColoredObject> object);

    static bool compareColoredObjectDistance(ColoredObject c1, ColoredObject c2);
};

#endif //ROBOTRECOGNIZER_HPP
