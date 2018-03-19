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

    QString vision_path;
    QString ai_path;
    QString comm_path;

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

    void runVision(void);
    void runAI(void);
    void runComm(void);

    void shutdownVision(void);
    void shutdownAI(void);
    void shutdownComm(void);

private slots:
    void on_vision_path_input_textChanged(const QString &arg1);
    void on_ai_path_input_textChanged(const QString &arg1);
    void on_comm_path_input_textChanged(const QString &arg1);

    void on_run_vision_clicked(void);
    void on_run_ai_clicked(void);
    void on_run_comm_clicked(void);

    void on_shutdown_vision_clicked(void);
    void on_shutdown_ai_clicked(void);
    void on_shutdown_comm_clicked(void);

    void processFrame(void);
    void handleVisionUpdate(void);
    void handleAIUpdate(void);
    void handleCommUpdate(void);
};

#endif // MAINWINDOW_HPP
