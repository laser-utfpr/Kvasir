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
    Mode *mode[N_MODES];
    modes active_mode;
    bool shouldWeDefend(void);
public:
    Strategy();
    ~Strategy();
    void updateField(void);
    void decideMode(void);
    void setDesiredXVel(int player, double x);
    void setDesiredYVel(int player, double y);
    void setDesiredAngVel(int player, double ang);
};

#endif //STRATEGY_HPP
