#include "habrok.hpp"

Habrok::Habrok(std::string wk, std::string rk, std::string sk) :
               write_key(wk), read_key(rk), shutdown_key(sk)
{
    image_processing_thread = new ImageProcessingThread(image_processing_settings,
                                                        vision_field_handler);
    robot_recognizer_thread = new RobotRecognizerThread(vision_field_handler);  
}

Habrok::Habrok()
{

}

void runHabrok(void)
{

}

int calibrate(void)
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(CALIBRATION_WINDOW_TITLE);
    w.show();
    return a.exec()
}

#include "moc_habrok.cpp"
