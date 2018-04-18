#include "imageprocessingthread.hpp"

ImageProcessingThread::ImageProcessingThread(ImageProcessingSettings &ips,
                                             VisionFieldHandler &vfh) :
                        image_processing_settings(ips), vision_field_handler(vfh)
{

}

ImageProcessingThread::~ImageProcessingThread()
{

}

#include "moc_imageprocessingthread.cpp"
