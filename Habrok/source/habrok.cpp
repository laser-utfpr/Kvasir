#include "habrok.hpp"

Habrok::Habrok(std::string wk, std::string rk, std::string sk) :
               write_key(wk), read_key(rk), shutdown_key(sk),
               shared_memory(boost::interprocess::open_only, SHARED_MEMORY_BLOCK_NAME)
{
    image_processing_thread = new ImageProcessingThread(image_processing_settings,
                                                        vision_field_handler);
    robot_recognizer_thread = new RobotRecognizerThread(vision_field_handler);
    write_changes = false;
}

Habrok::Habrok()
{
    image_processing_thread = nullptr;
    robot_recognizer_thread = nullptr;
}

Habrok::~Habrok()
{

}

//these functions are to be used if it is needed to use find each time you use the variables
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

void Habrok::writeChanges(void)
{
    write_changes = true;
}

int Habrok::runHabrok(void)
{
    image_processing_thread.run();
    robot_recognizer_thread.run();

    std::string *sm_write_key = shared_memory.find<std::string>(VISION_WRITE_KEY_MEMORY_NAME).first;
    std::string *sm_read_key = shared_memory.find<std::string>(VISION_READ_KEY_MEMORY_NAME).first;
    std::string *sm_shutdown_key = shared_memory.find<std::string>(VISION_SHUTDOWN_KEY_MEMORY_NAME).first;

    while(*sm_shutdown_key != shutdown_key)
    {
        if(*sm_read_key == read_key)
        {
            *sm_read_key = EMPTY_KEY;
            vision_field_handler.readChanges(shared_memory);
        }
        if(write_changes)
        {
            vision_field_handler.writeChanges(shared_memory);
            *sm_write_key = write_key;
            write_changes = false;
        }
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
