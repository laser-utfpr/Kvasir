#ifndef VISIONFIELDHANDLER_HPP
#define VISIONFIELDHANDLER_HPP

#include <QMutex>

#include <opencv2/opencv.hpp>

#include <boost/interprocess/managed_shared_memory.hpp>

#include <vector>
#include <ctime>

#include <smmclib.hpp>

class VisionFieldHandler : private VisionField
{
private:
    QMutex lock;

public:
    VisionFieldHandler();
    ~VisionFieldHandler();

    void readChanges(boost::interprocess::managed_shared_memory &sm);
    void writeChanges(boost::interprocess::managed_shared_memory &sm);

    void updateTime(useconds_t time);
    void updateImage(cv::Mat image);
    void updateObjects(std::vector<ColoredObject> object);
    bool isColorUsed(Color color);

};

#endif //VISIONFIELDHANDLER_HPP
