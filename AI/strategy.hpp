#ifndef STRATEGY_HPP
#define STRATEGY_HPP

#include "../ObRo/field.h"
#include "../ObRo/obroconstants.h"

#include "velocity.h"
#include "kbhit.h"
#include "geometry.h"

#include "aiconstants.h"
#include "fieldloader.hpp"

#include "modes.hpp"
class Mode;

#include <iostream>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/offset_ptr.hpp>

class Strategy
{
private:
    field current_field;
    field last_seen_field;
    velocity desired_vel[N_PLAYERS];
    roles role[N_PLAYERS];
    Mode *mode[N_MODES];
    modes active_mode;
    boost::interprocess::managed_shared_memory *shared_memory;
    velocity *shared_memory_velocities;
    static Strategy *instance;
    bool shouldWeDefend(void);
    Strategy();
public:
    static Strategy* getInstance(void);
    ~Strategy();
    void updateField(void);
    void decideMode(void);
    field getCurrentField(void);
    field getLastSeenField(void);
    void setDesiredXVel(int player, double x);
    void setDesiredYVel(int player, double y);
    void setDesiredAngVel(int player, double ang);
    roles getRole(int i);
    void calculateVelocities(void);
    void saveVelocities(void);
    void printMode(void);
    void printVelocities(void);
};

#endif //STRATEGY_HPP
