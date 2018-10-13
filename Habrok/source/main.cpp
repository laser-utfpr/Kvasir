#include "habrok.hpp"

#include <smmclib.hpp>

#include <iostream>
#include <string>

#include <QApplication>

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        if(argv[1] == "-c" || argv[1] == "-C" || argv[1] == "--calibrate")
        {
            Habrok habrok;
            return habrok.calibrate();
        }
        else if(argc == 4)
        {
            bool right_key_sizes = true;
            for(int i=1; i<4; i++)
            {
                std::string str(argv[i]);
                if(str.size() != KEY_SIZE)
                    right_key_sizes = false;
            }
            if(right_key_sizes)
            {
                Habrok habrok(argv[1], argv[2], argv[3]);
                return habrok.runHabrok();
            }
        }
    }

    std::cout << "ERROR: This application is expected to run from SMMCGUI receiveing "
              << "it's shared memory keys or with -c for calibration" << std::endl;

    return 0;
}
