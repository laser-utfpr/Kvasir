#include "mainwindow.hpp"
#include "guiconstants.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle(MAINWINDOW_TITLE);
    w.show();

    return a.exec();
}
