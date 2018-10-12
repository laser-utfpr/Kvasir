#ifndef INTERPROCESSVARIABLEDEFINITIONS_HPP
#define INTERPROCESSVARIABLEDEFINITIONS_HPP

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/allocators/allocator.hpp>

#include "smmcconstants.h"
#include "coloredobject.hpp"

typedef boost::interprocess::allocator<char,
        boost::interprocess::managed_shared_memory::segment_manager> CharAllocator;
typedef boost::interprocess::basic_string<char, std::char_traits<char>, CharAllocator> BoostInterprocessString;
typedef boost::interprocess::allocator<BoostInterprocessString,
        boost::interprocess::managed_shared_memory::segment_manager> StringAllocator;

typedef boost::interprocess::allocator<Color,
        boost::interprocess::managed_shared_memory::segment_manager> ColorAllocator;
typedef boost::interprocess::vector<Color, ColorAllocator> ColorVector;

typedef boost::interprocess::allocator<ColoredObject,
        boost::interprocess::managed_shared_memory::segment_manager> ColoredObjectAllocator;
typedef boost::interprocess::vector<ColoredObject, ColoredObjectAllocator> ColoredObjectVector;

typedef boost::interprocess::vector<BoostInterprocessString, StringAllocator> StringVector;

typedef boost::interprocess::allocator<float,
        boost::interprocess::managed_shared_memory::segment_manager> FloatAllocator;
typedef boost::interprocess::vector<float, FloatAllocator> FloatVector;

#endif //INTERPROCESSVARIABLEDEFINITIONS_HPP
