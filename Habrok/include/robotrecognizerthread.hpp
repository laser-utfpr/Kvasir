#ifndef ROBOTRECOGNIZERTHREAD_HPP
#define ROBOTRECOGNIZERTHREAD_HPP

#include <QtCore>

#include "habrokconstants.h"
#include "visionfieldhandler.hpp"

class RobotRecognizerThread : public QThread
{
    Q_OBJECT

private:
    VisionFieldHandler &vision_field_handler;

    bool stop_thread;
    bool recognize_robots;

public:
    RobotRecognizerThread(VisionFieldHandler &vfh);
    ~RobotRecognizerThread();

    void run() override;

signals:
    void robotsRecognized(void);

public slots:
    void stopThread(void);
    void recognizeRobots(void);

};

#endif //ROBOTRECOGNIZERTHREAD_HPP
