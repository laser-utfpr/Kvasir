#include "habrok.hpp"

Habrok::Habrok(std::string wk, std::string rk, std::string sk) :
               write_key(wk), read_key(rk), shutdown_key(sk)
{
    try
    {
        shared_memory = new boost::interprocess::managed_shared_memory(boost::interprocess::open_only,
                                                                       SHARED_MEMORY_BLOCK_NAME);
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl << "Exception called while opening shared memory block:" << std::endl;
        std::cout << e.what() << std::endl;
        exit(1);
    }

    image_processing_thread = new ImageProcessingThread(image_processing_settings,
                                                        vision_field_handler);
    robot_recognizer_thread = new RobotRecognizerThread(vision_field_handler);
    write_changes = false;

    connect(this, SIGNAL(stopImageProcessingThread(void)), image_processing_thread, SLOT(stopThread()));
    connect(this, SIGNAL(stopRobotRecognizerThread(void)), robot_recognizer_thread, SLOT(stopThread()));

    connect(image_processing_thread, SIGNAL(frameProcessed(void)), robot_recognizer_thread, SLOT(recognizeRobots(void)));
    connect(robot_recognizer_thread, SIGNAL(robotsRecognized(void)), this, SLOT(writeChanges(void)));
}

Habrok::Habrok()
{
    image_processing_thread = nullptr;
    robot_recognizer_thread = nullptr;
}

Habrok::~Habrok()
{
    if(image_processing_thread != nullptr)
        emit stopImageProcessingThread();
    if(robot_recognizer_thread != nullptr)
        emit stopRobotRecognizerThread();
    if(shared_memory != nullptr)
        delete shared_memory;
}

//these functions may not be needed
std::string Habrok::getSharedMemoryWriteKey(void)
{
    std::string *key = shared_memory->find<std::string>(VISION_WRITE_KEY_MEMORY_NAME).first;
    return *(key);
}

std::string Habrok::getSharedMemoryReadKey(void)
{
    std::string *key = shared_memory->find<std::string>(VISION_READ_KEY_MEMORY_NAME).first;
    return *(key);
}

std::string Habrok::getSharedMemoryShutdownKey(void)
{
    std::string *key = shared_memory->find<std::string>(VISION_SHUTDOWN_KEY_MEMORY_NAME).first;
    return *(key);
}

void Habrok::writeChanges(void)
{
    write_changes = true;
}

int Habrok::runHabrok(void)
{
    image_processing_thread->start();
    robot_recognizer_thread->start();

    std::string *sm_write_key;
    std::string *sm_read_key;
    std::string *sm_shutdown_key;
    try
    {
        sm_write_key = (shared_memory->find<std::string>(VISION_WRITE_KEY_MEMORY_NAME)).first;
        sm_read_key = (shared_memory->find<std::string>(VISION_READ_KEY_MEMORY_NAME)).first;
        sm_shutdown_key = (shared_memory->find<std::string>(VISION_SHUTDOWN_KEY_MEMORY_NAME)).first;
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl << "Exception called while acessing shared memory keys:" << std::endl;
        std::cout << e.what() << std::endl;
        exit(1);
    }

    //FUCKING STD STRING AND VECTOR

    std::cout << *sm_shutdown_key << std::endl;

    /*while(*sm_shutdown_key != shutdown_key)
    {
        if(*sm_read_key == read_key)
        {
            *sm_read_key = EMPTY_KEY;
            vision_field_handler.readChanges(*shared_memory);
        }
        if(write_changes)
        {
            vision_field_handler.writeChanges(*shared_memory);
            *sm_write_key = write_key;
            write_changes = false;
        }
    }*/

    emit stopImageProcessingThread();
    emit stopRobotRecognizerThread();

    return 0;
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
