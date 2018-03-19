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
    smmc->start();
    usleep(100);

    cam.open(0);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(processFrame()));
    timer->start(20);
}

MainWindow::~MainWindow()
{
    emit stopSMMC();
    usleep(100);
    delete smmc;
    delete ui;
}

void MainWindow::processFrame(void)
{
    cam.read(cam_image);
    if(cam_image.empty())
        return;

    cv::cvtColor(cam_image, cam_image, CV_BGR2RGB);
    QImage qimage((uchar*)cam_image.data, cam_image.cols, cam_image.rows,
                  cam_image.step, QImage::Format_RGB888);

    ui->game_control_image->setPixmap(QPixmap::fromImage(qimage));
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
