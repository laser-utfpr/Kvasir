#ifndef SMMCTHREAD_HPP
#define SMMCTHREAD_HPP

#include <QtCore>

#include <boost/interprocess/managed_shared_memory.hpp>

#include <iostream>
#include <string>
#include <random>
#include <vector>

#include "sharedparameters.hpp"
#include "smmclib.hpp"

class SMMCThread : public QThread
{
    Q_OBJECT

private:
    //parameters shared between threads
    SharedParameters &shared_parameters;

    //generated keys
    std::string vision_write_key;
    std::string ai_write_key;
    std::string communication_write_key;
    std::string vision_read_key;
    std::string ai_read_key;
    std::string communication_read_key;

    //shared memory key space
    std::string* sm_vision_write_key;
    std::string* sm_ai_write_key;
    std::string* sm_communication_write_key;
    std::string* sm_vision_read_key;
    std::string* sm_ai_read_key;
    std::string* sm_communication_read_key;

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
    void constructCommunicationSMVariables(void);

protected:
    void run() override;

public:
    SMMCThread(SharedParameters &sp);
    ~SMMCThread();
signals:
    //tell GUI something changed
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
