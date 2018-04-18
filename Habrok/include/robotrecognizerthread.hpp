#ifndef ROBOTRECOGNIZERTHREAD_HPP
#define ROBOTRECOGNIZERTHREAD_HPP

#include <QtCore>

#include "visionfieldhandler.hpp"

class RobotRecognizerThread : public QThread
{
    Q_OBJECT

private:
    VisionFieldHandler &vision_field_handler;

public:
    RobotRecognizerThread(VisionFieldHandler &vfh);
    ~RobotRecognizerThread();

    void run() override;

signals:

public slots:

};

#endif //ROBOTRECOGNIZERTHREAD_HPP
