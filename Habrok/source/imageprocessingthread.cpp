#include "imageprocessingthread.hpp"

ImageProcessingThread::ImageProcessingThread(ImageProcessingSettings &ips,
                                             VisionFieldHandler &vfh) :
                        image_processing_settings(ips), vision_field_handler(vfh)
{
    stop_thread = false;

    cam.open(0);
    cam.set(CV_CAP_PROP_FRAME_WIDTH, 1920);
    cam.set(CV_CAP_PROP_FRAME_HEIGHT, 1080);
}

ImageProcessingThread::~ImageProcessingThread()
{

}

void ImageProcessingThread::stopThread(void)
{
    stop_thread = true;
}

void ImageProcessingThread::findObjects(HSVMask mask)
{

}

void ImageProcessingThread::run()
{
    clock_start = clock();

    while(!stop_thread)
    {
        vision_field_handler.updateTime((useconds_t)((clock()-clock_start)/(CLOCKS_PER_SEC*0.000001)));
        cam.read(cam_image);
        vision_field_handler.updateImage(cam_image);
        cvtColor(cam_image,hsv_image,cv::COLOR_RGB2HSV);

        object.clear();
        for(int i=0; i<N_COLORS; i++)
        {
            if(vision_field_handler.isColorUsed(static_cast<Color>(i)))
                findObjects(image_processing_settings.mask[i]);
        }
        vision_field_handler.updateObjects(object);
    }
}

#include "moc_imageprocessingthread.cpp"
