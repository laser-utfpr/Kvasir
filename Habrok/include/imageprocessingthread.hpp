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

    bool stop_thread;

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
