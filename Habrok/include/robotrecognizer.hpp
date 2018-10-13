#ifndef ROBOTRECOGNIZER_HPP
#define ROBOTRECOGNIZER_HPP

#include <QtCore>

#include "habrokconstants.h"
#include "visionfieldhandler.hpp"

class RobotRecognizer
{

private:
    VisionFieldHandler &vision_field_handler;

public:
    RobotRecognizer(VisionFieldHandler &vfh);
    ~RobotRecognizer();

    void recognizeRobots(void);

};

#endif //ROBOTRECOGNIZERTHREAD_HPP
