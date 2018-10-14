#ifndef IMAGEPROCESSING_HPP
#define IMAGEPROCESSING_HPP

#include <QtCore>

#include <opencv2/opencv.hpp>

#include <ctime>
#include <vector>

#include <smmclib.hpp>

#include "habrokconstants.h"
#include "visionfieldhandler.hpp"
#include "imageprocessingsettings.hpp"
#include "robotrecognizer.hpp"
#include "hsvmask.hpp"

class ImageProcessing
{
private:
    ImageProcessingSettings &image_processing_settings;
    VisionFieldHandler &vision_field_handler;

    RobotRecognizer *robot_recognizer;

    cv::VideoCapture cam;
    cv::Mat cam_image;
    cv::Mat hsv_image;
    cv::Mat thresholded_image;

    std::vector<ColoredObject> object;

    std::clock_t clock_start;

    void findObjects(HSVMask mask);

public:
    ImageProcessing(ImageProcessingSettings &ips, VisionFieldHandler &vfh);
    ~ImageProcessing();

    void processFrame(void);

};

#endif //IMAGEPROCESSING_HPP
