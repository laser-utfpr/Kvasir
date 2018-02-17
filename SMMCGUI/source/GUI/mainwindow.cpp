#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_clicked()
{
    ui->label->setText(box_text);
}

void MainWindow::on_box_textChanged(const QString &arg1)
{
    box_text = arg1;
}

#include "moc_mainwindow.cpp"
