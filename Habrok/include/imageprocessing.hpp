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
#ifdef USE_GPU
    #include <opencv2/gpu/gpu.hpp>
#endif
class ImageProcessing
{
private:
    ImageProcessingSettings &image_processing_settings;
    VisionFieldHandler &vision_field_handler;

    RobotRecognizer *robot_recognizer;

    cv::VideoCapture cam;
    #ifdef USE_GPU
        cv::Mat cam_image;
        cv::gpu::GpuMat gpu_cam_image;
        cv::gpu::GpuMat gpu_hsv_image;
        cv::gpu::GpuMat gpu_thresholded_image;
    #else
        cv::Mat cam_image;
        cv::Mat hsv_image;
        cv::Mat thresholded_image;
    #endif

    std::vector<ColoredObject> object;

    std::clock_t clock_start;

    void findObjects(HSVMask mask);

public:
    ImageProcessing(ImageProcessingSettings &ips, VisionFieldHandler &vfh);
    ~ImageProcessing();

    void processFrame(void);

};

#endif //IMAGEPROCESSING_HPP
