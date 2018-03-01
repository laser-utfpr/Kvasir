#include "mainwindow.hpp"
#include "smmcthread.hpp"
#include "sharedparameters.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SharedParameters shared_parameters;
    shared_parameters.loadSettingsFromFile();

    MainWindow w;
    w.setWindowTitle("SMMCGUI");
    w.show();

    SMMCThread smmc(shared_parameters);
    smmc.start();

    return a.exec();
}
