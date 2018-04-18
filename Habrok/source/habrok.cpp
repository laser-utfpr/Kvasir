#include "habrok.hpp"

Habrok::Habrok(std::string wk, std::string rk, std::string sk) :
               write_key(wk), read_key(rk), shutdown_key(sk),
               shared_memory(boost::interprocess::open_only, SHARED_MEMORY_BLOCK_NAME)
{
    image_processing_thread = new ImageProcessingThread(image_processing_settings,
                                                        vision_field_handler);
    robot_recognizer_thread = new RobotRecognizerThread(vision_field_handler);
}

Habrok::Habrok()
{
    image_processing_thread = nullptr;
    robot_recognizer_thread = nullptr;
}

Habrok::~Habrok()
{

}

std::string Habrok::getSharedMemoryWriteKey(void)
{
    std::string *key = shared_memory.find<std::string>(VISION_WRITE_KEY_MEMORY_NAME).first;
    return *(key);
}

std::string Habrok::getSharedMemoryReadKey(void)
{
    std::string *key = shared_memory.find<std::string>(VISION_READ_KEY_MEMORY_NAME).first;
    return *(key);
}

std::string Habrok::getSharedMemoryShutdownKey(void)
{
    std::string *key = shared_memory.find<std::string>(VISION_SHUTDOWN_KEY_MEMORY_NAME).first;
    return *(key);
}

int Habrok::runHabrok(void)
{
    while(getSharedMemoryShutdownKey() != shutdown_key)
    {
        
    }
}

int Habrok::calibrate(void)
{
    int argc = 0;
    char **argv;
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(CALIBRATION_WINDOW_TITLE);
    w.show();
    return a.exec();
}

#include "moc_habrok.cpp"
