#ifndef MODES_HPP
#define MODES_HPP

#include "strategy.hpp"
class Strategy;

class Mode
{
private:
public:
    virtual ~Mode();
    virtual bool inProgress(Strategy* strat);
    virtual void calculateVelocities(Strategy* strat);
};

class AttackMode : public Mode
{
private:
public:
    virtual bool inProgress(Strategy* strat);
    virtual void calculateVelocities(Strategy* strat);
};

class DefendMode : public Mode
{
private:
public:
    virtual bool inProgress(Strategy* strat);
    virtual void calculateVelocities(Strategy* strat);
};

class FreeBallMode : public Mode
{
private:
public:
    virtual bool inProgress(Strategy* strat);
    virtual void calculateVelocities(Strategy* strat);
};

class InterruptMode : public Mode
{
private:
public:
    virtual bool inProgress(Strategy* strat);
    virtual void calculateVelocities(Strategy* strat);
};

#endif //MODES_HPP
