#ifndef VOR_HPP
#define VOR_HPP

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/allocators/allocator.hpp>

#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include <smmclib.hpp>

#include "vorconstants.h"
#include "aifieldhandler.hpp"
#include "strategy.hpp"

class Vor
{

private:
    boost::interprocess::managed_shared_memory *shared_memory;

    std::string write_key;
    std::string read_key;
    std::string shutdown_key;

    AIFieldHandler *ai_field_handler;
    //Boost Interprocess Allocators
    boost::interprocess::managed_shared_memory *allocator_provider; //only used to provide allocators
    std::string provider_name;
    CharAllocator *char_allocator;
    StringAllocator *string_allocator;

    Strategy *strategy;

    useconds_t last_sample_time = 0;

public:
    Vor(std::string wk, std::string rk, std::string sk);
    ~Vor();

    int runVor(void);

};

#endif // VOR_HPP
