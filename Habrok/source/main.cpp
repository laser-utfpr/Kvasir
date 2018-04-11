#include "mainwindow.hpp"
#include "imageprocessingthread.hpp"
#include "robotrecognizerthread.hpp"
#include "visionfieldhandler.hpp"

#include "smmclib.hpp"

#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        if(argv[1] == "-c" || argv[1] == "-C")
        {
            /*QApplication a(argc, argv);
            MainWindow w;
            w.setWindowTitle(MAINWINDOW_TITLE);
            w.show();
            return a.exec()*/
        }
        else if(argc == 4)
        {
            bool right_key_sizes = true;
            for(i=1; i<4; i++)
            {
                string str(argv[i]);
                if(str.size() != KEY_SIZE)
                    right_key_sizes = false;
            }
            if(right_key_sizes)
            {
                //run
            }
        }
    }

    std::cout << "This application is expected to run from SMMCGUI receiveing
                  it's keys or with -c for calibration" << std::endl;

    return 0;
}
