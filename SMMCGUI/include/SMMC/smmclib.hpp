#ifndef SMMCLIB_HPP
#define SMMCLIB_HPP

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/allocators/allocator.hpp>

typedef boost::interprocess::allocator<char,
        boost::interprocess::managed_shared_memory::segment_manager> CharAllocator;
typedef boost::interprocess::basic_string<char, std::char_traits<char>, CharAllocator> BoostInterprocessString;

#include "smmcconstants.h"
#include "coord.hpp"
#include "entity.hpp"
#include "visionfield.hpp"
#include "coloredobject.hpp"
#include "aifield.hpp"
#include "player.hpp"
#include "movement.hpp"

#endif // SMMCLIB_HPP
