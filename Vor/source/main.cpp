#include "vor.hpp"

#include <smmclib.hpp>

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if(argc > 3)
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
            Vor vor(argv[1], argv[2], argv[3]);
            return vor.runVor();
        }
    }

    std::cout << "ERROR: This application is expected to run from SMMCGUI receiving "
              << "it's shared memory keys" << std::endl;

    return 0;
}
