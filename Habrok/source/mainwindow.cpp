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

    ui->camera_id_input->setText(QString::number(image_processing_settings.getCameraID()));
    cam.open(image_processing_settings.getCameraID());
    cam.set(CV_CAP_PROP_FRAME_WIDTH, IMAGE_CAPTURE_WIDTH);
    cam.set(CV_CAP_PROP_FRAME_HEIGHT, IMAGE_CAPTURE_HEIGHT);
    if(cam.isOpened())
        ui->camera_id_message->setText("ID opened successfully");
    else
        ui->camera_id_message->setText("Couldn't open inputted ID");

    ui->maximum_tag_distance_input->setText(QString::number(image_processing_settings.getMaximumTagDistance()));
    ui->minimum_object_area_input->setText(QString::number(image_processing_settings.getMinimumObjectArea()));
    erode_rect_size = image_processing_settings.getErodeRectSize();
    ui->erode_rect_size_input->setText(QString::number(image_processing_settings.getErodeRectSize()));
    dilate_rect_size = image_processing_settings.getDilateRectSize();
    ui->dilate_rect_size_input->setText(QString::number(image_processing_settings.getDilateRectSize()));
    ui->use_morphing_operations->setChecked(image_processing_settings.getUseMorphingOperations());
}

MainWindow::~MainWindow()
{
    for(int i=0; i<N_IMAGE_TYPES; i++)
        delete image_type_action[i];
    for(int i=0; i<N_COLORS; i++)
        delete color_action[i];

    cam.release();
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
        #ifdef USE_GPU
            cv::gpu::GpuMat gpu_image;
        #endif

        if(active_image_type == THRESHOLDED && active_color != UNCOLORED)
        {
            HSVMask mask = image_processing_settings.mask[static_cast<int>(active_color)];
            #ifdef USE_GPU
                gpu_image.upload(image);
                cv::gpu::cvtColor(gpu_image, gpu_image, cv::COLOR_RGB2HSV);
                cv::gpu::GpuMat gpu_hsv_image_split[3];
                cv::gpu::GpuMat gpu_thresholded_image_split[3];
                cv::gpu::GpuMat aux_gpu_thresholded_image;
                cv::gpu::split(gpu_image, gpu_hsv_image_split);
                cv::gpu::threshold(gpu_hsv_image_split[0], gpu_thresholded_image_split[0], mask.h_min, mask.h_max, cv::THRESH_BINARY);
                cv::gpu::threshold(gpu_hsv_image_split[1], gpu_thresholded_image_split[1], mask.s_min, mask.s_max, cv::THRESH_BINARY);
                cv::gpu::threshold(gpu_hsv_image_split[2], gpu_thresholded_image_split[2], mask.v_min, mask.v_max, cv::THRESH_BINARY);
                cv::gpu::bitwise_and(gpu_thresholded_image_split[0], gpu_thresholded_image_split[1], aux_gpu_thresholded_image);
                cv::gpu::bitwise_and(aux_gpu_thresholded_image, gpu_thresholded_image_split[2], gpu_image);
                gpu_image.download(image);
            #else
                cv::cvtColor(image, image, cv::COLOR_RGB2HSV);
                cv::inRange(image, cv::Scalar(mask.h_min, mask.s_min, mask.v_min),
                        cv::Scalar(mask.h_max, mask.s_max, mask.v_max), image);
            #endif

            if(ui->use_morphing_operations->isChecked())
            {
                cv::Mat erode_element = getStructuringElement(cv::MORPH_RECT,
                                        cv::Size(erode_rect_size, erode_rect_size));
                cv::Mat dilate_element = getStructuringElement(cv::MORPH_RECT,
                                         cv::Size(dilate_rect_size, dilate_rect_size));

                cv::erode(image, image, erode_element);
                cv::erode(image, image, erode_element);

                cv::dilate(image, image, dilate_element);
                cv::dilate(image, image, dilate_element);
            }

            cv::Mat resized_image;
            cv::Size new_size(ui->image->width(),ui->image->height());
            #ifdef USE_GPU
                cv::gpu::GpuMat gpu_resized_image;
                gpu_image.upload(image);
                cv::gpu::resize(gpu_image, gpu_resized_image, new_size, INTERPOLATION_METHOD);
                gpu_resized_image.download(resized_image);
            #else
                cv::resize(image, resized_image, new_size, INTERPOLATION_METHOD);
            #endif

            QImage qimage((uchar*)resized_image.data, resized_image.cols, resized_image.rows,
                      resized_image.step, QImage::Format_Grayscale8);

            ui->image->setPixmap(QPixmap::fromImage(qimage));

            return;
        }

        if(active_image_type == RAW || active_image_type == HSV)
        {
            if(active_image_type == HSV)
            {
                #ifdef USE_GPU
                    gpu_image.upload(image);
                    cv::gpu::cvtColor(gpu_image, gpu_image, cv::COLOR_RGB2HSV);
                    gpu_image.download(image);
                #else
                    cv::cvtColor(image, image, cv::COLOR_RGB2HSV);
                #endif
            }

            if(ui->show_minimum_object_area->isChecked())
            {
                int radius = sqrt(image_processing_settings.getMinimumObjectArea()/M_PI);
                cv::circle(image, cv::Point(IMAGE_CAPTURE_WIDTH/2, IMAGE_CAPTURE_HEIGHT/2), radius, SCALAR_GREEN, CV_FILLED);
            }

            if(ui->show_maximum_tag_distance->isChecked())
            {
                cv::circle(image, cv::Point(IMAGE_CAPTURE_WIDTH/2, IMAGE_CAPTURE_HEIGHT/2), image_processing_settings.getMaximumTagDistance(),
                           SCALAR_RED, 3);
            }

            cv::Mat resized_image;
            cv::Size new_size(ui->image->width(),ui->image->height());
            #ifdef USE_GPU
                cv::gpu::GpuMat gpu_resized_image;
                gpu_image.upload(image);
                cv::gpu::resize(gpu_image, gpu_resized_image, new_size, INTERPOLATION_METHOD);
                cv::gpu::cvtColor(gpu_resized_image, gpu_resized_image, CV_BGR2RGB);
                gpu_resized_image.download(resized_image);
            #else
                cv::resize(image, resized_image, new_size, INTERPOLATION_METHOD);
                cv::cvtColor(resized_image, resized_image, CV_BGR2RGB);
            #endif
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
        black_text.setColor(ui->camera_id_input->foregroundRole(), Qt::black);
        ui->camera_id_input->setPalette(black_text);
        cam.release();
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

void MainWindow::on_minimum_object_area_input_textChanged(const QString &new_text)
{
    bool ok = false;
    int value = new_text.toInt(&ok);
    if(ok)
    {
        black_text.setColor(ui->minimum_object_area_input->foregroundRole(), Qt::black);
        ui->minimum_object_area_input->setPalette(black_text);
        image_processing_settings.setMinimumObjectArea(value);
    }
    else
    {
        red_text.setColor(ui->minimum_object_area_input->foregroundRole(), Qt::red);
        ui->minimum_object_area_input->setPalette(red_text);
    }
}

void MainWindow::on_maximum_tag_distance_input_textChanged(const QString &new_text)
{
    bool ok = false;
    int value = new_text.toInt(&ok);
    if(ok)
    {
        black_text.setColor(ui->maximum_tag_distance_input->foregroundRole(), Qt::black);
        ui->maximum_tag_distance_input->setPalette(black_text);
        image_processing_settings.setMaximumTagDistance(value);
    }
    else
    {
        red_text.setColor(ui->maximum_tag_distance_input->foregroundRole(), Qt::red);
        ui->maximum_tag_distance_input->setPalette(red_text);
    }
}

void MainWindow::on_erode_rect_size_input_textChanged(const QString &new_text)
{
    bool ok = false;
    int value = new_text.toInt(&ok);
    if(ok)
    {
        black_text.setColor(ui->erode_rect_size_input->foregroundRole(), Qt::black);
        ui->erode_rect_size_input->setPalette(black_text);
        erode_rect_size = value;
        image_processing_settings.setErodeRectSize(value);
    }
    else
    {
        red_text.setColor(ui->erode_rect_size_input->foregroundRole(), Qt::red);
        ui->erode_rect_size_input->setPalette(red_text);
    }
}

void MainWindow::on_dilate_rect_size_input_textChanged(const QString &new_text)
{
    bool ok = false;
    int value = new_text.toInt(&ok);
    if(ok)
    {
        black_text.setColor(ui->dilate_rect_size_input->foregroundRole(), Qt::black);
        ui->dilate_rect_size_input->setPalette(black_text);
        dilate_rect_size = value;
        image_processing_settings.setDilateRectSize(value);
    }
    else
    {
        red_text.setColor(ui->dilate_rect_size_input->foregroundRole(), Qt::red);
        ui->dilate_rect_size_input->setPalette(red_text);
    }
}

void MainWindow::on_use_morphing_operations_stateChanged(int state)
{
    image_processing_settings.setUseMorphingOperations(static_cast<bool>(state));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    image_processing_settings.saveCalibration();
}

#include "moc_mainwindow.cpp"
