#ifndef AIFIELDHANDLER_HPP
#define AIFIELDHANDLER_HPP

#include <boost/interprocess/managed_shared_memory.hpp>

#include <string>
#include <vector>
#include <ctime>

#include <smmclib.hpp>

class AIFieldHandler : private AIField
{
private:
    CharAllocator &char_allocator;

public:
    AIFieldHandler(CharAllocator &ca, StringAllocator &sa);
    ~AIFieldHandler();

    void readChanges(boost::interprocess::managed_shared_memory &sm);
    void writeChanges(boost::interprocess::managed_shared_memory &sm);

    useconds_t sampleTime(void);

    std::string commandReceived(void);
    void addCommand(const char* new_command);
};

#endif //AIFIELDHANDLER_HPP
