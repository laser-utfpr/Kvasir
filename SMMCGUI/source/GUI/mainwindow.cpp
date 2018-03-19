#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    shared_parameters.loadSettingsFromFile();

    smmc = new SMMCThread(shared_parameters);

    connect(this, SIGNAL(stopSMMC()), smmc, SLOT(stopThread()));

    connect(this, SIGNAL(visionSettingsChanged()), smmc, SLOT(updateVisionOutputSettings()));
    connect(this, SIGNAL(aiSettingsChanged()), smmc, SLOT(updateAIOutputSettings()));
    connect(this, SIGNAL(commSettingsChanged()), smmc, SLOT(updateCommOutputSettings()));

    connect(smmc, SIGNAL(visionInputUpdate()), this, SLOT(handleVisionUpdate()));
    connect(smmc, SIGNAL(aiInputUpdate()), this, SLOT(handleAIUpdate()));
    connect(smmc, SIGNAL(commInputUpdate()), this, SLOT(handleCommUpdate()));

    connect(this, SIGNAL(runVision()), smmc, SLOT(startVision()));
    connect(this, SIGNAL(runAI()), smmc, SLOT(startAI()));
    connect(this, SIGNAL(runComm()), smmc, SLOT(startComm()));

    connect(this, SIGNAL(shutdownVision()), smmc, SLOT(shutdownVision()));
    connect(this, SIGNAL(shutdownAI()), smmc, SLOT(shutdownAI()));
    connect(this, SIGNAL(shutdownComm()), smmc, SLOT(shutdownComm()));

    smmc->start();
    usleep(100);

    cam.open(0);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(processImages()));
    timer->start(20);
}

MainWindow::~MainWindow()
{
    emit stopSMMC();
    usleep(100);
    delete smmc;
    delete ui;
}

void MainWindow::processGameControlImage(void)
{
    //for testing - to be deleted
    cam.read(cam_image);
    if(cam_image.empty())
        return;

    cv::Mat resized_image;
    cv::Size new_size(ui->game_control_image->width(),ui->game_control_image->height());
    cv::resize(cam_image, resized_image, new_size, INTERPOLATION_METHOD);

    //draw stuff

    cv::cvtColor(resized_image, resized_image, CV_BGR2RGB);
    QImage qimage((uchar*)resized_image.data, resized_image.cols, resized_image.rows,
                  resized_image.step, QImage::Format_RGB888);

    ui->game_control_image->setPixmap(QPixmap::fromImage(qimage));
}

void MainWindow::processVisionSettingsImage(void)
{

}

void MainWindow::processAISettingsImage(void)
{

}

void MainWindow::processImages(void)
{
    switch(ui->tabWidget->currentIndex())
    {
        case RUN_MODULES_INDEX:
        break;

        case GAME_CONTROL_INDEX:
        processGameControlImage(); break;

        case VISION_SETTINGS_INDEX:
        processVisionSettingsImage(); break;

        case AI_SETTINGS_INDEX:
        processAISettingsImage(); break;

        default:
        break;
    }
}

void MainWindow::on_vision_path_input_textChanged(const QString &arg1)
{
    shared_parameters.setVisionPath(arg1.toStdString());
}

void MainWindow::on_ai_path_input_textChanged(const QString &arg1)
{
    shared_parameters.setAIPath(arg1.toStdString());
}

void MainWindow::on_comm_path_input_textChanged(const QString &arg1)
{
    shared_parameters.setCommPath(arg1.toStdString());
}

void MainWindow::on_run_vision_clicked(void)
{
    emit runVision();
}

void MainWindow::on_run_ai_clicked(void)
{
    emit runAI();
}

void MainWindow::on_run_comm_clicked(void)
{
    emit runComm();
}

void MainWindow::on_shutdown_vision_clicked(void)
{
    emit shutdownVision();
}

void MainWindow::on_shutdown_ai_clicked(void)
{
    emit shutdownAI();
}

void MainWindow::on_shutdown_comm_clicked(void)
{
    emit shutdownComm();
}

void MainWindow::handleVisionUpdate(void)
{

}

void MainWindow::handleAIUpdate(void)
{

}

void MainWindow::handleCommUpdate(void)
{
    //no comm parameters to be handled for now
}

#include "moc_mainwindow.cpp"
