#include "imageprocessing.hpp"

ImageProcessing::ImageProcessing(ImageProcessingSettings &ips,
                                             VisionFieldHandler &vfh) :
                        image_processing_settings(ips), vision_field_handler(vfh)
{
    robot_recognizer = new RobotRecognizer(vision_field_handler, image_processing_settings);

    try
    {
        cam.open(image_processing_settings.getCameraID());
        cam.set(CV_CAP_PROP_FRAME_WIDTH, IMAGE_CAPTURE_WIDTH);
        cam.set(CV_CAP_PROP_FRAME_HEIGHT, IMAGE_CAPTURE_HEIGHT);
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl << "Exception called while opening camera:" << std::endl;
        std::cout << e.what() << std::endl;
        exit(1);
    }
    clock_start = clock();
}

ImageProcessing::~ImageProcessing()
{
    if(robot_recognizer != nullptr)
        delete robot_recognizer;

    try
    {
        cam.release();
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl << "Exception called while releasing camera:" << std::endl;
        std::cout << e.what() << std::endl;
        exit(1);
    }
}

void ImageProcessing::findObjects(HSVMask mask)
{
    #ifdef USE_GPU
        cv::Mat hsv_image;//por enquanto ate descobrir como fazer
        cv::Mat thresholded_image;
        gpu_hsv_image.download(hsv_image);
    #endif
    cv::inRange(hsv_image, cv::Scalar(mask.h_min, mask.s_min, mask.v_min),
            cv::Scalar(mask.h_max, mask.s_max, mask.v_max), thresholded_image);

    if(image_processing_settings.getUseMorphingOperations() == true)
    {
        auto erode_rect_size = image_processing_settings.getErodeRectSize();
        auto dilate_rect_size = image_processing_settings.getDilateRectSize();

        cv::Mat erode_element = getStructuringElement(cv::MORPH_RECT,
                                cv::Size(erode_rect_size, erode_rect_size));
        cv::Mat dilate_element = getStructuringElement(cv::MORPH_RECT,
                                 cv::Size(dilate_rect_size, dilate_rect_size));

        cv::erode(thresholded_image, thresholded_image, erode_element);
        cv::erode(thresholded_image, thresholded_image, erode_element);

        cv::dilate(thresholded_image, thresholded_image, dilate_element);
        cv::dilate(thresholded_image, thresholded_image, dilate_element);
    }

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

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
                if(vision_field_handler.isInSearchedRegion(Coord(new_object.coord.x, new_object.coord.y)))
                    object.push_back(new_object);
            }
        }
    }
}

void ImageProcessing::processFrame(void)
{
    #ifdef USE_GPU
        cam.read(cam_image);
        vision_field_handler.updateImage(cam_image);
        gpu_cam_image.upload(cam_image);
        cv::gpu::cvtColor(gpu_cam_image, gpu_hsv_image, cv::COLOR_RGB2HSV);
    #else
        cam.read(cam_image);
        vision_field_handler.updateImage(cam_image);
        cv::cvtColor(cam_image, hsv_image, cv::COLOR_RGB2HSV);
    #endif

    object.clear();
    for(int i=0; i<N_COLORS; i++)
    {
        if(vision_field_handler.isColorUsed(static_cast<Color>(i)))
            findObjects(image_processing_settings.mask[i]);
    }
    vision_field_handler.updateObjects(object);

    robot_recognizer->recognizeRobots(object);

    vision_field_handler.updateTime((useconds_t)((clock()-clock_start)/(CLOCKS_PER_SEC*0.000001)));
}

#include "moc_imageprocessing.cpp"
