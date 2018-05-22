#ifndef SMMCTHREAD_HPP
#define SMMCTHREAD_HPP

#include <QtCore>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/allocators/allocator.hpp>

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
    BoostInterprocessString* sm_vision_write_key;
    BoostInterprocessString* sm_ai_write_key;
    BoostInterprocessString* sm_comm_write_key;
    BoostInterprocessString* sm_vision_read_key;
    BoostInterprocessString* sm_ai_read_key;
    BoostInterprocessString* sm_comm_read_key;
    BoostInterprocessString* sm_vision_shutdown_key;
    BoostInterprocessString* sm_ai_shutdown_key;
    BoostInterprocessString* sm_comm_shutdown_key;

    //interprocess allocators
    CharAllocator *char_allocator;
    StringAllocator *string_allocator;
    ColorAllocator *color_allocator;
    ColoredObjectAllocator *colored_object_allocator;

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
    //is this useful?
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
