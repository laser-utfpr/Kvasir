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
    VisionFieldHandler(ColorAllocator &color_allocator, ColoredObjectAllocator &colored_object_allocator, FloatAllocator &float_allocator);
    ~VisionFieldHandler();

    void readChanges(boost::interprocess::managed_shared_memory &sm);
    void writeChanges(boost::interprocess::managed_shared_memory &sm);

    void updateTime(useconds_t new_time);
    void updateImage(cv::Mat &new_image);
    void updateObjects(std::vector<ColoredObject> &new_objects);
    bool isColorUsed(Color color);
    bool isInSearchedRegion(Coord coord);

    Color getBallColor(void);
    Color getAllyCenterColor(void);
    Color getTagColor(int n);
    void setBall(Entity new_ball);
    void setBallAsNotFound(void);
    void setAlly(Entity new_ally, int n);
    void setAllyAsNotFound(int n);

};

#endif //VISIONFIELDHANDLER_HPP
