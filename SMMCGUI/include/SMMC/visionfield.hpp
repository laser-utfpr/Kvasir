#ifndef VISIONFIELD_HPP
#define VISIONFIELD_HPP

#include <opencv2/core/core.hpp>

#include <boost/serialization/utility.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/vector.hpp>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/containers/string.hpp>
#include <boost/interprocess/allocators/allocator.hpp>

#include <vector>

#include "interprocessvariabledefinitions.hpp"

#include "smmcconstants.h"
#include "coord.hpp"
#include "entity.hpp"
#include "coloredobject.hpp"

class VisionField
{
private:
    friend class boost::serialization::access;
    template<class Archive>
    inline void serialize(Archive &ar, const unsigned int /* file_version */)
    {
        ar & ball_color & ally_center & enemy_center;
        ar & searched_region_ulc & searched_region_lrc;
    };

public:
    FloatVector image_data;
    double image_width;
    double image_height;
    useconds_t time_us;

    ColoredObjectVector found_object;

    Entity ball;
    Entity robot[N_ROBOTS];
    Entity enemy_robot[N_ROBOTS];

    Color ball_color;
    Color ally_center;
    ColorVector ally_tag;
    Color enemy_center;

    Coord searched_region_ulc; //upper left corner
    Coord searched_region_lrc; //lower right corner

    inline VisionField(ColorAllocator &color_allocator, ColoredObjectAllocator &colored_object_allocator, FloatAllocator &float_allocator) :
    image_data(float_allocator),
    image_width(NAN), image_height(NAN), time_us(0),
    ball_color(UNCOLORED), ally_center(UNCOLORED), enemy_center(UNCOLORED),
    ally_tag(color_allocator), found_object(colored_object_allocator) {};
};

#endif // VISIONFIELD_HPP
