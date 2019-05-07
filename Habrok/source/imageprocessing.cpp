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
        float minDist = 10, cannyThreshold = 255, votesThreshold = 10, minRadius = 5, maxRadius = 20;
        cv::gpu::GpuMat gpu_hsv_image_split[3];
        cv::gpu::GpuMat gpu_thresholded_image_split[6];
        cv::gpu::GpuMat aux_gpu_thresholded_image[3];
        cv::gpu::GpuMat aux_thresholded_image;
        cv::gpu::split(gpu_hsv_image, gpu_hsv_image_split);
        cv::gpu::threshold(gpu_hsv_image_split[0], gpu_thresholded_image_split[0], mask.h_min, 255, cv::THRESH_BINARY);
        cv::gpu::threshold(gpu_hsv_image_split[0], gpu_thresholded_image_split[1], mask.h_max, 255, cv::THRESH_BINARY_INV);
        cv::gpu::threshold(gpu_hsv_image_split[1], gpu_thresholded_image_split[2], mask.s_min, 255, cv::THRESH_BINARY);
        cv::gpu::threshold(gpu_hsv_image_split[1], gpu_thresholded_image_split[3], mask.s_max, 255, cv::THRESH_BINARY_INV);
        cv::gpu::threshold(gpu_hsv_image_split[2], gpu_thresholded_image_split[4], mask.v_min, 255, cv::THRESH_BINARY);
        cv::gpu::threshold(gpu_hsv_image_split[2], gpu_thresholded_image_split[5], mask.v_max, 255, cv::THRESH_BINARY_INV);
        cv::gpu::bitwise_and(gpu_thresholded_image_split[0], gpu_thresholded_image_split[1], aux_gpu_thresholded_image[0]);
        cv::gpu::bitwise_and(gpu_thresholded_image_split[2], gpu_thresholded_image_split[3], aux_gpu_thresholded_image[1]);
        cv::gpu::bitwise_and(gpu_thresholded_image_split[4], gpu_thresholded_image_split[5], aux_gpu_thresholded_image[2]);
        cv::gpu::bitwise_and(aux_gpu_thresholded_image[0], aux_gpu_thresholded_image[1], aux_thresholded_image);
        cv::gpu::bitwise_and(aux_thresholded_image, aux_gpu_thresholded_image[2], gpu_thresholded_image);
        /*std::vector<cv::Vec3f> founded_circles;
        cv::gpu::GpuMat circles;
        cv::Mat oi;
        //useconds_t time = (useconds_t)(clock()/(CLOCKS_PER_SEC*0.000001));
        cv::gpu::HoughCircles(gpu_thresholded_image, circles, CV_HOUGH_GRADIENT, 1.0, minDist, cannyThreshold, votesThreshold, minRadius, maxRadius);
        founded_circles.resize(circles.size().width);
        if(!founded_circles.empty())
        {
            circles.download(oi);
            founded_circles = oi.reshape(3, 1);
            std::cout << "achou "<<founded_circles.size()<<"circulos"<< std::endl;
        }

        for(int i=0; i<founded_circles.size(); i++)
        {
            double area = founded_circles[i][2]*founded_circles[i][2]*M_PI;
            if(area > image_processing_settings.getMinimumObjectArea())
            {
                ColoredObject new_object;
                new_object.color = mask.color;
                new_object.area = area;
                new_object.coord.x = founded_circles[i][0];
                new_object.coord.y = founded_circles[i][1];
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
            cv::gpu::erode(gpu_thresholded_image, gpu_thresholded_image, erode_element);
            cv::gpu::dilate(gpu_thresholded_image, gpu_thresholded_image, dilate_element);
        #else

            cv::erode(thresholded_image, thresholded_image, erode_element);
            cv::erode(thresholded_image, thresholded_image, erode_element);

            cv::dilate(thresholded_image, thresholded_image, dilate_element);
            cv::dilate(thresholded_image, thresholded_image, dilate_element);
        #endif
    }
    #ifdef USE_GPU
        cv::Mat thresholded_image;
        gpu_thresholded_image.download(thresholded_image);
    #endif
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    //useconds_t time = (useconds_t)(clock()/(CLOCKS_PER_SEC*0.000001));
    findContours(thresholded_image, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
    //
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
