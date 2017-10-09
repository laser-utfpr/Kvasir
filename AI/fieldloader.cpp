#include "fieldloader.hpp"
//#include "../include/fieldloader.hpp"

using namespace boost::interprocess;

FieldLoader* FieldLoader::instance = nullptr;

/**
    FieldLoader::FieldLoader()

    The default constructor, initializes stuff and tries to open the shared memory.

    @author Lucca Rawlyk
    @version 2017.10.9-1
*/

FieldLoader::FieldLoader()
{
    shared_memory = nullptr;
    openSharedMemory();
}

FieldLoader::~FieldLoader()
{
    delete instance;
}

/**
    FieldLoader::openSharedMemory(void)

    Tries to open the shared memory.

    @author Lucca Rawlyk
    @version 2017.10.9-1
*/

void FieldLoader::openSharedMemory(void)
{
    if(shared_memory!=nullptr) //deletes the last opened vision shared memory if it exists
        delete shared_memory;

    bool opened = false;
    while(!opened)
    {
        try //tries to open the vision shared memory until it succeeds
        {
            shared_memory = new managed_shared_memory(open_only,VISION_SHARED_MEMORY_NAME);
            opened = true;
        }
        catch(...)
        {
            ;
        }
    }
}
