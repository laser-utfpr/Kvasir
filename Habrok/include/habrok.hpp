#ifndef HABROK_HPP
#define HABROK_HPP

#include <QApplication>
#include <QtCore>
#include <QWidget>
#include <QMainWindow>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/allocators/allocator.hpp>

#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>

#include <smmclib.hpp>

#include "habrokconstants.h"
#include "mainwindow.hpp"
#include "imageprocessingsettings.hpp"
#include "imageprocessing.hpp"
#include "visionfieldhandler.hpp"

class Habrok : public QObject
{

private:
    boost::interprocess::managed_shared_memory *shared_memory;

    std::string write_key;
    std::string read_key;
    std::string shutdown_key;

    VisionFieldHandler *vision_field_handler;
    //Boost Interprocess Allocators
    boost::interprocess::managed_shared_memory *allocator_provider; //only used to provide allocators
    std::string provider_name;
    ColorAllocator *color_allocator;
    ColoredObjectAllocator *colored_object_allocator;
    FloatAllocator *float_allocator;

    ImageProcessingSettings image_processing_settings;

    ImageProcessing *image_processing;

public:
    Habrok(std::string wk, std::string rk, std::string sk);
    Habrok();
    ~Habrok();

    int runHabrok(int argc, char *argv[]);

    int calibrate(void);

};

#endif // HABROK_HPP
