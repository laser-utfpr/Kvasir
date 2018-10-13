#include "imageprocessingthread.hpp"

ImageProcessingThread::ImageProcessingThread(ImageProcessingSettings &ips,
                                             VisionFieldHandler &vfh) :
                        image_processing_settings(ips), vision_field_handler(vfh)
{
    //this->moveToThread(this);

    stop_thread = false;

    robot_recognizer = new RobotRecognizer(vision_field_handler);

    cam.open(0);
    cam.set(CV_CAP_PROP_FRAME_WIDTH, IMAGE_CAPTURE_WIDTH);
    cam.set(CV_CAP_PROP_FRAME_HEIGHT, IMAGE_CAPTURE_HEIGHT);
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
    inRange(hsv_image, cv::Scalar(mask.h_min, mask.s_min, mask.v_min),
            cv::Scalar(mask.h_max, mask.s_max, mask.v_max), thresholded_image);
    image_processing_settings.applyMorphingOperations(thresholded_image);

    cv::vector<cv::vector<cv::Point>> contours;
    cv::vector<cv::Vec4i> hierarchy;

    findContours(thresholded_image, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);

    if(hierarchy.size()>0)
    {
        for(int j=0; j>=0; j=hierarchy[j][0])
        {
            cv::Moments moment = cv::moments((cv::Mat)contours[j], true);
            double area = moment.m00;
            if(area > image_processing_settings.getMinimumObjectArea())
            {
                ColoredObject new_object;
                new_object.color = mask.color;
                new_object.area = area;
                new_object.coord.x = moment.m10/area;
                new_object.coord.y = moment.m01/area;
                new_object.contour = contours[j];
                object.push_back(new_object);
            }
        }
    }
}

void ImageProcessingThread::run()
{
    clock_start = clock();
    while(!stop_thread)
    {
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
        vision_field_handler.updateTime((useconds_t)((clock()-clock_start)/(CLOCKS_PER_SEC*0.000001)));

        robot_recognizer->recognizeRobots();

        emit frameProcessed();
    }

}

#include "moc_imageprocessingthread.cpp"
