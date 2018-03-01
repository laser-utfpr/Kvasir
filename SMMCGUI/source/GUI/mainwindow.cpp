#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    shared_parameters.loadSettingsFromFile();

    smmc = new SMMCThread(shared_parameters);

    connect(this, SIGNAL(stopSMMC()), smmc, SLOT(stopThread()));

    smmc->start();

    cam.open(0);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(processFrame()));
    timer->start(20);

    ui->pauseButton->setText("pause");
}

MainWindow::~MainWindow()
{
    delete ui;
    emit stopSMMC();
    usleep(100);
    delete smmc;
}

void MainWindow::processFrame()
{
    cam.read(cam_image);
    if(cam_image.empty())
        return;

    cv::cvtColor(cam_image, cam_image, CV_BGR2RGB);
    QImage qimage((uchar*)cam_image.data, cam_image.cols, cam_image.rows,
                  cam_image.step, QImage::Format_RGB888);

    ui->image->setPixmap(QPixmap::fromImage(qimage));
}

void MainWindow::on_pauseButton_clicked()
{
    if(timer->isActive())
    {
        timer->stop();
        ui->pauseButton->setText("resume");
    }
    else
    {
        ui->pauseButton->setText("pause");
        timer->start(20);
    }
}

#include "moc_mainwindow.cpp"
