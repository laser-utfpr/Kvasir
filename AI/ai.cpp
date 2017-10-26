#include "ai.hpp"
//#include "../include/ai.hpp"

void AIStart()
{
    Strategy strat;
    //while(game still going on)
    {
        strat.updateField();
        strat.decideMode();
        //execute mode
        //send velocities
    }
}
