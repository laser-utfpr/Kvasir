#include "habrok.hpp"

Habrok::Habrok(std::string wk, std::string rk, std::string sk) :
               write_key(wk), read_key(rk), shutdown_key(sk),
               provider_name("sharedparametersallocatorprovider")
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

    boost::interprocess::shared_memory_object::remove(provider_name.c_str());
    allocator_provider = new boost::interprocess::managed_shared_memory(boost::interprocess::create_only, provider_name.c_str(), 65536);

    color_allocator = new ColorAllocator(allocator_provider->get_segment_manager());;
    colored_object_allocator = new ColoredObjectAllocator(allocator_provider->get_segment_manager());
    vision_field_handler = new VisionFieldHandler(*color_allocator, *colored_object_allocator);

    image_processing_thread = new ImageProcessingThread(image_processing_settings,
                                                        *vision_field_handler);
    robot_recognizer_thread = new RobotRecognizerThread(*vision_field_handler);
    write_changes = false;

    connect(this, SIGNAL(stopImageProcessingThread(void)), image_processing_thread, SLOT(stopThread()));
    connect(this, SIGNAL(stopRobotRecognizerThread(void)), robot_recognizer_thread, SLOT(stopThread()));

    connect(image_processing_thread, &ImageProcessingThread::frameProcessed, robot_recognizer_thread, &RobotRecognizerThread::recognizeRobots);
    connect(robot_recognizer_thread, &RobotRecognizerThread::robotsRecognized, this, &Habrok::writeChanges);
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

    if(vision_field_handler != nullptr)
        delete vision_field_handler;
    if(color_allocator != nullptr)
        delete color_allocator;
    if(colored_object_allocator != nullptr)
        delete colored_object_allocator;
    if(allocator_provider != nullptr)
        delete allocator_provider;

    if(shared_memory != nullptr)
        delete shared_memory;
}

void Habrok::writeChanges(void)
{
    write_changes = true;
}

int Habrok::runHabrok(void)
{
    image_processing_thread->start();
    robot_recognizer_thread->start();

    BoostInterprocessString *sm_write_key;
    BoostInterprocessString *sm_read_key;
    BoostInterprocessString *sm_shutdown_key;
    try
    {
        sm_write_key = (shared_memory->find<BoostInterprocessString>(VISION_WRITE_KEY_MEMORY_NAME)).first;
        sm_read_key = (shared_memory->find<BoostInterprocessString>(VISION_READ_KEY_MEMORY_NAME)).first;
        sm_shutdown_key = (shared_memory->find<BoostInterprocessString>(VISION_SHUTDOWN_KEY_MEMORY_NAME)).first;
    }
    catch(const std::exception& e)
    {
        std::cout << std::endl << "Exception called while acessing shared memory keys:" << std::endl;
        std::cout << e.what() << std::endl;
        exit(1);
    }

    while(*sm_shutdown_key != shutdown_key.c_str())
    {
        if(*sm_read_key == read_key.c_str())
        {
            std::cout << "lendo algo" << std::endl;
            *sm_read_key = EMPTY_KEY;
            vision_field_handler->readChanges(*shared_memory);
        }
        if(write_changes)
        {
            std::cout << "escrevendo algo" << std::endl;
            vision_field_handler->writeChanges(*shared_memory);
            *sm_write_key = write_key.c_str();
            write_changes = false;
        }
    }

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
