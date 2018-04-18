#ifndef VISIONFIELDHANDLER_HPP
#define VISIONFIELDHANDLER_HPP

#include <QCore>

#include <boost/interprocess/managed_shared_memory.hpp>

#include <smmclib.hpp>

class VisionFieldHandler : private VisionField
{
private:
    QMutex lock;

public:
    VisionFieldHandler();
    ~VisionFieldHandler();

    void readChanges(boost::interprocess::managed_shared_memory &sm);
    void writeChanges(boost::interprocess::managed_shared_memory &sm);

};

#endif //VISIONFIELDHANDLER_HPP
