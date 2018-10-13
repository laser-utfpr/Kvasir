#include "visionfieldhandler.hpp"

VisionFieldHandler::VisionFieldHandler(ColorAllocator &color_allocator,
    ColoredObjectAllocator &colored_object_allocator, FloatAllocator &float_allocator) :
    VisionField(color_allocator, colored_object_allocator, float_allocator)
{

}

VisionFieldHandler::~VisionFieldHandler()
{

}

void VisionFieldHandler::readChanges(boost::interprocess::managed_shared_memory &sm)
{
    QMutexLocker m(&lock);

    VisionField *sm_vf = sm.find<VisionField>(VISION_FIELD_MEMORY_NAME).first;

    this->ball_color = sm_vf->ball_color;
    this->ally_center = sm_vf->ally_center;
    this->enemy_center = sm_vf->enemy_center;
    this->ally_tag = sm_vf->ally_tag;

    this->searched_region_ulc = sm_vf->searched_region_ulc;
    this->searched_region_lrc = sm_vf->searched_region_lrc;
}

void VisionFieldHandler::writeChanges(boost::interprocess::managed_shared_memory &sm)
{
    QMutexLocker m(&lock);

    VisionField *sm_vf = sm.find<VisionField>(VISION_FIELD_MEMORY_NAME).first;

    sm_vf->image_data = this->image_data;
    sm_vf->image_width = this->image_width;
    sm_vf->image_height = this->image_height;
    sm_vf->time_us = this->time_us;

    sm_vf->found_object = this->found_object;

    sm_vf->ball = this->ball;
    for(int i=0; i<N_ROBOTS; i++)
    {
        sm_vf->robot[i] = this->robot[i];
        sm_vf->enemy_robot[i] = this->enemy_robot[i];
    }
}

void VisionFieldHandler::updateTime(useconds_t new_time)
{
    QMutexLocker m(&lock);
    time_us = new_time;
}

void VisionFieldHandler::updateImage(cv::Mat &new_image)
{
    QMutexLocker m(&lock);

    std::vector<float> image_data_tmp;

    if(new_image.isContinuous())
    {
        image_data_tmp.assign((float*)new_image.datastart, (float*)new_image.dataend);
    }
    else
    {
        for(int i=0; i<new_image.rows; ++i)
            image_data_tmp.insert(image_data_tmp.end(), new_image.ptr<float>(i), new_image.ptr<float>(i)+new_image.cols);
    }

    //image_data.insert(image_data.begin(), image_data_tmp.begin(), image_data_tmp.end());

    image_width = static_cast<double>(new_image.cols);
    image_height = static_cast<double>(new_image.rows);
}

void VisionFieldHandler::updateObjects(std::vector<ColoredObject> &new_objects)
{
    QMutexLocker m(&lock);
    found_object.insert(found_object.begin(), new_objects.begin(), new_objects.end());
}

bool VisionFieldHandler::isColorUsed(Color color)
{
    QMutexLocker m(&lock);

    if(color == ball_color || color == ally_center || color == enemy_center)
        return true;
    for(int i=0; i<ally_tag.size(); i++)
        if(color == ally_tag[i])
            return true;
    return false;
}
