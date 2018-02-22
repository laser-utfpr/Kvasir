#ifndef SMMCTHREAD_HPP
#define SMMCTHREAD_HPP

#include <QtCore>

#include <iostream>
#include <string>
#include <random>

#include "sharedparameters.hpp"
#include "smmcconstants.h"

class SMMCThread : public QThread
{
    Q_OBJECT

private:
    SharedParameters &shared_parameters;

    std::string vision_key;
    std::string ai_key;
    std::string communication_key;

protected:
    void run() override;

public:
    SMMCThread(SharedParameters &sp);
    ~SMMCThread();
    //void manageSharedMemory(void);

signals:
    //something changed
};

#endif // SMMCTHREAD_HPP
