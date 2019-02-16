//Este programa tem por objetivo captar as informacoes ditadas pela inteligencia artificial ou por um dispositivo de entrada e transmiti-las para os robos em campo

#include <smmclib.hpp>
#include <iostream>
#include <string>

#include "Vard.hpp"

int main(int argc, char *argv[])
{
    if(argc > 1)
    {
        if(argc == 4)
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
                Vard vard(argv[1], argv[2], argv[3]);
                vard.start();
                std::cout << "Vard received shutdown signal";
                return 0;
            }
        }
    }

    std::cout << "ERROR: This application is expected to run from SMMCGUI receiving "
              << "it's shared memory keys or with -c for calibration" << std::endl;
}
