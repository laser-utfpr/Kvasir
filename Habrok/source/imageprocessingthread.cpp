#include "imageprocessingthread.hpp"

ImageProcessingThread::ImageProcessingThread(ImageProcessingSettings &ips,
                                             VisionFieldHandler &vfh) :
                        image_processing_thread(ips), vision_field_handler(vfh)
{

}

#include "moc_imageprocessingthread.cpp"
