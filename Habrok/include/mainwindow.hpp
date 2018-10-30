#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QtCore>
#include <QWidget>
#include <QMainWindow>
#include <QMenu>

#include <opencv2/opencv.hpp>

#include "imageprocessingsettings.hpp"
#include "habrokconstants.h"
#include <iostream>
#include <cmath>

#include <smmclib.hpp>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    ImageProcessingSettings &image_processing_settings;

    QMenu image_type_menu;
    QMenu color_menu;
    ImageType active_image_type = RAW;
    Color active_color = UNCOLORED;

    QAction *image_type_action[N_IMAGE_TYPES];
    QAction *color_action[N_COLORS];

    QTimer* frame_update_timer;
    cv::VideoCapture cam;

    QPalette black_text;
    QPalette red_text;

public:
    explicit MainWindow(QWidget *parent = 0, ImageProcessingSettings *ips = nullptr);
    ~MainWindow();

signals:

private slots:
    void on_camera_id_input_textChanged(const QString &new_text);
    void on_minimum_object_area_input_textChanged(const QString &new_text);
    void on_erode_rect_size_input_textChanged(const QString &new_text);
    void on_dilate_rect_size_input_textChanged(const QString &new_text);
    void on_use_morphing_operations_stateChanged(int state);

    void on_h_min_slider_valueChanged(void);
    void on_h_max_slider_valueChanged(void);
    void on_s_min_slider_valueChanged(void);
    void on_s_max_slider_valueChanged(void);
    void on_v_min_slider_valueChanged(void);
    void on_v_max_slider_valueChanged(void);

    void changeColor(QAction *action);
    void changeImageType(QAction *action);

    void displayImage(void);

};

#endif // MAINWINDOW_HPP
