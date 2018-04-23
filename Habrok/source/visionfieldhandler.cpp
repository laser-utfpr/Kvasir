#include "visionfieldhandler.hpp"

VisionFieldHandler::VisionFieldHandler() : VisionField()
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

    sm_vf->image = this->image;
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

void VisionFieldHandler::updateTime(useconds_t time)
{

}

void VisionFieldHandler::updateImage(cv::Mat image)
{

}

void VisionFieldHandler::updateObjects(std::vector<ColoredObject> object)
{

}

bool VisionFieldHandler::isColorUsed(Color color)
{
    if(color == ball_color || color == ally_center || color == enemy_center)
        return true;
    for(int i=0; i<ally_tag.size(); i++)
        if(color == ally_tag[i])
            return true;
    return false;
}
