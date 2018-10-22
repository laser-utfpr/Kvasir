#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, ImageProcessingSettings *ips) : QMainWindow(parent), image_processing_settings(*ips),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->image_type_menu->setMenu(&image_type_menu);
    ui->color_menu->setMenu(&color_menu);

    QString qstr;

    const char *image_type_name[] = IMAGE_TYPE_MEMBER_NAMES;
    for(int i=0; i<N_IMAGE_TYPES; i++)
    {
        qstr = image_type_name[i];
        image_type_action[i] = new QAction(qstr,this);
        image_type_menu.addAction(image_type_action[i]);
    }

    const char *color_name[] = COLOR_MEMBER_NAMES;
    for(int i=0; i<N_COLORS; i++)
    {
        qstr = color_name[i];
        color_action[i] = new QAction(qstr,this);
        color_menu.addAction(color_action[i]);
    }

    connect(&image_type_menu, SIGNAL(triggered(QAction*)), this, SLOT(changeImageType(QAction*)));
    connect(&color_menu, SIGNAL(triggered(QAction*)), this, SLOT(changeColor(QAction*)));

    frame_update_timer = new QTimer(this);
    connect(frame_update_timer, SIGNAL(timeout()), this, SLOT(displayImage()));
    frame_update_timer->start(FRAME_REFRESH_RATE_MS);

    cam.open(value);
    cam.set(CV_CAP_PROP_FRAME_WIDTH, IMAGE_CAPTURE_WIDTH);
    cam.set(CV_CAP_PROP_FRAME_HEIGHT, IMAGE_CAPTURE_HEIGHT);
    if(cam.isOpened())
        ui->camera_id_message->setText("ID opened successfully");
    else
        ui->camera_id_message->setText("Couldn't open inputted ID");

    //get settings
}

MainWindow::~MainWindow()
{
    for(int i=0; i<N_IMAGE_TYPES; i++)
        delete image_type_action[i];
    for(int i=0; i<N_COLORS; i++)
        delete color_action[i];
}

void MainWindow::on_h_min_slider_valueChanged(void)
{
    if(active_color != UNCOLORED)
        image_processing_settings.mask[static_cast<int>(active_color)].h_min = ui->h_min_slider->value();
}

void MainWindow::on_h_max_slider_valueChanged(void)
{
    if(active_color != UNCOLORED)
        image_processing_settings.mask[static_cast<int>(active_color)].h_max = ui->h_max_slider->value();
}

void MainWindow::on_s_min_slider_valueChanged(void)
{
    if(active_color != UNCOLORED)
        image_processing_settings.mask[static_cast<int>(active_color)].s_min = ui->s_min_slider->value();
}

void MainWindow::on_s_max_slider_valueChanged(void)
{
    if(active_color != UNCOLORED)
        image_processing_settings.mask[static_cast<int>(active_color)].s_max = ui->s_max_slider->value();
}

void MainWindow::on_v_min_slider_valueChanged(void)
{
    if(active_color != UNCOLORED)
        image_processing_settings.mask[static_cast<int>(active_color)].v_min = ui->v_min_slider->value();
}

void MainWindow::on_v_max_slider_valueChanged(void)
{
    if(active_color != UNCOLORED)
        image_processing_settings.mask[static_cast<int>(active_color)].v_max = ui->v_max_slider->value();
}

void MainWindow::changeColor(QAction *action)
{
    QString qstr = action->text();
    ui->color_menu->setText(qstr);

    std::string new_color_name = qstr.toStdString();
    const char *color_name[] = COLOR_MEMBER_NAMES;
    for(int i=0; i<N_COLORS; i++)
    {
        std::string tested_color = color_name[i];
        if(new_color_name == tested_color)
            active_color = static_cast<Color>(i);
    }

    HSVMask mask = image_processing_settings.mask[static_cast<int>(active_color)];
    ui->h_min_slider->setValue(mask.h_min);
    ui->h_max_slider->setValue(mask.h_max);
    ui->s_min_slider->setValue(mask.s_min);
    ui->s_max_slider->setValue(mask.s_max);
    ui->v_min_slider->setValue(mask.v_min);
    ui->v_max_slider->setValue(mask.v_max);
}

void MainWindow::changeImageType(QAction *action)
{
    QString qstr = action->text();
    ui->image_type_menu->setText(qstr);

    std::string new_image_type_name = qstr.toStdString();
    const char *image_type_name[] = IMAGE_TYPE_MEMBER_NAMES;
    for(int i=0; i<N_IMAGE_TYPES; i++)
    {
        std::string tested_type = image_type_name[i];
        if(new_image_type_name == tested_type)
            active_image_type = static_cast<ImageType>(i);
    }
}

void MainWindow::displayImage(void)
{
    if(cam.isOpened())
    {
        cv::Mat image;
        cam.read(image);

        if(active_image_type == THRESHOLDED && active_color != UNCOLORED)
        {
            cv::cvtColor(image, image, cv::COLOR_RGB2HSV);

            HSVMask mask = image_processing_settings.mask[static_cast<int>(active_color)];
            cv::inRange(image, cv::Scalar(mask.h_min, mask.s_min, mask.v_min),
                    cv::Scalar(mask.h_max, mask.s_max, mask.v_max), image);

            cv::Mat resized_image;
            cv::Size new_size(ui->image->width(),ui->image->height());
            cv::resize(image, resized_image, new_size, INTERPOLATION_METHOD);

            QImage qimage((uchar*)resized_image.data, resized_image.cols, resized_image.rows,
                      resized_image.step, QImage::Format_Grayscale8);

            ui->image->setPixmap(QPixmap::fromImage(qimage));

            return;
        }

        if(active_image_type == RAW || active_image_type == HSV)
        {
            if(active_image_type == HSV)
                cvtColor(image, image, cv::COLOR_RGB2HSV);

            cv::Mat resized_image;
            cv::Size new_size(ui->image->width(),ui->image->height());
            cv::resize(image, resized_image, new_size, INTERPOLATION_METHOD);

            cv::cvtColor(resized_image, resized_image, CV_BGR2RGB);
            QImage qimage((uchar*)resized_image.data, resized_image.cols, resized_image.rows,
                      resized_image.step, QImage::Format_RGB888);

            ui->image->setPixmap(QPixmap::fromImage(qimage));
        }
    }
}

void MainWindow::on_camera_id_input_textChanged(const QString &new_text)
{
    bool ok = false;
    int value = new_text.toInt(&ok);
    if(ok)
    {
        black_text.setColor(ui->sr_camera_id_input->foregroundRole(), Qt::black);
        ui->camera_id_input->setPalette(black_text);
        cam.open(value);
        cam.set(CV_CAP_PROP_FRAME_WIDTH, IMAGE_CAPTURE_WIDTH);
        cam.set(CV_CAP_PROP_FRAME_HEIGHT, IMAGE_CAPTURE_HEIGHT);
        if(cam.isOpened())
            ui->camera_id_message->setText("ID opened successfully");
        else
            ui->camera_id_message->setText("Couldn't open inputted ID");
        image_processing_settings.setCameraID(value);
    }
    else
    {
        red_text.setColor(ui->camera_id_input->foregroundRole(), Qt::red);
        ui->camera_id_input->setPalette(red_text);
    }
}

#include "moc_mainwindow.cpp"
