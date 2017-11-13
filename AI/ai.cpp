#include "ai.hpp"
//#include "../include/ai.hpp"

void AIStart(bool print_mode, bool print_velocities)
{
    Strategy* strat = Strategy::getInstance();
    char quit = 0;
    while(quit != 'q')
    {
        strat->updateField();
        strat->decideMode();
        if(print_mode)
            strat->printMode();
        strat->calculateVelocities();
        if(print_velocities)
            strat->printVelocities();
        strat->saveVelocities();
        if(_kbhit())
            quit = std::cin.get();
        
    }
}
