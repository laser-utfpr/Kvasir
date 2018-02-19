
#include "SMMCGUI.hpp"
#include "mainwindow.hpp"
#include "smmcthread.hpp"

#include <QApplication>

/*#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/offset_ptr.hpp>*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("SMMCGUI");
    w.show();

    SMMCThread smmc;
    smmc.start();

    return a.exec();
}
