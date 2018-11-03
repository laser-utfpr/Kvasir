#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include "vorconstants.h"
#include "aifieldhandler.hpp"

#include <string>
#include <vector>
#include <cmath>

#include <smmclib.hpp>

class Strategy
{
private:
    AIFieldHandler &ai_field_handler;

    Command command;

public:
    Strategy(AIFieldHandler &afh);
    ~Strategy();

    void makeCommandList(void);
    void calculateVelocities(void);

};

#endif // STRATEGY_HPP
