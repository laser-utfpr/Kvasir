#include "imageprocessingthread.hpp"

ImageProcessingThread::ImageProcessingThread(ImageProcessingSettings &ips,
                                             VisionFieldHandler &vfh) :
                        image_processing_settings(ips), vision_field_handler(vfh)
{

}

ImageProcessingThread::~ImageProcessingThread()
{

}

void ImageProcessingThread::run()
{

}

#include "moc_imageprocessingthread.cpp"
