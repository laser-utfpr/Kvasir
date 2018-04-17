#ifndef IMAGEPROCESSINGTHREAD_HPP
#define IMAGEPROCESSINGTHREAD_HPP

#include <QtCore>

#include "visionfieldhandler.hpp"
#include "imageprocessingsettings.hpp"

class ImageProcessingThread : public QThread
{
    Q_OBJECT

private:
    ImageProcessingSettings &image_processing_settings;
    VisionFieldHandler &vision_field_handler;

public:
    ImageProcessingThread(ImageProcessingSettings &ips, VisionFieldHandler &vfh);
};

#endif //IMAGEPROCESSINGTHREAD_HPP
