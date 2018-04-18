#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{

}

MainWindow::~MainWindow()
{

}

#include "moc_mainwindow.cpp"
