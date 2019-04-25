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
        cv::gpu::GpuMat gpu_hsv_image_split[3];
        cv::gpu::GpuMat gpu_thresholded_image_split[3];
        cv::gpu::GpuMat aux_gpu_thresholded_image;
        cv::gpu::split(gpu_hsv_image, gpu_hsv_image_split);
        cv::gpu::threshold(gpu_hsv_image_split[0], gpu_thresholded_image_split[0], mask.h_min, mask.h_max, cv::THRESH_BINARY);
        cv::gpu::threshold(gpu_hsv_image_split[1], gpu_thresholded_image_split[1], mask.s_min, mask.s_max, cv::THRESH_BINARY);
        cv::gpu::threshold(gpu_hsv_image_split[2], gpu_thresholded_image_split[2], mask.v_min, mask.v_max, cv::THRESH_BINARY);
        cv::gpu::bitwise_and(gpu_thresholded_image_split[0], gpu_thresholded_image_split[1], aux_gpu_thresholded_image);
        cv::gpu::bitwise_and(aux_gpu_thresholded_image, gpu_thresholded_image_split[2], gpu_thresholded_image);
        //std::vector<cv::gpu::GpuMat> founded_circles;
        /*cv::gpu::GpuMat circles;
        std::vector<cv::Vec3f> founded_circles;
        cv::gpu::HoughCircles(gpu_thresholded_image, circles, CV_HOUGH_GRADIENT, 1.0, 70, 200, 100, 10, 100, 4096);
        for(std::vector<cv::Vec3f>::const_iterator it = founded_circles.begin() ; it != founded_circles.end() ; ++it)
        {
            double area = it->val[2]*it->val[2]*M_PI;
            if(area > image_processing_settings.getMinimumObjectArea())
            {
                ColoredObject new_object;
                new_object.color = mask.color;
                new_object.area = area;
                new_object.coord.x = it->val[0];
                new_object.coord.y = it->val[1];
                if(vision_field_handler.isInSearchedRegion(Coord(new_object.coord.x, new_object.coord.y)))
                    object.push_back(new_object);
            }
        }*/

    #else
        cv::inRange(hsv_image, cv::Scalar(mask.h_min, mask.s_min, mask.v_min),
                cv::Scalar(mask.h_max, mask.s_max, mask.v_max), thresholded_image);
    #endif


    if(image_processing_settings.getUseMorphingOperations() == true)
    {
        auto erode_rect_size = image_processing_settings.getErodeRectSize();
        auto dilate_rect_size = image_processing_settings.getDilateRectSize();

        cv::Mat erode_element = cv::getStructuringElement(cv::MORPH_RECT,
                                cv::Size(erode_rect_size, erode_rect_size));
        cv::Mat dilate_element = cv::getStructuringElement(cv::MORPH_RECT,
                                 cv::Size(dilate_rect_size, dilate_rect_size));
        #ifdef USE_GPU
            //cv::gpu::erode(gpu_thresholded_image, gpu_thresholded_image, erode_element, cv::Point(-1, -1), 1);
            //cv::gpu::dilate(gpu_thresholded_image, gpu_thresholded_image, dilate_element, cv::Point(-1, -1), 1);
        #else
            cv::erode(thresholded_image, thresholded_image, erode_element);
            cv::erode(thresholded_image, thresholded_image, erode_element);

            cv::dilate(thresholded_image, thresholded_image, dilate_element);
            cv::dilate(thresholded_image, thresholded_image, dilate_element);
        #endif
    }

    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    #ifdef USE_GPU
        cv::Mat thresholded_image;
        gpu_thresholded_image.download(thresholded_image);
    #endif
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
