#ifndef MODES_HPP
#define MODES_HPP

#include "kbhit.h"
#include "geometry.h"

#include "strategy.hpp"
class Strategy;

class Mode
{
private:
public:
    Mode();
    virtual ~Mode();
    virtual bool inProgress(Strategy* strat) = 0;
    virtual void calculateVelocities(Strategy* strat) = 0;
};

class AttackMode : public Mode
{
private:
public:
    AttackMode();
    ~AttackMode();
    virtual bool inProgress(Strategy* strat);
    virtual void calculateVelocities(Strategy* strat);
    std::pair<double,double> findGoalkeeperDestination(Strategy *strat);
};

class DefendMode : public Mode
{
private:
public:
    DefendMode();
    ~DefendMode();
    virtual bool inProgress(Strategy* strat);
    virtual void calculateVelocities(Strategy* strat);
};

class FreeBallMode : public Mode
{
private:
public:
    FreeBallMode();
    ~FreeBallMode();
    virtual bool inProgress(Strategy* strat);
    virtual void calculateVelocities(Strategy* strat);
};

class InterruptMode : public Mode
{
private:
public:
    InterruptMode();
    ~InterruptMode();
    virtual bool inProgress(Strategy* strat);
    virtual void calculateVelocities(Strategy* strat);
};

#endif //MODES_HPP
