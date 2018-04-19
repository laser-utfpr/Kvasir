#include "imageprocessingthread.hpp"

ImageProcessingThread::ImageProcessingThread(ImageProcessingSettings &ips,
                                             VisionFieldHandler &vfh) :
                        image_processing_settings(ips), vision_field_handler(vfh)
{
    stop_thread = false;
}

ImageProcessingThread::~ImageProcessingThread()
{

}

void ImageProcessingThread::stopThread(void)
{
    stop_thread = true;
}

void ImageProcessingThread::run()
{
    while(!stop_thread)
    {

    }
}

#include "moc_imageprocessingthread.cpp"
