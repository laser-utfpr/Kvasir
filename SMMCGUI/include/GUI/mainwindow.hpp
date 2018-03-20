#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QtCore>
#include <QWidget>
#include <QMainWindow>
#include <QMenu>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

#include "guiconstants.h"
#include "smmcconstants.h"

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

    QMenu command_menu;
    QAction **command_menu_action;
    int n_command_actions;

    bool force_stop;

    QMenu ally_center_menu;
    QMenu enemy_center_menu;
    QAction *color_action[N_COLORS];

    //for testing - to be deleted
    cv::VideoCapture cam;
    cv::Mat cam_image;

    QTimer* frame_update_timer;

    void processGameControlImage(void);
    void processVisionSettingsImage(void);
    void processAISettingsImage(void);

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

    void makeCommandMenu(void);
    void changeCommand(QAction *action);
    void on_send_command_clicked(void);

    void on_stop_resume_clicked(void);

    void changeAllyCenter(QAction *action);

    void processImages(void);
    void handleVisionUpdate(void);
    void handleAIUpdate(void);
    void handleCommUpdate(void);
};

#endif // MAINWINDOW_HPP
