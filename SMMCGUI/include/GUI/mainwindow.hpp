#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QtCore>
#include <QWidget>
#include <QMainWindow>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "sharedparameters.hpp"
#include "smmcthread.hpp"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    SharedParameters shared_parameters;
    SMMCThread *smmc;

    cv::VideoCapture cam;
    cv::Mat cam_image;

    QTimer* timer;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void stopSMMC(void);
    void visionSettingsChanged(void);
    void aiSettingsChanged(void);
    void commSettingsChanged(void);

private slots:
    void processFrame(void);
    void on_pauseButton_clicked(void);
    void handleVisionUpdate(void);
    void handleAIUpdate(void);
    void handleCommUpdate(void);
};

#endif // MAINWINDOW_HPP
