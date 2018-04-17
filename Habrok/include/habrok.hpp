#ifndef HABROK_HPP
#define HABROK_HPP

#include <QApplication>
#include <QtCore>
#include <QWidget>
#include <QMainWindow>
#include <QMenu>

#include <string>
#include <iostream>
#include <cmath>

#include <smmclib.hpp>

#include "habrokconstants.h"
#include "mainwindow.hpp"
#include "imageprocessingsettings.hpp"
#include "imageprocessingthread.hpp"
#include "robotrecognizerthread.hpp"
#include "visionfieldhandler.hpp"

class Habrok : public QObject
{
    Q_OBJECT

private:
    std::string write_key;
    std::string read_key;
    std::string shutdown_key;

    VisionFieldHandler vision_field_handler;

    ImageProcessingSettings image_processing_settings;

    ImageProcessingThread *image_processing_thread;
    RobotRecognizerThread *robot_recognizer_thread;

public:
    Habrok(std::string wk, std::string rk, std::string sk);
    Habrok();

    void runHabrok(void);

    int calibrate(void);

signals:

private slots:

};

#endif // HABROK_HPP
