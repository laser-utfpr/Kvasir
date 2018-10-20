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

    connect(&color_menu, SIGNAL(triggered(QAction*)), this, SLOT(changeColor(QAction*)));
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

#include "moc_mainwindow.cpp"
