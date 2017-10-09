#ifndef FIELDLOADER_HPP
#define FIELDLOADER_HPP

#include "../Vision/visionconstants.h"
//#include "../Vision/include/visionconstants.h"

#include "../ObRo/obroconstants.h"
#include "../ObRo/field.h"

#include <iostream>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/offset_ptr.hpp>

class FieldLoader
{
private:
    boost::interprocess::managed_shared_memory *shared_memory;
    field *sigthed_field;
    static FieldLoader* instance;
    void openSharedMemory(void);
    FieldLoader();
public:
    ~FieldLoader();
    static FieldLoader* getInstance(void);
};

#endif // FIELDLOADER_HPP
