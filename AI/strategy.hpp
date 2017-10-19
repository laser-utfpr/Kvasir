#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include "../obro/field.h"
#include "../obro/obroconstants.h"

#include "velocity.h"

#include "fieldloader.hpp"

#include "modes.hpp"
class Mode;

class Strategy
{
private:
    field current_field;
    velocity objective_vel[N_PLAYERS];
    Mode *mode;
public:
    Strategy();
    updateField();
}

#endif //STRATEGY_HPP
