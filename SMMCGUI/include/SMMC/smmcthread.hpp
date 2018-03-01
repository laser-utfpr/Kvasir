#ifndef SMMCTHREAD_HPP
#define SMMCTHREAD_HPP

#include <QtCore>

#include <boost/interprocess/managed_shared_memory.hpp>

#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <cstdlib>

#include "sharedparameters.hpp"
#include "smmclib.hpp"

class SMMCThread : public QThread
{
    Q_OBJECT

private:
    //parameters shared between threads
    SharedParameters &shared_parameters;

    //keep running thread flag
    bool run_thread;

    //generated keys
    std::string vision_write_key;
    std::string ai_write_key;
    std::string comm_write_key;
    std::string vision_read_key;
    std::string ai_read_key;
    std::string comm_read_key;

    //shared memory key space
    std::string* sm_vision_write_key;
    std::string* sm_ai_write_key;
    std::string* sm_comm_write_key;
    std::string* sm_vision_read_key;
    std::string* sm_ai_read_key;
    std::string* sm_comm_read_key;

    //vision shared memory variables
    VisionField* sm_vision_field;

    //ai shared memory variables

    //communication shared memory variables

    //shared memory block
    boost::interprocess::managed_shared_memory* shared_memory;

    std::vector<char> alphaNumericArray(void);
    std::string randomAlphaNumericString(int size);

    void generateKeys(void);
    void constructVisionSMVariables(void);
    void constructAISMVariables(void);
    void constructCommSMVariables(void);

protected:
    void run() override;

public:
    SMMCThread(SharedParameters &sp);
    ~SMMCThread();

signals:
    void visionInputUpdate(void);
    void aiInputUpdate(void);
    void commInputUpdate(void);

public slots:
    void stopThread(void);

    void startVision(std::string path);
    void startAI(std::string path);
    void startComm(std::string path);

    void updateVisionOutputSettings(void);
    void updateAIOutputSettings(void);
    void updateCommOutputSettings(void);
};

#endif // SMMCTHREAD_HPP

/*smmcthread should
-initialize shared memory block
-initialize keys
-start loop
--read changes with the right key

-slots for
--write changes from GUI
--start program sending the keys
--destroy shared memory and stop doing stuff on program finalization?*/
