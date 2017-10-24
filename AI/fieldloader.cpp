#include "fieldloader.hpp"
//#include "../include/fieldloader.hpp"

using namespace boost::interprocess;

FieldLoader* FieldLoader::instance = nullptr;

FieldLoader* FieldLoader::getInstance(void)
{
    if(instance==nullptr)
        instance = new FieldLoader;
    return instance;
}

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
            shared_memory = new managed_shared_memory(open_only,OBRO_SHARED_MEMORY_NAME);
            opened = true;
        }
        catch(...)
        {
            ;
        }
    }
}

/**
    FieldLoader::getField(void)

    Returns the current field stored in the shared memory.

    @author Lucca Rawlyk
    @version 2017.10.17-1
*/

field FieldLoader::getField(void)
{
    std::pair<field*, managed_shared_memory::size_type> stored_field;
    bool opened = false;

    while(!opened)
    {
        try
        {
            stored_field = shared_memory->find<field>(FIELD_MEMORY_NAME);
            opened = true;
        }
        catch(...)
        {
            std::cout << std::endl << "trying to reload the shared memory" << std::endl;
            openSharedMemory();
        }
    }

    return *(stored_field.first);
}
