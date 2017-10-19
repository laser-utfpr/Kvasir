#ifndef MODES_HPP
#define MODES_HPP

#include "strategy.hpp"
class Strategy;

class Mode
{
private:
public:
    virtual void calculateVelocities(Strategy* strat);
}

class AttackMode : public Mode
{
private:
public:
    virtual void calculateVelocities(Strategy* strat);
}

class DefendMode : public Mode
{
private:
public:
    virtual void calculateVelocities(Strategy* strat);
}

class FreeBallMode : public Mode
{
private:
public:
    virtual void calculateVelocities(Strategy* strat);
}

class FreeKickMode : public Mode
{
private:
public:
    virtual void calculateVelocities(Strategy* strat);
}

class PenaltyMode : public Mode
{
private:
public:
    virtual void calculateVelocities(Strategy* strat);
}

class GoalKickMode : public Mode
{
private:
public:
    virtual void calculateVelocities(Strategy* strat);
}

#endif //MODES_HPP
