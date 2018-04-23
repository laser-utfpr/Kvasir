#ifndef IMAGEPROCESSINGTHREAD_HPP
#define IMAGEPROCESSINGTHREAD_HPP

#include <QtCore>

#include <opencv2/opencv.hpp>

#include <ctime>
#include <vector>

#include <smmclib.hpp>

#include "visionfieldhandler.hpp"
#include "imageprocessingsettings.hpp"
#include "hsvmask.hpp"

class ImageProcessingThread : public QThread
{
    Q_OBJECT

private:
    ImageProcessingSettings &image_processing_settings;
    VisionFieldHandler &vision_field_handler;

    bool stop_thread;

    cv::VideoCapture cam;
    cv::Mat cam_image;
    cv::Mat hsv_image;
    cv::Mat thresholded_image;

    std::vector<ColoredObject> object;

    std::clock_t clock_start;

    void findObjects(HSVMask mask);

public:
    ImageProcessingThread(ImageProcessingSettings &ips, VisionFieldHandler &vfh);
    ~ImageProcessingThread();

    void run() override;

signals:
    void frameProcessed(void);

public slots:
    void stopThread(void);

};

#endif //IMAGEPROCESSINGTHREAD_HPP
