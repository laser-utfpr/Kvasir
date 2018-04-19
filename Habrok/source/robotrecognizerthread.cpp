#include "robotrecognizerthread.hpp"

RobotRecognizerThread::RobotRecognizerThread(VisionFieldHandler &vfh) : vision_field_handler(vfh)
{
    recognize_robots = false;
    stop_thread = false;
}

RobotRecognizerThread::~RobotRecognizerThread()
{

}

void RobotRecognizerThread::stopThread(void)
{
    stop_thread = true;
}

void RobotRecognizerThread::recognizeRobots(void)
{
    recognize_robots = true;
}

void RobotRecognizerThread::run()
{
    while(!stop_thread)
    {
        if(recognize_robots)
        {

        }
    }
}

#include "moc_robotrecognizerthread.cpp"
