#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include "../ObRo/field.h"
#include "../ObRo/obroconstants.h"

#include "velocity.h"

#include "aiconstants.h"
#include "fieldloader.hpp"

#include "modes.hpp"
class Mode;

#include <iostream>
#include <sys/select.h>

class Strategy
{
private:
    field current_field;
    velocity desired_vel[N_PLAYERS];
    roles role[N_PLAYERS];
    Mode *mode;
    bool kbhit(void);
    bool shouldWeDefend(void);
public:
    Strategy();
    void updateField(void);
    void decideMode(void);
};

#endif //STRATEGY_HPP
