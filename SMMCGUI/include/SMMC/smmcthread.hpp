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
    std::string vision_shutdown_key;
    std::string ai_shutdown_key;
    std::string comm_shutdown_key;

    //shared memory key space
    std::string* sm_vision_write_key;
    std::string* sm_ai_write_key;
    std::string* sm_comm_write_key;
    std::string* sm_vision_read_key;
    std::string* sm_ai_read_key;
    std::string* sm_comm_read_key;
    std::string* sm_vision_shutdown_key;
    std::string* sm_ai_shutdown_key;
    std::string* sm_comm_shutdown_key;

    //vision shared memory variables
    VisionField* sm_vision_field;

    //ai shared memory variables
    AIField* sm_ai_field;

    //communication shared memory variables
    Movement* sm_robot_movement;

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

    void sendVisionChangesToAI(void);
    void sendAIChangeToComm(void);

public slots:
    void stopThread(void);

    void startVision(void);
    void startAI(void);
    void startComm(void);

    void shutdownVision(void);
    void shutdownAI(void);
    void shutdownComm(void);

    void updateVisionOutputSettings(void);
    void updateAIOutputSettings(void);
    void updateCommOutputSettings(void);

    void updateAIFromVision(void);
    void updateCommFromAI(void);

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
