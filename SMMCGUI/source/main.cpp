#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::cout << "where am I stuck" << std::flush;
    MainWindow w;
    w.setWindowTitle(MAINWINDOW_TITLE);
    w.show();

    return a.exec();
}
